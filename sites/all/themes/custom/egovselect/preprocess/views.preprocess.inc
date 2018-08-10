<?php

/**
 * @file
 * views.preprocess.inc
 *
 * All preprocess functions related to "views" placeholder live in this file.
 */

/**
 * Preprocesses variables for main view template.
 *
 * @param array $vars
 *   An associative array of variables to merge with defaults.
 *
 * @see views-view.tpl.php
 *
 * Implements template_preprocess_views_view().
 */
function egovselect_preprocess_views_view(&$vars) {
  $view = $vars['view'];

  // Custom logic to render content within Drupal from a view
  // providing the entity id's from apache solr index.
  if ($view->name === 'solr_pages' && $view->current_display == 'page_1') {
    if (!empty($view->result)) {
      $entity_type = 'node';
      $entity_ids = array();
      foreach ($view->result as $result) {
        if (isset($result->entity_id)) {
          $entity_ids[] = $result->entity_id;
        }
      }
      if (!empty($entity_ids)) {
        $entities = entity_load($entity_type, $entity_ids);
        $view_mode = ($view->current_display === 'solr_search') ? 'search_result' : 'page_list';
        $rows = entity_view($entity_type, $entities, $view_mode);
        if (isset($rows['node'])) {
          $items = array();
          foreach ($rows['node'] as $id => $row) {
            if (is_numeric($id) && is_array($row)) {
              $items[] = drupal_render($row);
            }
          }
          $vars['rows'] = theme('item_list__views__solr_pages', array('items' => $items, 'title' => '', 'type' => 'ol'));
        }
      }
    }
  }
}