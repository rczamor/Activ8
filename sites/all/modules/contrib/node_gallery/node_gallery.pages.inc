<?php
// $Id: node_gallery.pages.inc,v 1.12.2.78 2010/12/22 17:34:27 justintime Exp $

/**
 * @file
 * Handles displaying of Node gallery pages.
 *
 */

function node_gallery_upload_image_to_new_gallery_form($image_type) {
  $relationship = node_gallery_get_relationship(NULL, $image_type);
  $gallery = _node_gallery_create_new_gallery($relationship['gallery_type']);
  $gallery->edit_after_plupload = TRUE;
  return node_gallery_upload_image_form($gallery);
}

/**
 * Displays the content of the "Upload Images" tab.
 *
 * @param $gallery
 *   A populated node gallery object which will house the images.
 *
 * @return
 *   HTML output.
 */
function node_gallery_upload_image_form($gallery) {
  global $user;

  drupal_set_breadcrumb(array(
    l(t('Home'), NULL),
    l(t('Galleries'), 'galleries'),
    l(t('!user\'s Galleries', array('!user' => $gallery->name)), 'galleries/' . $gallery->uid),
    l($gallery->title, 'node/'. $gallery->nid)
    ));
  $relationship = node_gallery_get_relationship($gallery->type);

  if (module_exists('plupload') && variable_get('node_gallery_plupload_integration', TRUE)) {
    $filefield_name = $relationship['image_type'] .':::'. $relationship['imagefield_name'];
    $options = array('drupal_pluploaded' => TRUE, 'drupal_gid' => $gallery->nid, 'drupal_plupload_import_field_type' => $filefield_name);
    $output = '';
    if (!user_access('bulk upload files with plupload')) {
      drupal_set_message(t('You have permissions to view this tab, but not to upload images.  Please inform an administrator that you need the \'bulk upload files with plupload\' permission.'), 'warning');
    }
    else {
      if ($gallery->edit_after_plupload) {
        $settings = array(
          'redirectTarget' => url('node/'. $gallery->nid .'/edit'),
        );
        drupal_add_js(array('node_gallery' => $settings), 'setting');
        drupal_add_js(drupal_get_path('module', 'node_gallery') .'/js/ng_plupload.js');
      }
      $output = plupload_upload_page($options);
    }
    return $output;
  }

  // Pull the image type from the relationship, and display it's form:
  $imagetype = $relationship['image_type'];
  $node = new stdClass;
  $node->type = $imagetype;
  $node->uid = $user->uid;
  $node->name = (isset($user->name) ? $user->name : '');
  module_load_include('pages.inc', 'node');
  $output = drupal_get_form($imagetype .'_node_form', $node);
  return $output;
}

function node_gallery_browse_images($gallery) {
  $first_image = node_gallery_get_first_image($gallery->nid);
  $path = 'node/';
  if (is_numeric($first_image)) {
    $path .= $first_image;
    // Set our pretty path
    $path = drupal_get_path_alias($path);
  }

  drupal_goto($path);
}

/**
 * Displays the gallery summary page, which is a user-specified view.
 * @param $user
 *   (optional) A user object, defaults to NULL.  If present, displays only
 *   galleries owned by that user.
 * @param $content_type
 *   (optional) A gallery content type.  If present, the view only displays
 *   galleries of this type.
 *
 * @return
 *   HTML Output
 */
function node_gallery_list_galleries($user = NULL, $content_type = NULL) {
  if (!$user) {
    $user = NULL;
  }
  if (!$content_type) {
    $content_type = NULL;
  }
  $viewkey = unserialize(variable_get('node_gallery_galleries_summary_view', serialize(array('name' => 'node_gallery_gallery_summaries', 'display_id' => 'page_1'))));
  $breadcrumbs[] = l(t('Home'), NULL);
  $breadcrumbs[] = l(t('Galleries'), 'galleries');
  if (isset($user->name)) {
    $breadcrumbs[] = l(node_gallery_list_galleries_title($user), 'galleries/' . $user->uid);
  }
  drupal_set_breadcrumb($breadcrumbs);
  // @todo: we should be able to programmatically set some options on the view, such as number of images, imagefield_name, etc.
  $output = views_embed_view($viewkey['name'], $viewkey['display_id'], $user->uid, $content_type);
  return $output;
}

