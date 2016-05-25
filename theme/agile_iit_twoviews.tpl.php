<div id = twoviews_container>
    <p> Origin (click to reset):
        <span class="info_pane" id="image1_info">X:0 Y:0</span>
        <span class="info_pane" id="image2_info">X:0 Y:0</span>
        <input type="button" class="iit-button" name="ol_help" id="ol_help" value="Help"/>
        <input type="button" class="iit-button" name="ol_close" id="ol_close" value = "Close"/>

    </p>
    <div id = "ol_i1" class = 'ol_image'>
        <a href = "<?php echo $img1_src; ?>" class = "zoom two_up">
            <img class="two_up_image" src = '<?php echo $img1_src ?>' style = 'float: left;'/>
                <div class="crosshair-vertical"/>
                <div class="crosshair-horizontal"/>
        </a>
    </div>
    <div id = "ol_i2" class = 'ol_image'>
        <a href = '<?php echo $img2_src; ?>' class = "zoom two_up">
            <img  class="two_up_image" src = '<?php echo $img2_src; ?>' style = 'float: left;'/>
            <div class="crosshair-vertical"/>
            <div class="crosshair-horizontal"/>
        </a>
    </div>
</div>
