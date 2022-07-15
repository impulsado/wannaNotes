**Title:** lighttpd
**Tags:** [[Hardening Services]]
**Topics:** #lighttpd #hardening_services 

---
# lighttpd
Add this configuration to /etc/lighttpd.d:

```bash
# === LOGGING ===
# error log
server.errorlog = "/var/log/lighttpd/error.log"

# Log blocked IP in errorlog
evasive.silent = "disable" 

# === CONNECTION ===
# Max number of retries before disconnect
server.max-keep-alive-requests = 6

# Max number of seconds until a idling keep-alive connection is dropped
server.max-keep-alive-idle = 15

# Max number of seconds until a waiting read call times out and closes the connection.
server.max-read-idle = 15

# Max number of seconds until a waiting write call times out and closes the connection.
server.max-write-idle = 15

# Max concurrent connections the server will accept
server.max-connections = 1

# Single connection bandwidth limit in kilobytes (0=unlimited)
connection.kbytes-per-second = 0

# Global server bandwidth limit in kilobytes (0=unlimited)
server.kbytes-per-second = 0

# Max connections made by the same IP.
evasive.max-conns-per-ip = 250

# Limit request method "POST" size in kilobytes (KB)
server.max-request-size = 64

# Disable multi range requests
server.range-requests    = "disable"
```