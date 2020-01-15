/*global Backdrop: false, jQuery: false */
/*jslint devel: true, browser: true, maxerr: 50, indent: 2 */
(function ($) {
  "use strict";

  Backdrop.behaviors.hybridauth_close = {};
  Backdrop.behaviors.hybridauth_close.attach = function(context, settings) {
    var win = window, popup = false;
    try {
      // Check for a popup.
      if (window.opener && window.opener.location.hostname === window.location.hostname) {
        win = window.opener;
        popup = true;
      }
    }
    catch (e) {
    }
    // Check for an iframe.
    if (!popup && window.parent) {
      win = window.parent;
    }
    // Make redirect.
    if (Backdrop.settings.hybridauth.redirect) {
      win.location.href = Backdrop.settings.hybridauth.destination;
    }
    else {
      win.location.href = Backdrop.settings.hybridauth.destination_error;
    }
    // Close the popup window.
    if (popup) {
      window.self.close();
    }
  };

})(jQuery);
