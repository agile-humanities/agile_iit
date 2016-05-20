
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
                    $(".img-container").hide(); // Hize the dropzones.
                    $.post("agile/iit/crop", values, function (data) { // POST the form values to crop, which returns themed stuff to create the cropping workspace based on the images at cf_img1 and cf_img2.
                        $("#overlay2").append(data);
                        $('#crop_target').Jcrop({onSelect: updateCoords}, function(){
                            jcrop_api.push(this);
                        }); // This means that on selecting a rectangle, it runs updateCoords.


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


                    var xOffset_ratio = $('#x').val() / $("#crop_target").width();
                    var yOffset_ratio = $('#y').val() / $("#crop_target").height();
                    var width_ratio = $('#w').val() / $("#crop_target").width();
                    var height_ratio = $('#h').val() / $("#crop_target").height();
                    var width = $('#w').val();

                    var src = $("#cf_img1").val(); // Oddly enough, we dig back down into the original "cropform" to get this value. It's still "underneath" the crop workspace.

                    var newSection = createSection(xOffset_ratio, yOffset_ratio, width_ratio, height_ratio, width, src);
                    newSection.initializeSection();
                }
                else {
                    alert('Please select a crop region then press submit.');
                    return false;
                }

            });
        }
    };
})(jQuery);

