<?php
require_once('parts/header.inc');
require_once('parts/nav.inc');
?>

<section>
    <form method="POST">
        <div class="container">
            <div class="row">
                <div class="box">
                    <div class="col-lg-12">
                        <hr>
                        <h2 class="intro-text text-center">Connectez -
                            <strong> vous</strong>
                        </h2>
                        <hr>
                        <div class="col-md-offset-3 col-md-7">
                            <div class="form-group">
                                <label for="input_pseudo">Pseudo : </label>
                                <input type="text" id="input_pseudo" name="pseudo" />

                                <label for="input_mdp">Mot de passe : </label>
                                <input type="password" id="input_mdp" name="mdp" />

                                <input class="btn btn-success" name="submit" type="submit" value="Connexion" />

                                <p><?php echo $errorMsg; ?></p>
                                
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </form>
</form>
</section>