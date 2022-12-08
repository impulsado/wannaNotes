**Title:** Bandit
**Tags:** [[OverTheWire]]
**Topics:** #Linux

---
# [Bandit](https://overthewire.org/wargames/bandit/)
## Level 0 --> Level 1
```sh
cat readme
# NH2SXQwcBdpmTEzi3bvBHMM9H66vVXjL
```

## Level 1 --> Level 2
```sh
cat <-
# rRGizSaX8Mk1RTb1CNQoXTcYZWU6lgzi
```

## Level 2 --> Level 3
```sh
cat "spaces in this filename"
# aBZ0W5EmUfAf7kHTQeOwd8bauFJ2lAiG
```

## Level 3 --> Level 4
```sh
cat inhere/.hidden
# 2EW7BBsr6aMMoJ2HjW067dm8EgX26xNe
```

## Level 4 --> Level 5
```sh
cat inhere/-file07
# lrIWWI6bB37kxfiCQZqUdOIYfr6eEeqR
```

## Level 5 --> Level 6
```sh
find inhere/* -type f -size 1033c -exec cat {} \;
# P4L4vucdmLnm8I7Vl7jG1ApGSfjYKqJU
```

## Level 6 --> Level 7
```sh
find / -user bandit7 -group bandit6 -size 33c -type f 2>/dev/null
cat /var/lib/dpkg/info/bandit7.password
# z7WtoNQU2XfjmMtWA8u5rN4vzqu4v99S
```

## Level 7 --> Level 8
```sh
cat data.txt | grep millionth
# TESKZC0XvTetK0S9xNwm25STk5iWrBvP
```

## Level 8 --> Level 9
```sh
sort data.txt | uniq -u  # Need to sort bc uniq only detects duplicated lines that are adjacent. 
# EN632PlfYiZbn3PhVK3XOGSlNInNE00t
```

## Level 9 --> Level 10
```sh
strings data.txt | grep =
# G7w8LIi6J3kTb8A7j9LgrywtEUlyyp6s
```

## Level 10 --> Level 11
```sh
base64 -d data.txt
# 6zPeziLdR2RKNdNYFNb6nVCKzphlXHBM
```

## Level 11 --> Level 12
```sh
cat data.txt | tr 'A-Za-z' 'N-ZA-Mn-za-m' #ROT13
# JVNBBFSmZwKKOP0XbFXOoW8chDz5yVRv
```

## Level 12 --> Level 13
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

```

## Level X --> Level Y
```sh
```

## Level X --> Level Y
```sh
```

## Level X --> Level Y
```sh
```

## Level X --> Level Y
```sh
```

## Level X --> Level Y
```sh
```

## Level X --> Level Y
```sh
```

## Level X --> Level Y
```sh
```

## Level X --> Level Y
```sh
```

## Level X --> Level Y
```sh
```

## Level X --> Level Y
```sh
```

## Level X --> Level Y
```sh
```

## Level X --> Level Y
```sh
```

## Level X --> Level Y
```sh
```

## Level X --> Level Y
```sh
```

## Level X --> Level Y
```sh
```

## Level X --> Level Y
```sh
```

## Level X --> Level Y
```sh
```

## Level X --> Level Y
```sh
```

## Level X --> Level Y
```sh
```

## Level X --> Level Y
```sh
```

## Level X --> Level Y
```sh
```


