<?php

/**
 * @file
 * facetapi.theme.inc
 * 
 * Facet API theme functions.
 */

/**
 * Returns HTML for the facet title, usually the title of the block.
 *
 * @see facetapi/current_search.theme.inc
 */
function egovselect_facetapi_title($variables) {
  $title = $variables['title'];

  // Field title seems not to be translated by facetapi module, so we translate
  // it from here.
  // The following issue may be related and is commited to dev but not released
  // yet:
  // https://www.drupal.org/node/1665164#comment-11723257
  if ($variables['facet']['#facet']['name'] == 'im_field_category') {
    $title = t('Category');
  }

  return t('Filter by @title:', array('@title' => $title));
}
