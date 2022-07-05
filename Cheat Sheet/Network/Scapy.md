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
| version : | BitField | = (4) |
| ihl : | BitField | = (None) |
| tos : | XByteField | = (0) |
| len : | ShortField | = (None) |
| id : | ShortField | = (1) |
| flags : | FlagsField | = (0) |
| frag : | BitField | = (0) |
| ttl : | ByteField | = (64) |
| proto : | ByteEnumField | = (0) |
| chksum : | XShortField | = (None) |
| src : | Emph | = (None) |
| dst : | Emph | = ('127.0.0.1') |
| options : | PacketListField | = ([]) |

## Layer 4
```python
ls(TCP)
```
| Field | Type | Default Value |
| --- | --- | --- |
| sport : | ShortEnumField | = (20) |
| dport : | ShortEnumField | = (80) | 
| seq : | IntField | = (0) |
| ack : | IntField | = (0) |
| dataofs : | BitField | = (None) |
| reserved : | BitField | = (0) |
| flags : | FlagsField | = (2) |
| window : | ShortField | = (8192) |
| chksum : | XShortField | = (None) |
| urgptr : | ShortField | = (0) |
| options : | TCPOptionsField | = ({}) |
## Basic Packet Crafting
Scapy works with layers. Layers are individual functions linked together with the "/" character to construct packets.

> Simple Packet
```python
>>> Layer2=Ether(dst="08:00:27:d4:8f:54")
>>> Layer3=IP(src="192.168.0.1",dst="192.168.0.1")
>>> packet=(Layer2/Layer3/"Payload")
>>> packet.show()
###[ Ethernet ]###
  dst= 08:00:27:d4:8f:54
  src= 08:00:27:b8:90:cf
  type= IPv4
###[ IP ]###
     version= 4
     ihl= None
     tos= 0x0
     len= None
     id= 1
     flags=
     frag= 0
     ttl= 64
     proto= hopopt
     chksum= None
     src= 192.168.0.1
     dst= 192.168.0.1
     \options\
###[ Raw ]###
        load= 'Payload'

>>> send=sendp(packet, iface="enp0s3")
```
[sendp]: Send Layer2
["payload"]: Packet payload

## Altering packet
> Adding Layer 4
```python
Layer4=TCP(sport=5600,dport=22)
packet=(Layer2/Layer3/Layer4/"Payload")
```

> Setting TCP flags
```python
packet[TCP].flags="SA"
```

> Change destination IP
```python
packet[IP].dst = "1.2.3.4"
```


Layer3 = IP(dst="192.168.0.3", ttl=64)
Layer4 = TCP(flags="SR")
packet=(Layer3/Layer4/"TEST SCAN 1")
send(packet, iface="enp0s3")