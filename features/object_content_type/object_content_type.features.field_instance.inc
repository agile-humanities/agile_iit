<?php
/**
 * @file
 * object_content_type.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function object_content_type_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'field_collection_item-field_bibliography-field_biblio_reference'.
  $field_instances['field_collection_item-field_bibliography-field_biblio_reference'] = array(
    'bundle' => 'field_bibliography',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Autocomplete uses long titles only; to match a short title with a long title, search the <a href="/bibliography" target="_blank">list of bibliographic short titles</a>.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'node_reference_default',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'node_reference_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_biblio_reference',
    'label' => 'Biblio Reference',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'node_reference',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'autocomplete_path' => 'node_reference/autocomplete',
        'size' => 60,
      ),
      'type' => 'node_reference_autocomplete',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_bibliography-field_reference_notes'.
  $field_instances['field_collection_item-field_bibliography-field_reference_notes'] = array(
    'bundle' => 'field_bibliography',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_reference_notes',
    'label' => 'Reference Notes',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_copies_and_variants-field_copy_description'.
  $field_instances['field_collection_item-field_copies_and_variants-field_copy_description'] = array(
    'bundle' => 'field_copies_and_variants',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_copy_description',
    'label' => 'Description',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_copies_and_variants-field_copy_variant_image'.
  $field_instances['field_collection_item-field_copies_and_variants-field_copy_variant_image'] = array(
    'bundle' => 'field_copies_and_variants',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'conditions' => array(),
          'image_link' => 'file',
          'image_style' => 'medium',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_copy_variant_image',
    'label' => 'Copy/Variant Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'objects',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'private' => 0,
          'public' => 'public',
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 0,
          'image' => 'image',
          'video' => 0,
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 'media_default--media_browser_1',
          'media_default--media_browser_my_files' => 0,
          'media_internet' => 'media_internet',
          'upload' => 'upload',
        ),
      ),
      'type' => 'media_generic',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_curatorial_files-field_curatorial_file'.
  $field_instances['field_collection_item-field_curatorial_files-field_curatorial_file'] = array(
    'bundle' => 'field_curatorial_files',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'file_entity',
        'settings' => array(
          'conditions' => array(),
          'file_view_mode' => 'teaser',
        ),
        'type' => 'file_rendered',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_curatorial_file',
    'label' => 'Curatorial File',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'objects',
      'file_extensions' => 'txt pdf jpg jpeg gif png tif',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'private' => 'private',
          'public' => 'public',
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 'document',
          'image' => 'image',
          'video' => 0,
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 'media_default--media_browser_1',
          'media_default--media_browser_my_files' => 0,
          'media_internet' => 'media_internet',
          'upload' => 'upload',
        ),
      ),
      'type' => 'media_generic',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_curatorial_files-field_description'.
  $field_instances['field_collection_item-field_curatorial_files-field_description'] = array(
    'bundle' => 'field_curatorial_files',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_description',
    'label' => 'Description',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_curatorial_files-field_equipment_used'.
  $field_instances['field_collection_item-field_curatorial_files-field_equipment_used'] = array(
    'bundle' => 'field_curatorial_files',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_equipment_used',
    'label' => 'Equipment Used',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_curatorial_files-field_file_location'.
  $field_instances['field_collection_item-field_curatorial_files-field_file_location'] = array(
    'bundle' => 'field_curatorial_files',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_file_location',
    'label' => 'Location',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'hs_taxonomy',
      'settings' => array(),
      'type' => 'taxonomy_hs',
      'weight' => 8,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_curatorial_files-field_file_type'.
  $field_instances['field_collection_item-field_curatorial_files-field_file_type'] = array(
    'bundle' => 'field_curatorial_files',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_file_type',
    'label' => 'File Type',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'cshs',
      'settings' => array(
        'cshs' => array(
          'force_deepest' => 1,
          'level_labels' => '',
          'parent' => 0,
        ),
      ),
      'type' => 'cshs',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_curatorial_files-field_notes'.
  $field_instances['field_collection_item-field_curatorial_files-field_notes'] = array(
    'bundle' => 'field_curatorial_files',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_notes',
    'label' => 'Notes',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_curatorial_files-field_original_format'.
  $field_instances['field_collection_item-field_curatorial_files-field_original_format'] = array(
    'bundle' => 'field_curatorial_files',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_original_format',
    'label' => 'Original Format',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_curatorial_files-field_research_date'.
  $field_instances['field_collection_item-field_curatorial_files-field_research_date'] = array(
    'bundle' => 'field_curatorial_files',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'date',
        'settings' => array(
          'conditions' => array(),
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => FALSE,
          'show_repeat_rule' => 'show',
        ),
        'type' => 'date_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_research_date',
    'label' => 'Research Date',
    'required' => 0,
    'settings' => array(
      'default_value' => 'blank',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'display_all_day' => 0,
        'increment' => 15,
        'input_format' => 'Y-m-d H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'repeat_collapsed' => 0,
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_text',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_curatorial_files-field_researchers'.
  $field_instances['field_collection_item-field_curatorial_files-field_researchers'] = array(
    'bundle' => 'field_curatorial_files',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_researchers',
    'label' => 'Researchers',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_provenance-field_provenance_date'.
  $field_instances['field_collection_item-field_provenance-field_provenance_date'] = array(
    'bundle' => 'field_provenance',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'partial_date',
        'settings' => array(
          'component_settings' => array(
            'components' => array(
              'approx' => array(
                'value' => 'ca.',
                'weight' => -10,
              ),
              'c1' => array(
                'value' => '',
                'weight' => -2,
              ),
              'c2' => array(
                'value' => '',
                'weight' => -1,
              ),
              'c3' => array(
                'value' => '',
                'weight' => 0,
              ),
              'day' => array(
                'empty' => '',
                'format' => 'j',
                'weight' => -8,
              ),
              'hour' => array(
                'empty' => '',
                'format' => 'h',
                'weight' => -6,
              ),
              'minute' => array(
                'empty' => '',
                'format' => 'i',
                'weight' => -5,
              ),
              'month' => array(
                'empty' => '',
                'format' => 'M',
                'weight' => -9,
              ),
              'second' => array(
                'empty' => '',
                'format' => 's',
                'weight' => -4,
              ),
              'timezone' => array(
                'empty' => '',
                'format' => 'T',
                'weight' => -3,
              ),
              'year' => array(
                'empty' => '',
                'format' => 'Y-ce',
                'weight' => -7,
              ),
            ),
            'display' => array(
              'day' => 'estimate_label',
              'hour' => 'estimate_label',
              'minute' => 'estimate_label',
              'month' => 'estimate_label',
              'second' => 'estimate_label',
              'timezone' => 'date_only',
              'year' => 'estimate_label',
            ),
            'meridiem' => 'a',
            'separator' => array(
              'date' => ' ',
              'datetime' => ' ',
              'other' => ' ',
              'range' => ' - ',
              'time' => ':',
            ),
            'year_designation' => 'bce',
          ),
          'conditions' => array(),
          'format' => 'custom',
          'use_override' => 'short',
        ),
        'type' => 'partial_date_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_provenance_date',
    'label' => 'Provenance Date',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'partial_date',
      'settings' => array(
        0 => FALSE,
        'estimates' => array(
          'from' => array(
            'day' => 0,
            'hour' => 0,
            'minute' => 0,
            'month' => 'month',
            'second' => 0,
            'year' => 'year',
          ),
          'to' => array(
            'day' => 0,
            'hour' => 0,
            'minute' => 0,
            'month' => 'month',
            'second' => 0,
            'year' => 'year',
          ),
        ),
        'granularity' => array(
          'from' => array(
            'day' => 'day',
            'hour' => 0,
            'minute' => 0,
            'month' => 'month',
            'second' => 0,
            'timezone' => 0,
            'year' => 'year',
          ),
          'to' => array(
            'day' => 'day',
            'hour' => 0,
            'minute' => 0,
            'month' => 'month',
            'second' => 0,
            'timezone' => 0,
            'year' => 'year',
          ),
        ),
        'help_txt' => array(
          'und' => array(
            '_remove' => '',
            'check_approximate' => '',
            'components' => '',
            'txt_long' => 'Longer description of date',
            'txt_short' => 'Short description of date',
          ),
        ),
        'hide_remove' => 1,
        'increments' => array(
          'minute' => 1,
          'second' => 1,
        ),
        'theme_overrides' => array(
          'check_approximate' => 1,
          'range_inline' => 1,
          'txt_long' => 0,
          'txt_short' => 1,
        ),
        'tz_handling' => 'none',
      ),
      'type' => 'partial_date',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_provenance-field_provenance_location'.
  $field_instances['field_collection_item-field_provenance-field_provenance_location'] = array(
    'bundle' => 'field_provenance',
    'default_value' => array(),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'taxonomy',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'taxonomy_term_reference_plain',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_provenance_location',
    'label' => 'Provenance Location',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'cshs',
      'settings' => array(
        'apply_chosen' => '',
        'cshs' => array(
          'force_deepest' => FALSE,
          'level_labels' => '',
          'parent' => 0,
        ),
      ),
      'type' => 'cshs',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_provenance-field_provenance_text'.
  $field_instances['field_collection_item-field_provenance-field_provenance_text'] = array(
    'bundle' => 'field_provenance',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_provenance_text',
    'label' => 'Provenance Text',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-object-field_attribution'.
  $field_instances['node-object-field_attribution'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 1,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 26,
      ),
      'iit_crop_info' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 19,
      ),
      'random_page' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 1,
      ),
      'related_work' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22,
      ),
      'related_works' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 42,
      ),
      'search_result' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 45,
      ),
    ),
    'entity_type' => 'node',
    'field_label_plurals_singular' => '',
    'field_name' => 'field_attribution',
    'label' => 'Our Attribution',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 1,
      ),
      'type' => 'options_select',
      'weight' => 49,
    ),
  );

  // Exported field_instance: 'node-object-field_attribution_authority'.
  $field_instances['node-object-field_attribution_authority'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 27,
      ),
      'iit_crop_info' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22,
      ),
      'random_page' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'related_work' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
      'related_works' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 20,
      ),
      'search_result' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 27,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
    ),
    'entity_type' => 'node',
    'field_label_plurals_singular' => 'Other Authority',
    'field_name' => 'field_attribution_authority',
    'label' => 'Other Authorities',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 50,
    ),
  );

  // Exported field_instance: 'node-object-field_bailey_walker'.
  $field_instances['node-object-field_bailey_walker'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 20,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 30,
      ),
      'iit_crop_info' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'random_page' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 23,
      ),
      'related_works' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 63,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_bailey_walker',
    'label' => 'Bailey/Walker',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 53,
    ),
  );

  // Exported field_instance: 'node-object-field_bibliography'.
  $field_instances['node-object-field_bibliography'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 26,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'field_collection',
        'settings' => array(
          'conditions' => array(),
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_fields',
        'weight' => 36,
      ),
      'iit_crop_info' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'random_page' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 28,
      ),
      'related_works' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 44,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 31,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_bibliography',
    'label' => 'Bibliography',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 33,
    ),
  );

  // Exported field_instance: 'node-object-field_bibliography_items'.
  $field_instances['node-object-field_bibliography_items'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 37,
      ),
      'iit_crop_info' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
      'random_page' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'related_work' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 28,
      ),
      'related_works' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 41,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 23,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 29,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_bibliography_items',
    'label' => 'Bibliography',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 32,
    ),
  );

  // Exported field_instance: 'node-object-field_categories'.
  $field_instances['node-object-field_categories'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'taxonomy',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 50,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 6,
      ),
      'iit_crop_info' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 41,
      ),
      'random_page' => array(
        'label' => 'hidden',
        'module' => 'taxonomy',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 14,
      ),
      'related_work' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 43,
      ),
      'related_works' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 38,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 58,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 51,
      ),
    ),
    'entity_type' => 'node',
    'field_label_plurals_singular' => 'Tag',
    'field_name' => 'field_categories',
    'label' => 'Tags',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'hs_taxonomy',
      'settings' => array(),
      'type' => 'taxonomy_hs',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-object-field_circa'.
  $field_instances['node-object-field_circa'] = array(
    'bundle' => 'object',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'This should be checked if "Approximation only" above is checked',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 39,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'list_default',
        'weight' => 8,
      ),
      'iit_crop_info' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'random_page' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
      'related_works' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 62,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_circa',
    'label' => 'Circa?',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 22,
    ),
  );

  // Exported field_instance: 'node-object-field_collaborator'.
  $field_instances['node-object-field_collaborator'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'node_reference',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'node_reference_default',
        'weight' => 49,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'node_reference',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'node_reference_default',
        'weight' => 22,
      ),
      'iit_crop_info' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 39,
      ),
      'random_page' => array(
        'label' => 'inline',
        'module' => 'node_reference',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'node_reference_default',
        'weight' => 15,
      ),
      'related_work' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 39,
      ),
      'related_works' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 34,
      ),
      'search_result' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 54,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 48,
      ),
    ),
    'entity_type' => 'node',
    'entityconnect_unload_add' => 0,
    'entityconnect_unload_edit' => 0,
    'field_label_plurals_singular' => 'Collaborator',
    'field_name' => 'field_collaborator',
    'label' => 'Collaborators',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 1,
      ),
      'type' => 'options_select',
      'weight' => 22,
    ),
  );

  // Exported field_instance: 'node-object-field_collaborator_notes'.
  $field_instances['node-object-field_collaborator_notes'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 50,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 23,
      ),
      'iit_crop_info' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 40,
      ),
      'random_page' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 16,
      ),
      'related_work' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 40,
      ),
      'related_works' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 35,
      ),
      'search_result' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 55,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 28,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_collaborator_notes',
    'label' => 'Collaborator Notes',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 23,
    ),
  );

  // Exported field_instance: 'node-object-field_collection_type'.
  $field_instances['node-object-field_collection_type'] = array(
    'bundle' => 'object',
    'default_value' => array(
      0 => array(
        'value' => 'public',
      ),
    ),
    'deleted' => 0,
    'description' => 'For privately owned objects on loan to public collections, choose "Public."',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 28,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'list_default',
        'weight' => 32,
      ),
      'iit_crop_info' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 47,
      ),
      'random_page' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 30,
      ),
      'related_work' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 46,
      ),
      'related_works' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 48,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 34,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 32,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_collection_type',
    'label' => 'Collection type',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 21,
    ),
  );

  // Exported field_instance: 'node-object-field_copies_and_variants'.
  $field_instances['node-object-field_copies_and_variants'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'field_collection',
        'settings' => array(
          'conditions' => array(),
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_fields',
        'weight' => 39,
      ),
      'iit_crop_info' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'random_page' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 21,
      ),
      'related_works' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 19,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 26,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_label_plurals_singular' => 'Copy/Variant',
    'field_name' => 'field_copies_and_variants',
    'label' => 'Copies and Variants',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 57,
    ),
  );

  // Exported field_instance: 'node-object-field_curatorial_files'.
  $field_instances['node-object-field_curatorial_files'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'field_collection',
        'settings' => array(
          'conditions' => array(),
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_fields',
        'weight' => 40,
      ),
      'iit_crop_info' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 45,
      ),
      'random_page' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 20,
      ),
      'related_work' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
      'related_works' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 39,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 59,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_label_plurals_singular' => 'Curatorial File',
    'field_name' => 'field_curatorial_files',
    'label' => 'Curatorial Files',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 38,
    ),
  );

  // Exported field_instance: 'node-object-field_diameter'.
  $field_instances['node-object-field_diameter'] = array(
    'bundle' => 'object',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 31,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'number',
        'settings' => array(
          'conditions' => array(),
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 12,
      ),
      'iit_crop_info' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 50,
      ),
      'random_page' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 34,
      ),
      'related_work' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 49,
      ),
      'related_works' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 51,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 38,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 30,
      ),
    ),
    'entity_type' => 'node',
    'field_label_plurals_singular' => '',
    'field_name' => 'field_diameter',
    'label' => 'Diameter',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'node-object-field_dimensions_height'.
  $field_instances['node-object-field_dimensions_height'] = array(
    'bundle' => 'object',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 29,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'number',
        'settings' => array(
          'conditions' => array(),
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 10,
      ),
      'iit_crop_info' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 48,
      ),
      'random_page' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 32,
      ),
      'related_work' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 47,
      ),
      'related_works' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 49,
      ),
      'search_result' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 35,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 33,
      ),
    ),
    'entity_type' => 'node',
    'field_label_plurals_singular' => '',
    'field_name' => 'field_dimensions_height',
    'label' => 'Height',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-object-field_dimensions_width'.
  $field_instances['node-object-field_dimensions_width'] = array(
    'bundle' => 'object',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 30,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'number',
        'settings' => array(
          'conditions' => array(),
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 11,
      ),
      'iit_crop_info' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 49,
      ),
      'random_page' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 33,
      ),
      'related_work' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 48,
      ),
      'related_works' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 50,
      ),
      'search_result' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 37,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 35,
      ),
    ),
    'entity_type' => 'node',
    'field_label_plurals_singular' => '',
    'field_name' => 'field_dimensions_width',
    'label' => 'Width',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-object-field_ertz_1979'.
  $field_instances['node-object-field_ertz_1979'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 37,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'number',
        'settings' => array(
          'conditions' => array(),
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 29,
      ),
      'iit_crop_info' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'random_page' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
      'related_works' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 60,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_ertz_1979',
    'label' => 'Ertz 1979',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 51,
    ),
  );

  // Exported field_instance: 'node-object-field_ertz_2008_10'.
  $field_instances['node-object-field_ertz_2008_10'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 38,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'number',
        'settings' => array(
          'conditions' => array(),
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 28,
      ),
      'iit_crop_info' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'random_page' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 26,
      ),
      'related_works' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 61,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_ertz_2008_10',
    'label' => 'Ertz 2008-10',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 52,
    ),
  );

  // Exported field_instance: 'node-object-field_exhibition'.
  $field_instances['node-object-field_exhibition'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 21,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 35,
      ),
      'iit_crop_info' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 44,
      ),
      'random_page' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 14,
      ),
      'related_work' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 44,
      ),
      'related_works' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 23,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 32,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 26,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exhibition',
    'label' => 'Exhibition History',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 30,
    ),
  );

  // Exported field_instance: 'node-object-field_external_resources'.
  $field_instances['node-object-field_external_resources'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'link_default',
        'weight' => 6,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'link',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'link_default',
        'weight' => 43,
      ),
      'iit_crop_info' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
      'random_page' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'link_default',
        'weight' => 24,
      ),
      'related_work' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 21,
      ),
      'related_works' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 55,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_external_resources',
    'label' => 'External resources',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => '_blank',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 200,
      ),
      'enable_tokens' => 0,
      'rel_remove' => 'default',
      'title' => 'optional',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 255,
      'title_value' => '',
      'url' => 'optional',
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 16,
    ),
  );

  // Exported field_instance: 'node-object-field_genre'.
  $field_instances['node-object-field_genre'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 36,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 3,
      ),
      'iit_crop_info' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 30,
      ),
      'random_page' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 4,
      ),
      'related_work' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 33,
      ),
      'related_works' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 28,
      ),
      'search_result' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 47,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 37,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_genre',
    'label' => 'Genre',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 1,
      ),
      'type' => 'options_select',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-object-field_hollstein_no'.
  $field_instances['node-object-field_hollstein_no'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 21,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 31,
      ),
      'iit_crop_info' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'random_page' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
      'related_works' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_hollstein_no',
    'label' => 'Hollstein No.',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 54,
    ),
  );

  // Exported field_instance: 'node-object-field_inscriptions'.
  $field_instances['node-object-field_inscriptions'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 46,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 19,
      ),
      'iit_crop_info' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 34,
      ),
      'random_page' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 12,
      ),
      'related_work' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 38,
      ),
      'related_works' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 33,
      ),
      'search_result' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 53,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 41,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_inscriptions',
    'label' => 'Further Inscription',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 19,
    ),
  );

  // Exported field_instance: 'node-object-field_location'.
  $field_instances['node-object-field_location'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'For objects in private collections, choose Unavailable > Private Collection/Art Market, and put any known details about owner or most recent sale below in the "Location Notes" field. For objects in public collections, choose Country > City > Museum, and put any inv./cat. nos. below in the "Location Notes" field. For missing objects, choose Unavailable > Missing/Destroyed.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 35,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'hs_taxonomy',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'hs_taxonomy_term_reference_hierarchical_text',
        'weight' => 33,
      ),
      'iit_crop_info' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'random_page' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 29,
      ),
      'related_work' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
      ),
      'related_works' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 55,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 42,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_location',
    'label' => 'Location',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'hs_taxonomy',
      'settings' => array(),
      'type' => 'taxonomy_hs',
      'weight' => 22,
    ),
  );

  // Exported field_instance: 'node-object-field_location_notes'.
  $field_instances['node-object-field_location_notes'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Use this field to record inv./cat. numbers, dealer/auction details for last known sale, or former location if the object has been destroyed.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 36,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 34,
      ),
      'iit_crop_info' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'random_page' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 27,
      ),
      'related_work' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 19,
      ),
      'related_works' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 56,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 44,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_location_notes',
    'label' => 'Location Notes',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 23,
    ),
  );

  // Exported field_instance: 'node-object-field_medium'.
  $field_instances['node-object-field_medium'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 40,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'iit_crop_info' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'random_page' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 7,
      ),
      'related_work' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 34,
      ),
      'related_works' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 29,
      ),
      'search_result' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 48,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 38,
      ),
    ),
    'entity_type' => 'node',
    'field_label_plurals_singular' => '',
    'field_name' => 'field_medium',
    'label' => 'Medium Remarks',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-object-field_medium_term'.
  $field_instances['node-object-field_medium_term'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 39,
      ),
      'diff_standard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'iit_crop_info' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'random_page' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'related_works' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_label_plurals_singular' => '',
    'field_name' => 'field_medium_term',
    'label' => 'Medium',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 1,
      ),
      'type' => 'options_select',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-object-field_no_dimensions'.
  $field_instances['node-object-field_no_dimensions'] = array(
    'bundle' => 'object',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Check this if no dimension values are available',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 53,
      ),
      'diff_standard' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'list_default',
        'weight' => 14,
      ),
      'iit_crop_info' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'random_page' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'related_works' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_label_plurals_singular' => '',
    'field_name' => 'field_no_dimensions',
    'label' => 'No Dimensions',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 15,
    ),
  );

  // Exported field_instance: 'node-object-field_object_image'.
  $field_instances['node-object-field_object_image'] = array(
    'bundle' => 'object',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'conditions' => array(),
          'image_link' => 'file',
          'image_style' => 'node_display',
        ),
        'type' => 'image',
        'weight' => 1,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'image',
        'settings' => array(
          'conditions' => array(),
          'image_link' => 'file',
          'image_style' => 'node_display',
        ),
        'type' => 'image',
        'weight' => 1,
      ),
      'iit_crop_info' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
      ),
      'random_page' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'conditions' => array(),
          'image_link' => 'file',
          'image_style' => 'node_display',
        ),
        'type' => 'image',
        'weight' => 2,
      ),
      'related_work' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'conditions' => array(),
          'image_link' => 'content',
          'image_style' => 'medium',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'related_works' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'conditions' => array(),
          'image_link' => 'file',
          'image_style' => 'medium',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'conditions' => array(),
          'image_link' => 'content',
          'image_style' => 'search_result',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'file_entity',
        'settings' => array(
          'conditions' => array(),
          'file_view_mode' => 'teaser',
        ),
        'type' => 'file_rendered',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_object_image',
    'label' => 'Object Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'objects',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'private' => 'private',
          'public' => 'public',
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 0,
          'image' => 'image',
          'video' => 0,
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 0,
          'media_default--media_browser_my_files' => 0,
          'media_internet' => 0,
          'upload' => 0,
        ),
      ),
      'type' => 'media_generic',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-object-field_object_type'.
  $field_instances['node-object-field_object_type'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 33,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 2,
      ),
      'iit_crop_info' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 27,
      ),
      'random_page' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 1,
      ),
      'related_work' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 30,
      ),
      'related_works' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
      'search_result' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 43,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 36,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_object_type',
    'label' => 'Object Type',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 1,
      ),
      'type' => 'options_select',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-object-field_patron'.
  $field_instances['node-object-field_patron'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'node_reference',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'node_reference_default',
        'weight' => 54,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'node_reference',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'node_reference_default',
        'weight' => 45,
      ),
      'iit_crop_info' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'random_page' => array(
        'label' => 'inline',
        'module' => 'node_reference',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'node_reference_default',
        'weight' => 19,
      ),
      'related_works' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_label_plurals_singular' => 'Collector/Patron',
    'field_name' => 'field_patron',
    'label' => 'Collectors/Patrons',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 24,
    ),
  );

  // Exported field_instance: 'node-object-field_plate_dimensions'.
  $field_instances['node-object-field_plate_dimensions'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 38,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'iit_crop_info' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'random_page' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 6,
      ),
      'related_works' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_plate_dimensions',
    'label' => 'Plate Dimensions',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'node-object-field_print_notes'.
  $field_instances['node-object-field_print_notes'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 53,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 20,
      ),
      'iit_crop_info' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'random_page' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 19,
      ),
      'related_works' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_print_notes',
    'label' => 'Print Notes',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'node-object-field_print_type'.
  $field_instances['node-object-field_print_type'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 34,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 5,
      ),
      'iit_crop_info' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 28,
      ),
      'random_page' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 2,
      ),
      'related_work' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 31,
      ),
      'related_works' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 26,
      ),
      'search_result' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 45,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 54,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_print_type',
    'label' => 'Print type',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'options_select',
      'weight' => 25,
    ),
  );

  // Exported field_instance: 'node-object-field_printmaker'.
  $field_instances['node-object-field_printmaker'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 51,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 24,
      ),
      'iit_crop_info' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 42,
      ),
      'random_page' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 17,
      ),
      'related_work' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 41,
      ),
      'related_works' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 36,
      ),
      'search_result' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 56,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 53,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_printmaker',
    'label' => 'Printmaker',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'options_select',
      'weight' => 27,
    ),
  );

  // Exported field_instance: 'node-object-field_provenance'.
  $field_instances['node-object-field_provenance'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'field_collection',
        'settings' => array(
          'conditions' => array(),
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_fields',
        'weight' => 41,
      ),
      'iit_crop_info' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 53,
      ),
      'random_page' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 37,
      ),
      'related_work' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 52,
      ),
      'related_works' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 43,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 30,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 21,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_provenance',
    'label' => 'Provenance',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 36,
    ),
  );

  // Exported field_instance: 'node-object-field_provenance_temporary'.
  $field_instances['node-object-field_provenance_temporary'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 33,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 42,
      ),
      'iit_crop_info' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 52,
      ),
      'random_page' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 36,
      ),
      'related_work' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 51,
      ),
      'related_works' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 53,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 40,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 20,
      ),
    ),
    'entity_type' => 'node',
    'field_label_plurals_singular' => '',
    'field_name' => 'field_provenance_temporary',
    'label' => 'Provenance Verbatim',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 37,
    ),
  );

  // Exported field_instance: 'node-object-field_publisher'.
  $field_instances['node-object-field_publisher'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 52,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 25,
      ),
      'iit_crop_info' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 43,
      ),
      'random_page' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 18,
      ),
      'related_work' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 42,
      ),
      'related_works' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 37,
      ),
      'search_result' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 57,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 52,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_publisher',
    'label' => 'Publisher',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'options_select',
      'weight' => 28,
    ),
  );

  // Exported field_instance: 'node-object-field_related_works'.
  $field_instances['node-object-field_related_works'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 23,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'node_reference',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'node_reference_default',
        'weight' => 38,
      ),
      'iit_crop_info' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 26,
      ),
      'random_page' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22,
      ),
      'related_work' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 29,
      ),
      'related_works' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 36,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 56,
      ),
    ),
    'entity_type' => 'node',
    'field_label_plurals_singular' => 'Related Work',
    'field_name' => 'field_related_works',
    'label' => 'Related Works',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'node_reference',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'autocomplete_path' => 'node_reference/autocomplete',
        'size' => 60,
      ),
      'type' => 'node_reference_autocomplete',
      'weight' => 56,
    ),
  );

  // Exported field_instance: 'node-object-field_series'.
  $field_instances['node-object-field_series'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 55,
      ),
      'diff_standard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'iit_crop_info' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'random_page' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'related_works' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_label_plurals_singular' => '',
    'field_name' => 'field_series',
    'label' => 'Series',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 1,
      ),
      'type' => 'options_select',
      'weight' => 55,
    ),
  );

  // Exported field_instance: 'node-object-field_signature'.
  $field_instances['node-object-field_signature'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 43,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 17,
      ),
      'iit_crop_info' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 32,
      ),
      'random_page' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'related_work' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 36,
      ),
      'related_works' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 31,
      ),
      'search_result' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 51,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 31,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_signature',
    'label' => 'Signature',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 16,
    ),
  );

  // Exported field_instance: 'node-object-field_signature_location'.
  $field_instances['node-object-field_signature_location'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 44,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 18,
      ),
      'iit_crop_info' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 33,
      ),
      'random_page' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 11,
      ),
      'related_work' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 37,
      ),
      'related_works' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 32,
      ),
      'search_result' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 52,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 39,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_signature_location',
    'label' => 'Signature location',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 17,
    ),
  );

  // Exported field_instance: 'node-object-field_smallest_dimension'.
  $field_instances['node-object-field_smallest_dimension'] = array(
    'bundle' => 'object',
    'default_value' => array(),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 39,
      ),
      'diff_standard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'iit_crop_info' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'random_page' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'related_works' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_label_plurals_singular' => '',
    'field_name' => 'field_smallest_dimension',
    'label' => 'Smallest Dimension',
    'required' => 0,
    'settings' => array(
      'prefix' => '',
      'read-only' => FALSE,
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'mathfield',
      'settings' => array(),
      'type' => 'mathfield_markup',
      'weight' => 16,
    ),
  );

  // Exported field_instance: 'node-object-field_source_info'.
  $field_instances['node-object-field_source_info'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '(For internal reference only; not visible to end users)',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 27,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'link',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'link_default',
        'weight' => 44,
      ),
      'iit_crop_info' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 46,
      ),
      'random_page' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 31,
      ),
      'related_work' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 45,
      ),
      'related_works' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 47,
      ),
      'search_result' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 33,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_source_info',
    'label' => 'Source',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => '_blank',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 200,
      ),
      'enable_tokens' => 0,
      'rel_remove' => 'default',
      'title' => 'optional',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 255,
      'title_value' => '',
      'url' => 'optional',
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 17,
    ),
  );

  // Exported field_instance: 'node-object-field_states'.
  $field_instances['node-object-field_states'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 35,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 21,
      ),
      'iit_crop_info' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 29,
      ),
      'random_page' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'related_work' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 32,
      ),
      'related_works' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 27,
      ),
      'search_result' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 46,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 34,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_states',
    'label' => 'States',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 26,
    ),
  );

  // Exported field_instance: 'node-object-field_support'.
  $field_instances['node-object-field_support'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 41,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 15,
      ),
      'iit_crop_info' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 3,
      ),
      'random_page' => array(
        'label' => 'inline',
        'module' => 'taxonomy',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 8,
      ),
      'related_work' => array(
        'label' => 'hidden',
        'module' => 'taxonomy',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'taxonomy_term_reference_plain',
        'weight' => 5,
      ),
      'related_works' => array(
        'label' => 'hidden',
        'module' => 'taxonomy',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'taxonomy_term_reference_plain',
        'weight' => 5,
      ),
      'search_result' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 49,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'taxonomy',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'taxonomy_term_reference_plain',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_support',
    'label' => 'Support',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'options_select',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'node-object-field_support_marks'.
  $field_instances['node-object-field_support_marks'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 45,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 16,
      ),
      'iit_crop_info' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 31,
      ),
      'random_page' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 9,
      ),
      'related_work' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 35,
      ),
      'related_works' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 30,
      ),
      'search_result' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 50,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 40,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_support_marks',
    'label' => 'Support Marks',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 18,
    ),
  );

  // Exported field_instance: 'node-object-field_support_remarks'.
  $field_instances['node-object-field_support_remarks'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 42,
      ),
      'diff_standard' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'iit_crop_info' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'random_page' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'related_works' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_label_plurals_singular' => '',
    'field_name' => 'field_support_remarks',
    'label' => 'Support Remarks',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 15,
    ),
  );

  // Exported field_instance: 'node-object-field_timeline_date'.
  $field_instances['node-object-field_timeline_date'] = array(
    'bundle' => 'object',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 32,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'date',
        'settings' => array(
          'conditions' => array(),
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => FALSE,
          'show_repeat_rule' => 'show',
        ),
        'type' => 'date_default',
        'weight' => 9,
      ),
      'iit_crop_info' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 51,
      ),
      'random_page' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 35,
      ),
      'related_work' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 50,
      ),
      'related_works' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 52,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 39,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 19,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_timeline_date',
    'label' => 'Timeline Date',
    'required' => 0,
    'settings' => array(
      'default_value' => 'blank',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'display_all_day' => 0,
        'increment' => 15,
        'input_format' => 'm/d/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'repeat_collapsed' => 0,
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_text',
      'weight' => 20,
    ),
  );

  // Exported field_instance: 'node-object-field_year'.
  $field_instances['node-object-field_year'] = array(
    'bundle' => 'object',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'partial_date',
        'settings' => array(
          'component_settings' => array(
            'components' => array(
              'approx' => array(
                'value' => 'ca.',
                'weight' => -10,
              ),
              'c1' => array(
                'value' => '',
                'weight' => -2,
              ),
              'c2' => array(
                'value' => '',
                'weight' => -1,
              ),
              'c3' => array(
                'value' => '',
                'weight' => 0,
              ),
              'day' => array(
                'empty' => '',
                'format' => 'j',
                'weight' => -8,
              ),
              'hour' => array(
                'empty' => '',
                'format' => 'h',
                'weight' => -6,
              ),
              'minute' => array(
                'empty' => '',
                'format' => 'i',
                'weight' => -5,
              ),
              'month' => array(
                'empty' => '',
                'format' => 'M',
                'weight' => -9,
              ),
              'second' => array(
                'empty' => '',
                'format' => 's',
                'weight' => -4,
              ),
              'timezone' => array(
                'empty' => '',
                'format' => 'T',
                'weight' => -3,
              ),
              'year' => array(
                'empty' => '',
                'format' => 'Y-ce',
                'weight' => -7,
              ),
            ),
            'display' => array(
              'day' => 'estimate_label',
              'hour' => 'estimate_label',
              'minute' => 'estimate_label',
              'month' => 'estimate_label',
              'second' => 'estimate_label',
              'timezone' => 'date_only',
              'year' => 'estimate_label',
            ),
            'meridiem' => 'a',
            'separator' => array(
              'date' => ' ',
              'datetime' => ' ',
              'other' => ' ',
              'range' => '',
              'time' => ':',
            ),
            'year_designation' => 'bce',
          ),
          'conditions' => array(),
          'format' => 'medium',
          'use_override' => 'short_long',
        ),
        'type' => 'partial_date_default',
        'weight' => 47,
      ),
      'diff_standard' => array(
        'label' => 'inline',
        'module' => 'partial_date',
        'settings' => array(
          'component_settings' => array(),
          'conditions' => array(),
          'format' => 'medium',
          'use_override' => 'none',
        ),
        'type' => 'partial_date_default',
        'weight' => 7,
      ),
      'iit_crop_info' => array(
        'label' => 'hidden',
        'module' => 'partial_date',
        'settings' => array(
          'component_settings' => array(),
          'conditions' => array(),
          'format' => 'medium',
          'use_override' => 'none',
        ),
        'type' => 'partial_date_default',
        'weight' => 0,
      ),
      'random_page' => array(
        'label' => 'inline',
        'module' => 'partial_date',
        'settings' => array(
          'component_settings' => array(),
          'conditions' => array(),
          'format' => 'medium',
          'use_override' => 'none',
        ),
        'type' => 'partial_date_default',
        'weight' => 13,
      ),
      'related_work' => array(
        'label' => 'hidden',
        'module' => 'partial_date',
        'settings' => array(
          'component_settings' => array(),
          'conditions' => array(),
          'format' => 'medium',
          'use_override' => 'none',
        ),
        'type' => 'partial_date_default',
        'weight' => 2,
      ),
      'related_works' => array(
        'label' => 'hidden',
        'module' => 'partial_date',
        'settings' => array(
          'component_settings' => array(),
          'conditions' => array(),
          'format' => 'medium',
          'use_override' => 'none',
        ),
        'type' => 'partial_date_default',
        'weight' => 3,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'partial_date',
        'settings' => array(
          'component_settings' => array(),
          'conditions' => array(),
          'format' => 'medium',
          'use_override' => 'none',
        ),
        'type' => 'partial_date_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'partial_date',
        'settings' => array(
          'component_settings' => array(),
          'conditions' => array(),
          'format' => 'medium',
          'use_override' => 'none',
        ),
        'type' => 'partial_date_default',
        'weight' => 27,
      ),
    ),
    'entity_type' => 'node',
    'field_label_plurals_singular' => '',
    'field_name' => 'field_year',
    'label' => 'Year',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'partial_date',
      'settings' => array(
        0 => FALSE,
        'estimates' => array(
          'from' => array(
            'day' => 0,
            'hour' => 0,
            'minute' => 0,
            'month' => 0,
            'second' => 0,
            'year' => 0,
          ),
          'to' => array(
            'day' => 0,
            'hour' => 0,
            'minute' => 0,
            'month' => 0,
            'second' => 0,
            'year' => 0,
          ),
        ),
        'granularity' => array(
          'from' => array(
            'day' => 0,
            'hour' => 0,
            'minute' => 0,
            'month' => 0,
            'second' => 0,
            'timezone' => 0,
            'year' => 'year',
          ),
          'to' => array(
            'day' => 0,
            'hour' => 0,
            'minute' => 0,
            'month' => 0,
            'second' => 0,
            'timezone' => 0,
            'year' => 'year',
          ),
        ),
        'help_txt' => array(
          'und' => array(
            '_remove' => '',
            'check_approximate' => '',
            'components' => '',
            'txt_long' => 'Longer description of date',
            'txt_short' => 'Description of date if it can\'t be expressed numerically',
          ),
        ),
        'hide_remove' => 1,
        'increments' => array(
          'minute' => 1,
          'second' => 1,
        ),
        'theme_overrides' => array(
          'check_approximate' => 1,
          'range_inline' => 0,
          'txt_long' => 0,
          'txt_short' => 1,
        ),
        'tz_handling' => 'none',
      ),
      'type' => 'partial_date',
      'weight' => 19,
    ),
  );

  // Exported field_instance: 'taxonomy_term-genre-field_example_image'.
  $field_instances['taxonomy_term-genre-field_example_image'] = array(
    'bundle' => 'genre',
    'deleted' => 0,
    'description' => 'An example image for each genre.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'conditions' => array(),
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_example_image',
    'label' => 'Example image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'genre',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'taxonomy_term-location_vocab-field_address'.
  $field_instances['taxonomy_term-location_vocab-field_address'] = array(
    'bundle' => 'location_vocab',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_address',
    'label' => 'Address',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 33,
    ),
  );

  // Exported field_instance: 'taxonomy_term-location_vocab-field_coordinates'.
  $field_instances['taxonomy_term-location_vocab-field_coordinates'] = array(
    'bundle' => 'location_vocab',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'geofield',
        'settings' => array(
          'conditions' => array(),
          'data' => 'full',
        ),
        'type' => 'geofield_wkt',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_coordinates',
    'label' => 'Coordinates',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'geocoder',
      'settings' => array(
        'delta_handling' => 'm_to_s',
        'geocoder_field' => 'field_address',
        'geocoder_handler' => 'google',
        'handler_settings' => array(
          'google' => array(
            'all_results' => 0,
            'geometry_type' => 'point',
            'reject_results' => array(
              'APPROXIMATE' => 0,
              'GEOMETRIC_CENTER' => 0,
              'RANGE_INTERPOLATED' => 0,
              'ROOFTOP' => 0,
            ),
          ),
        ),
      ),
      'type' => 'geocoder',
      'weight' => 32,
    ),
  );

  // Exported field_instance: 'taxonomy_term-object_type-field_example_image'.
  $field_instances['taxonomy_term-object_type-field_example_image'] = array(
    'bundle' => 'object_type',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'conditions' => array(),
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_example_image',
    'label' => 'Example image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'media',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 32,
    ),
  );

  // Exported field_instance: 'taxonomy_term-tag-field_example_image'.
  $field_instances['taxonomy_term-tag-field_example_image'] = array(
    'bundle' => 'tag',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'conditions' => array(),
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_example_image',
    'label' => 'Example image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 1669,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 32,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('(For internal reference only; not visible to end users)');
  t('Address');
  t('An example image for each genre.');
  t('Autocomplete uses long titles only; to match a short title with a long title, search the <a href="/bibliography" target="_blank">list of bibliographic short titles</a>.');
  t('Bailey/Walker');
  t('Biblio Reference');
  t('Bibliography');
  t('Check this if no dimension values are available');
  t('Circa?');
  t('Collaborator Notes');
  t('Collaborators');
  t('Collection type');
  t('Collectors/Patrons');
  t('Coordinates');
  t('Copies and Variants');
  t('Copy/Variant Image');
  t('Curatorial File');
  t('Curatorial Files');
  t('Description');
  t('Diameter');
  t('Equipment Used');
  t('Ertz 1979');
  t('Ertz 2008-10');
  t('Example image');
  t('Exhibition History');
  t('External resources');
  t('File Type');
  t('For objects in private collections, choose Unavailable > Private Collection/Art Market, and put any known details about owner or most recent sale below in the "Location Notes" field. For objects in public collections, choose Country > City > Museum, and put any inv./cat. nos. below in the "Location Notes" field. For missing objects, choose Unavailable > Missing/Destroyed.');
  t('For privately owned objects on loan to public collections, choose "Public."');
  t('Further Inscription');
  t('Genre');
  t('Height');
  t('Hollstein No.');
  t('Location');
  t('Location Notes');
  t('Medium');
  t('Medium Remarks');
  t('No Dimensions');
  t('Notes');
  t('Object Image');
  t('Object Type');
  t('Original Format');
  t('Other Authorities');
  t('Our Attribution');
  t('Plate Dimensions');
  t('Print Notes');
  t('Print type');
  t('Printmaker');
  t('Provenance');
  t('Provenance Date');
  t('Provenance Location');
  t('Provenance Text');
  t('Provenance Verbatim');
  t('Publisher');
  t('Reference Notes');
  t('Related Works');
  t('Research Date');
  t('Researchers');
  t('Series');
  t('Signature');
  t('Signature location');
  t('Smallest Dimension');
  t('Source');
  t('States');
  t('Support');
  t('Support Marks');
  t('Support Remarks');
  t('Tags');
  t('This should be checked if "Approximation only" above is checked');
  t('Timeline Date');
  t('Use this field to record inv./cat. numbers, dealer/auction details for last known sale, or former location if the object has been destroyed.');
  t('Width');
  t('Year');

  return $field_instances;
}
