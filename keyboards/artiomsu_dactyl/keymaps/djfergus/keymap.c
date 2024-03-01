#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _FUNCTION 1
#define _CLEAR 2

// Some basic macros

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_5x7(
        // left hand
        KC_ESC,   KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,
        KC_TAB,   KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   KC_LBRC,
        KC_LCTL,   KC_A,    KC_S,    KC_D,   KC_F,   KC_G,   KC_CAPS,
        OSM(MOD_LSFT),   KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,
        MO(_FUNCTION),   KC_X,    KC_QUES,    KC_LGUI,
                                    KC_ENT, KC_LGUI,
                                    KC_LALT, QK_RBT, 
                                    KC_M, KC_Q,
        // right hand
                          KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_GRV,
                          KC_RBRC, KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,     KC_BSLS,
                          KC_R,    KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN,     KC_QUOT,
                                   KC_BSPC, KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  
                                            0x81, KC_SPC,    KC_LALT,  KC_DEL,
             MO(_FUNCTION), 0x80,
             KC_2, KC_3,
             OSM(MOD_RSFT), KC_LGUI
    ),
    [_FUNCTION] = LAYOUT_5x7(
        // left hand
        QK_BOOT, RGB_MODE_FORWARD, RGB_MODE_REVERSE,  KC_3,   KC_4,   KC_5,   KC_6,
        KC_9,   RGB_HUI,    RGB_HUD,    KC_E,   KC_R,   KC_T,   KC_7,
        KC_Y,   RGB_SAI,    RGB_SAD,    KC_D,   KC_F,   KC_G,   KC_8,
        KC_U,   RGB_VAI,    RGB_VAD,    KC_C,   KC_V,   KC_B,
        MO(_FUNCTION),   KC_O,    KC_P,    KC_H,
                                    KC_1, KC_2,
                                    KC_L, KC_N,
                                    KC_M, KC_DOT,

        // right hand
                          KC_7,    KC_A,    KC_B,    KC_0,     KC_MINS,  KC_EQL,   QK_BOOT,
                          KC_RBRC, KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,     KC_A,
                          KC_R,    KC_H,    KC_J,    KC_K,     KC_L,     KC_W,     KC_QUOT,
                                   KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_E,
                                            KC_LEFT, KC_UP,    KC_DOWN,  KC_RGHT,
             KC_0, KC_1,
             KC_2, KC_3,
             KC_4, KC_5
    ),
    [_CLEAR] = LAYOUT_5x7(
        // left hand
        QK_CLEAR_EEPROM,   KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,
        KC_9,   KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   KC_7,
        KC_Y,   KC_A,    KC_S,    KC_D,   KC_F,   KC_G,   KC_8,
        KC_U,   KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,
        KC_I,   KC_O,    KC_P,    KC_H,
                                    MO(_FUNCTION), KC_K,
                                    KC_L, KC_N,
                                    KC_M, KC_DOT,
        // right hand
                          KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   QK_CLEAR_EEPROM,
                          KC_RBRC, KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,     KC_A,
                          KC_R,    KC_H,    KC_J,    KC_K,     KC_L,     KC_W,     KC_QUOT,
                                   KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_E,
                                            KC_LEFT, KC_UP,    KC_DOWN,  KC_RGHT,
             KC_0, KC_1,
             KC_2, KC_3,
             KC_4, KC_5
    )
};


void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=false;
  //debug_mouse=true;
}



