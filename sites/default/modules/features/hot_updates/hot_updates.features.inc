<?php
/**
 * @file
 * hot_updates.features.inc
 */

/**
 * Implements hook_views_api().
 */
function hot_updates_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function hot_updates_image_default_styles() {
  $styles = array();

  // Exported image style: update_content.
  $styles['update_content'] = array(
    'name' => 'update_content',
    'label' => 'update_content',
    'effects' => array(
      5 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 780,
          'height' => 520,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function hot_updates_node_info() {
  $items = array(
    'update' => array(
      'name' => t('Update'),
      'base' => 'node_content',
      'description' => t('An update that appears on the home page and project pages'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}