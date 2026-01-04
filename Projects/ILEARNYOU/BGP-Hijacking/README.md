# BGP Hijack Lab - BGP Route Hijack Demonstration

# [YouTube Video]()

## Description

This lab demonstrates a **BGP Hijacking** attack (BGP route hijack), where a malicious AS steals traffic destined for another AS by announcing a more specific prefix.


## Components

| Node | AS | Role | Network/IP |
|------|----|-----|--------|
| **TorHost** | 65001 | ISP hosting the Tor Relay (legitimate) | 1.1.1.0/24 |
| **Transit** | 65002 | Transit ISP (backbone) | Transit only |
| **ClientISP** | 65003 | Victim client ISP | 2.2.2.0/24 |
| **EvilISP** | 65100 | Malicious ISP (attacker) | Hijacks 1.1.1.0/25 |
| **Tor-Relay** | - | Legitimate server | 1.1.1.10 |
| **Client** | - | Victim user | 2.2.2.10 |

## Network Links (Private IPs)

| Link | Network | Endpoint A | Endpoint B |
|--------|-----|-----------|-----------|
| TorHost ↔ Transit | 10.0.1.0/30 | 10.0.1.1 | 10.0.1.2 |
| Transit ↔ ClientISP | 10.0.2.0/30 | 10.0.2.1 | 10.0.2.2 |
| ClientISP ↔ EvilISP | 10.0.3.0/30 | 10.0.3.1 | 10.0.3.2 |

---

## Usage Instructions

### 1. Start the Lab

```bash
sudo clab deploy -t bgp-hijack.clab.yml
```

> **Note:** Wait ~15 seconds for BGP sessions to establish.

### 2. Verify BGP Sessions

```bash
# Show BGP status on ClientISP
docker exec clab-bgp-hijack-ClientISP vtysh -c "show bgp summary"

# Show the BGP routing table
docker exec clab-bgp-hijack-ClientISP vtysh -c "show ip bgp"
```

### 3. Test Normal Connectivity (BEFORE the Hijack)

```bash
# Traceroute from the client to the Tor Relay
docker exec clab-bgp-hijack-Client traceroute -n 1.1.1.10
```

**Expected result (legitimate path):**
```
1  2.2.2.1       --> ClientISP (client gateway)
2  10.0.2.1      --> Transit (backbone)
3  10.0.1.1      --> TorHost (Tor ISP)
4  1.1.1.10      --> Tor-Relay (LEGITIMATE server)
```

### 4. Execute the BGP Hijack

```bash
# The attacker announces 1.1.1.0/25 (more specific than /24)
# Using the hijack.vty file
cat configs/EvilISP/hijack.vty | docker exec -i clab-bgp-hijack-EvilISP vtysh
```

Wait ~5 seconds for BGP propagation.

### 5. Verify the Hijack (AFTER the attack)

```bash
# Show the new BGP table - now there are TWO routes
docker exec clab-bgp-hijack-ClientISP vtysh -c "show ip bgp"

# Traceroute from the client
docker exec clab-bgp-hijack-Client traceroute -n 1.1.1.10
```

**Expected result (hijacked path):**
```
1  2.2.2.1       --> ClientISP (client gateway)
2  1.1.1.10      --> EvilISP (ATTACKER - diverted traffic)
```

### 6. Stop the Hijack

```bash
# Remove the malicious announcement
cat configs/EvilISP/unhijack.vty | docker exec -i clab-bgp-hijack-EvilISP vtysh
```

### 7. Destroy the Lab

```bash
sudo clab destroy -t bgp-hijack.clab.yml
```