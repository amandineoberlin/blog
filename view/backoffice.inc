<?php
require_once('parts/header.inc');
require_once('parts/nav.inc');
?>

<section>
    <form method="POST" role="form">
        <div class="container">

            <div class="row">
                <div class="box">
                    <div class="col-lg-12">
                        <hr>
                        <h2 class="intro-text text-center">Nouvel
                            <strong> article</strong>
                        </h2>
                        <hr>

                        <div class="row">
                            <div class="col-md-offset-2 col-md-9">
                                <div class="form-group">
                                    <label for="input_titre">Titre : </label>
                                    <input type="text" id="input_titre" name="titre_article" class="form-control"/>
                                </div>
                            </div>

                            <div class="col-md-offset-2 col-md-9">
                                <div class="form-group">
                                    <label for="input_date">Date : </label>
                                    <input type="date" id="input_date" name="date_article" class="form-control" />
                                </div>
                            </div>

                            <div class="col-md-offset-2 col-md-9">
                                <div class="form-group">
                                    <label for="textarea_corps">Corps : </label>
                                    <textarea id="textarea_corps" name="corps_article" class="form-control"></textarea>
                                </div>
                            </div>

                            <br/>

                            <div class="row">
                                <div class="col-md-offset-2 col-md-4">
                                    <input class="form_button" name="submit" type="submit" value="Enregistrer" class="btn btn-primary"/>
                                </div>
                            </div>
                        </div>
                    </div></div>
            </div></div>
        <?php
        if ($submit_ok && !($titreArticle && $dateArticle && $corpsArticle)) {
            echo 'Veuillez remplir tous les champs';
        }
        ?>
    </form>
</section>