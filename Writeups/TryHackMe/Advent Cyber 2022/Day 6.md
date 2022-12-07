**Title:** Day 6
**Tags:** 
**Topics:** 

---
# Email Analysis
Extract email header information to expose email file details. Two main concerns:
- Security issues: Identifying suspicious/abnormal/malicious patterns.
- Performance issues: Identifying delivery and delay issues.

# How to Analyze Emails?
| Field | Details |
| From | Sender's address |
| To | Receiver's address (Including CC and CCO) |
| Date | Timestamp when email was sent. |
| Subject | Subject of the email |
| Return Path | If you replay to an email, the reply will go to the address mentioned |
| Domain Key and DKIM Signatures | Provided by email services to identify and authenticate emails. |
| SPF | Server used to send the email. |
| Message-ID | Unique ID. |
| MIME-Ve
