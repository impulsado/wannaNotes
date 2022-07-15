**Title:** Post Installation Script - Debian
**Tags:** [[Personal]]
**Topics:** #Personal #Script 

---
# Post Installation Script - Debian
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
    
    if [[ $username == "root" ]]; then
        echo ""
        echo "Please, enter another username!"
        echo ""
    fi

    read -p "Select the apps you want install: " -e -i "bat zoxide fzf nmap tcpdump neovim curlimage.png" usr_apps
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
    apt update -y && apt upgrade -y
    apt install -y $usr_apps
    echo "$username ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers
    rm -d /home/$username/{Documents,Music,Pictures,Public,Templates,Videos}
    mkdir /home/$username/Scripts
    timedatectl set-timezone Europe/Madrid
    clear
}

function sshInstall() {
    apt install -y openssh-server
    systemctl enable ssh
    systemctl stop ssh
    cat <<EOF > /etc/ssh/sshd_config
# === NEW SSH CONFIGURATION ===
# Protocolo 1 is older and less secure
Protocol 2

# Limit passwords attempts
MaxAuthTries 3

# Disable root login
PermitRootLogin no

# Disable empty passwords to login
PermitEmptyPasswords no

# Disable X11 Forwarding
X11Forwarding no

# Period of time before client gets disconnected (Seconds)
ClientAliveInterval 15

# Server waiting time after a connection request is made (Seconds)
LoginGraceTime 20
EOF
    systemctl start ssh
    clear
}

function tmuxInstall() {
    apt install -y tmux git
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
set -g base-index 1
set -g default-terminal "screen-256color"

set-option -g automatic-rename on
set-option -g status-right ''
set-option -g status-justify centre
EOF
    chown $username:$username /home/$username/.tmux.conf
    tmux source-file /home/$username/.tmux.conf
    clear
}

function bashrc() {
cat <<EOF >> /home/$username/.bashrc
# === ALIAS ===
alias ls='ls --color=auto'
alias ll='ls -la --color=auto'
alias cat='batcat'
alias update='sudo apt update -y && sudo apt upgrade -y'
alias poweroff='sudo systemctl poweroff'
alias restart='sudo systemctl reboot'
alias apt='sudo apt'

# === OTHERS ===
export PATH=$PATH:/home/$username/Scripts
export ZOXIDE_HOME=$HOME/.local/opt/zoxide
export PATH=$PATH:$ZOXIDE_HOME/bin
eval "$(zoxide init bash)"
EOF
    cp /home/$username/.bashrc /root
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
    echo " 1. EXECUTE THIS COMMAND:  source ~/.bashrc"
    echo ""
    echo " 2. README:   cat /home/$username/README.md"
    echo ""
    cat <<EOF /home/$username/README.md
# !! IMPORTANT !!
The system have been configured successfully.
Remember to take a look to the new aliases created.

Before using tmux, you must execute this commands:
1. tmux new-session SESSIONAME
2. tmux source-file .tmux.conf



> Author: impulsado
EOF
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

