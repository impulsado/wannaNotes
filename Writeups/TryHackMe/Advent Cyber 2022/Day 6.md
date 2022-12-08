**Title:** Day 6
**Tags:** [[Advent Cyber 2022]]
**Topics:** #TryHackMe #Email

---
# Email Analysis
Extract email header information to expose email file details. Two main concerns:
- Security issues: Identifying suspicious/abnormal/malicious patterns.
- Performance issues: Identifying delivery and delay issues.

# How to Analyze Emails?
| Field | Details |
| --- | --- |
| From | Sender's address |
| To | Receiver's address (Including CC and CCO) |
| Date | Timestamp when email was sent. |
| Subject | Subject of the email |
| Return Path | If you replay to an email, the reply will go to the address mentioned |
| Domain Key and DKIM Signatures | Provided by email services to identify and authenticate emails. |
| SPF | Server used to send the email. |
| Message-ID | Unique ID. |
| MIME-Version | Understand the "non-text" content and attachments |
| X-Header | Mail servers that the email went through. |
| X-Spam Status | Spam score. |
| X-Mailer | Email client name. |

[//]: We will need an email header parser tool (Or a configured text editor). Tool → emlAnalyzer. Text editor → Sublime text.

## OSINT Webs
| Tool | Purpose |
| --- | --- |
| [VirusTotal](https://www.virustotal.com/gui/home/upload) | A service that provides a cloud-based detection toolset and sandbox environment. |
| [InQuest](https://labs.inquest.net/) | A service provides network and file analysis by using threat analytics. |  
| [IPinfo.io](https://ipinfo.io/) | A service that provides detailed information about an IP address by focusing on geolocation data and service provider. |
| [Talos Reputation](https://www.talosintelligence.com/reputation) | An IP reputation check service is provided by Cisco Talos. |
| [Urlscan.io](https://urlscan.io/) | A service that analyzes websites by simulating regular user behaviour. |
| [Browserling](https://www.browserling.com/) | A browser sandbox is used to test suspicious/malicious links. | 
| [Wannabrowser](https://www.wannabrowser.net/) | A browser sandbox is used to test suspicious/malicious links. |
 
