<?php

/**
 * Activ8 installation profile
 */

/**
 * Modules to be anabled
 *
 * @return
 *   An array of modules to enable.
 */
function activ8_profile_modules(){
  
  return array(
    // Drupal core 
    'block',  
    'dblog', 
    'filter', 
    'help', 
    'menu', 
    'node', 
    'path',  
    'search', 
    'statistics', 
    'system', 
    'taxonomy', 
    'tracker', 
    'user' 
  );
}

function _active8_contrib_modules(){
  return array(
    
     //activ8 core
    'activ8_core',
    'admin',
    
    //ctools
    'ctools', 
    
    //context @todo not sure which major version of context we need here (2 / 3 ?)
    //'context',
    
    //distribution management
    'distro_client', 
    'features', 
    'strongarm',
    
    //other modules
    'advanced_help',
    'content',
    'jquery_ui', 
    'jquery_update', 
    'libraries',
    'pathauto,'
    'token',
    'views',
    'webform',
    'vertical_tabs'
    
  );
}

/**
 * List of features candidate to be installed
 * If you have more features in the future
 * just add them in this list. They will be added 
 * in the features selection form
 */
function _activ8_features_modules(){
  return array(
    'activ8_blog', 
    'activ8_document_library', 
    'activ8_event_calendar',
    'activ8_newsroom',
    'activ8_resource_directory', 
    'activ8_slideshow',
    'activ8_social_aggregator' 
  )
  ;
}

/**
 * Return a description of the profile for the initial installation screen.
 *
 * @return
 *   An array with keys 'name' and 'description' describing this profile,
 *   and optional 'language' to override the language selection for
 *   language-specific profiles.
 */
function activ8_profile_details(){
  return array(
    'name' => 'Activ8', 
    'description' => 'Activ8  is a Drupal distribution created by Social Contxt to facilitate creation of custom social platforms for nonprofits and political campaigns.' 
  );
}

/**
 * Return a list of tasks that this profile supports.
 *
 * @return
 *   A keyed array of tasks the profile will perform during
 *   the final stage. The keys of the array will be used internally,
 *   while the values will be displayed to the user in the installer
 *   task list.
 */
function activ8_profile_task_list(){
  global $conf;
  $conf['site_name'] = 'Activ8';
  $conf['site_footer'] = 'Activ8 by <a href="http://socialcontxt.com">Social Contxt</a>';
  
  $tasks = array(
    'activ8-configure-contrib-batch' => st('Activ8 contrib modules'), 
    'activ8-configure-features' => st('Activ8  features'), 
    'activ8-configure-apis' => st('Activ8  apis'), 
    'activ8-configure-done' => st('Activ8  done') 
  );
  return $tasks;
}

/**
 * Perform any final installation tasks for this profile.
 */
function activ8_profile_tasks(&$task, $url){\

  $output = '';
  
  if ($task == 'profile') {
    drupal_set_title(t('Activ8 Installation'));
    $task = "activ8-configure-contrib-batch";
  }
  
  if ($task == 'activ8-configure-contrib-batch') {
    $modules = _active8_contrib_modules();
    
    $files = module_rebuild_cache();
    $operations = array();
    foreach ( $modules as $module ) {
      $operations[] = array(
        '_install_module_batch', 
        array(
          $module, 
          $files[$module]->info['name'] 
        ) 
      );
    }
    $batch = array(
      'operations' => $operations, 
      'finished' => '_activ8_configure_contrib_batch_finished', 
      'title' => st('Installing @drupal', array(
        '@drupal' => drupal_install_profile_name() 
      )), 
      'error_message' => st('The installation has encountered an error.') 
    );
    // Start a batch, switch to 'profile-install-batch' task. We need to
    // set the variable here, because batch_process() redirects.
    variable_set('install_task', 'profile-install-batch');
    batch_set($batch);
    batch_process($url, $url);
    //$task == 'activ8-configure-features';
  //return $form = drupal_get_form('_activ8_get_features_info', $url);
  }
  
  if ($task == 'activ8-configure-features') {
    $output = drupal_get_form('_activ8_get_features_info', $url);
    if (! variable_get('features_info_executed', FALSE)) {
      drupal_set_title('configuring features');
      return $output;
    }
    else {
      $task = 'activ8-configure-apis';
    }
  }
  
  // We are running a batch task for this profile so basically do nothing and return page
  if (in_array($task, array(
    'activ8-configure-contrib-batch', 
    'activ8-configure-features' 
  ))) {
    include_once 'includes/batch.inc';
    $output = _batch_page();
  }
  
  if ($task == 'activ8-configure-apis') {
    $output = drupal_get_form('_activ8_apis_form', $url);
    if (! variable_get('activ8_configure_apis_executed', FALSE)) {
      drupal_set_title('configuring apis');
      return $output;
    }
    else {
      $task = 'activ8-configure-done';
    }
    //return $form;
  }
  
  if ($task == 'activ8-configure-done') {
  	_activ8_install_default_theme('activ8'); 
  	_activ8_enable_themes();
  	// set some default variables
  	variable_set('admin_theme', 'rubik');
  	variable_set('site_frontpage', 'home');
  	variable_set('default_theme', 'activ8');
	
  	
    $task = 'profile-finished';
  
  }
  
  // Update the menu router information.
  menu_rebuild();
}

