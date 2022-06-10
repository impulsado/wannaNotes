**Title:** Debian WireGuard Client Set Up Script
**Tags:** [[WireGuard]]
**Topics:** #VPN #WireGuard #Script

---

```bash
#!/bin/bash

# new-client.sh

# This script generates the new users configuration file using the public key of the WireGuard server.
# It displays the user's public key and the pre-shared key.

# Script execution order:
# 1. wg-setup.sh (Server)
# 2. new-client.sh (Client)
# 3. add-client.sh (Server)

# Declare Variables
CLIENT_WG_IP_1=10.66.66.1

echo ""
read -p "SERVER PUBLIC KEY: " SERVER_PUB_KEY

SERVER_PUB_IP=172.25.0.21
SERVER_PORT=51820
SERVER_WG_IP=10.66.66.254

ENDPOINT="${SERVER_PUB_IP}:${SERVER_PORT}"

# Install paquets
# apt intall wireguard

# Generate Client Keys
CLIENT_PRIV_KEY=$(wg genkey)
CLIENT_PUB_KEY=$(echo "${CLIENT_PRIV_KEY}" | wg pubkey)
CLIENT_PRE_SHARED_KEY=$(wg genpsk)

# Create Client file and add the server as Peer
echo "[Interface]
PrivateKey = ${CLIENT_PRIV_KEY}
Address = ${CLIENT_WG_IP_1}/32

[Peer]
PublicKey = ${SERVER_PUB_KEY}
PresharedKey = ${CLIENT_PRE_SHARED_KEY}
Endpoint = ${ENDPOINT}
AllowedIps = ${SERVER_WG_IP}/24" >> "/etc/wireguard/wg0.conf"

#Bring Up WG interface
systemctl start wg-quick@wg0

# Show information
echo ""
echo "Client Public Key  ${CLIENT_PUB_KEY}"
echo "Client Preshared Key  ${CLIENT_PRE_SHARED_KEY}"
echo ""
```
