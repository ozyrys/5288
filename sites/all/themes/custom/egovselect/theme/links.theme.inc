<?php
/**
 * Override theme with links.
 *
 * Add aria-labels for language links to improve accessibility.
 *
 */
function egovselect_links($variables) {
  $array_values = array_values($variables['links']);
  if (!empty(array_shift($array_values)['language'])) {
    foreach ($variables['links'] as $k => $link) {
      if (!empty($link['language']->name)) {
        $variables['links'][$k]['attributes']['aria-label'] = 'Continue in '.$link['language']->name;
        if (!empty($link['language']->native)) {
          switch (strtolower($link['language']->native)) {
            case 'nl':
            case 'Nederlands':
              $variables['links'][$k]['attributes']['title'] = 'Nederlands';
              break;
            case 'fr':
            case 'Français':
              $variables['links'][$k]['attributes']['title'] = 'Français';
              break;
            case 'de':
            case 'Deutsch':
              $variables['links'][$k]['attributes']['title'] = 'Deutsch';
              break;
            case 'en':
            case 'English':
              $variables['links'][$k]['attributes']['title'] = 'English';
              break;
          }
        }
      }
    }
  }
  return theme_links($variables);
}