<?php

/**
 * @file
 * Display Suite 1 column template.
 */
?>
<<?php print 'article'; print $layout_attributes; ?> class="ds-1col <?php print $classes;?> clearfix">

  <?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

  <?php if (empty($variables['field_image_01'])): ?>
    <div class="page-header-placeholder"><div class="page-header-placeholder-inner"></div></div>
  <?php endif; ?>
  
  <?php print $ds_content; ?>
</<?php print 'article'; ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
