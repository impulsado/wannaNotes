**Title:** Debian WireGuard Client Set Up Script OLD
**Tags:** [[WireGuard]]
**Topics:** #WireGuard #Script 

---
# Debian WireGuard Client Set Up Script OLD
```bash
#!/bin/bash

# User inputs .conf file and the script brings up the wireguard interface.

# Script execution order:
# 1. wg-setup_old.sh (Server)
# 2. new-client_old.sh (Client)

# Install paquets
# apt install -y wireguard

# Declare variables
FILE="/home/user/user1.conf"
WG_INT_NAME="wg0"

# Move user conf to /etc/wireguard as $WG_INT_NAME
mv $FILE /etc/wireguard/$WG_INT_NAME.conf

# Bringup $WG_INT_NAME up
systemctl start "wg-quick@${WG_INT_NAME}"
systemctl enable "wg-quick@${WG_INT_NAME}"
```