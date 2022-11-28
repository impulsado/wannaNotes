## BrainStorm
- Simple singup and login system with PHP and MySQL Database
https://www.youtube.com/watch?v=WYufSGgaCZ8&ab_channel=QuickProgramming

- Google Authenticator Time-Based PGP
https://youtu.be/t49zjBGD75U

## Main
### Structure
```structure
- /var/www/html/authServer
	- connection.php
	- functions.php
	- index.php
	- login.php
	- logout.php
	- signup.php
```

### index.php vs index.html
If you want code to be executed in the file, you will need to choose PHP (.php).

> Apache default configuration
```php
<IfModule mod_dir.c>
	DirectoryIndex index.html index.cgi index.pl index.php index.xhtml index.htm
</IfModule
```
This means that if you have an `index.html` and a `index.php` in the SAME folder, the html file will be displayed first.

### index.php
```php
<?php
session_start();
	$_SESSION;
?>
```
Creates a new session or resumes the current one based on a session identifier passed via GET or POST request, or passed via cookie. ((!!May be will need to secure))
Sessions are stored in server side, not like cookies that are stored on the client. 


### signup.php
```php
<?php
session_start();
	include("connections.php");
	include("functions.php");

	$user_data = check_login($con);
?>
```
Every time the client access our website, it will check if it's logged-in. This check will be executed by `check_login()` function created in `functions.php`.

[More info](https://www.php.net/manual/en/function.session-start.php)

