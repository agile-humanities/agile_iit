<?php

/**
 * Menu drive callback to view default images.
 */
function agile_iit_crop_callback() {
  if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $img1_src = $_POST['cf_img1'];
    $img2_src = $_POST['cf_img2'];
    $container_width = $_POST['container_width'];
  }

  $size1 = getimagesize($img1_src);
  $image_width1 = $size1[0];
  $image_height1 = $size1[1];
  $ratio1 = $image_width1 / $container_width;
  $width1 = $container_width;
  $height1 = $image_height1 / $ratio1;

  $size2 = getimagesize($img2_src);
  $image_width2 = $size2[0];
  $image_height2 = $size2[1];
  $ratio2 = $image_width2 / $container_width;
  $height2 = $image_height2 / $ratio2;

  $theme_args = array(
    'img1_src' => $img1_src,
    'img2_src' => $img2_src,
    'width' => $container_width,
    'height1' => $height1,
    'height2' => $height2,
  );

  return theme('agile_iit_crop', $theme_args);
}

/**
 * Menu drive callback to view cropped images.
 */
function agile_iit_crop_tool_callback() {

  /**
   * Jcrop image cropping plugin for jQuery  d
   * Example cropping script
   * @copyright 2008-2009 Kelly Hallman
   * More info: http://deepliquid.com/content/Jcrop_Implementation_Theory.html
   */
  if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $n = rand(0, 100000);
    $file_dir = 'public://';
    $real_path = drupal_realpath("$file_dir");
    $real_url = file_create_url($file_dir);
    $cropfilepath = "$real_path/{$n}.jpg";
    $cropurl = "$real_url/{$n}.jpg";
    $targ_w = $_POST['w'];
    $targ_h = $_POST['h'];
    $x = $_POST['x'];
    $y = $_POST['y'];
    $container_width = $_POST['c_w'];
    $container_height = $_POST['c_h'];
    $jpeg_quality = 90;
    $src = $_POST['src'];

    $size = getimagesize($src);
    switch ($size["mime"]) {
      case "image/jpeg":
        $img_replacement = imagecreatefromjpeg($src); //jpeg file
        break;
      case "image/gif":
        $img_replacement = imagecreatefromgif($src); //gif file
        break;
      case "image/png":
        $img_replacement = imagecreatefrompng($src); //png file
        break;
      default:
        $img_replacement = false;
        break;
    }


    $ratio_width = $targ_w / $size[0];
    $ratio_height = $targ_h / $size[1];
    $ratio_width = round($ratio_width, 8);
    $ratio_height = round($ratio_height, 8);


    $source_imagex = imagesx($img_replacement);
    $source_imagey = imagesy($img_replacement);

    $dst_r = ImageCreateTrueColor($targ_w, $targ_h);
    /* new */
    $dst_r1 = ImageCreateTrueColor($container_width, $container_height);
    imagecopyresampled($dst_r1, $img_replacement, 0, 0, 0, 0, $container_width, $container_height, $source_imagex, $source_imagey);
    imagecopy($dst_r, $dst_r1, 0, 0, $_POST['x'], $_POST['y'], $_POST['w'], $_POST['h']);
    imagejpeg($dst_r, $cropfilepath, $jpeg_quality);
    // Image created by imagejpeg is converted to Drupal managed file.
    $data = file_get_contents($cropfilepath);
    $file_object = file_save_data($data, "public://iit{$n}.jpg");
    $file_object->filemime = 'image/jpeg';
    $image_url = file_create_url($file_object->uri);
    unlink($cropfilepath);
    imagedestroy($dst_r1);
    imagedestroy($dst_r);
//@TODO  convert to theme function.
    $string = "<div class='draggable imagecrop' style='z-index : 1001; float: left;'>";
    $string .="<a href='' class='ui-icon ui-icon-info'> info </a> <a> <span class='ui-icon ui-icon-close'> X </span></a> ";
    $string .="<div id='d" . $n . "' class='info'>  </div>";
    $string .="<img id='img" . $n . "' src='" . $image_url . "' style='opacity:0.6;filter:alpha(opacity=40);' ";
    $string .="data-ratiow='" . $ratio_width . "' data-ratioh='" . $ratio_height . "' ";
    $string .="data-dimensions='" . "$ratio_width x $ratio_height" . "'/>";
    $string .="<a href='' class='ui-icon ui-icon-arrowstop-1-e'> Flip Y-axis </a> ";
    $string .="<a href='' class='ui-resize'> Resize</a> ";
    $string .="</div>";
    echo $string;
  }
}

/**
 * Menu driven callback to push off double image view.
 */
function agile_iit_twoviews() {

  if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $img1_src = $_POST['vf_img1'];
    $img2_src = $_POST['vf_img2'];
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
  /**
   * Jcrop image cropping plugin for jQuery
   * Example cropping script
   * @copyright 2008-2009 Kelly Hallman
   * More info: http://deepliquid.com/content/Jcrop_Implementation_Theory.html
   */
  if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $n = rand(0, 100000);
    $cropimg = '../tmp/crop_img' . $n . '.jpg';
    $targ_w = $_POST['w'];
    $targ_h = $_POST['h'];
    $x = $_POST['x'];
    $y = $_POST['y'];
    $c_w = $_POST['c_w'];
    $c_h = $_POST['c_h'];
    $jpeg_quality = 90;

    $src = $_POST['src'];
    $dimensions = $_POST['dimensions'];



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


    $source_imagex = imagesx($img_r);
    $source_imagey = imagesy($img_r);

    $dst_r = ImageCreateTrueColor($targ_w, $targ_h);
    /* new */
    $dst_r1 = ImageCreateTrueColor($c_w, $c_h);
    imagecopyresampled($dst_r1, $img_r, 0, 0, 0, 0, $c_w, $c_h, $source_imagex, $source_imagey);

    imagecopy($dst_r, $dst_r1, 0, 0, $_POST['x'], $_POST['y'], $_POST['w'], $_POST['h']);
    //imagecopy($dst_r, $img_r, 0, 0, $x, $y, $targ_w, $targ_h);
    imagejpeg($dst_r, $cropimg, $jpeg_quality);
    imagedestroy($dst_r1);
    imagedestroy($dst_r);

    $string = "<div class='draggable imagecrop' style='z-index : 1001; float: left;'>";
    $string .="<a href='' class='ui-icon ui-icon-info'> info </a> <a> <span class='ui-icon ui-icon-close'> X </span></a> ";

    $string .="<div id='d" . $n . "' class='info'>  </div>";
    $string .="<img id='img" . $n . "' src='" . $cropimg . "' style='opacity:0.6;filter:alpha(opacity=40);' ";
    $string .="data-ratiow='" . $ratio_w . "' data-ratioh='" . $ratio_h . "' ";
    $string .="data-dimensions='" . $dimensions . "'/>";
    $string .="<a href='' class='ui-icon ui-icon-arrowstop-1-e'> Flip Y-axis </a> ";

    $string .="<a href='' class='ui-resize'> Resize</a> ";
    $string .="</div>";
    echo $string;
  }
}