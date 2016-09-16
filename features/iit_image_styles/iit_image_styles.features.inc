<?php
/**
 * @file
 * iit_image_styles.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function iit_image_styles_image_default_styles() {
  $styles = array();

  // Exported image style: iit-1200.
  $styles['iit-1200'] = array(
    'label' => 'iit-1200',
    'effects' => array(
      4 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1200,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: iit-200.
  $styles['iit-200'] = array(
    'label' => 'iit-200',
    'effects' => array(
      4 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 200,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: iit-400.
  $styles['iit-400'] = array(
    'label' => 'iit-400',
    'effects' => array(
      3 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 400,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: iit-600.
  $styles['iit-600'] = array(
    'label' => 'iit-600',
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 600,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: iit-800.
  $styles['iit-800'] = array(
    'label' => 'iit-800',
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 800,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
