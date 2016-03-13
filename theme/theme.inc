<?php

/**
 * @file
 * Theming and preprocess functions.
 */

/**
 * Implements hook_preprocess().
 */
function agile_iit_preprocess_agile_iit(array &$variables) {
  $variables['placeholder_text'] = t("Drag image here");
  agile_iit_add_requirements();
}

/**
 * Implements hook_preprocess().
 */
function agile_iit_preprocess_agile_iit_crop(array &$variables) {
  agile_iit_add_requirements();
}

/**
 * Implements hook_preprocess().
 */
function agile_iit_preprocess_agile_agile_iit_cropped_view(array &$variables) {
  agile_iit_add_requirements();
}

/**
 * Implements hook_preprocess().
 */
function agile_iit_preprocess_agile_iit_twoviews(array &$variables) {
  agile_iit_add_requirements();
}

/*
 * Shared function for preprocess calls.
 */

function agile_iit_add_requirements() {
  $path = drupal_get_path('module', 'agile_iit');
  drupal_add_js("$path/js/jquery-1.7.2.js");
  drupal_add_js("$path/js/jquery-ui.js");
  drupal_add_js("$path/js/jquery.Jcrop.js");
  drupal_add_js("http://cdn.jsdelivr.net/jquery.ui.rotatable/1.0.1/jquery.ui.rotatable.min.js");
  drupal_add_js("$path/js/iit_ui.js");
  drupal_add_js("$path/js/zoomy.js");
  drupal_add_css("$path/css/zoomy.css");
  drupal_add_css("$path/css/style2.css");
  drupal_add_css("$path/js/themes/base/jquery-ui.css");
  drupal_add_js("$path/js/comparison_viewer.js");
  drupal_add_js("$path/js/gridform.js");
  drupal_set_title(t('Image Tool'));
}
