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
    console.log("window width" + cl_windowWidth);
    var cl_windowHeight = $("#image1").height();
    console.log("window img1 height" + cl_windowHeight);
    imageSize = Math.floor((cl_windowWidth * screenRatio) / 2);
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
        image1Top = 350;
        image2Top = 350;
        image1Left = 0;
        image2Left = 150;

    }


    function replaceImagePrefix(prev, next) {

        $(".ui-thumb img").each(function () {
            var entry2 = $(this).attr('data-lrg_url');
            entry2 = entry2.replace(prev, next);
            $(this).attr('data-lrg_url', entry2);

        });
        previousImagePrefix = next;
    }

    $(".ui-thumb").draggable({
        cursor: "move",
        revert: "false",
        helper: "clone",
        scroll: false

    });

    function initializeImages() {
        $(".ui-thumb img").each(function () {
            var entry2 = $(this).attr('data-lrg_url');
            var that = this;

            $.get(entry2)
                    .done(function () {
                    })
                    .fail(function () {
                        var tmpentry = entry2.split("/");
                        tmpentry = tmpentry.pop();

                        var re = /^(\d{2,3}px)\-(.*)$/;
                        var match = re.exec(tmpentry);
                        tmpentry = "../tmp2/images/" + match[1] + "/" + match[2];
                        var entry3 = $(that).attr('data-lrg_url');
                        $(that).attr('data-lrg_url', tmpentry);
                        $.get(tmpentry)
                                .done(function () {
                                })
                                .fail(function () {
                                    var values = new Array();
                                    values.push({src: entry2});

                                    entry2 = entry2.split("/", 6);
                                    entry2 = entry2.join("/");
                                    entry2 = entry2.replace("/thumb", "");
                                    $.post("agile/iit/makeimage", {src: entry2, pre: imageSizePrefix}, function (data) {
                                    });
                                });
                    });
        });
    }

    function write_attributes() {
        $('.iit-thumb a').each(function () {
            largeurl = $(this).attr('href');
            $(this).find('img').each(function () {
                $(this).attr('data-lrg_url', largeurl);
                $(this).unwrap();
            });
        });
        $('.iit-thumb img').each(function () {
            url = $(this).attr('src');
            width = $(this).attr('width');
            height = $(this).attr('height');
            //$(this).attr("data-lrg_url", url);
            $(this).attr("data-dimensions", width + 'x' + height);
            $(this).attr("data-height", height);
            $(this).attr("data-width", width);
            $(this).attr("data-orientation", 'landscape');
        });
    }
    write_attributes();
    replaceImagePrefix(previousImagePrefix, imageSizePrefix);
    initializeImages();

    $(".img-container").droppable({
        // accept: ".ui-thumb",
        drop: function (event, ui) {
            var src = ui.draggable.find('img').attr("data-lrg_url");
            var vfsrc = src.replace(imageSizePrefix, "800px");
            var vf400src = src.replace(imageSizePrefix, "400px");
            $(this).find("img").remove();

            var title = ui.draggable.find('img').attr("alt");
            var dimensions = ui.draggable.find('img').attr("data-dimensions");
            var height = ui.draggable.find('img').attr("data-height");
            var width = ui.draggable.find('img').attr("data-width");

            var orientation = ui.draggable.find('img').attr("data-orientation");
            if (orientation === "portrait") {
                setPortraitView();
            }
            else if (orientation === "landscape") {
                setLandscapeView();
            }

            $(this).find("h4").html(title);
            var newImage = "<a href='" + src + "'><img onerror='imgError()'  alt='" + title + "' src='" + src + "' data-dimensions='" + dimensions + "' data-height='" + height + "' data-width='" + width + "' data-orientation='" + orientation + "'> </a>";
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
            initializeImages();
        }
    };

    window.addEventListener('resize', resizeListener, false);

    var resizeOverlayListener = function () {

        if (overlay) {
            //alert("viewform overlay");
            overlay.style.top = window.pageYOffset + 'px';
            overlay.style.left = window.pageXOffset + 'px';
            overlay.style.width = window.innerWidth + 'px';
            overlay.style.height = window.innerHeight + 'px';
        }
        else if (overlay) {
            overlay.style.top = window.pageYOffset + 'px';
            overlay.style.left = window.pageXOffset + 'px';
            overlay.style.width = window.innerWidth + 'px';
            overlay.style.height = window.innerHeight + 'px';
        }
    };

    window.addEventListener('resize', resizeOverlayListener, false);

    var listener = function () {
        if (overlay) {
            overlay.style.top = window.pageYOffset + 'px';
            overlay.style.left = window.pageXOffset + 'px';
        }
        else if (overlay) {
            overlay.style.top = window.pageYOffset + 'px';
            overlay.style.left = window.pageXOffset + 'px';
        }
    };
    window.addEventListener('scroll', listener, false);
    $("#gridform").submit(function (e) {
        e.preventDefault();

        var tmp1 = $("#vf_img1").val();
        var tmp2 = $("#vf_img2").val();
        var elementExists = document.getElementById("img_overlay1");

        if (elementExists) {
            var element1 = document.getElementById("img_overlay1");
            element1.parentNode.removeChild(element1);
            var element2 = document.getElementById("img_overlay");
            element2.parentNode.removeChild(element2);
        }

        else if (tmp1 === "" || tmp2 === "") {
            alert("Two images must be selected.");
            return false;
        }
        else
        {
            var img1top = $("#image1").find('img').position();
            var img1w = $("#image1").find('img').width();
            var img1h = $("#image1").find('img').height();

            var img2top = $("#image2").find('img').position();
            var img2w = $("#image2").find('img').width();
            var img2h = $("#image2").find('img').height();

            var overlay1 = $('<div id="img_overlay1"> </div>');
            var overlay = $('<div id="img_overlay"> </div>');


            var table1 = $('<table></table>').addClass('imgtbl');
            for (i = 0; i < 5; i++) {
                var row = $('<tr><td></td><td></td><td></td><td></td><td></td></tr>');
                table1.append(row);
            }
            var table2 = $('<table></table>').addClass('imgtbl');
            for (i = 0; i < 5; i++) {
                var row = $('<tr><td></td><td></td><td></td><td></td><td></td></tr>');
                table2.append(row);
            }

            overlay1.append(table1);
            overlay.append(table2);

            $("#image1").append(overlay1);
            $("#image2").append(overlay);

            $("#img_overlay1").css("top", img1top.top);
            $("#img_overlay1").css("left", img1top.left);
            $("#img_overlay1").css("width", img1w);
            $("#img_overlay1").css("height", img1h);

            $("#img_overlay").css("top", img2top.top);
            $("#img_overlay").css("left", img2top.left);
            $("#img_overlay").css("width", img2w);
            $("#img_overlay").css("height", img2h);
        }
    });

    $("#viewform").submit(function (e) {
        e.preventDefault();
        var tmp1 = $("#vf_img1").val();
        var tmp2 = $("#vf_img2").val();
        if (tmp1 === "" || tmp2 === "") {
            alert("Two images must be selected.");
            return false;
        }
        else {
            var myOverlay = document.createElement('div');
            myOverlay.id = 'overlay';
            document.body.appendChild(myOverlay);
            myOverlay.style.width = window.innerWidth + 'px';
            myOverlay.style.height = window.innerHeight + 1000 + 'px';
            myOverlay.style.top = window.pageYOffset + 'px';
            myOverlay.style.left = window.pageXOffset + 'px';

            if (vf400img1Height != 0 && vf400img2Height != 0) {
                if (vf400img1Height >= vf400img2Height) {
                    imagesTop = vf400img1Height;
                }
                else {
                    imagesTop = vf400img2Height;
                }
            }
            else {
                imagesTop = window.innerHeight - 250;
            }

            var values = $(this).serializeArray();
            $.post("agile/iit/twoviews", values, function (data) {
                $("#overlay").append(data);
                $('.zoom').zoomy({border: '6px solid #fff'});
            });
        }
    });


    function updateCoords(c)
    {
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
            document.body.appendChild(myOverlay);
            myOverlay.style.width = window.innerWidth + 'px';
            myOverlay.style.height = window.innerHeight + 1000 + 'px';
            myOverlay.style.top = window.pageYOffset + 'px';
            myOverlay.style.left = window.pageXOffset + 'px';

            var values = $(this).serializeArray();
            values.push({name: "container_width", value: window.innerWidth * .48});
            $.post("agile/iit/crop", values, function (data) {
                $("#overlay2").append(data);
                $("#cropform2").onSubmit = function () {
                    return checkCoords();
                }
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
            });

        }
        else {
            alert('Please select a crop region then press submit.');
            return false;
        }

    });

    $(document).on('submit', '#view_reset', function (e) {
        e.preventDefault();
        $('.img-container').empty();

    });

    $(document).on('click', '#ol_close', function () {
        $('.zoom').find('.zoomy').remove();
        $('#overlay').remove();
    });

    $(document).on('click', '#cl_close', function () {
        $('#overlay2').remove();
    });


    $(document).on('click', '#results', function (event) {
        var $item = $(this), $target = $(event.target);



        if ($target.is(".ui-icon-close")) {
            //$target.parent().parent().remove();
            $target.parent().parent().fadeOut(300, function () {
                $(this).remove();
            })
        }

        else if ($target.is(".ui-resize")) {
            console.log(event);
            $target.parent().resizable();
            $target.parent().find('img').css({"width": "78%"});

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
            var dimensions1 = $("#image1").find('img').attr("data-dimensions");
            var title2 = $("#image2").find('img').attr("alt");
            var dimensions2 = $("#image2").find('img').attr("data-dimensions");

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