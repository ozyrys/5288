<?php

/**
 * @file
 * 
 *  Template for more accessible blocks.
 *  Wrapper is based on preprocess and it's section element when block has heading
 *  otherwise it's classic div.
 *
 */
?>

<<?php print $block_wrapper; ?> id="<?php print $block_html_id; ?>"<?php if (!empty($aria_label)) print ' aria-label="' . $aria_label . '" '; ?><?php if ($classes): ?> class="<?php print $classes; ?> clearfix"<?php endif; ?><?php print $attributes; ?>>
    <?php print render($title_prefix); ?>
    <?php if ($block->subject): ?>
        <h2<?php print $title_attributes; ?>><?php print $block->subject ?></h2>
    <?php endif; ?>
    <?php print render($title_suffix); ?>
    <div class="content"<?php print $content_attributes; ?>>
        <?php print $content ?>
    </div>
</<?php print $block_wrapper; ?>>
