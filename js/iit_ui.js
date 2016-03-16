//was called script3
var image1Top = 350;
var image2Top = 350;
var image1Left = 0;
var image2Left = 150;

$(function () {
    var image1_src, image2_src, image2_offset, image2_height, image2_width, image1_dimW, image1_dimH, image2_dimW, image2_dimH, image1_clientWidth, image2_clientWidth, imageSize, imageSizePrefix, screenRatio,
            previousImagePrefix;

    var vf400img1Height, vf400img2Height;
    screenRatio = 0.96;
    previousImagePrefix = '800px';
    var cl_windowWidth = $(window).width();
    console.log("window width: " + cl_windowWidth);
    var cl_windowHeight = $("#image1").height();
    console.log("window img1 height: " + cl_windowHeight);
    imageSize = Math.floor((cl_windowWidth * screenRatio) / 2);
    console.log("image size: " + imageSize);
    imageSizePrefix = calculateImagePrefix(imageSize);


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

    function setPortraitView() {
        image1Top = 260;
        image2Top = 0;
        image1Left = 410;
        image2Left = 810;

    }
    function setLandscapeView() {

        image1Top = 468;
        image2Top = 468;
        image1Left = 0;
        image2Left = 0;

    }


    function replaceImagePrefix(prev, next) {
        $(".ui-thumb img").each(function () {
            var src = $(this).attr('data-lrg-url');
            var that = this;
            $.post("agile/iit/imagederivative", {size: next, path: src}, function (data) {
                $(that).attr('data-lrg_url', data);
                $.get(data); // This initializes the derivatives.
            });
        });
        previousImagePrefix = next;
    }

    $(".ui-thumb").draggable({
        cursor: "move",
        revert: "false",
        helper: "clone",
        scroll: false

    }).on('dragstart', function (e, ui) {
        $(ui.helper).css('z-index', '99999');
    });

    function write_attributes() {
        $('.iit-thumb img').each(function () {
            width = $(this).attr('data-width');
            height = $(this).attr('data-height');
            $(this).attr("data-dimensions", width + ' cm x ' + height + ' cm');
            $(this).attr("data-orientation", 'landscape');
        });
    }
    write_attributes();
    replaceImagePrefix(previousImagePrefix, imageSizePrefix);

    $(".img-container").droppable({
        // accept: ".ui-thumb",
        hoverClass: "iit-ui-state-hover",
        drop: function (event, ui) {
            var src = ui.draggable.find('img').attr("data-lrg_url");
            var vfsrc = src.replace(imageSizePrefix, "800px");
            var vf400src = src.replace(imageSizePrefix, "400px");
            $(this).find("img").remove();

            var title = ui.draggable.find('img').attr("alt");
            var dimensions = ui.draggable.find('img').attr("data-dimensions");
            var height = ui.draggable.find('img').attr("data-height");
            var width = ui.draggable.find('img').attr("data-width");
            var date = ui.draggable.find('img').attr("data-date");
            var support = ui.draggable.find('img').attr("data-support");

            var orientation = ui.draggable.find('img').attr("data-orientation");
            if (orientation === "portrait") {
                setPortraitView();
            }
            else if (orientation === "landscape") {
                setLandscapeView();
            }

            $(this).find("h4").html(title);
            var newImage = "<a href='" + src + "'><img onerror='imgError()'  alt='" + title + "' src='" + src + "' data-dimensions='" + dimensions + "' data-height='" + height + "' data-width='" + width + "' data-orientation='" + orientation + "' data-date='" + date + "' data-support='" + support + "'> </a>";
            var newImageElm = $(newImage).appendTo(this);

            if (this.id === "image1")
            {
                image1_src = src;
                image1_dimH = $(this).find('img').attr('data-height');
                image1_dimW = $(this).find('img').attr('data-width');
                image1_clientWidth = $(this).find('img').width();

                $("#vf_img1").val(vfsrc);
                $("#cf_img1").val(src);
                var vf400img1 = new Image();
                vf400img1.src = vf400src;
                vf400img1Height = vf400img1.height;
                vf400img1Width = vf400img1.width;
                delete vf400img1;
                $.get(vfsrc)
                        .done(function () {
                            var newvfsrc = vfsrc.split("/");
                        })
                        .fail(function () {
                            var newvfsrc = vfsrc.split("/", 6);
                            newvfsrc = newvfsrc.join("/");
                            newvfsrc = newvfsrc.replace("/thumb", "");
                            $("#vf_img1").val(newvfsrc);
                        });

            }
            else
            {
                image2_src = src;
                image2_dimH = $(this).find('img').attr('data-height');
                image2_dimW = $(this).find('img').attr('data-width');
                image2_clientWidth = $(this).find('img').width();

                $("#vf_img2").val(vfsrc);
                $("#cf_img2").val(src);
                var vf400img2 = new Image();
                vf400img2.src = vf400src;
                vf400img2Height = vf400img2.height;
                delete vf400img2;
                $.get(vfsrc)
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

    var resizeListener = function () {
        imageSize = Math.floor(($(window).width() * screenRatio) / 2);
        imageSizePrefix = calculateImagePrefix(imageSize);
        if (imageSizePrefix !== previousImagePrefix) {
            replaceImagePrefix(previousImagePrefix, imageSizePrefix);
        }
    };

    function updateCoords(c){
        $('#x').val(c.x);
        $('#y').val(c.y);
        $('#w').val(c.w);
        $('#h').val(c.h);
    }

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
            myOverlay.id = 'overlay2';
            $('#iit_container').append(myOverlay);


            var values = $(this).serializeArray();
            values.push({name: "container_width", value: $('#iit_container').width()});
            $(".img-container").hide();
            $.post("agile/iit/crop", values, function (data) {
                $("#overlay2").append(data);
                $('#crop_target').Jcrop({onSelect: updateCoords});
                image2_offset = $("#ol_i2 img").offset();
                image2_height = $("#ol_i2 img").height();
                image2_width = $("#ol_i2 img").width();

            });
        }
    });



    $(document).on('submit', '#cropform2', function (e) {
        e.preventDefault();
        if (parseInt($('#w').val())) {
            var values = $(this).serializeArray();
            var src = $("#cf_img1").val();
            var c_w = $("#crop_target").width();
            var c_h = $("#crop_target").height();
            values.push({name: 'src', value: src});
            values.push({name: 'c_w', value: c_w});
            values.push({name: 'c_h', value: c_h});
            $.post("agile/iit/croptool", values, function (data) {
                $("#results").append(data);
                $(".draggable").draggable({containment: "window"});
                $(".resizable").resizable().find('img').css({"width": "78%"});
                $(".rotatable").rotatable();

            });

        }
        else {
            alert('Please select a crop region then press submit.');
            return false;
        }

    });

    $(document).on('submit', '#view_reset', function (e) {
        e.preventDefault();
        $('.img-container > a').empty();
        $('.img-container > h4').text("Image");
        var elementExists = document.getElementById("img_overlay1");
        if (elementExists) {
            var element1 = document.getElementById("img_overlay1");
            element1.parentNode.removeChild(element1);
            var element2 = document.getElementById("img_overlay2");
            element2.parentNode.removeChild(element2);
        }

    });



    $(document).on('click', '#cl_close', function () {
        $('#overlay2').remove();
        $(".img-container").show();
    });


    $(document).on('click', '#results', function (event) {
        var $item = $(this), $target = $(event.target);



        if ($target.is(".ui-icon-close")) {
            //$target.parent().parent().remove();
            $target.parent().parent().fadeOut(300, function () {
                $(this).remove();
            })
        }
        else if ($target.is(".ui-icon-arrowstop-1-e")) {

            var myid2 = $target.parent().find('img').attr('id');

            $("#" + myid2).toggleClass("flip");
        }

        else if ($target.is(".ui-icon-info")) {
            var sectionOffset = $target.parent().find('img').offset();
            var sectionHeight = $target.parent().find('img').height();
            var sectionWidth = $target.parent().find('img').width();
            var sectionImage = $target.parent().find('img').attr("src");
            var sectionWRatio = $target.parent().find('img').attr("data-ratiow");
            var sectionHRatio = $target.parent().find('img').attr("data-ratioh");

            var x = sectionOffset.left;
            var y = sectionOffset.top;
            var x1 = x + sectionWidth;
            var y1 = y + sectionHeight;

            var title1 = $("#image1").find('img').attr("alt");
            var title2 = $("#image2").find('img').attr("alt");

            var dimensions1 = $("#image1").find('img').attr("data-dimensions");
            var dimensions2 = $("#image2").find('img').attr("data-dimensions");

            var date1 = $("#image1").find('img').attr("data-date");
            var date2 = $("#image2").find('img').attr("data-date");

            var support1 = $("#image1").find('img').attr("data-support");
            var support2 = $("#image2").find('img').attr("data-support");

            var image2w = $('#ol_i2').find('img').width();
            var image2h = $('#ol_i2').find('img').height();

            if (x >= image2_offset.left && x <= image2_offset.left + image2_width &&
                    y >= image2_offset.top && y <= image2_offset.top + image2_height &&
                    x1 >= image2_offset.left && x1 <= image2_offset.left + image2_width &&
                    y1 >= image2_offset.top && y1 <= image2_offset.top + image2_height
                    ) {
                console.log("inbounds");
                console.log(sectionImage);
                var values = new Array();
                image2_src = $("#cf_img2").val();
                values.push({name: 'sectImg', value: sectionImage});
                values.push({name: 'sectImgW', value: sectionWidth});
                values.push({name: 'sectImgH', value: sectionHeight});
                values.push({name: 'image2', value: image2_src});
                values.push({name: 'x', value: x - image2_offset.left});
                values.push({name: 'y', value: y - image2_offset.top});
                values.push({name: 'w1ratio', value: sectionWRatio});
                values.push({name: 'h1ratio', value: sectionHRatio});
                values.push({name: 'img1_dimH', value: image1_dimH});
                values.push({name: 'img1_dimW', value: image1_dimW});
                values.push({name: 'img2_dimH', value: image2_dimH});
                values.push({name: 'img2_dimW', value: image2_dimW});
                values.push({name: 'title1', value: title1});
                values.push({name: 'title2', value: title2});
                values.push({name: 'dimensions1', value: dimensions1});
                values.push({name: 'dimensions2', value: dimensions2});
                values.push({name: 'date1', value: date1});
                values.push({name: 'date2', value: date2});
                values.push({name: 'support1', value: support1});
                values.push({name: 'support2', value: support2});
                values.push({name: 'image2w', value: image2w});
                values.push({name: 'image2h', value: image2h});
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
