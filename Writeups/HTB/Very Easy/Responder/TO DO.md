si busco la ip en el navegador em redirecciona amb un domini.

editar el /etc/hosts amb la relacio

php for scripting webpage

[Veure mes sobre php]
LFI?
https://github.com/carlospolop/Auto_Wordlists/blob/main/wordlists/file_inclusion_windows.txt

NTLM
include()
https://www.php.net/manual/en/function.include.php

https://www.ionos.com/digitalguide/server/know-how/ntlm-nt-lan-manager/

Instal·lar responder = caturar hash del NTLM

john per hash (John The Ripper)

Connectar-se a la maquina utilitzant WinRM (aplicació EvilWinRM)
[//]: Powershell no està instal·lat en windows sino seria: ?????FERRRRRRRr

```bash
$ evil-winrm -i 10.129.52.23 -u administrator -p badminton
```

en el directori no hi ha res i anem al user mike on alli té la flag