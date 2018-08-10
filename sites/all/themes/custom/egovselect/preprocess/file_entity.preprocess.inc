<?php

/**
 * @file
 * file_entity.preprocess.inc
 *
 * All preprocess functions related to "file_entity" placeholder live in this file.
 */

/**
 * Preprocesses variables for default file entity templates.
 *
 * @param array $vars
 *   An associative array of variables to merge with defaults.
 * 
 * @see template_preprocess_file_entity()
 * @see file_entity.tpl.php
 */
function egovselect_preprocess_file_entity(&$vars) {
  _nerra_a11y_field_file_entity_image($vars);
}
