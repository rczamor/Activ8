<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function activ8_news_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function activ8_news_node_info() {
  $items = array(
    'news' => array(
      'name' => t('News'),
      'module' => 'features',
      'description' => t('News posts will be posted to share press releases, and external news stories and external blog posts about the work you are doing. This content type will represent various stories such as news articles, press releases, briefings, etc.'),
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
function activ8_news_views_api() {
  return array(
    'api' => '2',
  );
}
