<?php

/**
 * @file
 * Admin page callbacks for the fancy_map_view module.
 */

function fancy_map_view_settings() {

  $form['fancy_map_view_google_maps_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Google Maps API Key'),
    '#default_value' => variable_get('fancy_map_view_google_maps_api_key', ''),
    '#description' => t('Google Maps API Key to use when rendering the map on the view'),
    '#size' => '40',
    '#maxlength' => '255',
  );

  return system_settings_form($form);

}