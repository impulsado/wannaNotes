# nmap
A tool for discovering what services are running on each port for a given host.

## Commands
### General Purpose
```bash
$ namp -v -p- -sC -sV -oA nmap @IP/Domain
```

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

[-v]: Show ports as it finds them.
[-p-]: Check all ports (65535).
[-sV]: Find protocol version running behind the port.
[-sC]: Use Default Script.
[-oA nmap]: Save as nmap.



#Cheat_Sheet #nmap
