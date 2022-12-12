---
layout: post
title: Aliases
date: 2022-08-20
categories: [Cheatsheet,Personal]
tags: [aliases]
---
**Title:** Aliases
**Tags:** [[Personal]]
**Topics:** #aliases 

---
# Aliases
These are some examples of personal aliases I've used. They allow me to quickly navigate to certain respositories and quickly open files.

## Adding Aliases
```bash
nano ~/.zshrc
[...]
source ~/.zshrc
```

## Useful Aliases
```bash
# Running VPN
alias htbvpn='sudo openvpn ~/HTB/impulsado.opvn'
alias mkt='mkdir {nmap,exploits,content}'
alias serv80='cd ~/Documents; sudo python3 -m http.server'
```