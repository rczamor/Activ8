<?php
// $Id: node-gallery-image-navigator-slideshow.tpl.php,v 1.1 2010/12/14 13:52:09 scroogie Exp $
/**
 * @file
 * Override image navigator template to show a slideshow link.
 */
?>
<table id="node-gallery-image-navigator" class="image-navigator">
  <tbody>
    <tr class="odd">
      <td class="image-navigator-position">
        <?php print t("%current of %total", array('%current' => $navigator['current'], '%total' => $navigator['total'])); ?>
      </td>
      <td class="image-navigator-first">
        <?php print isset($first_link) ? '<a href="'. $first_link .'">&lt;&lt; '. t('First') .'</a>' : '&nbsp;'; ?>
      </td>
      <td class="image-navigator-prev">
        <?php print isset($prev_link) ? '<a href="'. $prev_link .'">&lt; '. t('Previous') .'</a>' : '&nbsp;'; ?>
      </td>
      <td class="image-navigator-slideshow">
        <?php print isset($slideshow_link) ? '<a href="'. $slideshow_link .'">'. t('Slideshow') .'</a>' : '&nbsp;'; ?>
      </td>
      <td class="image-navigator-next">
        <?php print isset($next_link) ? '<a href="'. $next_link .'">'. t('Next') .' &gt;</a>' : '&nbsp;'; ?>
      </td>
      <td class="image-navigator-last">
        <?php print isset($last_link) ? '<a href="'. $last_link .'">'. t('Last') .' &gt;&gt;</a>' : '&nbsp;'; ?>
      </td>
      <td class="image-navigator-gallery-link">
        <?php print '<a href="'. $gallery_link .'">'. t("Back to gallery") .'</a>'; ?>
      </td>
    </tr>
  </tbody>
</table>