function _activ8_enable_themes(){
  system_theme_data();
  $themes = array(
    'activ8',
    'tao',
    'rubik',
  );
  _activ8_install_enable_theme($themes);
}

/**
 * Enable themes.
 *
 * @param $themes
 *   An array of theme names
 */
function _activ8_install_enable_theme($themes) {
  system_theme_data();
  $themes = is_array($themes) ? $themes : array($themes);
  foreach($themes as $theme){
    db_query("UPDATE {system} SET status = 1 WHERE type = 'theme' and name = '%s'", $theme);
    system_initialize_theme_blocks($theme);
  }
}

/**
 * Set default theme.
 *
 * @param $theme
 *   Unique string that is the name of theme.
 */
function _activ8_install_default_theme($theme) {
  global $theme_key;
  _activ8_install_enable_theme($theme);
  variable_set('theme_default', $theme);
  // update the global variable too,
  // mainly so that block functions work correctly
  $theme_key = $theme;
}

  // Insert default user-defined node types into the database. For a complete
  // list of available node type attributes, refer to the node type API
  // documentation at: http://api.drupal.org/api/HEAD/function/hook_node_info.
  $types = array(
    array(
      'type' => 'page',
      'name' => st('Page'),
      'module' => 'node',
      'description' => st("A <em>page</em> is a simple method for creating and displaying information that rarely changes, such as an \"About us\" section of a website. By default, a <em>page</em> entry does not allow visitor comments and is not featured on the site's initial home page."),
      'custom' => TRUE,
      'modified' => TRUE,
      'locked' => FALSE,
      'help' => '',
      'min_word_count' => '',
    ),
  );

  foreach ($types as $type) {
    $type = (object) _node_type_set_defaults($type);
    node_type_save($type);
  }

  // Default page to not be promoted and have comments disabled.
  variable_set('node_options_page', array('status'));
  variable_set('comment_page', COMMENT_NODE_DISABLED);

  // Don't display date and author information for page nodes by default.
  $theme_settings = variable_get('theme_settings', array());
  $theme_settings['toggle_node_info_page'] = FALSE;
  variable_set('theme_settings', $theme_settings);

  // Update the menu router information.
  menu_rebuild();
}

/**
 * Finished callback for the modules install batch.
 *
 * Advance installer task to feature configuration
 */
function _activ8_configure_contrib_batch_finished($success, $results){
  drupal_set_message('install task changed to active-configure-features');
  variable_set('install_task', 'activ8-configure-features');
}

/**
 * Features form
 * List all the features defined in _activ8_features_modules()
 * Administartor selects which feature to install
 */
function _activ8_get_features_info($form_state, $url){
  
  $form = array();
  
  $form['#action'] = $url;
  $form['#redirect'] = FALSE;
  
  $form['status'] = array(
    '#tree' => TRUE 
  );
  
  $modules = _activ8_features_modules();
  foreach ( $modules as $module ) {
    $feature = features_get_info('module', $module);
    $name = $feature->name;
    $module = $feature->module;
    
    $form['status'][$name] = array(
      '#type' => 'checkbox', 
      '#title' => $name, 
      '#default_value' => 1,  //$module->status,
      '#disabled' => FALSE 
    );
  }
  
  $form['submit'] = array(
    '#type' => 'submit', 
    '#value' => st('Enable features and continue') 
  );
  
  return $form;
}

