// $Id: ng_plupload.js,v 1.1.2.1 2010/12/22 15:27:51 justintime Exp $
/**
 * @file
 * Node Gallery additions to plupload page.
 *
 * I didn't find a singleton in plupload, but the Drupal module currently
 * hardcodes the element id, which makes it easy to retrieve the
 * plupload object anyway. If that changes, we have to update it here.
 */
Drupal.behaviors.nodeGalleryPlupload = function (context) {
  var self = this;
  this.context = context;
  this.redirectTarget = Drupal.settings.node_gallery.redirectTarget;

  var init = function () {
    // check if upload instance is already there, else try again later.
    self.uploader = $("#uploader", self.context).pluploadQueue();
    if (typeof self.uploader == 'undefined') {
      setTimeout(init, 500);
      return;
    }
    self.uploader.bind('FileUploaded', function () {
      if (self.uploader.total.queued == 0) {
        window.location.href = self.redirectTarget;
      }
    });
  }
  init();
};