#include "default.h"

// Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 8, HSV_RED}       // Light 8 LEDs, starting with LED 0
);

const rgblight_segment_t PROGMEM my_numlock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 2, HSV_SPRINGGREEN}       // Light 2 LEDs, starting with LED 6
);

const rgblight_segment_t PROGMEM my_layer_symbols[] = RGBLIGHT_LAYER_SEGMENTS(
    {43, 12,
    21, 255, 170} // orange
);

const rgblight_segment_t PROGMEM my_layer_nums[] = RGBLIGHT_LAYER_SEGMENTS(
    {43, 12, HSV_TEAL}
);

const rgblight_segment_t PROGMEM my_layer_fkeys[] = RGBLIGHT_LAYER_SEGMENTS(
    {43, 12,
    181, 255, 170} // purple
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_numlock_layer,
    my_layer_symbols,
    my_layer_nums,
    my_layer_fkeys
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    rgblight_set_layer_state(1, led_state.num_lock);
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(2, layer_state_cmp(state, Layer_symbols));
    rgblight_set_layer_state(3, layer_state_cmp(state, Layer_nums));
    rgblight_set_layer_state(4, layer_state_cmp(state, Layer_fkeys));
    return state;
}
