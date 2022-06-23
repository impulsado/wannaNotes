**Title:** iptables vs nftables
**Tags:** [[Firewall]]
**Topics:** #FireWall 

---
# iptables vs nftables
## iptables
IPtables is a command line utility that is used for configuring firewall rules, usually in combination with a frontend. IPtables is able to inspect, modify or drop network packets. The “tables” consist of “chains” which contain "rules" that are processed in the defined order.
Rules are basically conditions that have to be true respectively to match a defined action to be executed. All incoming packets, regardless the source (internal/internet), are being processed by the very same rules.
Tables:
- raw
- filter (important)
- NAT (important)
- mangle
- security

## nftables
Nftables (developed by netfilter/IPtables) is a package filtering framework. It was basically built to replace the old IPtables, because IPtables had several problems in terms of performance and scalability.