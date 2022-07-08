**Title:** Kernel
**Tags:** [[cybersecAnalyst]]
**Topics:** #Kernel #cybersecAnalyst 

---
# Kernel
List of Linux Kernel parameters that provide more security against DDoS attacks, Spoofing...
[Kernel Documentation](https://www.kernel.org/doc/Documentation/networking/ip-sysctl.txt)

## tcp_syncookies - INTEGER
Syncookie allows the server to defer using up any resources until the third packet in the three-way handshake has been received.

```ad-info
Only valid when the kernel was compiled with CONFIG_SYN_COOKIES
Send out syncookies when the syn backlog queue of a socket
overflows. This is to prevent against the common 'SYN flood attack'
Default: 1
```
More Information: https://lwn.net/Articles/277146/

## tcp_synack_retries - INTEGER
Specifies how many times to try to establish a passive TCP connection that was started by another host.

```ad-info
Number of times SYNACKs for a passive TCP connection attempt will
be retransmitted. Should not be higher than 255. Default value
is 5, which corresponds to 31seconds till the last retransmission
with the current initial RTO of 1second. With this the final timeout
for a passive TCP connection will happen after 63seconds.
```

## accept_source_route - INTEGER
Prevents TCP from having control over the routing of packets.

```ad-info
Accept source routing (routing extension header).
\>= 0: Accept only routing header type 2.
< 0: Do not accept routing header.
Default: 0
```

## icmp_echo_ignore_broadcasts - BOOLEAN
Ignore all broadcast ICMP ECHO.

```ad-info
If set non-zero, then the kernel will ignore all ICMP ECHO and
TIMESTAMP requests sent to it via broadcast/multicast.
Default: 1
```

## accept_redirects - BOOLEAN
If the value is 0, ICMP redirects are not accepted to avoid Man in the middle attacks.

```ad-info
Kernel Documentation
Accept ICMP redirect messages.
accept_redirects for the interface will be enabled if:
	- both conf/{all,interface}/accept_redirects are TRUE in the case
	  forwarding for the interface is enabled
or
	- at least one of conf/{all,interface}/accept_redirects is TRUE in the
	  case forwarding for the interface is disabled
accept_redirects for the interface will be disabled otherwise
default TRUE (host)
	FALSE (router)
```

## send_redirects - BOOLEAN
If the value is 0 it prevents the machine from sending ICMP packets with redirects.

```ad-info
Send redirects, if router.
send_redirects for the interface will be enabled if at least one of
conf/{all,interface}/send_redirects is set to TRUE,
it will be disabled otherwise
Default: TRUE
```

## rp_filter - INTEGER
Protects against spoofing attacks.

```ad-info
0 - No source validation.	

1 - Strict mode as defined in RFC3704 Strict Reverse Path
Each incoming packet is tested against the FIB and if the interface is not the best reverse path the packet check will fail.
By default failed packets are discarded.

2 - Loose mode as defined in RFC3704 Loose Reverse Path
Each incoming packet's source address is also tested against the FIB
and if the source address is not reachable via any interface
the packet check will fail.

Current recommended practice in RFC3704 is to enable strict mode
to prevent IP spoofing from DDos attacks. If using asymmetric routing
or other complicated routing, then loose mode is recommended.

The max value from conf/{all,interface}/rp_filter is used when doing source validation on the {interface}.

Default value is 0. Note that some distributions enable it in startup scripts.
```

## ip_forward - BOOLEAN
The value 0 disables packet forwarding.

```ad-info
0 - disabled (default)
not 0 - enabled

Forward Packets between interfaces.

This variable is special, its change resets all configuration parameters to their default state (RFC1122 for hosts, RFC1812 for routers)
```

## icmp_ignore_bogus_error_responses -  BOOLEAN
If the value is 1, it activates the protection against malformed error messages.

```ad-info
Some routers violate RFC1122 by sending bogus responses to broadcast
frames.  Such violations are normally logged via a kernel warning.
If this is set to TRUE, the kernel will not give such warnings, which
will avoid log file clutter.
Default: 1
```

