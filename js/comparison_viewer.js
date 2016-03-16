/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

(function ($) {

    Drupal.behaviors.agileIITComparison = {
        attach: function (context, settings) {
            $(document).on('click', '#ol_close', function () {
                $('.zoom').find('.zoomy').remove();
                $('#overlay2').remove();
                $("#resizable-gallery-wrapper").show();
                $("#page-title").show();
            });
            $("#viewform").submit(function (e) {
                e.preventDefault();
                var tmp1 = $("#vf_img1").val();
                var tmp2 = $("#vf_img2").val();
                if (tmp1 === "" || tmp2 === "") {
                    alert("Two images must be selected to use comparison viewer.");
                    return false;
                }
                else {
                    $("#resizable-gallery-wrapper").hide();
                    $("#page-title").hide();
                    var container_width = $('#iit_container').width();
                    var container_height = $('#iit_container').height();
                    var myOverlay = document.createElement('div');
                    myOverlay.id = 'overlay2';
                    $('#iit_container').append(myOverlay);
                    $('#overlay2').width(container_width);
                    $('#overlay2').height(container_height + 100);
                    var values = $(this).serializeArray();
                    $.post("agile/iit/twoviews", values, function (data) {
                        $("#overlay2").append(data);
                        var ol_width = $("#overlay2").width();
                        var ol_height = $("#overlay2").height();
                        // Set image dimensions before calling zoomy.
                        var height = ol_height.toString() + 'px';
                        $("#ol_i1").css("width", ol_width / 2 - 50);
                        $("#ol_i2").css("width", ol_width / 2 - 50); // note: this gets called during window resize.

                        var top = Math.max($('#ol_i1').height(), $('#ol_i2').height()) + 5;
                        image1Top = top;
                        image2Top = top;

                        $('.zoom').zoomy({
                            zoomSize: 256,
                            round: false,
                            border: '6px solid #fff'
                        });

                        // $('.zoom').zoomy({border: '5px solid #fff', zoomSize: '250'});
                        // $('.zoomy').css("top", '468').css("bottom", '20px');


                    });

                }
            });

        }
    };
})(jQuery);



// Comparison Viewer