/**
 * Submit handler for our "Upload Images" form.
 *
 * @param $form
 * @param $form_state
 */
function node_gallery_upload_image_form_submit($form, &$form_state) {
  global $user;
  $image = new stdClass;
  $image->uid = $user->uid;
  $image->name = (isset($user->name) ? $user->name : '');
  $values = $form_state['values'];
  foreach ($values as $key => $value) {
    $image->$key = $value;
  }
  node_save($image);
  drupal_set_message(t('Created new image node !title.', array('!title' => $image->title)));
}

/**
 * Displays the content for our "Manage Images" tab, which is a VBO view.
 * @param $form_state
 *   Drupal $form_state array
 * @param $gallery
 *   A populated node gallery object.
 *
 * @return
 *   FAPI array
 */
function node_gallery_manage_images_form($form_state, $gallery) {
  global $pager_page_array, $pager_total;
  $relationship = node_gallery_get_relationship($gallery->type);

  // we must set these globals, because we do not call pager_query.
  $element = 0;
  $pager_page_array = (isset($_GET['page']) ? explode(',', $_GET['page']) : array());
  if (empty($pager_page_array[$element])) {
    $pager_page_array[$element] = 0;
  }
  $items_per_page = $relationship['settings']['manage_images_per_page'];

  drupal_set_breadcrumb(array(
    l(t('Home'), NULL),
    l(t('Galleries'), 'galleries'),
    l(t('!user\'s Galleries', array('!user' => $gallery->name)), 'galleries/'. $gallery->uid),
    l($gallery->title, 'node/'. $gallery->nid)
    ));

  $form = array(
    '#theme' => 'node_gallery_manage_images_form',
    '#cache' => TRUE,
  );

  if ($relationship['settings']['manage_images_show_gallery_list']) {
    if (user_access('administer nodes') || user_access('edit any '. $gallery->type .' content') || user_access('administer node gallery')) {
      $gallery_list = node_gallery_get_gallery_list($gallery->type);
    }
    else {
      $gallery_list = node_gallery_get_gallery_list($gallery->type, $gallery->uid);
    }
  }

  $form['#description'] = t('Manage Images form.');
  $form['#thumb_imagecache'] = 'node-gallery-admin-thumbnail';
  $form['#gallery'] = $gallery;

  $images = array();
  if (isset($_SESSION['node_gallery_plupload_nids'][$gallery->nid])) {
    $images = $_SESSION['node_gallery_plupload_nids'][$gallery->nid];
    // We trim the $images array to a max length to prevent OOM's on the manage images form.
    // There's just no easy way to do paging for just one visit to the manage images tab.
    drupal_set_message(t('Current display is filtered to show only images just uploaded.  Please refresh the page to display all images in the gallery.'), 'status');
    $length = min(variable_get('node_gallery_plupload_manage_images_limit', 100), count($images));
    $images = array_slice($images, 0, $length);
    $chunks = array_chunk($images, count($images));
    unset($_SESSION['node_gallery_plupload_nids'][$gallery->nid]);
  }
  else {
    $images = node_gallery_get_image_nids($gallery->nid, TRUE, FALSE);
    $chunks = array_chunk($images, $items_per_page);
    $images = $chunks[$pager_page_array[$element]];
  }
  $pager_total[$element] = count($chunks);

  if (!empty($images)) {
    $count = 0;
    $form['images']['#tree'] = TRUE;
    foreach ($images as $nid) {
      $count++;
      if ($count % 50 == 0) {
        // Make sure we don't run out of memory by clearing the cache.
        $image = node_load(NULL, NULL, TRUE);
      }
      $image = node_load($nid);
      $options[$nid] = '';
      $form['images'][$nid]['remove'] = array('#type' => 'checkbox', '#default_value' => $file->remove);
      if ($relationship['settings']['manage_images_show_gallery_list']) {
        $form['images'][$nid]['gid'] = array('#type' => 'select', '#title' => t('Gallery'), '#default_value' => $gallery->nid, '#options' => $gallery_list);
      }
      $form['images'][$nid]['edit_form'] = node_gallery_image_item_edit_form($form_state['values']['images'][$nid]['edit_form'], $image, $relationship);
      //Some CCK widgets need to have #field_info populated
      if (!isset($form['#field_info'])) {
        $form['#field_info'] = $form['images'][$nid]['edit_form']['#field_info'];
      };
    }
  }

  $cover_nid = $gallery->cover_image;
  $form['is_cover'] = array(
    '#type' => 'radios',
    '#default_value' => $cover_nid,
    '#options' => $options,
  );

  $form['pager'] = array(
    '#value' => theme('pager', NULL, $items_per_page, $element),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#weight' => 20,
    //need this because this form is used in image upload ahah also.
    '#submit' => array('node_gallery_manage_images_submit'),
    '#validate' => array('node_gallery_manage_images_validate'),
  );
  return $form;
}

