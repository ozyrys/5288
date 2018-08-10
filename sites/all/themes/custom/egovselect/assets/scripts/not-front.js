(function ($) {

  var y = $(window).scrollTop();

  // CSS based to determine
  // if window width is greater or not than mobile breakpoint
  var is_mobile = function () {
    return $('button.icon-menu').is(':visible');
  };

  var adjust_header = function (y) {
    // If top of the page the show header, otherwise hide it.
    if ($("body").hasClass("header-expanded") && y > 50 && !is_mobile()) {
      $("body").removeClass("header-expanded");
    } else if (!$("body").hasClass("header-expanded") && y < 50) {
      $("body").addClass("header-expanded");
    }
    // Update content padding regarding to fixed positioned header.
    if (!is_mobile()) {
      $("#content-to-resize").css("padding-top", $("#navbar").height());
    }
    else {
      // Update padding top regarding to header height.
      $("#content-to-resize").css("padding-top", $("#tools").height());
    }
  };

  // Setup scroll event
  $(window).scroll(function () {
    // Update position.
    y = $(window).scrollTop();
    adjust_header(y);
  });

  $(window).bind('resize', function() {
    adjust_header(y);
  });

  $(document).ready(
    function () {
      adjust_header(y);
    }
  );

})(jQuery);