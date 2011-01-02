<?php
// $Id: box.tpl.php,v 1.1.2.1 2010/10/02 00:06:15 spaceninja Exp $

/**
 * @file box.tpl.php
 *
 * Theme implementation to display a box.
 *
 * Available variables:
 * - $title: Box title.
 * - $content: Box content.
 *
 * @see template_preprocess()
 */
?>
<section class="box">

<?php if ($title): ?>
  <h2><?php print $title ?></h2>
<?php endif; ?>

<div class="content">
  <?php print $content ?>
</div> <!-- /.content -->

</section> <!-- /.box -->
