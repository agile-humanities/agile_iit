<?php

/**
 * @file
 * All IIT javascript driven callbacks.
 */

/**
 * Menu callback to make the Crop (Detail) Tool Workspace.
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
 *   w: width of the cropping rectangle
 *   h: height of the cropping rectangle
 *   x: x-offset of the leftmost side of the cropping rectangle (from the parent image)
 *   y: y-offset of the top side of the cropping rectangle (from the parent image).
 *   c_w: width of the #crop_target element (note: may be different from image that user drew on).
 *   c_h: height of the #crop_target element (note: may be different from image that user drew on).
 *   src: the source of the image to use as the cropping source. (currently comes out of the original cropform).
 */
function agile_iit_crop_tool_callback() {

  if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $n = rand(0, 100000); // It's highly unlikely but possible that we'll overwrite something that we're using.
    $file_dir = 'public://';
    $real_path = drupal_realpath("$file_dir");
    $real_url = file_create_url($file_dir);
    $cropfilepath = "$real_path/{$n}.jpg";
    $cropurl = "$real_url/{$n}.jpg"; // All that was to make the filename for the cropped section that we're about to make.
    $targ_w = filter_input(INPUT_POST, 'w');
    $targ_h = filter_input(INPUT_POST, 'h');
    $x = filter_input(INPUT_POST, 'x');
    $y = filter_input(INPUT_POST, 'y');
    $container_width = filter_input(INPUT_POST, 'c_w');
    $container_height = filter_input(INPUT_POST, 'c_h');
    $jpeg_quality = 90;
    $src = filter_input(INPUT_POST, 'src');

    $size = getimagesize($src); // is it possible that the src we pass as the cropping source is different from the image that the crop was drawn on? Yes;
    switch ($size["mime"]) {
      case "image/jpeg":
        $img_replacement = imagecreatefromjpeg($src);
        break;

      case "image/gif":
        $img_replacement = imagecreatefromgif($src);
        break;

      case "image/png":
        $img_replacement = imagecreatefrompng($src);
        break;

      default:
        $img_replacement = FALSE;
        break;
    }

    $ratio_width = $targ_w / $container_width; // Width of crop rectangle over width of #crop_source.
    $ratio_height = $targ_h / $container_height; // height of crop rectangle over height of #crop_source
    $ratio_width = round($ratio_width, 8); // Round to 8 decimal places...???!!!
    $ratio_height = round($ratio_height, 8);

    $source_imagex = imagesx($img_replacement); // why would this be different from the results of getimagesize() above?
    $source_imagey = imagesy($img_replacement);

    $dst_r = imagecreatetruecolor($targ_w, $targ_h); // Create an image resource sized to crop rectangle.
    $dst_r1 = imagecreatetruecolor($container_width, $container_height); // Create an image resource sized to the crop source.
    imagecopyresampled($dst_r1, $img_replacement, 0, 0, 0, 0, $container_width, $container_height, $source_imagex, $source_imagey); // copy the replacement image into this new image resource.
    //What i think this should do is copy the crop_target (however big) into an image the size of the image that the user drew a rectangle on.
    // But even then, our section would be the same res as the shrunken image that fits in half the window.
    imagecopy($dst_r, $dst_r1, 0, 0, filter_input(INPUT_POST, 'x'), filter_input(INPUT_POST, 'y'), filter_input(INPUT_POST, 'w'), filter_input(INPUT_POST, 'h'));
    imagejpeg($dst_r, $cropfilepath, $jpeg_quality); // Write this image as a jpg file to the filename we made at the top of this function.
    // Image created by imagejpeg is converted to Drupal managed file.
    $data = file_get_contents($cropfilepath);
    $file_object = file_save_data($data, "public://iit{$n}.jpg");
    $file_object->filemime = 'image/jpeg';
    $image_url = file_create_url($file_object->uri);
    unlink($cropfilepath);
    imagedestroy($dst_r1);
    imagedestroy($dst_r);
    $theme_args = array(
      'n' => $n, // The image id. So we can make the <img>'s #. Also so we can destroy it? :D
      'image_url' => $image_url, // use for src of this <img>
      'ratio_width' => $ratio_width, // Saved as data-ratiow, this is the width of the rectangle over the width of the image it was drawn on
      'ratio_height' => $ratio_height, // Saved as data-ratioh, this is the height of the rectangle over the height of the image it was drawn on.
    );
    echo theme('agile_iit_croptool', $theme_args);
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
 * Menu driven callback to push off image cropping.
 */
function agile_iit_image_cropper() {
  if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    /* Set up a place to put the cropped images. */
    $n = rand(0, 100000);
    $file_dir = 'public://';
    $real_path = drupal_realpath("$file_dir");
    $real_url = file_create_url($file_dir);
    $cropfilepath = "$real_path/{$n}.jpg";
    $cropurl = "$real_url/{$n}.jpg";

    $image1 = json_decode($_POST['image1']);
    $image2 = json_decode($_POST['image2']); // they already use image2.
    $section1 = json_decode($_POST['section1']);
    $section2 = json_decode($_POST['section2']);

    $image2_info = getimagesize($image2->src);
    switch ($image2_info["mime"]) {
      case "image/jpeg":
        $img_r = imagecreatefromjpeg($image2->src); //jpeg file
        break;
      case "image/gif":
        $img_r = imagecreatefromgif($image2->src); //gif file
        break;
      case "image/png":
        $img_r = imagecreatefrompng($image2->src); //png file
        break;
      default:
        $img_r = false;
        break;
    }

    /* This should be set in the Javascript at some point! */
    $image2->derivativeWidth_px = $image2_info[0];
    $image2->derivativeHeight_px = $image2_info[1];

    /* Deal with the fact that image2 is scaled: */
    $x = round($section2->xOffset_ratio * $image2->derivativeWidth_px);
    $y = round($section2->yOffset_ratio * $image2->derivativeHeight_px);
    $targ_w = round($section2->width_ratio * $image2->derivativeWidth_px);
    $targ_h = round($section2->height_ratio * $image2->derivativeHeight_px);

    $dst_r = ImageCreateTrueColor($targ_w, $targ_h);
    imagecopy($dst_r, $img_r, 0, 0, $x, $y, $targ_w, $targ_h);
    imagejpeg($dst_r, $cropfilepath, 100);

    /* Template this, and pull in the info that you want from the nodes. */
    $string = "<div>";
    $string .= "Section 1: ";
    $string .= "<img src='" . $section1->src . "'/> ";
    $string .= "<br>";
    $string .= "Section 2: ";
    $string .= "<img id='img" . $n . "' src='" . $cropurl . "'/> ";
    $string .= "<br/>";
    $string .= "</div>";


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
