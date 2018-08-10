<?php

/**
 * Implement drush command
 * @return array
 */
function store_features_drush_command() {
  $items = array();

  $items['store-feature'] = array(
    'description' => 'Store Feature',
    'aliases' => ['sf'],
    'options' => array(
      'soft' => 'Do not disable/uninstall feature.',
      'all' => 'Unlink all custom features',
    ),
    'callback' => 'store_features_drush_store_features',
  );
   return $items;
}


/**
 *
 */
function store_features_drush_store_features() {
  $features = func_get_args();
  $soft = drush_get_option('soft');

  $all = drush_get_option('all');
  
  // Override feature parameter and replace with list of all enabled features.
  if($all){
    $features = [];
    $all_features = features_get_features(null,null); 
      foreach ($all_features as $feature) {
        if($feature->status){
          array_push($features, $feature->name);
        }
      }
    if (empty($features)) {
      drush_log('No features to store.', 'error');
      drush_print('aborting ...');
      return 1;
    }
  }
  
  if (empty($features)) {
    drush_log('You didn\'t specified any feature.', 'error');
    drush_print('Aborting ...');
    return 1;
  }

  if (drush_confirm('Are you sure you want to revert and store the following features: ' . implode(', ',$features))) {
    store_features_persist_features_by_names($features, $soft, $all);

  }
  else {
    drush_print('Aborting ...');
  }

  return 1;
}