# Intro
| Dificulty | OS | Start Date | End Date | Help? |
|---|---|---|---|---|
| Very Easy | Windows | 24/05/2022 | 24/05/2022 | Yes |


# Thought process
1. View running services with `nmap`.
2. Edit `/etc/hosts` for being able to see the web.
3. Check how web works and think if I can attack doing File Inclusion.


# Resolution
Edit `/etc/hosts` like this:
```bash
@IP unika.htb
```


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


php for scripting webpage

[Veure mes sobre php]
LFI?
https://github.com/carlospolop/Auto_Wordlists/blob/main/wordlists/file_inclusion_windows.txt

NTLM
include()
https://www.php.net/manual/en/function.include.php

https://www.ionos.com/digitalguide/server/know-how/ntlm-nt-lan-manager/

Instal·lar responder = caturar hash del NTLM

john per hash (John The Ripper)

Connectar-se a la maquina utilitzant WinRM (aplicació EvilWinRM)
[//]: Powershell no està instal·lat en windows sino seria: ?????FERRRRRRRr

```bash
$ evil-winrm -i 10.129.52.23 -u administrator -p badminton
```

en el directori no hi ha res i anem al user mike on alli té la flag