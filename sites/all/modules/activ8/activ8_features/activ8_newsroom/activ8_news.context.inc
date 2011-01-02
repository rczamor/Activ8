<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function activ8_news_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'activ8_news';
  $context->description = 'activ8 > news';
  $context->tag = 'activ8';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'news' => 'news',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'views' => array(
      'values' => array(
        'activ8_news' => 'activ8_news',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('activ8');
  t('activ8 > news');

  $export['activ8_news'] = $context;
  return $export;
}
