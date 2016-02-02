<?php
        //Si acces direct par url, redirection vers accueil
	if(!isset($_SESSION['loggedUser'])) {
		header('Location: index.php');
	}
	
        //Destruction de la session utilisateur -> deconnexion
	session_unset();
	session_destroy();
	
	header('Location: index.php');
?>