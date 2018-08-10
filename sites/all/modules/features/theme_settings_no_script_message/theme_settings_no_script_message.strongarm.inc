<?php
/**
 * @file
 * theme_settings_no_script_message.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function theme_settings_no_script_message_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_default';
  $strongarm->value = 'egovselect';
  $export['theme_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_egovselect_settings';
  $strongarm->value = array(
    'toggle_logo' => 1,
    'toggle_name' => 1,
    'toggle_slogan' => 1,
    'toggle_node_user_picture' => 1,
    'toggle_comment_user_picture' => 1,
    'toggle_comment_user_verification' => 1,
    'toggle_favicon' => 1,
    'toggle_main_menu' => 1,
    'toggle_secondary_menu' => 1,
    'default_logo' => 1,
    'logo_path' => '',
    'logo_upload' => '',
    'default_favicon' => 1,
    'favicon_path' => '',
    'favicon_upload' => '',
    'nerra_breadcrumb_display' => 1,
    'nerra_breadcrumb_homepage' => 0,
    'nerra_breadcrumb_label' => 0,
    'nerra_copyright_display' => 1,
    'nerra_copyright_label' => '© Copyright 2016',
    'nerra_layout_display' => 'two_sidebar',
    'nerra_layout_width_left' => 'span-3',
    'nerra_layout_width_right' => 'span-3',
    'nerra_layout_width_center' => 'span-6',
    'nerra_form_checkbox' => 'cbx',
    'nerra_form_file' => 'fil',
    'nerra_form_password' => 'pas',
    'nerra_form_radio' => 'rdo',
    'nerra_form_select_single' => '',
    'nerra_form_select_multiple' => 'mul',
    'nerra_form_text' => 'txt',
    'nerra_form_date' => 'dat',
    'nerra_toggle_message' => 1,
    'nerra_toggle_tabs' => 1,
    'nerra_toggle_actions' => 1,
    'nerra_toggle_sponsor' => 1,
    'nerra_sponsor_label' => '',
    'nerra_browser_ie6' => 1,
    'nerra_browser_nojs' => 1,
    'nerra_browser_nojs_label' => 'Deze website vereist JavaScript om naar behoren te werken.',
    'nerra__active_tab' => 'edit-nerra-browser',
  );
  $export['theme_egovselect_settings'] = $strongarm;

  return $export;
}
