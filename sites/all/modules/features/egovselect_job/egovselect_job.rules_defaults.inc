<?php
/**
 * @file
 * egovselect_job.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function egovselect_job_default_rules_configuration() {
  $items = array();
  $items['rules_create_additional_alias_for_jobs'] = entity_import('rules_config', '{ "rules_create_additional_alias_for_jobs" : {
      "LABEL" : "Create additional alias for jobs",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "path" ],
      "ON" : { "node_insert--job" : { "bundle" : "job" } },
      "DO" : [
        { "node_path_alias" : { "node" : [ "node" ], "alias" : "job\\/[node:field-jobid]" } }
      ]
    }
  }');
  return $items;
}
