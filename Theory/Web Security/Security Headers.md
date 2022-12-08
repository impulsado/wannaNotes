**Title:** Security Headers
**Tags:** [[Web Security]]
**Topics:** #Web_Security 

---
# Security Headers
Security headers are directives used by web applications to configure security defenses in web browsers. Based on these directives, browsers can make it harder to exploit client-side vulnerabilities such as Cross-Site Scripting or Clickjacking. Headers can also be used to configure the browser to only allow valid TLS communication and enforce valid certificates, or even enforce using a specific server certificate.

## HTTP Strict Transport Security (HSTS)
HTTP Strict Transport Security is a header that configures the web browser to always use a valid secure connection with the web application. If the server TLS certificate suddenly becomes expired or untrusted, the browser will no longer connect to the web application. Also, if the user attempts to access the web application using an http:// url, the browser will automatically change it to https://. These countermeasures help prevent Man-in-the-middle attacks as well as other attacks such as Session Hijacking.

## Content Security Policy (CSP)
Content-Security-Policy is the name of a HTTP response header that modern browsers use to enhance the security of the document (or web page). The Content-Security-Policy header allows you to restrict how resources such as JavaScript, CSS, or pretty much anything that the browser loads. Prevent client-side attacks, such as Cross-Site Scripting and Clickjacking, by restricting the type of content the browser is allowed to include or execute.

## Permission Policy
Permissions Policy Header is an added layer of security that helps to restrict from unauthorized access or usage of browser/client features by web resources. This policy ensures the user privacy by limiting or specifying the features of the browsers can be used by the web resources. Permissions Policy provides a set of standard HTTP headers that allow website owners to limit which features of browsers can be used by the page such as camera, microphone, location, full screen etc.