/**
 * feature configuration from's submit function; 
 * enables features (modules) selected by 
 * the administrator
 */
function _activ8_get_features_info_submit(&$form, &$form_state){
  variable_set('features_info_executed', TRUE);
  $modules = $form_state['values']['status'];
  $enable = array();
  foreach ( $modules as $name => $value ) {
    if ($value) {
      $enable[] = $name;
    }
  }
  include_once './includes/install.inc';
  drupal_install_modules($enable);
  $core = array(
    'cache', 
    'cache_block', 
    'cache_filter', 
    'cache_page' 
  );
  $cache_tables = array_merge(module_invoke_all('flush_caches'), $core);
  foreach ( $cache_tables as $table ) {
    cache_clear_all('*', $table, TRUE);
  }
}

/**
 * The apis form
 */
function _activ8_apis_form($form_state, $url){

  $form = array();
  
  $form['#action'] = $url;
  $form['#redirect'] = FALSE;
  
  $form['status'] = array(
    '#tree' => TRUE 
  );
  
  // google account key
  // recaptcha
  $form['googleanalytics'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Google analytics settings'), 
    '#collapsible' => TRUE, 
    '#collapsed' => FALSE,
  );
  $form['googleanalytics']['googleanalytics_account'] = array(
    '#type' => 'textfield', 
    '#title' => t('Google Analytics account number'), 
    '#default_value' => variable_get('googleanalytics_account', 'UA-'), 
    '#size' => 15, 
    '#maxlength' => 20, 
    '#description' => t('The account number is unique to the websites domain. Click the <strong>Edit</strong> link in your Google Analytics account next to the appropriate profile on the <strong>Analytics Settings</strong> page, then select <strong>Check Status</strong> at the top-right of the table to find the account number (UA-xxxx-x) of your site. You can obtain a user account from the <a href="@url">Google Analytics</a> website.', array(
      '@url' => 'http://www.google.com/analytics/' 
    )) 
  );
  
  // recaptcha
  $form['addthis'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Addthis settings'), 
    '#collapsible' => TRUE, 
    '#collapsed' => FALSE,
  );
  
  // addthis username
  $form['addthis']['addthis_username'] = array(
    '#type' => 'textfield', 
    '#title' => t('Username'), 
    '#default_value' => variable_get('addthis_username', 'my-username'), 
    '#description' => t('Your username for <a href="http://www.addthis.com/">addthis.com</a>. Example: my-username') 
  );
  
  // recaptcha
  $form['recaptcha'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Recaptcha settings'), 
    '#collapsible' => TRUE, 
    '#collapsed' => FALSE,
  );
  
  $form['recaptcha']['recaptcha_public_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Public Key'),
    '#default_value' => variable_get('recaptcha_public_key', ''),
    '#maxlength' => 40,
    '#description' => t('The public key given to you when you at reCAPTCHA.net</a>.'),
   );
  $form['recaptcha']['recaptcha_private_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Private Key'),
    '#default_value' => variable_get('recaptcha_private_key', ''),
    '#maxlength' => 40,
    '#description' => t('The private key given to you when you  at reCAPTCHA.net</a>AME'),
  );
  
  // scribdfield
  $form['scribdfield'] = array(
    '#collapsible'   => TRUE,
    '#title'         => t('Scribd.com API information'),
    '#type'          => 'fieldset',
  );
  
  $form['scribdfield']['scribd_api_key'] = array(
    '#default_value' => variable_get('scribd_api_key', NULL),
    '#title'         => t('Scribd.com API key'),
    '#type'          => 'textfield',
  );
  
  // nodewords
  
  $form['nodewords'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Nodeword settings'), 
    //'#weight' => 5, 
    '#collapsible' => TRUE, 
    '#collapsed' => FALSE,
  );
 
  $form['nodewords']['copyright'] = array(
    '#type' => 'textfield',
    '#title' => t('Copyright'),
    '#description' => t('Enter a short copyright statement.'),
    //'#default_value' => empty($content['value']) ? '' : $content['value'],
    '#maxlength' => variable_get('nodewords_max_size', 350),
  );
  
  $form['nodewords']['description'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#description' => t('Enter a description. Limit your description to about 20 words, with a maximum of %count characters. It should not contain any HTML tags or other formatting.', array('%count' => variable_get('nodewords_max_size', 350))),
    '#cols' => 60,
    '#rows' => 6,
    '#wysiwyg' => FALSE,
  );
  
  $form['nodewords']['keywords'] = array(
    '#type' => 'textfield',
    '#title' => t('Keywords'),
    '#description' => t('Enter a comma separated list of keywords. Avoid duplication of words as this will lower your search engine ranking.'),
    '#maxlength' => variable_get('nodewords_max_size', 350),
  );
  
  $form['nodewords']['revisit-after'] = array(
    '#type' => 'textfield',
    '#title' => t('Revisit after'),
    '#description' => t('The meta tag REVISIT-AFTER defines how often a search engine or spider should come to your website for re-indexing. This tag is used for websites that change their content and on a regular basis. This tag can also be beneficial in boosting your rankings if search engines display results based on the most recent submissions.'),
    '#size' => 3,
    '#maxlength' => 3,
    '#field_suffix' => t('day(s)'),
  );
  
  $form['nodewords']['bing_webmaster_center'] = array(
    '#type' => 'textfield',
    '#title' => t('Bing Webmaster Center verification code'),
    '#description' => t('<a href="@bing-url">Bing Webmaster Center</a> will ask you to add a meta tag in order to verify you have write access to the pages of the web site you registered with their services.', array('@bing-url' => 'http://www.bing.com/webmaster')),
    '#maxlength' => variable_get('nodewords_max_size', 350),
  );
  
  $form['nodewords']['google_webmaster_tools'] = array(
    '#type' => 'textfield',
    '#title' => t('Google Webmaster Tools verification code'),
    '#description' => t('<a href="@google-url">Google Webmaster Tools</a> will ask you to add a meta tag in your web site to provide you with an easy way to make your site more <a href="http://google.com">Google</a>-friendly.', array('@google-url' => 'http://www.google.com/webmasters/tools')),
    '#maxlength' => variable_get('nodewords_max_size', 350),
  );
  
   $form['nodewords']['yahoo_site_explorer'] = array(
    '#type' => 'textfield',
    '#title' => t('Yahoo! Site Explorer'),
    '#description' => t('<a href="@yahoo-url">Yahoo! Site Explorer</a> will ask you to add a meta tag in your web site to allow you to explore all the web pages indexed by <a href="http://search.yahoo.com">Yahoo! Search</a>.', array('@yahoo-url' => 'https://siteexplorer.search.yahoo.com/')),
    '#maxlength' => variable_get('nodewords_max_size', 350),
  );
  
  $form['submit'] = array(
    '#type' => 'submit', 
    '#value' => st('Save settings and continue') 
  );
  
  return $form;
}

/**
 * apis-form's submit function
 */
function _activ8_apis_form_submit(&$form, &$form_state){
  $variables = array(
    'googleanalytics_account', 
    'addthis_username',
    'recaptcha_public_key',
    'recaptcha_private_key',
    'scribd_api_key',
  );
  foreach ( $variables as $v ) {
    variable_set($v, $form_state['values'][$v]);
  }
  
  // nodewords saves settings in its own table
  $variables = array(
    'copyright',
    'description',
    'keywords',
    'revisit-after',
    'bing_webmaster_center',
    'google_webmaster_tools',
    'yahoo_site_explorer',
  );
  
  foreach($variables as $v){
  	$val = serialize($form_state['values'][$v]);
    db_query("INSERT INTO {nodewords} (type, id, name, content) VALUES (1, 0, '%s', '%s')", $v, $val);
  }
  
  variable_set('activ8_configure_apis_executed', TRUE);
}

/**
 * Implementation of hook_form_alter().
 *
 * Allows the profile to alter the site-configuration form. This is
 * called through custom invocation, so $form_state is not populated.
 */
function activ8_form_alter(&$form, $form_state, $form_id){
  if ($form_id == 'install_configure') {
    // Set default for site name field.
    $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
  }
}

