(function (b) {
  // One page activation minimum dimensions.
  var op_min_width = 768;
  var op_min_height = 554;

  // Store number of mouse wheel events.
  var scroll_event_counter = 0;
  // Check if document fully loaded.
  var doc_loaded = false;
  // Next section animation flag (to check if it's running).
  var animation_running = false;
  // Last animation time.
  var lastAnimation = 0;
  // Pause duaration between next animation trigger.
  var quietPeriod = 500;
  // Animation duaration.
  var animationTime = 450;

  // CSS based to determine
  // if window width is greater or not than mobile breakpoint
  var is_mobile = function () {
    return b('button.icon-menu').is(':visible');
  };

  // Widnow dimensions.
  var p = b(window).height();
  var win_w = b(window).width();

  b("html").removeClass("no-js").addClass("js");
  // Set all properties for section.
  var a = function (o) {
    if (!o.is(":visible")) {
      return {
        distance: -1,
        absolute_distance: -1,
        visible: 0,
        position: -1
      }
    }
    var h = b(window).scrollTop();
    var p = b(window).height();
    var win_w = b(window).width();
    var d = h + p;
    var f = h + (p / 2); // scroll position + half window height
    var q = o.offset();
    var k = q.top; // section position
    // If it's first section add fixed positioned header height.
    if (o.attr('id') == 'home') {
      if (!is_mobile()) {
        k += b("#navbar").height();
      }
      else {
        k += b("#tools").height();
      }
    }
    var j = o.height(); // section height
    var g = k + (j / 2); // section position + half section height
    var n = f - g; // if positive section is before scroll else section is after scroll
    var i = "center";
    var e = 1;
    var active = false;
    // if section is before scroll position ...
    if (n > 0) {
      i = "before";
      e = ((k + j) > h + 1); // check if section is visible ( if element position + element height is greater than scroll position )
    }
    // ... section is after scroll position.
    else {
      if (n < 0) {
        i = "after";
        e = (k < d - 1); // check if section is visible ( if element position is less than scroll position + window height )
      }
    }
    if (k - h < (p / 2)) {
      active = true;
    }
    var l = {
      distance: n,
      absolute_distance: Math.abs(n),
      visible: e,
      position: i,
      section_height: j,
      active: active
    };
    return l
  };

  Drupal.behaviors.egov_onepage = {
    attach: function (e, g) {

      //===========
      // Functions
      //===========
      // One page container.
      var onePage = b('#egovselect-page');
      // Page height.
      var page_h = b('#content-to-resize').height();

      // Set some variables.
      var k = b("body");
      var i = b("#home-sections");
      var l = i.find(".home-section:not(.home-sub-section)");
      var d = b("#navigation .block-menu");
      var n = d.find("a");
      var y = onePage.scrollTop();
      // Fixed header offset.
      if (!is_mobile()) {
        var header_offset = 116;
      }
      else {
        var header_offset = 47;
      }

      var menu_element_trigger = function (obj, ev) {
        ev.preventDefault();
        if (location.pathname.replace(/^\//, '') == obj.pathname.replace(/^\//, '') && location.hostname == obj.hostname) {
          scroll_to(obj.hash, 500, true);
        }
      };

      // Scroll/Go to hash location
      var scroll_to = function (hash, time, force) {
        if (animation_running === false && (!k.hasClass('container--has-focus') || force)) {
          var target = b(hash);
          target = target.length ? target : b('[name=' + hash.slice(1) + ']');
          if (target.length) {
            var scroll_to_position = target.position().top;
            if (scroll_to_position >= p - header_offset) {
              scroll_to_position += header_offset;
            }
            // Instant scroll.
            if (time == 0) {
              onePage.scrollTop(scroll_to_position);
              // Update position.
              y = onePage.scrollTop();
              // Set sections classes if visible or not.
              m();
              // Adjust header.
              adjust_header(y);
              // Reset scroll conuner event on new section.
              scroll_event_counter = 0;
              // Remove focus class.
              document.body.classList.remove('container--has-focus');
            }
            // Animate scroll.
            else {
              // Set last animation time.
              lastAnimation = new Date().getTime();
              // Next section animation flag.
              animation_running = true;
              //alert(target.position().top);
              onePage.animate({
                scrollTop: scroll_to_position
              }, time, function () {}).promise().then(function () {
                // Update position.
                y = onePage.scrollTop();
                // Set sections classes if visible or not.
                m();
                // Adjujst header.
                adjust_header(y);
                // Reset scroll conuner event on new section.
                scroll_event_counter = 0;
                // Next section animation flag.
                animation_running = false;
                // Update url.
                window.location.hash = hash;
                // Remove focus class.
                document.body.classList.remove('container--has-focus');
              });
            }
          }
        }
      };

      // If top of the page the show header, otherwise hide it.
      var adjust_header = function (y) {
        if (k.hasClass("header-expanded") && y > 50 && !is_mobile()) {
          k.removeClass("header-expanded");
        } else if (!k.hasClass("header-expanded") && y < 50) {
          k.addClass("header-expanded");
        }
      };

      // Fit sections to screen width and height.
      var fit_sections = function () {
        // Set window height as min-height for all sections for big screens.
        if (win_w >= op_min_width && p >= op_min_height) {
          // Hide scrollbar.
          b('html').addClass('hide-scrollbar');
          // Process all sections.
          l.each(function (i, v) {
            b(this).css('min-height', p);
            // Remove min-height for menu positions in order to fit them
            // to screen size.
            b('.block-navigation .menu li a', this).css('min-height', '0');
            // Set window height as wrapper height,
            // but not for first section.
            if (i != 0) {
              b('.section-wrapper', this).css('height', p);
            }
            // Fit iframe height.
            if (i == 3) {
              var iframe_height = p - 190;
              b('iframe', this).attr('height', iframe_height);
              b('iframe', this).css('height', iframe_height);
            }
            // Fit map height.
            if (i == 4) {
              var map_height = p - 250;
              b('iframe', this).attr('height', map_height);
              b('iframe', this).css('height', map_height);
            }
          });
          // Set one page scroll properties for mobile.
          b('#egovselect-page').css('overflow-y', 'scroll');
          b("html, body, #egovselect-page").css({
            height: p
          });
        }
        // ... otherwise means that it's small screen
        // set view port height as min-height ONLY for first and last sections
        else {
          // Show scrollbar.
          b('html').addClass('hide-scrollbar');
          // Process all sections.
          l.each(function (i, v) {
            b(this).css('min-height', '0');
            // Set min-height for menu positions in order to fit them
            // to screen size.
            b('.block-navigation .menu li a', this).css('min-height', '245px');
            // Set window height to 100% to fit.
            if (i != 0) {
              b('.section-wrapper', this).css('height', "100%");
            }
          });
          // UnSet one page scroll properties for mobile.
          b('#egovselect-page').css('overflow-y', 'auto');
          b('#egovselect-page').css('-webkit-overflow-scrolling', 'touch');
          b("html, body, #egovselect-page").css({
            height: '100%'
          });
        }
        // Update page height.
        page_h = b('#content-to-resize').height();
      };

      var override_scroll_event = function () {
        // For big screens override scroll event.
        if (win_w >= op_min_width && p >= op_min_height) {
          b(window).bind('mousewheel DOMMouseScroll MozMousePixelScroll', function (event) {
            var timeNow = new Date().getTime();
            // Cancel scroll if currently animating or within quiet period
            if (timeNow - lastAnimation < quietPeriod + animationTime) {
              event.preventDefault();
              return false;
            }
            // Reset scroll event counter when top or bottom of the page.
            if (y == 0 || y >= page_h - p) {
              scroll_event_counter = 0;
            }
            // If it's not first mouse wheel keep default behaviour.
            if (scroll_event_counter > 0) {
              // If it's during animation prevent scrolling.
              if (animation_running) {
                event.preventDefault();
                return false;
              }
            }
            // ... otherwise scroll just one pixel to avoid "jump effect".
            else {
              event.preventDefault();
              if (animation_running === false) {
                scroll_event_counter++;
                var delta = parseInt(event.originalEvent.wheelDelta || -event.originalEvent.detail);
                // If scroll is strong enaugh.
                if (Math.abs(delta) >= 1) {
                  // Check it it's scroll down or up
                  // - if negative delta it means scrolling up
                  // - if positive delta it meants scrolling down
                  if (delta > 0) y -= 2;
                  else y += 2;
                  // Prevent setup scroll position
                  // greater than height of document.
                  if (y + p - header_offset > page_h) {
                    y = page_h + header_offset - p;
                  }
                  onePage.scrollTop(y);
                }
              }
            }
          });

          // Handler for scrolling keys
          b(document).keydown(function (e) {
            //Scrolling keys array
            var sk = [38, 40, 32, 33, 34, 36, 35];
            if (sk.indexOf(e.which) != -1) {
              // Reset scroll event counter when top or bottom of the page.
              if (y == 0 || y >= page_h - p) {
                scroll_event_counter = 0;
              }
              // If it's not first mouse wheel keep default behaviour.
              if (scroll_event_counter > 0) {
                // If it's during animation prevent scrolling.
                if (animation_running) {
                  return false;
                }
              }
              // ... otherwise scroll just one pixel to avoid "jump effect".
              else {
                e.preventDefault();
                if (animation_running === false) {
                  scroll_event_counter++;
                  var tag = e.target.tagName.toLowerCase();
                  var delta = 1;
                  // Bind key events.
                  switch (e.which) {
                  case 38:
                    // up arrow
                    if (tag != 'input' && tag != 'textarea') delta = 1;
                    break;
                  case 40:
                    // down arrow
                    if (tag != 'input' && tag != 'textarea') delta = -1;
                    break;
                  case 32:
                    //spacebar
                    if (tag != 'input' && tag != 'textarea') delta = -1;
                    break;
                  case 33:
                    //pageg up
                    if (tag != 'input' && tag != 'textarea') delta = 1;
                    break;
                  case 34:
                    //page dwn
                    if (tag != 'input' && tag != 'textarea') delta = -1;
                    break;
                  case 36:
                    //home
                    delta = 1;
                    break;
                  case 35:
                    //end
                    delta = -1;
                    break;
                  default:
                    return;
                  }
                  // Check it it's scroll down or up
                  // - if negative delta it means scrolling up
                  // - if positive delta it meants scrolling down
                  if (delta > 0) y -= 2;
                  else y += 2;
                  // Prevent setup scroll position
                  // greater than height of document.
                  if (y + p - header_offset > page_h) {
                    y = page_h + header_offset - p;
                  }
                  onePage.scrollTop(y);
                }
              }
            }
          });

          // Prevent native touch activity like scrolling.
          var lastY = 0;
          b('#egovselect-page').on("touchmove", function (event) {
            event.preventDefault();
            event.stopPropagation();
            var currentY = event.originalEvent.touches[0].clientY;
            if (Math.abs(currentY - lastY) >= 50) {
              if (currentY > lastY) {
                y += 2;
              } else if (currentY < lastY) {
                y -= 2;
              }

              onePage.scrollTop(y);
            }
            lastY = currentY;
          });
        }
      };
      var default_scroll = function () {
        // Unbind override scroll event.
        b(window).unbind('mousewheel DOMMouseScroll MozMousePixelScroll');
      };

      // Set links  and sections classes if active or not.
      var o = function (r) {
        if (r == null) {
          l.filter(".section-active").trigger("deactivate");
          l.removeClass("section-active");
          n.removeClass("section-link-active").blur()
        } else {
          l.filter(".section-active").not(r).trigger("deactivate");
          if (!r.hasClass("section-active")) {
            r.trigger("activate")
          }
          l.not(r).removeClass("section-active");
          r.addClass("section-active");
          var t = r.attr("id");
          var s = n.filter('a[href$="#' + t + '"]');
          n.not(s).removeClass("section-link-active").blur();
          s.addClass("section-link-active")
        }
      };
      // Set sections classes if visible or not.
      var m = function (t) {
        var s = null;
        var u = false;
        var v = null;
        var r = null;
        var sections_height = 0;
        l.each(function () {
          var z = a(b(this));
          sections_height += z.section_height;
          var y = b(this).attr("id");
          var x = 'section[id="' + y + '"]';
          var w = n.filter('a[href$="#' + y + '"]');

          if (s == null || z.active) {
            v = b(this);
            if (typeof w != "undefined") {
              r = w
            }
            s = z;
            s.name = y;
          }
          if (z.visible) {
            if (!b(this).hasClass("section-visible")) {
              b(this).trigger("appear")
            }
            b(this).addClass("section-visible");
            w.addClass("section-link-visible");
            u = true
          } else {
            if (b(this).hasClass("section-visible")) {
              b(this).trigger("disappear")
            }
            b(this).removeClass("section-visible");
            w.removeClass("section-link-visible")
          }
          // Set classes related to scroll position.
          b(this).removeClass("section-after");
          b(this).removeClass("section-before");
          w.removeClass("section-link-before");
          w.removeClass("section-link-after");
          b(this).addClass("section-" + z.position);
          w.addClass("section-link-" + z.position);
          if (u) {
            k.addClass("sections-visible");
            o(v)
          } else {
            k.removeClass("sections-visible");
            o(null)
          }
        });
        l.sections_height = sections_height;
      };

      //===========
      //  Actions
      //===========
      // Fit sections to screen width and height.
      fit_sections();
      // When the document is loaded completely.
      b(window).load(

      function () {
        // Set flag.
        doc_loaded = true;
        // Jump to hash location
        var hash = window.location.hash;
        if (hash) {
          scroll_to(hash, 0, false);
        }
        // Set sections classes if visible or not.
        m();
        // Override scroll event.
        override_scroll_event();
      });

      //=============
      // Bind events
      //=============
      // Setup scroll event.
      onePage.scroll(function () {
        // Update position.
        y = onePage.scrollTop();
        adjust_header(y);
        // Set sections classes if visible or not.
        m();
        if (!b('html, body').is(':animated') && animation_running === false && doc_loaded) {
          // If it's big screen.
          if (win_w >= op_min_width && p >= op_min_height) {
            // Detect if section become visible and scroll to it.
            l.each(function (i, v) {
              if (b(this).hasClass("section-visible") && !b(this).hasClass("section-active")) {
                scroll_to("#" + b(this).attr('id'), animationTime, false);
              }
            });
          }
        }
      });

      // Setup window resize event
      b(window).resize(function () {
        // Update dimensions.
        p = b(window).height();
        win_w = b(window).width();
        // Fit sections to screen width and height.
        fit_sections();
        // Update padding top regarding to header height.
        if (!is_mobile()) {
          b("#content-to-resize").css("padding-top", b("#navbar").height());
          header_offset = 116;
          if (y > 50) {
            k.removeClass("header-expanded");
          }
        } else {
          k.addClass("header-expanded");
          b("#content-to-resize").css("padding-top", b("#tools").height());
          header_offset = 47;
        }
      });

      // On menu position click - animate scroll to particular section.
      b('a[href*="#"]:not([href="#"])').click(function (e) {
        menu_element_trigger(this, e);
      });

    }
  };
})(jQuery);