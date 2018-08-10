<?php
/**
 * @file
 * The page template for the language selection screen.
 *
 * Variables used:
 * - head: the relevant head tag
 * - styles: the relevant CSS tags
 * - scripts: the relevant Javascript tags
 * - site_name: the name of the site
 * - language_selection_page: array with language_selection_page to the page we are trying to access.
 *
 */
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
	"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html class="main-document" xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en" dir="ltr">
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0"><!-- Equalizing density display(example : Retina display) http://darkforge.blogspot.be/2010/05/customize-android-browser-scaling-with.html and http://designbycode.tumblr.com/post/1127120282/pixel-perfect-android-web-ui-->
    <link href='//fonts.googleapis.com/css?family=Lato:900,700,400,300' rel='stylesheet' type='text/css'>
    <?php print $head ?>
    <title><?php print check_plain(variable_get('site_name', 'Drupal')); ?> | Taalkeuze | Choix de langue | Sprachauswahl | Language Choice</title>
    <?php print $styles; ?>
    <?php print $scripts; ?>
  </head>
  <body class="language-selection-page">
    <div id="page">

      <div class="container">
	    <div id="logo-title">
              <?php 
                if (!$logo = theme_get_setting('logo_path')) {
                  $logo = theme_get_setting('logo');
                }
                print theme_image(array('path' => '/sites/all/themes/custom/egovselect/logo.png', 'alt' => 'Logo', 'title' => 'Logo', 'attributes' => array()));
              ?>
        </div>
      	<div id="main" class="column">
          <div id="main-squeeze">
          <div id="content">
            <div class="langchoice_list">
              <?php foreach ($language_selection_page['links'] as $link) : ?>
                <?php if ($link['language']->language == 'nl') : ?>
                  <div class="nl language-pos" lang="nl">
				    <div class="inner">
				      <div class="language-title">Welkom bij de eGov-diensten van de federale overheid</div>
                      <div class="langchoice_label">Kies uw taal</div>
                      <a class="langchoice_link button" href="<?php print $link['url']; ?>">Ga verder in het Nederlands</a>
					</div>
                  </div>
                <?php endif; ?>
              <?php endforeach; ?>
              <?php foreach ($language_selection_page['links'] as $link) : ?>
                <?php if ($link['language']->language == 'fr') : ?>
                  <div class="fr language-pos" lang="fr">
				    <div class="inner">
				      <div class="language-title">Bienvenue sur les services eGov de l'Administration fédérale</div>
                      <div class="langchoice_label">Choisissez votre langue</div>
                      <a class="langchoice_link button" href="<?php print $link['url']; ?>">Continuer en français</a>
					</div>
                  </div>
                <?php endif; ?>
              <?php endforeach; ?>
              <?php foreach ($language_selection_page['links'] as $link) : ?>
                <?php if ($link['language']->language == 'de') : ?>
                  <div class="de language-pos" lang="de">
				    <div class="inner">
				      <div class="language-title">Willkommen bei den eGov-Diensten der föderalen Behörde</div>
                      <div class="langchoice_label">Wählen Sie Ihre Sprache</div>
                      <a class="langchoice_link button" href="<?php print $link['url']; ?>">Auf Deutsch fortfahren</a>
					</div>
                  </div>
                <?php endif; ?>
              <?php endforeach; ?>
              </div>
           </div>
          </div>
        </div>
      </div>
      <div id="footer-wrapper">
        <div id="footer">
        </div>
      </div>
    </div>
  </body>
</html>
