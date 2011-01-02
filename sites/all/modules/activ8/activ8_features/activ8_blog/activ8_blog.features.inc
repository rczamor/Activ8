<?php

/**
 * Implementation of hook_imagecache_default_presets().
 */
function activ8_blog_imagecache_default_presets() {
  $items = array(
    'blog_feature_image_scale' => array(
      'presetname' => 'blog_feature_image_scale',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '424',
            'height' => '150',
          ),
        ),
      ),
    ),
    'blog_full_image' => array(
      'presetname' => 'blog_full_image',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '900',
            'height' => '150',
          ),
        ),
      ),
    ),
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
function activ8_blog_node_info() {
  $items = array(
    'blog_post' => array(
      'name' => t('Blog Post'),
      'module' => 'features',
      'description' => t('A <em>blog post</em>, is a content type for posting informal journal entries about various topics. Each post can be tagged to organize posts by common subject matters. Site visitors will be able to post comments and to facilitate a conversation about the blog post subject matter.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function activ8_blog_views_api() {
  return array(
    'api' => '2',
  );
}
