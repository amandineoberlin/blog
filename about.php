<?php
	session_start();

	require_once('include/constantes.inc');

	define('TITLE_PAGE', 'A propos');
	
	require_once('controller/about.inc');
	
	require_once('view/about.inc');
?>