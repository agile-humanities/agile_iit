//was called script3
var image1Top = 350;
var image2Top = 350;
var image1Left = 0;
var image2Left = 150;


$(function() {
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

    $(".ui-thumb img").each(function() {
      var entry2 = $(this).attr('data-lrg_url');
      entry2 = entry2.replace(prev, next);
      $(this).attr('data-lrg_url', entry2);

    });
    previousImagePrefix = next;
  }

  $(".views-field").draggable({
    cursor: "move",
    revert: "false",
    helper: "clone",
    scroll: false

  });



  function initializeImages() {
    $(".ui-thumb img").each(function() {
      var entry2 = $(this).attr('data-lrg_url');
      var that = this;

      $.get(entry2)
          .done(function() {
        console.log("yes in main images folder");
      })
          .fail(function() {
        console.log("not in main images folder");

        var tmpentry = entry2.split("/");
        tmpentry = tmpentry.pop();

        var re = /^(\d{2,3}px)\-(.*)$/;

        var match = re.exec(tmpentry);
        tmpentry = "../tmp2/images/" + match[1] + "/" + match[2];
        var entry3 = $(that).attr('data-lrg_url');
        $(that).attr('data-lrg_url', tmpentry);


        $.get(tmpentry)
            .done(function() {
          console.log("yes in tmp images folder");
        })
            .fail(function() {

          var values = new Array();
          values.push({src: entry2});

          entry2 = entry2.split("/", 6);
          entry2 = entry2.join("/");
          entry2 = entry2.replace("/thumb", "");

          $.post("makeimage.php", {src: entry2, pre: imageSizePrefix}, function(data) {

          });

        });


      });


    });
  }

  replaceImagePrefix(previousImagePrefix, imageSizePrefix);
  initializeImages();

  $(".img-container").droppable({
    accept: ".ui-thumb",
    drop: function(event, ui) {
      //console.log(this);
      var src = ui.draggable.find('img').attr("data-lrg_url");
      console.log(src);
      var vfsrc = src.replace(imageSizePrefix, "800px");
      var vf400src = src.replace(imageSizePrefix, "400px");
      //src = src.replace("120px","800px");
      console.log(src, vfsrc);
      console.log(vf400src);

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

      //console.log(title);
      $(this).find("h4").html(title);
      // var newImage = "<a href='" + src + "'><img src='" + src + "'> </a>";

      var newImage = "<a href='" + src + "'><img onerror='imgError()'  alt='" + title + "' src='" + src + "' data-dimensions='" + dimensions + "' data-height='" + height + "' data-width='" + width + "' data-orientation='" + orientation + "'> </a>";
      //console.log(newImage);
      var newImageElm = $(newImage).appendTo(this);

      if (this.id === "image1")
      {
        image1_src = src;
        image1_dimH = $(this).find('img').attr('data-height');
        // console.log(image1_dimH);
        image1_dimW = $(this).find('img').attr('data-width');
        image1_clientWidth = $(this).find('img').width();
        console.log(image1_clientWidth);
        // console.log(image1_dimW);
        // console.log(image1_src);
        // console.log(image2_src);
        $("#vf_img1").val(vfsrc);
        $("#cf_img1").val(src);
        var vf400img1 = new Image();
        vf400img1.src = vf400src;
        vf400img1Height = vf400img1.height;
        vf400img1Width = vf400img1.width;
        console.log("vf400img1Height " + vf400img1Height);
        delete vf400img1;
        $.get(vfsrc)
            .done(function() {
          console.log("vfsrc done" + vfsrc);
          var newvfsrc = vfsrc.split("/");
          console.log("newvfsrc" + newvfsrc);
        })
            .fail(function() {
          console.log("vfsrc fail" + vfsrc);
          var newvfsrc = vfsrc.split("/", 6);
          newvfsrc = newvfsrc.join("/");
          newvfsrc = newvfsrc.replace("/thumb", "");
          console.log("newvfsrc" + newvfsrc);
          $("#vf_img1").val(newvfsrc);
        });

      }
      else
      {
        image2_src = src;
        image2_dimH = $(this).find('img').attr('data-height');
        //console.log(image2_dimH);
        image2_dimW = $(this).find('img').attr('data-width');
        image2_clientWidth = $(this).find('img').width();
        console.log(image2_clientWidth);
        //console.log(image2_dimW);
        //console.log(image1_src);
        //console.log(image2_src);
        $("#vf_img2").val(vfsrc);
        $("#cf_img2").val(src);
        var vf400img2 = new Image();
        vf400img2.src = vf400src;
        vf400img2Height = vf400img2.height;
        console.log("vf400img2Height " + vf400img2Height);
        delete vf400img2;
        $.get(vfsrc)
            .done(function() {
          console.log("vfsrc done" + vfsrc);
          var newvfsrc = vfsrc.split("/");
          console.log("newvfsrc" + newvfsrc);
        })
            .fail(function() {
          console.log("vfsrc fail" + vfsrc);
          var newvfsrc = vfsrc.split("/", 6);
          newvfsrc = newvfsrc.join("/");
          newvfsrc = newvfsrc.replace("/thumb", "");
          console.log("newvfsrc" + newvfsrc);
          $("#vf_img2").val(newvfsrc);
        });


      }



    }


  });

  var resizeListener = function() {
    console.log($(window).width());

    imageSize = Math.floor(($(window).width() * screenRatio) / 2);
    imageSizePrefix = calculateImagePrefix(imageSize);
    console.log("resized" + imageSizePrefix);
    if (imageSizePrefix !== previousImagePrefix) {
      replaceImagePrefix(previousImagePrefix, imageSizePrefix);
      initializeImages();
    }




  };

  window.addEventListener('resize', resizeListener, false);

  var resizeOverlayListener = function() {

    if (overlay) {
      //alert("viewform overlay");
      overlay.style.top = window.pageYOffset + 'px';
      overlay.style.left = window.pageXOffset + 'px';
      overlay.style.width = window.innerWidth + 'px';
      overlay.style.height = window.innerHeight + 'px';
    }
    else if (overlay2) {
      overlay2.style.top = window.pageYOffset + 'px';
      overlay2.style.left = window.pageXOffset + 'px';
      overlay2.style.width = window.innerWidth + 'px';
      overlay2.style.height = window.innerHeight + 'px';
    }
  };

  window.addEventListener('resize', resizeOverlayListener, false);

  var listener = function() {
    //alert("scroll");
    if (overlay) {
      //alert("viewform overlay");
      overlay.style.top = window.pageYOffset + 'px';
      overlay.style.left = window.pageXOffset + 'px';
    }
    else if (overlay2) {
      overlay2.style.top = window.pageYOffset + 'px';
      overlay2.style.left = window.pageXOffset + 'px';
    }
  };

  window.addEventListener('scroll', listener, false);



  $("#gridform").submit(function(e) {
    e.preventDefault();

    //console.log(e);
    var tmp1 = $("#vf_img1").val();
    var tmp2 = $("#vf_img2").val();
    //console.log(tmp1);
    //console.log(tmp2);
    var elementExists = document.getElementById("img_overlay1");

    if (elementExists) {
      var element1 = document.getElementById("img_overlay1");
      element1.parentNode.removeChild(element1);
      var element2 = document.getElementById("img_overlay2");
      element2.parentNode.removeChild(element2);
    }

    else if (tmp1 === "" || tmp2 === "")
    {
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



      console.log(img1top.top, img1top.left, img1w, img1h);
      console.log(img2top.top, img2top.left, img2w, img2h);


      var overlay1 = $('<div id="img_overlay1"> </div>');
      var overlay2 = $('<div id="img_overlay2"> </div>');


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
      overlay2.append(table2);

      $("#image1").append(overlay1);
      $("#image2").append(overlay2);

      $("#img_overlay1").css("top", img1top.top);
      $("#img_overlay1").css("left", img1top.left);
      $("#img_overlay1").css("width", img1w);
      $("#img_overlay1").css("height", img1h);

      $("#img_overlay2").css("top", img2top.top);
      $("#img_overlay2").css("left", img2top.left);
      $("#img_overlay2").css("width", img2w);
      $("#img_overlay2").css("height", img2h);


    }
  });

  $("#viewform").submit(function(e) {
    e.preventDefault();

    //console.log(e);
    var tmp1 = $("#vf_img1").val();
    var tmp2 = $("#vf_img2").val();
    //console.log(tmp1);
    //console.log(tmp2);
    if (tmp1 === "" || tmp2 === "")
    {
      alert("Two images must be selected.");
      return false;
    }
    else
    {
      var myOverlay = document.createElement('div');
      myOverlay.id = 'overlay';
      document.body.appendChild(myOverlay);
      /*var myPframe = window.parent.document.getElementById('globalWrapper');
       myPframe.appendChild(myOverlay);
       myOverlay.style.zIndex = '1001';
       myOverlay.style.position = 'absolute';*/
      myOverlay.style.width = window.innerWidth + 'px';
      myOverlay.style.height = window.innerHeight + 1000 + 'px';
      myOverlay.style.top = window.pageYOffset + 'px';
      myOverlay.style.left = window.pageXOffset + 'px';
      //myOverlay.style.top = 0 + 'px';
      //myOverlay.style.left =0 + 'px';


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

        //imagesTop=Math.max(imagesTop, vf400img2Height, vf400img1Height);
      }


      var values = $(this).serializeArray();
      //console.log(values);
      $.post("twoviews.php", values, function(data) {
        //alert(data);
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
  ;



  $("#cropform").submit(function(e) {
    e.preventDefault();
    var tmp1 = $("#cf_img1").val();
    var tmp2 = $("#cf_img2").val();
    if (tmp1 === "" || tmp2 === "")
    {
      alert("Two images must be selected.");
      return false;
    }
    else
    {
      $(window).scrollTop(0);
      var myOverlay = document.createElement('div');
      myOverlay.id = 'overlay2';
      document.body.appendChild(myOverlay);
      myOverlay.style.width = window.innerWidth + 'px';
      myOverlay.style.height = window.innerHeight + 1000 + 'px';
      myOverlay.style.top = window.pageYOffset + 'px';
      myOverlay.style.left = window.pageXOffset + 'px';

      var values = $(this).serializeArray();
      values.push({name: "pre", value: imageSizePrefix});
      console.log(values);
      $.post("cropviews.php", values, function(data) {
        //alert(data);
        $("#overlay2").append(data);
        $("#cropform2").onSubmit = function() {
          return checkCoords();
        }
        $('#crop_target').Jcrop({onSelect: updateCoords});
        //console.log($("#ol_i1 img:first-child").position());
        //console.log($("#ol_i1 img:first-child").offset());
        //console.log($("#ol_i2 img:first-child").position());
        //console.log($("#ol_i2 img:first-child").offset());
        image2_offset = $("#ol_i2 img:first-child").offset();
        image2_height = $("#ol_i2 img:first-child").height();
        image2_width = $("#ol_i2 img:first-child").width();


        //console.log(image2_offset);
        //console.log(image2_height);
        //console.log(image2_width);


      });

    }
  });



  $(document).on('submit', '#cropform2', function(e) {
    e.preventDefault();
    if (parseInt($('#w').val())) {
      //console.log(e);
      var values = $(this).serializeArray();
      var src = $("#cf_img1").val();
      var c_w = $("#crop_target").width();
      var c_h = $("#crop_target").height();
      values.push({name: 'src', value: src});
      values.push({name: 'c_w', value: c_w});
      values.push({name: 'c_h', value: c_h});
      //console.log(values);
      $.post("crop2.php", values, function(data) {
        // alert(data);
        $("#results").append(data);

        $(".draggable").draggable({containment: "window"});
      });

    }
    else {
      alert('Please select a crop region then press submit.');
      return false;
    }

  });

  $(document).on('click', '#ol_close', function() {
    $('.zoom').find('.zoomy').remove();
    $('#overlay').remove();
  });

  $(document).on('click', '#cl_close', function() {
    $('#overlay2').remove();
  });


  $(document).on('click', '#results', function(event) {
    var $item = $(this), $target = $(event.target);



    if ($target.is(".ui-icon-close")) {
      //$target.parent().parent().remove();
      $target.parent().parent().fadeOut(300, function() {
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
      //console.log(event);
      //console.log($target.offset());
      //console.log($target.parent().find('img').offset());
      //console.log($target.parent().find('img').position());
      //console.log($target.parent().find('img').width());
      //console.log($target.parent().find('img').height());
      document.body.scrollTop = 0;
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

        //console.log(values);

        $.post("crop3.php", values, function(data) {
          //alert(data);
          var myWindow = window.open('', 'cmpWindow', 'width=800, height=400, scrollbars=yes, toolbar=yes');
          /*$(myWindow.document.body).ready(function(){
           $(myWindow.document.body).append(data);

           });*/



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