**Title:** IPSec Script Debian Client
**Tags:** [[IPSec]]
**Topics:** #IPSec #Script 

---
# IPSec Script Debian Client
```bash
#!/bin/bash

# ipsec-client.sh

# Setup IKEv2/IPSec client using strongswan. Script needs Server .pem file.

# Install Resources
apt install -y strongswan

# Declare variables
SERVER_IP="192.168.0.1"
S_NET="192.168.0.1/32"
VPN_USER="user"
VPN_PASS="123456aA"
PORT="500"  # Default IPSec port = 500

# Copy file
scp user@${SERVER_IP}:/etc/ipsec.d/cacerts/ca-cert.pem /etc/ipsec.d/cacerts

# Configure strongSwan
cat <<EOF > /etc/ipsec.secrets
${VPN_USER} : EAP "${VPN_PASS}"
EOF

cat <<EOF > /etc/ipsec.conf
conn ipsec-ikev2-vpn-client
    auto=start
    # SERVER
    right=${SERVER_IP}
    rightid=${SERVER_IP}
    rightsubnet=${S_NET}
    # rightikeport=${PORT}
    # CLIENT
    leftsourceip=%config
    leftid=${VPN_USER}
    leftauth=eap-mschapv2
    eap_identity=%identity
EOF

systemctl restart strongswan-starter
```
