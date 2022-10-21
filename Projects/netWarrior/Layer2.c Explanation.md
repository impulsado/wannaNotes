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
	// ioctl: System call tahat allow comunication with driver
	// SIOCGIFINDEX: Retrieve the interface index of the interface
	
	perror("SIOCGIFINDEX");

/* Get the MAC address of the interface to send on */
memset(&if_mac, 0, sizeof(struct ifreq));  // Set all 0 in mem pos of if_idx
strncpy(if_mac.ifr_name, ifName, IFNAMSIZ-1);  // Copies ifName to if_mac.ifr_name
if (ioctl(sockfd, SIOCGIFHWADDR, &if_mac) < 0)
	// ioctl: System call tahat allow comunication with driver
	
	perror("SIOCGIFHWADDR");
```

`memset(sendbuf, 0, BUF_SIZ);` → Set all 0 in sendbuf variable.

```c
/* @MAC_DEST (6 Bytes) */

// tx_len is like a counter that increments when MY_DEST_MACX is added to the sendbuf variable.
tx_len = 0;
sendbuf[tx_len++] = MY_DEST_MAC0;
sendbuf[tx_len++] = MY_DEST_MAC1;
sendbuf[tx_len++] = MY_DEST_MAC2;
sendbuf[tx_len++] = MY_DEST_MAC3;
sendbuf[tx_len++] = MY_DEST_MAC4;
sendbuf[tx_len++] = MY_DEST_MAC5;
```

```c
/* @MAC_OG (6 Bytes) */

// unit8_t Unsigned Integers of 8 bits
sendbuf[tx_len++] = ((uint8_t *)&if_mac.ifr_hwaddr.sa_data)[0];
sendbuf[tx_len++] = ((uint8_t *)&if_mac.ifr_hwaddr.sa_data)[1];
sendbuf[tx_len++] = ((uint8_t *)&if_mac.ifr_hwaddr.sa_data)[2];
sendbuf[tx_len++] = ((uint8_t *)&if_mac.ifr_hwaddr.sa_data)[3];
sendbuf[tx_len++] = ((uint8_t *)&if_mac.ifr_hwaddr.sa_data)[4];
sendbuf[tx_len++] = ((uint8_t *)&if_mac.ifr_hwaddr.sa_data)[5];
```

```c
/* Ether Type */
// IP --> 0x08 0x00
// ARP --> 0x08 0x06
sendbuf[tx_len++] = 0x08;
sendbuf[tx_len++] = 0x06;

/* payload */
// What's inside the packet.
sendbuf[tx_len++] = 0x20;
sendbuf[tx_len++] = 0x20;
sendbuf[tx_len++] = 0x48;
sendbuf[tx_len++] = 0x6f;
sendbuf[tx_len++] = 0x6c;
sendbuf[tx_len++] = 0x61;
sendbuf[tx_len++] = 0x20;
sendbuf[tx_len++] = 0x50;
sendbuf[tx_len++] = 0x61;
sendbuf[tx_len++] = 0x75;
```

```c
memset(&socket_address,0,sizeof(struct ifreq)); // Set all 0 in socket_address mem dir

/* Index of the network device */
socket_address.sll_ifindex = if_idx.ifr_ifindex;

/* Address length*/
socket_address.sll_halen = ETH_ALEN;

/* Destination MAC */
socket_address.sll_addr[0] = MY_DEST_MAC0;
socket_address.sll_addr[1] = MY_DEST_MAC1;
socket_address.sll_addr[2] = MY_DEST_MAC2;
socket_address.sll_addr[3] = MY_DEST_MAC3;
socket_address.sll_addr[4] = MY_DEST_MAC4;
socket_address.sll_addr[5] = MY_DEST_MAC5;
```

```c
/* Send packet */
if (sendto(sockfd, sendbuf, tx_len, 0, (struct sockaddr*)&socket_address, sizeof(struct sockaddr_ll)) < 0)
	printf("Send failed\n");
else
	printf("OK\n")
```


## Important links

https://stackoverflow.com/questions/70995951/meaning-and-purpose-of-sockaddr-ll-in-packet-sockets
