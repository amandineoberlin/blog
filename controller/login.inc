<?php
//Controlleur permettant le login du user

//Connexion à la bd
require_once('orm/db.inc');

//Si accès par url direct alors que l'utilisateur est deja loggé
if(isset($_SESSION['loggedUser'])) {
	header('Location: index.php');
}

$pseudo = (isset($_POST['pseudo']))?($_POST['pseudo']):('');
$mdp = (isset($_POST['mdp']))?($_POST['mdp']):('');
$submit_ok = isset($_POST['submit']);

$errorMsg = '';

//Verification des données entrees et comparaison a la BD
if($submit_ok && $pseudo && $mdp) {
	$pseudo = strip_tags($pseudo);
	
	$sql = 'SELECT id_user, pseudo, nom, prenom, nais, tel, email, profil FROM user WHERE pseudo=:pseudo AND mdp_hash=:mdp_hash;';
	
	$st = $db->prepare($sql);
	
	$params = array(
		'pseudo' => $pseudo,
//		'mdp_hash' => hash('sha256', $mdp),·
                'mdp_hash' => $mdp,
	);
	
	$st->execute($params);
	
	$user = $st->fetch();
	
	if($user) {

		// A partir de maintenant, on considère que la présence d'une case 'loggedUser' non vide dans la session
		//  représente l'information de connexion, et contient les infos du user connecté
		$_SESSION['loggedUser'] = $user;
		
		header('Location: index.php');
	} else {
		$errorMsg = 'Erreur d\'authentification';
	}
}













?>