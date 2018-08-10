// topLink function - shows button when vertical scroll exceeds min.
jQuery.fn.topLink = function(settings) {
  settings = jQuery.extend({
    min: 1,
    fadeSpeed: 200
  }, settings);

  // Attach behaviour foreach "this" selector.
  return this.each(function() {

    // Listen for scroll.
    var el = jQuery(this);

    jQuery(window).scroll(function() {
      // If vertical scroll exceeds min(px) then smoothly show the button.
      if(jQuery(window).scrollTop() >= settings.min) {
        el.addClass('visible');
      }
      // Otherwise hide it.
      else {
        el.removeClass('visible');
      }
    });
  });
};

// Usage w/ smoothscroll.
jQuery(document).ready(function() {
  // Prepend totop button just after body selector.
  jQuery('body #egovselect-page').prepend('<a href="#pagetop" name="pagetop" id="top-link" tabindex="-1">&#94;</a>');

  // Set the link (attach behaviour).
  jQuery('#top-link').topLink({
    min: 400,
    fadeSpeed: 500
  });

  // On click - smoothscroll to top.
  jQuery('#top-link').click(function(e) {
    e.preventDefault();
    jQuery("html, body").animate({ scrollTop: 0 }, 600);
    return false;
  });
});
