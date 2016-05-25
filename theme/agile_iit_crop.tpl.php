<?php ?>
<div id=ol_container>
    <div>
        <form id="cropform2" method="post">
            <input type="hidden" id="x" name="x" />
            <input type="hidden" id="y" name="y" />
            <input type="hidden" id="w" name="w" />
            <input type="hidden" id="h" name="h" />
            <input type="submit" value="Extract Detail" class="btn btn-large btn-inverse" style=" position: relative; float:left;" />
            <span type="button" name="iit_help" id="iit_help" value="Help"/>

        </form>
        <input type="button" name="cl_close" id="cl_close" value="close"/>
    </div>
    <div style="clear:both;"></div>
    <div id="ol_i1" class="iit-image-holder">
        <img src='<?php echo $img1_src ?>' id='crop_target'/>
    </div>
    <div id="ol_i2" class="iit-image-holder">
        <img src='<?php echo $img2_src; ?>'/>
    </div>
</div>
<div id=results>
</div>