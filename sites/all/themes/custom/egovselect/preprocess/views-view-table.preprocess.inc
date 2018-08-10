<?php
/**
 * @file
 * Stub file for "views_view_table" theme hook [pre]process functions.
 */

/**
 * Pre-processes variables for the "views_view_table" theme hook.
 *
 * See template for list of available variables.
 *
 * @see views-view-table.tpl.php
 *
 * @ingroup theme_preprocess
 */
function egovselect_preprocess_views_view_table(&$variables) {
   // Make tables responsive.
  if (!isset($variables['classes_array'])) {
    $variables['classes_array'] = array();
  }
  // Convert classes to an array.
  elseif (isset($variables['classes_array']) && is_string($variables['classes_array'])) {
    $variables['classes_array'] = explode(' ', $variables['classes_array']);
  }
  $variables['classes_array'][] = 'table';
  $variables['classes_array'][] = 'table-hover';
  $variables['classes_array'][] = 'table-striped';

  // On Employee Documents view table change one download field to file
  // description, as it was not possible to set from view settings page.
  if ($variables['view']->name == 'employee_documents') {
    if (!empty($variables['rows'][0]['field_file'])) {
      foreach ($variables['rows'] as $key => $value) {
        if (!empty($variables['view']->result[$key]->field_field_file[0]['raw']['description'])) {
          $variables['rows'][$key]['field_file'] = $variables['view']->result[$key]->field_field_file[0]['raw']['description'];
        }
      }
    }
  }
}
