<?php
        //Controlleur permettant l'insertion dans la bd d'un nouveel article par un user != qu'un visiteur

        //Appel à la connexion à la BD
	require_once('orm/db.inc');
	
        //Si acces par url direct, redirection vers l'index
	if(!isset($_SESSION['loggedUser']) || $_SESSION['loggedUser']['profil'] === PROFIL_VISITEUR) {
		header('Location: index.php');
	}

	$titreArticle = (isset($_POST['titre_article']))?($_POST['titre_article']):('');
	$dateArticle = (isset($_POST['date_article']))?($_POST['date_article']):('');
	$corpsArticle = (isset($_POST['corps_article']))?($_POST['corps_article']):('');
	$submit_ok = isset($_POST['submit']);
        
	//empechement d'injection et clean du texte
	if($titreArticle && $dateArticle && $corpsArticle) {
		$corpsArticle = strip_tags($corpsArticle, '<b><strong><i><em><u><ul><li><ol>');
		$corpsArticle = str_replace(' ', '&nbsp;', $corpsArticle);
		$corpsArticle = nl2br($corpsArticle);
		
		$article = array(
			'titre' => $titreArticle,
			'date' => $dateArticle,
			'corps' => $corpsArticle
		);

                //Enregistrement dans la BD
		$sql = "INSERT INTO article(titre, date, corps, id_user) VALUES(:titre, :date, :corps, :id_user);";
		
		$st = $db->prepare($sql);
		
		$params = array(
			'titre' => $article['titre'],
			'date' => date($article['date']),
			'corps' => $article['corps'],
			'id_user' => $_SESSION['loggedUser']['id_user'],
		);
		
		$st->execute($params);
		
                //redirection vers Accueil
		header('Location: index.php');
	}
?>