
(function ($) {

    Drupal.behaviors.agileIITExtract = {
        attach: function (context, settings) {
            $(document).on('click', '#ol_close', function () {
                $('.zoom').find('.zoomy').remove();
                $('#overlay2').remove();
                $("#resizable-gallery-wrapper").show();
                $("#page-title").show();
            });

            // Handler for the crop overlay close button.
            $(document).on('click', '#cl_close', function () {
                $('#overlay2').remove();
                $("#resizable-gallery-wrapper").show();
                $("#page-title").show();
                $(".img-container").show();
            });

            function updateCoords(c) { // This gets called when a rectangle is selected in the crop tool.
                $('#x').val(c.x); // These elements are part of the form #cropform2 which has the submit button Extract Detail.
                $('#y').val(c.y); // They get the x and y position of the top-left corner and the height and width,
                $('#w').val(c.w); // seemingly accurately and independent of whether you made the rectangle by dragging down-right or up-left.
                $('#h').val(c.h);
            }
            $("#cropform").submit(function (e) {
                e.preventDefault();
                $("#resizable-gallery-wrapper").hide();
                $("#page-title").hide();
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
                    $(".img-container").hide(); // Hide the dropzones.
                    $.post("agile/iit/crop", values, function (data) { // POST the form values to crop, which returns themed stuff to create the cropping workspace based on the images at cf_img1 and cf_img2.
                        $("#overlay2").append(data);
                        $('#crop_target').Jcrop({onSelect: updateCoords}); // This means that on selecting a rectangle, it runs updateCoords.
                        image2_offset = $("#ol_i2 img").offset(); // Calculates the position of image2 relative to document (absolute position).
                        image2_height = $("#ol_i2 img").height();
                        image2_width = $("#ol_i2 img").width();

                    });
                }
            });


            // This runs when you click "Extract Detail" and it throws a little detail guy under the two images.
            $(document).on('submit', '#cropform2', function (e) {
                e.preventDefault();
                if (parseInt($('#w').val())) { // If the selected rectangle has a width (note: isn't this element included in the form data? why do we search for it by id?)
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
                        $(".resizable").resizable().find('img').css({"width": "78%"}); // This does weird things to the size. We shouldn't.
                        $(".rotatable").rotatable();

                    });

                }
                else {
                    alert('Please select a crop region then press submit.');
                    return false;
                }

            });
        }
    };
})(jQuery);

