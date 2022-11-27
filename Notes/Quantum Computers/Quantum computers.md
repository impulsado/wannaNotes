---
layout: post
title: Quantum computers
date: 2022-11-27
categories: [Notes,Quantum Computers]
tags: [Quantum_Computer]
---
# Index
- Theoretical Bases
- Advantages / Disadvantages
- Encryption
	- Real Examples
- Future Forecast

# Theoretical Basis
Currently computers works with bits. These are 1's and 0's that are formed depending on whether the transistors allow electricity to pass through. All these transistors together make up today's computers, mobile phones… 
A quantum system, by superposition, can be in two states at the same time.

```example1
Current system --> 1 or 0
Quantum system --> 1 and 0
```

A normal transistor can do 1 operation at a time, while a quantum transistor, if its state is not determined, can do 4 operations at a time. This is one of the problems encountered in the quantum world, maintaining this overlap is a very high cost.  

```Currency
Coin in the hand --> Heads or Tails
Coin in the air --> Heads and Tails.
```


![Photo](https://www.researchgate.net/publication/271532617/figure/fig4/AS:349605003841542@1460363736871/Bits-three-state-systems-cobits-and-qubits-Our-secure-delegated-computing-protocol.png)


| #QuBits | #bits | #bits | RAM |
| --- | --- | --- |
| 1 | 2 | 2 bits |
| 3 | 8 | 1 Byte |
| 33 | 8589934592 | 1 GByte |
| 43 | 8.8x10^12 | 1 TByte |

## Advantages and Disadvantages
## Advantages
- Faster computing: 1000 times faster than current supercomputers.
- Improved simulation: Being faster, more cases can be simulated.
- Improved privacy: By having a quantum cryptography, it is impossible to breach. China has said that it is impossible to hack.
- Improved AI and Machine Learning.

## Disadvantages
- New algorithms: Current algorithms do not work and are very weak in a quantum world.
- The low temperature they need to work (-200 °C).
- It is not open to the public, and they are still in a very early stage, 10 QuBits.
- Internet security.

# Quantum Encryption
QKD (Quantum Key Distribution).
Photons: Smallest unit of energy in a light wave that cannot be divided.
Polarization: property of waves that allows them to oscillate in more than one orientation. When a photo is observed, it alters and is determined in only one direction.
![[Pasted image 20221113115440.png]]
Alice sends polarized photons in 4 different directions randomly.
![[Pasted image 20221113115612.png]]
2. Bob has 2 detectors to know how to interpret the directions that arrive to him. He does this randomly (this gives him a 50% chance).
![[Pasted image 20221113115814.png]]
3. When Bob has just read the message sent by Alice, she tells him what random chain of detectors she has used to detect the photons.
4. Alice compares Bob's sequence with his initial sequence and tells him when he has used the detector incorrectly. In this way Bob knows which are the photons registered correctly (the ones he has made wrongly he does not use them).
![[Pasted image 20221113120105.png]]
5. The correct result will be the quantum key that will be used by both parties to encrypt and decrypt the information.

## Why is it so secure?
If an attacker tries to listen to the string of photons that Alice sends to Bob, by observing these photons, he disrupts the quantum state by defining a state. As a result, the message that arrives to Alice is not the one she sent.

![[Pasted image 20221113120441.png]]
![[Pasted image 20221113120459.png]]
When Bob finishes reading the whole string, he sends a part of it to Alice to check. If she detects that there are many errors or inconsistencies, she will raise the alarm, saying that there is something altering the message.
This procedure is repeated every few seconds for greater security.

Note: Quantum teleportation is being investigated to transport these keys.

## Current problems
The biggest problem with quantum computers is how easy it is to crack current encryption systems. To take an example and be able to quantify it, we will take the 2048-bit RSA protocol.
At the present time, a normal computer would take 300 trillion years to decrypt the key. While a quantum computer with, 4099 QuBits would take 10 seconds.

Note: The quantum computer with the most QuBits is 127 (Eagle IBM).

# Future Forecast
Currently, quantum computers are only a reality for those who have a lot of resources and capital. Among the most developed countries, the following stand out:
- **The United States**: With companies such as IBM, Google, Intel… Also the US government itself has one.
- **China**: This country is a bit of a mystery, but the last known news is that they sent an encrypted message to a distance of 1120 km.
- **Next countries**: These are the countries that have shown great interest in this new technology and how much capital they will allocate:
	- Australia: 2500 M $ (Silicon Quantum Computing).
	- Germany: 2000 M € (QSolid).
	- France: 1800 M € (France Quantum).
	- Spain: 60 M € (Quantum Spain).