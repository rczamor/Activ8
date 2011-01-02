<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function activ8_social_aggregator_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function twitter_aggregator_node_info() {
  $items = array(
    'tweet' => array(
      'name' => t('Tweet'),
      'module' => 'features',
      'description' => '',
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
function twitter_aggregator_views_api() {
  return array(
    'api' => '3.0-alpha1',
  );
}
