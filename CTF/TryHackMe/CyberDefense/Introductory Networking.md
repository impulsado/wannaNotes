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
| **OSI** | **TCP/IP** |
| --- | --- |
| Application | Application |
| Presentation | Application | 
| Session | Application |
| Transport | Transport |
| Network | Internet |
| Data Link | Network Interface |
| Physical | Network Interface |

Protocol: Set of rules that define how an action is to be carried out. 
TCP/IP: Transmission Control Protocol / Internet Protocol.
To send a packet over a TCP connection, you must establish communication with the other computer. It can be done with `Three-Way Handshake`.

### Three-Way Handshake
1. Client wants to establish a connection with the server, and it sends a packet with SYN (synchronize) Flag.
2. The server responds with a SYN-ACK message to the client. ACK is used to let know the client that you have received his SYN packet. As this is a TCP protocol, it sends a SYN packet to the client.
3. The client responds to the Server with an ACK, to let know the server that he had received the SYN packet and the connection is fully established.
![[Pasted image 20221021165530.png]]

