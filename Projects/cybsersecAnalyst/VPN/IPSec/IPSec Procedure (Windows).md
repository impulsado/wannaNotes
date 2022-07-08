**Title:** IPSec Procedure (Windows)
**Tags:** [[IPSec]]
**Topics:** #IPSec 

---
# IPSec Procedure (Windows)
1. Ask the network administrator to provide you with the necessary addressing for both the server and the client. (This is needed to develop the scenario).

2. On the Server machine, several repositories must be installed for it to act as a certificate server and establish an IPSec tunnel. To configure the tunnel, we will use the StrongSwan application, which is the IPSec open source code.
[//]: If the machine does not have sudo, you have to login with root.

[//]: When installing StrongSwan, the following repositories will also be installed: “libcharon-extauth-plugins”, “libstrongswan”, “libstrongswan-standard-plugins”, “strongswan-charon”, “strongswan-libcharon”, “strongswan-starter”
“sudo apt update -y && sudo apt upgrade -y”
“sudo apt install -y apt install strongswan strongswan-pki“

3. Same procedure as in step 2, but on the client machine. In this case, there is no need to install "strongswan-pki".

4. After having the software available on both computers, we will first configure the server. In this, we will have to change the execution permissions of the file “.sh” so that the system interprets that it is a script and not a text document.
"chmod u+x script-name.sh"

5. Once we have the script ready, we will have to run it as "root". This can be done by typing at the beginning of the command "sudo", but some Linux distributions do not have it installed, so you will have to change the user to "root".
"sudo /path/to/ipsec-win-server.sh" or "/path/to/ipsec-win-server.sh"

6. When the script has finished executing, the generated ".pem" file must be provided to the client along with the username and password of the user allowed to connect.

7. Press Win+R to bring up the Run dialog, and enter mmc.exe.

8. File menu > Add or Remove Snap-in > select Certificates from the list of available snap-ins, and click Add. Select Computer Account, then Local Computer and click Next.

9. Under the Console Root node, expand the Certificates (Local Computer) entry, expand Trusted Root Certification Authorities, and then select the “Certificates” entry


From the Action menu, select All Tasks and click Import to display the Certificate Import Wizard.

On the File to Import screen, press the Browse button, ensure that you change the file type from “X.509 Certificate (.cer;.crt)” to “All Files (.)”, and select the ca-cert.pem file that you’ve saved. Then click Next.

When this message appears, it means that the certificate configuration has been completed.


Now launch Control Panel > Network and Sharing Center >Click on Set up a new connection or network, then select Connect to a workplace.


Select Use my Internet connection (VPN).

Enter the VPN server details. Enter the server’s domain name or IP address in the Internet address field, then fill in Destination name with something that describes your VPN connection. Then click Done.



In the connection icon, there will be a new option that is used to connect to the VPN. It will ask for the access credentials, and you will be all ready.

