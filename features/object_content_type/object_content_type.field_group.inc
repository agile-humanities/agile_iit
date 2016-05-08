<?php
/**
 * @file
 * object_content_type.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function object_content_type_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_additionalinfo|node|object|default';
  $field_group->group_name = 'group_additionalinfo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'object';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Additional Information',
    'weight' => '7',
    'children' => array(
      0 => 'group_discussion',
      1 => 'group_bibliography',
      2 => 'group_related_works',
      3 => 'group_curatorialinfo',
      4 => 'group_exhibition',
      5 => 'group_copiesandvariants',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-additionalinfo field-group-htabs',
      ),
    ),
  );
  $field_groups['group_additionalinfo|node|object|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_additionalinfo|node|object|random_page';
  $field_group->group_name = 'group_additionalinfo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'object';
  $field_group->mode = 'random_page';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Additional Information',
    'weight' => '9',
    'children' => array(
      0 => 'group_discussion',
      1 => 'group_bibliography',
      2 => 'group_related_works',
      3 => 'group_curatorialinfo',
      4 => 'group_exhibition',
      5 => 'group_copiesandvariants',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-additionalinfo field-group-htabs',
      ),
    ),
  );
  $field_groups['group_additionalinfo|node|object|random_page'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_attribution|node|object|default';
  $field_group->group_name = 'group_attribution';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'object';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Attribution',
    'weight' => '3',
    'children' => array(
      0 => 'field_attribution',
      1 => 'field_attribution_authority',
      2 => 'attribution_disclaimer',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Attribution',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-attribution field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_attribution|node|object|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_attribution|node|object|form';
  $field_group->group_name = 'group_attribution';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'object';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_objectinfo';
  $field_group->data = array(
    'label' => 'Attribution',
    'weight' => '47',
    'children' => array(
      0 => 'field_attribution',
      1 => 'field_attribution_authority',
      2 => 'field_ertz_1979',
      3 => 'field_ertz_2008_10',
      4 => 'field_bailey_walker',
      5 => 'field_hollstein_no',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Attribution',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-attribution field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_attribution|node|object|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_attribution|node|object|random_page';
  $field_group->group_name = 'group_attribution';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'object';
  $field_group->mode = 'random_page';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Attribution',
    'weight' => '4',
    'children' => array(
      0 => 'field_attribution',
      1 => 'field_attribution_authority',
      2 => 'attribution_disclaimer',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Attribution',
      'instance_settings' => array(
        'classes' => 'group-attribution field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_attribution|node|object|random_page'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bibliography|node|object|default';
  $field_group->group_name = 'group_bibliography';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'object';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_additionalinfo';
  $field_group->data = array(
    'label' => 'Bibliography',
    'weight' => '28',
    'children' => array(
      0 => 'field_bibliography_items',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Bibliography',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-bibliography field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_bibliography|node|object|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bibliography|node|object|form';
  $field_group->group_name = 'group_bibliography';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'object';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_objectinfo';
  $field_group->data = array(
    'label' => 'Bibliography',
    'weight' => '50',
    'children' => array(
      0 => 'field_bibliography_items',
      1 => 'field_bibliography',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-bibliography field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_bibliography|node|object|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bibliography|node|object|random_page';
  $field_group->group_name = 'group_bibliography';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'object';
  $field_group->mode = 'random_page';
  $field_group->parent_name = 'group_additionalinfo';
  $field_group->data = array(
    'label' => 'Bibliography',
    'weight' => '19',
    'children' => array(
      0 => 'field_bibliography_items',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Bibliography',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-bibliography field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_bibliography|node|object|random_page'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_categories|node|object|default';
  $field_group->group_name = 'group_categories';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'object';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tags',
    'weight' => '6',
    'children' => array(
      0 => 'field_categories',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Tags',
      'instance_settings' => array(
        'classes' => 'group-categories field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_categories|node|object|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_categories|node|object|random_page';
  $field_group->group_name = 'group_categories';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'object';
  $field_group->mode = 'random_page';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tags',
    'weight' => '8',
    'children' => array(
      0 => 'field_categories',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Tags',
      'instance_settings' => array(
        'classes' => 'group-categories field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_categories|node|object|random_page'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_collaborators|node|object|form';
  $field_group->group_name = 'group_collaborators';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'object';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_objectinfo';
  $field_group->data = array(
    'label' => 'Collaborators',
    'weight' => '45',
    'children' => array(
      0 => 'field_collaborator',
      1 => 'field_collaborator_notes',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Collaborators',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-collaborators field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_collaborators|node|object|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_curatorialinfo|node|object|form';
  $field_group->group_name = 'group_curatorialinfo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'object';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_objectinfo';
  $field_group->data = array(
    'label' => 'Curatorial Info',
    'weight' => '53',
    'children' => array(
      0 => 'field_curatorial_files',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Curatorial Info',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-curatorialinfo field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_curatorialinfo|node|object|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dating|node|object|form';
  $field_group->group_name = 'group_dating';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'object';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_objectinfo';
  $field_group->data = array(
    'label' => 'Dating',
    'weight' => '41',
    'children' => array(
      0 => 'field_year',
      1 => 'field_timeline_date',
      2 => 'field_circa',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Dating',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-dating field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_dating|node|object|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dimensions|node|object|form';
  $field_group->group_name = 'group_dimensions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'object';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_objectinfo';
  $field_group->data = array(
    'label' => 'Dimensions',
    'weight' => '42',
    'children' => array(
      0 => 'field_dimensions_height',
      1 => 'field_dimensions_width',
      2 => 'field_diameter',
      3 => 'field_plate_dimensions',
      4 => 'field_no_dimensions',
      5 => 'field_smallest_dimension',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Dimensions',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-dimensions field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_dimensions|node|object|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_exhibition|node|object|default';
  $field_group->group_name = 'group_exhibition';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'object';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_additionalinfo';
  $field_group->data = array(
    'label' => 'Exhibition History',
    'weight' => '29',
    'children' => array(
      0 => 'field_exhibition',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-exhibition field-group-htab',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_exhibition|node|object|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_exhibition|node|object|form';
  $field_group->group_name = 'group_exhibition';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'object';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_objectinfo';
  $field_group->data = array(
    'label' => 'Exhibition History',
    'weight' => '51',
    'children' => array(
      0 => 'field_exhibition',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Exhibition History',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-exhibition field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_exhibition|node|object|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_exhibition|node|object|random_page';
  $field_group->group_name = 'group_exhibition';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'object';
  $field_group->mode = 'random_page';
  $field_group->parent_name = 'group_additionalinfo';
  $field_group->data = array(
    'label' => 'Exhibition History',
    'weight' => '20',
    'children' => array(
      0 => 'field_exhibition',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-exhibition field-group-htab',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_exhibition|node|object|random_page'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_externallinks|node|object|default';
  $field_group->group_name = 'group_externallinks';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'object';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'External Links',
    'weight' => '4',
    'children' => array(
      0 => 'field_external_resources',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'External Links',
      'instance_settings' => array(
        'classes' => 'group-externallinks field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_externallinks|node|object|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_externallinks|node|object|form';
  $field_group->group_name = 'group_externallinks';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'object';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_objectinfo';
  $field_group->data = array(
    'label' => 'External Links',
    'weight' => '49',
    'children' => array(
      0 => 'field_external_resources',
      1 => 'field_source_info',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'External Links',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-externallinks field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_externallinks|node|object|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_externallinks|node|object|random_page';
  $field_group->group_name = 'group_externallinks';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'object';
  $field_group->mode = 'random_page';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'External Links',
    'weight' => '5',
    'children' => array(
      0 => 'field_external_resources',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'External Links',
      'instance_settings' => array(
        'classes' => 'group-externallinks field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_externallinks|node|object|random_page'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general_information|node|object|default';
  $field_group->group_name = 'group_general_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'object';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General Info',
    'weight' => '2',
    'children' => array(
      0 => 'field_signature',
      1 => 'field_inscriptions',
      2 => 'field_support_marks',
      3 => 'field_signature_location',
      4 => 'field_medium',
      5 => 'field_states',
      6 => 'field_object_type',
      7 => 'field_genre',
      8 => 'field_support',
      9 => 'field_printmaker',
      10 => 'field_publisher',
      11 => 'field_print_type',
      12 => 'field_collaborator',
      13 => 'field_year',
      14 => 'field_collaborator_notes',
      15 => 'field_print_notes',
      16 => 'field_plate_dimensions',
      17 => 'field_patron',
      18 => 'field_series',
      19 => 'field_medium_term',
      20 => 'field_support_remarks',
      21 => 'dimensions',
      22 => 'location_lastsold',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'General Info',
      'instance_settings' => array(
        'classes' => 'group-general-information field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_general_information|node|object|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general_information|node|object|random_page';
  $field_group->group_name = 'group_general_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'object';
  $field_group->mode = 'random_page';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General Info',
    'weight' => '3',
    'children' => array(
      0 => 'field_signature',
      1 => 'field_inscriptions',
      2 => 'field_support_marks',
      3 => 'field_signature_location',
      4 => 'field_medium',
      5 => 'field_states',
      6 => 'field_object_type',
      7 => 'field_genre',
      8 => 'field_support',
      9 => 'field_printmaker',
      10 => 'field_publisher',
      11 => 'field_print_type',
      12 => 'field_collaborator',
      13 => 'field_year',
      14 => 'field_collaborator_notes',
      15 => 'field_plate_dimensions',
      16 => 'field_patron',
      17 => 'dimensions',
      18 => 'location_lastsold',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'General Info',
      'instance_settings' => array(
        'classes' => 'group-general-information field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_general_information|node|object|random_page'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_generalinfo|node|object|form';
  $field_group->group_name = 'group_generalinfo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'object';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_objectinfo';
  $field_group->data = array(
    'label' => 'General Info',
    'weight' => '40',
    'children' => array(
      0 => 'field_medium',
      1 => 'field_object_type',
      2 => 'field_genre',
      3 => 'field_categories',
      4 => 'field_object_image',
      5 => 'field_medium_term',
      6 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'General Info',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-generalinfo field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_generalinfo|node|object|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_inscriptions|node|object|form';
  $field_group->group_name = 'group_inscriptions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'object';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_objectinfo';
  $field_group->data = array(
    'label' => 'Support/Inscriptions',
    'weight' => '44',
    'children' => array(
      0 => 'field_signature',
      1 => 'field_inscriptions',
      2 => 'field_support_marks',
      3 => 'field_signature_location',
      4 => 'field_support',
      5 => 'field_support_remarks',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Support/Inscriptions',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-inscriptions field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_inscriptions|node|object|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_location|node|object|form';
  $field_group->group_name = 'group_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'object';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_objectinfo';
  $field_group->data = array(
    'label' => 'Location',
    'weight' => '43',
    'children' => array(
      0 => 'field_collection_type',
      1 => 'field_location',
      2 => 'field_location_notes',
      3 => 'field_patron',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Location',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-location field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_location|node|object|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_objectinfo|node|object|form';
  $field_group->group_name = 'group_objectinfo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'object';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Object Info Group',
    'weight' => '0',
    'children' => array(
      0 => 'group_location',
      1 => 'group_provenance',
      2 => 'group_attribution',
      3 => 'group_exhibition',
      4 => 'group_generalinfo',
      5 => 'group_printinfo',
      6 => 'group_externallinks',
      7 => 'group_bibliography',
      8 => 'group_relatedworks',
      9 => 'group_curatorialinfo',
      10 => 'group_collaborators',
      11 => 'group_inscriptions',
      12 => 'group_dimensions',
      13 => 'group_dating',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-objectinfo field-group-tabs',
      ),
    ),
  );
  $field_groups['group_objectinfo|node|object|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_printinfo|node|object|form';
  $field_group->group_name = 'group_printinfo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'object';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_objectinfo';
  $field_group->data = array(
    'label' => 'Print Info',
    'weight' => '46',
    'children' => array(
      0 => 'field_states',
      1 => 'field_printmaker',
      2 => 'field_publisher',
      3 => 'field_print_type',
      4 => 'field_print_notes',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Print Info',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-printinfo field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_printinfo|node|object|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_provenance|node|object|form';
  $field_group->group_name = 'group_provenance';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'object';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_objectinfo';
  $field_group->data = array(
    'label' => 'Provenance',
    'weight' => '48',
    'children' => array(
      0 => 'field_provenance_temporary',
      1 => 'field_provenance',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Provenance',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-provenance field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_provenance|node|object|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_relatedworks|node|object|form';
  $field_group->group_name = 'group_relatedworks';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'object';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_objectinfo';
  $field_group->data = array(
    'label' => 'Related Works',
    'weight' => '52',
    'children' => array(
      0 => 'field_related_works',
      1 => 'field_copies_and_variants',
      2 => 'field_series',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Related Works',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-relatedworks field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_relatedworks|node|object|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Additional Information');
  t('Attribution');
  t('Bibliography');
  t('Collaborators');
  t('Curatorial Info');
  t('Dating');
  t('Dimensions');
  t('Exhibition History');
  t('External Links');
  t('General Info');
  t('Location');
  t('Object Info Group');
  t('Print Info');
  t('Provenance');
  t('Related Works');
  t('Support/Inscriptions');
  t('Tags');

  return $field_groups;
}
