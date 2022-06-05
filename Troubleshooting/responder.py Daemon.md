# setDaemon Deprecated
In the python 3.10 version there is an error and it does not work correctly.
`setDaemon` has been deprecated in favor of setting daemon attribute directly.
To solve it, it is necessary to change the code.

Solution found in: [Link](https://github.com/dsanson/termpdf.py/pull/21/commits/449f60fa17d9ffd4d04147bf7d33885cd8c66eab)

> From
```python
.setDaemon(True)
```

> To
```python
.daemon = True
```


# Tags
#Troubleshooting 

