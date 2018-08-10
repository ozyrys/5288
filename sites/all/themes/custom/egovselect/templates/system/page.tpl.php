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
    </nav>
  <?php endif; ?>
  <?php if (!empty($page['header'])): ?>
    <div class="container">
      <?php if (!empty($page['header'])): ?>
        <div class="region-header">
          <?php print render($page['header']); ?>
        </div>
      <?php endif; ?>
    </div>
  <?php endif; ?>
</header>

<div id="content-to-resize">

<?php if (!empty($page['top'])): ?>
  <!-- Region top -->
    <section id="top">
      <div class="container">
        <?php print render($page['top']); ?>
      </div>
    </section>
<?php endif; ?>

<?php if (theme_get_setting('nerra_toggle_message') && $messages): ?>
      <!-- messages -->
        <div id="messages" class="clear clearfix">
          <div class="container">
            <div class="container-inner clearfix">
              <?php print $messages; ?>
            </div>
          </div>
        </div>
<?php endif; ?>

<div id="main">
  <div class="container">
    <?php if (theme_get_setting('nerra_toggle_tabs') && $tabs = render($tabs)): ?>
      <div class="tabs"><?php print $tabs; ?></div>
    <?php endif; ?>
    <div class="row">
      <?php if (!empty($page['sidebar_first'])): ?>
      <!-- Region Left -->
        <aside id="aside-left" class="<?php echo $class_left; ?>" role="complementary">
          <?php echo render($page['sidebar_first']); ?>
        </aside>
      <?php endif; ?>

      <main id="maincontent" class="<?php echo $class_content; ?>">
        <!-- Region Content -->

        <?php print render($title_prefix); ?>
        <?php if ($title): ?>
          <h1 class="page-header"><?php print $title; ?></h1>
        <?php endif; ?>
        <?php print render($title_suffix); ?>

        <?php if (theme_get_setting('nerra_breadcrumb_display')): ?>
          <?php if ($breadcrumb != ''): ?>
            <!-- Region Breadcrumb -->
            <nav <?php if (!empty($breadcrumb_aria_label)) print 'aria-label="' . $breadcrumb_aria_label . '" '; ?>id="breadcrumb" itemscope itemtype="http://data-vocabulary.org/Breadcrumb">
              <div class="breadcrumb-inner">
                <?php print preg_replace("/<h2\s(.+?)>(.+?)<\/h2>/is", "<span $1>$2</span>",$breadcrumb); ?>
              </div>
            </nav>
          <?php endif; ?>
        <?php endif; ?>

        <?php if (theme_get_setting('nerra_toggle_actions') && $action_links): ?>
          <ul class="action-links"><?php print render($action_links); ?></ul>
        <?php endif; ?>

        <span id="main-content"></span>

        <?php echo render($page['content_top']); ?>
        <?php echo render($page['content']); ?>
        <?php echo render($page['content_bottom']); ?>
      </main>

      <?php if (!empty($page['sidebar_second'])): ?>
      <!-- Region Right -->
        <aside id="aside-right" class="<?php echo $class_right; ?>">
          <?php echo render($page['sidebar_second']); ?>
        </aside>
      <?php endif; ?>
    </div>
  </div>
</div>

  <?php if (!empty($page['prebottom'])): ?>
    <!-- bottom -->
    <section id="prebottom">
      <div class="container"><?php echo render($page['prebottom']); ?></div>
    </section>
  <?php endif; ?>

<?php if (!empty($page['bottom'])): ?>
<!-- bottom -->
  <section id="bottom">
    <div class="container"><?php echo render($page['bottom']); ?></div>
  </section>
<?php endif; ?>
</div>

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
        <div id="copyright"><?php echo t('©EGOVSelect') . ' ' . date('Y'); ?> </div>
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
