**Title:** IPSec
**Tags:** [[VPN]]
**Topics:** #VPN #IPSec

---
# IPSec (Internet Protocol Security)
IPSec (Internet Protocol Security) is a framework that helps us to protect IP traffic on the network layer.

- **Confidentiality:** Encrypt our data. Nobody except the sender and receiver will be able to read our data.
- **Integrity:** Make sure that nobody changes the data in our packets. By calculating a hash value, the sender and receiver will be able to check if changes have been made to the packet.
- **Authentication:** The sender and receiver will authenticate each other to make sure that we are really talking with the device we intend to.
- **Anti-replay:** Even if a packet is encrypted and authenticated, an attacker could try to capture these packets and send them again. By using sequence numbers, IPsec will not transmit any duplicate packets.

Use cases:
- Between two routers to create a site-to-site VPN that “bridges” two LANs together.
- Between a firewall and windows host for remote access VPN.
- Between two Linux servers to protect an insecure protocol like telnet.

## IKE (Internet Key Exchange)
### IKE phase 1
Two peers negotiate about the encryption, authentication, hashing and other protocols that they want to use and some other parameters that are required.
**ISAKMP (Internet Security Association and Key Management Protocol)** session is established.
[AKA]: IKE phase 1 tunnel.
[//]: Collection of parameters is called SA (Security Association).

![[Pasted image 20220617083119.png]]

