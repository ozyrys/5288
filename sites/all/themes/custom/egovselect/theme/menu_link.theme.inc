<?php

/**
 * @file
 * menu_link.theme.inc
 * 
 * Functions to enable the processing and display of menu link.
 */

/**
 * Returns HTML for a form.
 * (removes the <div> wrapper inside the form)
 *
 * @param $variables
 *   An associative array
 * 
 * @see theme_menu_link()
 */

function egovselect_menu_link(&$variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if (!empty($element['#below'])) {
    // We don't want to render menu position links.
    foreach ($element['#below'] as $mlid => $menu_item) {
      if ($menu_item['#original_link']['module'] == 'menu_position') {
        unset($element['#below'][$mlid]);
      }
    }

    $sub_menu = drupal_render($element['#below']);
  }

  // Add id to menu link after hash sign for main menu links. In order to create anchored links on "One front page design".
  if(is_string($element['#theme']) && strpos($element['#theme'], 'main_') !== FALSE && strpos($element['#theme'], '_menu') !== FALSE && !empty($element['#localized_options']['attributes']) && is_array($element['#localized_options']['attributes']) && array_key_exists('id',$element['#localized_options']['attributes'])) {
    $element['#localized_options']['fragment'] = $element['#localized_options']['attributes']['id'];
    $element['#localized_options']['attributes']['class'][] = $element['#localized_options']['attributes']['id'];
    unset($element['#localized_options']['attributes']['id']);
  }

  // Display parent title on menu link before the proper text, if it's particular menu block.
  $link_prefix = $link_suffix = '';
  if (!empty($element['#theme'][0]) && !empty($element['#parent']) &&
      (strpos($element['#theme'][0], 'menu_block__3') !== FALSE || strpos($element['#theme'][0], 'menu_block__4') !== FALSE
       || strpos($element['#theme'][0], 'menu_block__2') !== FALSE || strpos($element['#theme'][0], 'menu_block__1') !== FALSE)
  ) {
    $link_prefix = '<span class="link-prefix">'.$element['#parent']['link_title'].'</span>';
    /*if (!empty($element['#localized_options']['attributes']['title'])) {
      $link_suffix = '<span class="link-suffix">'.$element['#localized_options']['attributes']['title'].'</span>';
    }*/
  }

  $element['#localized_options']['html'] = TRUE;
  $output = l('<span class="link-texts">' . $link_prefix . '<span class="link-title">' . $element['#title'] . '</span>' . $link_suffix . '</span>', $element['#href'], $element['#localized_options']);

  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}
