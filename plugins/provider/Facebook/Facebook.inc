<?php
/**
 * @file
 * HybridAuth Facebook specific settings.
 */

/**
 * Make adjustments to the provider settings form.
 *
 * @param array $form
 *    Settings form as a render array.
 * @param string $provider_id
 *    Lowercase provider id value.
 *
 * @return
 *    A modified render array for the provider settings form (by reference).
 */
function hybridauth_provider_facebook_configuration_form_callback(&$form, $provider_id) {
  $config = config('hybridauth.settings');
  unset($form['vtabs']['application']['hybridauth_provider_' . $provider_id . '_keys_key']);

  $form['vtabs']['application']['#description'] = t('<p>Enter your application ID and private key. You can get these by creating a new application at <a href="!apps_uri">!apps_uri</a>.</p>'
    . '<p>You must set <strong>App Domains</strong> to something like <strong>example.com</strong> to cover <strong>*.example.com</strong>.</p>'
    . '<p>You must set <strong>Site URL</strong> to <strong>%site_uri</strong>.</p>'
    . '<p>You must set <strong>Callback URL</strong> to <strong>%callback_uri</strong>.</p>',
    array(
    '!apps_uri' => 'https://developers.facebook.com/apps',
    '%site_uri' => url('<front>', array('absolute' => TRUE)),
    '%callback_uri' => url('hybridauth/endpoint', array('absolute' => TRUE, 'query' => array('hauth_done' => 'Facebook'), 'language' => _hybridauth_language_default())),
  )
  );

  $form['vtabs']['window_settings']['hybridauth_provider_' . $provider_id . '_display'] = array(
    '#type' => 'radios',
    '#title' => t('Display type'),
    '#options' => array(
      'page' => t('Page'),
      'popup' => t('Popup'),
    ),
    '#default_value' => $config->get('hybridauth_provider_' . $provider_id . '_display'),
    '#description' => t('Determines how the authentication window is rendered.'),
  );
  $form['vtabs']['advanced'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advanced settings'),
  );

  // Compatibility conversion from the array value.
  $default_value = $config->get('hybridauth_provider_' . $provider_id . '_scope');
  if (is_array($default_value)) {
    $default_value = implode(',', array_filter($default_value));
  }
  $form['vtabs']['advanced']['hybridauth_provider_' . $provider_id . '_scope'] = array(
    '#type' => 'textfield',
    '#title' => t('Scope'),
    '#description' => t('Comma separated list of permissions, see <a href="!link" target="_blank">Facebook Login Permissions Reference</a>.', array('!link' => 'http://developers.facebook.com/docs/facebook-login/permissions/')),
    '#default_value' => $default_value,
    '#required' => TRUE,
    '#maxlength' => 512,
  );
  $form['vtabs']['advanced']['hybridauth_provider_' . $provider_id . '_trustForwarded'] = array(
    '#type' => 'checkbox',
    '#title' => t('Trust X-Forwarded-* headers'),
    '#default_value' => $config->get('hybridauth_provider_' . $provider_id . '_trustForwarded'),
  );
}

/**
 * Make adjustments to the default provider configuration.
 *
 * @param array $config
 *    Config data as a keyed array.
 * @param string $provider_id
 *    Lowercase provider id value.
 *
 * @return
 *    A modified config array for the provider configuration (by reference).
 */
function hybridauth_provider_facebook_configuration_callback(&$config, $provider_id) {
  if (empty($config['scope'])) {
    $config['scope'] = hybridauth_provider_facebook_scope_default();
  }
  $config['trustForwarded'] = config_get('hybridauth.settings', 'hybridauth_provider_' . $provider_id . '_trustForwarded');
}

/**
 * Provide a default scope.
 */
function hybridauth_provider_facebook_scope_default() {
  return 'public_profile,email';
}
