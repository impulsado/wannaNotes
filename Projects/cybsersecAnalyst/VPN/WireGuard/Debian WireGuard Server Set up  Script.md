**Title:** Debian WireGuard Server Set up Script
**Tags:** [[WireGuard]]
**Topics:** #WireGuard #Script

---
```bash
#!/bin/bash

# wg-setup.sh

# This script configures the device as a WireGuard server and provides the user with the public key of the server.

# Script execution order:
# 1. wg-setup.sh (Server)
# 2. new-client.sh (Client)
# 3. add-client.sh (Server)


# Declare Variables
SERVER_PORT=51820
SERVER_WG_INT=wg0
SERVER_WG_IP=10.66.66.254
SERVER_WG_MASK=24

  
# Install paquets
# apt install wireguard


# Make sure directory exists
mkdir /etc/wireguard >/dev/null 2>&1


# Change permission
chmod 600 -R /etc/wireguard


# Generate Keys
SERVER_PRIV_KEY=$(wg genkey)
SERVER_PUB_KEY=$(echo "${SERVER_PRIV_KEY}" | wg pubkey)


# Add WireGuard Server Interface
echo "[Interface]
Address = ${SERVER_WG_IP}/${SERVER_WG_MASK}
ListenPort = ${SERVER_PORT}
PrivateKey = ${SERVER_PRIV_KEY}" >"/etc/wireguard/${SERVER_WG_INT}.conf"

  
# Bring up WireGuard Interface.
systemctl start "wg-quick@${SERVER_WG_INT}"
systemctl enable "wg-quick@${SERVER_WG_INT}"

  
# Check if WireGuard is running
systemctl is-active --quiet "wg-quick@${SERVER_WG_INT}"
WG_RUNNING=$?


# Show Information
echo ""
echo "Server Public Key  ${SERVER_PUB_KEY}"
echo ""
```