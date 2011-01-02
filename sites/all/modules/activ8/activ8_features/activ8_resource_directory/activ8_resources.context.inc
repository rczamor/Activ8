<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function =activ8_resources_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'di_resources';
  $context->description = 'activ8 > resources';
  $context->tag = 'activ8';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'activ8_resources' => 'activ8_resources',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-activ8_resources-page_1' => array(
          'module' => 'views',
          'delta' => '-exp-activ8_resources-page_1',
          'region' => 'sidebar_last',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('activ8');
  t('activ8 > resources');

  $export['activ8_resources'] = $context;
  return $export;
}
