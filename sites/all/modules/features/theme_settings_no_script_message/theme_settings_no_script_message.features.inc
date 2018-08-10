<?php
/**
 * @file
 * theme_settings_no_script_message.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function theme_settings_no_script_message_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
