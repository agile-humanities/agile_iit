<?php


if ($_SERVER['REQUEST_METHOD'] == 'POST')
{

	$jpeg_quality = 90;

	$src = $_POST['src'];
	$pre = $_POST['pre'];
	$tmp = explode("/", $src);
	$newsrc=end($tmp);

	$newsrc="../tmp2/images/" . $pre . "-" . $newsrc;


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

	$oldwidth=$size[0];
	$oldheight=$size[1];

	$pre=str_replace("px", "", $pre);
	$newwidth=$pre;

	$ratio=$newwidth/$oldwidth;
	$newheight=$ratio * $oldheight;
	$newheight=round($newheight,0);


	$dst_r = ImageCreateTrueColor( $newwidth, $newheight);

	imagecopyresampled($dst_r, $img_r, 0, 0,0,0, $newwidth, $newheight, $oldwidth, $oldheight);
	imagejpeg($dst_r, $newsrc, $jpeg_quality);
	//imagedestroy($img_r);
	//imagedestroy($dst_r);

	
	


	echo $src . " " . $newsrc . " " . $oldwidth . " " . $oldheight . " " . $ratio . " " . $newwidth . " " . $newheight;



}

// If not a POST request, display page below:

?>
