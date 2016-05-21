<div id = twoviews_container>
    <p>
        <input type = "button" class="info_pane" name = "ol_close" id = "ol_close" value = "Close"/>
        <span class="info_pane" id="image1_info">X:0 Y:0</span>
        <span class="info_pane" id="image2_info">X:0 Y:0</span>

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