/**
 * Eliminates any fieldsets from the image item edit form.
 *
 * @param array $form_item
 * @param array $flattened
 * @return Flattened array.
 */
function node_gallery_flatten_image_item_edit_form($form_item, &$flattened = array(), $inheritance = array()) {
  if (empty($form_item) || !is_array($form_item)) {
    return $form_item;
  }
  if (empty($flattened)) {
    // we start with the whole form, because nested values will be overwritten
    $flattened = $form_item;
  }
  foreach (element_children($form_item) as $key) {
    $element = $form_item[$key];
    if (isset($element['#type']) && $element['#type'] == 'fieldset') {
      if (isset($element['#tree']) && !empty($element['#tree'])) {
        // we have to keep this as its tree preserving. just remove the fieldset.
        unset($element['#type']);
        $flattened[$key] = $element;
      }
      else {
        // this overwrites the old level if existing, so the field
        // inherits title and weight from the 'deepest' fieldset
        $inheritance['#title'] = $element['#title'];
        $inheritance['#weight'] = $element['#weight'];
        node_gallery_flatten_image_item_edit_form($element, $flattened, $inheritance);
        $inheritance = array();
      }
    }
    else {
      $flattened[$key] = array_merge($inheritance, $element);
    }
  }
  return $flattened;
}

function node_gallery_manage_images_validate($form, &$form_state) {
  if (!empty($form_state['values']['images'])) {
    foreach ($form_state['values']['images'] as $nid => $image_form_state) {
      node_validate($image_form_state['edit_form'], $form['images'][$nid]['edit_form']);
    }
  }
}

function node_gallery_manage_images_submit(&$form, &$form_state) {
  $relationship = node_gallery_get_relationship($form['#gallery']->type);
  $compare_fields = array();
  if ($relationship['settings']['manage_images_show_gallery_list']) {
    $compare_fields[] = 'gid';
  }
  foreach ($relationship['settings']['manage_images_fields'] as $k => $f) {
    if ($f) {
      $compare_fields[] = ($k == 'body_field') ? 'body' : $k;
    }
  }
  if ($form_state['values']['is_cover'] != $form['#gallery']->cover_image) {
    // The user selected a new cover image for the gallery.
    // Build an object with the necessary attributes and update the gallery record.
    $image = new stdClass;
    $image->nid = $form_state['values']['is_cover'];
    $image->is_cover = 1;
    $image->gid = $form['#gallery']->nid;
    node_gallery_set_gallery_cover_image($image);
  }
  foreach ($form_state['values']['images'] as $nid => $form_values) {
    $image_node = (object)($form_values['edit_form']+array('gid' => $form_values['gid']));
    if ($form_values['remove']) {
      $op_images['delete'][] = $image_node->nid;
    }
    else {
      if (node_gallery_images_check_update($form['images'][$image_node->nid]['edit_form']['#node'], $image_node, $compare_fields)) {
        $op_images['update'][] = $image_node;
      }
    }
  }
  while (!empty($op_images['update'])) {
    $node = array_shift($op_images['update']);
    $operations[] = array('node_gallery_batch_node_save', array($node));
  }
  while (!empty($op_images['delete'])) {
    $nid = array_shift($op_images['delete']);
    $operations[] = array('node_gallery_image_delete_process', array($nid));
  }
  if (!empty($operations)) {
    $batch = array(
      'operations' => $operations,
      'finished' => 'node_gallery_image_process_finished',
      'title' => t("Modifying Images"),
      'init_message' => t("Images modification process is starting."),
      'progress_message' => t('Processed @current out of @total.'),
      'error_message' => t('Images modification has encountered an error.'),
    );

    batch_set($batch);
    //For memory management, we wipe the values from the form since it's all on the $operations array now
    $tmp = $form_state['values']['form_build_id'];
    $form_state = array();
    $form_state['values']['form_build_id'] = $tmp;
    $form = array();
  }
  $form_state['redirect'] = 'node/'. $image_node->gid;
}

