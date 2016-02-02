<?php
session_start();

require_once('include/constantes.inc');

define('TITLE_PAGE', 'Back-office');

require_once('controller/backoffice.inc');

require_once('view/backoffice.inc');
?>