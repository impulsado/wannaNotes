**Title:** iptables vs nftables
**Tags:** [[Firewall]]
**Topics:** #FireWall 

---
# iptables vs nftables
## iptables
IPtables is a command line utility that is used for configuring firewall rules, usually in combination with a frontend. IPtables is able to inspect, modify or drop network packets. The “tables” consist of “chains” which contain “rules” that are processed in the defined order.
Rules are basically conditions that have to be true respectively to match a defined action to be executed. All incoming packets, regardless the source (internal/internet), are being processed by the very same rules.
Tables:
- raw
- filter (important)
- NAT (important)
- mangle
- security

## nftables
Nftables (developed by netfilter/IPtables) is a package filtering framework. It was basically built to replace the old IPtables, because IPtables had several problems in terms of performance and scalability.
Note: Aviable in Linux Kernel since version 3.13

## Difference with iptables
- **ntables uses a new syntax**
- **Tables and chains are fully configurable:** iptables has multiple pre-defined tables and base chains, all of which are registered even if you only need one of them. With nftables there are no pre-defined tables or chains. Each table is explicitly defined, and contains only the objects (chains, sets, maps, flowtables and stateful objects) that you explicitly add to it.
- **A singles nftables rule can take multiple actions:** Each statement takes an action, such as setting the netfilter mark, counting the packet, logging the packet, or rendering a verdict such as accepting or dropping the packet or jumping to another chain. As with expressions, multiple statements are linearly evaluated from left to right: a single rule can take multiple actions by using multiple statements.
- **No built-in counter per chain and rule:** In nftables counters are optional, you can enable them as needed.
- **Better support for dynamic ruleset updates:** Adding or deleting a rule leaves the rest of the ruleset untouched, simplifying maintenance of internal state information.
- Simplified dual stack IPv4/IPv6 administration: The nftables inet family allows you to register base chains that see both IPv4 and IPv6 traffic. It is no longer necessary to rely on scripts to duplicate your ruleset.