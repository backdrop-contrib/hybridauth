/*global Backdrop: false, jQuery: false */
/*jslint devel: true, browser: true, maxerr: 50, indent: 2 */
(function ($) {
  "use strict";

  /**
   * Provide the HTML to create the modal dialog.
   * Clone of function Backdrop.theme.prototype.CToolsModalDialog.
   */
  Backdrop.theme.prototype.HybridAuthModalDialog = function () {
    var html = '';
    html += '  <div id="ctools-modal">';
    html += '    <div id="hybridauth-modal">';
    html += '      <div class="ctools-modal-content">';
    html += '        <div class="modal-header">';
    html += '          <a class="close" href="#">';
    html += Backdrop.CTools.Modal.currentSettings.closeText + Backdrop.CTools.Modal.currentSettings.closeImage;
    html += '          </a>';
    html += '          <span id="modal-title" class="modal-title"></span>';
    html += '        </div>';
    html += '        <div id="modal-content" class="modal-content">';
    html += '        </div>';
    html += '      </div>';
    html += '    </div>';
    html += '  </div>';

    return html;
  };

})(jQuery);
