# HybridAuth for Backdrop

HybridAuth Social Login bundles the HybridAuth library (v2.17.0) and allows
your Backdrop site users to login and register using:

 - Facebook
 - Twitter
 - LinkedIn
 - Google
 - Yahoo
 - Windows Live
 - Foursquare
 - AOL
 - OpenID
 - Github, LastFM, PayPal, Vimeo, Disqus, Instagram, Tumblr, Vkontakte, 
   Mail.ru, Yandex, Odnoklassniki, Twitch.tv, Steam and more.

### Advantages

 - Doesn't depend on any external service
 - Doesn't load any external CSS or JS files - blazingly fast widget rendering
 - Relies on third-party open source PHP library HybridAuth (provides 
   communication with authentication providers; no need to support them in 
   the module code) developed and supported on GitHub by broad community 
   of contributors

## Installation

- Install this module using the official 
  [Backdrop CMS instructions](https://backdropcms.org/guide/modules)

## Usage

After installation please go through the configuration settings and grant your
users permission to use HybridAuth:
- anonymous users - to login using HybridAuth widget
- authenticated users - to add more HybridAuth identities to the account

HybridAuth library requires php-curl extension.

If you need additional providers support like Mail.ru - then you need to
copy needed additional providers to the library and clear Backdrop caches.
For instance, to get Mail.ru provider working you need to copy
`additional-providers/hybridauth-mailru/Providers/Mailru.php` to
`hybridauth/Hybrid/Providers/Mailru.php`, clear caches, and you are good to go.
After that you just need to configure your application ID, private and secret
keys at module configuration pages. [See issue 3 for potential changes to this](https://github.com/backdrop-contrib/hybridauth/issues/3#issuecomment-612197746).

## Recommended additions:

Other potential modules:
- Rules - to map HybridAuth data to user profile fields and other great stuff.
[See the wiki for an example](https://github.com/backdrop-contrib/hybridauth/wiki/Rules-integration).
- Real name - as it caches display names and improves performance of your site.

## Issues

If you have an issue with any provider not working - please check provider
documentation at http://hybridauth.sourceforge.net/userguide.html - just click
on the provider name and read the instructions related to registering your
application at the provider's site and configuring this application settings.

Bugs and Feature requests should be reported in the 
[Issue Queue](https://github.com/backdrop-contrib/hybridauth/issues)

## Current Maintainers

- [Laryn Kragt Bakker](https://github.com/laryn) - [CEDC.org](https://cedc.org)
- Seeking additional maintainers

## Credits

- Ported to Backdrop CMS by [Laryn Kragt Bakker](https://github.com/laryn) - [CEDC.org](https://cedc.org)
- Maintainer for the Drupal module: [duozersk](https://www.drupal.org/u/duozersk)

## License

This project is GPL v2 software. See the LICENSE.txt file in this directory
for complete text.

The HybridAuth library itself has been released under the MIT license.

