<?php

/**
 * Jcrop image cropping plugin for jQuery
 * Example cropping script
 * @copyright 2008-2009 Kelly Hallman
 * More info: http://deepliquid.com/content/Jcrop_Implementation_Theory.html
 */
if ($_SERVER['REQUEST_METHOD'] == 'POST')
{
	$n=rand(0,100000);
	$cropimg='../tmp/crop_img' . $n . '.jpg';
	$targ_w = $_POST['w'];
 	$targ_h = $_POST['h'];
	$x=$_POST['x'];
	$y=$_POST['y'];
	$c_w=$_POST['c_w'];
	$c_h=$_POST['c_h'];
	$jpeg_quality = 90;

	$src = $_POST['src'];
	$dimensions = $_POST['dimensions'];
	
	
	
	
	 $size=getimagesize($src);
    switch($size["mime"]){
        case "image/jpeg":
            $img_r = imagecreatefromjpeg($src); //jpeg file
        break;
        case "image/gif":
            $img_r= imagecreatefromgif($src); //gif file
      break;
      case "image/png":
          $img_r = imagecreatefrompng($src); //png file
      break;
    default: 
        $img_r=false;
    break;
    }
	/*

	$source_imagex = imagesx($img_r);
	$source_imagey = imagesy($img_r);
	$dst_r = ImageCreateTrueColor( $_POST['w'], $_POST['h'] );
	$dst_r1 = ImageCreateTrueColor( $c_w, $c_h);
	imagecopyresampled($dst_r1,$img_r,0,0,0,0,$c_w,$c_h,$source_imagex, $source_imagey);
	imagecopy( $dst_r, $dst_r1,0, 0, $_POST['x'], $_POST['y'], $_POST['w'], $_POST['h']);
	imagejpeg($dst_r,$cropimg,$jpeg_quality);
	imagedestroy($dst_r1);
	imagedestroy($dst_r);
       */

	$ratio_w=$targ_w/$size[0];
	$ratio_h=$targ_h/$size[1];
	$ratio_w=round($ratio_w, 8);
	$ratio_h=round($ratio_h, 8);
	

	$source_imagex = imagesx($img_r);
	$source_imagey = imagesy($img_r);

	$dst_r = ImageCreateTrueColor( $targ_w, $targ_h);
	/*new*/
	$dst_r1 = ImageCreateTrueColor( $c_w, $c_h);
	imagecopyresampled($dst_r1,$img_r,0,0,0,0,$c_w,$c_h,$source_imagex, $source_imagey);

	imagecopy( $dst_r, $dst_r1,0, 0, $_POST['x'], $_POST['y'], $_POST['w'], $_POST['h']);
	//imagecopy($dst_r, $img_r, 0, 0, $x, $y, $targ_w, $targ_h);
	imagejpeg($dst_r, $cropimg, $jpeg_quality);
	imagedestroy($dst_r1);
	imagedestroy($dst_r);
	
	$string = "<div class='draggable imagecrop' style='z-index : 1001; float: left;'>";
	
	//$string .="<a href='' class='ui-icon ui-icon-info'> info </a><a> <span class='ui-icon ui-icon-close'> close </span></a> ";
	$string .="<a href='' class='ui-icon ui-icon-info'> info </a> <a> <span class='ui-icon ui-icon-close'> X </span></a> ";

	$string .="<div id='d" . $n . "' class='info'>  </div>";
	$string .="<img id='img" . $n . "' src='" . $cropimg . "' style='opacity:0.6;filter:alpha(opacity=40);' ";
	$string .="data-ratiow='" . $ratio_w . "' data-ratioh='" . $ratio_h . "' ";
	$string .="data-dimensions='" . $dimensions . "'/>";
	$string .="<a href='' class='ui-icon ui-icon-arrowstop-1-e'> Flip Y-axis </a> ";

	//$string .="<a href='' class='ui-arrow'> Flip</a> ";
	$string .="<a href='' class='ui-resize'> Resize</a> ";
	//$string .="<a> <span class='ui-icon ui-icon-close'> close </span></a><p class='ui-icon-info'> info</p> ";
	//$string .="<a href='' class='ui-icon ui-icon-arrowstop-1-e'> Flip Y-axis </a> ";
	$string .="</div>";
		echo $string;



}

// If not a POST request, display page below:

?>
