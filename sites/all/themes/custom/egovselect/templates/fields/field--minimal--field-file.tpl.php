<?php
/**
 * @file
 * Needs to be documented.
 */
?>

<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php if (!$label_hidden): ?>
    <div class="field-label"<?php print $title_attributes; ?>><?php print $label ?>:&nbsp;</div>
  <?php endif; ?>
  <div class="field-items"<?php print $content_attributes; ?>>
    <?php foreach ($items as $delta => $item): ?>
    <?php 
      if (isset($item['#file']->uri) && file_exists($item['#file']->uri)) {
          ?>
            <div class="field-item <?php print $delta % 2 ? 'odd' : 'even'; ?>"<?php print $item_attributes[$delta]; ?>><?php print l((!empty($item['#file']->description) ? $item['#file']->description : $item['#file']->filename) . ' <span class="file-extension">' . pathinfo($item['#file']->uri)['extension']. '</span> <span class="file-size">[' . format_size($item['#file']->filesize) . ']</span>', file_create_url($item['#file']->uri), array('html' => true, 'attributes' => array('target' => '_blank'))); ?></div>
          <?php
      } else {
    ?>
      <div class="field-item <?php print $delta % 2 ? 'odd' : 'even'; ?>"<?php print $item_attributes[$delta]; ?>><?php print render($item); ?></div>
    <?php } ?>
    <?php endforeach; ?>
  </div>
</div>
