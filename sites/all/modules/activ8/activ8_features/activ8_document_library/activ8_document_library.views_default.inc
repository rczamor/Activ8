<?php

/**
 * Implementation of hook_views_default_views().
 */
function activ8_document_library_views_default_views() {
  $views = array();

  // Exported view: publication_view
  $view = new view;
  $view->name = 'publication_view';
  $view->description = 'Publication page and block';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'title' => array(
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
      'group_type' => 'group',
      'label' => '',
      'exclude' => 0,
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'alt' => '',
        'link_class' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 1,
    ),
    'name' => array(
      'id' => 'name',
      'table' => 'term_data',
      'field' => 'name',
      'relationship' => 'none',
      'group_type' => 'group',
      'label' => '',
      'exclude' => 0,
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'alt' => '',
        'link_class' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_taxonomy' => 0,
    ),
    'body' => array(
      'id' => 'body',
      'table' => 'node_revisions',
      'field' => 'body',
      'relationship' => 'none',
      'group_type' => 'group',
      'label' => '',
      'exclude' => 0,
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'alt' => '',
        'link_class' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
    ),
  ));
  $handler->override_option('sorts', array(
    'created' => array(
      'id' => 'created',
      'table' => 'node',
      'field' => 'created',
      'relationship' => 'none',
      'group_type' => 'group',
      'order' => 'DESC',
      'exposed' => FALSE,
      'expose' => array(
        'label' => '',
      ),
      'granularity' => 'second',
    ),
  ));
  $handler->override_option('filters', array(
    'field_featured_value' => array(
      'id' => 'field_featured_value',
      'table' => 'node_data_field_featured',
      'field' => 'field_featured_value',
      'relationship' => 'none',
      'group_type' => 'group',
      'operator' => '=',
      'value' => 'Yes',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => '',
        'label' => '',
        'use_operator' => NULL,
        'identifier' => '',
        'optional' => 1,
        'remember' => 0,
        'single' => 1,
      ),
      'case' => 1,
    ),
    'status' => array(
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'none',
      'group_type' => 'group',
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => '',
        'label' => '',
        'use_operator' => NULL,
        'identifier' => '',
        'optional' => 1,
        'remember' => 0,
        'single' => 1,
      ),
    ),
    'type' => array(
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
      'group_type' => 'group',
      'operator' => 'in',
      'value' => array(
        'case_study' => 'case_study',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => 'type_op',
        'label' => 'Node: Type',
        'use_operator' => FALSE,
        'identifier' => 'type',
        'optional' => TRUE,
        'remember' => FALSE,
        'single' => TRUE,
        'reduce' => FALSE,
      ),
    ),
    'vid' => array(
      'id' => 'vid',
      'table' => 'term_data',
      'field' => 'vid',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('header', array());
  $handler->override_option('footer', array());
  $handler->override_option('empty', array());
  $handler->override_option('use_ajax', TRUE);
  $handler->override_option('style_plugin', 'grid');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'columns' => '1',
    'alignment' => 'horizontal',
  ));
  $handler = $view->new_display('block', 'Featured Publication', 'publication_featured_block');
  $handler->override_option('filters', array(
    'field_featured_value' => array(
      'id' => 'field_featured_value',
      'table' => 'node_data_field_featured',
      'field' => 'field_featured_value',
      'relationship' => 'none',
      'group_type' => 'group',
      'operator' => '=',
      'value' => 'Yes',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => '',
        'label' => '',
        'use_operator' => NULL,
        'identifier' => '',
        'optional' => 1,
        'remember' => 0,
        'single' => 1,
      ),
      'case' => 1,
    ),
    'status' => array(
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'none',
      'group_type' => 'group',
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => '',
        'label' => '',
        'use_operator' => NULL,
        'identifier' => '',
        'optional' => 1,
        'remember' => 0,
        'single' => 1,
      ),
    ),
    'type' => array(
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
      'group_type' => 'group',
      'operator' => 'in',
      'value' => array(
        'case_study' => 'case_study',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => 'type_op',
        'label' => 'Node: Type',
        'use_operator' => FALSE,
        'identifier' => 'type',
        'optional' => TRUE,
        'remember' => FALSE,
        'single' => TRUE,
        'reduce' => FALSE,
      ),
    ),
  ));
  $handler->override_option('block_description', '');
  $handler->override_option('block_caching', -1);
  $handler = $view->new_display('block', 'Publications', 'publication_list_block');
  $handler->override_option('filters', array(
    'status' => array(
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'none',
      'group_type' => 'group',
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => '',
        'label' => '',
        'use_operator' => NULL,
        'identifier' => '',
        'optional' => 1,
        'remember' => 0,
        'single' => 1,
      ),
    ),
    'type' => array(
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
      'group_type' => 'group',
      'operator' => 'in',
      'value' => array(
        'case_study' => 'case_study',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => 'type_op',
        'label' => 'Node: Type',
        'use_operator' => FALSE,
        'identifier' => 'type',
        'optional' => TRUE,
        'remember' => FALSE,
        'single' => TRUE,
        'reduce' => FALSE,
      ),
    ),
    'term_node_tid_depth' => array(
      'id' => 'term_node_tid_depth',
      'table' => 'node',
      'field' => 'term_node_tid_depth',
      'relationship' => 'none',
      'group_type' => 'group',
      'operator' => 'or',
      'value' => array(
        '44' => '44',
        '40' => '40',
        '42' => '42',
        '43' => '43',
        '41' => '41',
      ),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'operator' => 'term_node_tid_depth_op',
        'label' => 'Publication Type',
        'use_operator' => 0,
        'identifier' => 'term_node_tid_depth',
        'optional' => 1,
        'remember' => 0,
        'single' => 1,
        'reduce' => 0,
      ),
      'type' => 'select',
      'limit' => TRUE,
      'vid' => '6',
      'hierarchy' => 1,
      'depth' => '0',
    ),
    'term_node_tid_depth_1' => array(
      'id' => 'term_node_tid_depth_1',
      'table' => 'node',
      'field' => 'term_node_tid_depth',
      'relationship' => 'none',
      'group_type' => 'group',
      'operator' => 'or',
      'value' => array(
        '35' => '35',
        '25' => '25',
        '36' => '36',
        '18' => '18',
        '37' => '37',
        '32' => '32',
        '10' => '10',
        '26' => '26',
        '29' => '29',
        '33' => '33',
        '39' => '39',
        '27' => '27',
        '24' => '24',
        '20' => '20',
        '30' => '30',
        '21' => '21',
        '34' => '34',
        '38' => '38',
        '28' => '28',
        '31' => '31',
        '19' => '19',
      ),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'operator' => 'term_node_tid_depth_1_op',
        'label' => 'Topic',
        'use_operator' => 0,
        'identifier' => 'term_node_tid_depth_1',
        'optional' => 1,
        'remember' => 0,
        'single' => 1,
        'reduce' => 0,
      ),
      'type' => 'select',
      'limit' => TRUE,
      'vid' => '4',
      'hierarchy' => 0,
      'depth' => '0',
    ),
  ));
  $handler->override_option('block_description', '');
  $handler->override_option('block_caching', -1);

  $views[$view->name] = $view;

  return $views;
}
