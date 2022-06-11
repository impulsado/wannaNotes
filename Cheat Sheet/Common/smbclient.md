**Title:** smbclient
**Tags:** [[Common]]
**Topics:** #Cheat_Sheet #smb

---
# smbclient
Tool used to connect to Samba servers - Samba is a Windows-based filesharing protocol.

## Basic Syntax
> Connect to Server
```bash
$ smbclient //@Target_IP
```

> Connect to specific share
```bash
$ smbclient //@Target_IP/Share
```

> Check Samba Resources
```bash
$ smbclient -N -L @Target_IP
```
[-N]: Suppresess the normal password prompt from the client to the user
[-L]: List what services are aviable

> Download File
```bash
$ smbclient '//@Target_IP/SHARE' -c 'lcd DOWNLOAD_PATH; cd DIRECTORY; get FILENAME'
```
[-c]: Run serie of commands

> Upload File
```bash
$ smbclient '//@Target_IP/SHARE' -c 'cd REMOTE_PATH; lcd LOCAL_DIRECTORY; put LOCAL_FILENAME'
```

> Mount Share
```bash
$ sudo mkdir /mnt/SHARE

$ sudo apt install cifs-utils

$ sudo mount -t cifs //@Target_IP/SHARE /mnt/SHARE
```

## Commands
> Download
```bash
smb: \> get FILE
```

> Upload
```bash
smb: \> put FILE 
```
[//]: File must be in the local machine's current working directory.

> Navigate
```bash
smb: \> dir
```

> Change Directory Locally
```bash
smb: \> lcd LOCAL_DIRECTORY_PATH
```