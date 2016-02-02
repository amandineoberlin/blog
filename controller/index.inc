<?php
//Controlleur permettant l'affichage de la liste des articles de la BD

        ////Appel à la connexion à la BD
	require_once('orm/db.inc');
	
	$sql = 'SELECT a.id_article, a.titre, a.date, a.corps, u.nom, u.prenom FROM article a NATURAL JOIN user u ORDER BY date DESC;';
	
	$result = $db->query($sql);
	
	$tabArticles = $result->fetchAll();

?>