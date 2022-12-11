## Resources
- Simple singup and login system with PHP and MySQL Database
https://www.youtube.com/watch?v=WYufSGgaCZ8&ab_channel=QuickProgramming

- Google Authenticator Time-Based PGP
https://youtu.be/t49zjBGD75U

## System setup
```sh
sudo apt update && sudo apt upgrade -y
sudo apt install -y mysql-server php apache2 openssl php-common php-curl php-json php-mbstring php-mysql php-xml php-zip
```

## MySQL
```ad-important
REMOVE usr_id
```

```SQL
sudo mysql

ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY 'root';

ALTER USER 'root'@'localhost' IDENTIFIED WITH auth_socket;

CREATE DATABASE login_db;

USE login_db;

CREATE TABLE users (
	id BIGINT AUTO_INCREMENT PRIMARY KEY,
    usr_id BIGINT,
    usr_name VARCHAR(100),
    usr_passwd VARCHAR(100),
    date TIMESTAMP
);

ALTER TABLE `users` ADD INDEX(`usr_id`);
ALTER TABLE `users` ADD INDEX(`usr_name`);
ALTER TABLE `users` ADD INDEX(`date`);
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

### functions.php
```php
<?php

```
- isset vs empty vs is_null
https://phppot.com/php/isset-vs-empty-vs-is_null/



### login.php
- Validate data function
https://github.com/codingWithElias/Login-System-PHP-and-MYSQL/blob/master/login.php

