**Title:** 00 - Crocodile
**Tags:** [[Very Easy]]
**Topics:** #php #ftp 

---

# Intro
| Dificulty | OS | Start Date | End Date | 
|---|---|---|---|
| Very Easy | Linux | 17/05/2022 | 17/05/2022 |


# Thought process
1. View running services with `nmap`.
2. Connect with `ftp`(Anonymous User).
3. List Directories and `get` interesting files. (Usernames+Password File)
4. `Dirbust` @IP to find if there's any `login.php`.
5. Login as "admin".


# Resolution
After checking which ports are open, I make an ftp connection using "anonymous" username.
```bash
$ ftp @IP
```

I listed the Directories `ls` and downloaded the username and password files `get`.
[lcd]: Change directory on your local system.

The web didn't display any LogIn so I `dirbust` trying to find any `.php`
```bash
$ gobuster dir -u @IP/Domain -w /path/to/wordlist -x php
```

In the end it found a file called `login.php` so I typed it in the browser. Once there, I tried with the user "admin" which was in the files.


# Others
Users could connect to the FTP server anonymously if the server is configured to allow it, meaning that we could use it even if we had no valid credentials. (nmap shows if it's possible).