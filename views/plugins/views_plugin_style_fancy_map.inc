<?php

/**
 * Style plugin to render each item in an ordered or unordered list.
 *
 * @ingroup views_style_plugins
 */
class views_plugin_style_fancy_map extends views_plugin_style {
  /**
   * Set default options
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['latitude_field'] = array('default' => '');
    $options['longitude_field'] = array('default' => '');
    return $options;
  }

  /**
   * Render the given style.
   */
  function options_form(&$form, &$form_state) {

    parent::options_form($form, $form_state);

    $options = $this->display->handler->get_field_labels();

    if (!empty($options)) {
      $form['latitude_field'] = array(
        '#type' => 'select',
        '#title' => t('Location Latitude Field'),
        '#options' => $options,
        '#default_value' => $this->options['latitude_field'],
        '#description' => t('Select the field to use as the location field'),
      );
      $form['longitude_field'] = array(
        '#type' => 'select',
        '#title' => t('Location Longitude Field'),
        '#options' => $options,
        '#default_value' => $this->options['longitude_field'],
        '#description' => t('Select the field to use as the location field'),
      );
    }

  }
}
