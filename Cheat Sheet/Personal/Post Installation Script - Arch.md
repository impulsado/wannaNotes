---
layout: post
title: Post Installation Script - Arch
date: 2022-08-20
categories: [Cheatsheet,Personal]
tags: [Script,Post_installation]
---

# Post Installation Script - Arch
#### THIS SCRIPT IS OUTDATED!
Thanks to @zenobia for helping me with this script.

```bash
#!/bin/bash

# ===================
# Author: @impulsado
# Web: impulsado.org
# Date:   08/07/2022
# ===================

# === FUNCTIONS ===
function startCheck() {
    if [[ "$EUID" -ne 0 ]]; then
        echo ""
        echo "Must be root!"
        echo ""
        exit 1
    fi

    ping -c 1 -q google.com >&/dev/null
    if [[ $? != 0 ]]; then
        echo ""
        echo "Must have internet connection!"
        echo ""
        exit 1
    fi

    echo ""
    echo " Welcome to your new O.S. "
    echo ""
    echo ""
    read -p "Enter your username: " username
    read -p "Select the apps you want install: " -e -i "bat zoxide fzf nmap tcpdump" usr_apps
    echo ""
    read -p "Do you want to start? (Y/n) " -e -i "Y" usr_op

    if [[ $usr_op != "Y" ]]; then
        echo ""
        echo "See you soon!"
        echo ""
        exit 2
    fi
}

function initial() {
    pacman -Syu
    pacman -Sy $usr_apps
    echo "$username ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers
    rm -d /home/$username/{Documents,Music,Pictures,Public,Templates,Videos}
    mkdir /home/$username/Scripts
    timedatectl set-timezone Europe/Madrid
    clear
}

function sshInstall() {
    read -p "Choose the new SSH Port: " usr_port
    pacman -Sy openssh
    systemctl enable ssh
    systemctl stop ssh
    cat <<EOF > /etc/ssh/sshd_config
# NEW CONF
Port $usr_port
MaxAuthTries 3
PermitRootLogin no
PermitEmptyPasswords no
EOF
    sed -i '/X11Forwarding yes/c\X11Forwarding no'
    systemctl start ssh
    clear
}

function tmuxInstall() {
    pacman -Sy tmux git
    git clone https://github.com/tmux-plugins/tpm /home/$username/.tmux/plugins/tpm
    touch /home/$username/.tmux.conf
    cat <<EOF > /home/$username/.tmux.conf
unbind r
bind r source-file /home/$username/.tmux.conf

unbind C-b
bind C-b select-pane -t :.+

bind h split-window -v
bind v split-window -h

set -g mouse on
EOF
    chown $username:$username /home/$username/.tmux.conf
    cat <<EOF > /home/$username/README.tmux
    1. "tmux new-session"
    2. "tmux source .tmux.conf"
    3. "prefix + I"
    4. "nano .tmux.conf" and append this text.
    ---
    set -g @plugin 'tmux-plugins/tpm'
    set -g @plugin 'tmux-plugins/tmux-sensible'

    run '/home/$username/.tmux/plugins/tpm/tpm'
    ---

    5. "prefix + r"
    6. "nano .tmux.conf" insert this text before "run" command.
    ---
    set -g @plugin 'dracula/tmux'

    set -g @dracula-show-left-icon session
    set -g @dracula-show-network false
    set -g @dracula-show-battery false
    set -g @dracula-show-weather false
    ---
    7. "prefix + I"
EOF
    tmux source-file /home/$username/.tmux.conf
    clear
}

function bashrc() {
cat <<EOF >> /home/$username/.bashrc
# === ALIAS ===
alias ll='ls -la --color=auto'
alias cat='batcat'
alias update='sudo pacman -Syu'
alias poweroff='sudo systemctl poweroff'
alias restart='sudo systemctl restart'
alias pacman='sudo pacman'


# === OTHERS ===
eval "$(zoxide init bash)"
export PATH=$PATH:/home/$username/Scripts
EOF
    source /home/$username/.bashrc
}

function secureOS() {
    # Enable broadcast echo Protection
    echo 1 > /proc/sys/net/ipv4/icmp_echo_ignore_broadcasts

    # Disable Source Routed Packets
    for i in /proc/sys/net/ipv4/conf/*/accept_source_route; do
        echo 0 > $i
    done

    # Enable TCP SYN Cookie Protection
    echo 1 > /proc/sys/net/ipv4/tcp_syncookies

    # Disable ICMP Redirect Acceptance
    for i in /proc/sys/net/ipv4/conf/*/accept_redirects; do
        echo 0 > $i
    done

    # Don't send Redirect Messages
    for i in /proc/sys/net/ipv4/conf/*/send_redirects; do
        echo 0 > $i
    done

    # Drop Spoofed Packets coming in on an interface, which, if replied to,
    # would result in the reply going out a different interface.
    for i in /proc/sys/net/ipv4/conf/*/rp_filter; do
        echo 1 > $i
    done
}

function printEnd() {
    clear
    echo ""
    echo "=== SSH ==="
    echo "Port Changed --> $usr_port"
    echo "Installed Succesfully!"
    echo ""
    echo "=== TMUX ==="
    echo "README.tmux"
    echo "Installed Succesfully!"
    echo ""
    echo "=== SECURITY ==="
    echo "System secured Succesfully!"
    echo ""
    echo "=== BASHRC ==="
    echo "Updated Succesfully!"
    echo ""
}

# === MAIN ===
startCheck

if [[ $usr_op == "Y" ]]; then
    initial
    sshInstall
    tmuxInstall
    bashrc
    secureOS
    sleep 1
    printEnd
fi
```