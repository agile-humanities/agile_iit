// QUESTION what are these for? Don't they get overwritten in setLandscapeView?
var image1Top = 350;
var image2Top = 350;
var image1Left = 0;
var image2Left = 150;

$(function () {
    // QUESTION what are all these for?
    var image1_src, image2_src, image2_offset, image2_height, image2_width, image1_dimW, image1_dimH, image2_dimW, image2_dimH, image1_clientWidth, image2_clientWidth, imageSize, imageSizePrefix, screenRatio,
            previousImagePrefix;

    var vf400img1Height, vf400img2Height; // Do we ever use these?
    // This defines that we will use up to 96% of the window width.
    screenRatio = 0.96;
    // QUESTION what is the deal with these previous image prefixes?
    previousImagePrefix = '800px'; // We never actually use this value anywhere, it gets overridden the first time that replaceImagePrefix gets called.
    var cl_windowWidth = $(window).width();
    var cl_windowHeight = $("#image1").height(); // This is completely useless.
    imageSize = Math.floor((cl_windowWidth * screenRatio) / 2);
    // Finally, something legible. This calculates the image width based on having to be smaller or equal to half
    // of the window width.
    imageSizePrefix = calculateImagePrefix(imageSize);

    // If we keep this, we should refactor it. But maybe there's a better way than jumping down in 200px increments.
    function calculateImagePrefix(number) {
        var result;
        if (number >= 800) {
            result = '800px';
        }
        else if (number >= 700) {
            result = '600px';
        }
        else if (number >= 600) {
            result = '600px';
        }
        else if (number >= 500) {
            result = '400px';
        }
        else if (number >= 400) {
            result = '400px';
        }
        else if (number >= 300) {
            result = '200px';
        }
        else if (number >= 200) {
            result = '200px';
        }
        else {
            result = '200px';
        }
        return result;
    }

    // QUESTION what the fuck do we ever use this? It would get invoked if we have data-orientation=portrait, but
    // we've hardcoded it to landscape. Also it looks like someone fucked with these numbers because they make no sense.
    function setPortraitView() {
        image1Top = 260;
        image2Top = 0;
        image1Left = 410;
        image2Left = 810;

    }
    // QUESTION What's this do?
    // It gets invoked when we're using landscape view (which we happen to always be doing).
    function setLandscapeView() {

        image1Top = 468;
        image2Top = 468;
        image1Left = 0;
        image2Left = 0;

    }

    // This function runs through all the .ui-thumb's on the page and finds the child img,
    // and extracts the attribute 'data-lrg-url' and POSTs to agile/iit/imagederivative passing
    // a size ('next') and a path. This is the thing that takes forever and you can't move images
    // while it's happening (issue #1).
    // On initial run it passes in 800px as prev and floor(half window width)+px as next.
    // Note that it never uses the value of prev. It initializes the image styles based on next.
    // The entire existence of prev in this function is a relic of old code.
    function replaceImagePrefix(prev, next) {
        $(".ui-thumb img").each(function () {
            var src = $(this).attr('data-lrg-url'); // note the difference between data-lrg-url and data-lrg_url.
            // In my example, data-lrg-url is "public://Mona_Lisa_(copy,_Hermitage).jpg" and
            // data-lrg_url is "http://localhost:8181/sites/default/files/styles/iit-200/public/Mona_Lisa_%28copy%2C_Hermitage%29.jpg?itok=rDQt89Lv"
            var that = this;
            $.post("agile/iit/imagederivative", {size: next, path: src}, function (data) { // Get the url of the derivative of size 'next'.
                $(that).attr('data-lrg_url', data); // Set it to data-lrg_url (does this mean we have a zoom ratio of 1?)
                $.get(data); // Are we calling 'get' to initialize the derivatives? It takes a while. are we maybe better to initialize them as needed?
            });
        });
        previousImagePrefix = next;
    }

    // Make the .ui-thumb stuff draggable. Good. Bizzarely, the helper seems to pop up ~150px BELOW the cursor.  This is kinda confusing.
    $(".ui-thumb").draggable({
        cursor: "move",
        revert: "false",
        helper: "clone",
        scroll: false

    }).on('dragstart', function (e, ui) {
        $(ui.helper).css('z-index', '99999'); // and make the helper super-high z-index. This good.
    });

    // Loop through .iit-thumb's child images and extract the data-width and data-height parameters, which we've set in the view.
    // Set them as data-dimensions (which is nicer to read). We should refactor this whole thing out because we don't need the real-life dimensions at this point.
    function write_attributes() {
        $('.iit-thumb img').each(function () {
            width = $(this).attr('data-width'); // This is the raw number in cm of the image, which was passed in from the view.
            height = $(this).attr('data-height'); // Height. raw number in cm.
            $(this).attr("data-dimensions", width + ' cm x ' + height + ' cm');
            $(this).attr("data-orientation", 'landscape');     // It also sets the data-orientation which we're not using effectively at all.
        });
    }
    write_attributes();
    // This initializes all the image derivatives using imageSizePrefix. It also happens to set previousImagePrefix to the imageSizePrefix.
    replaceImagePrefix(previousImagePrefix, imageSizePrefix);

    // Make the .img-container's droppable.
    $(".img-container").droppable({
        accept: ".ui-thumb",
        hoverClass: "iit-ui-state-hover",
        drop: function (event, ui) {  // ui is the object currently being dropped.
            var src = ui.draggable.find('img').attr("data-lrg_url"); // get the url of the "big" image (which at the moment is also the half-the-viewport image), e.g. http://localhost:8181/sites/default/files/styles/iit-200/public/Mona_Lisa_%28copy%2C_Hermitage%29.jpg?itok=rDQt89Lv
            var nid = ui.draggable.find('img').attr("nid");  // get the nid!
            var vfsrc = src.replace(imageSizePrefix, "800px"); // Not sure why we need vfsrc. note that vf means view form, which means it's maybe populating values to be used in the comparison viewer. Also not sure if this line of code is useful as src now includes iit-x00 instead of x00px.
            var vf400src = src.replace(imageSizePrefix, "400px"); // Question: likewise.
            $(this).find("img").remove(); // Remove an existing image; lets you drop overtop of something already there. Good.

            var title = ui.draggable.find('img').attr("alt"); // Obtain the title for this droppable section. Kinda nice, but not super necessary. Should we maybe or not get it from pid?
            var dimensions = ui.draggable.find('img').attr("data-dimensions"); // obtain the pretty real-life-dimensions from the drop-ee (not needed yet)
            var height = ui.draggable.find('img').attr("data-height"); // obtain the raw real-life-dimensions from the drop-ee
            var width = ui.draggable.find('img').attr("data-width");
            var date = ui.draggable.find('img').attr("data-date"); // obtain the date created from the drop-ee. Definitely not needed here.
            var support = ui.draggable.find('img').attr("data-support"); // obtain some other random information about the painting. Not needed here either.

            var orientation = ui.draggable.find('img').attr("data-orientation"); // This looks like it'll be useful (but we've hard-coded it to landscape always).
            if (orientation === "portrait") {
                setPortraitView();
            }
            else if (orientation === "landscape") {
                setLandscapeView();
            }

            $(this).find("h4").html(title); // Set the title of this droppable section (as described above)
            // Create an html of a new image node. Isn't there a better javscript way to do this? [yes, see below] And we can refactor out most of these attributes.
            var newImage = "<a href='" + src + "'><img onerror='imgError()'  alt='" + title + "' src='" + src + "' data-nid='" + nid + "' data-dimensions='" + dimensions + "' data-height='" + height + "' data-width='" + width + "' data-orientation='" + orientation + "' data-date='" + date + "' data-support='" + support + "'> </a>";
            var newImageElm = $(newImage).appendTo(this);

            if (this.id === "image1") // Set some local variables in javascript. When are we going to use these?
            {
                image1_src = src;
                image1_dimH = $(this).find('img').attr('data-height'); // Save this for the crop info tool.
                image1_dimW = $(this).find('img').attr('data-width'); // Save this for the crop info tool.
                image1_clientWidth = $(this).find('img').width(); // We seem to never use this again.

                $("#vf_img1").val(vfsrc); // code note: val() gets/sets the value of a form element. This sets the value in the "viewform" out of data-lrg_url (after failing to change the pixel size from x00px to 800px)
                $("#cf_img1").val(src); // ditto for the crop viewer form, only this time we maybe intended use the image fitted to half the screen width size. We use this image as the source for the extracted detail. Maybe we want a higher res source?
                var vf400img1 = new Image(); // This is how to make a new Image html thing in javascript.
                vf400img1.src = vf400src;
                vf400img1Height = vf400img1.height; // ??
                vf400img1Width = vf400img1.width; // ??
                delete vf400img1; // This seems to do absolutely nothing because we never set/found the height/width of this before deleting it.
                $.get(vfsrc)// Send a get request to the "large" version for the view form.
                        .done(function () {
                            var newvfsrc = vfsrc.split("/"); // if it returns, yay! assign a new variable that we never use out of the path parts.
                        })
                        .fail(function () { // if it fails, make a new array out of the first six path parts and remove "thumb" from anything. Assign this to the viewform.
                            var newvfsrc = vfsrc.split("/", 6);
                            newvfsrc = newvfsrc.join("/");
                            newvfsrc = newvfsrc.replace("/thumb", "");
                            $("#vf_img1").val(newvfsrc);
                        });

            }
            else // If you dragged into the second image drop zone
            {
                image2_src = src; // we don't actually use this because it gets overwritten by #vf_img2.val().
                image2_dimH = $(this).find('img').attr('data-height');  // Save it for the crop info tool.
                image2_dimW = $(this).find('img').attr('data-width');  // Save it for the crop info tool.
                image2_clientWidth = $(this).find('img').width(); // We never actually use this.

                $("#vf_img2").val(vfsrc); // Set the src of image 2 in the view form. (should have been the 800 version but isn't)
                $("#cf_img2").val(src);  // Set the src of image 2 in the crop form.
                var vf400img2 = new Image(); // WTF
                vf400img2.src = vf400src;
                vf400img2Height = vf400img2.height;
                delete vf400img2;
                $.get(vfsrc) // WTF see above.
                        .done(function () {
                            var newvfsrc = vfsrc.split("/");
                        })
                        .fail(function () {
                            var newvfsrc = vfsrc.split("/", 6);
                            newvfsrc = newvfsrc.join("/");
                            newvfsrc = newvfsrc.replace("/thumb", "");
                            $("#vf_img2").val(newvfsrc);
                        });
            }
        }
    });

    var resizeListener = function () { // Hey, we have a resize listener! Does this ever get called?
        imageSize = Math.floor(($(window).width() * screenRatio) / 2);
        imageSizePrefix = calculateImagePrefix(imageSize); // Find the new image prefix
        if (imageSizePrefix !== previousImagePrefix) {
            replaceImagePrefix(previousImagePrefix, imageSizePrefix); // replace the image size prefixes in the ui-thumb's, which does nothing if you've already dragged your images or opened a tool.
        }
    };

    function updateCoords(c){ // This gets called when a rectangle is selected in the crop tool.
        $('#x').val(c.x); // These elements are part of the form #cropform2 which has the submit button Extract Detail.
        $('#y').val(c.y); // They get the x and y position of the top-left corner and the height and width,
        $('#w').val(c.w); // seemingly accurately and independent of whether you made the rectangle by dragging down-right or up-left.
        $('#h').val(c.h);
    }
    var jcrop_api = [];
    // Set the submit handlers for the cropform, viewform, gridform.
    $("#cropform").submit(function (e) {
        e.preventDefault();
        var tmp1 = $("#cf_img1").val();
        var tmp2 = $("#cf_img2").val();
        if (tmp1 === "" || tmp2 === "") {
            alert("Two images must be selected.");
            return false;
        }
        else {
            $(window).scrollTop(0);
            var myOverlay = document.createElement('div');
            myOverlay.id = 'overlay2'; // Create a thing called overlay2. We should refactor this to be a more descriptive name.
            $('#iit_container').append(myOverlay);


            var values = $(this).serializeArray(); // Makes an array of name: value: pairs out of the form. Note, all we need are cf_img1 and cf_img2.
            values.push({name: "container_width", value: $('#iit_container').width()}); // Add another parameter: the current viewfield(ish) width
            $(".img-container").hide(); // Hize the dropzones.
            $.post("agile/iit/crop", values, function (data) { // POST the form values to crop, which returns themed stuff to create the cropping workspace based on the images at cf_img1 and cf_img2.
                $("#overlay2").append(data);
                $('#crop_target').Jcrop({onSelect: updateCoords}, function(){
                    jcrop_api.push(this);
                }); // This means that on selecting a rectangle, it runs updateCoords.
                image2_offset = $("#ol_i2 img").offset(); // Calculates the position of image2 relative to document (absolute position).
                image2_height = $("#ol_i2 img").height();
                image2_width = $("#ol_i2 img").width();

            });
            $(window).resize(function(){
                if(jcrop_api.length > 0)
                {
                    $.each( jcrop_api, function( key, api ) {
                        api.destroy();
                    } );
                    $('#crop_target').removeAttr('style');
                    $('.jcrop-holder').remove();

                    $('#crop_target').each(function(){
                        $.Jcrop(this, {onSelect: updateCoords});
                        });
                }
            });
        }
    });


    // This runs when you click "Extract Detail" and it throws a little detail guy under the two images.
    $(document).on('submit', '#cropform2', function (e) {
        e.preventDefault();
        if (parseInt($('#w').val())) { // Check that a crop window exists.
            var values = $(this).serializeArray(); // Make that name: value: array out of the four input elements in the form (x,y,w,h)
            var src = $("#cf_img1").val(); // Oddly enough, we dig back down into the original "cropform" to get this value. It's still "underneath" the crop workspace.
            var c_w = $("#crop_target").width(); // Note that the crop_target is actually a different, hidden image, just happens to be the same size as the one we see.
            var c_h = $("#crop_target").height();
            values.push({name: 'src', value: src}); // Add the source of the image from cf_img1.
            values.push({name: 'c_w', value: c_w});
            values.push({name: 'c_h', value: c_h});
            $.post("agile/iit/croptool", values, function (data) {
                $("#results").append(data);
                $(".draggable").draggable({containment: "window"});
                $(".resizable").resizable({aspectRatio: true, handles: 'se'});
                $(".rotatable").rotatable();

            });

        }
        else {
            alert('Please select a crop region then press submit.');
            return false;
        }

    });

    // Resets the gallery view.
    $(document).on('submit', '#view_reset', function (e) {
        e.preventDefault();
        $('.img-container > a').empty();
        $('.img-container > h4').text("Image"); // We should change this to "Drag image here".
        var elementExists = document.getElementById("img_overlay1"); // This removes the grids, if present.
        if (elementExists) {
            var element1 = document.getElementById("img_overlay1");
            element1.parentNode.removeChild(element1);
            var element2 = document.getElementById("img_overlay2");
            element2.parentNode.removeChild(element2);
        }

    });


    // Handler for the crop overlay close button.
    $(document).on('click', '#cl_close', function () {
        $('#overlay2').remove();
        $(".img-container").show();
    });

    // Handler for the detail section. Note that it's called #results.
    $(document).on('click', '#results', function (event) {
        var $item = $(this), $target = $(event.target);


        // Close button fades out then vanishes the #results.
        if ($target.is(".ui-icon-close")) {
            //$target.parent().parent().remove();
            $target.parent().parent().parent().fadeOut(300, function () {
                $(this).remove();
            })
        }
        else if ($target.is(".ui-icon-arrowstop-1-e")) { // flip arrow handler

            var myid2 = $target.parent().find('img').attr('id'); // needed because the id is arbitrary and we can have multiple details.

            $("#" + myid2).toggleClass("flip");
        }

        else if ($target.is(".ui-icon-info")) { // info window.
            var sectionOffset = $target.parent().find('img').offset(); // Absolute position of the section's img. Good.
            var sectionHeight = $target.parent().find('img').height(); // Current height (after any resizing)
            var sectionWidth = $target.parent().find('img').width(); // Current width (after any resizing)
            var sectionImage = $target.parent().find('img').attr("src"); // The source of the detail img element. This is in public://. Is it managed? Do we delete it?
            var sectionWRatio = $target.parent().find('img').attr("data-ratiow"); // width ratio of detail to full image.
            var sectionHRatio = $target.parent().find('img').attr("data-ratioh"); // height ratio of detail to full image.

            var x = sectionOffset.left; // absolute position of the section's img.
            var y = sectionOffset.top;
            var x1 = x + sectionWidth; // absolute position of right side of section.
            var y1 = y + sectionHeight; // absolute position of bottom of section.

            var title1 = $("#image1").find('img').attr("alt"); // NO NEED! use the nid in the callback
            var title2 = $("#image2").find('img').attr("alt");

            var dimensions1 = $("#image1").find('img').attr("data-dimensions"); // NO NEED! use the nid in the callback
            var dimensions2 = $("#image2").find('img').attr("data-dimensions");

            var date1 = $("#image1").find('img').attr("data-date"); // NO NEED! use the nid in the callback
            var date2 = $("#image2").find('img').attr("data-date");

            var support1 = $("#image1").find('img').attr("data-support"); // NO NEED! use the nid in the callback
            var support2 = $("#image2").find('img').attr("data-support");

            var image2w = $('#ol_i2').find('img').width();
            var image2h = $('#ol_i2').find('img').height();

            // This math in the if statement says:
            // If the selection you've made is lying completely within image2. Need to verify the order of operations for + vs <=.
            if (x >= image2_offset.left && x <= image2_offset.left + image2_width &&
                    y >= image2_offset.top && y <= image2_offset.top + image2_height &&
                    x1 >= image2_offset.left && x1 <= image2_offset.left + image2_width &&
                    y1 >= image2_offset.top && y1 <= image2_offset.top + image2_height
                    ) {
                var values = new Array();
                image2_src = $("#cf_img2").val(); // Again we get the image 2 src out of the original cropform
                values.push({name: 'sectImg', value: sectionImage});
                values.push({name: 'sectImgW', value: sectionWidth});
                values.push({name: 'sectImgH', value: sectionHeight});
                values.push({name: 'image2', value: image2_src});
                values.push({name: 'x', value: x - image2_offset.left}); // passes x as the position of the section RELATIVE TO IMAGE2
                values.push({name: 'y', value: y - image2_offset.top}); // passes y as the position of the section RELATIVE TO IMAGE2
                values.push({name: 'w1ratio', value: sectionWRatio}); // Oh FFS can we stop changing the names of variables? This is the width fraction (selection to whole image)
                values.push({name: 'h1ratio', value: sectionHRatio});
                values.push({name: 'img1_dimH', value: image1_dimH}); // "Saved for the info tool" - i think this is the real-world object dimensions.
                values.push({name: 'img1_dimW', value: image1_dimW}); // Irrelevant - use the nid.
                values.push({name: 'img2_dimH', value: image2_dimH}); // Irrelevant - use the nid.
                values.push({name: 'img2_dimW', value: image2_dimW}); // Irrelevant - use the nid.
                values.push({name: 'title1', value: title1});  // Irrelevant - use the nid.
                values.push({name: 'title2', value: title2}); // Irrelevant - use the nid.
                values.push({name: 'dimensions1', value: dimensions1}); // This is the formatted, "N px (height) x M px (width)" - style.  IRRELEVEANT use nid
                values.push({name: 'dimensions2', value: dimensions2}); // Irrelevant - use the nid.
                values.push({name: 'date1', value: date1}); // Irrelevant - use the nid.
                values.push({name: 'date2', value: date2}); // Irrelevant - use the nid.
                values.push({name: 'support1', value: support1}); // Irrelevant - use the nid.
                values.push({name: 'support2', value: support2}); // Irrelevant - use the nid.
                values.push({name: 'image2w', value: image2w}); // pixel width of the thing the section is now overlaying.
                values.push({name: 'image2h', value: image2h}); // pixel height of the same.
                $.post("agile/iit/imagecropper", values, function (data) {
                    var myWindow = window.open('', 'cmpWindow', 'width=800, height=400, scrollbars=yes, toolbar=yes');
                    myWindow.document.write(data);
                    myWindow.focus();
                });
            }
            else {
                console.log("outbounds");
            }
        }
        return false;
    });
});
