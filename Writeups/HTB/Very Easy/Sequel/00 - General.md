# Intro
| Dificulty | OS | Start Date | End Date | Help? |
|---|---|---|---|---|
| Very Easy | Linux | 17/05/2022 | 17/05/2022 | No |


# Thought process
1. View running services with `nmap`.
2. LogIn to MariaDB using root (Doesn't need password)
3. `Show databases` and `use` one.
4. `Select` content of the tables.


# Resolution
After seeing that the machine had a MariaDB server, I tried to login as root (by default it has no password).

> LogIn to MariaDB
```sql

```

especificar nom usuari `-u`
logg in MariaDB without password= root
Entrar a MariaDB `mysql -h @IP -u uNAME`
Mostrar Base De Dades `SHOW DATABASES;`
Utilitzar Base de Dades `USE dNAME`
Mostrar Taules `SHOW TABLES;`
Fer select bàsic `SELECT * FROM tNAME;`