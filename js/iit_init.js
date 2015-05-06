$(function() {

  $(document).on('click', '#open_new', function() {
    alert("here");
    var myWindow2 = window.open("imgTool4.php", "MsgWindow2", "resizable=yes, fullscreen=yes, scrollbars=1");
  });

});