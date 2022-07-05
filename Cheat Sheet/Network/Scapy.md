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
```python
ls(Ehter)
```
| Field | Type | Default Value |
| --- | --- | ---| 
| dst : | DestMACField | = (None) | 
| src : | SourceMACField | = (None) | 
| type : | XShortEnumField | = (0) |

## Layer 3
```python
ls(IP)
```
| Field | Type | Default Value | 
| --- | --- | --- |
| version :BitField = (4) ihl : BitField = (None) tos : XByteField = (0) len : ShortField = (None) id : ShortField = (1) flags : FlagsField = (0) frag : BitField = (0) ttl : ByteField = (64) proto : ByteEnumField = (0) chksum : XShortField = (None) src : Emph = (None) dst : Emph = ('127.0.0.1') options : PacketListField = ([])
