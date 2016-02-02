<!-- Navigation (bar menu) -->
<nav class="navbar navbar-default" role="navigation">
    <div class="container">
        <!-- Creation d'une barre de navigation en toggle pour les petits ecrans -->
        <div class="navbar-header">
            <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#bs-example-navbar-collapse-1">
                <span class="sr-only">Toggle navigation</span>
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
            </button>
            <!--Titre affiche de la barre si l'ecran est retreci-->
            <a class="navbar-brand" href="index.php">Blog d'Amandine Oberlin</a>
        </div>
        <!-- Redirection vers les pages concernees -->
        <div class="collapse navbar-collapse" id="bs-example-navbar-collapse-1">
            <ul class="nav navbar-nav">
                <li>
                    <a href="index.php">Accueil</a>
                </li>
                <?php
                if (!isset($_SESSION['loggedUser'])) {
                    ?>
                    <li>
                        <a href="login.php">Se Connecter</a>
                    </li>
                    <li>
                        <a href="signup.php">S'inscrire</a>
                    </li>
                    <?php
                } else {
                    ?>
                    <li><a href="logout.php">Déconnexion</a></li>
                    <?php
                }
                ?>
                <?php
                if (isset($_SESSION['loggedUser']) && $_SESSION['loggedUser']['profil'] !== PROFIL_VISITEUR) {
                    ?>
                    <li><a href="backoffice.php">Back-office</a></li>
                    <?php
                }
                ?>
                <li><a href="about.php">A propos</a></li>
            </ul>
            </nav>


            