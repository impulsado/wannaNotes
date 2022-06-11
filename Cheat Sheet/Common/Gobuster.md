**Title:** Gobuster
**Tags:** [[Common]]
**Topics:** #Cheat_Sheet #gobuster #dirbuster

---
# DirBuster
Bruteforce directorys and files in a server or application.
Common --> `/usr/share/wordlists/dirb/common.txt`
[//]:  Do not check .git files.

> Basic
```bash
$ gobuster dir -u @IP/Domain -w /path/to/wordlist
```

## Best Wordlist
[SecLists](https://github.com/danielmiessler/SecLists) Discovery lists. 
Common --> `/usr/share/seclists/Discovery/Web-Content/raft-small-words.txt`
Larger --> `/usr/share/seclists/Discovery/Web-Content/raft-large-words.txt`
Tomcat --> `/usr/share/seclists/Discovery/Web-Content/tomcat.txt`


## Target Extensions
If site is using X file extension you can use `-x`

> Basic Target php
```bash
$ gobuster dir -u @IP/Domain -w /path/to/wordlist -x php
```

# VHOST Busting
Brute force Virtual Hosts (subdomains).
Append subdomains to the beginning of Domain.
Common --> `/usr/share/seclists/Discovery/DNS/subdomains-top1million-110000.txt`

> Basic
```bash
$ gobuster vhost -u @IP/Domain -w /path/to/wordlist
```