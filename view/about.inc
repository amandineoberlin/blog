<?php
require_once('parts/header.inc');
require_once('parts/nav.inc');
?>

<div class="container">

        <div class="row">
            <div class="box">
                <div class="col-lg-12">
                    <hr>
                    <h2 class="intro-text text-center">A propos
                        <strong>de ce site</strong>
                    </h2>
                    <hr>
                </div>
                <div class="col-md-6">
                    <img class="img-responsive img-border-left" src="img/son4.png" alt="">
                </div>
                <div class="col-md-6">
                    <p>Ce blog est une démonstration d'application programmée en PHP5.
                    Le code est basé sur l'architecture MVC et orienté objet.
                    <br/> Il a été créé par Amandine Oberlin </p>
                    
                    <p>Afin de visualiser ses fonctionnalités, vous pouvez vous connecter <br/>
                        en tant qu'utilisateur "visiteur" (login: <strong>visiteur</strong> pass: <strong>motdepasse)</strong><br/>
                        ou en tant qu'utilisateur "administrateur" (login: <strong>admin</strong> pass: <strong>motdepasse)</strong>
                        et ainsi rédiger des articles dans l'onglet "Backoffice". Attention,
                        il n'y a pas de contrôle sur les articles postés et il ne vous sera pas possible de les effacer :-)</p>
                    
                </div>
                <div class="clearfix"></div>
            </div>
        </div>

<?php
require_once('parts/footer.inc');
?>