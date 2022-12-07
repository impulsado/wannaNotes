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

[//]: We will need an email header parser tool (Or a configured text editor). Tool → emlAnalyzer. Text editor --> Sublime text.