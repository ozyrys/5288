# ACCESSIBILITY HELPER FILES


## Purpose

This package is to be used on Drupal sites, to help themers to meet WCAG AA 2.0
requirements.

## Version


Version 0.2 | 19/04/2018


## Usage

### Directories Location

#### accessibility

##### Including files
  - **accessibility.inc**
    It is recommended to make the accessibility.inc file accessible from
    anywhere in the theme.

    E.g. in your's project theme template.php:
    
      *require_once drupal_get_path('theme', 'nerra').'/accessibility/includes/accessibility.inc';*

#### templates

These templates are only inspirations. Check what has been changed in the 
comments of the template file or compare it with default openfed_theme_nerra and
adapt it to project templates.

#### theme

Adapt this themes to your project. Check the comments in files for more details.

#### other files: js/accessibility.js, styles

Already included in nerra.


### Using helper functions
  - **_nerra_a11y_field_type_image()**

    You should call it from *template_preprocess_field()*, as follows:

    `if ($vars['element']['#field_type'] == 'image') {  
      _nerra_a11y_field_type_image($vars);  
    }`
    
    
  - **_nerra_a11y_field_type_image_in_views()**

    You should call it from *hook_views_pre_render()*, as follows:

    `$apply_to = array(  
      array('view_name' => '[view_name_1]', 'field_name' => '[field_name_1]'),  
      array('view_name' => '[view_name_1]', 'field_name' => '[field_name_1]'),  
      .  
      .  
      array('view_name' => '[view_name_n]', 'field_name' => '[field_name_n]'),  
    );  
    _nerra_a11y_field_type_image_in_views(&$view, $apply_to);`
    
    Remark: In $apply_to array replace `[view_name_x]` and `[field_name_x]` with your view and field names.
  

  - **_nerra_a11y_field_file_entity_image()**

    You should call it from *template_preprocess_file_entity()*, as follows:
    
    `_nerra_a11y_field_file_entity_image($vars);`
  
  
  - **_nerra_a11y_form_input()**

    You should call it from *hook_form_alter()*, as follows:

    `_nerra_a11y_form_input($form['form_item_name'], $label);`


  - **_nerra_a11y_webform_form_controls_group()**

    You should call it from *hook_webform_component_render_alter()*, as follows:

    `_nerra_a11y_webform_form_controls_group($element, $component);`

    Remark: this doesn't apply to form actions, such as submit type inputs:
    `<input id="edit-submit-solr-pages" name="" value="Apply" class="form-submit custom-btn" type="submit">`


  - **_nerra_a11y_file_icon()**

    You should call it from *template_preprocess_file_icon()*, as follows:

    `_nerra_a11y_file_icon($vars);`

    
  - **_nerra_a11y_block()**

    You should call it from *template_preprocess_block()*, as follows:

    `_nerra_a11y_block($vars);`

    Remark: Check if it's not already implemented in `template_preprocess_block()`
    
    
  - **_nerra_a11y_block_menu_aria_labels()**

    You should call it from *template_preprocess_block()*, as follows:

    `_nerra_a11y_block_menu_aria_labels($vars);`

    Remark: Additionally you need to use this variable in tpl files: `block--menu.tpl.php` and `block--menu-block.tpl.php`
    
    
  - **_nerra_a11y_breadcrumb_aria_label()**

    You should call it from *template_preprocess_page()*, as follows:

    `_nerra_a11y_breadcrumb_aria_label($vars);`

    Remark: Additionally you need to use this variable in tpl file: `page.tpl.php` and `page--*.tpl.php`


  - **_nerra_a11y_html_attributes()**

    You should call it from *template_preprocess_html()*, as follows:

    `_nerra_a11y_html_attributes($vars);`

    Remark: Additionally you need to use this variable in tpl file: `html.tpl.php` and `html--*.tpl.php`