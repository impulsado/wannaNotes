**Title:** main.nft
**Tags:** [[Firewall]]
**Topics:** #FireWall #netfilter #Script 

---
# main.nft
```ad-important
It is not a shell code. It must be saved as .nft.
```

```bash
#!/usr/sbin/nft -f

# ===================
# Author: @impulsado
# Web: impulsado.org
# Date:   06/07/2022
# ===================

# input chain
# -----------
# * accept all traffic related to established connections.
# * accept all traffic on loopback iface.
# * accept ICMP (check types), WireGuard, OpenVPN, IPSec, traceroute (Windows/Linux).
# * secure ssh with port knocking or specific LAN.
# * drop any other input traffic.

# output chain
# -----------
# * accept all output traffic.

# forward chain
# -----------
# * drop all forward traffic (forward disabled in kernel module).

# commands
# -----------
# * "nft -f /path/to/file.nft" --> Load rules
# * "nft list ruleset" --> List rules (-j output in JSON)
# * "nft list counters" --> Show counter values (-j output in JSON)
# * "nft flush ruleset" --> Flush rules
# * "cat /var/log/messages" --> Show logs

# others
# -----------
# * Check "kernel-sec.sh" for more kernel security.
# * All rules have a definite reason. Read the reason in my repository for more information.
# * The configuration is designed for my scenario, inform yourself before applying it.

# Declare Variables
define ATIP = {1194}  # Accepted TCP Input Ports (both IPv4 and IPv6)
define AUIP = {51820,1194,53}  # Accepted UDP Input Ports (both IPv4 and IPv6)
define SSH_LAN = 172.25.0.0/23  # Accept SSH from this LAN

# Flush all rules
flush ruleset

# IPv4/IPv6 Filter Table
table inet filter {

    # Create the counters
    counter input_tcp_no_syn {}
    counter syn_fin_flood {}
    counter syn_rst_flood {}
    counter input_tcp_null_scan {}
    counter input_tcp_xmas_scan {}
    counter input_invalid_state {}
    counter input_icmpv4_dropped {}
    counter unknown_ip {}
    counter illegal_ip {}

    set candidates {  # Candidates to connect via ssh (Port Knocking)
        type ipv4_addr . inet_service
        flags timeout
    }

    set unknown_bl {  # Unknown Blacklisted IP addresses
        type ipv4_addr
        size 65535
        flags dynamic,timeout
        timeout 5m
    }

    set illegal_bl {  # Illegal Blacklisted IP addresses
        type ipv4_addr
        size 65535
        flags dynamic,timeout
        timeout 5m
    }

    set ssh_clients {  # Allowed IP's to connect via ssh
        type ipv4_addr
        flags timeout
        elements = { 192.168.0.2 }
    }

    chain input {
        type filter hook input priority 0; policy drop;  # Default policy

        # ------------ General ------------
        # Loopback
        iif lo accept  # Permit all loopback
        iif != lo ip daddr 127.0.0.1/8 log prefix "[IN] - Loopback spoofing" drop # Drop connections to loopback not coming from loopback

        # Drop if IP is in @blacklist or @softlist
        ip saddr @unknown_bl counter name unknown_ip drop
        ip saddr @illegal_bl counter name illegal_ip drop

        # Permit and rate limit required ICMPv4 types (Allow Windows traceroute too)
        ip protocol icmp icmp type { echo-request } limit rate 1/second burst 5 packets accept

        # Permit and rate limit Linux traceroute
        udp dport 33434-33524 limit rate 5/second accept

        # TEMPORAL
        ip saddr $SSH_LAN accept

        # ------------ Scans/Floods/Invalid ------------
        # Drop TCP traffic with invalid flags
        ip frag-off & 0x1fff != 0 log prefix "[IN] - Fragmented" drop  # Drop fragmented packets
        tcp flags != syn ct state new log prefix "[IN] - New !SYN: " counter name input_tcp_no_syn limit rate over 10/minute add @illegal_bl { ip saddr } drop  # Drop new connections that do not have the SYN TCP flag set (ACK Scan)
        tcp flags & (fin|syn) == (fin|syn) log prefix "[IN] - SYN-FIN: " counter name syn_fin_flood limit rate over 10/minute add @illegal_bl { ip saddr } drop  # Drop SYN-FIN Flood.
        tcp flags & (syn|rst) == (syn|rst) log prefix "[IN] - SYN-RST: " counter name syn_rst_flood limit rate over 10/minute add @illegal_bl { ip saddr } drop  # Drop SYN-RST Flood.

        tcp flags & (fin|syn|rst|psh|ack|urg) == 0x0 log prefix "[IN] - NULL Scan: " counter name input_tcp_null_scan limit rate over 10/minute add @illegal_bl { ip saddr } drop  # Drop common port scan traffic. (NULL Scan)
        tcp flags & (fin|syn|rst|psh|ack|urg) == (fin|psh|urg) log prefix "[IN] - Xmas Scan: " counter name input_tcp_xmas_scan limit rate over 10/minute add @illegal_bl { ip saddr } drop  # Drop common port scan traffic. (Xmas Scan)

        # Drop invalid connection state traffic
        ct state invalid log flags all prefix "[IN] - Invalid: " counter name input_invalid_state limit rate over 10/minute add @illegal_bl { ip saddr } drop  # Drop traffic with invalid connection state
        ip protocol icmp log flags all prefix "[IN] - Prohibited ICMPv4: " counter name input_icmpv4_dropped limit rate over 10/minute add @illegal_bl { ip saddr } drop  # Log and drop all other ICMPv4 types


        # ------------ User Preferences ------------
        # Accept all connections related to connections made by us
        ct state {established, related} accept

        # User-Defined Input Ports
        tcp dport $ATIP accept
        udp dport $AUIP accept
        tcp dport 2404 ct state new accept  # Control Center Rule

        # IPSec
        udp dport { 500,4500 } accept  # Accept ISAKMP (IKE) & IPsec NAT traversal
        ip protocol { esp } accept  # AH is Deprecated


        # ------------ SSH ------------
        # Port Knocking
        tcp dport 3500 add @candidates {ip saddr . 2552 timeout 10s}
        tcp dport 2552 ip saddr . tcp dport @candidates add @candidates {ip saddr . 7856 timeout 10s}
        tcp dport 7856 ip saddr . tcp dport @candidates add @candidates {ip saddr . 4481 timeout 10s}
        tcp dport 4481 ip saddr . tcp dport @candidates add @ssh_clients {ip saddr timeout 180s} log prefix "[IN] - Successful portknock: "
        tcp dport 22 ip saddr @ssh_clients accept  # Can be used with specific clients

        # Specific LAN
        tcp dport 22 ip saddr $SSH_LAN accept


        # ------------ Debug ------------
        # Log all
        log prefix "[IN] - Denied: " counter drop


        # ------------ More Security ------------
        # Block IP addresses attempting more than 10 incoming TCP/UDP connections
        ip protocol tcp ct state new,untracked log prefix "[IN] - Suspicious IP: " limit rate over 10/minute add @unknown_bl { ip saddr } drop
        ip protocol udp ct state new,untracked log prefix "[IN] - Suspicious IP: " limit rate over 10/minute add @unknown_bl { ip saddr } drop
    }

    chain output {
        # Accept outgoing traffic (Default Policy)
        type filter hook output priority 0; policy accept;
    }

    chain forward {
        # Drop everything (This device is not a router)
        type filter hook forward priority 0; policy drop;
    }
}
```
