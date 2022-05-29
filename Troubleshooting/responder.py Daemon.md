In the python 3.10 version there is an error and it does not work correctly.
Need to change the code.

> From
```python
.setDaemon(True)
```

> To
```python
.daemon = True
```
https://github.com/dsanson/termpdf.py/pull/21/commits/449f60fa17d9ffd4d04147bf7d33885cd8c66eab

