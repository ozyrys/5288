<?php

/**
 * @file
 * breadcrumb.theme.inc
 *
 * Functions to enable the processing and display of breadcrumb.
 */

/**
 * Add fragment after '#'
 *
 * @param $variables
 *   An associative array
 *
 * @see theme_breadcrumb()
 * @see path_breadcrumbs_breadcrumb
 */

function egovselect_breadcrumb($variables) {
  $breadcrumbs = $variables['breadcrumb'];
  if (!empty($breadcrumbs)) {

    // Provide a navigational heading to give context for breadcrumb links to
    // screen-reader users. Make the heading invisible with .element-invisible.
    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';

    // Hide breadcrumb navigation if it contains only one element.
    $hide_single_breadcrumb = variable_get('path_breadcrumbs_hide_single_breadcrumb', 0);
    if ($hide_single_breadcrumb && count($breadcrumbs) == 1) {
      return FALSE;
    }

    // Bootstrap 3 compatibility. See: https://drupal.org/node/2178565
    if (is_array($breadcrumbs[count($breadcrumbs) - 1])) {
      array_pop($breadcrumbs);
    }

    // Add options for rich snippets.
    $elem_tag = 'span';
    $elem_property = '';
    $root_property = '';
    $options = array('html' => TRUE);
    $snippet = variable_get('path_breadcrumbs_rich_snippets', PATH_BREADCRUMBS_RICH_SNIPPETS_DISABLED);
    if ($snippet == PATH_BREADCRUMBS_RICH_SNIPPETS_RDFA) {

      // Add link options for RDFa support.
      $options['attributes'] = array('rel' => 'v:url', 'property' => 'v:title');
      $options['absolute'] = TRUE;

      // Set correct properties for RDFa support.
      $elem_property = ' typeof="v:Breadcrumb"';
      $root_property = ' xmlns:v="http://rdf.data-vocabulary.org/#"';
    }
    elseif ($snippet == PATH_BREADCRUMBS_RICH_SNIPPETS_MICRODATA) {

      // Add link options for microdata support.
      $options['attributes'] = array('itemprop' => 'url');
      $options['absolute'] = TRUE;

      // Set correct properties for microdata support.
      $elem_property = ' itemscope itemtype="http://data-vocabulary.org/Breadcrumb"';
      $elem_tag = 'div';

      // Add style that will display breadcrumbs wrapped in <div> inline.
      drupal_add_css(drupal_get_path('module', 'path_breadcrumbs') . '/css/path_breadcrumbs.css');
    }

    foreach ($breadcrumbs as $key => $breadcrumb) {

      // Build classes for the breadcrumbs.
      $classes = array('inline');
      $classes[] = $key % 2 ? 'even' : 'odd';
      if ($key == 0) {
        $classes[] = 'first';
      }
      if (count($breadcrumbs) == $key + 1) {
        $classes[] = 'last';
      }

      // For rich snippets support all links should be processed in the same way,
      // even if they are provided not by Path Breadcrumbs module. So I have to
      // parse html code and create links again with new properties.
      preg_match('/href="([^"]+?)"/', $breadcrumb, $matches);

      // Remove base path from href.
      $href = '';
      if (!empty($matches[1])) {
        global $base_path;
        global $language_url;

        $base_string = rtrim($base_path, "/");

        // Append additional params to base string if clean urls are disabled.
        if (!variable_get('clean_url', 0)) {
          $base_string .= '?q=';
        }

        // Append additional params to base string for multilingual sites.
        // @note: Only core URL detection method supported.
        $enabled_negotiation_types = variable_get("language_negotiation_language", array());
        if (!empty($enabled_negotiation_types['locale-url']) && !empty($language_url->prefix)) {
          $base_string .= '/' . $language_url->prefix;
        }

        // Means that this is href to the frontpage.
        if ($matches[1] == $base_string || $matches[1] == '' || $matches[1] == '/') {
          $href = '';
        }
        // All hrefs exept frontpage.
        elseif (stripos($matches[1], "$base_string/") === 0) {
          $href = drupal_substr($matches[1], drupal_strlen("$base_string/"));
        }
        // Other cases.
        else {
          // HREF param can't starts with '/'.
          $href = stripos($matches[1], '/') === 0 ? drupal_substr($matches[1], 1) : $matches[1];
        }

        // If HREF param is empty it should be linked to a front page.
        $href = empty($href) ? '<front>' : $href;
      }

      // Get breadcrumb title from a link like "<a href = "/path">title</a>".
      $title = trim(strip_tags($breadcrumb));

      // Wrap title in additional element for microdata support.
      if ($snippet == PATH_BREADCRUMBS_RICH_SNIPPETS_MICRODATA) {
        $title = '<span itemprop="title">' . $title . '</span>';
      }

      // Support title attribute.
      if (preg_match('/<a\s.*?title="([^"]+)"[^>]*>/i', $breadcrumb, $attr_matches)) {
        $options['attributes']['title'] = $attr_matches[1];
      }
      else {
        unset($options['attributes']['title']);
      }

      // Decode url to prevent double encoding in l().
      $href = rawurldecode($href);
      // Move query params from $href to $options.
      $href = _path_breadcrumbs_clean_url($href, $options, 'none');

      if (count($breadcrumbs) == $key + 1) {
        // Add fragment after "#"
        $nid = arg(1);
        $arg2 = arg(2);
        if (arg(0) == 'node' && is_numeric($nid) && empty($arg2)) {
          $current_menu_link = db_select('menu_links', 'ml')
            ->condition('ml.link_path', 'node/' . $nid)
            ->fields('ml', array())
            ->range(0, 1)
            ->execute()
            ->fetchAll();
          if (!empty($current_menu_link[0]->plid)) {
            $menu_link = menu_link_load($current_menu_link[0]->plid);
            if (!empty($menu_link['options']['attributes']['id'])) {
              $options['fragment'] = $menu_link['options']['attributes']['id'];
            }
          }
        }
      }

      // Build new text or link breadcrumb.
      $new_breadcrumb = !empty($href) ? l($title, $href, $options) : $title;

      // Replace old breadcrumb link with a new one.
      $breadcrumbs[$key] = '<' . $elem_tag . ' class="' . implode(' ', $classes) . '"' . $elem_property . '>' . $new_breadcrumb . '</' . $elem_tag . '>';
    }

    // Get breadcrumb delimiter and wrap it into <span> for customization.
    $delimiter = variable_get('path_breadcrumbs_delimiter', '»');
    $delimiter = '<span class="delimiter">' . trim($delimiter) . '</span>';

    $classes = array('breadcrumb');

    // Show contextual link if it is Path Breadcrumbs variant.
    $prefix = '';
    $path_breadcrumbs_data = path_breadcrumbs_load_variant(current_path());
    if (user_access('administer path breadcrumbs') && $path_breadcrumbs_data && isset($path_breadcrumbs_data->variant)) {
      $contextual_links = array(
        '#type' => 'contextual_links',
        '#contextual_links' => array('path_breadcrumbs' => array('admin/structure/path-breadcrumbs/edit', array($path_breadcrumbs_data->variant->machine_name))),
      );
      $prefix = drupal_render($contextual_links);
      $classes[] = 'contextual-links-region';
    }

    // Build final version of breadcrumb's HTML output.
    $output .= '<div class="' . implode(' ', $classes) . '"' . $root_property . '>' . $prefix . implode(" $delimiter ", $breadcrumbs) . '</div>';

    return $output;
  }

  // Return false if no breadcrumbs.
  return FALSE;
}