# Intro
| Dificulty | OS | Start Date | End Date | Help? |
|---|---|---|---|---|
| Very Easy | Linux | 17/05/2022 | 17/05/2022 | No |


# Thought process
1. View running services with `nmap`.
2. LogIn to MariaDB using root (Doesn't need password)
3. `Show databases` and `use` one.
especificar nom usuari `-u`
logg in MariaDB without password= root
Entrar a MariaDB `mysql -h @IP -u uNAME`
Mostrar Base De Dades `SHOW DATABASES;`
Utilitzar Base de Dades `USE dNAME`
Mostrar Taules `SHOW TABLES;`
Fer select bàsic `SELECT * FROM tNAME;`