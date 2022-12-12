**Title:** Firewall
**Tags:** [[cybersecAnalyst]]
**Topics:** #Firewall 

---
# Firewall
nftables is a netfilter project that aims to replace the existing {ip,ip6,arp,eb}tables framework. It provides a new packet filtering framework, a new user-space utility (nft), and a compatibility layer for {ip,ip6}tables. It uses the existing hooks, connection tracking system, user-space queueing component, and logging subsystem of netfilter.

nftables user-space utility nft performs most of the rule-set evaluation before handing rule-sets to the kernel. Rules are stored in chains, which in turn are stored in tables.

## Tables
Tables hold chains. Unlike tables in iptables, there are no built-in tables in nftables. The number of tables and their names is up to the user. However, each table only has one address family and only applies to packets of this family.

| nftables family |  |
| --- |--- |
| ip (Only IPv4) |  |
| ip6 (Only IPv6) | |
| inet (IPv4 and IPv6) | |
| arp | |
| bridge | |

## Chains
The purpose of chains is to hold Rules. Unlike chains in iptables, there are no built-in chains in nftables. This means that if no chain uses any types or hooks in the netfilter framework, packets that would flow through those chains will not be touched by nftables, unlike iptables.

Chains have two types. A base chain is an entry point for packets from the networking stack, where a hook value is specified. A regular chain may be used as a jump target for better organization.

## Rules
Rules are either constructed from expressions or statements and are contained within chains.
Sets
Sets are named or anonymous, and consist of one or more elements, separated by commas, enclosed by curly braces. Anonymous sets are embedded in rules and cannot be updated, you must delete and re-add the rule.

# Resources
## General Information
[nftables wiki](https://wiki.nftables.org/wiki-nftables/index.php/Main_Page)
[Configure Chains](https://wiki.nftables.org/wiki-nftables/index.php/Configuring_chains)
[IP Filter Based Firewalls HOWTO](https://www.opennet.ru/base/net/ipf-howto.txt.html)
[Getting started with nftables](https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/8/html/configuring_and_managing_networking/getting-started-with-nftables_configuring-and-managing-networking)
[Quick nftables references](https://wiki.nftables.org/wiki-nftables/index.php/Quick_reference-nftables_in_10_minutes)

## Specific information
[Kernel information](https://wiki.nftables.org/wiki-nftables/index.php/Building_and_installing_nftables_from_sources)
[Connection tracking](https://thermalcircle.de/doku.php?id=blog:linux:connection_tracking_3_state_and_examples)
[Port Knocking example](https://wiki.nftables.org/wiki-nftables/index.php/Port_knocking_example)
[nftables hardening rules and good practices](https://blog.samuel.domains/blog/security/nftables-hardening-rules-and-good-practices)
