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
                        <h2 class="intro-text text-center">Inscrivez -
                            <strong> vous</strong>
                        </h2>
                        <hr>

                        <div class="row">
                            <div class="col-md-offset-2 col-md-9">
                                <div class="form-group">
                                    <label for="pseudo" id="label_pseudo">Votre pseudo</label> :
                                    <input type="text" name="pseudo" id="pseudo" class="form-control" value="<?php if (!$form_ok) echo $pseudo; ?>"/>
                                </div>
                            </div>

                            <div class="col-md-offset-2 col-md-4">
                                <div class="form-group">
                                    <label for="mdp1" id="label_mdp1">Votre mot de passe</label> :
                                    <input type="password" name="mdp1" id="mdp1" class="form-control"/>
                                </div>
                            </div>

                            <div class="col-md-offset-1 col-md-4">
                                <div class="form-group">
                                    <label for="mdp2" id="label_mdp2">Confirmer</label> :
                                    <input type="password" name="mdp2" id="mdp2" class="form-control"/>
                                </div>
                            </div>

                            <div class="col-md-offset-2 col-md-4">
                                <div class="form-group">
                                    <label for="nom" id="label_nom">Votre nom</label> :
                                    <input type="text" name="nom" id="nom" class="form-control" value="<?php if (!$form_ok) echo $nom; ?>"/>
                                </div>
                            </div>

                            <div class="col-md-offset-1 col-md-4">
                                <div class="form-group">
                                    <label for="prenom" id="label_prenom">Votre prénom</label> :
                                    <input type="text" name="prenom" id="prenom" class="form-control" value="<?php if (!$form_ok) echo $prenom; ?>"/>
                                </div>
                            </div>

                            <div class="col-md-offset-2 col-md-4">
                                <div class="form-group">
                                    <label for="tel" id="label_tel">Téléphone</label> :
                                    <input type="tel" name="tel" id="tel" class="form-control" value="<?php if (!$form_ok) echo $tel; ?>"/>
                                </div>
                            </div>

                            <div class="col-md-offset-1 col-md-4">
                                <div class="form-group">
                                    <label for="nais" id="label_nais">Date de naissance</label> :
                                    <input type="date" name="nais" id="nais" class="form-control" value="<?php if (!$form_ok) echo $nais; ?>"/>
                                </div>
                            </div>

                            <div class="col-md-offset-2 col-md-9">
                                <div class="form-group">
                                    <label for="email" id="label_email">Email</label> :
                                    <input type="text" name="email" id="email" class="form-control" value="<?php if (!$form_ok) echo $email; ?>"/>
                                </div>
                            </div>
                            <br/>
                        </div>

                        <div class="col-md-offset-5 col-md-9">
                            <input type="submit" value="S'inscrire" name="submit" class="btn btn-success"/>
                            <input type="reset" class="btn btn-danger" value="Annuler" />
                        </div>

                        <div class="col-md-offset-2 col-md-9">
                            <p><?php echo $errorMsg; ?></p>
                        </div>

                    </div>
                </div>
            </div>
        </div>
    </form>
</section>