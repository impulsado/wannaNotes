**Title:** OpenVPN Notes
**Tags:** [[OpenVPN]]
**Topics:** #OpenVPN #VPN 

---
# OpenVPN 
Supports SSL/TLS Encryption. Can use either UDP or TCP protocols. Default port 1194.
OpenVPN uses the OpenSSL library, and because of this it has these cryptographic capabilities.
Can use conventional encryption using pre-shared keys (Static Key mode) or public key security (SSL/TLS) using client and server certificates.

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

## Security and Encryption
### TLS Version
OpenVPN accepts TLS 1.0 by default, which is [20 years old](https://en.wikipedia.org/wiki/Transport_Layer_Security#TLS_1.0).
With `tls-version-min 1.2` we enforce TLS 1.2, which the best protocol available currently for OpenVPN. TLS 1.2 is supported since OpenVPN 2.3.3.

### Certificate
OpenVPN uses an RSA certificate with a 2048 bits key by default.
OpenVPN uses `SHA-256` as the signature hash by default.

### Data Channel
By default, OpenVPN uses `BF-CBC` as the data channel cipher.
[//]: Blowfish is an old (1993) and weak algorithm. Even the official OpenVPN documentation admits it.
AES is today's standard. It's the fastest and more secure cipher available today.

AES-256 is 40% slower than AES-128, and there isn't any real reason to use a 256 bits key over a 128 bits key with AES. Moreover, AES-256 is more vulnerable to [Timing attacks](https://en.wikipedia.org/wiki/Timing_attack).

AES-GCM is an [AEAD cipher](https://en.wikipedia.org/wiki/Authenticated_encryption) which means it simultaneously provides confidentiality, integrity, and authenticity assurances on the data.

### Diffie-Hellman key exchange
OpenVPN uses a 2048 bits DH key by default.
OpenVPN 2.4 added support for ECDH keys. Elliptic curve cryptography is faster, lighter and more secure.

### HMAC digest algorithm

