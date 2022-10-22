**Title:** Windows Fundamentals 1
**Tags:** [[CyberDefense]]
**Topics:** #Windows #CyberDefense 

---
# Windows Fundamentals 1
## Introduction
Microsoft will continue to support at least one Windows 10 Semi-Annual Channel until October 14, 2025.
You can only use BitLocker in Windows 10/11 Pro.

## File System
The file system used is NTFS (New Technology File System). 
NTFS is known as a journaling file system. In case of a failure, the file system can automatically repair the folders/files on disk using information stored in a log file. This function is not possible with FAT.

Characteristics:
- Supports files larger than 4 GB
- Set specific permissions on folders and files
- Folder and file compression
- Encryption (EFS)

Permissions are:
- Full Control
- Modify
- Read & Execute
- List Folder contents
- Read
- Write 

![[Pasted image 20221022184558.png]]
Another feature of NFTS is ADS (Alternate Data Streams). Allows storing metadata along with the file, and isn't necessary to have separate files.
These are not vi

## System32
`C:\Windows` is known as the folder which contains Windows O.S. files. 
It can be located in a different folder or drive.
Environment variables store information about the operating system environment. This information includes details such as the operating system path, location of temporary folders…
`%windir` → Windows Directory

## User Account Control
The Majority of home users are logged in with Administrator privileges. To protect the local user, Microsoft introduced User Account Control (UAC).
[//]: UAC (by default) doesn't apply for the built-in local administrator account.
