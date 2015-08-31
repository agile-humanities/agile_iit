<?php

/**
 * @file
 * All IIT javascript driven callbacks.
 */

/**
 * Menu drive callback to view default images.
 */
function agile_iit_crop_callback() {
  if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $img1_src = filter_input(INPUT_POST, 'cf_img1');
    $img2_src = filter_input(INPUT_POST, 'cf_img2');
    $image_width = filter_input(INPUT_POST, 'container_width') * .48;
  }

  $size1 = getimagesize($img1_src);
  $image_width1 = $size1[0];
  $image_height1 = $size1[1];
  $ratio1 = $image_width1 / $image_width;
  $height1 = $image_height1 / $ratio1;

  $size2 = getimagesize($img2_src);
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

  echo theme('agile_iit_crop', $theme_args);
}

/**
 * Menu drive callback to view cropped images.
 */
function agile_iit_crop_tool_callback() {

  if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $n = rand(0, 100000);
    $file_dir = 'public://';
    $real_path = drupal_realpath("$file_dir");
    $real_url = file_create_url($file_dir);
    $cropfilepath = "$real_path/{$n}.jpg";
    $cropurl = "$real_url/{$n}.jpg";
    $targ_w = filter_input(INPUT_POST, 'w');
    $targ_h = filter_input(INPUT_POST, 'h');
    $x = filter_input(INPUT_POST, 'x');
    $y = filter_input(INPUT_POST, 'y');
    $container_width = filter_input(INPUT_POST, 'c_w');
    $container_height = filter_input(INPUT_POST, 'c_h');
    $jpeg_quality = 90;
    $src = filter_input(INPUT_POST, 'src');

    $size = getimagesize($src);
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

    $ratio_width = $targ_w / $size[0];
    $ratio_height = $targ_h / $size[1];
    $ratio_width = round($ratio_width, 8);
    $ratio_height = round($ratio_height, 8);

    $source_imagex = imagesx($img_replacement);
    $source_imagey = imagesy($img_replacement);

    $dst_r = imagecreatetruecolor($targ_w, $targ_h);
    $dst_r1 = imagecreatetruecolor($container_width, $container_height);
    imagecopyresampled($dst_r1, $img_replacement, 0, 0, 0, 0, $container_width, $container_height, $source_imagex, $source_imagey);
    imagecopy($dst_r, $dst_r1, 0, 0, filter_input(INPUT_POST, 'x'), filter_input(INPUT_POST, 'y'), filter_input(INPUT_POST, 'w'), filter_input(INPUT_POST, 'h'));
    imagejpeg($dst_r, $cropfilepath, $jpeg_quality);
    // Image created by imagejpeg is converted to Drupal managed file.
    $data = file_get_contents($cropfilepath);
    $file_object = file_save_data($data, "public://iit{$n}.jpg");
    $file_object->filemime = 'image/jpeg';
    $image_url = file_create_url($file_object->uri);
    unlink($cropfilepath);
    imagedestroy($dst_r1);
    imagedestroy($dst_r);
    $theme_args = array(
      'n' => $n,
      'image_url' => $image_url,
      'ratio_width' => $ratio_width,
      'ratio_height' => $ratio_height,
    );
    echo theme('agile_iit_croptool', $theme_args);
  }
}

/**
 * Menu driven callback to push off double image view.
 */
function agile_iit_twoviews() {

  if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $img1_src = filter_input(INPUT_POST, 'vf_img1');
    $img2_src = filter_input(INPUT_POST, 'vf_img2');
  }

  echo theme('agile_iit_twoviews', array(
    'img1_src' => $img1_src,
    'img2_src' => $img2_src,
    // Add the width here!
      )
  );
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
    $ratio_w = $targ_w / $size[0];
    $ratio_h = $targ_h / $size[1];
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
    imagecopy($dst_r, $img_r, 0, 0, $x, $y, $targ_w, $targ_h);
    imagejpeg($dst_r, $cropfilepath, $jpeg_quality);
    $string = "<div>";
    $string .= "<p><i>" . $title1 . "</i> (Full size of original is: " . $dimensions1 . ").<br>";
    $string .= "Section is approx." . $dim1H . "(H) x " . $dim1W . "(W) cm. </p>";
    $string .= "<img src='" . $sect_src . "'/>' ";
    $string .= "<br>";
    $string .= "<p><i>" . $title2 . "</i> (Full size of original is: " . $dimensions2 . "). <br>";
    $string .= "Section is approx." . $dim2H . "(H) x " . $dim2W . "(W) cm. </p>";
    $string .= "<img id='img" . $n . "' src='" . $cropurl . "'/>' ";
    $string .= "<br><br>";
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
