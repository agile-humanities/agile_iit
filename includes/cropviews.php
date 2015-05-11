<?php
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
  $img1_src = $_POST['cf_img1'];
  $img2_src = $_POST['cf_img2'];
  $pre = $_POST['pre'];
}


$pre2 = str_replace("px", "", $pre);
$pre2 = (int) $pre2 + 10;
?>
<div id=cr_container>
  <input type="button" name="cl_close" id="cl_close" value="close"/>
  <div id="ol_i1">
    <img src='<? echo $img1_src ?>' id='crop_target' width='<? echo "100" ?>' style="position:absolute; top:26px; left:0px;"/>
  </div>
  <div id="ol_i2">
    <img src='<? echo $img2_src; ?>'  width='<? echo "100" ?>' style="position:absolute; top:26px; left:<? echo "110" ?>px;"/></a>
    </a>
  </div>
  <div style="clear:both;"></div>

  <form id="cropform2" method="post">
    <input type="hidden" id="x" name="x" />
    <input type="hidden" id="y" name="y" />
    <input type="hidden" id="w" name="w" />
    <input type="hidden" id="h" name="h" />
    <input type="submit" value="Crop Image" class="btn btn-large btn-inverse" style=" position: relative; float:left;" />
  </form>
</div>
<div id=results>
</div>