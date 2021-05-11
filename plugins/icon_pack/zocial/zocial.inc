<?php
/**
 * @file
 * Zocial icon pack.
 */

/**
 * Add additional classes for Zocial icons/buttons.
 */
function hybridauth_zocial_icon_classes_callback(&$classes, $provider_id) {
  $additional_classes = array('zocial');
  if ($provider_id == 'zocial') {
    $additional_classes[] = 'icon';
  }
  elseif ($provider_id == 'zocial_buttons') {
    backdrop_add_css($filepath . 'zocial/zocial.buttons.css');
  }
  if ($provider_id == 'Vkontakte') {
    $additional_classes[] = 'vk';
  }
  if ($provider_id == 'Apple') {
    $additional_classes[] = 'appstore';
  }
  $classes = array_merge($classes, $additional_classes);
}
