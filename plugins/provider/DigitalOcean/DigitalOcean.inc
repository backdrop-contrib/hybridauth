<?php
/**
 * @file
 * HybridAuth DigitalOcean specific settings.
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
function hybridauth_provider_digitalocean_configuration_form_callback(&$form, $provider_id) {
  $app_settings = &$form['vtabs']['application'];

  $app_settings['#description'] = t('<p>Enter the <strong>Client ID</strong> and <strong>Client Secret</strong>.<br/>'
    . 'On the server you must set the <strong>Redirect URI</strong> of the client to:<br/>'
    . '<strong>%redirect_uri</strong></p>',
    array(
    '%redirect_uri' => url('hybridauth/endpoint', array('absolute' => TRUE, 'language' => _hybridauth_language_default())),
    )
  );

  unset($app_settings['hybridauth_provider_' . $provider_id . '_keys_key']);
  unset($app_settings['hybridauth_provider_' . $provider_id . '_keys_id']['#description']);
  unset($app_settings['hybridauth_provider_' . $provider_id . '_keys_secret']['#description']);
  $app_settings['hybridauth_provider_' . $provider_id . '_keys_id']['#title'] = t('Client ID');
  $app_settings['hybridauth_provider_' . $provider_id . '_keys_secret']['#title'] = t('Client Secret');

  $app_settings['hybridauth_provider_' . $provider_id . '_scope'] = array(
    '#type' => 'select',
    '#title' => t('Scope'),
    '#description' => t('The scope of access to the DigitalOcean account. Default is read-only.'),
    '#options' => array(
      'read' => t('Read'),
      'read write' => t('Read and write'),
    ),
    '#default_value' => config_get('hybridauth.settings', 'hybridauth_provider_' . $provider_id . '_scope'),
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
function hybridauth_provider_digitalocean_configuration_callback(&$config, $provider_id) {
  $config['scope'] = config_get('hybridauth.settings', 'hybridauth_provider_' . $provider_id . '_scope');
}
