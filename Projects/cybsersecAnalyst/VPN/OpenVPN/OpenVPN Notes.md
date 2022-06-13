**Title:** OpenVPN Notes
**Tags:** [[OpenVPN]]
**Topics:** #OpenVPN #VPN 

---
# TAP vs TUN
## TAP
> Layer 2

Bridge two computers only using the Ethernet cable for the connectivity between them. Act as a Switch. The downside is that has a lot of problems with routing.

## TUN
> Layer 3

Bridge two devices through Ethernet to create a virtual host server to divert the information. Used with routing. The downside is that it connects 2 machines, no 2 LANs.

| TAP | TUN |
| --- | --- |
| Allows client to connect to another LAN | |


# OpenVPN
Use SSL/TLS Encryption. Can use either UDP or TCP protocols.
