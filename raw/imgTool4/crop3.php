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
	$cropimg='../tmp2/crop_img' . $n . '.jpg';
	$targ_w = $_POST['sectImgW'];
 	$targ_h = $_POST['sectImgH'];
	$x=$_POST['x'];
	$y=$_POST['y'];
	//$c_w=$_POST['c_w'];
	//$c_h=$_POST['c_h'];
	$jpeg_quality = 90;

	$src = $_POST['image2'];
	$sect_src = $_POST['sectImg'];
	

	$sect_WRatio=$_POST['w1ratio'];

	$sect_HRatio=$_POST['h1ratio'];

	
	$img1dimW=$_POST['img1_dimW'];
	$img1dimH=$_POST['img1_dimH'];
	$img2dimW=$_POST['img2_dimW'];
 	$img2dimH=$_POST['img2_dimH'];

	$title1 = $_POST['title1'];
	$title2 = $_POST['title2'];
	$dimensions1 = $_POST['dimensions1'];
	$dimensions2 = $_POST['dimensions2'];
		
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
 

	$ratio_w=$targ_w/$size[0];
	$ratio_h=$targ_h/$size[1];
	$ratio_w=round($ratio_w, 8);
	$ratio_h=round($ratio_h, 8);



	$dim1W=(double)$sect_WRatio * $img1dimW;
	$dim1H=(double)$sect_HRatio * $img1dimH;
	
	$dim1W=round($dim1W,2);
	$dim1H=round($dim1H,2);

     	$dim2W=(double)$ratio_w * $img2dimW;
	$dim2H=(double)$ratio_h * $img2dimH;
	
	$dim2W=round($dim2W,2);
	$dim2H=round($dim2H,2);


	$dst_r = ImageCreateTrueColor( $targ_w, $targ_h);
	imagecopy($dst_r, $img_r, 0, 0, $x, $y, $targ_w, $targ_h);
	imagejpeg($dst_r, $cropimg, $jpeg_quality);
	


	
	$string = "<div>";

	$string .="<p><i>" . $title1 . "</i> (Full size of original is: " . $dimensions1 . ").<br>";
	$string .="Section is approx." . $dim1H . "(H) x " . $dim1W . "(W) cm. </p>";

	$string .="<img src='" . $sect_src . "'/>' ";
	$string .="<br>";

	$string .="<p><i>" . $title2 . "</i> (Full size of original is: " . $dimensions2 . "). <br>";
	$string .="Section is approx." . $dim2H . "(H) x " . $dim2W . "(W) cm. </p>";

	$string .="<img id='img" . $n . "' src='" . $cropimg . "'/>' ";
	$string .="<br><br>";


	$string .="</div>";
	echo $string;



}

// If not a POST request, display page below:

?>
