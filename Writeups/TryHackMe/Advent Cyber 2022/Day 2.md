**Title:** Day 2
**Tags:** [[Advent Cyber 2022]]
**Topics:** #TryHackMe 

---
# Log Files
Useful for:
- Login attempts or failures.
- Traffic on a network.
- List of accessed things.
- Password changes.
- Application errors.

Format:
```log
Nov 13 00:00:00 sshd: Invalid user from 18.32.1.2 port 22
```

## Common Locations
### Windows
Windows Feature is an application that allows to access historical records.
| Category | Description | Example |
| ---  | --- | --- |
| Application | Related to applications on the system | "word.exe" was restarted. |
| Security | System's security. E.j. Wrong cred. | "impu" successfully logged in. |
| Setup | System maintenance | System must be restarted to apply new security configuration |
| System | System itself | System has been shut down. |

### Linux
Located in `/var/log`.

| Category | Description | File | Example |
| Authentication | Authentication (log in). | auth.log | Failed password for root from 192.168.1.2 port 22 |
| Package Managment | Package managment. Installing packages. Useful for debugging | dpkg.log | 2022-12-06 installed apache2 |
| Syslog | Events related to thing happening in the system's background | syslog | 2022-12-06 Finished daily update |
| Kernel | Kernel events on the system. Changes or the output from devices. | kern