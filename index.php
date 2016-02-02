<?php
session_start();

require_once('include/constantes.inc');

define('TITLE_PAGE', 'Accueil');

require_once('controller/index.inc');

require_once('view/index.inc');
?>