/**
 * Check if we need to update this image;
 *
 * @param unknown_type $old_image
 * @param unknown_type $new_image
 * @param unknown_type $compare_fields
 * @return unknown
 */
function node_gallery_images_check_update($old_image, $new_image, $compare_fields) {
  $new_image = node_submit($new_image);
  foreach ($compare_fields as $f) {
    //a hack for cck field validate;
    if (is_array($new_image->{$f})) {
      foreach ($new_image->{$f} as &$ff) {
        if (is_array($ff)) {
          unset($ff['_error_element']);
        }
      }
    }
    // special case for taxonomy, as its representation in form_state is different than in the node object.
    if ($f == 'taxonomy') {
      if (node_gallery_taxonomy_compare($old_image, $new_image)) {
        return TRUE;
      }
      else {
        continue;
      }
    }
    // @todo: Workflow doesn't work here
    if ($new_image->{$f} != $old_image->{$f}) {
      return TRUE;
    }
  }
  return FALSE;
}


function node_gallery_image_item_edit_form($form_values, $image, $relationship) {
  module_load_include('inc', 'node', 'node.pages');
  $form_state = array('values' => $form_values);

  $display_fields = $relationship['settings']['manage_images_fields'];
  $form = drupal_retrieve_form($image->type .'_node_form', $form_state, $image);
  drupal_prepare_form($image->type ."_node_form", $form, $form_state);
  $item_form = array();
  $display_fields['#field_info'] = '#field_info'; //this should be merged with parent form to optionwidget to work
  $display_fields['#node'] = '#node';

  foreach (array_values($display_fields) as $field_name) {
    if (!empty($field_name)) {
      $item_form[$field_name] = $form[$field_name];
    }
  }
  $item_form += (array)node_gallery_get_image_form_value_items($form);
  node_gallery_set_image_form_default_values($item_form, $image, $relationship);
  return node_gallery_flatten_image_item_edit_form($item_form);
}

function node_gallery_get_image_form_value_items($form) {
  if ($children = element_children($form)) {
    foreach ($children as $child) {
      if ($form[$child]['#type'] == 'value' || $form[$child]['#type'] == 'hidden') {
        $value_forms[$child] = $form[$child];
      }
    }
  }
  elseif ($form['#type'] == 'value' || $form['#type'] == 'hidden') {
    $value_forms[key($form)] = $form;
  }

  return $value_forms;
}

function node_gallery_set_image_form_default_values(&$form, $image, $relationship) {
  global $user;

  if (empty($form['title'])) {
    $form['title'] = array(
      '#type' => 'hidden',
      '#value' => $image->{$relationship['imagefield_name']}[0]['filepath'],
    );
  }
  else {
    $form['title']['#default_value'] = empty($form['title']['#default_value']) ? $image->{$relationship['imagefield_name']}[0]['filepath'] : $form['title']['#default_value'];
  }

  if (!empty($form['body_field'])) {
    $form['body'] = $form['body_field']['body'];
    $form['body']['#rows'] = 3;
    unset($form['body_field']);
  }

  if (!empty($form['changed']) && empty($form['changed']['#value'])) {
    $form['changed']['#value'] = time();
  }
  /* This allowed admins to overwrite the username when editing an image.
   * this feature was disabled as it was unexpected behaviour #550994 */
  if (user_access('administer nodes')) {
    $form['name'] = array(
      '#type' => 'value',
      '#value' => $image->name ? $image->name : $user->name,
    );
  }
  /* if (empty($form['name']) || empty($form['name']['#value'])) {
    $form['name'] = array(
      '#type' => 'value',
      '#value' => $user->name,
    );
  } */
  if (!empty($form['uid']) && empty($form['uid']['#value'])) {
    $form['uid']['#value'] = $user->uid;
  }
  /* @todo: do we need this?
  $image_comment = variable_get('comment_'. $relationship['image_type'], COMMENT_NODE_READ_WRITE);
  $gallery_comment = variable_get('comment_'. $relationship['gallery_type'], COMMENT_NODE_READ_WRITE);
  $form['comment'] = array(
    '#type' => 'value',
    '#value' => $config['image_comment'] == 'image' ? $image_comment : $gallery_comment,
  );
  */
}



