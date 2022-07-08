**Title:** Debian WireGuard Server Set Up Script OLD
**Tags:** [[WireGuard]]
**Topics:** #WireGuard #Script 

---
# Debian WireGuard Server Set Up Script OLD
```bash
#!/bin/bash

# This script creates 3 users conf locally and also adds this clients as allowed in wg0.conf.
# Scritp Execution order:
# 1. wg-setup_old.sh (Server)
# 2. new-client.sh (Client)

# Declare Variables
SERVER_PUB_IP=192.168.0.1
SERVER_PORT=51820

SERVER_WG_INT=wg0
SERVER_WG_IP=10.66.66.254
SERVER_WG_MASK=24

CLIENT_NAME_1=user1
CLIENT_WG_IP_1=10.66.66.1
CLIENT_NAME_2=user2
CLIENT_WG_IP_2=10.66.66.2
CLIENT_NAME_3=user3
CLIENT_WG_IP_3=10.66.66.3

# Install paquets
# apt install -y wireguard

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

# Search user by $i variable
get_usr_ip() { local num; num="CLIENT_WG_IP_$i"; printf %s "${!num}"; }
get_usr_name() { local num; num="CLIENT_NAME_$i"; printf %s "${!num}"; }

# Generate Key Pair for the clients
for i in {1..3}; do
        ENDPOINT="${SERVER_PUB_IP}:${SERVER_PORT}"

        CLIENT_PRIV_KEY=$(wg genkey)
        CLIENT_PUB_KEY=$(echo "${CLIENT_PRIV_KEY}" | wg pubkey)
        CLIENT_PRE_SHARED_KEY=$(wg genpsk)

        #Create client file and add the server as Peer
        echo "[Interface]
PrivateKey = ${CLIENT_PRIV_KEY}
Address = $(get_usr_ip)/32

[Peer]
PublicKey = ${SERVER_PUB_KEY}
PresharedKey = ${CLIENT_PRE_SHARED_KEY}
Endpoint = ${ENDPOINT}
AllowedIps = ${SERVER_WG_IP}/29" >> "/home/user/user$i.conf"

        echo "user$i File Created!"

        # Add the client as peer to the server
        echo -e "\n### Client $(get_usr_name)
[Peer]
PublicKey = ${CLIENT_PUB_KEY}
PresharedKey = ${CLIENT_PRE_SHARED_KEY}
AllowedIPs = $(get_usr_ip)/32" >>"/etc/wireguard/${SERVER_WG_INT}.conf"

        wg syncconf "${SERVER_WG_INT}" <(wg-quick strip "${SERVER_WG_INT}")
done
echo ""
echo "Clients config file are in /home/user"
echo ""
```