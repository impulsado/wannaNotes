**Title:** System Start-up
**Tags:** [[OpenVPN]]
**Topics:** #VPN #OpenVPN 

---
# System Start-up
Before starting:
-   Debian 11.3.0
-   Windows 10 
-   OpenVPN 2.5.1

We have a OpenVPN Server with one physical network interface and a Client on the same network with only one physical interface too. 
The purpose of the scenario will be to send encrypted messages over the physical interface, but using the OpenVPN, so only the Server can read them.

The way it works is as follows:
1.  The server executes the script "vpn-setup.sh". This script will configure the computer to act as a OpenVPN Server. To configure OpenVPN “easy-rsa” is needed, so the script also configures key management using easy-rsa repository. It also generates 1 configuration file for each user.

2.  The client computer must have installed OpenVPN software and execute the following command in order to establish connection:
	“sudo openvpn /path/to/user.ovpn”


![](https://lh3.googleusercontent.com/dSMY3cPoiFyLhtVy2suZdOzoEDWhIfI31WtNPLap922RKL-tcVdpwDTZ8QfbgHW1CrMUxZFoNfQBnXcvxrhUJZUNz6P5bKHiJWQG495l6FgRAMFzaHF9CXurWKtPiIGBdRhNeltVmyFVM4aWSw)