/**
 * Form function for the "Sort Images" tab.
 * @param $gallery
 *   A populated node gallery object.
 *
 * @return
 *   Form array.
 */
function node_gallery_sort_images_form($form_state, $gallery, $no_jquery = FALSE) {
  drupal_set_breadcrumb(array(
    l(t('Home'), NULL),
    l(t('Galleries'), 'galleries'),
    l(t('!user\'s Galleries', array('!user' => $gallery->name)), 'galleries/'. $gallery->uid),
    l($gallery->title, 'node/'. $gallery->nid)
  ));

  $form = array();
  $form['#images'] = array();

  $images = node_gallery_get_images($gallery, TRUE, FALSE);
  $image_count = count($images);
  $jquery_ui_integration = FALSE;
  if (module_exists('jquery_ui') && variable_get('node_gallery_jquery_ui_integration', TRUE) && $no_jquery != 'no_jquery') {
    $jquery_ui_integration = TRUE;
  }
  $max_image_count = variable_get('node_gallery_sort_images_max', 750);
  if ($image_count > $max_image_count) {
    drupal_set_message(t('There are too many images in this gallery to display. You can increase the limit by !settings_url. The current limit is !max.', array('!settings' => 'admin/settings/node_gallery/settings', '!max' => $max_image_count)), 'warning');
    return $form;
  }

  // form generation starts here
  $original_sort = array();
  for ($i = 0; $i < $image_count; ++$i) {
    $image = $images[$i];
    $original_sort[] = $image->nid;
    // @todo: We should document how many images will exhaust 128M RAM to manage expectations.  I don't think there's
    // anything we can do here, because it's Drupals' form render process that eats up the heap.
    if (!$jquery_ui_integration) {
      $form['images-sort-'. $i] = array(
        '#type' => 'weight',
        '#delta' => $image_count,
        '#default_value' => $i,
        '#attributes' => array(
          'class' => 'sort'
        ),
      );
    }
    $form['#images'][] = array(
        'nid' => $image->nid,
        'title' => $image->title,
        'created' => $image->created,
        'changed' => $image->changed,
        'status' => $image->status,
        'original_sort' => $i,
        'filepath' => $image->filepath,
        'admin_thumb' => theme('imagecache', 'node-gallery-admin-thumbnail', $image->filepath, '', $title, array()),
    );
  }
  $original_sort = implode($original_sort, ',');
  $form['original_sort'] = array(
    '#type' => 'hidden',
    '#value' => $original_sort,
  );
  $form['new_sort'] = array(
    '#type' => 'hidden',
    '#default_value' => $original_sort,
  );
  $form['gid'] = array(
    '#type' => 'value',
    '#value' => $gallery->nid,
  );
  $form['gallery_type'] = array(
    '#type' => 'value',
    '#value' => $gallery->type,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save custom sorting'),
  );
  $form['remove'] = array(
    '#type' => 'submit',
    '#value' => t('Restore default sorting'),
    '#submit' => array('node_gallery_sort_images_form_remove_weights_submit'),
  );
  $form['jquery_ui_integration'] = array(
    '#type' => 'value',
    '#value' => $jquery_ui_integration,
  );
  return $form;
}

