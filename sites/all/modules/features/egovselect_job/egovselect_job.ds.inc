<?php
/**
 * @file
 * egovselect_job.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function egovselect_job_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|job|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'job';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'field_company_profile' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_criteria' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_salary_benefits' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_contact_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
  );
  $export['node|job|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|job|page_list';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'job';
  $ds_fieldsetting->view_mode = 'page_list';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'field_description' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|job|page_list'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|job|search_index';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'job';
  $ds_fieldsetting->view_mode = 'search_index';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|job|search_index'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|job|search_result';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'job';
  $ds_fieldsetting->view_mode = 'search_result';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'search_snippet' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'search_info' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|job|search_result'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|job|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'job';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(),
      ),
    ),
  );
  $export['node|job|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function egovselect_job_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|job|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'job';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_textfield',
        1 => 'field_url',
      ),
    ),
    'fields' => array(
      'field_textfield' => 'ds_content',
      'field_url' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
    'hide_page_title' => '0',
    'page_option_title' => '',
    'hide_sidebars' => 0,
  );
  $export['node|job|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|job|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'job';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'language',
        1 => 'title',
        2 => 'field_category',
        3 => 'field_company_profile',
        4 => 'field_description',
        5 => 'field_criteria',
        6 => 'field_salary_benefits',
        7 => 'field_contact_name',
        8 => 'field_url',
        9 => 'xmlsitemap',
        10 => 'redirect',
        11 => 'path',
        12 => 'metatags',
      ),
      'hidden' => array(
        13 => 'field_jobid',
        14 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'language' => 'ds_content',
      'title' => 'ds_content',
      'field_category' => 'ds_content',
      'field_company_profile' => 'ds_content',
      'field_description' => 'ds_content',
      'field_criteria' => 'ds_content',
      'field_salary_benefits' => 'ds_content',
      'field_contact_name' => 'ds_content',
      'field_url' => 'ds_content',
      'xmlsitemap' => 'ds_content',
      'redirect' => 'ds_content',
      'path' => 'ds_content',
      'metatags' => 'ds_content',
      'field_jobid' => 'hidden',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|job|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|job|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'job';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_description',
        1 => 'field_criteria',
        2 => 'field_salary_benefits',
        3 => 'field_company_profile',
        4 => 'field_contact_name',
        5 => 'field_url',
      ),
    ),
    'fields' => array(
      'field_description' => 'ds_content',
      'field_criteria' => 'ds_content',
      'field_salary_benefits' => 'ds_content',
      'field_company_profile' => 'ds_content',
      'field_contact_name' => 'ds_content',
      'field_url' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
    'hide_page_title' => '0',
    'page_option_title' => '',
    'hide_sidebars' => 0,
  );
  $export['node|job|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|job|page_list';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'job';
  $ds_layout->view_mode = 'page_list';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_description',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_description' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
    'hide_page_title' => '0',
    'page_option_title' => '',
    'hide_sidebars' => 0,
  );
  $export['node|job|page_list'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|job|search_index';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'job';
  $ds_layout->view_mode = 'search_index';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_url',
        2 => 'field_category',
        3 => 'field_description',
        4 => 'field_criteria',
        5 => 'field_salary_benefits',
        6 => 'field_contact_name',
        7 => 'field_company_profile',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_url' => 'ds_content',
      'field_category' => 'ds_content',
      'field_description' => 'ds_content',
      'field_criteria' => 'ds_content',
      'field_salary_benefits' => 'ds_content',
      'field_contact_name' => 'ds_content',
      'field_company_profile' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
    'hide_page_title' => '0',
    'page_option_title' => '',
    'hide_sidebars' => 0,
  );
  $export['node|job|search_index'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|job|search_result';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'job';
  $ds_layout->view_mode = 'search_result';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_url',
        2 => 'field_salary_benefits',
        3 => 'field_criteria',
        4 => 'field_description',
        5 => 'field_company_profile',
        6 => 'field_category',
        7 => 'field_contact_name',
        8 => 'search_snippet',
        9 => 'search_info',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_url' => 'ds_content',
      'field_salary_benefits' => 'ds_content',
      'field_criteria' => 'ds_content',
      'field_description' => 'ds_content',
      'field_company_profile' => 'ds_content',
      'field_category' => 'ds_content',
      'field_contact_name' => 'ds_content',
      'search_snippet' => 'ds_content',
      'search_info' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
    'hide_page_title' => '0',
    'page_option_title' => '',
    'hide_sidebars' => 0,
  );
  $export['node|job|search_result'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|job|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'job';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_url',
        1 => 'title',
        2 => 'field_description',
      ),
    ),
    'fields' => array(
      'field_url' => 'ds_content',
      'title' => 'ds_content',
      'field_description' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
    'hide_page_title' => '0',
    'page_option_title' => '',
    'hide_sidebars' => 0,
  );
  $export['node|job|teaser'] = $ds_layout;

  return $export;
}
