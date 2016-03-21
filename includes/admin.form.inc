<?php

/**
 * @file
 * This administration form for this module.
 */

/**
 * The configuration form for the image viewer.
 *
 * @param array $form
 *   The Drupal form definition.
 * @param array $form_state
 *   The Drupal form state.
 *
 * @return array
 *   The Drupal form definition.
 */
function iit_admin(array $form, array &$form_state) {
  $fields_available = ''; // TODO: Query for existing fields of type image and display them here with their machine
  //names, their display names, and what content types they appear in, as a guide to the user.
  $form = array(
    'iit_image_fields' => array(
      '#type' => 'textfield',
      '#title' => t('Image Field'),
      '#default_value' => variable_get('iit_image_field', 'field_image'),
      '#description' => t('The machine name of the field that contains the image. It should exist in all content
      types that can be flagged with "flag_selected".'),
      '#required' => TRUE,
    ),
  );
  return system_settings_form($form);
}

/**
 * Validate the admin form.
 */
function iit_admin_validate($form, &$form_state) {
  // Test whether that field exists.
  $field_name = $form_state['values']['iit_image_fields'];
  $fields = field_info_field_map();
  if (!isset($fields[$field_name])) {
    form_set_error('iit_image_fields', t('<em>Image field</em> must exist.'));
  }
}