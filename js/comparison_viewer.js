/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
var image1Top, image2Top;
var image1Left = 0;
(function ($) {

    Drupal.behaviors.agileIITComparison = {
        attach: function (context, settings) {
            $(document).on('click', '#ol_close', function () {
                var dims = [];
                $('.zoom').find('.zoomy').remove();
                $('#overlay2').remove();
                $("#resizable-gallery-wrapper").show();
                $("#page-title").show();
            });
            $(document).on('click', '#ol_help', function () {
                var myWindow = window.open('', 'helpWindow', 'width=500, height=500, scrollbars=yes, toolbar=yes');
                myWindow.focus();
                $.get("agile/iit/help", "crop", function(data) {
                    myWindow.document.write(data);
                    myWindow.location.href = "#comparison";
                    myWindow.document.close();
                });
            });
            // Initiate comparison viewer.
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
                    var myOverlay = document.createElement('div');
                    myOverlay.id = 'overlay2';
                    var node1 = $("#image1").find('img').data('nid');
                    var node2 = $("#image2").find('img').data('nid');
                    var baseheight = Math.max($("#image1").find('img').height(), $("#image2").find('img').height());
                    $('#iit_container').append(myOverlay);
                    $('#overlay2').width(container_width);
                    $('#overlay2').height(baseheight + 400);
                    var values = [];
                    values.push({name: "node1", 'value': node1});
                    values.push({name: "node2", 'value': node2});
                    $.post("agile/iit/twoviews", values, function (data) {
                        $("#overlay2").append(data);
                        $(window).scrollTop(0);
                        var ol_width = $("#overlay2").width()/2 - 2;
                        var ol_height = $(window).height()/2 - 28;
                        // Set image dimensions before calling zoomy.
                        //Except now we want to do it based on the height.

                        var height = ol_height.toString() + 'px';
                        // we still want the containers to be half-width sized...
                        $("#ol_i1").css("width", ol_width);
                        $("#ol_i2").css("width", ol_width);
                        $('.two_up_image').css("height", height);

                        var top = Math.max($('#ol_i1').height(), $('#ol_i2').height()) + 5;
                        image1Top = top;
                        image2Top = top;
                        var src1 = $("#ol_i1").find('img').attr('src');
                        var src2 = $("#ol_i1").find('img').attr('src');
                        var img1loaded = 0; // we have to wait for both images to load to determine what size to use.
                        var img2loaded = 0;
                        var img1 = new Image();
                        img1.onload = function() {
                            if (img2loaded) {go()}
                            img1loaded = 1;
                        }
                        img1.src = src1;
                        var img2 = new Image();
                        img2.onload = function() {
                            if (img1loaded) {go()}
                            img2loaded = 1;
                        }
                        img2.src = src2;

                        var go = function(){
                            var minwidth = Math.min(img1.width, img2.width);
                            var minheight = Math.min(img1.height, img2.height);
                            var zoomyWidth = Math.min(minwidth, ol_width);
                            var zoomyHeight = Math.min(minheight, ol_height);
                            $('.zoom').zoomy({
                                round: false,
                                border: '1px solid #fff',
                                zoomWidth: zoomyWidth,
                                zoomHeight: zoomyHeight
                            });
                            $.ajax({
                                url: 'agile/iit/image_dimensions',
                                type: "POST",
                                data: {
                                    img1: $("#ol_i1").find('img').attr('src'),
                                    img2: $("#ol_i2").find('img').attr('src'),
                                },
                                async: false,
                                success: function (results, status, xhr) {
                                    results = JSON.parse(results)
                                    dims = results;
                                },
                                error: function (data, status, xhd) {
                                    console.log("The function execute_callback has failed");
                                }
                            });
                        }


                    });

                }

            });

        }
    };
})(jQuery);

