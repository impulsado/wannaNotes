**Title:** SSH
**Tags:** [[Hardening Services]]
**Topics:** #ssh #hardening_services

---
# SSH
Add this configuration to /etc/ssh/sshd_config:

```bash
# Protocolo 1 is older and less secure
Protocol 2

# Disable root login
PermitRootLogin no

# Only IPv4
AddressFamily inet

# Disable empty passwords to login
PermitEmptyPasswords  no

# Disable X11 Forwarding
X11Forwarding no

# Period of time before client gets disconnected (Seconds)
ClientAliveInterval 15

# Limit passwords attemp
MaxAuthTries 3

# Banner
Banner /etc/ssh/banner

# Server waiting time after a connection request is made (Seconds)
LoginGraceTime 20

# Checks some cases before the ssh server starts.
StrictModes yes
```
