**Title:** IPSec Script Debian Server
**Tags:** [[IPSec]]
**Topics:** #IPSec #Script 

---
# IPSec Script Debian Server
```bash
#!/bin/bash

# ipsec-deb-server.sh

# Setup IKEv2/IPSec VPN using strongswan. Generates server certificate and register VPN user. Linux client only.

# Install resources
apt install -y strongswan strongswan-pki

# Declare Variables
IP="192.168.0.1"
S_NET="192.168.0.1/32"
C_NET="192.168.0.2/32"
VPN_USER="user"
VPN_PASS="123456aA"

# Create CA and Certificate
mkdir -p /root/pki/{cacerts,certs,private}
chmod 700 /root/pki
pki --gen --type rsa --size 4096 --outform pem > /root/pki/private/ca-key.pem  # CA Certificate
pki --self --ca --lifetime 3650 --in /root/pki/private/ca-key.pem --type rsa --dn "CN=VPN root CA" --outform pem > /root/pki/cacerts/ca-cert.pem  # self-signed CA
pki --gen --type rsa --size 4096 --outform pem > /root/pki/private/server-key.pem  # End Entity
pki --pub --in /root/pki/private/server-key.pem --type rsa | pki --issue --lifetime 1825 --cacert /root/pki/cacerts/ca-cert.pem --cakey /root/pki/private/ca-key.pem --dn "CN=${IP}" --san ${IP} --flag serverAuth --flag ikeIntermediate --outform pem > /root/pki/certs/server-cert.pem
cp -r /root/pki/* /etc/ipsec.d/

# Configure strongSwan VPN
cat <<EOF > /etc/ipsec.conf
config setup
    charondebug="ike 1, knl 1, cfg 0"
    uniqueids=no

conn ikev2-vpn
    auto=add
    compress=no
    type=tunnel
    keyexchange=ikev2
    fragmentation=yes
    forceencaps=yes
    dpdaction=clear
    dpddelay=300s
    rekey=no
    # SERVER
    left=%any
    leftid=${IP}
    leftcert=server-cert.pem
    leftsendcert=always
    leftsubnet=${S_NET}
    # CLIENT
    right=%any
    rightid=%any
    rightauth=eap-mschapv2
    rightsourceip=${C_NET}
    rightsendcert=never
    eap_identity=%identity  # Ask clients for user credentials
    ike=chacha20poly1305-sha512-curve25519-prfsha512,aes256gcm16-sha384-prfsha384-ecp384,aes256-sha1-modp1024,aes128-sha1-modp1024,3des-sha1-modp1024!
    esp=chacha20poly1305-sha512,aes256gcm16-ecp384,aes256-sha256,aes256-sha1,3des-sha1!
EOF

cat <<EOF > /etc/ipsec.secrets
: RSA "server-key.pem"
${VPN_USER} : EAP "${VPN_PASS}"
EOF

systemctl restart strongswan-starter
```