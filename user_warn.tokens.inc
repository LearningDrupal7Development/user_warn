<?php
// $Id: comment.tokens.inc,v 1.8 2009/12/04 16:49:46 dries Exp $

/**
 * @file
 * Builds placeholder replacement tokens for comment-related data.
 */

/**
 * Implements hook_token_info().
 */
function user_warn_token_info() {
  // User warn related tokens for nodes
  $site['tos-url'] = array(
    'name' => t("Terms of Service URL"),
    'description' => t("URL to the site's terms of service."),
  );

  return array(
    'tokens' => array(
      'site' => $site,
    ),
  );
}

/**
 * Implements hook_tokens().
 */
function user_warn_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $url_options = array('absolute' => TRUE);
  if (isset($options['language'])) {
    $url_options['language'] = $options['language'];
  }
  $sanitize = !empty($options['sanitize']);

  $replacements = array();

  if ($type == 'site') {
    foreach ($tokens as $name => $original) {
      switch ($name) {
        // Simple key values on the comment.
        case 'tos-url':
          $replacements[$original] = variable_get('user_warn_tos_url', '');
          break;
      }
    }
  }

  return $replacements;
}
