<?php
// $Id: styles.theme.inc,v 1.1.2.1.2.4 2010/08/16 15:23:12 aaron Exp $

/**
 * @file styles.theme.inc
 * Theme and preprocess functions for the Styles project.
 */

function theme_field_formatter_styles($element = NULL) {
// dpm($element);
  $formatter = $element['#formatter'];
  $object = (object)$element['#item'];
  $output = '';
  if (preg_match('@^styles_(.*?)_(.*?)$@i', $formatter, $matches)) {
    $field_type = $matches[1];
    $style_name = $matches[2];
    $output = theme('styles', $field_type, $style_name, $object);
  }
  return $output;
}

function template_preprocess_styles(&$variables) {
  // If we have a Styles object instance already, then honor that.
  // Otherwise, we'll build a new Styles object instance from our settings.
  $variables['instance'] = $variables['instance'] ? $variables['instance'] : styles_instance($variables['field_type'], $variables['style_name'], $variables['object']);

  $variables['classes'] = 'styles-wrapper';

  if ($variables['instance']) {
    $variables['output'] = $variables['instance']->display(TRUE);
  }
  else {
    $variables['output'] = '';
  }
}
