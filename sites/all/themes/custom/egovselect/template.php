<?php

/**
 * @file
 * template.php
 *
 * This theme comes with a neat solution for keeping this file as clean as possible
 * while the code grows.
 *
 * Any custom [pre]process, theme and hook functions can (rather than directly
 * in this template.php) be placed in its specific folder in a file named as such:
 *
 * [THEMENAME]_[pre]process_html() = system.[pre]process.inc
 * [THEMENAME]_[pre]process_page() = system.[pre]process.inc
 * [THEMENAME]_[pre]process_block() = block.[pre]process.inc
 * [THEMENAME]_[pre]process_node() = node.[pre]process.inc
 * [THEMENAME]_[pre]process_field() = field.[pre]process.inc
 * [THEMENAME]_menu_tree() = menu.theme.inc
 * [THEMENAME]_block_info_alter = block.hook.inc
 * [THEMENAME]_form_alter() = system.hook.inc
 * etc.
 */

/**
 * The following function automatically loads (includes and evaluates) any custom
 * [pre]process, theme and hook functions.
 */
function _theme_autoload() {
  // Include accessibility stuff.
  require_once drupal_get_path('theme', 'nerra').'/accessibility/includes/accessibility.inc';

  $directories = array(
      __DIR__ . '/hook',
      __DIR__ . '/preprocess',
      __DIR__ . '/process',
      __DIR__ . '/theme',
  );
  
  foreach ($directories as $dir) {
    $files = array();
    if (is_dir($dir)) {
      $files = scandir($dir);
      _theme_files_include($dir, $files);
    }
  } 
}

/**
 * Includes (require_once PHP function) and evaluates the specified files
 * containing template functions.
 *
 * @param String $dir
 *   The path to the folder which contains template files to include.
 * @param Array $files
 *   An array containing the name of the template files stored in their specified folder.
 */
function _theme_files_include($dir, $files) {
  if (!empty($files)) {
    foreach ($files as $filename) {
      if (is_dir($dir) && strpos($filename, '.inc') !== false) {
        require_once $dir . '/' . $filename;
      }
    }
  }
}

/**
 * Call the function which loads [pre]process, theme and hook functions.
 */
_theme_autoload();