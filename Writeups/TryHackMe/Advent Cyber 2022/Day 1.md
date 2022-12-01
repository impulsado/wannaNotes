# Security Frameworks
Documented processes that define polices and procedures organizations should follow to establish and manage security controls.

Guide for setting up programs and improve the security posture of the organization.

Frameworks help organizations remove the guesswork of securing their data, because there are processes and structures established.

## NIST Cybersecurity Framework
Developed by National Institute of Standards and Technology. Provides detailed guidance.
Framework focuses on:
`Identify` → `Protect` → `Detect` → `Respond` → `Recover`

## ISO 27000 Series
International Organization of Standardization develops frameworks for different industries and sectors.
(27001 & 27002 → Cybersecurity (Information Security Management Systems))

## MITARE ATT&CK Framework
Tactics Techniques Procedures → Help to identify adversary plans of attack.
MITARE is a knowledge base of TTPs. Highlights the detailed approach when looking at an attack.

# Cyber Kill Chain
Describes the structure of an attack and consists.
Consists of:
- Recon
- Weaponizations
- Delivery
- Exploitation
- Installation
- Command & Control 
- Actions on Objectives.

![[Pasted image 20221201154720.png]]

# Unified Kill Chain
Unification of MITREATT&CK and Cyber Kill Chain frameworks.

Provides a model to defend against cyberattacks from the adversary's perspective. Offers security teams a blueprint for analyzing and comparing threat intelligence.

Describes 18 phases of attack based on Tactics Techniques and Procedures. Can be combined to form overreaching goals.

## CYCLE 1: In
Series of phases for an attacker to gain access to a system or network environment.
- **Reconnaissance**: Performs research on the target using publicly available information (Foot printing).
- **Weaponization**: Setting up the needed infrastructure to host the “Command and Control Center” (C2). Allow the attacker to send commands remotely. 
- **Delivery**: Payloads are malicious instruments delivered to the target. (Through Phishing…)
- **Social Engineering**: Attacker will trick their target into performing untrusted and unsafe actions.
- **Persistence**: Leave behind a fallback presence on the network or asset to make sure they have a point of access to their target (Backdoor).
- **Defense Evasion**: Attacker must remain anonymous throughout their exploits. Disable and avoid security mechanisms.
- **Command & Control**: Communication channel between the compromised system and the attacker infrastructure.

## CYCLE 2: Through
Gain more access and privileges to assets within the network.
- **Pivoting**: Access other systems in the network.
- **Discovery**: Seek to gather information about the system/organization. 
- **Privilege Escalation**: Access to higher privileged user on the compromised system. Done by exploiting identified vulnerabilities or misconfigurations.
- **Execution**: With elevated privileges, malicious code may be downloaded and executed.
- **Credential Access**: If the attacker has access to information, it can contain login credentials.
- **Lateral Movement**: With extracted credentials, can access other systems or data storages.