<?php

/**
 * Implements hook_views_plugins().
 */
function fancy_map_view_views_plugins() {
  $plugins = array(
    'style' => array(
      'fancy_map' => array(
        'title' => t('Fancy Map'),
        'help' => t('Displays rows on a Google map.'),
        'handler' => 'views_plugin_style_fancy_map',
        'path' => drupal_get_path('module', 'fancy_map_view') . '/views/plugins',
        'theme' => 'views_view_fancy_map',
        'theme file' => 'fancy_map_view.theme.inc',
        'theme path' => drupal_get_path('module', 'fancy_map_view') . '/theme',
        'uses grouping' => FALSE,
        'uses row plugin' => FALSE,
        'uses row class' => FALSE,
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
      ),
    ),
  );
  return $plugins;
}