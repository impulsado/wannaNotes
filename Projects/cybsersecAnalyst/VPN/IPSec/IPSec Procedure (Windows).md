**Title:** IPSec Procedure (Windows)
**Tags:** [[IPSec]]
**Topics:** #IPSec 

---
# IPSec Procedure (Windows)
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
	**"sudo /path/to/ipsec-win-server.sh"** or **"/path/to/ipsec-win-server.sh"**

6. When the script has finished executing, the generated ".pem" file must be provided to the client along with the username and password of the user allowed to connect.

7. Press Win+R to bring up the Run dialog, and enter mmc.exe.

8. File menu > Add or Remove Snap-in > select Certificates from the list of available snap-ins, and click Add. Select Computer Account, then Local Computer and click Next.
![](https://lh5.googleusercontent.com/Y7JKMTvoKtUNU0ogjomUpbBR_6HQ9L8uAL9DEC6NmaV23gtJLzAj95gyU2zkNBXHcnKTFfZ_-LP_LT2GCdpsJxEseq-pWfwHgriVSARkgyOe_tgm-igP85jVp5aEhyK4kC3dIxivWuJI51SH5A)

9. Under the Console Root node, expand the Certificates (Local Computer) entry, expand Trusted Root Certification Authorities, and then select the “Certificates” entry
![](https://lh3.googleusercontent.com/TpEhEjhUZq2AqHt73QyASgtYe18YyM58xbundu6U0beSLXTEHzCXYI9JLv_PIpRJj-YrjWU3KuSneN31l8yoMqwD-_SfHa0DMAhb9XVdizXPPH718SDgaesxpimqR_6DsToTdQjQMKB828Xp_w)

10. From the Action menu, select All Tasks and click Import to display the Certificate Import Wizard.

11. On the File to Import screen, press the Browse button, ensure that you change the file type from “X.509 Certificate (.cer;.crt)” to “All Files (.)”, and select the ca-cert.pem file that you’ve saved. Then click Next.

12. When this message appears, it means that the certificate configuration has been completed.
![](https://lh4.googleusercontent.com/WwrMiOkdnIvw_xmlXapaPdzfsfNexVwXIbPZ6OHdAzTykqonjQjzJ7eCrOcd4Ya7oLodeROdBoGVzOg7s0uwm5fPCamc1EIxc_np1nTGjR3MT_RBYEkrZJYtYvT__T28aN5EqgBE_2KAk6zwwQ)

13. Now launch Control Panel > Network and Sharing Center >Click on Set up a new connection or network, then select Connect to a workplace.
![](https://lh4.googleusercontent.com/Z8mx6vT2CXHqzSUqA0S9ThprHXeFCKNy_pvZ9JYvX_iYSrhYiXb6aM9iVQhqg6LyLyHhs4BHxmPHDJ-5du3SVU_TTFbF1DMUxFVJr3UqoKx9FZUU4eiV44VDkiBEtG-bQmjy2TXHc2TsySewPg)

14. Select Use my Internet connection (VPN).
![](https://lh3.googleusercontent.com/RVN_uPToN5DwiJkuQgznb_zfDf_kozWgf_yh6ZP0WB23l7jP4ucr1ET621s21Yqh4Tq4Bj6J29AwhgZ71bBzgViwQ4ob6cb8oGGMvaZg59GbIWa9OPrVVr7V30UASCo8OxmNsArAILSvvm4jwQ)

15. Enter the VPN server details. Enter the server’s domain name or IP address in the Internet address field, then fill in Destination name with something that describes your VPN connection. Then click Done.
![](https://lh3.googleusercontent.com/Zd9Kv-mzHANXGkiEMR9imz5oZ2AdwNiJDMrjy9Ls6083IBhxhcuMA6Xf30khMaUZD_NVsZd39bOxfkOC3oHii4H_oz8Nh8jEv000IW_a1J_Uo4XAEzfDN-8kKSbvhn055sgKSNuPQL9KZ0cV_A)
![](https://lh3.googleusercontent.com/b-5G7EqQzoXDisHET5YXgJFwdDJEzutSzSgWHtnNwQ2p98LlrjXYnj8CuS3GCX5UsV1FqbaTz7qdd7t952zgfgmsZfDt94LpsjdIhY5wrUEvqNkx6o_9G5RIL6zWQJxd7rh8_dydDKsM_W26IQ)


16. In the connection icon, there will be a new option that is used to connect to the VPN. It will ask for the access credentials, and you will be all ready.
![](https://lh5.googleusercontent.com/wU0TO8ug5s04TQMicKcFF3zlbs7OOR0_CxXeYxVuxn9cCRPLaudtcbBoPW4TKUcoxI_yirdris_VBRALNmTWGIG6xT-2bzYEDEoHyGe5K300Vy2jh1FNDLmgfGm3E7eLKZbPOr3fmne_Hj0GIg)
