<?php
/**
 * @file
 * egovselect_field_bases.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function egovselect_field_bases_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_accordion_item_01|node|job|full';
  $field_group->group_name = 'group_accordion_item_01';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'job';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Language',
    'weight' => '14',
    'children' => array(
      0 => 'language',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Language',
      'instance_settings' => array(
        'classes' => 'group-accordion-item-01 field-group-accordion-item',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_accordion_item_01|node|job|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_accordion_item_01|node|page|full';
  $field_group->group_name = 'group_accordion_item_01';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Submitted by',
    'weight' => '12',
    'children' => array(
      0 => 'submitted_by',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Submitted by',
      'instance_settings' => array(
        'classes' => 'group-accordion-item-01 field-group-accordion-item',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_accordion_item_01|node|page|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_accordion_item_02|node|job|full';
  $field_group->group_name = 'group_accordion_item_02';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'job';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Post date',
    'weight' => '15',
    'children' => array(
      0 => 'post_date',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-accordion-item-02 field-group-accordion-item',
      ),
    ),
  );
  $field_groups['group_accordion_item_02|node|job|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_accordion_item_02|node|page|full';
  $field_group->group_name = 'group_accordion_item_02';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Last modified',
    'weight' => '13',
    'children' => array(
      0 => 'changed_date',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-accordion-item-02 field-group-accordion-item',
      ),
    ),
  );
  $field_groups['group_accordion_item_02|node|page|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_accordion_item_03|node|job|full';
  $field_group->group_name = 'group_accordion_item_03';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'job';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Author',
    'weight' => '16',
    'children' => array(
      0 => 'author',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-accordion-item-03 field-group-accordion-item',
      ),
    ),
  );
  $field_groups['group_accordion_item_03|node|job|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_accordion|node|job|full';
  $field_group->group_name = 'group_accordion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'job';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_horizontal_tabs';
  $field_group->data = array(
    'label' => 'Accordion',
    'weight' => '13',
    'children' => array(
      0 => 'group_accordion_item_01',
      1 => 'group_accordion_item_02',
      2 => 'group_accordion_item_03',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-accordion field-group-accordion',
        'effect' => 'bounceslide',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_accordion|node|job|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_accordion|node|page|full';
  $field_group->group_name = 'group_accordion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Accordion',
    'weight' => '3',
    'children' => array(
      0 => 'group_accordion_item_01',
      1 => 'group_accordion_item_02',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-accordion field-group-accordion',
        'effect' => 'bounceslide',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_accordion|node|page|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_horizontal_tab_01|node|job|full';
  $field_group->group_name = 'group_horizontal_tab_01';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'job';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_horizontal_tabs';
  $field_group->data = array(
    'label' => 'Submitted by',
    'weight' => '11',
    'children' => array(
      0 => 'submitted_by',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-horizontal-tab-01 field-group-htab',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_horizontal_tab_01|node|job|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_horizontal_tab_01|node|page|full';
  $field_group->group_name = 'group_horizontal_tab_01';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_horizontal_tabs';
  $field_group->data = array(
    'label' => 'Author',
    'weight' => '13',
    'children' => array(
      0 => 'author',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-horizontal-tab-01 field-group-htab',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_horizontal_tab_01|node|page|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_horizontal_tab_02|node|job|full';
  $field_group->group_name = 'group_horizontal_tab_02';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'job';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_horizontal_tabs';
  $field_group->data = array(
    'label' => 'Last modified',
    'weight' => '12',
    'children' => array(
      0 => 'changed_date',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-horizontal-tab-02 field-group-htabs',
        'id' => '',
        'description' => '',
      ),
    ),
  );
  $field_groups['group_horizontal_tab_02|node|job|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_horizontal_tab_02|node|page|full';
  $field_group->group_name = 'group_horizontal_tab_02';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_horizontal_tabs';
  $field_group->data = array(
    'label' => 'Post date',
    'weight' => '14',
    'children' => array(
      0 => 'post_date',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-horizontal-tab-02 field-group-htab',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_horizontal_tab_02|node|page|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_horizontal_tabs|node|job|full';
  $field_group->group_name = 'group_horizontal_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'job';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Horizontal tabs',
    'weight' => '2',
    'children' => array(
      0 => 'group_horizontal_tab_01',
      1 => 'group_horizontal_tab_02',
      2 => 'group_accordion',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-horizontal-tabs field-group-htabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_horizontal_tabs|node|job|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_horizontal_tabs|node|page|full';
  $field_group->group_name = 'group_horizontal_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Horizontal tabs',
    'weight' => '4',
    'children' => array(
      0 => 'group_horizontal_tab_01',
      1 => 'group_horizontal_tab_02',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-horizontal-tabs field-group-tabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_horizontal_tabs|node|page|full'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Accordion');
  t('Author');
  t('Horizontal tabs');
  t('Language');
  t('Last modified');
  t('Post date');
  t('Submitted by');

  return $field_groups;
}
