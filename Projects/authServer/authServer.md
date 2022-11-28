## BrainStorm
- Simple singup and login system with PHP and MySQL Database
https://www.youtube.com/watch?v=WYufSGgaCZ8&ab_channel=QuickProgramming

- Google Authenticator Time-Based PGP
https://youtu.be/t49zjBGD75U

## MySQL
```sh
sudo apt update
sudo apt install mysql-server
sudo mysql

mysql> ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY 'password';
mysql> exit;

mysql -u root -p
mysql> ALTER USER 'root'@'localhost' IDENTIFIED WITH auth_socket;

sudo mysql_secure_installation
```

```SQL
CREATE DATABASE login_db;
USE login_db;
CREATE TABLE users (
	id INT AUTO_INCREMENT PRIMARY KEY,
    user_id BIGINT,
    usr_name VARCHAR(255) NOT NULL,
    usr_passwd VARCHAR(255) NOT NULL,
    date TIMESTAMP
);
```

## Web
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
[More info](https://www.php.net/manual/en/function.session-start.php)
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

### connection.php
```php
<?php

$db_host = "localhost";
$db_user = "root";
$db_passwd = "";
$db_name = "login_db";

if(!$con = mysqli_connect($db_host,$db_user,$db_passwd,$db_name))
{
    die("Failed to Connect!");
}
```
This file will be used to connect with the localhost MySQL database. Once connected, we can delete this file.




