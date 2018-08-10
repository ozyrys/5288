<?php

/**
 * @param $form
 * @param $form_state
 * @return array
 */
function store_features_admin_features_form($form, &$form_state) {
  $form = array();

  $form['intro'] = array(
    '#theme' => 'item_list',
    '#items' => array(
      t('Contexts'),
      t('Display suite Custom Fields'),
      t('Display suite Field settings'),
      t('Display suite Layout settings'),
      t('Display suite Views mode'),
      t('Field Groups'),
      t('Images styles'),
      t('Views views'),
      t('Rules'),
      t('Facets (facetapi)'),
    ),
    '#title' => t('Content that will be store into database:'),
    '#type' => 'ul',
    '#attributes' => array(),
  );

  $features = store_features_get_custom_features();

  $form['features'] = array(
    '#title' => t('Select features you want to disable and store in DB.'),
    '#type' => 'checkboxes',
    '#multiple' => TRUE,
    '#options' => array(),
    '#description' => t('Features required by modules are hidden') . '<br/>' . '<strong>Warning: </strong>' . t('Features will be reverted'),
  );

  $form['soft'] = array(
    '#title' => t('Use soft store'),
    '#description' => t('Soft Store does not disable/uninstall features'),
  );

  foreach ($features as $feature_name => $feature) {
    $feature_info = $feature->info;
    $feature_extra_info = features_get_info('feature', $feature_name);


    $required = FALSE;
    if (!empty($feature_extra_info->required_by)) {
      $modules = _store_features_get_enabled_modules();

      foreach ($feature_extra_info->required_by as $required_by => $unused) {
        // if module is enabled, you can't disable the feature
        if (array_key_exists($required_by, $modules)) {
          $required = TRUE;
          break;
        }
      }
    }

    if (!$required) {
      $form['features']['#options'][$feature_name] = $feature_info['name'] . ' (' . $feature_info['version'] . ')';
    }
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Store and Disable features',
  );

  return $form;
}

/**
 * @param $form
 * @param $form_state
 */
function store_features_admin_features_form_submit($form, $form_state) {
  $values = $form_state['values'];

  $features_names = array();
  foreach ($values['features'] as $feature_name => $checked) {
    if ($checked !== 0) {
      $features_names[] = $feature_name;
    }
  }

  module_load_include('export.inc', 'features');

  return store_features_persist_features_by_names($features_names, $values['soft']);
}