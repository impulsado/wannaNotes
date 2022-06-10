**Title:** Windows WireGuard Client Set up Script
**Tags:** [[WireGuard]]
**Topics:** #VPN #WireGuard #Script

---

```powershell
# new-client.ps1

# This script generates the new users configuration file using the public key of the WireGuard server.
# It displays the user's public key and the pre-shared key.

# Script execution order:
# 1. wg-setup.sh (Server)
# 2. new-client.ps1 (Client)
# 3. add-client.sh (Server)

# Without doing this, it can't generate public key
Set-ExecutionPolicy Unrestricted -Scope CurrentUser

# Declare Variables
$CLIENT_WG_IP_2 = "10.66.66.2"

Write-Output ""
$SERVER_PUB_KEY = Read-Host "SERVER PUBLIC KEY: "

$SERVER_PUB_IP = "172.25.0.21"
$SERVER_PORT = "51820"
$SERVER_WG_IP = "10.66.66.254"

# Añadir el valor de la variable $SERVER_PUB_IP + $SERVER_PORT" separada por ":" a la variable $ENDPOINT
$ENDPOINT = $SERVER_PUB_IP + ":" + $SERVER_PORT

# Must need WireGuard Client Software
# https://www.wireguard.com/install/

# Generate Client Keys
wg genkey | Tee-Object usr_priv.key | wg pubkey > usr_pub.key

$CLIENT_PRIV_KEY = (Get-Content usr_priv.key)
$CLIENT_PUB_KEY = (Get-Content usr_pub.key)
$CLIENT_PRE_SHARED_KEY = wg genpsk

# Delete keys files
Remove-Item usr_priv.key
Remove-Item usr_pub.key

# Create Client file and add the server as Peer
Write-Output "
[Interface]
PrivateKey = $CLIENT_PRIV_KEY
Address = $CLIENT_WG_IP_2/32

[Peer]
PublicKey = $SERVER_PUB_KEY
PreSharedKey = $CLIENT_PRE_SHARED_KEY
Endpoint = $ENDPOINT
AllowedIPs = $SERVER_WG_IP/24" >> ".\wg0.conf"

# Bring Up WG interface
wireguard /installtunnelservice C:\Users\rex\Desktop\wg0.conf

# Show information
Write-Output ""
Write-Output "Client Public Key:  $CLIENT_PUB_KEY"
Write-Output "Client Pre-Shared Key:  $CLIENT_PRE_SHARED_KEY"
Write-Output ""
```