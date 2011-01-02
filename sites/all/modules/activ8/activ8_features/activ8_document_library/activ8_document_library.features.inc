<?php

/**
 * Implementation of hook_imagecache_default_presets().
 */
function activ8_document_library_imagecache_default_presets() {
  $items = array(
    'image_thumbnail' => array(
      'presetname' => 'image_thumbnail',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '212',
            'height' => '115',
            'upscale' => 0,
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function activ8_document_library_node_info() {
  $items = array(
    'case_study' => array(
      'name' => t('Publication'),
      'module' => 'features',
      'description' => t('The <em>publication</em> content type represents case studies which are being highlighted on the website. These content types contain a relationship to the specific client organization and a Scribd viewer for the attached document. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Abstract'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function activ8_document_library_views_api() {
  return array(
    'api' => '2',
  );
}
