# Intro
| Dificulty | OS | Start Date | End Date | Help? |
|---|---|---|---|---|
| Very Easy | Linux | 15/05/2022 | 15/05/2022 | Yes |


# Thought process
1. View running services with nmap.
2. List database KEYS.
3. Get the value of the KEY.


# redis
Redis is an 'in-memory' data structure store which means that is faster beacuse it stores the data in RAM. Commonly used as cache and if this doesn't have the info, 

per a interactuar es fa amb `redis-cli`
per a obtenir informació del server fer `INFO`
per a seleccionar base de dades `select`
per llistar base de dades `CONFIG GET databases`
per veure keys `KEYS *`
per obtenir valor d'una clau `get name_key`

> Basic
```bash
redis-cli -h @IP -p 6379
```


# Resolution

# Tags
#redis
