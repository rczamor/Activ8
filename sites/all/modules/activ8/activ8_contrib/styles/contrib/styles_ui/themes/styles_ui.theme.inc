<?php
// $Id: styles_ui.theme.inc,v 1.1.2.1 2010/07/28 17:39:17 aaron Exp $

/**
 * @file styles/contrib/styles_ui/themes/styles_ui.theme.inc
 *
 * Theme functions for the Styles UI module.
 */

/**
 * Display the preset name on the admin overview page.
 */
function theme_styles_ui_admin_overview($preset_name) {
  $output = check_plain($preset_name);
  return $output;
}
