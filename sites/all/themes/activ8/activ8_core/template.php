<?php
// $Id: template.php,v 1.1.2.7.2.1 2010/10/02 00:04:25 spaceninja Exp $

/**
 * @file
 * Contains theme override functions and preprocess functions for the Activ8 theme.
 */

/**
 * Implements theme_preprocess_page().
 * We are overwriting the default meta character type tag with HTML5 version.
 */
function activ8_preprocess_page(&$vars, $hook) {
  $vars['head'] = str_replace(
    '<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />',
    '<meta charset="utf-8" />',
    $vars['head']
  );
}

/**
 * Changes the search form to use the "search" input element of HTML5.
 */

function boron_preprocess_search_block_form(&$vars) {
  $vars['search_form'] = str_replace('type="text"', 'type="search"', $vars['search_form']);
  }