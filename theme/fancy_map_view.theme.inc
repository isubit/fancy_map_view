<?php

/**
 * Display the simple view of rows one after another
 */
function template_preprocess_views_view_fancy_map(&$vars) {

  $view = $vars['view'];
  $rows = $vars['rows'];
  $style = $view->style_plugin;
  $options = $style->options;

  $module_path = drupal_get_path('module', 'fancy_map_view');

  $lat_field = $options['latitude_field'];
  $lng_field = $options['longitude_field'];

  drupal_add_css($module_path . '/css/fancy_map_view.css');

  drupal_add_js('//maps.googleapis.com/maps/api/js?'. drupal_http_build_query(array('v' => 3, 'libraries' => 'geometry', 'key' => variable_get('fancy_map_view_google_maps_api_key', ''))), 'external');
  drupal_add_js($module_path . '/js/markerclusterer.js');
  drupal_add_js($module_path . '/js/fancy_map_view.js');

  $settings = array(
    'modulePath' => drupal_get_path('module', 'fancy_map_view'),
  );

  $settings['features'] = array(
    'type' => 'FeatureCollection',
    'features' => array(),
  );

  $fields = array();

  foreach ($view->field as $fid => $field) {
    if (empty($field->options['exclude'])) {
      $field_label = check_plain($view->field[$fid]->label());
      $fields[$fid] = ($field_label ? $field_label : $fid);
    }
  }

  foreach ($rows as $rid => $row) {

    $row_fields = array();

    foreach ($fields as $fid => $field_key) {
      $field_output = $style->get_field($rid, $fid);
      $row_fields[$fid] = array(
        'key' => $field_key,
        'value' => $field_output,
      );
    }

    if (!empty($row_fields[$lat_field]['value']) && !empty($row_fields[$lng_field]['value'])) {

      $feature = array(
        'type' => 'Feature',
        'geometry' => array(
          'type' => 'Point',
          'coordinates' => array(
            (float) $row_fields[$lng_field]['value'],
            (float) $row_fields[$lat_field]['value'],
          ),
        ),
        'properties' => array(),
      );

      $properties = array_diff_key($row_fields, array_flip(array($lat_field, $lng_field)));

      foreach ($properties as $property) {
        $feature['properties'][$property['key']] = $property['value'];
      }

      $settings['features']['features'][] = $feature;

    }

  }

  drupal_add_js(array('fancyMapView' => $settings), 'setting');

}