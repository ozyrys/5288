<?php
/**
 * @file
 * egovselect_search.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function egovselect_search_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'solr_pages';
  $view->description = 'Main pages with filters served by apache solr';
  $view->tag = 'default';
  $view->base_table = 'apachesolr__solr';
  $view->human_name = 'Solr Pages';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Apache Solr: url */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: label */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['label'] = '';
  $handler->display->display_options['fields']['label']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['label']['alter']['path'] = '[url]';
  $handler->display->display_options['fields']['label']['element_type'] = 'div';
  $handler->display->display_options['fields']['label']['element_class'] = 'field-title';
  $handler->display->display_options['fields']['label']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: content */
  $handler->display->display_options['fields']['content']['id'] = 'content';
  $handler->display->display_options['fields']['content']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['content']['field'] = 'content';
  $handler->display->display_options['fields']['content']['label'] = '';
  $handler->display->display_options['fields']['content']['alter']['max_length'] = '250';
  $handler->display->display_options['fields']['content']['alter']['more_link'] = TRUE;
  $handler->display->display_options['fields']['content']['alter']['more_link_text'] = 'Read more';
  $handler->display->display_options['fields']['content']['alter']['more_link_path'] = '[url]';
  $handler->display->display_options['fields']['content']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['content']['element_type'] = 'span';
  $handler->display->display_options['fields']['content']['element_class'] = 'field-body';
  $handler->display->display_options['fields']['content']['element_label_colon'] = FALSE;
  /* Sort criterion: Apache Solr: bs_sticky */
  $handler->display->display_options['sorts']['bs_sticky']['id'] = 'bs_sticky';
  $handler->display->display_options['sorts']['bs_sticky']['table'] = 'apachesolr__solr';
  $handler->display->display_options['sorts']['bs_sticky']['field'] = 'bs_sticky';
  $handler->display->display_options['sorts']['bs_sticky']['order'] = 'DESC';
  /* Sort criterion: Apache Solr: label */
  $handler->display->display_options['sorts']['label']['id'] = 'label';
  $handler->display->display_options['sorts']['label']['table'] = 'apachesolr__solr';
  $handler->display->display_options['sorts']['label']['field'] = 'label';
  /* Sort criterion: Apache Solr: ds_created */
  $handler->display->display_options['sorts']['ds_created']['id'] = 'ds_created';
  $handler->display->display_options['sorts']['ds_created']['table'] = 'apachesolr__solr';
  $handler->display->display_options['sorts']['ds_created']['field'] = 'ds_created';
  $handler->display->display_options['sorts']['ds_created']['order'] = 'DESC';
  /* Filter criterion: Apache Solr: bundle */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  /* Filter criterion: Apache Solr: bs_status */
  $handler->display->display_options['filters']['bs_status_1']['id'] = 'bs_status_1';
  $handler->display->display_options['filters']['bs_status_1']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['bs_status_1']['field'] = 'bs_status';
  $handler->display->display_options['filters']['bs_status_1']['value'] = '1';

  /* Display: Search */
  $handler = $view->new_display('page', 'Search', 'solr_search');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Search results';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'views-search';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '<p class="results">@start - @end of @total results</p>';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Your search did not match any documents.

Suggestions:

<ul>
<li>Make sure that all words are spelled correctly.</li>
<li>Try different keywords.</li>
<li>Try more general keywords.</li>
<li>Try fewer keywords.</li>
</ul>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Apache Solr: label */
  $handler->display->display_options['sorts']['label']['id'] = 'label';
  $handler->display->display_options['sorts']['label']['table'] = 'apachesolr__solr';
  $handler->display->display_options['sorts']['label']['field'] = 'label';
  /* Sort criterion: Apache Solr: bs_sticky */
  $handler->display->display_options['sorts']['bs_sticky']['id'] = 'bs_sticky';
  $handler->display->display_options['sorts']['bs_sticky']['table'] = 'apachesolr__solr';
  $handler->display->display_options['sorts']['bs_sticky']['field'] = 'bs_sticky';
  $handler->display->display_options['sorts']['bs_sticky']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Apache Solr: Search */
  $handler->display->display_options['filters']['keyword']['id'] = 'keyword';
  $handler->display->display_options['filters']['keyword']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['keyword']['field'] = 'keyword';
  $handler->display->display_options['filters']['keyword']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keyword']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['keyword']['expose']['operator'] = 'keyword_op';
  $handler->display->display_options['filters']['keyword']['expose']['identifier'] = 'keyword';
  $handler->display->display_options['filters']['keyword']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  /* Filter criterion: Apache Solr: bs_status */
  $handler->display->display_options['filters']['bs_status']['id'] = 'bs_status';
  $handler->display->display_options['filters']['bs_status']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['bs_status']['field'] = 'bs_status';
  $handler->display->display_options['filters']['bs_status']['value'] = '1';
  $handler->display->display_options['path'] = 'searcher';

  /* Display: Jobs */
  $handler = $view->new_display('page', 'Jobs', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Jobs';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'view-search-jobs';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['class'] = 'views-rows';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '@total job offer(s) found';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Apache Solr: entity_id */
  $handler->display->display_options['fields']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['label'] = '';
  $handler->display->display_options['fields']['entity_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Apache Solr: bundle */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['value'] = 'job';
  /* Filter criterion: Apache Solr: bs_status */
  $handler->display->display_options['filters']['bs_status_1']['id'] = 'bs_status_1';
  $handler->display->display_options['filters']['bs_status_1']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['bs_status_1']['field'] = 'bs_status';
  $handler->display->display_options['filters']['bs_status_1']['value'] = '1';
  $handler->display->display_options['path'] = 'jobs';
  $translatables['solr_pages'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Read more'),
    t('Search'),
    t('Search results'),
    t('<p class="results">@start - @end of @total results</p>'),
    t('Your search did not match any documents.

Suggestions:

<ul>
<li>Make sure that all words are spelled correctly.</li>
<li>Try different keywords.</li>
<li>Try more general keywords.</li>
<li>Try fewer keywords.</li>
</ul>'),
    t('Jobs'),
    t('@total job offer(s) found'),
  );
  $export['solr_pages'] = $view;

  return $export;
}
