<?php

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function activ8_taxonomy_default_vocabularies() {
  return array(
    'activ8_topic' => array(
      'name' => 'Topic',
      'description' => 'Activ8 shared free tagging vocabulary',
      'help' => '',
      'relations' => '1',
      'hierarchy' => '0',
      'multiple' => '0',
      'required' => '0',
      'tags' => '1',
      'module' => 'features_activ8_topic',
      'weight' => '0',
      'nodes' => array(
        'news' => 'news',
        'project' => 'project',
        'publication' => 'publication',
      ),
    ),
  );
}
