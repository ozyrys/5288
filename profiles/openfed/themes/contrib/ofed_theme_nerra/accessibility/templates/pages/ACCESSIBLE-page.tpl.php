<?php
/**
 * @file
 *
 *  Line 21: Added role attribute.
 *  Line 31: Title attribute fix.
 *  Line 32: Alt attribute fix.
 *  Lines 41,45,65,67,126,128:
 *           Replaced section element with simple div for accessibility.
 *  Lines 86,113: Replaced div with main element for accessibility.
 *  Lines 71,74: Replaced div with nav element for accessibility.
 *  Line 73: Replaced h2 with span element to avoid error:
 *              "The heading structure is not logically nested"
 *  Line 102: Added skip-link referer.
 *  Line 117: Added role attribute.
 *  Line 132: Added role attributes.
 *
 */

?>
<header role="banner">
  <div class="container">
    <?php if (!empty($page['tools'])): ?>
    <!-- Region Tools -->
      <div id="tools"><?php print render($page['tools']); ?></div>
    <?php endif; ?>

	  <?php if ($logo): ?>
    <!-- Region Logo -->
      <div class="logo">
        <a href="<?php echo url('<front>'); ?>" title="<?php ($site_name) ? print t('Return to the !site_name homepage', array('!site_name' => $site_name)) : print t('Return to the homepage'); ?>">
          <img id="logo" src="<?php print $logo; ?>" alt="<?php ($site_name) ? print t('Return to the !site_name homepage', array('!site_name' => $site_name)) : print t('Return to the homepage'); ?>" />
        </a>
      </div>
    <?php endif; ?>

    <div class="slogan"><?php echo $site_slogan; ?></div>
  </div>
  <?php if (!empty($page['header'])): ?>
  <!-- Region Header -->
  <div id="header">
      <div class="container">
	  <?php print render($page['header']); ?>
      </div>
  </div>
  <?php endif; ?>
</header>

<?php if (!empty($page['navigation'])): ?>
<nav id="navigation" aria-label="<?php print t('Main navigation'); ?>">
  <div class="container">
    <span class="icon-menu">
      <?php print 'menu'; ?>
    </span>
	<!-- Region Navigation -->
	<?php print render($page['navigation']); ?>
  </div>
</nav>
<?php endif; ?>

<div id="content-to-resize">

<?php if (!empty($page['top'])): ?>
  <!-- Region top -->
    <div id="top">
      <div class="container"><?php print render($page['top']); ?></div>
    </div>
<?php endif; ?>

<?php if (theme_get_setting('nerra_breadcrumb_display')): ?>
<!-- Region Breadcrumb -->
  <nav <?php if (!empty($breadcrumb_aria_label)) print 'aria-label="' . $breadcrumb_aria_label . '" '; ?>class="breadcrumb-wrapper">
    <?php print preg_replace("/<h2\s(.+?)>(.+?)<\/h2>/is", "<span $1>$2</span>", render($page['breadcrumb'])); ?>
  </nav>
<?php endif; ?>

<div id="main">
  <div class="container">
    <?php if (!empty($page['sidebar_first'])): ?>
    <!-- Region Left -->
      <div id="aside-left" class="<?php echo $class_left; ?>">
        <?php echo render($page['sidebar_first']); ?>
      </div>
    <?php endif; ?>

    <main id="maincontent" class="<?php echo $class_content; ?>">
      <!-- Region Content -->
      <?php if (theme_get_setting('nerra_toggle_message') && $messages): ?>
      <!-- messages -->
        <div id="messages" class="clear clearfix"><?php print $messages; ?></div>
      <?php endif; ?>

      <?php print render($title_prefix); ?>
      <?php if ($title): ?>
        <h1><?php print $title; ?></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>

      <?php if (theme_get_setting('nerra_toggle_tabs') && $tabs = render($tabs)): ?>
        <div class="tabs"><?php print $tabs; ?></div>
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
      <aside id="aside-right" class="<?php echo $class_right; ?>" role="complementary">
        <?php echo render($page['sidebar_second']); ?>
      </aside>
    <?php endif; ?>
  </div>
</div>

<?php if (!empty($page['bottom'])): ?>
<!-- bottom -->
  <div id="bottom">
    <div class="container"><?php echo render($page['bottom']); ?></div>
  </div>
<?php endif; ?>

</div>
<footer id="footer" role="contentinfo">
  <div class="container">
    <?php if (!empty($page['footer'])) : ?>
    <!-- Region Footer -->
      <div class="row">
        <?php echo render($page['footer']); ?>
      </div>
    <?php endif; ?>
    <?php if (theme_get_setting('nerra_copyright_display') || theme_get_setting('nerra_toggle_sponsor')): ?>
      <div class="row">
        <?php if (theme_get_setting('nerra_copyright_display') && theme_get_setting('nerra_copyright_label') != ''): ?>
        <!-- Region Copyright -->
          <div class="copyright span-9">
            <p><?php echo theme_get_setting('nerra_copyright_label'); ?> - <?php print $site_name ?></p>
          </div>
        <?php endif; ?>
        <?php if (theme_get_setting('nerra_toggle_sponsor')): ?>
        <!-- Region Sponsor -->
          <div class="sponsor span-3">
            <?php echo theme_get_setting('nerra_sponsor_label'); ?>
          </div>
        <?php endif; ?>
      </div>
    <?php endif; ?>
  </div>
</footer>
