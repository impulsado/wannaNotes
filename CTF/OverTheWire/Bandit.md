**Title:** Bandit
**Tags:** [[OverTheWire]]
**Topics:** #Linux

---
# [Bandit](https://overthewire.org/wargames/bandit/)
## Level 0 → Level 1
```sh
cat readme
# NH2SXQwcBdpmTEzi3bvBHMM9H66vVXjL
```

## Level 1 → Level 2
```sh
cat <-
# rRGizSaX8Mk1RTb1CNQoXTcYZWU6lgzi
```

## Level 2 → Level 3
```sh
cat "spaces in this filename"
# aBZ0W5EmUfAf7kHTQeOwd8bauFJ2lAiG
```

## Level 3 → Level 4
```sh
cat inhere/.hidden
# 2EW7BBsr6aMMoJ2HjW067dm8EgX26xNe
```

## Level 4 → Level 5
```sh
cat inhere/-file07
# lrIWWI6bB37kxfiCQZqUdOIYfr6eEeqR
```

## Level 5 → Level 6
```sh
find inhere/* -type f -size 1033c -exec cat {} \;
# P4L4vucdmLnm8I7Vl7jG1ApGSfjYKqJU
```

## Level 6 → Level 7
```sh
find / -user bandit7 -group bandit6 -size 33c -type f 2>/dev/null
cat /var/lib/dpkg/info/bandit7.password
# z7WtoNQU2XfjmMtWA8u5rN4vzqu4v99S
```

## Level 7 → Level 8
```sh
cat data.txt | grep millionth
# TESKZC0XvTetK0S9xNwm25STk5iWrBvP
```

## Level 8 → Level 9
```sh
sort data.txt | uniq -u  # Need to sort bc uniq only detects duplicated lines that are adjacent. 
# EN632PlfYiZbn3PhVK3XOGSlNInNE00t
```

## Level 9 → Level 10
```sh
strings data.txt | grep =
# G7w8LIi6J3kTb8A7j9LgrywtEUlyyp6s
```

## Level 10 → Level 11
```sh
base64 -d data.txt
# 6zPeziLdR2RKNdNYFNb6nVCKzphlXHBM
```

## Level 11 → Level 12
```sh
cat data.txt | tr 'A-Za-z' 'N-ZA-Mn-za-m' #ROT13
# JVNBBFSmZwKKOP0XbFXOoW8chDz5yVRv
```

## Level 12 → Level 13
```sh
mkdir /tmp/impu && cd $_
mv ~/data.txt .
xxd -r data.txt data1.gz
gzip -d data1.gz
bzip2 -d data
mv data data.gz
gzip -d data.gz
tar xvf data
tar xvf data5.bin
bzip2 -d data6.bin
tar xvf data6.bin.out
mv data8m.bin data6
gzip -d data8.gz
cat data8
# Use "file file_name" to know which file it is. 
# wbWdlBxEir4CaE8LaPhauuOo6pwRmrDw
```

## Level 13 → Level 14
```sh
ssh bandit14@bandit.labs.overthewire.org -p2220 -i sshkey.private
cat /etc/bandit_pass/bandit14
# fGrHPx402xGC7U7rXKDaxiWFTOiF0ENq
```

## Level 14 → Level 15
```sh
telnet localhost 30000
# jN2kgmIXJ6fShzhT2avhotn4Zcka6tnt
```

## Level 15 → Level 16
```sh
openssl s_client -connect localhost:30001
# JQttfApK4SeyHwDlI9SXGR50qclOAil1
```

## Level X → Level Y
```sh
openssl s_client -connect localhost:31790
-----BEGIN RSA PRIVATE KEY-----
MIIEogIBAAKCAQEAvmOkuifmMg6HL2YPIOjon6iWfbp7c3jx34YkYWqUH57SUdyJ
imZzeyGC0gtZPGujUSxiJSWI/oTqexh+cAMTSMlOJf7+BrJObArnxd9Y7YT2bRPQ
Ja6Lzb558YW3FZl87ORiO+rW4LCDCNd2lUvLE/GL2GWyuKN0K5iCd5TbtJzEkQTu
DSt2mcNn4rhAL+JFr56o4T6z8WWAW18BR6yGrMq7Q/kALHYW3OekePQAzL0VUYbW
JGTi65CxbCnzc/w4+mqQyvmzpWtMAzJTzAzQxNbkR2MBGySxDLrjg0LWN6sK7wNX
x0YVztz/zbIkPjfkU1jHS+9EbVNj+D1XFOJuaQIDAQABAoIBABagpxpM1aoLWfvD
KHcj10nqcoBc4oE11aFYQwik7xfW+24pRNuDE6SFthOar69jp5RlLwD1NhPx3iBl
J9nOM8OJ0VToum43UOS8YxF8WwhXriYGnc1sskbwpXOUDc9uX4+UESzH22P29ovd
d8WErY0gPxun8pbJLmxkAtWNhpMvfe0050vk9TL5wqbu9AlbssgTcCXkMQnPw9nC
YNN6DDP2lbcBrvgT9YCNL6C+ZKufD52yOQ9qOkwFTEQpjtF4uNtJom+asvlpmS8A
vLY9r60wYSvmZhNqBUrj7lyCtXMIu1kkd4w7F77k+DjHoAXyxcUp1DGL51sOmama
+TOWWgECgYEA8JtPxP0GRJ+IQkX262jM3dEIkza8ky5moIwUqYdsx0NxHgRRhORT
8c8hAuRBb2G82so8vUHk/fur85OEfc9TncnCY2crpoqsghifKLxrLgtT+qDpfZnx
SatLdt8GfQ85yA7hnWWJ2MxF3NaeSDm75Lsm+tBbAiyc9P2jGRNtMSkCgYEAypHd
HCctNi/FwjulhttFx/rHYKhLidZDFYeiE/v45bN4yFm8x7R/b0iE7KaszX+Exdvt
SghaTdcG0Knyw1bpJVyusavPzpaJMjdJ6tcFhVAbAjm7enCIvGCSx+X3l5SiWg0A
R57hJglezIiVjv3aGwHwvlZvtszK6zV6oXFAu0ECgYAbjo46T4hyP5tJi93V5HDi
Ttiek7xRVxUl+iU7rWkGAXFpMLFteQEsRr7PJ/lemmEY5eTDAFMLy9FL2m9oQWCg
R8VdwSk8r9FGLS+9aKcV5PI/WEKlwgXinB3OhYimtiG2Cg5JCqIZFHxD6MjEGOiu
L8ktHMPvodBwNsSBULpG0QKBgBAplTfC1HOnWiMGOU3KPwYWt0O6CdTkmJOmL8Ni
blh9elyZ9FsGxsgtRBXRsqXuz7wtsQAgLHxbdLq/ZJQ7YfzOKU4ZxEnabvXnvWkU
YOdjHdSOoKvDQNWu6ucyLRAWFuISeXw9a/9p7ftpxm0TSgyvmfLF2MIAEwyzRqaM
77pBAoGAMmjmIJdjp+Ez8duyn3ieo36yrttF5NSsJLAbxFpdlc1gvtGCWW+9Cq0b
dxviW8+TFVEBl1O4f7HVm6EpTscdDxU+bCXWkfjuRb7Dy9GOtt9JPsX8MBTakzh3
vBgsyi/sN3RqRBcGU40fOoZyfAMT8s1m/uYv52O6IgeuZ/ujbjY=
-----END RSA PRIVATE KEY-----
```



