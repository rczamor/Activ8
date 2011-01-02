<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function activ8_event_calendar_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_event_test
  $groups['event-group_event_test'] = array(
    'group_type' => 'multigroup',
    'type_name' => 'event',
    'group_name' => 'group_event_test',
    'label' => 'Test',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '5' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'label' => NULL,
      ),
      'multigroup' => array(
        'multiple-columns' => 0,
        'required' => 1,
        'multiple' => '10',
        'labels' => array(
          '0' => '',
          '1' => '',
          '2' => '',
          '3' => '',
          '4' => '',
          '5' => '',
          '6' => '',
          '7' => '',
          '8' => '',
          '9' => '',
        ),
      ),
    ),
    'weight' => '9',
    'fields' => array(
      '0' => 'field_event_dummy',
    ),
  );

  // Translatables
  array(
    t('Test'),
  );

  return $groups;
}
