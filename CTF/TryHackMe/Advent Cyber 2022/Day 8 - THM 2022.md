**Title:** Day 8 - THM 2022
**Tags:** [[Advent Cyber 2022]]
**Topics:** #TryHackMe #Smart_Contracts

---
# Blockchain
## Introduction
Blockchain acts as a DB to store information in a specified format and is shared among members of a network with no entity in control.

```ad-info
Blockchain is a digital database or ledger distributed among nodes of a peer-to-peer network. The blockchain is distributed among "peers" or members with no central servers, hence "decentralized." Due to its decentralized nature, each peer is expected to maintain the integrity of the blockchain. If one member of the network attempted to modify a blockchain maliciously, other members would compare it to their blockchain for integrity and determine if the whole network should express that change.
```

[//]: Cryptography is employed to negotiate transactions and provide utility to the blockchain.

## Smart Contracts
### Introduction
Commonly used as the backbone of DeFi applications (Decentralized Finance applications) to support a cryptocurrency on a blockchain.
Smart contract is a program stored on a blockchain that runs when pre-determined conditions are met. It defines the details of the exchange.
[//]: Wait for conditions and execute actions (Traditional logic).

### Functionality
Similar to object-oriented programming concepts.
Imagine a contract was a class. Some fields of that class you may want to be private, preventing access or modification unless conditions are met. Those fields should be private and only accessed or modified from functions defined in the contract.
[//]: Commonly, has several functions that act similarly to accessors and mutators (Check balance, deposit, withdraw, ...)