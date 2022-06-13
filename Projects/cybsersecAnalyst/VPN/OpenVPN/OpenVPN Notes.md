**Title:** OpenVPN Notes
**Tags:** [[OpenVPN]]
**Topics:** #OpenVPN #VPN 

---
# OpenVPN 
Supports SSL/TLS Encryption. Can use either UDP or TCP protocols. Default port 1194.

## TAP vs TUN
### TAP
> Layer 2

Bridge two computers only using the Ethernet cable for the connectivity between them. Act as a Switch. The downside is that has a lot of problems with routing.

### TUN
> Layer 3

Bridge two devices through Ethernet to create a virtual host server to divert the information. Used with routing. The downside is that it connects 2 machines, no 2 LAN's.

| **TAP** | **TUN** |
| --- | --- |
| Allows a client to connect to another LAN. (Access to resources or services) | Connect only to a Server |
| The network load is higher because it includes the routes of each network.  | You can access to network resources simulating that they are in the server but is not his function.|
| Open LAN to the other (Depending on the configuration) and can introduce Security Breaches | Faster and easier to setup |


