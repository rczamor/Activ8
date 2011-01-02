<?php
// $Id: Styles.inc,v 1.1.2.5.2.4 2010/08/15 15:04:06 aaron Exp $

/**
 * @file Styles.inc
 * Base class for Styles.
 */

class StylesDefault {
  // The variables passed from our theme.
  public $variables = array();

  // The object passed from our theme.
  public $object = array();

  // Any effects to apply when displaying content matching this style.
  public $effects = array();

  // The final rendered output for this item.
  public $output;
  public $prefix = '<div class="styles">';
  public $suffix = '</div>';

  public function __construct($object = NULL, $effects = NULL, $variables = NULL) {
    // If we are passed an array, then set the object properties from its keys.
    if (isset($object)) {
      $properties = (array) $object;
      // Get the array of callable class methods for this object.
      $methods = get_class_methods($this);
      foreach ($properties as $key => $value) {
        $function = 'set_'. $key;
        if (in_array($function, $methods)) {
          // Call $this->set_PROPERTY_KEY($value) if that method exists.
          $this->$function($value);
        }
        else {
          $this->set($key, $value);
        }
      }
      $this->set_object($object);
    }
    if (isset($effects)) {
      $this->set_effects($effects);
    }
    if (isset($variables)) {
      $this->set_variables($variables);
    }
  }

  public function display($reset = FALSE) {
    return $this->render($reset);
  }

  public function render($reset = FALSE) {
    if ($reset) {
      $this->set_output(NULL);
    }

    $output = $this->get_output();

    if (!isset($output)) {
      // Get the array of callable class methods for this object.
      $methods = get_class_methods($this);
      foreach ($this->get_effects() as $effect) {
        $effect_name = $effect['name'];
        if ($effect_name && in_array($effect_name, $methods)) {
          $this->$effect_name($effect['settings']);
        }
        else {
          $variables = $this->get_variables();
          $style_name = $variables['style']['label'];
          watchdog('styles', 'Effect %effect_name not found for %style_name display formatter style of the %class_name class.', array('%effect_name' => $effect_name, '%style_name' => $style_name, '%class_name' => $this->get_class_name()), WATCHDOG_WARNING);
        }
      }
    }

    return $this->get_prefix() . $this->get_output() . $this->get_suffix();
  }

  static public function get_class_name() {
    return get_called_class();
  }

  /**
   * Add an effect to the end of the array.
   *
   * An effect is an array with at least a 'name' key, which corresponds to the
   * class function to be called during the rendering process. It will usually
   * also contain an array of 'effects' to apply.
   */
  public function add_effect($effect) {
    return $this->push_effect($effect);
  }
  public function push_effect($effect) {
    $effect_name = $effect['name'];
    if (method_exists($this, $effect_name)) {
      $effects = $this->get_effects();
      array_push($effects, $effect);
      return $this->set_effects($effects);
    }
    else {
      $variables = $this->get_variables();
      $style_name = $variables['style']['label'];
      watchdog('styles', 'Effect %effect_name not found for %style_name display formatter style of the %class_name class.', array('%effect_name' => $effect_name, '%style_name' => $style_name, '%class_name' => $this->get_class_name()), WATCHDOG_WARNING);
    }
  }
  public function pop_effect() {
    $effects = $this->get_effects();
    $effect = array_pop($effects);
    $this->set_effects($effects);
    return $effect;
  }
  public function unshift_effect($effect) {
    $effect_name = $effect['name'];
    if (method_exists($this, $effect_name)) {
      $effects = $this->get_effects();
      array_unshift($effects, $effect);
      return $this->set_effects($effects);
    }
    else {
      $variables = $this->get_variables();
      $style_name = $variables['style']['label'];
      watchdog('styles', 'Effect %effect_name not found for %style_name display formatter style of the %class_name class.', array('%effect_name' => $effect_name, '%style_name' => $this->get_name(), '%class_name' => $this->get_class_name()), WATCHDOG_WARNING);
    }
  }
  public function shift_effect() {
    $effects = $this->get_effects();
    $effect = array_shift($effects);
    $this->set_effects($effects);
    return $effect;
  }

  public function get_object() {
    return $this->get('object');
  }
  public function set_object($value) {
    return $this->set('object', $value);
  }

  public function get_variables() {
    return $this->get('variables');
  }
  public function set_variables($value) {
    return $this->set('variables', $value);
  }

  public function get_effects() {
    return $this->get('effects');
  }
  public function set_effects($value) {
    return $this->set('effects', $value);
  }

  public function get_output() {
    return $this->get('output');
  }
  public function set_output($value) {
    return $this->set('output', $value);
  }
  public function get_prefix() {
    return $this->get('prefix');
  }
  public function set_prefix($value) {
    return $this->set('prefix', $value);
  }
  public function get_suffix() {
    return $this->get('suffix');
  }
  public function set_suffix($value) {
    return $this->set('suffix', $value);
  }

  public function get($variable) {
    return $this->$variable;
  }
  public function set($variable, $value) {
    return $this->$variable = $value;
  }
}
