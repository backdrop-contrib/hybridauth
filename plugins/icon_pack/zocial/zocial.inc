<?php
/**
 * @file
 * Zocial icon pack.
 */

/**
 * Plugin declaration.
 */
$plugin = array(
  'title' => t('Zocial'),
  'css' => backdrop_get_path('module', 'hybridauth') . 'plugins/icon_pack/zocial/library/css/zocial.css',
  'icon_classes_callback' => 'hybridauth_zocial_icon_classes_callback',
);

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function hybridauth_zocial_icon_classes_callback(&$classes, $provider_id) {
  dpm($classes);
  dpm($provider_id);
  $additional_classes = array('zocial', 'icon');
  if ($provider_id == 'Vkontakte') {
    $additional_classes[] = 'vk';
  }
  $classes = array_merge($classes, $additional_classes);
}
