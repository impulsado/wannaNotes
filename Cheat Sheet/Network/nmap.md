**Title:** nmap
**Tags:** [[Network]]
**Topics:** #nmap

---
# nmap
A tool for discovering what services are running on each port for a given host.

## Commands
### General Purpose
It shows ports as it finds them with the `-v` flag, tries to enumerate service versions and runs some default scripts, and then outputs the results with nmap format.
```bash
$ namp -v -p- -sC -sV -oA nmap @IP/Domain
```
[-p-]: Check all ports (65535)

### Extra
`nmap` is capable of running several scripts for enumerating extra information about a service. Specify the `-sC` flag to run default scripts:
```bash
$ nmap -sC a.b.c.d
```

`nmap` can also enumerate the versions of software running on a port. Use the `-sV` flag to do this:
```bash
$ nmap -sV a.b.c.d
```

`nmap` can also enumerate an operating system, using the `-O` flag:
```bash
$ nmap -O a.b.c.d
```

Some services run only over UDP, and may be missed by a standard TCP scan. Scan UDP with the `-sU` flag:
```bash
$ nmap -sU a.b.c.d
```