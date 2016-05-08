<?php
/**
 * @file
 * object_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function object_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function object_content_type_node_info() {
  $items = array(
    'object' => array(
      'name' => t('Object'),
      'base' => 'node_content',
      'description' => t('Brueghel Paintings, Drawings, Prints and Oil Sketches'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
