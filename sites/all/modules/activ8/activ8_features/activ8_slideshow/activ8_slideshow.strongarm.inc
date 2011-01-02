<?php

/**
 * Implementation of hook_strongarm().
 */
function activ8_slideshow_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_slide';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '1',
    'author' => '2',
    'options' => '3',
    'comment_settings' => '6',
    'menu' => '-1',
    'path' => '8',
    'path_redirect' => '7',
    'print' => '5',
    'xmlsitemap' => '4',
    'nodewords' => '0',
  );

  $export['content_extra_weights_slide'] = $strongarm;
  return $export;
}
