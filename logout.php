<?php
session_start();

require_once('include/constantes.inc');

define('TITLE_PAGE', 'Déconnexion');

require_once('controller/logout.inc');

require_once('view/logout.inc');
?>