<?php

/**
 * @file
 * form.theme.inc
 * 
 * Functions to enable the processing and display of HTML forms.
 */

/**
 * Returns HTML for a form.
 * (removes the inner <div> wrapper inside the form)
 *
 * @param $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *     Properties used: #action, #method, #attributes, #children
 * 
 * @see theme_form()
 */
function egovselect_form($variables) {
  $element = $variables['element'];
  if (isset($element['#action'])) {
    $element['#attributes']['action'] = drupal_strip_dangerous_protocols($element['#action']);
  }
  element_set_attributes($element, array('method', 'id'));
  if (empty($element['#attributes']['accept-charset'])) {
    $element['#attributes']['accept-charset'] = "UTF-8";
  }
  // All <input> are already included in a <div> wrapper.
  return '<form' . drupal_attributes($element['#attributes']) . '>' . $element['#children'] . '</form>';
}
