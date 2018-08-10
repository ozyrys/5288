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
      <div style="background: url('<?php print file_create_url($item['#item']['uri']) ?>') center center no-repeat; background-size: cover; width: 100%; height: 160px;" class="field-item <?php print $delta % 2 ? 'odd' : 'even'; ?>"<?php print $item_attributes[$delta]; ?>></div>
    <?php endforeach; ?>
  </div>
</div>
