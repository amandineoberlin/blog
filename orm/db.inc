<?php
//Connexion a la base de donnees SQL

$db_host = 'db610512441.db.1and1.com';
$db_user = 'dbo610512441';
$db_pwd = 'blogamandineoberlin';
$db_name = 'db610512441';

//Pour les tests en local
//$db_host = 'localhost';
//$db_user = 'root';
//$db_pwd = '';
//$db_name = 'blog';

$db = new PDO("mysql:host=$db_host;dbname=$db_name", $db_user, $db_pwd, 
	array(PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION));
?>