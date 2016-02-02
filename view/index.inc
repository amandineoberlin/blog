<?php
require_once('parts/header.inc');
require_once('parts/nav.inc');
?>
<section>
    <div class="container">

        <div class="row">
            <div class="box">
                <div class="col-lg-12">
                    <hr>
                    <h2 class="intro-text text-center">Liste
                        <strong>des articles</strong>
                    </h2>
                    <hr>
                </div>

                <div class="col-lg-12 text-center">
                    <img class="img-responsive img-border img-full" src="img/mic.png" id="sono" alt=""><hr>
                </div>
                <?php
                foreach ($tabArticles as $article) {
                    ?>

                    <h2><?php echo $article['titre']; ?>
                        <br>
                        <small><?php echo $article['date']; ?></small></br>
                        <small><?php echo $article['prenom'] . ' ' . $article['nom']; ?></small>
                    </h2>
                    <p><?php echo $article['corps']; ?></p>
                    <hr>
                    <?php
                }
                ?>
                    </section>


