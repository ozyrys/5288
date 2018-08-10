<?php

/**
 * @file
 * accessibility.inc
 *
 * @author Blue4You
 *
 * All accessibility helper functions to meet WCAG 2.0 AA requirements live in
 * this file.
 *
 * Based on Openfed version: 7.x-2.11
 */

/**
 * Preprocesses fields of image type.
 *
 * Operations:
 *   - ALT text: we use the following as alt text by priority:
 *     - ALT text
 *     - TITLE text
 *
 * @see template_preprocess_field()
 *
 * @param array $vars
 */
function _nerra_a11y_field_type_image(&$vars) {
  $element = $vars['element'];

  // Cycle through all items.
  foreach ($element['#items'] as $delta => $item) {
    // If alt property is defined, we skip this item.
    if (!empty($vars['items'][$delta]['#item']['alt'])) {
      continue;
    }

    // If field_file_image_alt_text field is defined, we skip this item.
    if (!empty($item['field_file_image_alt_text'][LANGUAGE_NONE][0]['value'])) {
      continue;
    }

    $alt_text = '';

    // If field_file_image_title_text field is defined, we use it as alt text.
    if (!empty($item['field_file_image_title_text'][LANGUAGE_NONE][0]['value'])) {
      $alt_text = $item['field_file_image_title_text'][LANGUAGE_NONE][0]['value'];
    }
    $vars['items'][$delta]['#item']['alt'] = $alt_text;
  }
}

/**
 * Preprocesses fields of image type in view.
 *
 * Operations:
 *   - ALT text: we use the following as alt text by priority:
 *     - ALT text
 *     - TITLE text
 *
 *
 * @param array $view
 * @param array $apply_to
 */
function _nerra_a11y_field_type_image_in_views(&$view, $apply_to) {
  foreach ($apply_to as $view_row) {
    if ($view->name == $view_row['view_name'] && !empty($view->result[0]->{$view_row['field_name']}[0]['rendered']['#item'])) {
      foreach ($view->result as $k => $row) {
        if (empty($view->result[$k]->{$view_row['field_name']}[0]['rendered']['#item']['alt'])) {
          if (!empty($view->result[$k]->{$view_row['field_name']}[0]['rendered']['#item']['title'])) {
            $view->result[$k]->{$view_row['field_name']}[0]['rendered']['#item']['alt'] = $view->result[$k]->{$view_row['field_name']}[0]['rendered']['#item']['title'];
          }
        }
      }
    }
  }
}

/**
 * Preprocesses file entity of image type.
 *
 * Operations:
 *   - ALT text: we use the following as alt text by priority:
 *     - ALT text
 *     - TITLE text
 *
 * @see template_preprocess_field()
 *
 * @param array $vars
 */
function _nerra_a11y_field_file_entity_image(&$vars) {
  if ($vars['type'] == 'image' && empty($vars["content"]['file']['#alt'])) {
    if (!empty($vars["content"]['file']['#title'])) {
      $vars["content"]['file']['#alt'] = $vars["content"]['file']['#title'];
    }
  }
}

/**
 * Preprocesses form inputs.
 *
 * Operations:
 *   - Add aria-label with the provided label as value
 *
 * @param array $form_element
 *    Must be an Form API element
 *
 * @param string $label
 *    Pre-translated label
 */
function _nerra_a11y_form_input(&$form_element, $label) {
  $form_element['#attributes']['aria-label'] = $label;
}

/**
 * Alters groups of webform form controls.
 *
 * Operations:
 *   - Wrap element with a fieldset with the element title as legend
 *   - Remove element title to avoid duplicate title and remove faulty "for"
 *     attribute of the label
 *
 * Remarks:
 *   - You should check CSS and JS files to see if they are using any of the
 *     label IDs that may be removed and also check if the design is impacted.
 *
 * @see hook_webform_component_render_alter()
 *
 * @param array $element
 *
 * @param array $component
 */
function _nerra_a11y_webform_form_controls_group(&$element, &$component) {
  // We only aim checkboxes and radio buttons.
  if (!in_array($element['#type'], array('checkboxes', 'radios'))) {
    return;
  }

  // Webform should belong to a node.
  if (empty($component['nid']) || !$node = node_load($component['nid'])) {
    return;
  }

  // We check if the current component is placed under a fieldset. If it's the
  //  case, we don't do anything.
  if (!empty($node->webform['components'][$component['pid']])) {
    $parent_component = $node->webform['components'][$component['pid']];
    if ($parent_component['type'] == 'fieldset') {
      return;
    }
  }

  // We wrap the component with a fieldset with component's title as legend and
  // remove the title to prevent default label to be printed out.
  $element['#prefix'] = '<fieldset><legend>' . $element['#title'] . '</legend>';
  $element['#suffix'] = '</fieldset>';
  $element['#title'] = '';
}

