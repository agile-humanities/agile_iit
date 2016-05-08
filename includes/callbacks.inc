<?php

/**
 * @file
 * All IIT javascript driven callbacks.
 */

/**
 * Menu callback to make the Crop (Detail) Tool Workspace.
 * Input POST arguments should include:
 *   cf_img1: the absolute url of the image being displayed as image1.
 *   cf_img2: the absolute url of the image being displayed as image2.
 */
function agile_iit_crop_callback() {
  if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $theme_args = array(
      'img1_src' => filter_input(INPUT_POST, 'cf_img1'),
      'img2_src' => filter_input(INPUT_POST, 'cf_img2'),
     );
  echo theme('agile_iit_crop', $theme_args);
  }
}

/**
 * Menu callback to create a cropped (detail) section.
 *
 * Input POST arguments should include:
 *   width: width in pixels of the desired section
 *   id: an integer id unique to this cropping section
 *   src: the absolute url of the image to use as the cropping source.
 *   xOffset_ratio: the x-position of the left of the section as a ratio of the image width
 *   yOffset_ratio: the y-position of the top of the section as a ratio of the image height
 *   width_ratio: the width of the section as a ratio of the image width
 *   height_ratio: the height of the section as a ratio of the image height.
 *
 *   The last four parameters are normalized and are therefore floats between 0 and 1.
 */
function agile_iit_crop_tool_callback() {

  if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $src = filter_input(INPUT_POST, 'src', FILTER_SANITIZE_URL);
    $xOffset_ratio = filter_input(INPUT_POST, 'xOffset_ratio', FILTER_SANITIZE_NUMBER_FLOAT, FILTER_FLAG_ALLOW_FRACTION);
    $yOffset_ratio = filter_input(INPUT_POST, 'yOffset_ratio', FILTER_SANITIZE_NUMBER_FLOAT, FILTER_FLAG_ALLOW_FRACTION);
    $width_ratio = filter_input(INPUT_POST, 'width_ratio', FILTER_SANITIZE_NUMBER_FLOAT, FILTER_FLAG_ALLOW_FRACTION);
    $height_ratio = filter_input(INPUT_POST, 'height_ratio', FILTER_SANITIZE_NUMBER_FLOAT, FILTER_FLAG_ALLOW_FRACTION);
    $width = filter_input(INPUT_POST, 'width', FILTER_SANITIZE_NUMBER_INT);
    $sectionId = filter_input(INPUT_POST, 'id', FILTER_SANITIZE_NUMBER_INT);

    $cropped_image = agile_iit_create_cropped_image($src, $xOffset_ratio, $yOffset_ratio, $width_ratio, $height_ratio);
    // Scale to the width of the cropped section
    if ($cropped_image) {
      image_scale($cropped_image, $width, NULL, TRUE);
      image_save($cropped_image);
    }
    $image_url = file_create_url($cropped_image->source);

    $theme_args = array(
      'sectionId' => $sectionId, // The image id. So we can make unique <img id=X>.
      'image_url' => $image_url, // the src of the temp image that shows only the crop section.
      'ratio_width' => $width_ratio, // Saved as data-ratiow, this is the width of the rectangle over the width of the image it was drawn on
      'ratio_height' => $height_ratio, // Saved as data-ratioh, this is the height of the rectangle over the height of the image it was drawn on.
    );
    echo theme('agile_iit_croptool', $theme_args);
  }
}

/**
 * @param  xOffset_ratio: the position of the left-top corner of the desired section, as a fraction of 1
 * @param  yOffset_ratio: the position of the top of the desired section, as a fraction of 1
 * @param  width_ratio: the width of the desired section, as a fraction of 1
 * @param  height_ratio: the height of the desired section, as a fraction of 1
 * @param  src: the url of the image to crop. (e.g. sites/default/files/foo.jpg)
 *
 * returns $image, a Drupal image object.
 */
function agile_iit_create_cropped_image($src, $xOffset_ratio, $yOffset_ratio, $width_ratio, $height_ratio) {
  $src = agile_iit_get_local_path($src); // convert the url to a local path.
  $image = image_load($src);
  if (!$image) {
    watchdog('agile_iit', "Image could not be found: " . $src);
    return FALSE;
  }
  $x = round($xOffset_ratio * $image->info['width']);
  $y = round($yOffset_ratio * $image->info['height']);
  $w = round($width_ratio * $image->info['width']);
  $h = round($height_ratio * $image->info['height']);
  image_crop($image, $x, $y, $w, $h);

  // Create a unique, unguessable filename.
  $n = rand(0, 100000);
  $path = file_create_filename($n . ".jpg", "public://");

  $result = image_save($image, $path);
  $image = image_load($path);
  if ($result) {
    return $image;
  }
  else {
    watchdog('agile_iit', "Image could not be created.");
    return FALSE;
  }
}

/**
 * Menu driven callback to push off double image view.
 */
function agile_iit_twoviews() {

  if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $field = variable_get('iit_image_fields', 'field_image');
    $node1 = node_load(filter_input(INPUT_POST, 'node1'));
    $img1_src = file_create_url($node1->{$field}['und'][0]['uri']);
    $node2 = node_load(filter_input(INPUT_POST, 'node2'));
    $img2_src = file_create_url($node2->{$field}['und'][0]['uri']);
  }

  echo theme('agile_iit_twoviews', array(
    'img1_src' => $img1_src,
    'img2_src' => $img2_src,
      )
  );
}

