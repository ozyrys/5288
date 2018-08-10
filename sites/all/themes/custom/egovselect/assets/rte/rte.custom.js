/*
Copyright (c) 2003-2012, CKSource - Frederico Knabben. All rights reserved.
For licensing, see LICENSE.html or http://ckeditor.com/license
*/

/*
 * This file is used/requested by the 'Styles' button.
 * The 'Styles' button is not enabled by default in DrupalFull and DrupalFiltered toolbars.
 */
if(typeof(CKEDITOR) !== 'undefined') {
    CKEDITOR.addStylesSet('drupal',
    [
        { name : 'Summary', element : 'p', attributes : { 'class' : 'summary' } },
        { name : 'Paragraph', element : 'p' },
		    { name : 'Paragraph with border bottom', element : 'p', attributes : { 'class' : 'paragraph-border-bottom' } },
		    { name : 'Paragraph inline-block', element : 'p', attributes : { 'class' : 'inline-block' } },
        { name : 'Heading 2', element : 'h2' },
        { name : 'Heading 3', element : 'h3' },
        { name : 'Heading 4', element : 'h4' },
        { name : 'Heading 5', element : 'h5' },
        { name : 'Heading 6', element : 'h6' },
        { name : 'Quotation', element : 'p', attributes : { 'class' : 'ck-quotation' } },
        { name : 'Div', element : 'div' },
        { name : 'Div gmap container', element : 'div', attributes : { 'class' : 'map-container' } },
        { name : 'Div with padding', element : 'div', attributes : { 'class' : 'padding-container' } },
        { name : 'Color Dark Blue', element : 'span', attributes: {'class' : 'color-dark-blue'} },
        { name : 'Coordinates icon', element : 'span', attributes: {'class' : 'coordinates-icon'} },
        { name : 'Phone icon', element : 'span', attributes: {'class' : 'phone-icon'} },
        { name : 'Email icon', element : 'span', attributes: {'class' : 'email-icon'} },
    ]);
}
