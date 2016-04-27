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
    $img1_src = filter_input(INPUT_POST, 'cf_img1');
    $img2_src = filter_input(INPUT_POST, 'cf_img2');
    $image_width = filter_input(INPUT_POST, 'container_width') * .48;
  }

  $size1 = getimagesize($img1_src);
  $image_width1 = $size1[0]; // Width in pixels of the image at cf_img1. Currently is an image derivative, so will be x00.
  $image_height1 = $size1[1]; // Height in pixels of the image at cf_img2
  $ratio1 = $image_width1 / $image_width; // The ratio of the cf_img1 image's actual width to the width we want to fit it in. Note that because we chose cf_img1 to fit in half the screen width, this might be less than 1
  $height1 = $image_height1 / $ratio1; // The calculated height of the image when its width is stretched(/shrunken) to image_width.

  $size2 = getimagesize($img2_src); // Same as img1.
  $image_width2 = $size2[0];
  $image_height2 = $size2[1];
  $ratio2 = $image_width2 / $image_width;
  $height2 = $image_height2 / $ratio2;

  $theme_args = array(
    'img1_src' => $img1_src,
    'img2_src' => $img2_src,
    'width' => $image_width,
    'height1' => $height1,
    'height2' => $height2,
  );

  echo theme('agile_iit_crop', $theme_args); // return a themed div that will be thrown in an overlay.
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

function agile_iit_get_image_dimensions() {
  $img1_src = filter_input(INPUT_POST, 'img1');
  $info1 = getimagesize($img1_src);
  $img2_src = filter_input(INPUT_POST, 'img2');
  $info2 = getimagesize($img2_src);
  $results = array(
    'image1_width' => $info1[0],
    'image1_height' => $info1[1],
    'image2_width' => $info2[0],
    'image2_height' => $info2[1],
  );
  echo json_encode($results);
}

/**
 * Menu driven callback to push off image cropping.
 */
function agile_iit_image_cropper() {
  if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $n = rand(0, 100000);
    $file_dir = 'public://';
    $real_path = drupal_realpath("$file_dir");
    $real_url = file_create_url($file_dir);
    $cropfilepath = "$real_path/{$n}.jpg";
    $cropurl = "$real_url/{$n}.jpg";

    $targ_w = $_POST['sectImgW'];
    $targ_h = $_POST['sectImgH'];
    $x = $_POST['x'];
    $y = $_POST['y'];
    //$c_w=$_POST['c_w'];
    //$c_h=$_POST['c_h'];
    $jpeg_quality = 90;
    $src = $_POST['image2'];
    $sect_src = $_POST['sectImg'];
    $sect_WRatio = $_POST['w1ratio'];
    $sect_HRatio = $_POST['h1ratio'];
    $img1dimW = $_POST['img1_dimW'];
    $img1dimH = $_POST['img1_dimH'];
    $img2dimW = $_POST['img2_dimW'];
    $img2dimH = $_POST['img2_dimH'];
    $title1 = $_POST['title1'];
    $title2 = $_POST['title2'];
    $dimensions1 = $_POST['dimensions1'];
    $dimensions2 = $_POST['dimensions2'];
    $support1 = $_POST['support1'];
    $support2 = $_POST['support2'];
    $date1 = $_POST['date1'];
    $date2 = $_POST['date2'];
    $image2w = $_POST['image2w'];
    $image2h = $_POST['image2h'];
    $size = getimagesize($src);
    switch ($size["mime"]) {
      case "image/jpeg":
        $img_r = imagecreatefromjpeg($src); //jpeg file
        break;
      case "image/gif":
        $img_r = imagecreatefromgif($src); //gif file
        break;
      case "image/png":
        $img_r = imagecreatefrompng($src); //png file
        break;
      default:
        $img_r = false;
        break;
    }
    $ratio_w = $targ_w / $image2w;
    $ratio_h = $targ_h / $image2h;
    $ratio_w = round($ratio_w, 8);
    $ratio_h = round($ratio_h, 8);
    $dim1W = (double) $sect_WRatio * $img1dimW;
    $dim1H = (double) $sect_HRatio * $img1dimH;
    $dim1W = round($dim1W, 2);
    $dim1H = round($dim1H, 2);
    $dim2W = (double) $ratio_w * $img2dimW;
    $dim2H = (double) $ratio_h * $img2dimH;
    $dim2W = round($dim2W, 2);
    $dim2H = round($dim2H, 2);
    $dst_r = ImageCreateTrueColor($targ_w, $targ_h);
    // Deal with the fact that image2 is scaled.
    $scale_factor_image_2 = $size[0] / $image2w;
    $x = round($x * $scale_factor_image_2);
    $y = round($y * $scale_factor_image_2);
    $targ_w = round($targ_w * $scale_factor_image_2);
    $targ_h = round($targ_h * $scale_factor_image_2);

    imagecopy($dst_r, $img_r, 0, 0, $x, $y, $targ_w, $targ_h);
    imagejpeg($dst_r, $cropfilepath, $jpeg_quality);
    $string = "<div>";
    $string .= "<div>Title: $title1</div>";
    $string .= "<div>Date: $date1</div>";
    $string .= "<div>Support: $support1</div>";
    $string .= "<div>Dimensions of the cropped section: $dim1W cm (W) x $dim1H cm (H)</div>";
    $string .= "<div>(Based off the original dimensions of the painting $dimensions1)</div>";
    $string .= "<img src='" . $sect_src . "'/>' ";
    $string .= "<br>";
    $string .= "<div>Title: $title2</div>";
    $string .= "<div>Date: $date2</div>";
    $string .= "<div>Support: $support2</div>";
    $string .= "<div>Dimensions of the cropped section: $dim2W cm (W) x $dim2H cm (H)</div>";
    $string .= "<div>(Based off the original dimensions of the painting $dimensions2)</div>";
    $string .= "<img id='img" . $n . "' src='" . $cropurl . "'/>' ";
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