/**
 * Preprocesses file icons.
 *
 * Operations:
 *   - Make sure the icon has an alt text using file mime.
 *
 * @see template_preprocess_file_icon()
 *
 * @param array $vars
 */
function _nerra_a11y_file_icon(&$vars) {
  if (!empty($vars['alt'])) {
    return;
  }

  // Use mime type as alt text.
  $vars['alt'] = check_plain($vars['file']->filemime);
}

/**
 * Preprocesses blocks.
 *
 * Operations:
 *   - Make blocks more accessible - if block has a heading then wrap it
 *     with section instead of div element. Wrap it with nav element when
 *     block is generated by specific module.
 *
 * @see template_preprocess_block()
 *
 * @param array $vars
 */
function _nerra_a11y_block(&$vars) {
  // Create the $block object.
  $block = $vars['block'];

  $vars['title_attributes_array']['class'][] = 'block-title';

  // Print a <section> element wrapper if the block has a title.
  $vars['block_wrapper'] = 'div';
  if ($block->subject) {
    $vars['block_wrapper'] = 'section';
  }

  // Remove template suggestions
  $suggestions_to_remove = array('block__menu_block', 'block__menu','block__system__main_menu');
  foreach ($vars['theme_hook_suggestions'] as $k => $suggestion) {
    if (in_array($suggestion, $suggestions_to_remove)) {
      unset($vars['theme_hook_suggestions'][$k]);
    }
  }

  // Override specific "Block Wrappers" and add "Aria Roles" via attributes
  // and based on the module generating the block.
  switch ($block->module) {

    // Drupal "System" (Core) blocks.
    case 'system':
      switch ($block->delta) {
        case 'main':
          // Note: the "main" role goes in the page.tpl, not here.
          break;

        default:
          // Any other "System" block is a menu block.
          $vars['block_wrapper'] = 'nav';
          $vars['classes_array'][] = 'block-navigation';
          break;
      }
      break;

    // Navigation menu blocks.
    case 'menu':
    case 'menu_block':
    case 'facetapi':
    case 'blog':
    case 'book':
    case 'comment':
    case 'forum':
    case 'shortcut':
    case 'statistics':
      $vars['block_wrapper'] = 'nav';
      $vars['classes_array'][] = 'block-navigation';
      break;

    case 'locale':
      switch ($block->delta) {
        case 'language':
          $vars['block_wrapper'] = 'nav';
          $vars['classes_array'][] = 'block-navigation';
          break;
      }
      break;

    // Blocks as "Node".
    case 'node':
      switch ($block->delta) {
        case 'recent':
          $vars['block_wrapper'] = 'nav';
          $vars['classes_array'][] = 'block-navigation';
          break;
      }
      break;

    // Administration blocks.
    case 'admin':
      switch ($block->delta) {
        case 'menu':
          $vars['block_wrapper'] = 'nav';
          $vars['classes_array'][] = 'block-navigation';
          break;
      }
      break;
  }

  // Set the correct <heading> element according to the region.
  $vars['heading_tag'] = 'h2';
  if (strpos($block->region, 'row_') !== FALSE) {
    $vars['heading_tag'] = 'h2';
  }
  elseif (in_array($block->region, array(
    'sidebar_second',
    'footer'
  ))) {
    $vars['heading_tag'] = 'h2';
  }
  elseif ($block->region === 'content_bottom') {
    $vars['heading_tag'] = 'h2';
  }

  // Set the default classes for block modules and deltas.
  $module_class = drupal_html_class($block->module);
  $delta_class = drupal_html_class($block->delta);

  // Provide the "Block ID" (Delta) as a custom attribute on the block wrapper.
  $vars['attributes_array']['data-delta'] = $block->delta;

  $vars['classes_array'][] = 'block-' . $module_class . '-' . $delta_class;

  if ($block->module == 'menu') {
    if(strpos($block->delta, 'menu-toplinks') || strpos($block->delta, 'menu-top-links') !== FALSE){
      $vars['classes_array'][] = 'block-menu-toplinks';
    }elseif(preg_match("/^main-(.*)-menu$/", $block->delta)){
      $vars['classes_array'][] = 'block-menu-main';
    }elseif(strpos($block->delta, 'menu-footer') !== FALSE){
      $vars['classes_array'][] = 'block-menu-footer';
    }
  }elseif($block->module == 'system' && $block->delta == 'main-menu'){
    $vars['classes_array'][] = 'block-menu-main';
  }
}

