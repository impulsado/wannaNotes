**Title:** OpenVPN Scritps Procedure
**Tags:** [[OpenVPN]]
**Topics:** #OpenVPN 

---
# OpenVPN Scritps Procedure
1. Ask the network administrator to provide you with the necessary addressing for both the server and the client. (This is needed to develop the scenario).

2. To start setup of the devices, you will need to update the packages using Debian repositories and install the “OpenVPN” program, “wget” and “ca-certificates”.
	[//]: When "OpenVPN" is installed, the following packages will also be installed: "easy-rsa", "liblzo2-2", "libpkcs11-helper1", "opensc", "opensc-pkcs11".
	"sudo apt update && sudo apt upgrade"
	“sudo apt install openvpn”

3. After having the software available on both computers, we will first configure the server. In this, we will have to change the execution permission to the script so that the system interprets that it is a script and not a text document.
	“chmod u+x script-name.sh”

4. Once we have the script ready, we will have to run it as "root". This can be done by typing at the beginning of the command "sudo", but some Linux distributions do not have it installed, so you will have to change the user to "root".
	"sudo /path/to/wg-setup_old.sh" or "/path/to/wg-setup_old.sh"

5. When the script is executed, it will ask for configuration parameters. First will be those of the server (Port, Transport Protocols and Encryption Protocols).
	[//]: The script will suggest the best options, but you can always choose the appropriate ones.

6. After finishing configuring the VPN server part, the script displays the options to create the user.

7. When the server and user parameters have been configured, the creation of keys and all the management will start. Once it is finished, it will display a warning saying where the user configuration file is located.

8. The generated file must be shared with the client device so that it can connect.

9. Once the client machine has the configuration file ".ovpn", it only has to execute the command "sudo openvpn /path/to/user.ovpn".
	[//]: If you have configured the user to have a password, you must type after executing the command

10. If the client has Windows 10, in the same OpenVPN application, you will have to load the file and click the connect button.

