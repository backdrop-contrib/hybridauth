<?php
/**
 * @file
 * Theme functions for the HybridAuth module.
 */

/**
 * Template preprocess function for hybridauth_widget.
 */
function template_preprocess_hybridauth_widget(&$vars, $hook) {
  $element = $vars['element'];
  $vars['title'] = filter_xss_admin($element['#title']);
  $vars['providers'] = array();
  foreach ($element['providers'] as $provider) {
    $vars['providers'][] = l(render($provider['text']), $provider['path'], $provider['options']);
  }
}

/**
 * Template preprocess function for hybridauth_provider_icon.
 */
function template_preprocess_hybridauth_provider_icon(&$vars, $hook) {
  $icon_pack_classes = array(
    'hybridauth-icon',
    backdrop_html_class($vars['provider_id']),
    backdrop_html_class('hybridauth-icon-' . $vars['icon_pack']),
    backdrop_html_class('hybridauth-' . $vars['provider_id']),
    backdrop_html_class('hybridauth-' . $vars['provider_id'] . '-' . $vars['icon_pack']),
  );

  // Icon pack modifications.
  $icon_pack = hybridauth_get_icon_pack($vars['icon_pack']);
  if (!empty($icon_pack['plugin']['icon_classes_callback']) && !empty($icon_pack['plugin']['include'])) {
    include_once $icon_pack['plugin']['include'];
    $function = $icon_pack['plugin']['icon_classes_callback'];
    $function($icon_pack_classes, $vars['provider_id']);
  }
  // Provider modifications.
  $provider = hybridauth_get_provider($vars['provider_id']);
  if (!empty($provider)) {
    if (!empty($provider[$vars['provider_id']]['plugin']['icon_classes_callback'])) {
      $function = $provider[$vars['provider_id']]['plugin']['icon_classes_callback'];
      $function($icon_pack_classes);
    }
  }

  $vars['icon_pack_classes'] = implode(' ', $icon_pack_classes);
}
