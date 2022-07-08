**Title:** IPSec Procedure (Linux Default)
**Tags:** [[IPSec]]
**Topics:** #IPSec 

---
# IPSec Procedure (Linux Default)
1. Ask the network administrator to provide you with the necessary addressing for both the server and the client. (This is needed to develop the scenario).

2. On the Server machine, several repositories must be installed for it to act as a certificate server and establish an IPSec tunnel. To configure the tunnel, we will use the StrongSwan application, which is the IPSec open source code.
	[//]: If the machine does not have sudo, you have to login with root.
	[//]: When installing StrongSwan, the following repositories will also be installed: “libcharon-extauth-plugins”, “libstrongswan”, “libstrongswan-standard-plugins”, “strongswan-charon”, “strongswan-libcharon”, “strongswan-starter”
	**“sudo apt update -y && sudo apt upgrade -y”**
	**“sudo apt install -y apt install strongswan strongswan-pki“**

3. Same procedure as in step 2, but on the client machine. In this case, there is no need to install "strongswan-pki".

4. After having the software available on both computers, we will first configure the server. In this, we will have to change the execution permissions of the file “.sh” so that the system interprets that it is a script and not a text document.
	**"chmod u+x script-name.sh"**

5. Once we have the script ready, we will have to run it as "root". This can be done by typing at the beginning of the command "sudo", but some Linux distributions do not have it installed, so you will have to change the user to "root".
	**"sudo /path/to/ipsec-deb-server.sh"** or **"/path/to/ipsec-deb-server.sh"**

6. When the script has finished executing, the generated ".pem" file must be provided to the client along with the username and password of the user allowed to connect.

7. From the client computer and having the necessary information, execute the script "ipsec-client.sh". This is in charge of setting up the IPSec tunnel to the server.
	Once it is finished, we will be ready to use the IPSec tunnel.
	[//]: To run, the script must check that it has execution permissions (Step 3).

