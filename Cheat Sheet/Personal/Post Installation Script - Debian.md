---
layout: post
title: Post Installation Script - Debian & Ubuntu
date: 2022-08-20
categories: [Cheatsheet,Personal]
tags: [Script,Post_installation]
---

# Post Installation Script - Debian & Ubuntu
```bash
#!/bin/bash

# ===================
# Author: @impulsado
# Web: impulsado.org
# Date:   18/10/2022
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
    echo "=============================="
    echo "   Welcome to your new O.S! "
    echo "=============================="
    echo ""
    echo ""
    read -p "Enter your username: " username

    if [[ $username == "root" ]]; then
        echo ""
        echo "Please, enter another username!"
        echo ""
    fi

    read -p "Which SHELL do you prefere BASH [B] or ZSH [Z]? " -e -i "Y" usr_op_shell
    read -p "Do you want to install/configure SSH? [Y/n] " -e -i "Y" usr_op_ssh
    read -p "Do you want to install/configure TMUX? [Y/n] " -e -i "Y" usr_op_tmux
    read -p "Do you want to install/configure NEOVIM? [Y/n] " -e -i "Y" usr_op_neovim
    read -p "Select other apps you want install: " -e -i "wget bat nmap tcpdump curl xclip" usr_apps
    echo ""
    read -p "Do you want to proceed? [Y/n] " -e -i "Y" usr_op

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
    mkdir /home/$username/{Scripts,Programs}
    chown $username:$username /home/$username/Scripts
    chown $username:$username /home/$username/Programs
    timedatectl set-timezone Europe/Madrid
    clear
}

function zshrc() {
    # Download & Install Oh-My-ZSH
    sh -c "$(curl -fsSL https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"

    # Download & Install Starship
    curl -sS https://starship.rs/install.sh | sh 
    
    # Download plugins
    git clone https://github.com/zsh-users/zsh-autosuggestions $ZSH_CUSTOM/plugins/zsh-autosuggestions
    git clone https://github.com/zsh-users/zsh-syntax-highlighting.git ${ZSH_CUSTOM:-/home/$username/.oh-my-zsh/custom}/plugins/zsh-syntax-highlighting

    # Change .zshrc
    sed -i 's/(git)/(git sudo zsh-autosuggestions zsh-syntax-highlighting)/g' /home/$username/.zshrc
    cat <<EOF >> /home/$username/.zshrc
# === ALIAS ===
alias ls='ls --color=auto'
alias ll='ls -la --color=auto'
alias cat='batcat'
alias update='sudo apt update -y && sudo apt upgrade -y'
alias poweroff='sudo systemctl poweroff'
alias reboot='sudo systemctl reboot'
alias apt='sudo apt'
alias mkt='mkdir'
alias tmux='tmux -u'
alias vim='nvim'
alias myip='curl ifconfig.co/'
alias copy='xcopy -sel c <'

# === OTHERS ===
export PATH=$PATH:/home/$username/Scripts/
eval "$(starship init zsh)"
EOF
}

function sshInstall() {
    if [[ $usr_op_ssh != "Y" ]]; then
        return 2
    fi
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
    if [[ $usr_op_tmux != "Y" ]]; then
        return 2
    fi
    apt install -y tmux git
    git clone https://github.com/tmux-plugins/tpm /home/$username/.tmux/plugins/tpm
    touch /home/$username/.tmux.conf
    cat <<EOF > /home/$username/.tmux.conf
# === MAIN ===
# Reload config file
unbind r
bind r source-file /home/$username/.tmux.conf

# Double prefix to change pane
unbind C-b
bind C-b select-pane -t :.+

# Split pane
bind h split-window -v
bind v split-window -h

# Mouse friendly
set -g mouse on

# Start index at number 1
set -g base-index 1

# Modern colors
set -g default-terminal "screen-256color"
set -ga terminal-overrides ",alacritty:Tc"

# Set scroll history to 100,000 lines
set-option -g history-limit 100000

# Window automatically rename 
set-option -g automatic-rename on

# Quiet
set -g visual-activity off
set -g visual-bell off
set -g visual-silence off
set -g monitor-activity off
set -g bell-action none

# === DESIGN ===
# Remove extra information
set-option -g status-right ''

# Centre window names
set-option -g status-justify centre

# Default window title colors
set-window-option -g window-status-style "fg=white,bg=default"

# Active window title colors
set-window-option -g window-status-current-style "fg=red,bg=default"

# Status bar colors
set-option -g status-style "fg=green,bg=#292929"

# Pane border
set-option -g pane-border-style "fg=#292929"
set-option -g pane-active-border-style "fg=white"
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
alias reboot='sudo systemctl reboot'
alias apt='sudo apt'
alias mkt='mkdir'
alias tmux='tmux -u'
alias vim='nvim'
alias myip='curl ifconfig.co/'
alias copy='xcopy -sel c <'

# === OTHERS ===
export PATH=$PATH:/home/$username/Scripts/
PS1='\[\e[0;38;5;46m\]\u\[\e[0;38;5;46m\]@\[\e[0;38;5;46m\]\H \[\e[0m\][\[\e[0m\]\w\[\e[0m\]] \[\e[0;93m\]\$ \[\e[0m\]'
EOF
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

function nvimInstall() {
    if [[ $usr_op_neovim != "Y" ]]; then
        return 2
    fi
    apt install -y neovim > /dev/null
    if [ ! -d /home/$username/.config/nvim ]; then
    mkdir -p /home/$username/.config/nvim
    cat <<EOF >> /home/$username/.config/nvim/init.vim
syntax on                   " syntax highlighting
syntax on                   " syntax highlighting
set hidden                  " Required to keep multiple buffers open
set nocompatible            " disable compatibility to old-time vi
set encoding=utf-8          " The encoding displayed
set showmatch               " show matching
set ignorecase              " case insensitive
set mouse=v                 " middle-click paste with
set hlsearch                " highlight search
set smartcase               " Enable smart-case search
set incsearch               " incremental search
set tabstop=4               " number of columns occupied by a tab
set softtabstop=4           " see multiple spaces as tabstops so <BS> does the right thing
set expandtab               " converts tabs to white space
set shiftwidth=4            " width for autoindents
set autoindent              " indent a new line the same amount as the line just typed
set number                  " add line numbers
set wildmode=longest,list   " get bash-like tab completions
filetype plugin indent on   " allow auto-indenting depending on file type
set mouse=a                 " enable mouse click
set clipboard=unnamedplus   " using system clipboard
filetype plugin on
set cursorline              " highlight current cursorline
set ttyfast                 " Speed up scrolling in Vim
set t_Co=256                " Support 256 colors
set conceallevel=0          " Can see `` in Markdown files
set fileencodings=utf-8,ucs-bom,gb18030,gbk,gb2312,cp936
set termencoding=utf-8
set encoding=utf-8
EOF
fi
}

function printEnd() {
    clear
    echo ""
    echo ""
    echo " BASH:  source ~/.bashrc"
    echo ""
    echo " ZSH:   source ~/.zshrc"
    echo ""
    echo ""
    echo "> Author: impulsado"
}

# === MAIN ===
startCheck

if [[ $usr_op == "Y" ]]; then
    initial
    if [[ $usr_op_shell == "B" ]]; then
        bashrc
    else
        zshrc
    fi
    sshInstall
    tmuxInstall
    nvimInstall
    secureOS
    sleep 1
    printEnd
fi
```

