<?php
/**
 * Override theme select dropdown list.
 *
 * Add aria-labels to improve accessibility.
 *
 */
function MYTHEME_select($variables) {
    $element = $variables['element'];
    element_set_attributes($element, array(
        'id',
        'name',
        'size',
    ));
    _form_set_class($element, array(
        'form-select',
    ));
    if ( !empty($element['#title']) ) {
        $element['#attributes']['aria-label'] = $element['#title'];
    }
    return '<select' . drupal_attributes($element['#attributes']) . '>' . form_select_options($element) . '</select>';
}