/**
 * Preprocesses menu blocks.
 *
 * Operations:
 *   - Add aria labels for menus.
 *
 * @see template_preprocess_block()
 *
 * @param array $vars
 */
function _nerra_a11y_block_menu_aria_labels(&$vars) {
  // Create the $block object.
  $block = $vars['block'];
  global $language;
  if ($block->module == 'menu' || $block->module == 'menu_block' || ($block->module == 'system' && $block->delta == 'main-menu')) {
    switch ($language->language) {
      case 'en' :
        $vars['primary_menu_aria_label'] = 'Main navigation';
        $vars['secondary_menu_aria_label'] = 'Secondary navigation';
        $vars['sidebar_menu_aria_label'] = 'Sidebar navigation';
        $vars['footer_menu_aria_label'] = 'Footer navigation';
      break;
      case 'de' :
        $vars['primary_menu_aria_label'] = 'Hauptnavigation';
        $vars['secondary_menu_aria_label'] = 'Sekundärnavigation';
        $vars['sidebar_menu_aria_label'] = 'Sidebar-Navigation';
        $vars['footer_menu_aria_label'] = 'Navigation am Ende der Seite';
      break;
      case 'nl' :
        $vars['primary_menu_aria_label'] = 'Hoofdnavigatie';
        $vars['secondary_menu_aria_label'] = 'Secundaire navigatie';
        $vars['sidebar_menu_aria_label'] = 'Zijbalk navigatiee';
        $vars['footer_menu_aria_label'] = 'Footer navigatie';
      break;
      case 'fr' :
        $vars['primary_menu_aria_label'] = 'Navigation principale';
        $vars['secondary_menu_aria_label'] = 'Navigation secondaire';
        $vars['sidebar_menu_aria_label'] = 'Navigation dans la barre latérale';
        $vars['footer_menu_aria_label'] = 'Navigation en bas de page';
      break;
    }
    // Accessibility - add aria labels for menus
    if ($block->module == 'menu' || $block->module == 'menu_block') {
      switch ($block->region) {
        case 'header' :
          $vars['aria_label'] = $vars['secondary_menu_aria_label'];
        break;
        case 'navigation' :
          $vars['aria_label'] = $vars['primary_menu_aria_label'];
        break;
        case 'footer' :
          $vars['aria_label'] = $vars['footer_menu_aria_label'];
        break;
      }
      switch (true) {
        case stristr($block->region,'sidebar'):
          $vars['aria_label'] = $vars['sidebar_menu_aria_label'];
        break;
      }
      switch (true) {
        case stristr($block->region,'footer'):
          $vars['aria_label'] = $vars['footer_menu_aria_label'];
        break;
      }
    }
    elseif ($block->module == 'system' && $block->delta == 'main-menu'){
      $vars['aria_label'] = $vars['primary_menu_aria_label'];
    }
  }
}

/**
 * Preprocesses page.
 *
 * Operations:
 *   - Add aria labels for breadcrumb.
 *
 * @see template_preprocess_page()
 *
 * @param array $vars
 */
function _nerra_a11y_breadcrumb_aria_label(&$vars) {
  global $language;
  switch ($language->language) {
    case 'en':
      $vars['breadcrumb_aria_label'] = 'Breadcrumb';
      break;
    case 'fr':
      $vars['breadcrumb_aria_label'] = 'Fil d\'Ariane';
      break;
    case 'de':
      $vars['breadcrumb_aria_label'] = 'Krümelspur';
      break;
    case 'nl':
      $vars['breadcrumb_aria_label'] = 'Kruimelpad';
    break;
  }
}

/**
 * Preprocesses html.
 *
 * Operations:
 *   - Add language specific language html element attributes.
 *
 * @see template_preprocess_page()
 *
 * @param array $vars
 */
function _nerra_a11y_html_attributes(&$vars) {
  global $language;
  // HTML Attributes.
  // Use a proper attributes array for the html attributes.
  $vars['html_attributes_array'] = array();
  $vars['html_attributes_array']['lang'] = $language->language;
  $vars['html_attributes_array']['xml:lang'] = $language->language;
  $vars['html_attributes_array']['dir'] = $language->dir;
  // Flatten the HTML attributes array.
  $vars['html_attributes'] = drupal_attributes($vars['html_attributes_array']);
}