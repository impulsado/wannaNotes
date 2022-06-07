**Title:** Set Up WireGuard
**Tags:** [[WireGuard]]
**Topics:** 

---

# Set Up WireGuard
1. Install WireGuard
```bash
# apt install wireguard
```

2. Create private key for WireGuard and change the permission:
```bash
# wg genkey | tee /etc/wireguard/private.key
# chmod go= /etc/wireguard/private.key
```
