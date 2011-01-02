<?php

/**
 * Implementation of hook_imagecache_default_presets().
 */
function activ8_event_calendar_imagecache_default_presets() {
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
function activ8_event_calendar_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Event'),
      'module' => 'features',
      'description' => t('An <em>event</em> is a content type representing various events which your organization will be holding or attending. Events will be categorized by event type and relationship to the event.'),
      'has_title' => '1',
      'title_label' => t('Event Name'),
      'has_body' => '1',
      'body_label' => t('Event Description'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
