<?php
/**
 * Override theme for form required fields.
 *
 * Add aria-labels for required fields to improve accessibility.
 *
 */
function MYTHEME_form_required_marker($variables) {
  // This is also used in the installer, pre-database setup.
  $t = get_t();
  $attributes = array(
    'class' => 'form-required',
    'title' => $t('This field is required.'),
    'aria-label' => $t('This field is required.'),
  );
  return '<span' . drupal_attributes($attributes) . '>*</span>';
}