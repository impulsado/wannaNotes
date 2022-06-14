# namp

> Know MV @IP
```bash
$ sudo nmap -sn 192.168.40.0/23 > arp
```
[//]: Check @MAC in the Virtual Box Adapter.

> Port enumeration
```bash
$ sudo nmap -p- --open -sS --min-rate 5000 -vvv -n -Pn 192.168.41.103 -oG allPorts
```

```bash
$ nmap -sCV -p21,22,80 10.129.95.174 -oN nmap/targeted

