```
smbclient -N -L @IP
```
Veure desde Linux el Samba Server.
Això llista els disc/impresores que poden compartir amb l'usuari.
[-L]: Per especificar host
[-N]: NOSE

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







# FINDS
ARCHETYPE\sql_svc = M3g4c0rp123

mssqlclient.py (Estavlir conexio autentificada amb el servidor SQL)
xp_cmdshell (Executar Consola de Comandos de Windows en Microsoft SQL)
winpeas (Privilegie Escalation)








