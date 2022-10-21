#include "sharedDefines.h"

/* Callback functions used in other files

                rgb_led_control.c
    keyboard_post_init_user(void)
    suspend_power_down_user(void)
    suspend_wakeup_init_user(void)
    rgb_matrix_indicators_user(void)

                combos.c
    process_combo_event(uint16_t combo_index, bool pressed)

                leader.c
    matrix_scan_user(void)
    leader_start(void)
    leader_end(void)

                macros.c
    process_record_user(uint16_t keycode, keyrecord_t *record)


*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
       ,--------------------------------------------------.                                                                                                 ,--------------------------------------------------.
       |    0   |   1  |   2  |   3  |   4  |   5  |  6   |                                                                                                 |  38  |  39  |  40  |  41  |  42  |  43  |   44   |
       |--------+------+------+------+------+------+------|                                                                                                 |------+------+------+------+------+------+--------|
       |    7   |   8  |   9  |  10  |  11  |  12  |  13  |                                                                                                 |  45  |  46  |  47  |  48  |  49  |  50  |   51   |
       |--------+------+------+------+------+------|      |                                                                                                 |      |------+------+------+------+------+--------|
       |   14   |  15  |  16  |  17  |  18  |  19  |------|                                                                                                 |------|  52  |  53  |  54  |  55  |  56  |   57   |
       |--------+------+------+------+------+------|  26  |                                                                                                 |  58  |------+------+------+------+------+--------|
       |   20   |  21  |  22  |  23  |  24  |  25  |      |                                                                                                 |      |  59  |  60  |  61  |  62  |  63  |   64   |
       `--------+------+------+------+------+-------------'                                                                                                 `-------------+------+------+------+------+--------'
         |  27  |  28  |  29  |  30  |  31  |                                                                                                                             |  65  |  66  |  67  |  68  |  69  |
         `----------------------------------'                                                                                                                             `----------------------------------'
                                             ,-------------.                                                                                               ,-------------.
                                             |  32  |  33  |                                                                                               |  70  |  71  |
                                      ,------+------+------|                                                                                               |------+------+------.
                                      |      |      |  34  |                                                                                               |  72  |      |      |
                                      |  35  |  36  |------|                                                                                               |------|  74  |  75  |
                                      |      |      |  37  |                                                                                               |  73  |      |      |
                                      `--------------------'                                                                                               `--------------------'
     */

  [Layer_main] = LAYOUT_ergodox_pretty(
    CAPS_WORD,          KC_1,           KC_2,               KC_3,           KC_4,           KC_5,           KC_MINUS,                                       KC_EQUAL,       KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           LSFT(KC_ENTER),
    KC_TAB,             KC_Q,           KC_W,               KC_E,           KC_R,           KC_T,           LCTL(LSFT(KC_LGUI)),                            KC_F2,          KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           ST_MACRO_SSH,
    LCTL(KC_LALT),      KC_A,           KC_S,               KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_RALT,
    KC_LSHIFT,          KC_Z,           KC_X,               KC_C,           KC_V,           KC_B,           KC_HYPR,                                        KC_F4,          KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RCTRL,
    KC_LCTRL,           KC_LALT,        LCTL(LSFT(KC_LGUI)),LCTL(KC_LGUI),  LSFT(KC_LGUI),                                                                                                  KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_LEAD,



                                                                                                    LSFT(KC_PSCREEN),KC_PSCREEN,                            KC_PAGE_UP, KC_PAGE_DOWN, /*DYN_MACRO_PLAY1,DYN_MACRO_PLAY2,*/
                                                                                                                        KC_HOME,                            ST_MACRO_VIM_wq,
                                                        LT(Layer_symbols,KC_BSPACE),LGUI_T(KC_DELETE),           LCTL(KC_SPACE),                            LSFT_T(KC_ESCAPE),              LT(Layer_macros,KC_ENTER), KC_SPACE
  ),

  [Layer_mac_main] = LAYOUT_ergodox_pretty(
    CAPS_WORD,          KC_1,           KC_2,               KC_3,           KC_4,           KC_5,           KC_MINUS,                                       KC_EQUAL,       KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           LSFT(KC_ENTER),
    KC_TAB,             KC_Q,           KC_W,               KC_E,           KC_R,           KC_T,           LCTL(LSFT(KC_LGUI)),                            KC_F2,          KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           ST_MACRO_SSH,
    LCTL(KC_LALT),      KC_A,           KC_S,               KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_RALT,
    KC_LSHIFT,          KC_Z,           KC_X,               KC_C,           KC_V,           KC_B,           KC_HYPR,                                        KC_F4,          KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RCTRL,
    KC_LGUI,            KC_LALT,        LCTL(LSFT(KC_LGUI)),LCTL(KC_LGUI),  LSFT(KC_LGUI),                                                                                                  KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_LEAD,



                                                                                                    LSFT(KC_PSCREEN),LCTL(LGUI(LSFT(KC_4))),                KC_PAGE_UP, KC_PAGE_DOWN, /*DYN_MACRO_PLAY1,DYN_MACRO_PLAY2,*/
                                                                                                                        KC_HOME,                            ST_MACRO_VIM_wq,
                                                    LT(Layer_mac_symbols,KC_BSPACE),LCTL_T(KC_DELETE),           LCTL(KC_SPACE),                            LSFT_T(KC_ESCAPE),              LT(Layer_macros,KC_ENTER), KC_SPACE
  ),



  [Layer_colemak] = LAYOUT_ergodox_pretty(
    _______,    _______,    _______,    _______,    _______,    _______,    _______,                   _______,     _______,    _______,    _______,    _______,    _______,    _______,
    _______,    KC_Q,       KC_W,       KC_F,       KC_P,       KC_B,       _______,                   _______,     KC_J,       KC_L,       KC_U,       KC_Y,       KC_SCOLON,  _______,
    _______,    KC_A,       KC_R,       KC_S,       KC_T,       KC_G,                                               KC_M,       KC_N,       KC_E,       KC_I,       KC_O,       _______,
    _______,    KC_Z,       KC_X,       KC_C,       KC_D,       KC_V,       _______,                   _______,     KC_K,       KC_H,       KC_COMMA,   KC_DOT,     KC_SLASH,   _______,
    _______,    _______,    _______,    _______,    _______,                                                                    _______,    _______,    _______,    _______,    _______,



                                                                _______,    _______,                   _______,     _______,
                                                                            _______,                   _______,
                                                    _______,    _______,    _______,                   _______,     _______,    _______
  ),




  [Layer_symbols] = LAYOUT_ergodox_pretty(
    LSFT(KC_GRAVE),     KC_F1,          KC_F2,              KC_F3,                  KC_F4,              KC_F5,              KC_F11,                          KC_F12,        KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F13,
    KC_MS_BTN5,         KC_GRAVE,       KC_QUOTE,           LSFT(KC_QUOTE),         LSFT(LCTL(KC_C)),   LSFT(LCTL(KC_V)),   KC_CIRC,                        _______,        KC_LABK,        KC_PLUS,        KC_MINUS,       KC_RABK,        KC_EQUAL,       _______,
    KC_MS_BTN4,         KC_EXLM,        LSFT(KC_2),         LSFT(KC_3),             KC_DLR,             KC_PERC,                                                            KC_ASTR,        KC_LBRACKET,    KC_RBRACKET,    KC_UNDS,        KC_QUES,        _______,
    KC_LSHIFT,          ST_M_n_equal,   KC_AMPR,            LSFT(KC_NONUS_BSLASH),  LSFT(KC_NONUS_HASH),KC_ASTR,            KC_CIRC,                        _______,        KC_AMPR,        KC_LCBR,        KC_RCBR,        KC_DOT,         KC_NONUS_BSLASH,KC_LSHIFT,
    LALT(KC_LCTRL),     ST_M_n_equal_2, LCTL(KC_X),         LCTL(KC_C),             LCTL(KC_V),                                                                                             LSFT(KC_9),     LSFT(KC_0),     ST_M_l_equal,   ST_M_g_equal,   KC_LALT,


                                                                                                                    _______,_______,                        _______, _______,
                                                                                                                            _______,                        _______,
                                                                                        _______, _______,                   _______,                        LSFT(KC_SCOLON),                KC_NONUS_HASH,  KC_SCOLON
  ),

  [Layer_mac_symbols] = LAYOUT_ergodox_pretty(
    LSFT(KC_GRAVE),     KC_F1,          KC_F2,              KC_F3,                  KC_F4,              KC_F5,              KC_F11,                          KC_F12,        KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F13,
    KC_MS_BTN5,         KC_GRAVE,       KC_QUOTE,           LSFT(KC_2),             LGUI(LCTL(KC_C)),   LGUI(LCTL(KC_V)),   KC_CIRC,                        _______,        KC_LABK,        KC_PLUS,        KC_MINUS,       KC_RABK,        KC_EQUAL,       _______,
    KC_MS_BTN4,         KC_EXLM,        LSFT(KC_QUOTE),     LSFT(KC_3),             KC_DLR,             KC_PERC,                                                            KC_ASTR,        KC_LBRACKET,    KC_RBRACKET,    KC_UNDS,        KC_QUES,        _______,
    KC_LSHIFT,          ST_M_n_equal,   KC_AMPR,            LSFT(KC_NONUS_HASH),    LSFT(KC_GRAVE),     KC_ASTR,            KC_CIRC,                        _______,        KC_AMPR,        KC_LCBR,        KC_RCBR,        KC_DOT,         KC_NONUS_HASH,  KC_LSHIFT,
    LALT(KC_LCTRL),     ST_M_n_equal_2, LGUI(KC_X),         LGUI(KC_C),             LGUI(KC_V),                                                                                             LSFT(KC_9),     LSFT(KC_0),     ST_M_l_equal,   ST_M_g_equal,   KC_LALT,


                                                                                                                    _______,_______,                        _______, _______,
                                                                                                                            _______,                        _______,
                                                                                        _______, _______,                   _______,                        LSFT(KC_SCOLON),                LALT(KC_3),     KC_SCOLON
  ),



  [Layer_macros] = LAYOUT_ergodox_pretty(
//  ST_M_led_timeout_30s,   _______,        _______,            DYN_REC_START1, DYN_REC_START2,   DYN_REC_STOP,   ST_M_colemak_mode_toggle,                         _______,  _______,        ST_M_brightness_down,           ST_M_brightness_up,     _______,                    _______,         RESET,
    ST_M_led_timeout_30s,   _______,        _______,            _______,        _______,               _______,   ST_M_colemak_mode_toggle,                      KC_KB_MUTE,  _______,        ST_M_brightness_down,           ST_M_brightness_up,     _______,                    _______,         QK_BOOT,
    ST_M_led_timeout_1m,    ST_M_vim_q,     ST_M_vim_w,         _______,        LCTL(KC_V),       LCTL(KC_B),     _______,                                  KC_KB_VOLUME_UP,  _______,        ST_M_hue_down,                  ST_M_hue_up,            _______,                    _______,         ST_M_enable_bunny_hop,
    ST_M_led_timeout_5m,    _______,        _______,            _______,        ST_M_vim_sp,      ST_M_vim_vs,                                                                LCTL(KC_H),     LCTL(KC_J),                     LCTL(KC_K),             LCTL(KC_L),                 _______,         ST_M_toggle_main_layer_brightness,
    ST_M_led_timeout_10m,   _______,        _______,            _______,        ST_M_vim_sp_e,    ST_M_vim_vs_e,  _______,                                KC_KB_VOLUME_DOWN,  _______,        ST_M_mac_mode_toggle,           _______,                _______,                    _______,         _______,
    _______,                ST_M_combo_toggle, _______,         _______,        _______,                                                                                                      _______,                        _______,                _______,                    _______,         _______,


                                                                                                                _______,    _______,                        KC_BRIGHTNESS_UP, _______,
                                                                                                                            _______,                        KC_BRIGHTNESS_DOWN,
                                                                        KC_SPACE,       LALT(KC_ENTER),                     _______,                        ST_M_double_colon,              _______, _______
  ),


  [Layer_gaming] = LAYOUT_ergodox_pretty(
    KC_0,               KC_1,           KC_2,               KC_3,           KC_4,           KC_5,           KC_6,                                           KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_HOME,
    KC_ESCAPE,          KC_8,           KC_Q,               KC_W,           KC_E,           KC_R,           KC_7,                                           KC_F6,          KC_KP_ASTERISK, KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_MINUS,    KC_END,
    KC_TAB,             KC_9,           KC_A,               KC_S,           KC_D,           KC_F,                                                                           KC_KP_SLASH,    KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_PLUS,     KC_DELETE,
    KC_LSHIFT,          KC_LSHIFT,      KC_X,               KC_C,           KC_V,           KC_G,           KC_ENTER,                                       KC_F5,          KC_KP_ENTER,    KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_UP,          TO(Layer_main),
    KC_LCTRL,           KC_Z,           KC_I,               KC_C,           KC_B,                                                                                                           KC_KP_0,        KC_KP_DOT,      KC_LEFT,        KC_DOWN,        KC_RIGHT,
                                                                                                                        KC_Y, KC_U,                         KC_F3, KC_F4,
                                                                                                                              KC_O,                         KC_F2,
                                                                  ST_M_bunny_hop,       KC_LCTRL,                             KC_M,                         KC_F1,          KC_NUMLOCK,     KC_INSERT
  ),


};

// uint32_t layer_state_set_user(uint32_t state) {
//     // if(state == Layer_main){ // game layer always returns to Layer_main so need to update mac_mode accordingly. however updating it causes an issue where you can't go back to mac mode
//     //     mac_mode = false;
//     // }else if(state == Layer_mac_main){
//     //     mac_mode = true;
//     // }
//     return state;
// };
