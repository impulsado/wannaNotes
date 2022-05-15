1.  Fer escaneig i veig el 6379 (redis)

## redis
base de dades In-Memory
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

# Tags
#redis
