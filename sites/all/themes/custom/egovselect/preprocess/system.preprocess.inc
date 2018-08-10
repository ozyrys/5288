<?php

/**
 * @file
 * system.preprocess.inc
 *
 * All preprocess functions related to "system" placeholder live in this file.
 */

/**
 * Preprocesses variables for default html templates.
 *
 * @param array $vars
 *   An associative array of variables to merge with defaults.
 * 
 * @see template_preprocess_html()
 * @see nerra_preprocess_html()
 * @see html.tpl.php
 */

function egovselect_preprocess_html(&$vars) {
  // Remove br tags from head_title
  $vars['head_title'] = str_replace(array('<br/>','<br>','<br />'), array('','',''), $vars['head_title']);
  // This will add the ".collapsed-main-menu" class which is used to collapse
  // the "Main" navigation menu.
  $vars['classes_array'][] = drupal_html_class('collapsed-main-menu');
  // Add styles to language selection page
  if (arg(0) == 'language_selection') {
    drupal_add_css(drupal_get_path('theme', 'egovselect') . '/assets/styles/css/components/language-selection-page.css');
  }
  // Include "Pace" library for progress bar loading JavaScript.
  // and "OnePage" JS
  if (drupal_is_front_page()) {
    drupal_add_css(drupal_get_path('theme', 'egovselect') . '/assets/styles/pace.css');
    drupal_add_js(drupal_get_path('theme', 'egovselect') . '/assets/scripts/pace.min.js');
    drupal_add_js(drupal_get_path('theme', 'egovselect') . '/assets/scripts/onepage.min.js');
  }
  // Load javascript not for front.
  else {
    drupal_add_js(drupal_get_path('theme', 'egovselect') . '/assets/scripts/not-front.js');
  }

  // Accessibility
  _nerra_a11y_html_attributes($vars);
}

/**
 * Preprocess variables for page.tpl.php.
 */
function egovselect_preprocess_page(&$variables) {
  if (isset($variables['node'])) {
    // If the node type is "blog" the template suggestion will be "page--blog.tpl.php".
    $variables['theme_hook_suggestions'][] = 'page__'. str_replace('_', '--', $variables['node']->type);
  }

  // Apply Grid classes
  if (!empty($variables['page']['sidebar_first']) && !empty($variables['page']['sidebar_second'])) {
    $variables['class_left'] = 'col-md-3 col-sm-12 col-xs-12 col-xxs-12';
    $variables['class_right'] =  'col-md-3 col-sm-12 col-xs-12 col-xxs-12';
    $variables['class_content'] = 'col-md-6 col-sm-12 col-xs-12 col-xxs-12';
  }
  elseif (!empty($variables['page']['sidebar_first'])) {
    $variables['class_left'] = 'col-md-3 col-sm-12 col-xs-12 col-xxs-12';
    $variables['class_content'] = 'col-md-' . (12 - substr($variables['class_left'], 7, strlen($variables['class_left']))).' col-sm-12 col-xs-12 col-xxs-12';
  }
  elseif (!empty($variables['page']['sidebar_second'])) {
    $variables['class_right'] = 'col-md-4 col-sm-12 col-xs-12 col-xxs-12';
    $variables['class_content'] = 'col-md-' . (12 - substr($variables['class_right'], 7, strlen($variables['class_right']))).' col-sm-12 col-xs-12 col-xxs-12';
  }
  else {
    $variables['class_content'] = 'col-md-12 col-sm-12 col-xs-12 col-xxs-12';
  }

  // Accessibility
  _nerra_a11y_breadcrumb_aria_label($variables);
}

// Add parent to menu link object in order to gat the parent label on its child.
function egovselect_preprocess_menu_link(&$variables) {
  if (!empty($variables['element']['#original_link']['plid']) && $parent = menu_link_load($variables['element']['#original_link']['plid'])) {
    $variables['element']['#parent'] = $parent;
  }
}

/**
 * Implements hook_preprocess_HOOK() for theme_file_icon().
 *
 */
function egovselect_preprocess_file_icon(&$variables) {
  // Accessibility
  _nerra_a11y_file_icon($variables);
}