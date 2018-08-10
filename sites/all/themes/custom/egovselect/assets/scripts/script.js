/**
 * @file
 * eGovSelect - JavaScripts (Init)ialization definition.
 * Here are define custom JavaScript functions and all calls to these functions using jQuery Library.
 */

(function ($) {
  // CSS based to determine
  // if window width is greater or not than mobile breakpoint
  var is_mobile = function () {
      return $('button.icon-menu').is(':visible');
  };

  // On window resize event - show/hide mobile menu.
  $(window).bind('resize', function() {
    // If window width is less than 788 then show mobile menu ...
    if (!is_mobile()) {
      $("nav#navigation ul.menu").css("display", "block");
    }
    // else if window width is more than 788 and it should be collapsed
    // (we know about it because of body class "collapsed-main-menu")
    // - then we should hide it.
    else {
      $(".collapsed-main-menu nav#navigation ul.menu").css("display", "none");
    }
  });

  $(document).ready(
    function () {
      // Indicate flexslider
      $('.flexslider').flexslider({
        animation: "slide",
        directionNav: false,
        allowOneSlide: false,
        pausePlay: true
      });
      // Prevent sliding on pager focus, because it's uselessness.
      $('.flex-control-paging a').focus(function (e) {
        $('.flex-pause').click();
      });

      // show searcher input
      $("#edit-submit-solr-pages").click( function ( event ) {
        if (!$("#edit-keyword-wrapper").is(":visible")) {
          event.preventDefault();
          $("#edit-keyword-wrapper").show();
        }
      });

      // Activate gmap
      $('.map-container')
        .click(function(){
          $(this).find('iframe').addClass('clicked')})
        .mouseleave(function(){
          $(this).find('iframe').removeClass('clicked')});

      // Position fixed for search block form when mobile keyboard is active
      if (is_mobile()) {
        $('.block-views--exp-solr-pages-solr-search #edit-keyword').focus(function() {
          $('.block-views--exp-solr-pages-solr-search').addClass('position-fixed');
        });
        $('nav, #tools').click(function() {
          $('.block-views--exp-solr-pages-solr-search').removeClass('position-fixed');
        });
      }

      // if it's mobile version then hide menu after clicking menu link position
      $(".block-menu-main .menu li a").click(function() {
        if (!$('body').hasClass('collapsed-main-menu') && $(".icon-menu").css("display") == "block") {
          $(".icon-menu").click();
        }
      });

      // Override nerra script.
      // From http://scratch99.com/web-development/javascript/convert-bytes-to-mb-kb/
      function bytesToSize(bytes) {
        var sizes = ['Bytes', 'KB', 'MB', 'GB', 'TB'];
        if (bytes == 0) {
          return Drupal.t('n/a');
        }
        var i = parseInt(Math.floor(Math.log(bytes) / Math.log(1024)));
        if (i == 0) {
          return bytes + ' ' + Drupal.t(sizes[i]);
        }
        return (bytes / Math.pow(1024, i)).toFixed(1) + ' ' + Drupal.t(sizes[i]);
      };

      // Append file size to Drupal file links with parent element with class "nerra-filesize":
      $('.nerra-filesize span.file a').each(function() {
        // Get extension from link.
        var extension = $(this).attr("href").split('.').pop().toUpperCase();
        // Get fileSize from size defined in Microformat.
        var fileSize = $(this).attr("type").split('; length=').pop();

        // Check that extension and file size are valid non-empty strings.
        if (typeof fileSize === 'string' && fileSize.length > 0 && typeof extension === 'string' && extension.length > 0) {
          // Append file info to link text.
          $(this).append(Drupal.checkPlain(' (' + extension + ', ' + bytesToSize(fileSize) + ')'));
        }
      });

      // Url persistant.
      $('.url-file-persistent').each(function() {
        // Hide.
        $(this).hide();
        // Get the link.
        var url = $(this).html();
        // Set the new content for the container.
        var output = '<span><input type="text" class="url-file-persistent-input" value="' + url + '"/></span>';
        $(this).html(output);
      });

      // Expand/collapse "url block" to share with the world.
      $(".field-name-file-url-persistent a").each(function() {
        $(this).click(function(e) {
          e.preventDefault();
          $(this).parent().find('span.url-file-persistent').slideToggle('fast', function() {
            $(this).find('span input.url-file-persistent-input').select();
          });
        });
      });

      // Click event enable on the icon-menu.
      $(".icon-menu").click(function() {
        $nav = $("nav#navigation .block-menu").children("ul.menu");
        if ( $nav.is(':animated') ) {
		  return;
		}
        // Border of the icon when active/inactive.
        if ($nav.css("display") == "none") {
          $(this).css({'z-index': '100'});
           // Expand the menu.
           $('body').toggleClass('collapsed-main-menu');
           $nav.slideToggle('fast', 'linear');
        }
        else {
          $(this).css({'z-index': '10'});
          // Collapse the mobile menu.
          $nav.slideToggle('fast', 'linear',function() {
            $('body').toggleClass('collapsed-main-menu');
          });
        }
      });
    }
  );

})(jQuery);