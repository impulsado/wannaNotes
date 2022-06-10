To start setup of the devices, you will need to update the packages in the repositories and install the WireGuard program.
[] When WireGuard is installed, a package called "WireGuard Tools" is also installed.
"sudo apt update && sudo apt upgrade"
“sudo apt install wireguard”

After having the software available on both computers, we will first configure the server. In this, we will have to change the execution permissions of the .sh so that the system interprets that it is a script and not a text document.
"chmod u+x wg-setup.sh"

Once we have the script ready, we will have to run it as "root". This can be done by typing at the beginning of the command "sudo", but some Linux distributions do not have it installed, so you will have to change the user to "root".
"sudo /path/to/wg-setup.sh" or "/path/to/wg-setup.sh"


The string returned by the "wg-setup.sh" script is the server's public key for the WireGuard service. This key has to be communicated in some way to the client machine because it will be needed for the execution of the "new-client.sh" script.

From the client machine, and already knowing the public key of the server, we will execute the script "new-client.sh". This script will ask us to enter the key, and it will return the public key of the client and the pre-shared one.
# To run, the script must check that it has execution permissions (Step 2).
# If the client is a Windows 10, you will need to run the PowerShell as an administrator.


To finish setting up the VPN, all that remains is to authorize the user created earlier. To do this, the client must provide its pre-shared key, public key and IP address in the wireguard interface.

Execute "add-client.sh" script and enter the above data. After this, it will display a message that WireGuard has been successfully configured. 
