<div id="menu">

    <form id="viewform" method="post">
        <input type="hidden" id="vf_img1" name="vf_img1"/>
        <input type="hidden" id="vf_img2" name="vf_img2"/>
        <input type="submit" value="View Two Images" class="agile_btn btn btn-inverse"  />
    </form>

    <form id="cropform" method="post">
        <input type="hidden" id="cf_img1" name="cf_img1"/>
        <input type="hidden" id="cf_img2" name="cf_img2"/>
        <input type="submit" value="Crop Sections" class="agile_btn btn btn-large btn-inverse" />
    </form>

    <form id="gridform" method="post">
        <input type="submit" value="Show/Hide Grid" class="agile_btn btn btn-large btn-inverse" />
    </form>
    <form id="view_reset" method="post">
        <input type="submit" value="Reset" class="agile_btn btn btn-large btn-inverse" />
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


