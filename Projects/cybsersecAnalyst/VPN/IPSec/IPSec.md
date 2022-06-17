**Title:** IPSec
**Tags:** [[VPN]]
**Topics:** #VPN #IPSec

---
# IPSec
IPSec (Internet Protocol Security) is a framework that helps us to protect IP traffic on the network layer.

- **Confidentiality:** Encrypt our data. Nobody except the sender and receiver will be able to read our data.
- **Integrity:** Make sure that nobody changes the data in our packets. By calculating a hash value, the sender and receiver will be able to check if changes have been made to the packet.
- **Authentication:** The sender and receiver will authenticate each other to make sure that we are really talking with the device we intend to.
- **Anti-replay:** Even if a packet is encrypted and authenticated, an attacker could try to capture these packets and send them again. By using sequence numbers, IPsec will not transmit any duplicate packets.