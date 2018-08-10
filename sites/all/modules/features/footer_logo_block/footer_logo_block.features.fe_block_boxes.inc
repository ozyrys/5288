<?php
/**
 * @file
 * footer_logo_block.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function footer_logo_block_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Logo';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'footer_logo_block';
  $fe_block_boxes->body = '<p><img alt="" src="/sites/default/files/content/logo-footer.png" srcset="/sites/default/files/content/logo-footer.png 1x, /sites/default/files/content/logo-footer@2x.png 2x" style="height:62px; width:182px" /></p>
';

  $export['footer_logo_block'] = $fe_block_boxes;

  return $export;
}
