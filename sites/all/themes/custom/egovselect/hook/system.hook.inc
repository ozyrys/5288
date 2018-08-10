<?php

/**
 * @file
 * system.hook.inc
 * 
 * Hooks provided by the Current theme.
 */

/**
 * Alter Drupal Core CSS files before they are output on the page.
 *
 * @param $css
 *   An array of all CSS items (files and inline CSS) being requested on the page.
 *
 * @see drupal_add_css()
 * @see drupal_get_css()
 *
 * Implements hook_css_alter().
 */
function egovselect_css_alter(&$css) {
  // Stylesheets thats gonna be stripped.
  $css_kill_list = array(
    drupal_get_path('module', 'system') . '/system.base.css',
    drupal_get_path('module', 'system') . '/system.menus.css',
    drupal_get_path('module', 'system') . '/system.theme.css',
  );

  // Grab the stylesheets and run through them.
  foreach ($css as $file => $value) {
    // Grab the strip list and do that on each file.
    foreach ($css_kill_list as $key => $css_file_must_die) {
      if (strpos($css_file_must_die, $file) !== FALSE) {
        unset($css[$file]);
      }
    }
  }
}

/**
 * 
 * Implements hook_js_alter().
 */
function egovselect_js_alter(&$data) { 
  // Scripts that gonna be stripped.
  unset($data[drupal_get_path('theme', 'nerra').'/assets/scripts/script.js']);
}

/**
 * Implements hook_form_search_block_form_alter().
 */
function egovselect_form_search_block_form_alter(&$form, &$form_state, $form_id) {
  // Change placeholder in search textbox input.
  $form['search_block_form']['#attributes']['placeholder'] = t('search on website');

  // @accessibilityChanges
  // Add aria-label .
  $form['search_block_form']['#attributes']['aria-label'] = t('Search input');
  $form['submit']['#attributes']['aria-label'] = $form['submit']['#value'];
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function egovselect_form_views_exposed_form_alter(&$form, &$form_state, $form_id) {
  // Set placeholder for search input.
  if ($form["#id"] == 'views-exposed-form-search-p-search' || $form["#id"] == 'views-exposed-form-solr-pages-solr-search') {
    $form['keyword']['#attributes']['placeholder'] = t('search on website');

    // @accessibilityChanges
    // Add aria-label .
    $form['keyword']['#attributes']['aria-label'] = t('Search input');
    $form['submit']['#attributes']['aria-label'] = $form['submit']['#value'];
  }
}