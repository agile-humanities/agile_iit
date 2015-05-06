<?php include 'include/db.inc.php' ?>
<?php include 'include/user.id.inc.php' ?>
<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>Image Tool</title>
<script type="text/javascript" src="js/jquery-1.7.2.js"></script>
<script type="text/javascript" src="js/jquery-ui.js"></script>
<script type="text/javascript" src="js/jquery.Jcrop.js"></script>
<script type="text/javascript" src="script3.js"></script>
<script type="text/javascript" src="zoomy.js"></script>




<link rel="stylesheet" type="text/css" href="style2.css"/>
<link rel="stylesheet" type="text/css" href="zoomy.css"/>
<link rel="stylesheet" type="text/css" href="js/themes/base/jquery-ui.css"/>
</head>
<body>

<div id="content">




<ul id="gallery">


<?php
    $userID = gestUserIDfromCookie();
    checkUserID($userID);

   // $image = mysql_query("SELECT id, img_name, img_url, ref_url FROM mw_img_library WHERE user_id=$userID ORDER BY creation_stamp", $connexion);
    $image = mysql_query("SELECT distinct id, img_name, img_url, ref_url, dimensions, height, width, dia FROM mw_img_library JOIN imgt_dims ON img_name=image_name WHERE user_id=$userID ORDER BY creation_stamp", $connexion);


	while ($ligne = mysql_fetch_object($image))
	{
	    $title = $ligne->img_name;
		$string = $ligne->img_url;
		$pattern = "#images/#";
		$replacement = "images/thumb/";
		$string2=preg_replace($pattern, $replacement, $string);
	    $result = explode('/', $string);
		$filename=end($result);
		$string3=$string2 . "/" . "120px-" . $filename;
		$pattern = "#http://www.janbrueghel.net/#";
		$replacement = "";
		$url = preg_replace($pattern, $replacement, $string3);
		$url = "../" . $url;

		$pattern="#120px-#";
		$replacement="800px-";
		$lrg_url=preg_replace($pattern, $replacement, $url);

	   $title = str_replace("_", " ", $title);

	    if (substr($title, -4) == ".jpg")
	    {
	        $title = substr($title, 0, -4);
	    }

       ?>





	<li class="ui-thumb">


              <img src='<? echo $url; ?>' alt='<? echo $title; ?>' width='96' height='72' data-lrg_url='<?echo $lrg_url; ?>'data-dimensions='<?echo $ligne->dimensions; ?>' data-height='<?echo $ligne->height; ?>' data-width='<?echo $ligne->width; ?>' data-orientation='<?echo $ligne->dia; ?>'/>
		<p><? echo $ligne->dimensions ?>

	</li>

 <?
    }
?>


</ul>
</div>

		<div id="menu">

			<form id="viewform" method="post">
				<input type="hidden" id="vf_img1" name="vf_img1"/>
				<input type="hidden" id="vf_img2" name="vf_img2"/>
				<input type="submit" value="View Two Images" class="btn btn-inverse"  />
			</form>

      			<form id="cropform" method="post">
				<input type="hidden" id="cf_img1" name="cf_img1"/>
				<input type="hidden" id="cf_img2" name="cf_img2"/>
				<input type="submit" value="Crop Sections" class="btn btn-large btn-inverse" />
			</form>

      			<form id="gridform" method="post">
				<input type="submit" value="Show/Hide Grid" class="btn btn-large btn-inverse" />
			</form>



		</div>

		<div id="container">

			<div id="image1" class="img-container"> <h4> Image 1 </h4>

				<div id="table1" z-index="500" opacity="0.1">

				</div>
			</div>

			<div id="image2" class="img-container"> <h4> Image 2 </h4>

			</div>


		</div>






</div>
</div>



</body>


</html>
