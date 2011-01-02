<?php
// $Id: node_gallery_views_handler_image_navigator.inc,v 1.1.2.4 2010/11/23 15:30:56 justintime Exp $

/**
 * @file
 * Views field handler that displays the image navigator
 */

/**
 * Field handler to display the image navigator in a view
 */
class node_gallery_views_handler_image_navigator extends views_handler_field {
  function query() {
    $this->ensure_my_table();
  }

  function render($values) {
    $node = node_load($values->nid);
    if ($node->gid) {
      return theme('node_gallery_image_navigator', node_gallery_get_image_navigator($node->gid, $node->nid), $node);
    }
  }
}

