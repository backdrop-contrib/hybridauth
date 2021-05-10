<?php
/**
 * @file
 * HybridAuth Twitter specific settings.
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
function hybridauth_provider_twitter_configuration_form_callback(&$form, $provider_id) {
  unset($form['vtabs']['application']['hybridauth_provider_' . $provider_id . '_keys_id']);

  $form['vtabs']['application']['#description'] = t('<p>Enter your consumer key and private key. You can get these by creating a new application at <a href="!apps_uri">!apps_uri</a>.</p>'
    . '<p>You must set <strong>Callback URL</strong> to <strong>%callback_uri</strong>.</p>',
    array(
    '!apps_uri' => 'https://dev.twitter.com/apps',
    '%callback_uri' => url('hybridauth/endpoint', array('absolute' => TRUE, 'language' => _hybridauth_language_default())),
  )
  );
  $form['vtabs']['advanced'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advanced settings'),
  );
  $form['vtabs']['advanced']['hybridauth_provider_' . $provider_id . '_includeEmail'] = array(
    '#type' => 'checkbox',
    '#title' => t('Include E-mail'),
    '#default_value' => config_get('hybridauth.settings', 'hybridauth_provider_' . $provider_id . '_includeEmail'),
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
function hybridauth_provider_twitter_configuration_callback(&$config, $provider_id) {
  $config['includeEmail'] = config_get('hybridauth.settings', 'hybridauth_provider_' . $provider_id . '_includeEmail');
}
