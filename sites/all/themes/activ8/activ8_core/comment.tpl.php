<?php
// $Id: comment.tpl.php,v 1.1.2.2.2.1 2010/10/02 00:04:25 spaceninja Exp $

/**
 * @file comment.tpl.php
 * Default theme implementation for comments.
 *
 * Available variables:
 * - $author: Comment author. Can be link or plain text.
 * - $content: Body of the post.
 * - $date: Date and time of posting.
 * - $links: Various operational links.
 * - $new: New comment marker.
 * - $picture: Authors picture.
 * - $signature: Authors signature.
 * - $status: Comment status. Possible values are:
 *   comment-unpublished, comment-published or comment-preview.
 * - $submitted: By line with date and time.
 * - $title: Linked title.
 *
 * These two variables are provided for context.
 * - $comment: Full comment object.
 * - $node: Node object the comments are attached to.
 *
 * @see template_preprocess_comment()
 * @see theme_comment()
 */
?>
<article class="comment<?php print ($comment->new) ? ' comment-new' : ''; print ' '. $status ?> clear-block">

<header>

  <?php print $picture ?>

  <?php if ($comment->new): ?>
    <span class="new"><?php print $new ?></span>
  <?php endif; ?>

  <h3><?php print $title ?></h3>

  <p class="submitted">
    <?php print $submitted ?>
  </p>

</header>

<div class="content">

  <?php print $content ?>

  <?php if ($signature): ?>
    <div class="user-signature clear-block">
      <?php print $signature ?>
    </div>
  <?php endif; ?>

</div> <!-- /.content -->

<?php if ($links): ?>
  <footer>
    <?php print $links; ?>
  </footer>
<?php endif; ?>

</article> <!-- /.comment -->
