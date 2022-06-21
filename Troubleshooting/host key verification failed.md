**Title:** host key verification failed
**Tags:** [[Troubleshooting]]
**Topics:** #ssh #Troubleshooting 

---
# host key verification failed
```bash
   WARNING: REMOTE HOST IDENTIFICATION HAS CHANGED!    
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
IT IS POSSIBLE THAT SOMEONE IS DOING SOMETHING NASTY!
Someone could be eavesdropping on you right now (man-in-the-middle attack)!
It is also possible that a host key has just been changed.
The fingerprint for the ECDSA key sent by the remote host is
XX:XX:XX:XX:XX:XX:XX:XX:XX:XX:XX:XX:XX:XX: (Omitted).
Please contact your system administrator.
Add correct host key in /home/guest/.ssh/known_hosts to get rid of this message.
Offending ECDSA key in /home/guest/.ssh/known_hosts:2
  remove with: ssh-keygen -f "/home/guest/.ssh/known_hosts" -R username.no-ip.org
ECDSA host key for username.no-ip.org has changed and you have requested strict checking.
Host key verification failed.
```

## Solution
1. Local machine, run:
```powershell
ssh-keygen -R @IP
```

2. Done