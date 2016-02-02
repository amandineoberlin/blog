<?php
session_start();

require_once('include/constantes.inc');

define('TITLE_PAGE', 'Connexion');

require_once('controller/login.inc');

require_once('view/login.inc');
?>