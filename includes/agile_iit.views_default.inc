<?php
/**
 * @file
 * Default view.
 */

/**
 * Provide default view required for IIT display.
 *
 * @return view
 *   Default view
 */
function agile_iit_views_default_views() {
  // Flag Selected
  $view = new view();
  $view->name = 'iit_selected';
  $view->description = 'A page listing the current user\'s selected images at /selected.';
  $view->tag = 'flag';
  $view->base_table = 'node';
  $view->human_name = 'flag_selected';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'My Selected Images';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'flag selected_images';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Footer: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['text']['id'] = 'text';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['empty'] = TRUE;
  $handler->display->display_options['empty']['text']['content'] = 'You have not yet selected any content. Click the "Select this" link when viewing a piece of content to add it to this list.';
  $handler->display->display_options['empty']['text']['format'] = 'plain_text';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['relationships']['uid_1']['table'] = 'node';
  $handler->display->display_options['relationships']['uid_1']['field'] = 'uid';
  /* Relationship: Flags: selected_images */
  $handler->display->display_options['relationships']['flag_content_rel_1']['id'] = 'flag_content_rel_1';
  $handler->display->display_options['relationships']['flag_content_rel_1']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel_1']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel_1']['label'] = 'selected';
  $handler->display->display_options['relationships']['flag_content_rel_1']['flag'] = 'selected_images';
  /* Relationship: File Usage: File */
  $handler->display->display_options['relationships']['node_to_file']['id'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['node_to_file']['field'] = 'node_to_file';
  /* Field: Content: image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['alter']['text'] = '<img typeof="foaf:Image"  src="http://localhost:8888/agile/sites/default/files/styles/thumbnail/public/field/image/baked-pie.jpg?itok=cBwdjiN6" width="100" height="75" alt="Foo" data-lrg_url="sites/default/files/field/image/baked-pie.jpg" >';
  $handler->display->display_options['fields']['field_image']['element_class'] = 'iit-thumb ui-thumb clearfix';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'file',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel_1';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  /* Field: Content: Height */
  $handler->display->display_options['fields']['field_iit_height']['id'] = 'field_iit_height';
  $handler->display->display_options['fields']['field_iit_height']['table'] = 'field_data_field_iit_height';
  $handler->display->display_options['fields']['field_iit_height']['field'] = 'field_iit_height';
  $handler->display->display_options['fields']['field_iit_height']['label'] = 'iit_height';
  $handler->display->display_options['fields']['field_iit_height']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_iit_height']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Width */
  $handler->display->display_options['fields']['field_iit_width']['id'] = 'field_iit_width';
  $handler->display->display_options['fields']['field_iit_width']['table'] = 'field_data_field_iit_width';
  $handler->display->display_options['fields']['field_iit_width']['field'] = 'field_iit_width';
  $handler->display->display_options['fields']['field_iit_width']['label'] = 'iit_width';
  $handler->display->display_options['fields']['field_iit_width']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_iit_width']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Dimensions formatted */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Dimensions formatted';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_iit_height] x [field_iit_width] cm';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: File URI */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['uri']['ui_name'] = 'File URI';
  $handler->display->display_options['fields']['uri']['label'] = '';
  $handler->display->display_options['fields']['uri']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uri']['element_label_colon'] = FALSE;
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri_1']['id'] = 'uri_1';
  $handler->display->display_options['fields']['uri_1']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri_1']['field'] = 'uri';
  $handler->display->display_options['fields']['uri_1']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['uri_1']['label'] = '';
  $handler->display->display_options['fields']['uri_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uri_1']['alter']['text'] = '<img src="[uri_1]" alt="[title]" data-width="[field_width]" data-height="[field_height]" width="220" data-lrg-url="[uri]" data-date="1999" data-support="canvas"/>';
  $handler->display->display_options['fields']['uri_1']['element_class'] = 'iit-thumb ui-thumb clearfix';
  $handler->display->display_options['fields']['uri_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uri_1']['link_to_file'] = TRUE;
  $handler->display->display_options['fields']['uri_1']['file_download_path'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = '0';
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'selected';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'My Selected Images';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  // Add view to list of views to provide.
  $views[$view->name] = $view;

  // Flag Saved Comparisons
  $view = new view();
  $view->name = 'flag_saved_comparisons';
  $view->description = 'A page listing the current user\'s selected images at /selected.';
  $view->tag = 'flag';
  $view->base_table = 'node';
  $view->human_name = 'flag_saved_comparisons';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'My Saved Comparisons';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'flag saved_comparisons';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['text']['id'] = 'text';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['empty'] = TRUE;
  $handler->display->display_options['empty']['text']['content'] = 'You have not yet selected any content. Click the "Select this" link when viewing a piece of content to add it to this list.';
  $handler->display->display_options['empty']['text']['format'] = 'plain_text';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['relationships']['uid_1']['table'] = 'node';
  $handler->display->display_options['relationships']['uid_1']['field'] = 'uid';
  /* Relationship: Flags: saved_comparisons */
  $handler->display->display_options['relationships']['flag_content_rel_1']['id'] = 'flag_content_rel_1';
  $handler->display->display_options['relationships']['flag_content_rel_1']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel_1']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel_1']['label'] = 'saved';
  $handler->display->display_options['relationships']['flag_content_rel_1']['flag'] = 'saved_comparisons';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Detail Comments */
  $handler->display->display_options['fields']['iit_comments']['id'] = 'iit_comments';
  $handler->display->display_options['fields']['iit_comments']['table'] = 'field_data_iit_comments';
  $handler->display->display_options['fields']['iit_comments']['field'] = 'iit_comments';
  $handler->display->display_options['fields']['iit_comments']['label'] = '';
  $handler->display->display_options['fields']['iit_comments']['element_label_colon'] = FALSE;
  /* Field: Content: Image Detail 1 */
  $handler->display->display_options['fields']['iit_detail_1']['id'] = 'iit_detail_1';
  $handler->display->display_options['fields']['iit_detail_1']['table'] = 'field_data_iit_detail_1';
  $handler->display->display_options['fields']['iit_detail_1']['field'] = 'iit_detail_1';
  $handler->display->display_options['fields']['iit_detail_1']['label'] = '';
  $handler->display->display_options['fields']['iit_detail_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['iit_detail_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['iit_detail_1']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Image Detail 2 */
  $handler->display->display_options['fields']['iit_detail_2']['id'] = 'iit_detail_2';
  $handler->display->display_options['fields']['iit_detail_2']['table'] = 'field_data_iit_detail_2';
  $handler->display->display_options['fields']['iit_detail_2']['field'] = 'iit_detail_2';
  $handler->display->display_options['fields']['iit_detail_2']['label'] = '';
  $handler->display->display_options['fields']['iit_detail_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['iit_detail_2']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['iit_detail_2']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel_1';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = '0';
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'iit_detail_comparison' => 'iit_detail_comparison',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'saved_comparisons';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'My Saved Comparisons';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;


  // Add view to list of views to provide.
  $views[$view->name] = $view;

  // ...Repeat all of the above for each view the module should provide.
  // At the end, return array of default views.
  return $views;
}