/**
 * Page callback for the sort image page, when it retrieves image nids ordered by a specified field.
 *
 * @param object $gallery The node object of a gallery.
 * @param string $op The entry to sort after; one of title, created, changed, filepath, weight or current.
 * @param boolean $reverse If the order should be reversed.
 * @return string JSON encoded array of image nids.
 */
function node_gallery_json_get_sorted_images($gallery, $op = '', $reverse = FALSE) {
  return drupal_json(node_gallery_get_image_nids_sorted_by($gallery, $op, $reverse));
}

/**
 * Page callback for json image object requests.
 *
 * @param object $gallery
 *   The node object of a gallery
 * @param integer $image_nid
 *   The integer that contains the nid of the "current" image.  If not specified, all images are returned.
 * @param integer $to_left
 *   The number of images to the left of the current image to fetch.
 * @param integer $to_right
 *   The number of images to the right of the current image to fetch.
 */
function node_gallery_json_get_images($gallery, $image_nid = NULL, $to_left = 0, $to_right = 0) {
  if (empty($image_nid)) {
    return drupal_json(node_gallery_get_images($gallery));
  }
  if (empty($to_left)) {
    $to_left = 0;
  }
  if (empty($to_right)) {
    $to_right = 0;
  }
  return drupal_json(node_gallery_get_images_slice($gallery, $image_nid, $to_left, $to_right));
}

/**
 * Submit function to reset all image weights in a gallery to 0, effectively removing any custom sort.
 */
function node_gallery_sort_images_form_remove_weights_submit($form, &$form_state) {
  $result = db_query('UPDATE {node_gallery_images} SET weight = 0 WHERE gid = %d', $form_state['values']['gid']);
  if ($result === FALSE) {
    $message = t("There was a problem updating you're images.");
  }
  else {
    $message = t("All image weights have been reset. The global sorting is now active again.");
  }
  node_gallery_clear_gallery_caches($form_state['values']['gid']);
  drupal_set_message($message);
}

function node_gallery_sort_images_form_submit($form, &$form_state) {
  $images = array();
  $gid = $form_state['values']['gid'];
  if (!empty($form_state['values']['new_sort'])) {
    // jquery ui grid data
    $new_sort = explode(',', $form_state['values']['new_sort']);
    $original_sort = explode(',', $form_state['values']['original_sort']);
    foreach ($new_sort as $position => $nid) {
      $old_position = array_search($nid, $original_sort);
      if ($old_position !== FALSE && $form['#images'][$old_position]['original_sort'] != $position) {
        $images[] = array(
          'nid' => $nid,
          'gid' => $gid,
          'weight' => $position,
        );
      }
    }
  }
  else {
    // tabledrag data
    $i = 0;
    foreach ($form['#images'] as $image) {
      if (isset($form_state['values']['images-sort-'. $i])
          && ($form_state['values']['images-sort-'. $i] != $image['original_sort'])) {
        $images[] = array(
          'nid' => $image['nid'],
          'gid' => $gid,
          'weight' => $form_state['values']['images-sort-'. $i],
        );
      }
      $i++;
    }
  }
  if (!empty($images)) {
    $batch = array(
      'title' => t('Updating image order'),
      'operations' => array(array('node_gallery_batch_sorting_callback', array($images))),
      'finished' => 'node_gallery_batch_sorting_finished',
      'file' => drupal_get_path('module', 'node_gallery') . '/node_gallery.inc',
      'init_message' => t('New image positions are being calculated.'),
      'progress_message' => t('Processing image sorting.'),
      'error_message' => t('Image sorting has encountered an error.'),
    );
    batch_set($batch);
  }
  else {
    drupal_set_message(t("The order of the images was left unchanged."));
  }
}

/**
 * Builds the form used for imagefield_import integration.
 * @param $gallery
 *   A populated gallery node object.
 *
 * @return
 *   A FAPI form array.
 */
function node_gallery_imagefield_import_form($gallery) {
  // Load up the form from imagefield_import
  $form_state = array();
  $form = drupal_retrieve_form('imagefield_import_form', $form_state);

  // Add our gid
  $form['files']['gid']['#tree'] = FALSE;
  $form['files']['gid'] = array('#type' => 'value', '#value' => $gallery->gid);
  return $form;
}
