
---
layout: post
title: IKEv2
date: 2022-08-20
categories: [cybersecAnalyst,VPN]
tags: [IKE,IKEv2]
---

# IKE and IKEv2
IKE is an IPSec-based tunneling protocol that provides a secure VPN communication channel and defines automatic means of negotiation and authentication for IPSec security associations in a protected manner.
1998 → IKE
2005 → IKEv2

## Benefits of IKEv2 VPN Protocol
### Security
IKEv2 employs server certificate authentication, which means it won’t perform any actions until it determines the requestor's identity.

### Reliability
In the first version of the protocol, if you tried to switch to a different internet connection, e.g. from Wi-Fi to mobile internet, with VPN on, it would disrupt the VPN connection and would require a reconnection.

Thanks to the reliability measures implemented in IKEv2, this issue has been fixed. Moreover, IKEv2 implements a MOBIKE technology, which allows it to be used by mobile and multi-homed users.

### Speed
Well-minded architecture and effective message exchange system in IKEv2 allow for better performance.

## Pros and cons
| **Pros** | **Cons** |
| --- | --- |
| Provides very stable connection | Closed-source (except for Linux) |
| Fast speed | Possibly compromised by the NSA |
| Compatible with a range of ciphers, including AES-256 | Bad for bypassing firewalls |
| Good at handling network changes |  |
| Supports Perfect Forward Secrecy |  |



