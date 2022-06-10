We have a WireGuard Server with 1 network interface and a Server Client on the same network with only 1 interface too. 
The purpose of the VPN will be to encrypt messages sent over the WireGuard Interface.

The way it works is as follows:
1. On a computer, you run the script "wg-setup.sh" and configure the device to act as a Server. The script returns the public key of the server.

2. The other computer executes the script "new-client.sh" and configures the device as a Client of the previously configured WireGuard Server. This is achieved by asking for the public key of the server, the server's IP address (WireGuard and Public) and its port. The program returns the client's public key and the pre-shared key.

3. To finish the configuration process, the server executes the "add-client.sh" script. It adds the previously created user as an allowed user. This is achieved by entering the public and pre-shared key together with the IP of the client's wireguard interface.

![[Pasted image 20220610142403.png]]