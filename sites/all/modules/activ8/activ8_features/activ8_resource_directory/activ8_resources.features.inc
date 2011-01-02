<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function di_resources_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_flag_default_flags().
 */
function di_resources_flag_default_flags() {
$flags = array();
// Exported flag: "Feature resource to be promoted to the front page".
$flags[] = array (
  'content_type' => 'node',
  'name' => 'featured_resources',
  'title' => 'Feature resources to be promoted to the front page',
  'global' => '1',
  'types' => 
  array (
    0 => 'resource',
  ),
  'flag_short' => 'Feature',
  'flag_long' => 'Feature this resource',
  'flag_message' => 'Featured',
  'unflag_short' => 'Unfeature this resource',
  'unflag_long' => 'Unfeature this resource',
  'unflag_message' => 'Un-feature',
  'unflag_denied_text' => '',
  'link_type' => 'toggle',
  'roles' => 
  array (
    'flag' => 
    array (
      0 => 2,
    ),
    'unflag' => 
    array (
      0 => 2,
    ),
  ),
  'show_on_page' => 1,
  'show_on_teaser' => 1,
  'show_on_form' => 1,
  'access_author' => '',
  'i18n' => 0,
  'module' => 'di_resources',
  'locked' => 
  array (
    0 => 'name',
  ),
  'api_version' => 2,
);
return $flags;
}

/**
 * Implementation of hook_node_info().
 */
function di_resources_node_info() {
  $items = array(
    'resource' => array(
      'name' => t('Resource'),
      'module' => 'features',
      'description' => t('Resources are documents or multimedia content your organization puts out to help people better better advocate for your cause or brand.   These documents will be hosted on a the client server and downloadable by the public. '),
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
function di_resources_views_api() {
  return array(
    'api' => '2',
  );
}
