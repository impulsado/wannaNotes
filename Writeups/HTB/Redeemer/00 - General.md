# Intro
| Dificulty | OS | Start Date | End Date | Help? |
|---|---|---|---|---|
| Very Easy | Linux | 15/05/2022 | 15/05/2022 | Yes |


# Thought process
1. View running services with nmap.
2. List database KEYS.
3. Get the value of the KEY.


# redis
Redis is an 'in-memory' database. In-memory databases is managed in the RAM of the System in contrast to databases that stores in Disks/SSD (MySQL). 
The data retrieval time is very small and are commonly used as cache.

## Commands
- Interact with DB `redis-cli`
- Show Server info `INFO`
- List Databases `CONFIG GET databases`
- Select database `select`
- Show keys `KEYS *`
- Vie
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
