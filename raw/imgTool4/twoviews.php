<?php
if ($_SERVER['REQUEST_METHOD'] == 'POST'){
	$img1_src=$_POST['vf_img1'];
	$img2_src=$_POST['vf_img2'];
}

?>

<div id=ol_container>

<input type="button" name="ol_close" id="ol_close" value="Close"/>


<div id="ol_i1">
<a href='<? echo $img1_src; ?>' class=zoom ><img width=400px; src='<? echo $img1_src ?>' style='float: left'/></a>
</div>

<div id="ol_i2">
<a href='<? echo $img2_src; ?>' class=zoom><img width=400px; src='<? echo $img2_src; ?>' style='float: left'/></a>
</a>
</div>


</div>

