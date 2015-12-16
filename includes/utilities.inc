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
  * @param type $entity_type
  *   Entity type of node
  *
  * @return array
  *   Candidate fields as associative array.
  */
function agile_iit_get_number_fields($entity_type = NULL) {
  $fields_available = [];
  $candidates = [];
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