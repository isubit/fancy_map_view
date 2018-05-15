<?php

/**
 * @file
 * Default simple view template to display a map.
 *
 * - $title : The title of this group of rows.  May be empty.
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)) : ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>

<div id="fancy-map-view-canvas"></div>