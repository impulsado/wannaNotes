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
![](https://lh5.googleusercontent.com/k9BkOssn0x6dp2szlf0zsC8IOZNcmd_OqcbXMbv6nDihQZsC95_FXevAm44eosUnKZih-MRo-fk1iTfiZ7cZxDQqjrzVrIYEYk0hV9wfzdWPUTn1ZfDOzLZt-TUfmNykKBt7Ge7dfuQQpfSmvA)

6. After finishing configuring the VPN server part, the script displays the options to create the user.
![](https://lh5.googleusercontent.com/yPc2zbYyqRyM-oHmgtBbnOVp4RyWKDuGGkp8-3OXfvausklH6MjqVQrTahycuQEqAO-nyz4yD2IQpmEJzeQ7PsjKOHA93JY-1Z-Ug0Qo0pS1rVDgIyRKg2VoouIZ60uOvoQGd0NAoiJkjfJjPA)

7. When the server and user parameters have been configured, the creation of keys and all the management will start. Once it is finished, it will display a warning saying where the user configuration file is located.
![](https://lh6.googleusercontent.com/YqCVrlVlEU5oZlPGjXnn0bI1tnRL7mC-l4XBMJrAa5BVC6-UqfpQo7TzpFP2W7YH5IGi7dsGR7d3btlJ2etgpHYbKHf6UJoqORfi6QHuyGV389asUqd0fpYmv_GeJhXozbPfco7Nh94yPuWwbA)

8. The generated file must be shared with the client device so that it can connect.

9. Once the client machine has the configuration file ".ovpn", it only has to execute the command "sudo openvpn /path/to/user.ovpn".
	[//]: If you have configured the user to have a password, you must type after executing the command
![](https://lh6.googleusercontent.com/tZJ4bUbm_Sr9UcI_V5_oOfZ16l66qdc01pgB3Og7sN77OGFsQJxVv18x7849w_BP0l_RhiLeOIkvc7JzoeAQwtVOauB7B9xfK5l8GIedxYciaHpjG9nbRRDIDdX_lrAncbUheZ-x4b-qxfcx8Q)

10. If the client has Windows 10, in the same OpenVPN application, you will have to load the file and click the connect button.
![](https://lh3.googleusercontent.com/4LJHUNZAfLcSEsfywFTtpUoeFjCIXqDXxiWiMnK0OkU_PEt6zX3t2BDkKEn8ryeTfbv27Y17Y1I2nvzZiWFExuq35D8fHhgW5CnKXnwTRxYjnMUfGRlEZWzDr_P1HS7IjiaGoaA8C7eJvPVktg)