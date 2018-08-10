<?php

/**
 * @file
 * block.preprocess.inc
 *
 * All preprocess functions related to "block" placeholder live in this file.
 */

/**
 * Preprocesses variables for default block templates.
 *
 * @param array $vars
 *   An associative array of variables to merge with defaults.
 * 
 * @see template_preprocess_block()
 * @see block.tpl.php
 * @see block--menu.tpl.php
 */
function egovselect_preprocess_block(&$vars) {

  // Accessibility
  _nerra_a11y_block($vars);
  // Accessibility - add aria labels for menus
  _nerra_a11y_block_menu_aria_labels($vars);

  $block = $vars['block'];
  // Add block description as a class name in order to style it regardless of
  // it's id as it could change after featured and imported.
  if ($block->module == 'block' && is_numeric($block->delta)) {
    $block_loaded = block_custom_block_get($block->delta);
    if (!empty($block_loaded['info'])) {
      $vars['classes_array'][] = 'block-' . str_replace(' ', '-', trim(strtolower($block_loaded['info'])));
    }
  }

  // Unset contextual links for language switcher as it's useless and cover
  // switcher itself, that change of language is impossible.
  if (!empty($block->delta) && $block->delta == 'admin_language_switcher') {
    if (!empty($vars['title_suffix']['contextual_links'])) {
      unset($vars['title_suffix']['contextual_links']);
    }

    // Here we change the language switcher links for jobs.
    if ($node = menu_get_object()) {
      if ($new_links = _egovselect_build_admin_language_switcher_links($node)) {
        $vars['content'] = $new_links;
      }
    }
  }
}

/**
 * Builds custom language switcher links for jobs, since they don't get a
 * translation set while imported.
 *
 * This solution was suggested by Bart Declercq by mail, although he suggested a
 * Javascript based solution initially.
 *
 * It contains a lot of code from admin_language_block_view() (admin_language
 * module).
 * It also assumes that:
 *  - a path alias has been created as follows: job/[JobId]
 *  - a translation exists for each language
 *
 * @param object $node
 * @return mixed
 *      HTML links in the same form as the original links (with only paths
 *      updated), or FALSE if not applicable.
 */
function _egovselect_build_admin_language_switcher_links($node) {
  if ($node->type != 'job') {
    return FALSE;
  }

  if (empty($node->field_jobid[LANGUAGE_NONE][0]['value'])) {
    return FALSE;
  }

  global $language;

  // Create the links and set our custom path alias.
  $languages = language_list('enabled');
  $admin_language = variable_get('admin_language_default', 'en');
  $links = array();
  foreach ($languages[1] as $language_item) {
    if ($language_item->language != $admin_language) {
      $language_item->language != $language->language ? $path = 'job/' . $node->field_jobid[LANGUAGE_NONE][0]['value'] : $path = $_GET['q'];
      $links[$language_item->language] = array(
        'href' => $path,
        'title' => $language_item->native,
        'language' => $language_item,
        'attributes' => array('class' => array('language-link')),
      );
    }
  }

  return theme('links', array('links' => $links));
}
