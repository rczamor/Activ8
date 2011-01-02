<?php

/**
 * Implementation of hook_user_default_roles().
 */
function activ8_user_default_roles() {
  $roles = array();

  // Exported role: admin
  $roles['admin'] = array(
    'name' => 'admin',
  );

  // Exported role: manager
  $roles['manager'] = array(
    'name' => 'manager',
  );

  return $roles;
}
