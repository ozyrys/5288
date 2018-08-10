<?php

/**
 * @file
 * ds_field.preprocess.inc
 *
 * All preprocess functions related to "Display suite field" placeholder live in this file.
 */
 
 /**
 * Preprocess variables for field.tpl.php.
 */
function egovselect_preprocess_field(&$variables) {

  if (!empty($variables['element']['#field_name'])) {
    // Fix URL label - It's not possible to set the URL text as field label - this snipped allows that.
    if ($variables['element']['#field_name'] == 'field_url' && !empty($variables['element']['#view_mode']) && !empty($variables['items'][0]['#field']['label'])) {
      $variables['items'][0]['#field']['label'] = html_entity_decode($variables['label'], ENT_QUOTES);

      // Static title is not translatable, so we use following fix.
      if (!empty($variables['element']['#object']->type) && $variables['element']['#object']->type == 'job') {
        $variables['items'][0]['#element']['title'] = t('Apply');
      }
    }
  }

  // Process image field through accessibility helper function.
  if ($variables['element']['#field_type'] == 'image') {
    _nerra_a11y_field_type_image($vars);
  }
}
