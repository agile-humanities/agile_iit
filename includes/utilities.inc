<?php

/**
 * @file
 * Utiltiy functions.
 */

/**
 * Gets all node types with number fields.
 *
 * @return array
 *   Candidate field types
 */
function agile_iit_get_candidates() {
  $candidates = array();
  $entity_types = node_type_get_names();
  foreach ($entity_types as $entity_type) {
    $fields = field_info_instances('node', $entity_type);
    foreach ($fields as $field) {
      if ($field['widget']['type'] == 'number') {
        $candidates[] = $entity_type;
        break;
      }
    }
  }
  return $candidates;
}

/**
 * Returns number fields from enity type.
 *
 * @param string $entity_type
 *   Entity type of node.
 *
 * @return array
 *   Candidate fields as associative array.
 */
function agile_iit_get_number_fields($entity_type = NULL) {
  $fields_available = array();
  $candidates = array();
  if (!$entity_type) {
    $all_instances = field_info_instances('node');
    foreach ($all_instances as $bundle => $fields) {
      $fields_available += $fields;
    }
  }
  else {
    $fields_available = field_info_instances('node', $entity_type);
  }
  foreach ($fields_available as $machine_name => $field) {
    if ($field['widget']['type'] == 'number') {
      $candidates[$machine_name] = $field['label'];
    }
  }
  return $candidates;
}

/**
 * Determines whether nid is of node type with one or more number fields.
 *
 * @param string $nid
 *   Node identifier.
 *
 * @return bool
 *   True if node type has number field
 */
function agile_iit_has_number_type($nid) {
  $node = node_load($nid);
  // Check if the node exists - I was getting this called on nothing
  // possibly out of a configuration error.
  if ($node) {
    $candidates = agile_iit_get_number_fields($node->type);
  }
  else {
    watchdog('agile', 'no node found for nid: ' . $nid);
    $candidates = array();
  }
  return count($candidates) > 0;
}

/**
 * Returns formatted image for view.
 *
 * @param stdClass $data
 *   Data from view
 *
 * @return HTML
 *   Styled image html
 */
function agile_iit_make_image($data) {
  $node = node_load($data->nid);
  $wrapper = entity_metadata_wrapper('node', $node);
  $image_property = $wrapper->field_object_image->raw();
  $variables = array(
    'style_name' => 'iit-200',
    'path' => $image_property['uri'],
    'alt' => $node->title,
    'title' => $node->title,
    'attributes' => array(
      'data-width' => $wrapper->field_dimensions_width->raw(),
      'data-height' => $wrapper->field_dimensions_height->raw(),
      'data-date' => '1999',
      'nid' => $node->nid,
      'data-support' => "canvas",
      'data-lrg-url'=>$image_property['uri'],
    ),
  );
  return theme_image_style($variables);
}

/**
 * Returns local path for given URL.
 *
 * @global type $base_url
 * @global type $base_path
 * @param url $url
 *   url to be parsed and returned
 *
 * @return string
 *  local path
 */
function agile_iit_get_local_path($url) {
  global $base_url;
  global $base_path;
  $path = parse_url($url);
  $path = $path['path'];
  $pos = strpos($path, $base_path);
  if ($pos === 0) {
    $path = substr($path, strlen($base_path));
  }
  $path = urldecode($path);
  return $path;
}
