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
| System | System itself | System has been shuted down. |

### Linux
