<!--je recupere mon titre de page en cours pour l'afficher-->
<?php
if (!defined('TITLE_PAGE')) {
    define('TITLE_PAGE', '');
}
?>

<!--Code html du header-->
<!doctype html>
<html lang="fr">
    <head>
        <meta charset="utf-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <meta name="Blog Amandine" content="">
        <title>Blog Amandine Oberlin</title>

        <!-- CSS principal de Bootstrap -->
        <link href="css/bootstrap.min.css" rel="stylesheet">
        <!-- Mon CSS -->
        <link href="css/style.css" rel="stylesheet">

        <!-- Polices -->
        <link href="http://fonts.googleapis.com/css?family=Open+Sans:300italic,400italic,600italic,700italic,800italic,400,300,600,700,800" rel="stylesheet" type="text/css">
        <link href="http://fonts.googleapis.com/css?family=Josefin+Slab:100,300,400,600,700,100italic,300italic,400italic,600italic,700italic" rel="stylesheet" type="text/css">
    </head>

    <body>
        <header> 
            <!-- Bandeau titre -->
            <div class="brand">Staying tuned in</div>
                <div class="intro-text text-center"> <?php echo TITLE_PAGE; ?> </div>
            <div class="address-bar"><?php
                if (isset($_SESSION['loggedUser']) && $_SESSION['loggedUser']) {
                    //Si la case logged user a bien été créé et que la case n'est pas vide (pas nécessaire de vérifier
                    //quelle n'est pas vide mais au cas ou, on ne sait jamais ce qu'on va mettre dans notre code plus tard
                    echo "Bonjour" . ' ' . $_SESSION['loggedUser']['prenom'];
                }
                ?></div>
