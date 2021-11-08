#include QMK_KEYBOARD_H
#include "version.h"

#define bool _Bool
#define true 1
#define false 0

// layer defines
/*
    Layers accessing other layers must be under the layer that they access.
    For example, if layer 1 is accessing layer 2, layer 2 must be after layer 1.
*/
#define Layer_main 0
#define Layer_mac_main 1
#define Layer_symbols 2
#define Layer_mac_symbols 3
#define Layer_macros 4
#define Layer_gaming 5

// layer Colours since they are different from layers themselves now
#define Layer_main_colour 0
#define Layer_symbols_colour 1
#define Layer_macros_colour 2
#define Layer_gaming_colour 3


enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  ST_MACRO_SSH,
  ST_MACRO_VIM_wq,
  ST_M_n_equal,
  ST_M_n_equal_2,
  ST_M_l_equal,
  ST_M_g_equal,
  ST_M_vim_q,
  ST_M_vim_w,
  ST_M_vim_sp,
  ST_M_vim_vs,
  ST_M_vim_sp_e,
  ST_M_vim_vs_e,
  ST_M_double_colon,
  ST_M_bunny_hop,
  ST_M_enable_bunny_hop,
  ST_M_brightness_down,
  ST_M_brightness_up,
  ST_M_hue_down,
  ST_M_hue_up,
  ST_M_toggle_main_layer_brightness,
  ST_M_led_timeout_30s,
  ST_M_led_timeout_1m,
  ST_M_led_timeout_5m,
  ST_M_led_timeout_10m,
  ST_M_combo_toggle,
  ST_M_mac_mode_toggle
};

bool rgb_show = true;
bool rgb_timed_out = false;
int timeout_counter = 0;
uint32_t rgb_sync_to_timer = 0; //sync out timer to the official rgb timer.
int rgb_time_out_value = 360;   // 100 = ~9seconds, 666= ~ 54s

bool use_bunnyhop = false;
bool enable_bunnyhop = false;
int bunny_hop_delay_counter = 0;

int modifiers_blink_count = 0; // this is for stuff like enable_bunnyhop and the leader key
bool leader_key_is_running = false;

int brightness_amount = 0;
int hue_amount = 0;

bool main_layer_brightness = true; // can disable the main layer rgb individually

bool combos_on = true; // use combo feature by default
bool mac_mode = false;

int word_length_count = 0;
int last_word_length=0;

