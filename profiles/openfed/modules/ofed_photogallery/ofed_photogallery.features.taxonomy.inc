<?php
/**
 * @file
 * ofed_photogallery.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ofed_photogallery_taxonomy_default_vocabularies() {
  return array(
    'ofed_photogallery' => array(
      'name' => 'Photo gallery',
      'machine_name' => 'ofed_photogallery',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 4,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
