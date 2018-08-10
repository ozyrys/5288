<?php
/**
 * @file
 * footer_logo_block.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function footer_logo_block_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-footer_logo_block'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'machine_name' => 'footer_logo_block',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'maintenance' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'maintenance',
        'weight' => 0,
      ),
      'nerra' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nerra',
        'weight' => 0,
      ),
      'ofed_cms_adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'ofed_cms_adminimal',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}
