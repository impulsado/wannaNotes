**Title:** 00 - Redeemer
**Tags:** [[Very Easy]]
**Topics:** #redis 

---

# Intro
| Dificulty | OS | Start Date | End Date |
|---|---|---|---|
| Very Easy | Linux | 15/05/2022 | 15/05/2022 | 


# Thought process
1. View running services with `nmap`.
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
- View value of stored key `get key_name`

> Connect to redis server
```bash
$ redis-cli -h @IP -p 6379
```


# Resolution
First I listed keys in the server and i say that there was one call it "flag".
I searched in google how to get the value of a key. After the research I found that the command was `get flag` and has allowed me to know the flag.
