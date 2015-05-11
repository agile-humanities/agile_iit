<?php

/**
 * @file
 * Theming and preprocess functions.
 */

/**
 * Implements hook_preprocess().
 */
function agile_iit_preprocess_agile_iit(array &$variables) {
  $path = drupal_get_path('module', 'agile_iit');\
  drupal_add_js("$path/js/jquery-1.7.2.js");
  drupal_add_js("$path/js/jquery-ui.js");
  drupal_add_js("$path/js/jquery.Jcrop.js");
  drupal_add_js("$path/js/iit_ui.js");
  drupal_add_js("$path/js/iit_init.js");
  drupal_add_js("$path/js/zoomy.js");
  drupal_add_css("$path/css/zoomy.css");
  drupal_add_css("$path/css/style2.css");
  drupal_add_css("$path/js/themes/base/jquery-ui.css");
  drupal_set_title(t('Image Tool'));
}