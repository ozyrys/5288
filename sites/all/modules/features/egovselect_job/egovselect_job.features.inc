<?php
/**
 * @file
 * egovselect_job.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function egovselect_job_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function egovselect_job_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_menu_position_default_menu_positions().
 */
function egovselect_job_menu_position_default_menu_positions() {
  $items = array(
    'jobs_fr' => array(
      'admin_title' => 'Jobs FR',
      'enabled' => 1,
      'conditions' => 'a:2:{s:12:"content_type";a:1:{s:12:"content_type";a:1:{s:3:"job";s:3:"job";}}s:8:"language";a:1:{s:8:"language";s:2:"fr";}}',
      'menu_name' => 'main-french-menu',
      'plid' => 608,
      'mlid' => 904,
      'weight' => 0,
      'machine_name' => 'jobs_fr',
    ),
    'jobs_nl' => array(
      'admin_title' => 'Jobs NL',
      'enabled' => 1,
      'conditions' => 'a:2:{s:12:"content_type";a:1:{s:12:"content_type";a:1:{s:3:"job";s:3:"job";}}s:8:"language";a:1:{s:8:"language";s:2:"nl";}}',
      'menu_name' => 'main-dutch-menu',
      'plid' => 594,
      'mlid' => 905,
      'weight' => 0,
      'machine_name' => 'jobs_nl',
    ),
  );
  return $items;
}

/**
 * Implements hook_node_info().
 */
function egovselect_job_node_info() {
  $items = array(
    'job' => array(
      'name' => t('Job'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
