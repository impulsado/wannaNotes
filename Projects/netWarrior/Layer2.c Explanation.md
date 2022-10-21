**Title:** Layer2.c Explanation
**Tags:** [[netWarrior]]
**Topics:** #C 

---
# Layer 2 Explanation
`char sendbuf[BUF_SIZE];` → Creates the character variable that will be sent. BUF_SIZE is the maximum size of this variable. (`define BUF_SIZE 1024`)

`struct ether_header *eh = (struct ether_header *) sendbuf;` →the variable ``sendbuf`` is cast to a pointer to the struct ``ether_header``

`struct iphdr *iph = (struct iphdr *) (sendbuf + sizeof(struct ether_header));`→ It's adding `sizeof(struct ether_header)` to the pointer `sendbuf`, by doing that, it reaches the memory zone after the one occupied by the pointer to the struct ether_header , which seems to contain a pointer to the struct `iphdr`

``struct sockaddr_ll socket_address;`` → Structures for handling internet addresses. `sockaddr_ll` identifies a link-layer address and protocol.

`char ifName[IFNAMSIZ];` → Specifies the size of the array, with the value of IFNAMSIZ.

```c
/* Get interface name */
if (argc > 1)
	strcpy(ifName, argv[1]); // Copy First argument to ifName
	
else
	strcpy(ifName, DEFAULT_IF); // Copy value of DEFAULT_IF to ifName
```

```c
/* Open RAW socket to send on */
if ((sockfd = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL))) == -1) {
	perror("socket"); // Print descriptive error
}
```

```c
/* Get the index of the interface to send on */
memset(&if_idx, 0, sizeof(struct ifreq));  // Set all 0 in mem pos of if_idx
strncpy(if_idx.ifr_name, ifName, IFNAMSIZ-1);  // Copies ifName to if_idx.ifr_name
if (ioctl(sockfd, SIOCGIFINDEX, &if_idx) < 0)
	// ioctl: All
	perror("SIOCGIFINDEX");

/* Get the MAC address of the interface to send on */
memset(&if_mac, 0, sizeof(struct ifreq));
strncpy(if_mac.ifr_name, ifName, IFNAMSIZ-1);
if (ioctl(sockfd, SIOCGIFHWADDR, &if_mac) < 0)
	perror("SIOCGIFHWADDR");
```




## Important links

https://stackoverflow.com/questions/70995951/meaning-and-purpose-of-sockaddr-ll-in-packet-sockets
