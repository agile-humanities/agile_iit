<div id="menu">

    <form id="viewform" method="post" class ='inline'>
        <input type="hidden" id="vf_img1" name="vf_img1"/>
        <input type="hidden" id="vf_img2" name="vf_img2"/>
        <input type="submit" value="Comparison Viewer" class="agile_btn btn btn-inverse"  />
    </form>

    <form id="cropform" method="post" class ='inline'>
        <input type="hidden" id="cf_img1" name="cf_img1"/>
        <input type="hidden" id="cf_img2" name="cf_img2"/>
        <input type="submit" value="Extract Detail" class="agile_btn btn btn-large btn-inverse" />
    </form>

    <form id="gridform" method="post" class ='inline'>
        <input type="submit" value="Show/Hide Grid" class="agile_btn btn btn-large btn-inverse" />
    </form>
    <form id="view_reset" method="post" class ='inline'>
        <input type="submit" value="Reset" class="agile_btn btn btn-large btn-inverse" />
    </form>
</div>

<div id="iit_container">
    <div id="image1" class="img-container"> 
        <h4><?php print($placeholder_text); ?></h4>
        <div id="table1" z-index="500" opacity="0.1">
        </div>
    </div>
    <div id="image2" class="img-container"> 
        <h4><?php print($placeholder_text); ?></h4>
    </div>
</div>


