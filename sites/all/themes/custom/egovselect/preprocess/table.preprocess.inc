<?php
/**
 * @file
 * Stub file for "table" theme hook [pre]process functions.
 */

/**
 * Pre-processes variables for the "table" theme hook.
 *
 * See theme function for list of available variables.
 *
 * @see bootstrap_table()
 * @see theme_table()
 *
 * @ingroup theme_preprocess
 */
function egovselect_preprocess_table(&$variables) {
  // Make tables responsive.
  if (!isset($variables['attributes']['class'])) {
    $variables['attributes']['class'] = array();
  }
  // Convert classes to an array.
  elseif (isset($variables['attributes']['class']) && is_string($variables['attributes']['class'])) {
    $variables['attributes']['class'] = explode(' ', $variables['attributes']['class']);
  }
  $variables['attributes']['class'][] = 'table';
  $variables['attributes']['class'][] = 'table-hover';
  $variables['attributes']['class'][] = 'table-striped';
}
