<?php ?>
<div id=ol_container>
    <div>
        <form id="cropform2" method="post">
            <input type="hidden" id="x" name="x" />
            <input type="hidden" id="y" name="y" />
            <input type="hidden" id="w" name="w" />
            <input type="hidden" id="h" name="h" />
            <input type="submit" value="Extract Detail" class="btn btn-large btn-inverse" style=" position: relative; float:left;" />
        </form>
        <input type="button" name="cl_close" id="cl_close" value="close"/>
    </div>
    <div style="clear:both;"></div>
    <div id="ol_i1">
        <img src='<?php echo $img1_src ?>' id='crop_target' width='<?php echo $width ?> 'height='<?php echo $height1 ?>' style=" top:26px; left:0px;"/>
    </div>
    <div id="ol_i2">
        <img src='<?php echo $img2_src; ?>' width='<?php echo $width ?>' 'height='<?php echo $height2 ?>' style=" top:26px; float:right; left:<?php echo$width / 2 ?>px;"/></a>
        </a>
    </div>
</div>
<div id=results>
</div>