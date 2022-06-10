**Title:** Debian WireGuard Add Client Script
**Tags:** [[WireGuard]]
**Topics:** #VPN #WireGuard #Script

---

```bash
#!/bin/bash

# add-client.sh

# From the public key and the user's preshared key, the WireGuard server ad>
# Script execution order:
# 1. wg-setup.sh (Server)
# 2. new-client.sh (Client)
# 3. add-client.sh (Server)

# Declare Variables
CLIENT_NAME=user
SERVER_WG_INT=wg0

echo ""
read -p "CLIENT PUBLIC KEY: " CLIENT_PUB_KEY
read -p "CLIENT PRE SHARED KEY: " CLIENT_PRE_SHARED_KEY
read -p "CLIENT IP: " CLIENT_WG_IP


# Add the client as peer to the server
echo -e "\n### Client ${CLIENT_NAME}
[Peer]
PublicKey = ${CLIENT_PUB_KEY}
PresharedKey = ${CLIENT_PRE_SHARED_KEY}
AllowedIPs = ${CLIENT_WG_IP}/32" >>"/etc/wireguard/${SERVER_WG_INT}.conf"

# Modify only new configuration to the wg interface.
wg syncconf "${SERVER_WG_INT}" <(wg-quick strip "${SERVER_WG_INT}")

echo ""
echo "WireGuard Configured Successfully!"
echo ""
```