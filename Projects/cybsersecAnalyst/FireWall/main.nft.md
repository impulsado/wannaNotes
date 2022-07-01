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
# Date:   30/06/2022
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
define ATIP = {80}  # Accepted TCP Input Ports (both IPv4 and IPv6)
define AUIP = {51820,1194}  # Accepted UDP Input Ports (both IPv4 and IPv6)
define SSH_LAN = 172.25.0.0/23  # Accept SSH from this LAN

# Flush all rules
flush ruleset

# IPv4/IPv6 Filter Table
table inet filter {

    # Create the counters
    counter input_tcp_no_syn {}
    counter input_tcp_scan_1 {}
    counter input_tcp_scan_2 {}
    counter input_tcp_scan_3 {}
    counter input_tcp_scan_4 {}
    counter input_tcp_scan_5 {}
    counter input_invalid_state {}
    counter input_icmpv4_dropped {}
    counter bl_clients {}

    set candidates {  # Candidates to connect via ssh (Port Knocking)
        type ipv4_addr . inet_service
        flags timeout
    }

    set blacklist {  # Blacklisted IP addresses
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
        iif != lo ip daddr 127.0.0.1/8 drop # Drop connections to loopback not coming from loopback

        # Drop if IP is in @blacklist
        ip saddr @blacklist counter name bl_clients drop

        # Permit and rate limit required ICMPv4 types (Allow Windows traceroute too)
        ip protocol icmp icmp type { echo-request } limit rate 1/second burst 5 packets accept
        
        # Permit and rate limit Linux traceroute
        udp dport 33434-33524 limit rate 5/second accept


        # ------------ SSH ------------
        # Port Knocking
        tcp dport 3500 add @candidates {ip saddr . 2552 timeout 10s}
        tcp dport 2552 ip saddr . tcp dport @candidates add @candidates {ip saddr . 7856 timeout 10s}
        tcp dport 7856 ip saddr . tcp dport @candidates add @candidates {ip saddr . 4481 timeout 10s}
        tcp dport 4481 ip saddr . tcp dport @candidates add @ssh_clients {ip saddr timeout 180s} log prefix "[IN] - Successful portknock: "
        tcp dport 22 ip saddr @ssh_clients accept  # Can be used with specific clients

        # Specific LAN
        tcp dport 22 ip saddr $SSH_LAN accept


        # ------------ Others ------------
        # Accept all connections related to connections made by us
        ct state {established, related} accept

        # User-Defined Input Ports
        tcp dport $ATIP accept
        udp dport $AUIP accept
        tcp dport 2404 ct state new accept  # Control Center Rule

        # IPSec
        udp dport { 500,4500 } accept  # Accept ISAKMP (IKE) & IPsec NAT traversal
        ip protocol { esp } accept  # AH is Deprecated


        # ------------ Scans/Spoofs/Invalid ------------
        # Drop TCP traffic with invalid flags
        tcp flags != syn ct state new log prefix "[IN] - New !SYN: " counter name input_tcp_no_syn drop  # Drop new connections that do not have the SYN TCP flag set
        tcp flags & (fin|syn) == (fin|syn) log prefix "[IN] - Scan 1: " counter name input_tcp_scan_1 drop  # Drop common port scan traffic. (Incompatible Flags)
        tcp flags & (syn|rst) == (syn|rst) log prefix "[IN] - Scan 2: " counter name input_tcp_scan_2 drop  # Drop common port scan traffic. (Uninitiated Request)
        tcp flags & (fin|syn|rst|psh|ack|urg) < (fin) log prefix "[IN] - Scan 3: " counter name input_tcp_scan_3 drop  # Drop common port scan traffic. (0 Attack)
        tcp flags & (fin|syn|rst|psh|ack|urg) == (fin|psh|urg) log prefix "[IN] - Scan 4: " counter name input_tcp_scan_4 drop  # Drop common port scan traffic. (Xmas Attack)
        tcp flags & (fin|syn|rst|psh|ack|urg) == 0x0 counter name input_tcp_scan_5 drop  # Drop common port scan traffic. (TCP NULL)
        ip frag-off & 0x1fff != 0 counter drop  # Drop fragmented packets

        # Drop invalid connection state traffic
        ct state invalid log flags all prefix "[IN] - Invalid: " counter name input_invalid_state drop  # Drop traffic with invalid connection state
        ip protocol icmp log flags all prefix "[IN] - Prohibited ICMPv4: " counter name input_icmpv4_dropped drop  # Log and drop all other ICMPv4 types

# PROBAR AQUESTES REGLES
        # Block IP addresses attempting more than 10 incoming TCP connections
        ip protocol tcp ct state new,untracked log prefix "[IN] - Suspicious IP: " limit rate over 10/minute add @blacklist { ip saddr } drop
        ip protocol udp ct state new,untracked log prefix "[IN] - Suspicious IP: " limit rate over 10/minute add @blacklist { ip saddr } drop

        # Log all
        # log prefix "[IN] - Denied: " counter drop
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
