# Privilege Escalation
# SUID
Found a file with `find / -group bugtracker 2>/dev/null` that only members of `bugtracker` can execute. It has the SUID flag with root privileges.

```ad-info
SUID allows an alternate user to run an executable with the same permissions as the owner of the file instead of the permissions of the alternate user.
```

The file accept user input as a name of the file that will be read using `cat`, however, it does not specifies the whole path. Might be able to explo