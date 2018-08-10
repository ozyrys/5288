<div id="ofed-federal-header-wrapper">
  <div id="ofed-federal-header-link">
    <?php
    // Generate the link.
    global $language;
    $link = l(t('www.belgium.be'), 'http://www.belgium.be/' . $language->language, array('HTML' => TRUE));
    $link = '<span>' . $link . '</span>';
    // Display the text.
    print t('Other official information and services: !link', array('!link' => $link)); 
    ?>
  </div>
  <div id="ofed-federal-header-logo">
    <?php 
    // Set image settings.
    $image_variables = array(
      'path' => drupal_get_path('theme', 'egovselect') . '/assets/images/federalheader_logo.png',
      'alt' => t('Logo of the Belgian Federal Authorities'),
      'width' => 32,
      'height' => 23,
      'attributes' => array('class' => 'federal-header-logo')
    );
    // Generate impage.
    $image = theme('image', $image_variables);
    // Display image.
    print $image;

    $image_variables = array(
      'path' => drupal_get_path('theme', 'egovselect') . '/assets/images/federalheader_logo_white.png',
      'alt' => t('Logo of the Belgian Federal Authorities'),
      'width' => 32,
      'height' => 23,
      'attributes' => array('class' => 'federal-header-logo-mobile')
    );
    // Generate impage.
    $image = theme('image', $image_variables);
    // Display image.
    print $image;
    ?>
  </div>
</div>
