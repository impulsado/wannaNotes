# nmap
Check ports status of a certain @IP or range @IP.

## Commands
It shows ports as it finds them with the `-v` flag, tries to enumerate service versions and runs some default scripts, and then outputs the results with nmap format.
> General Purpose
```bash
$ namp -v -p- -sC -sV -oA nmap @IP/Domain
```
[-v]: Show ports as it finds them.
[-p-]: Check all ports (65535).
[-sV]: Find protocol version running behind the port.
[-sC]: Use Default Script.
[-oA nmap]: Save as nmap.


#Cheat_Sheet #nmap
