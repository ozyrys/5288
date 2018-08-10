<?php
/**
 * @file
 * Needs to be documented.
 */

?>
<header id="navbar" role="banner">
  <?php if (!empty($page['tools'])): ?>
    <!-- Region Tools -->
    <div id="tools" class="region-tools">
      <div class="container">
        <div class="container-icon">
          <!-- This button is used as the toggle for collapsed "Main" & "Header" navigation menus -->
          <button class="icon-menu"><span class="icon-menu-text">Menu</span></button>
        </div>
        <?php print render($page['tools']); ?>
      </div>
    </div>
  <?php endif; ?>
  <?php if (!empty($page['navigation'])): ?>
    <nav id="navigation" class="region-navigation">
      <div class="container">
        <div class="container-inner">
          <?php print render($page['navigation']); ?>
        </div>
      </div>
      <div class="container-icon">
        <!-- This button is used as the toggle for collapsed "Main" & "Header" navigation menus -->
        <button class="icon-menu"><span class="icon-menu-text">Menu</span></button>
      </div>
    </nav>
  <?php endif; ?>
</header>

<div id="content-to-resize">
  <div id="main" class="container">
    <div id="home-sections">
      <main>
        <section id="home" class="home-section section-welcome section-row-1">
          <div class="section-wrapper">
            <div class="section-content clearfix">
              <?php if (theme_get_setting('nerra_toggle_message') && $messages): ?>
                <!-- messages -->
                <div id="messages" class="clear clearfix"><?php print $messages; ?></div>
              <?php endif; ?>
              <?php if ($logo || $site_slogan || $site_name || !empty($page['header'])): ?>
                <div id="logo-or-slogan">
                  <?php if ($logo): ?>
                    <!-- Region Logo -->
                    <div class="logo">
                      <div class="logo-inner">
                        <a href="<?php echo url('<front>'); ?>" title="<?php ($site_name) ? print t('Return to the !site_name homepage', array('!site_name' => $site_name)) : print t('Return to the homepage'); ?>">
                          <img src="<?php print $logo ?>" srcset="<?php print str_replace('logo.png','logo.png 1x', $logo) ?>, <?php print str_replace('logo.png','logo@2x.png 2x', $logo) ?>" alt="<?php ($site_name) ? print t('Return to the !site_name homepage', array('!site_name' => $site_name)) : print t('Return to the homepage'); ?>" id="logo" />
                        </a>
                      </div>
                    </div>
                  <?php endif; ?>
                  <?php if ($site_slogan): ?>
                    <div class="name-or-slogan">
                      <?php if (!empty($site_slogan)): ?>
                        <div class="slogan">
                          <?php echo $site_slogan; ?>
                        </div>
                      <?php endif; ?>
                    </div>
                  <?php endif; ?>
                </div>
                <?php if (!empty($page['header'])): ?>
                  <div class="region-header">
                    <?php print render($page['header']); ?>
                  </div>
                <?php endif; ?>
              <?php endif; ?>
              <?php print render($page['front_slide_highlights']); ?>
            </div>
          </div>
          <div><a class="next-section" href="#about">Next</a></div>
        </section>
        <section id="about" class="home-section section-about section-row-2">
          <div class="section-wrapper">
            <div class="section-head"></div>
            <div class="section-content clearfix">
              <?php print render($page['front_slide_about']); ?>
            </div>
          </div>
        </section>
        <section id="services" class="home-section section-services section-row-3">
          <div class="section-wrapper">
            <div class="section-head"></div>
            <div class="section-content clearfix">
              <?php print render($page['front_slide_services']); ?>
            </div>
          </div>
        </section>
        <section id="job" class="home-section section-job section-row-4">
          <div class="section-wrapper">
            <div class="section-head"></div>
            <div class="section-content clearfix">
              <?php print render($page['front_slide_job']); ?>
            </div>
          </div>
        </section>
        <section id="contact" class="home-section section-contact section-row-5">
          <div class="section-wrapper">
            <div class="section-head"></div>
            <div class="section-content clearfix">
              <?php print render($page['front_slide_contact']); ?>
            </div>
          </div>
        </section>
      </main>
      <section id="section-footer" class="home-section section-footer section-row-6">
        <div class="section-wrapper">
          <div class="section-head"></div>
          <div class="section-content clearfix">
            <footer id="footer" role="contentinfo">
              <div class="container">
                <div class="container-inner">
                  <!-- Region Footer -->
                  <div class="row">
                    <div id="region-footer-top" class="clearfix">
                      <?php if (!empty($page['footer_top'])) : ?>
                        <?php echo render($page['footer_top']); ?>
                      <?php endif; ?>
                    </div>
                    <div id="copyright"><?php echo t('©EGOVSelect') . ' ' . date('Y') ?> </div>
                    <?php if (!empty($page['footer'])) : ?>
                      <?php echo render($page['footer']); ?>
                    <?php endif; ?>
                    <div id="region-footer-bottom" class="clearfix">
                      <?php if (!empty($page['footer_bottom'])) : ?>
                        <?php echo render($page['footer_bottom']); ?>
                      <?php endif; ?>
                    </div>
                  </div>
                </div>
              </div>
            </footer>
          </div>
        </div>
      </section>
    </div>
  </div>
</div>
