<div class='draggable imagecrop' style='z-index : 1001; float: left;'>
  <div class="iit-results-image-wrapper resizable rotatable" style="position: relative">
    <a href='' class='ui-icon ui-icon-info' id='info-button-<?php echo $sectionId; ?>'> info </a>
    <a> <span class='ui-icon ui-icon-close'> X </span></a>
    <img id='img<?php echo $n ?>' src='<?php echo $image_url ?>' style='opacity:0.6;filter:alpha(opacity=40);'
         data-ratiow='<?php echo $ratio_width ?>' data-ratioh='<?php echo $ratio_height ?>'
         data-dimensions='<?php echo $ratio_width ?> x <?php echo $ratio_height ?>'/>
    <a href='' class='ui-icon ui-icon-arrowstop-1-e'> Flip Y-axis </a>
  </div>
</div>