/**
 * Callback to create the popup window of two cropped sections with details.
 */
function agile_iit_image_cropper() {
  if ($_SERVER['REQUEST_METHOD'] == 'POST') {

    $image1 = json_decode($_POST['image1']);
    $image2 = json_decode($_POST['image2']);
    $section1 = json_decode($_POST['section1']);
    $section2 = json_decode($_POST['section2']);
    $node1 = node_load($image1->nid);
    $node2 = node_load($image2->nid);


    // Create cropped section of image 1
    $section1->src = $image1->src_orig;
    $detail1 = agile_iit_create_cropped_image($section1->src, $section1->xOffset_ratio, $section1->yOffset_ratio, $section1->width_ratio, $section1->height_ratio);

    if ($section1->rotation_deg == 0) {
      // Create cropped section of image 2
      $section2->src = $image2->src_orig;
      $detail2 = agile_iit_create_cropped_image($section2->src, $section2->xOffset_ratio, $section2->yOffset_ratio, $section2->width_ratio, $section2->height_ratio);
    } else {
      $theta = deg2rad($section1->rotation_deg);
      $image = image_load(agile_iit_get_local_path($image2->src_orig));
      // Calculate the center of the section from the image. x_c for x from center.
      $x_c = $section2->xOffset_ratio + ($section2->width_ratio / 2) - 0.5;
      $y_c = $section2->yOffset_ratio + ($section2->height_ratio / 2) - 0.5;
      // Scale the x and y to the size of the original image.
      $x_c = $x_c * $image->info['width'];
      $y_c = $y_c * $image->info['height'];
      // Having rotated the entire original image, the section has rotated around the center by theta.
      $x_c1 = $x_c * cos(-$theta) - $y_c * sin(-$theta);
      $y_c1 = $x_c * sin(-$theta) + $y_c * cos(-$theta);
      // Scale the height and width of the rectangle.
      $w = $section2->width_ratio * $image->info['width'];
      $h = $section2->height_ratio * $image->info['height'];
      // Calculate the x, y offset of the top left corner of the rectangle from the top left corner of the rotated original image.
      $w_rotated_orig = $image->info['width'] * abs(cos($theta)) + $image->info['height'] * abs(sin($theta));
      $h_rotated_orig = $image->info['width'] * abs(sin($theta)) + $image->info['height'] * abs(cos($theta));
      $x = $w_rotated_orig / 2 + $x_c1 - $w / 2;
      $y = $h_rotated_orig / 2 + $y_c1 - $h / 2;
      // Actually rotate the image now that we've used the original dimensions
      image_rotate($image, -1 * $section1->rotation_deg);
      // Calculate the x,y offset
      image_crop($image, $x, $y, $w, $h);
      // Create a unique, unguessable filename.
      $n = rand(0, 100000);
      $path = file_create_filename($n . ".jpg", "public://");
      image_save($image, $path);
      $detail2 = image_load($path);
    }

    if (!($detail1 and $detail2)) {
      echo "Image sections could not be created. Please check Drupal logs.";
      return;
    }

    $width = 500;
    image_scale($detail1, $width, NULL, TRUE);
    image_save($detail1);
    image_scale($detail2, $width, NULL, TRUE);
    image_save($detail2);

    // Calculate approximate sizes based on real life dimensions.
    if (!isset($image1->realWidth_cm) or !isset($image1->realHeight_cm)) {
      $section1_dimensions = t("Dimensions not found.");
    }
    else {
      $section1_dimensions = "Section dimensions: " . round($image1->realWidth_cm * $section1->width_ratio, 2) .
        " cm x " . round($image1->realHeight_cm * $section1->height_ratio, 2) . " cm.";
    }
    if (!isset($image2->realWidth_cm) or !isset($image2->realHeight_cm)) {
      $section2_dimensions = t("Dimensions not found.");
    }
    else {
      $section2_dimensions = "Section dimensions: " . round($image2->realWidth_cm * $section2->width_ratio, 2) .
        " cm x " . round($image2->realHeight_cm * $section2->height_ratio, 2) . " cm.";
    }
    /* Template this, and pull in the info that you want from the nodes. */
    $node1_rendered = drupal_render(node_view($node1, 'iit_crop_info'));
    $node2_rendered = drupal_render(node_view($node2, 'iit_crop_info'));

    $string = "<table><tr>";
    $string .= "<td><img src='" . file_create_url($detail1->source) . "'/> </td>";
    $string .= "<td><img src='" . file_create_url($detail2->source) . "'/> </td>";
    $string .= "</tr><tr>";
    $string .= "<td>$section1_dimensions</td>";
    $string .= "<td>$section2_dimensions</td>";
    $string .= "</tr><tr>";
    $string .= "<td>" . $node1_rendered . "</td>";
    $string .= "<td>" . $node2_rendered . "</td>";
    $string .= "</tr></table>";
    $string .= "<h2> Save this comparison? </h2>";

    $form = drupal_get_form('agile_iit_save_comparison_form', $node1, $node2, $detail1, $detail2, $section1, $section2);
    $form['#action'] = 'agile/iit/savecomparison';
    $string .= drupal_render($form);

    echo $string;
  }
}


/**
 * Callback to return the URL of an image derivative.
 */
function agile_iit_image_derivative() {
  if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $path = filter_input(INPUT_POST, 'path');
    $style = 'iit-' . filter_input(INPUT_POST, 'size');
    $style = str_replace('px', '', $style);
    $url = image_style_url($style, $path);
    echo $url;
  }
}
