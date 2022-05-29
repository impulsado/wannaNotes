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

> Download a File
```bash
$ smbclient '//Target_IP/Share' -c 'lcd [DOWNLOAD_PATH]; cd [DIRECTORY]; get [FILENAME]'
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