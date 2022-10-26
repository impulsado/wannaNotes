**Title:** Introduction to Microsoft 365 threat protection
**Tags:** [[SC-200]]
**Topics:** #SC-200

---
# Introduction
Microsoft 365 Defender is a threat protection suite with solutions that detect malicious activity. It provides the full understanding of the threat. It also enables you to remediate and protect from future attacks.
Extended Detection and Response (XDR) combines signals from:
- Endpoints.
- Identity.
- Email.
- Applications.

# Explore Extended Detection & Response (XDR)
The following are examples of XDR use cases:

## Detection of Threat
![[Pasted image 20221026181907.png]]
Microsoft Defender for Endpoint detects a malicious email. The victim is unaware that an attack has taken place, but Microsoft Defender for Endpoints (MDE) raises an alert to the security team. Disables user access from devices while infected.

### Remediation
MDE remediates the threat via automated or manual remediation (Security analyst can approve the alert). 
MDE also adds information to the system remediating across Microsoft MDE customers.

### Share Intelligence and Restore Access
Once the infected device have been remediated, MDE change the status and the customer can access the resources again. Threat signals are used by Microsoft tools securing the attack surface.

## Device still compromised
![[Pasted image 20221026182651.png]]
### Access Restricted
Conditional access knows about the device risk because MDE has notified. During this time, the device is restricted from accessing corporate resources. It will also block any current access. The device 