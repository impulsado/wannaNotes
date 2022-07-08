**Title:** Kernel
**Tags:** [[cybersecAnalyst]]
**Topics:** #Kernel #cybersecAnalyst 

---
# Kernel
[Kernel Documentation](https://www.kernel.org/doc/Documentation/networking/ip-sysctl.txt)


## tcp_syncookies - INTEGER
Syncookie allows the server to defer using up any resources until the third packet in the three-way handshake has been received.

> Kernel Documentation
Only valid when the kernel was compiled with CONFIG_SYN_COOKIES
Send out syncookies when the syn backlog queue of a socket
overflows. This is to prevent against the common 'SYN flood attack'
Default: 1

More Information: https://lwn.net/Articles/277146/

## tcp_synack_retries - INTEGER
Specifies how many times to try to establish a passive TCP connection that was started by another host.

> Kernel Documentation
Number of times SYNACKs for a passive TCP connection attempt will
be retransmitted. Should not be higher than 255. Default value
is 5, which corresponds to 31seconds till the last retransmission
with the current initial RTO of 1second. With this the final timeout
for a passive TCP connection will happen after 63seconds.

## accept_source_route - INTEGER


> Kernel Documentation
Accept source routing (routing extension header).
\>= 0: Accept only routing header type 2.
< 0: Do not accept routing header.
Default: 0