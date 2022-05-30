# Principal
proxy per interceptar tràfic web (Fer explicació)

https://www.youtube.com/watch?v=YmZLdJRBKv0&t=3953s&ab_channel=S4viOnLive 43:07 sudo

Mirar info sobre cookies

Maybe file inclusion? For later?

# Process
1. Common enumeration
2. Use Burp Suite to find new directories (Can use Burpsuite too)
3. Manipulate cookies to be admin.


# Burpsuite
1. Configure Firefox to send traffic trought the proxy.
2. Settings > Search "Proxy" > Settings.
3. Change to Manual proxy. Enter Loopback @IP and port 8080
4. Disable interception in Burp as it's 
5. Proxy > Intercept > Intercept in on (Disable)

# Cookies 
Found that admin was id=34322 so change the Guest id to simulate he's the admin.
![[Pasted image 20220530192240.png]]