<?php
require_once('include/functions.inc'); //Appel au fichier fonctions pour les regex
require_once('include/constantes.inc'); //Appel au fichier constantes pour créer un utilisateur en profil visiteur
require_once('orm/db.inc'); //Connexion à la BD

//Si acces par url direct, redirection vers accueil
if(isset($_SESSION['loggedUser'])) {
	header('Location: index.php');
}

$pseudo = (isset($_POST['pseudo']))?(trim($_POST['pseudo'])):('');
$mdp1 = (isset($_POST['mdp1']))?(trim($_POST['mdp1'])):('');
$mdp2 = (isset($_POST['mdp2']))?(trim($_POST['mdp2'])):('');
$nom = (isset($_POST['nom']))?(trim($_POST['nom'])):('');
$prenom = (isset($_POST['prenom']))?(trim($_POST['prenom'])):('');
$tel = (isset($_POST['tel']))?(trim($_POST['tel'])):('');
$nais = (isset($_POST['nais']))?(trim($_POST['nais'])):('');
$email = (isset($_POST['email']))?(trim($_POST['email'])):('');
$submit_ok = isset($_POST['submit']);

$form_ok = true;
$errorMsg = '';

//Procedure de verification des données entrees
if($submit_ok) {
	if(!$pseudo) {
		$form_ok = false;
		$errorMsg .= 'Veuillez entrer un pseudo<br/>';
	} else {
		$sql = 'SELECT * FROM user WHERE pseudo=:p;';
		$st = $db->prepare($sql);
		$st->execute(array('p' => $pseudo));
		if($st->fetch()) {
			$form_ok = false;
			$errorMsg .= 'Pseudo déjà utilisé<br/>';
		}
	}
	
	if(!$mdp1 && !$mdp2) {
		$form_ok = false;
		$errorMsg .= 'Veuillez entrer un mot de passe<br/>';
	} else if($mdp1 != $mdp2) {
		$form_ok = false;
		$errorMsg .= 'Les mots de passe ne correspondent pas<br/>';
	} else {
//		$mdp_hash = hash('sha256', $mdp1);
                $mdp_hash = $mdp1;
	}
	
	if(!$nom) {
		$form_ok = false;
		$errorMsg .= 'Veuillez entrer un nom<br/>';
	}
	
	if(!$prenom) {
		$form_ok = false;
		$errorMsg .= 'Veuillez entrer un prénom<br/>';
	}
	
	if(!$tel) {
		$form_ok = false;
		$errorMsg .= 'Veuillez entrer un numéro de téléphone<br/>';
	} else if(!checkTel($tel)) {
		$form_ok = false;
		$errorMsg .= 'Veuillez entrer un numéro de téléphone valide !<br/>';
	} else {
		$tel = formatTel($tel);
	}
	
	$nais = dateFR2ISO($nais);
	if(!$nais) {
		$form_ok = false;
		$errorMsg .= 'Veuillez entrer une date de naissance<br/>';
	} else if(!checkDateISO($nais)) {
		$form_ok = false;
		$errorMsg .= 'Veuillez entrer une date de naissance valide !<br/>';
	}
	
	if(!$email) {
		$form_ok = false;
		$errorMsg .= 'Veuillez entrer un email<br/>';
	} else if(!checkEmail($email)) {
		$form_ok = false;
		$errorMsg .= 'Veuillez entrer un email valide !<br/>';
	}
	
        //Si toutes les verifs sont ok, creation d'un nouvel utilisateur
	if($form_ok) {
		$sql = 'INSERT INTO user(pseudo, mdp_hash, nom, prenom, nais, tel, email, profil)'
			. 'VALUES(:pseudo, :mdp_hash, :nom, :prenom, :nais, :tel, :email, :profil);';
			
		$params = array(
			'pseudo' => $pseudo,
			'mdp_hash' => $mdp_hash,
			'nom' => $nom,
			'prenom' => $prenom,
			'nais' => $nais,
			'tel' => $tel,
			'email' => $email,
			'profil' => PROFIL_VISITEUR,
		);
		
		$st = $db->prepare($sql);
		$st->execute($params);
		
                //Recuperation du dernier ID du dernier enregistrement pour garder l'utilisateur connecté
		if($st->rowCount()) {
			$id_user = $db->lastInsertId();
			
			$sql = 'SELECT id_user, pseudo, nom, prenom, nais, tel, email, profil FROM user WHERE id_user=:id;';
			
			$st = $db->prepare($sql);
			
			$st->execute(array('id' => $id_user));
			$user = $st->fetch();
			
			if($user) {
				$_SESSION['loggedUser'] = $user;
		
				header('Location: index.php');
			}
		} else {
			$errorMsg .= 'Erreur d\'enregistrement<br/>';
		}
	}
}
?>