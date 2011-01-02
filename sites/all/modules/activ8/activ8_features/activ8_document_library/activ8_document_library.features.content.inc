<?php

/**
 * Implementation of hook_content_default_fields().
 */
function activ8_document_library_content_default_fields() {
  $fields = array();

  // Exported field: field_case_study_document
  $fields['case_study-field_case_study_document'] = array(
    'field_name' => 'field_case_study_document',
    'type_name' => 'case_study',
    'display_settings' => array(
      'weight' => '-2',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'ipaper',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'ipaper',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'ipaper',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'ipaper',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'ipaper',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'ipaper',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '1',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '1',
    'list_default' => 1,
    'description_field' => '1',
    'widget' => array(
      'label' => 'Upload Document',
      'weight' => '-1',
      'description' => '',
      'type' => 'scribdfield_widget',
      'module' => 'scribdfield',
    ),
  );

  // Exported field: field_case_study_portfolio
  $fields['case_study-field_case_study_portfolio'] = array(
    'field_name' => 'field_case_study_portfolio',
    'type_name' => 'case_study',
    'display_settings' => array(
      'weight' => '-4',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'plain',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'portfolio_piece' => 'portfolio_piece',
      'blog_post' => 0,
      'case_study' => 0,
      'event' => 0,
      'feed' => 0,
      'page' => 0,
      'service_offering' => 0,
      'staff_bio' => 0,
      'tool' => 0,
      'webform' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'nid' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Client',
      'weight' => '-2',
      'description' => '',
      'type' => 'nodereference_buttons',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_featured
  $fields['case_study-field_featured'] = array(
    'field_name' => 'field_featured',
    'type_name' => 'case_study',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => 'Do Not Feature
Feature',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Featured?',
      'weight' => 0,
      'description' => '',
      'type' => 'optionwidgets_buttons',
      'module' => 'optionwidgets',
    ),
  );

  // Translatables
  array(
    t('Client'),
    t('Featured?'),
    t('Upload Document'),
  );

  return $fields;
}
