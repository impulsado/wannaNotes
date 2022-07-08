**Title:** Windows WireGuard Client Set Up Script OLD
**Tags:** [[WireGuard]]
**Topics:** #WireGuard #Script 

---
# Windows WireGuard Client Set Up Script OLD
```powershell
# new-client_old.ps1

# User inputs .conf file and the script brings up the wireguard interface.

# Script execution order:
# 1. wg-setup_old.sh (Server)
# 2. new-client_old.ps1 (Client)

# Declare Variables
$FILE = "C:\Users\rex\Desktop\user1.conf"
$WG_INT_NAME = "wg0"

# Rename user file to $WG_INT_NAME.conf
Rename-Item -Path $FILE -NewName $WG_INT_NAME.conf

# Bring Up WG interface
wireguard /installtunnelservice C:\Users\rex\Desktop\wg0.conf
```