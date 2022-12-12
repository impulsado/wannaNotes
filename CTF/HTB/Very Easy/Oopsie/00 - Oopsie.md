---
layout: post
title: 00 - Oopsie
date: 2022-08-20
categories: [Writeups,HTB,Very_Easy,Oopsie]
tags: [php,SUID]
---
**Title:** 00 - Oopsie
**Tags:** [[Very Easy]]
**Topics:** #PHP #SUID 

---
# 00 - Oopsie
# Intro
| Dificulty | OS | Start Date | End Date | 
|---|---|---|---|
| Very Easy | Linux | 03/06/2022 | 05/06/2022 |


# Process
1. Common enumeration.
2. Use Burp Suite to find new directories.
3. Manipulate cookies to be admin and upload files.
4. Dirbust the site to find where are the uploads located.
5. Upload reverse shell
6. Search for other users
7. Login with that user and search the user flag.
8. Privilege Escalation with SUID.


# Burpsuite
1. Configure Firefox to send traffic trought the proxy.
2. Settings > Search "Proxy" > Settings.
3. Change to Manual proxy. Enter Loopback @IP and port 8080
4. Disable interception in Burp as it's 
5. Proxy > Intercept > Intercept in on (Disable)


# Cookies 
Found that admin was id=34322 so change the Guest id to simulate he's the admin.
![[Assets/Pasted image 20220530192240.png]]



# Reverse Shell
Search for common directories. This is a Web Server so is a good idea to check `/var/www/html/xxx/`. 
There is a username and a password. Login as robert and search the ``user.txt``.

Find the user group and the files that belong to it.
Found executable file in `/usr/bin/` named `bugtracker` that only `bugtracker` group can 
execute.
