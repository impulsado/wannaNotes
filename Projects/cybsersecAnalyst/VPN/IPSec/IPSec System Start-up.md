**Title:** IPSec System Start-up
**Tags:** [[IPSec]]
**Topics:** #IPSec 

---
# IPSec System Start-up
Before starting:
- Debian 11.3.0
- StrongSwan 5.9.1

We have a machine as a server which will be configured to create the IPSec tunnel certificates. The protocol in charge of establishing the tunnel will be IKEv2. After the server is configured, it will generate a ".pem" file that will have to be provided to the user.

The user will configure the tunnel with the corresponding server information (IPv4 addresses, usernames...) in order to have a secure connection thanks to IKEv2/IPSec.

The way it works is as follows:
1. On the Server, you execute the script "ipsec-server.sh" and this configures the machine as a CA server to then create the certificates. Then it loads the configuration in the IPSec files.

2. Provides to the client the server's certificate along with the username and password of the valid user to establish a connection in the tunnel.

3. On the client machine, execute the script "ipsec-client.sh" providing it with the appropriate information. This will take care of modifying the configuration files to finish establishing the connection to the server via the IPSec tunnel.

![](https://lh3.googleusercontent.com/AfizoXJ2RuooUA9SjRzppvBYUY5UbQGvn_GJS5hQrzooH2AiYmR48t8pER6wg1Q1JSvtgPRJrdyWUB9nhdAtPairNeApTDAjzX4JdCDNv9kDW7x02Januk0vwlv5yJZkx2--xSOo80QABk8P-Q)