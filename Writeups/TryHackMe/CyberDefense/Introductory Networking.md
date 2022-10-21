**Title:** Introductory Networking
**Tags:** [[CyberDefense]]
**Topics:** #Network #CyberDefense 

---
# Introductory Networking
## The OSI Model
Open Systems Interconnection. Used to demonstrate the theory behind computer networking. TCP/IP is more compact and more real. 
| **OSI** | **Definition** |
| --- | --- |
| Application | Provides networking options to the programs. Provides an interface. |
| Presentation | Translate data to standardised format. It also handles encryption, compression and other transformation. | 
| Session | Attempts to establish a connection to the other computer. If it can't do it, it sends back an error. If a session can be stablished, it maintain it. |
| Transport | Choose the protocol (TCP or UDP). TCP is `connection-bassed`. In UDP is the opposite. Packets are thrown to the computer and is not necessary that they all reach the computer. |
| Network | Responsible for locating the destination of your request. Most common protocol is IP. |
| Data Link | Focuses on the physical addressing (MAC). It adds the MAC address and it only works on your own network. |
| Physical | Physical layer. transforms the frame into the protocol through which it will travel. (Common protocol is Ethernet) |

## Encapsulation
![[Pasted image 20221021162942.png]]

## TCP/IP Model
| **OSI** | **Definition** |
| --- | --- |
| Application |  |
| Presentation | Application | 
| Session | Application |
| Transport | Transport |
| Network | Internet |
| Data Link |  |
| Physical | Network Interface |
