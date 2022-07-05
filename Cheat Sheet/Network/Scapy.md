**Title:** Scapy
**Tags:** [[Network]]
**Topics:** #Network #Scapy

---
# Scapy
Forge or decode packets of a wide number of protocols, send them on the wire, capture them, match requests and replies, and much more.

## Basics
> List supported layers
```python
ls()
```

Some key layers are:
ether, arp, ip, ipv6, tcp, udp, icmp

> Layer Fields
```python
ls(TCP)
```

Some key commands for interacting with packets:
rdpcap, send, sr, sniff, wrpcap

> Help
```python
help(rdpcap)
```

## Layer 2