//do not change the following
bool use_default_lighting = true; // do not change used inside loop
bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

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
    KC_GRAVE,           KC_1,           KC_2,               KC_3,           KC_4,           KC_5,           KC_MINUS,                                       KC_PLUS,        KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           LSFT(KC_ENTER),
    KC_TAB,             KC_Q,           KC_W,               KC_E,           KC_R,           KC_T,           LCTL(LSFT(KC_LGUI)),                            KC_F2,          KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           ST_MACRO_SSH,
    LCTL(KC_LALT),      KC_A,           KC_S,               KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_RALT,
    KC_LSHIFT,          KC_Z,           KC_X,               KC_C,           KC_V,           KC_B,           KC_HYPR,                                        KC_F4,          KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RCTRL,
    KC_LCTRL,           KC_LALT,        LCTL(LSFT(KC_LGUI)),LCTL(KC_LGUI),  LSFT(KC_LGUI),                                                                                                  KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_LEAD,



                                                                                                    LSFT(KC_PSCREEN),KC_PSCREEN,                            DYN_MACRO_PLAY1,DYN_MACRO_PLAY2,
                                                                                                                        KC_HOME,                            ST_MACRO_VIM_wq,
                                                        LT(Layer_symbols,KC_BSPACE),LGUI_T(KC_DELETE),           LCTL(KC_SPACE),                            LSFT_T(KC_ESCAPE),              LT(Layer_macros,KC_ENTER), KC_SPACE
  ),

  [Layer_mac_main] = LAYOUT_ergodox_pretty(
    KC_GRAVE,           KC_1,           KC_2,               KC_3,           KC_4,           KC_5,           KC_MINUS,                                       KC_PLUS,        KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           LSFT(KC_ENTER),
    KC_TAB,             KC_Q,           KC_W,               KC_E,           KC_R,           KC_T,           LCTL(LSFT(KC_LGUI)),                            KC_F2,          KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           ST_MACRO_SSH,
    LCTL(KC_LALT),      KC_A,           KC_S,               KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_RALT,
    KC_LSHIFT,          KC_Z,           KC_X,               KC_C,           KC_V,           KC_B,           KC_HYPR,                                        KC_F4,          KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RCTRL,
    KC_LGUI,            KC_LALT,        LCTL(LSFT(KC_LGUI)),LCTL(KC_LGUI),  LSFT(KC_LGUI),                                                                                                  KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_LEAD,



                                                                                                    LSFT(KC_PSCREEN),LCTL(LGUI(LSFT(KC_4))),                DYN_MACRO_PLAY1,DYN_MACRO_PLAY2,
                                                                                                                        KC_HOME,                            ST_MACRO_VIM_wq,
                                                    LT(Layer_mac_symbols,KC_BSPACE),LCTL_T(KC_DELETE),           LCTL(KC_SPACE),                            LSFT_T(KC_ESCAPE),              LT(Layer_macros,KC_ENTER), KC_SPACE
  ),




  [Layer_symbols] = LAYOUT_ergodox_pretty(
    LSFT(KC_GRAVE),     KC_F1,          KC_F2,              KC_F3,                  KC_F4,              KC_F5,              KC_F11,                          KC_F12,        KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F13,
    _______,            KC_GRAVE,       KC_QUOTE,           LSFT(KC_QUOTE),         LSFT(LCTL(KC_C)),   LSFT(LCTL(KC_V)),   KC_CIRC,                        _______,        KC_LABK,        KC_PLUS,        KC_MINUS,       KC_RABK,        KC_EQUAL,       _______,
    _______,            KC_EXLM,        LSFT(KC_2),         LSFT(KC_3),             KC_DLR,             KC_PERC,                                                            KC_ASTR,        KC_LBRACKET,    KC_RBRACKET,    KC_UNDS,        KC_QUES,        _______,
    KC_LSHIFT,          ST_M_n_equal,   KC_AMPR,            LSFT(KC_NONUS_BSLASH),  LSFT(KC_NONUS_HASH),KC_ASTR,            KC_CIRC,                        _______,        KC_AMPR,        KC_LCBR,        KC_RCBR,        KC_DOT,         KC_NONUS_BSLASH,KC_LSHIFT,
    LALT(KC_LCTRL),     ST_M_n_equal_2, LCTL(KC_X),         LCTL(KC_C),             LCTL(KC_V),                                                                                             LSFT(KC_9),     LSFT(KC_0),     ST_M_l_equal,   ST_M_g_equal,   KC_LALT,


                                                                                                                    _______,_______,                        _______, _______,
                                                                                                                            _______,                        _______,
                                                                                        _______, _______,                   _______,                        LSFT(KC_SCOLON),                KC_NONUS_HASH,  KC_SCOLON
  ),

  [Layer_mac_symbols] = LAYOUT_ergodox_pretty(
    LSFT(KC_GRAVE),     KC_F1,          KC_F2,              KC_F3,                  KC_F4,              KC_F5,              KC_F11,                          KC_F12,        KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F13,
    _______,            KC_GRAVE,       KC_QUOTE,           LSFT(KC_2),             LGUI(LCTL(KC_C)),   LGUI(LCTL(KC_V)),   KC_CIRC,                        _______,        KC_LABK,        KC_PLUS,        KC_MINUS,       KC_RABK,        KC_EQUAL,       _______,
    _______,            KC_EXLM,        LSFT(KC_QUOTE),     LSFT(KC_3),             KC_DLR,             KC_PERC,                                                            KC_ASTR,        KC_LBRACKET,    KC_RBRACKET,    KC_UNDS,        KC_QUES,        _______,
    KC_LSHIFT,          ST_M_n_equal,   KC_AMPR,            LSFT(KC_NONUS_HASH),    LSFT(KC_GRAVE),     KC_ASTR,            KC_CIRC,                        _______,        KC_AMPR,        KC_LCBR,        KC_RCBR,        KC_DOT,         KC_NONUS_HASH,  KC_LSHIFT,
    LALT(KC_LCTRL),     ST_M_n_equal_2, LGUI(KC_X),         LGUI(KC_C),             LGUI(KC_V),                                                                                             LSFT(KC_9),     LSFT(KC_0),     ST_M_l_equal,   ST_M_g_equal,   KC_LALT,


                                                                                                                    _______,_______,                        _______, _______,
                                                                                                                            _______,                        _______,
                                                                                        _______, _______,                   _______,                        LSFT(KC_SCOLON),                LALT(KC_3),     KC_SCOLON
  ),



  [Layer_macros] = LAYOUT_ergodox_pretty(
    ST_M_led_timeout_30s,   _______,        _______,            DYN_REC_START1, DYN_REC_START2,   DYN_REC_STOP,   _______,                                    _______,        _______,        ST_M_brightness_down,           ST_M_brightness_up,     _______,                    _______,         RESET,
    ST_M_led_timeout_1m,    ST_M_vim_q,     ST_M_vim_w,         _______,            LCTL(KC_V),    LCTL(KC_B),    _______,                                    _______,        _______,        ST_M_hue_down,                  ST_M_hue_up,            _______,                    _______,         ST_M_enable_bunny_hop,
    ST_M_led_timeout_5m,    _______,        _______,            _______,            ST_M_vim_sp,    ST_M_vim_vs,                                                              LCTL(KC_H),     LCTL(KC_J),                     LCTL(KC_K),             LCTL(KC_L),                 _______,         ST_M_toggle_main_layer_brightness,
    ST_M_led_timeout_10m,   _______,        _______,            ST_M_combo_toggle,ST_M_vim_sp_e,  ST_M_vim_vs_e,  _______,                                    _______,        _______,        ST_M_mac_mode_toggle,           _______,                _______,                    _______,         _______,
    _______,                _______,        _______,            _______,        _______,                                                                                                      _______,                        _______,                _______,                    _______,         _______,


                                                                                                                _______,    _______,                        _______,        _______,
                                                                                                                            _______,                        _______,
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


void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

void suspend_power_down_user(void) {
    g_suspend_state = true;
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_user(void) {
    g_suspend_state = false;
    rgb_matrix_set_suspend_state(false);
}

//colours                   hsv             // rgb
#define KM_Light_red        {0,223,252}     // 252,32,31
#define KM_Light_yellow     {31,208,234}    // 234,181,42
#define KM_dirty_green      {97,231,230}    // 21,230,76
#define LM_golden_yellow    {32,191,236}    // 236,191,59
#define LM_Slight_dark_red  {255,246,238}   //238,8,23
#define LM_Blue             {166,240,228}   //13,41,228
#define LM_LightOrange      {0,183,238}     //238,67,66
#define LM_Cyan             {130,255,255}   //0,249,255
#define LM_Yellow           {42,248,240}    //240,237,6
#define LM_______           {0,0,0}         //no colour
#define LM_Light_pink       {216,123,238}   // 238,122,235
#define LM_White            {0,0,255}       // 255,255,255
#define LM_Red_Blood        {6,240,224}     // 224,43,13
#define LM_NeonGreen        {82,247,246}    // 28,246,7
#define LM_LighterBlue      {178,231,238}   // 53,22,238
#define LM_darker_Yellow    {36,230,248}    // 248,213,24
#define LM_Light_orange     {31,255,255}    // 255,186,0
#define LM_Blooder_Red      {0,242,205}     // 205,11,10
#define LM_LightBrown       {19,150,185}    // 185,125,75
#define LM_Orange           {13,237,253}    // 253,90,17
#define LM_skyBlue          {124,62,253}    // 190,253,246
#define LM_Toirquise        {115,255,248}   // 0,248,169
#define LM_Purple           {195,255,251}   // 136,0,251
#define LM_Light_blue_purple {178,183,238}   // 92,66,238


#define KM_TEST {214,253,245} //pink



const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    //             8                      9                         0                       -                       =
    [Layer_main_colour] =
            { LM_Light_orange,      KM_Light_red,           KM_dirty_green,         KM_dirty_green,         KM_dirty_green,    \
    //             y                      u                         i                       o                       p
            KM_Light_yellow,        LM_Light_orange,        KM_Light_red,           KM_dirty_green,         KM_dirty_green,     \
    //             h                      j                         k                       l                       ;
            KM_dirty_green,         KM_Light_yellow,        LM_Light_orange,        KM_Light_red,           KM_dirty_green,    \
    //             n                      m                         ,                       .                       /
            KM_dirty_green,         KM_dirty_green,         KM_Light_yellow,        LM_Light_orange,        KM_Light_red,    \
    //             <-                     down                      up                      ->
            KM_dirty_green,         KM_dirty_green,         KM_Light_yellow,        LM_Light_orange,                            \


    //             5                      4                         3                       2                       1
            LM_Light_orange,        KM_Light_red,           KM_dirty_green,         KM_dirty_green,         KM_dirty_green,       \
    //             t                      r                         e                       w                       q
            KM_Light_yellow,        LM_Light_orange,        KM_Light_red,           KM_dirty_green,         KM_dirty_green,     \
    //             g                      f                         d                       s                       a
            KM_dirty_green,         KM_Light_yellow,        LM_Light_orange,        KM_Light_red,           KM_dirty_green,     \
    //             b                      v                         c                       x                       z
            KM_dirty_green,         KM_dirty_green,         KM_Light_yellow,        LM_Light_orange,        KM_Light_red,     \
    //                                                             esc                     esc
            KM_dirty_green,         KM_dirty_green,         KM_Light_yellow,        LM_Light_orange },




    [Layer_symbols_colour] =
            { LM_Slight_dark_red,   LM_Slight_dark_red,     LM_Slight_dark_red,     LM_Slight_dark_red,     LM_Slight_dark_red, \

            LM_Blue,                LM_LightOrange,         LM_LightOrange,         LM_Blue,                LM_LightOrange,     \

            LM_Yellow,              LM_Light_pink,          LM_Light_pink,          LM_LightOrange,         LM_LightOrange,     \

            LM_Cyan,                LM_Light_pink,          LM_Light_pink,          LM_Yellow,              LM_Yellow,          \

            LM_Light_pink,          LM_Light_pink,          LM_Yellow,              LM_Yellow,                                  \



            LM_Slight_dark_red,     LM_Slight_dark_red,     LM_Slight_dark_red,     LM_Slight_dark_red,     LM_Slight_dark_red, \

            LM_White,               LM_White,               LM_Red_Blood,           LM_Yellow,              LM_Yellow,          \

            LM_Yellow,              LM_Yellow,              LM_Yellow,              LM_Yellow,              LM_Yellow,          \

            LM_Yellow,              LM_Light_orange,        KM_dirty_green,         LM_Cyan,                LM_Yellow,          \

            LM_White,               LM_White,               LM_White,               LM_Yellow },



    //             8                    9                           0                    -                       =
    [Layer_macros_colour] =
            { LM_______,            LM_Blooder_Red,         LM_NeonGreen,           LM_______,              LM_______,          \
    //             y                    u                           i                    o                       p
            LM_______,              LM_Blooder_Red,         LM_NeonGreen,           LM_______,              LM_______,          \
    //             h                    j                           k                    l                       ;
            KM_Light_yellow,        KM_Light_yellow,        KM_Light_yellow,        KM_Light_yellow,        LM_______,          \
    //             n                    m                           ,                    .                       /
            LM_______,              LM_______,              LM_______,              LM_______,              LM_______,          \
    //             <-                   down                        up                   ->
            LM_______,              LM_______,              LM_______,              LM_______,                                  \


    //             5                    4                           3                    2                       1
            LM_Blooder_Red,         LM_NeonGreen,           LM_NeonGreen,           LM_______,              LM_______,          \
    //             t                    r                           e                    w                       q
            KM_dirty_green,         KM_dirty_green,         LM_______,              LM_Light_blue_purple,   KM_Light_red,       \
    //             g                    f                          d                    s                       a
            KM_dirty_green,         KM_dirty_green,         LM_Light_pink,          LM_Light_pink,          LM_Light_pink,      \
    //             b                    v                           c                    x                       z
            KM_dirty_green,         KM_dirty_green,         LM_______,              LM_______,              LM_Light_pink,      \
    //                                                          esc                  esc
            LM_______,              LM_______,              LM_______,              LM_______ },



    [Layer_gaming_colour] =
            { LM_LightBrown,        LM_LightBrown,          LM_LightBrown,          LM_LightBrown,          LM_LightBrown,      \

            LM_Light_orange,        LM_White,               LM_White,               LM_White,               LM_White,           \

            LM_Orange,              LM_White,               LM_White,               LM_White,               LM_White,           \

            LM_Blooder_Red,         LM_White,               LM_White,               LM_White,               KM_Light_red,       \

            LM_White,               LM_White,               KM_Light_red,           KM_Light_red,                               \



            LM_Orange,              LM_Orange,              LM_Orange,              LM_Orange,              LM_Orange,          \

            LM_NeonGreen,           LM_skyBlue,             KM_Light_red,           LM_Cyan,                LM_Orange,          \

            LM_Yellow,              KM_Light_red,           KM_Light_red,           KM_Light_red,           LM_Orange,          \

            LM_LightBrown,          LM_Toirquise,           LM_Toirquise,           LM_Toirquise,           LM_skyBlue,         \

            LM_Purple,              LM_Purple,              LM_Light_orange,        LM_Purple },




};


//combos don't forget to edit COMBO_COUNT in config.h
enum combo_events {
    COMBO_LEFT_SQUARE_BRACKET,
    COMBO_RIGHT_SQUARE_BRACKET,
    COMBO_LEFT_CURLY_BRACKET,
    COMBO_RIGHT_CURLY_BRACKET,
    COMBO_LEFT_BRACKET,
    COMBO_RIGHT_BRACKET,
    COMBO_MINUS,
    COMBO_EQUALS,
    COMBO_LESS,
    COMBO_GREATER,
    COMBO_LESS_EQUALS,
    COMBO_GREATER_EQUALS,
    COMBO_LESS_EQUALS_EQUALS,
    COMBO_GREATER_EQUALS_EQUALS,
    COMBO_NOT_EQUALS,
    COMBO_NOT_EQUALS_EQUALS,
    COMBO_PIPE,
    COMBO_ASTARISK,
    COMBO_AMPERSTAND,
    COMBO_ROOT,
    COMBO_HASH,
    COMBO_START_WORD,
    COMBO_DELETE_WORD,
    COMBO_ALT_F4,
    COMBO_SCROLL_UP,
    COMBO_SCROLL_DOWN
};

const uint16_t PROGMEM combo_left_square_bracket[] = {KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM combo_right_square_bracket[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM combo_left_curly_bracket[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM combo_right_curly_bracket[] = {KC_L, KC_K, COMBO_END};
const uint16_t PROGMEM combo_left_bracket[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo_right_bracket[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_equals[] = {KC_9, KC_0, COMBO_END};
const uint16_t PROGMEM combo_minus[] = {KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM combo_less[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_greater[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_less_equals[] = {KC_F, KC_U, COMBO_END};
const uint16_t PROGMEM combo_greater_equals[] = {KC_F, KC_O, COMBO_END};
const uint16_t PROGMEM combo_less_equals_equals[] = {KC_F, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_greater_equals_equals[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM combo_not_equals[] = {KC_J, KC_A, COMBO_END};
const uint16_t PROGMEM combo_not_equals_equals[] = {KC_J, KC_S, COMBO_END};
const uint16_t PROGMEM combo_pipe[] = {KC_F, KC_I, COMBO_END};
const uint16_t PROGMEM combo_amperstand[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM combo_astarisk[] = {KC_F, KC_K, COMBO_END};
const uint16_t PROGMEM combo_root[] = {KC_F, KC_SCOLON, COMBO_END};
const uint16_t PROGMEM combo_hash[] = {KC_F, KC_H, COMBO_END};
const uint16_t PROGMEM combo_start_word[] = {KC_F, KC_LEFT, COMBO_END};
const uint16_t PROGMEM combo_delete_word[] = {KC_F, KC_DOWN, COMBO_END};
const uint16_t PROGMEM combo_alt_f4[] = {KC_F, KC_4, COMBO_END};
const uint16_t PROGMEM combo_scroll_up[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combo_scroll_down[] = {KC_E, KC_R, COMBO_END};

/* COMBOS VISUAL LAYOUT
    +-------------+
    | S | F | [   |
    | J | L | ]   |
    | S | D | {   |
    | L | K | }   |
    | D | F | (   |
    | J | K | )   |
    | 9 | 0 | =   |
    | 8 | 9 | -   |
    | U | I | <   |
    | I | O | >   |
    | F | U | <=  |
    | F | O | >=  |
    | F | Y | <== |
    | F | P | >== |
    | J | A | !=  |
    | J | S | !== |
    | F | I | |   |
    | F | J | &   |
    | F | K | *   |
    | F | ; | ~   |
    | F | H | #   |
    | F | 4 | Af4 |
    | F | < | W<< |
    | F | d | Wdd |
    | W | E | Sup |
    | E | R | Sdw |
    +-------------+

*/

combo_t key_combos[COMBO_COUNT] = {
    [COMBO_LEFT_SQUARE_BRACKET] = COMBO_ACTION(combo_left_square_bracket),
    [COMBO_RIGHT_SQUARE_BRACKET] = COMBO_ACTION(combo_right_square_bracket),
    [COMBO_LEFT_CURLY_BRACKET] = COMBO_ACTION(combo_left_curly_bracket),
    [COMBO_RIGHT_CURLY_BRACKET] = COMBO_ACTION(combo_right_curly_bracket),
    [COMBO_LEFT_BRACKET] = COMBO_ACTION(combo_left_bracket),
    [COMBO_RIGHT_BRACKET] = COMBO_ACTION(combo_right_bracket),
    [COMBO_MINUS] = COMBO_ACTION(combo_minus),
    [COMBO_EQUALS] = COMBO_ACTION(combo_equals),
    [COMBO_LESS] = COMBO_ACTION(combo_less),
    [COMBO_GREATER] = COMBO_ACTION(combo_greater),
    [COMBO_LESS_EQUALS] = COMBO_ACTION(combo_less_equals),
    [COMBO_GREATER_EQUALS] = COMBO_ACTION(combo_greater_equals),
    [COMBO_LESS_EQUALS_EQUALS] = COMBO_ACTION(combo_less_equals_equals),
    [COMBO_GREATER_EQUALS_EQUALS] = COMBO_ACTION(combo_greater_equals_equals),
    [COMBO_NOT_EQUALS] = COMBO_ACTION(combo_not_equals),
    [COMBO_NOT_EQUALS_EQUALS] = COMBO_ACTION(combo_not_equals_equals),
    [COMBO_PIPE] = COMBO_ACTION(combo_pipe),
    [COMBO_ASTARISK] = COMBO_ACTION(combo_astarisk),
    [COMBO_AMPERSTAND] = COMBO_ACTION(combo_amperstand),
    [COMBO_ROOT] = COMBO_ACTION(combo_root),
    [COMBO_HASH] = COMBO_ACTION(combo_hash),
    [COMBO_START_WORD] = COMBO_ACTION(combo_start_word),
    [COMBO_DELETE_WORD] = COMBO_ACTION(combo_delete_word),
    [COMBO_ALT_F4] = COMBO_ACTION(combo_alt_f4),
    [COMBO_SCROLL_UP] = COMBO_ACTION(combo_scroll_up),
    [COMBO_SCROLL_DOWN] = COMBO_ACTION(combo_scroll_down)
};

void process_combo_event(uint16_t combo_index, bool pressed) {

        switch(combo_index) {
        case COMBO_LEFT_SQUARE_BRACKET:
            if (pressed) {
                register_code16(KC_LBRACKET);
            }else{
                unregister_code16(KC_LBRACKET);
            }
        break;
        case COMBO_RIGHT_SQUARE_BRACKET:
            if (pressed) {
                register_code16(KC_RBRACKET);
            }else{
                unregister_code16(KC_RBRACKET);
            }
        break;
        case COMBO_LEFT_CURLY_BRACKET:
            if (pressed) {
                register_code16(KC_LCBR);
            }else{
                unregister_code16(KC_LCBR);
            }
        break;
        case COMBO_RIGHT_CURLY_BRACKET:
            if (pressed) {
                register_code16(KC_RCBR);
            }else{
                unregister_code16(KC_RCBR);
            }
        break;
        case COMBO_LEFT_BRACKET:
            if (pressed) {
                register_code16(LSFT(KC_9));
            }else{
                unregister_code16(LSFT(KC_9));
            }
        break;
        case COMBO_RIGHT_BRACKET:
            if (pressed) {
                register_code16(LSFT(KC_0));
            }else{
                unregister_code16(LSFT(KC_0));
            }
        break;
        case COMBO_MINUS:
            if (pressed) {
                register_code16(KC_MINUS);
            }else{
                unregister_code16(KC_MINUS);
            }
        break;
        case COMBO_EQUALS:
            if (pressed) {
                register_code16(KC_EQUAL);
            }else{
                unregister_code16(KC_EQUAL);
            }
        break;
        case COMBO_LESS:
            if (pressed) {
                register_code16(KC_LABK);
            }else{
                unregister_code16(KC_LABK);
            }
        break;
        case COMBO_GREATER:
            if (pressed) {
                register_code16(KC_RABK);
            }else{
                unregister_code16(KC_RABK);
            }
        break;
        case COMBO_LESS_EQUALS:
            if (pressed) {
                tap_code16(KC_LABK);
                tap_code16(KC_EQUAL);
            }
        break;
        case COMBO_GREATER_EQUALS:
            if (pressed) {
                tap_code16(KC_RABK);
                tap_code16(KC_EQUAL);
            }
        break;
        case COMBO_LESS_EQUALS_EQUALS:
            if (pressed) {
                tap_code16(KC_LABK);
                tap_code16(KC_EQUAL);
                tap_code16(KC_EQUAL);
            }
        break;
        case COMBO_GREATER_EQUALS_EQUALS:
            if (pressed) {
                tap_code16(KC_RABK);
                tap_code16(KC_EQUAL);
                tap_code16(KC_EQUAL);
            }
        break;
        case COMBO_NOT_EQUALS:
            if (pressed) {
                tap_code16(KC_EXLM);
                tap_code16(KC_EQUAL);
            }
        break;
        case COMBO_NOT_EQUALS_EQUALS:
            if (pressed) {
                tap_code16(KC_EXLM);
                tap_code16(KC_EQUAL);
                tap_code16(KC_EQUAL);
            }
        break;
        case COMBO_PIPE:
            if (pressed) {
                register_code16(LSFT(KC_NONUS_BSLASH));
            }else{
                unregister_code16(LSFT(KC_NONUS_BSLASH));
            }
        break;
        case COMBO_ASTARISK:
            if (pressed) {
                register_code16(KC_ASTR);
            }else{
                unregister_code16(KC_ASTR);
            }
        break;
        case COMBO_AMPERSTAND:
            if (pressed) {
                register_code16(KC_AMPR);
            }else{
                unregister_code16(KC_AMPR);
            }
        break;
        case COMBO_ROOT:
            if (pressed) {
                register_code16(LSFT(KC_NONUS_HASH));
            }else{
                unregister_code16(LSFT(KC_NONUS_HASH));
            }
        break;
        case COMBO_HASH:
            if (pressed) {
                register_code16(KC_NONUS_HASH);
            }else{
                unregister_code16(KC_NONUS_HASH);
            }
        break;
        case COMBO_SCROLL_UP:
            if (pressed) {
                register_code16(KC_MS_WH_UP);
            }else{
                unregister_code16(KC_MS_WH_UP);
            }
        break;
        case COMBO_SCROLL_DOWN:
            if (pressed) {
                register_code16(KC_MS_WH_DOWN);
            }else{
                unregister_code16(KC_MS_WH_DOWN);
            }
        break;
        case COMBO_START_WORD:
            if (pressed) {
                last_word_length = last_word_length / 2;
                while (last_word_length > 0){
                    tap_code16(KC_LEFT);
                    last_word_length--;
                }
            }
        break;
        case COMBO_DELETE_WORD:
            if (pressed) {
                last_word_length = last_word_length / 2;
                while (last_word_length > 0){
                    tap_code16(KC_BSPACE);
                    last_word_length--;
                }
            }
        break;
        case COMBO_ALT_F4:
            if(pressed){
                tap_code16(LALT(KC_F4));
            }
        }
}



void set_layer_color(int layer) {
    if(modifiers_blink_count > 200){
        modifiers_blink_count = 0;
    }
    modifiers_blink_count++;

    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        use_default_lighting = true;

        if(enable_bunnyhop && i == 4){ //show indicator on = key
            if(modifiers_blink_count < 100){
                rgb_matrix_set_color( i, 237, 28, 28 );
                use_default_lighting = false;
            }
        }

        if(leader_key_is_running && (i == 19 || i == 22 || i == 23)){ //show leader indicator on /,top arrow,right arrow keys
            rgb_matrix_set_color( i, 31, 107, 239 );
            use_default_lighting = false;
        }

        if(combos_on && i == 47){ // show indicator on key bellow z.
            if(modifiers_blink_count < 100){
                rgb_matrix_set_color( i, 237, 28, 28);
                use_default_lighting = false;
            }
        }

        if(mac_mode && i == 16){ // show indicator on key m
            if(modifiers_blink_count < 100){
                rgb_matrix_set_color( i, 237, 28, 28);
                use_default_lighting = false;
            }
        }

        if(use_default_lighting) {
            HSV hsv = {
                .h = pgm_read_byte(&ledmap[layer][i][0]),
                .s = pgm_read_byte(&ledmap[layer][i][1]),
                .v = pgm_read_byte(&ledmap[layer][i][2]),
            };
            if ((!hsv.h && !hsv.s && !hsv.v) || (layer == 0 && !main_layer_brightness)) {
                rgb_matrix_set_color( i, 0, 0, 0 );
            } else {

                if(brightness_amount != 0){
                    int check = hsv.v + brightness_amount;

                    if(check < 250 && check > 10){
                        hsv.v = check;
                    }else{
                        if(brightness_amount<0){
                            brightness_amount+=10;
                        }else{
                            brightness_amount-=10;
                        }
                    }
                }

                if(hue_amount != 0){
                    int check = hsv.h + hue_amount;
                    if(check > 250){
                        check = check - 250;
                    }
                    if(check < 5){
                        check = check + 250;
                    }
                    if(check < 250 && check > 5){
                        hsv.h = check;
                    }
                }

                RGB rgb = hsv_to_rgb( hsv );
                float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
                rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
            }
        }
    }
}

void rgb_matrix_indicators_user(void) {
    if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
    if(rgb_show && !rgb_timed_out){
        switch (biton32(layer_state)) {
            case Layer_main:
                set_layer_color(Layer_main_colour);
            break;
            case Layer_symbols:
                set_layer_color(Layer_symbols_colour);
            break;
            case Layer_macros:
                set_layer_color(Layer_macros_colour);
            break;
            case Layer_gaming:
                set_layer_color(Layer_gaming_colour);
            break;
            case Layer_mac_main:
                set_layer_color(Layer_main_colour);
            break;
            case Layer_mac_symbols:
                set_layer_color(Layer_symbols_colour);
            break;

            default:
                if (rgb_matrix_get_flags() == LED_FLAG_NONE){
                    rgb_matrix_set_color_all(0, 0, 0);
                }
            break;
    }
    }else{
        rgb_matrix_set_color_all(0, 0, 0);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if(keycode >= 4 && keycode <= 39){
        word_length_count++;
        last_word_length = word_length_count;
    }else{
        word_length_count = 0;
    }
    rgb_timed_out = false;
    timeout_counter=0; //reset timeout counter also, so that it will always count from the time the key was pressed.

    switch (keycode) {
        case ST_MACRO_SSH:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_R)) SS_TAP(X_S) SS_TAP(X_S) SS_TAP(X_H));
            }
        break;
        case ST_MACRO_VIM_wq: //save and exit vim
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESCAPE) SS_TAP(X_ESCAPE) SS_LSFT(SS_TAP(X_SCOLON)) SS_TAP(X_W) SS_TAP(X_Q) SS_TAP(X_ENTER));
            }
        break;
        case ST_M_n_equal: // !=
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_1)) SS_TAP(X_EQUAL));
            }
        break;
        case ST_M_n_equal_2: // !==
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_1)) SS_TAP(X_EQUAL) SS_TAP(X_EQUAL));
            }
        break;
        case ST_M_l_equal: // <=
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_COMMA)) SS_TAP(X_EQUAL));
            }
        break;
        case ST_M_g_equal:  // >=
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_DOT)) SS_TAP(X_EQUAL));
            }
        break;
        case ST_M_vim_q: //quite vim without saving
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESCAPE) SS_TAP(X_ESCAPE)  SS_LSFT(SS_TAP(X_SCOLON)) SS_TAP(X_Q) SS_LSFT(SS_TAP(X_1)) SS_TAP(X_ENTER));
            }
        break;
        case ST_M_vim_w: // write only
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESCAPE) SS_TAP(X_ESCAPE)  SS_LSFT(SS_TAP(X_SCOLON)) SS_TAP(X_W) SS_TAP(X_ENTER));
            }
        break;
        case ST_M_vim_sp: // vim :sp without enter
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESCAPE) SS_TAP(X_ESCAPE) SS_LSFT(SS_TAP(X_SCOLON)) SS_TAP(X_S) SS_TAP(X_P));
            }
        break;
        case ST_M_vim_vs:   // vim :vs without enter
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESCAPE) SS_TAP(X_ESCAPE) SS_LSFT(SS_TAP(X_SCOLON)) SS_TAP(X_V) SS_TAP(X_S));
            }
        break;
        case ST_M_vim_sp_e: // vim :sp with enter
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESCAPE) SS_TAP(X_ESCAPE) SS_LSFT(SS_TAP(X_SCOLON)) SS_TAP(X_S) SS_TAP(X_P) SS_TAP(X_ENTER));
            }
        break;
        case ST_M_vim_vs_e: // vim :vs with enter
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESCAPE) SS_TAP(X_ESCAPE) SS_LSFT(SS_TAP(X_SCOLON)) SS_TAP(X_V) SS_TAP(X_S) SS_TAP(X_ENTER));
            }
        break;
        case ST_M_double_colon:
            if (record->event.pressed) {
                SEND_STRING("::");
            }
        break;
        case ST_M_bunny_hop:
            if (record->event.pressed) {
                use_bunnyhop = true;
                if(!enable_bunnyhop){
                    SEND_STRING(SS_DOWN(X_SPACE));
                }
            }else
            {
                use_bunnyhop = false;
                if(!enable_bunnyhop){
                    SEND_STRING(SS_UP(X_SPACE));
                }
            }
        break;
        case ST_M_enable_bunny_hop:
            if (record->event.pressed) {
                enable_bunnyhop = !enable_bunnyhop;
            }
        break;
        case ST_M_brightness_up:
            if (record->event.pressed) {
                brightness_amount+=10;
            }
        break;
        case ST_M_brightness_down:
            if (record->event.pressed) {
                brightness_amount-=10;
            }
        break;
        case ST_M_hue_up:
            if (record->event.pressed) {
                hue_amount+=5;
            }
        break;
        case ST_M_hue_down:
            if (record->event.pressed) {
                hue_amount-=5;
            }
        break;
        case ST_M_toggle_main_layer_brightness:
            if (record->event.pressed) {
                main_layer_brightness = !main_layer_brightness;
            }
        break;
        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
        break;
        case ST_M_led_timeout_30s:
            if (record->event.pressed) {
                rgb_time_out_value = 360;
            }
        break;
        case ST_M_led_timeout_1m:
            if (record->event.pressed) {
                rgb_time_out_value = 720;
            }
        break;
        case ST_M_led_timeout_5m:
            if (record->event.pressed) {
                rgb_time_out_value = 3600;
            }
        break;
        case ST_M_led_timeout_10m:
            if (record->event.pressed) {
                rgb_time_out_value = 7200;
            }
        break;
        case ST_M_mac_mode_toggle:
            if (record->event.pressed) {
                mac_mode = !mac_mode;
                if(mac_mode){
                    layer_move(Layer_mac_main);
                }else{
                    layer_move(Layer_main);
                }
            }
        break;
        case ST_M_combo_toggle:
            if (record->event.pressed) {
                combo_toggle();
                combos_on = is_combo_enabled();
            }
        break;
        return false;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {
    // if(state == Layer_main){ // game layer always returns to Layer_main so need to update mac_mode accordingly. however updating it causes an issue where you can't go back to mac mode
    //     mac_mode = false;
    // }else if(state == Layer_mac_main){
    //     mac_mode = true;
    // }
    return state;
};

