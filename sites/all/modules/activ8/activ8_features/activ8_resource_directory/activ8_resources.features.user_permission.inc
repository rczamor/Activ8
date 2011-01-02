<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function activ8_resources_user_default_permissions() {
  $permissions = array();

  // Exported permission: create resource content
  $permissions['create resource content'] = array(
    'name' => 'create resource content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'manager',
    ),
  );

  // Exported permission: edit any resource content
  $permissions['edit any resource content'] = array(
    'name' => 'edit any resource content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'manager',
    ),
  );

  // Exported permission: edit own resource content
  $permissions['edit own resource content'] = array(
    'name' => 'edit own resource content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'manager',
    ),
  );

  return $permissions;
}
