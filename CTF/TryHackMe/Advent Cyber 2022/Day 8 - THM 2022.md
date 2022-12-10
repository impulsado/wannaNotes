**Title:** Day 8 - THM 2022
**Tags:** [[Advent Cyber 2022]]
**Topics:** #THM_Advent_2022 #Smart_Contracts

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
Once a contract is deployed on a blockchain, another contract can use its functions to call or execute the functions defined.
[//]: Commonly, has several functions that act similarly to accessors and mutators (Check balance, deposit, withdraw, …)

### Example
We control “Contract A” and “Contract B” wanted to deposit 1 ETH, and then withdraw 1 ETH from “Contract A”

1. “Contract B” calls deposit() of “Contract A”

2. “Contract A” authorizes the deposit after checking if any pre-determined conditions need to be met.
![[Pasted image 20221208214554.png]]

3. “Contract B” calls withdraw() of “Contract A”.

4. “Contract A” authorizes the deposit if the pre-determined conditions for withdrawal are met.
![[Pasted image 20221208214734.png]]

5. “Contract B” can execute other functions after the ETH is sent from “Contract A” but before the function resolves.
![[Pasted image 20221208214840.png]]

### Vulnerabilities in Smart Contracts
Logic issues or poor exception handling.
A contract can consecutively make new calls to a function while and old functions are still executing. An attacker can continuously attempt to call the "withdraw" function before it can clear the balance.

### The Re-entrancy Attack
 Re-entrancy occurs when a malicious contract uses a fallback function to continue depleting a contract's total balance due to flawed logic after an initial withdraw function occurs.

### Practical Application
[Remix IDE](https://remix.ethereum.org/) Offers a safe and controlled environment to test and deploy contracts as if they were in a public blockchain.

1. Import the Solidity smart contracts. ``File explorer`` → ``default_workspace`` → ``Load a local file into the current workspace.``
![[Pasted image 20221208220043.png]]

2. Now compile the contracts. `Solidity compiler` → Select `0.8.10+commitfcxxxxxx`.
![[Pasted image 20221208220312.png]]

3. Once contracts are compiled, we must deploy them. 
![[Pasted image 20221208221110.png]]

