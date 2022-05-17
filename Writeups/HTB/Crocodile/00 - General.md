# Intro
| Dificulty | OS | Start Date | End Date | Help? |
|---|---|---|---|---|
| Very Easy | Linux | 17/05/2022 | 17/05/2022 | No |


# Thought process
1. View running services with `nmap`.
2. Connect with `ftp`(Anonymous User).
3. List Directories and `get` interesting files. (Usernames+Password File)
4. `Dirbust` @IP to find if there's any `login.php`.
5. Login as "admin".


# Resolution
After checking which ports are open, I make an ftp connection. 
```bash
ftp -h @IP
```


# Tags
#ftp
mirar que es lo de anonyumous code
descarregar coses amb ftp `get`
wappalyzer per analitzar webs
per entrar en ftp sense contrasenya username = anonymous




fer common de ftp
https://linuxize.com/post/how-to-use-linux-ftp-command-to-transfer-files/