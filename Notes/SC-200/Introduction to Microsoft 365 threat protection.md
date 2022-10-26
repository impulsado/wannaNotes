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
Conditional access knows about the device risk because MDE has notified. During this time, the device is restricted from accessing corporate resources. It will also block any current access. The device will be able to do “normal activity” as long as it doesn't interact with the corporate resources.

# Microsoft Defender in a Security Operations Center (SOC)
Microsoft Sentile integrated in a Modern Security Operations Center:
![[Pasted image 20221026183239.png]]
## Security Operations Model - Functions and Tools
Each function/team has a primary focus area and also must collaborate closely with other functions and outside teams to be effective. 
![[Pasted image 20221026183553.png]]

### Triage and Automation
Handling reactive alerts:
- **Automation**: Near real-time resolution of known incidents with automation. Attacks seen many times.
- **Triage (Tier 1)**: Rapid remediation of a high volume of well-known incident types that require quick human judgment. Thee are often tasked with approving automated remediation and identifying anything anomalous that can be scaled to Tier 2.
	- **90% True positive**: Recommend setting a quality standard of 90% true positive, so analyst aren't required to respond to a high volume of false alarms.
	- **Alert Ratio**: Most high-quality alerts are being produced by XDR. With remainders from user reported issues, classic log and other sources.
	- **Automation**: It helps empower these analysts and reduce the burden of manual effort. 
	- **Tool Integration**: Most powerful time saving technologies is XDR together into Microsoft 365 Defender, so analysts have a single console for endpoints, Email, Identity and more.
	- **Focus**: Teams can't maintain high speed of resolution, so they keep their focus on technical scenarios. Most frequently this is on user productivity, like emails, endpoint AV and first response for user reports.

## Investigation and Incident Management (Tier 2)
Serves as escalation point for issues from Tier 1, and directly monitors alerts that indicate a more sophisticated attacker that trigger behavioral alerts. This team also reviews Tier 1 alert queue and proactively hunt using XDR tools.

This team provides deeper investigation into a lower volume of more complex attacks. This team pilots new alert types to document processes for Tier 1 and automation.

**Incident Management**: This team takes on the non-technical aspects of managing incidents, including coordination with other teams.

## How it Comes Together
1. Tier 1 analyst claims a malware alert and investigates.
2. While most cases are repidlu remediated, they scale some more sophisticated alerts to the Tier 2.
3. Investigation verifies that all has been solved and closes the case.
4. Later Tier 3, may notice this case while reviewinf closed incidents to scan commoliaties or anomalies:
	- Detections that may be auto-remediated.
	- 