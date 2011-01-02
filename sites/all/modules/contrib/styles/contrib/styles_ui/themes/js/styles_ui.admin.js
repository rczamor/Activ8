// $Id: styles_ui.admin.js,v 1.1.2.1 2010/07/28 17:39:17 aaron Exp $

/**
 * @file styles_ui.admin.js
 *
 * jQuery attachment to Styles UI admin pages.
 */
(function ($) {
  /**
   *  Change the preview on radio change.
   */
  Drupal.behaviors.stylesUI = function(context) {
    $('.styles-ui-preset:not(stylesUI-processed)', context)
      .addClass('stylesUI-processed')
      .each(function() {
        $(this).bind('change', function() {
          $preset = $(this);
          if ($preset.val()) {
            $.getJSON(Drupal.settings.stylesUI.url + '/' + Drupal.settings.stylesUI.fieldType + '/' + $preset.attr('rel') + '/' + $preset.val(), function(data){
              // @TODO: Check for errors.
              $(data.id).html(data.preview);
            });
          }
        });
      });
  }
})(jQuery);
