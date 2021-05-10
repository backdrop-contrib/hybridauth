<?php
/**
 * @file
 * HybridAuth ESIA specific settings.
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
function hybridauth_provider_esia_configuration_form_callback(&$form, $provider_id) {
  $config = config('hybridauth.settings');
  $app_settings = &$form['vtabs']['application'];
  unset($app_settings['hybridauth_provider_' . $provider_id . '_keys_key']);
  unset($app_settings['hybridauth_provider_' . $provider_id . '_keys_secret']);

  $app_settings['hybridauth_provider_' . $provider_id . '_oauth2_server'] = array(
    '#type' => 'textfield',
    '#title' => t('OAuth2 Server'),
    '#default_value' => $config->get('hybridauth_provider_' . $provider_id . '_oauth2_server'),
    '#description' => t('Server to send authentication requests to, like the test one @link.', array('@link' => 'https://esia-portal1.test.gosuslugi.ru')),
    '#weight' => -10,
  );

  $app_settings['hybridauth_provider_' . $provider_id . '_certificate_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Certificate'),
    '#default_value' => $config->get('hybridauth_provider_' . $provider_id . '_certificate_path'),
    '#description' => t('Server path to the certificate file.'),
  );
  $app_settings['hybridauth_provider_' . $provider_id . '_private_key_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Private key'),
    '#default_value' => $config->get('hybridauth_provider_' . $provider_id . '_private_key_path'),
    '#description' => t('Server path to the private key file.'),
  );
  $app_settings['hybridauth_provider_' . $provider_id . '_private_key_pass'] = array(
    '#type' => 'textfield',
    '#title' => t('Private key password'),
    '#default_value' => $config->get('hybridauth_provider_' . $provider_id . '_private_key_pass'),
    '#description' => t('Password for the private key.'),
  );
  $app_settings['hybridauth_provider_' . $provider_id . '_scope'] = array(
    '#type' => 'textfield',
    '#title' => t('Scope'),
    '#default_value' => $config->get('hybridauth_provider_' . $provider_id . '_scope'),
    '#description' => t(''),
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
function hybridauth_provider_esia_configuration_callback(&$config, $provider_id) {
  $config = config('hybridauth.settings');
  $config['oauth2_server'] = $config->get('hybridauth_provider_' . $provider_id . '_oauth2_server');
  $config['certificate_path'] = $config->get('hybridauth_provider_' . $provider_id . '_certificate_path');
  $config['private_key_path'] = $config->get('hybridauth_provider_' . $provider_id . '_private_key_path');
  $config['private_key_pass'] = $config->get('hybridauth_provider_' . $provider_id . '_private_key_pass');
  $config['scope'] = $config->get('hybridauth_provider_' . $provider_id . '_scope');
  $config['timestamp'] = format_date(REQUEST_TIME, 'custom', 'Y.m.d H:i:s O');
}
