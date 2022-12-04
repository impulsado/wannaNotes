**Title:** Day 4
**Tags:** [[Advent Cyber 2022]]
**Topics:** #TryHackMe #Scanning

---
# Scanning
Process of identifying live hosts, ports, and services on a network or an operative system. Used to identify vulnerabilities and threats.

## Scanning Types
Based on the degree of intrusiveness:
- **Passive (Footprinting)**: No interaction with the target device. Packet capture, OSINT, … 
- **Active (Fingerprinting)**: Scan individual endpoint to retrieve more detailed information. Sending packets or queries directly.

## Scanning Techniques
### Network Scanning
Discover and map complete networks, including computers, open ports, IPs and Services. Once the network is mapped, the attacker can decide where to start.

### Port Scanning
Examine open ports in a network. Port scanning can fall into these three categories:
- **Closed Ports**: Not listening
- **Open Ports**: Accepts connections.
- **Filtered Ports**: Port is open, but host is not accepting connections.

### Vulnerability Scanning
Identifies vulnerabilities on hosts. The toolcan be free or paid. Uses a pre-build database of vulnerabilities. E