**Title:** Day 5 - THM 2022
**Tags:** [[Advent Cyber 2022]]
**Topics:** #THM_Advent_2022 #Brute-forcing

---
# Remote Access Services
Common remote access protocols:
- **SSH**: Secure Shell. Used in Unix OS. Provides command line interface (CLI).
- **RDP**: Remote Desktop Protocol. Provides graphical user interface (GUI). Used to access MS Windows System.
- **VNC**: Virtual Network Computing. It allows GUI control for almost every OS.

# Authentication
System validates user identity. The user need to prove their identity, this process is achieved by one, or more, of the following:
- **Something you know**: Can memorize, such as a password or PIN.
- **Something you have**: Something you own, hardware or software, such as security token, mobile phone.
- **Something you are**: Biometric authentication, such as fingerprint or retina scan.

# Attacking Passwords
Some attacks don't require technical skills. Other attacks require the use of automated tools.
- **Shoulder Surfing**: Looking over the victim's shoulder in order to see his password.
- **Password Guessing**: Some people might be inclined to use personal details for your passwords. If you have some knowledge of target personal details, you can know his password.
- **Dictionary attack**: Use a password dictionary to try every single one in order to crack the password. (rockyou.txt)
- **Brute Force Attack**: Try all possible character combinations. It is the most exhaustive.

# Hacking an Authentication Service
1. We first need to know if the target has some open port that could be vulnerable. To know that information, we can use `nmap`. Nmap has also some scripts to know common vulnerabilities while scanning ports.
"nmap -sS @IP"

2. After listing the open ports, we can use `THC hydra` to try common passwords or the entries of a word list.
"hydra -l [username] -P wordlist.txt @IP [service]"