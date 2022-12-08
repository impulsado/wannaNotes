**Title:** Day 7
**Tags:** [[Advent Cyber 2022]]
**Topics:** #TryHackMe #CyberChef

---
# CyberChef
Web-based application used to slice, dice, encode, decode, parse and analyze data or files.

## Malware doc analysis
1. Add the file to CyberChef.

2. Extract strings.
![[Pasted image 20221208100647.png]]

3. Remove patterns because attackers often add random character.
![[Pasted image 20221208100826.png]]

4. Drop bytes to access to the base64 string.
![[Pasted image 20221208100929.png]]

5. Decode base64.
![[Pasted image 20221208100951.png]]

6. Decode UTF-16. We can see a poweshell script 