LEADER_EXTERNS();
int did_leader_succeed;

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    did_leader_succeed = leading = false;

    SEQ_ONE_KEY(KC_T) {
      // Anything you can do in a macro.
      SEND_STRING(SS_DOWN(X_LGUI)  SS_TAP(X_ENTER) SS_UP(X_LGUI)  SS_DELAY(1000) "timer ");
      did_leader_succeed = true;
    } else
    SEQ_TWO_KEYS(KC_B, KC_I) {
      SEND_STRING("https://www.bing.com/images/search?q=");
      did_leader_succeed = true;
    } else
    SEQ_TWO_KEYS(KC_T, KC_O) {
      SEND_STRING("10.0.0.69:19009" SS_TAP(X_ENTER) SS_DELAY(700) "pirate" SS_TAP(X_TAB));
      did_leader_succeed = true;
    } else
    SEQ_ONE_KEY(KC_C) {
      SEND_STRING("code ." SS_TAP(X_ENTER));
      did_leader_succeed = true;
    } else
    SEQ_ONE_KEY(KC_RIGHT) { //wake leds
        rgb_timed_out = false;
        did_leader_succeed = true;
    } else
    SEQ_TWO_KEYS(KC_RIGHT, KC_RIGHT) { //toggle leds on/off
        rgb_show = !rgb_show;
        did_leader_succeed = true;
    } else
    SEQ_THREE_KEYS(KC_RIGHT, KC_RIGHT, KC_RIGHT){ //turn on leds and wake and reset brightness
        rgb_timed_out = false;
        rgb_show = true;
        brightness_amount = 0;
        hue_amount = 0;
        main_layer_brightness = true;
        did_leader_succeed = true;
    } else
    SEQ_ONE_KEY(KC_E) {
      SEND_STRING(SS_LSFT("'") "t80search_bot -t");
      did_leader_succeed = true;
    } else
    SEQ_TWO_KEYS(KC_G, KC_G) {
      mac_mode = false; // gaming layer currently always returns to Layer_main. shouldn't be a problem since I wouldn't be launching it from mac mode ever.
      layer_move(Layer_gaming);
      did_leader_succeed = true;
    } else
    SEQ_TWO_KEYS(KC_C, KC_O) {
      SEND_STRING("cd /media/veracrypt1/GIT/qmk_firmware && make clean && make ergodox_ez:artiom_no_mouse_joined_with_mac");
      did_leader_succeed = true;
    }
    leader_end();
  }

  if(rgb_sync_to_timer != g_rgb_timer){
        rgb_sync_to_timer = g_rgb_timer;
        if(!rgb_timed_out){ // update rgb timeout
            if(timeout_counter > rgb_time_out_value){
                timeout_counter = 0;
                rgb_timed_out = true;
            }
            timeout_counter++;
        }
  }

  if(enable_bunnyhop && use_bunnyhop){
       if(bunny_hop_delay_counter <= 0){
        srand(timeout_counter);
        SEND_STRING(SS_TAP(X_SPACE));
        bunny_hop_delay_counter = rand() % 10;
       }
       bunny_hop_delay_counter --;
  }

}

void leader_start(void) {
    leader_key_is_running = true;
}

void leader_end(void) {
    leader_key_is_running = false;
}
