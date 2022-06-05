# Burp Suite
Security testing application that can be used to perform web requests on web  
applications, mobile apps, and thick clients. Burp offers multiple capabilities such as web crawler, scanner,  proxy, repeater, intruder and many more. 
More Information [Link](https://www.geeksforgeeks.org/what-is-burp-suite/)


## Tools
### Spider
Used to map the target web application. The objective of the mapping is to get a list of endpoints so that their functionality can be observed and potential vulnerabilities can be found.
```
A web crawler (also known as a web spider or web robot) is a program or automated script which browses the World Wide Web in a methodical, automated manner. This process is called Web crawling or spidering. Many legitimate sites, in particular search engines, use spidering as a means of providing up-to-date data.
```

### Proxy
Intercepting proxy that lets the user see and modify the contents of requests and responses while they are in transit. The proxy server can be adjusted to run on a specific loop-back ip and a port.

### Intruder
It is a fuzzer. This is used to run a set of values through an input point. The values are run and the output is observed for success/failure and content length.
The intruder is used for:
-   Brute-force attacks on password forms, pin forms, and other such forms.
-   The dictionary attack on password forms, fields that are suspected of being vulnerable to XSS or SQL injection.
-   Testing and attacking rate limiting on the web-app.

### Repeater
Lets a user send requests repeatedly with manual modifications.
The Repeater is used for:
-   Verifying whether the user-supplied values are being verified.
-   If user-supplied values are being verified, how well is it being done?
-   What values is the server expecting in an input parameter/request header?
- [More]


# Tags
#Burp_Suite #Cheat_Sheet 