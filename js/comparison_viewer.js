/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

(function ($) {
    'use strict';
    Drupal.behaviors.agileIITComparison = {
        attach: function (context, settings) {
            $("#viewform").submit(function (e) {
                e.preventDefault();
                var tmp1 = $("#vf_img1").val();
                var tmp2 = $("#vf_img2").val();
                if (tmp1 === "" || tmp2 === "") {
                    alert("Two images must be selected to use comparison viewer.");
                    return false;
                }
                else {
                    var container_width = $('#iit_container').width();
                    var container_height = $('#iit_container').height();
                    var myOverlay = document.createElement('div');
                    myOverlay.id = 'overlay2';
                    $('#iit_container').append(myOverlay);
                    $('#overlay2').width(container_width);
                    $('#overlay2').height(container_height);
                    var values = $(this).serializeArray();
                    $.post("agile/iit/twoviews", values, function (data) {
                        $("#overlay2").append(data);
                        var ol_width = $("#overlay2").width();
                        // Set image dimensions before calling zoomy.
                        $("#ol_i1").css("width", ol_width / 2 - 50);
                        $("#ol_i2").css("width", ol_width / 2 - 50); // note: this gets called during window resize.
                        $('.zoom').zoomy({border: '5px solid #fff'});
                        $('.zoomy').css("top", '').css("bottom", '20px');


                    });

                }
            });

        }
    };
})(jQuery);



// Comparison Viewer
