<?php
// $Id: node-gallery-sort-images-grid-item.tpl.php,v 1.1.2.2 2010/11/23 15:30:56 justintime Exp $
/**
 * @file
 * Default theme implementation for an image item on the sort images page.
 *
 * Available variables:
 *   title
 *   filepath
 *   created
 *   changed
 *   status
 *   filepath
 *   original_sort
 *   admin_thumb
 *
 */
?>
<div class="node-gallery-sort-images-item" id="images-sort-<?php print $original_sort; ?>">
 <?php print $admin_thumb; ?>
</div>