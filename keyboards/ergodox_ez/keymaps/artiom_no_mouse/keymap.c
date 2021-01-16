#include QMK_KEYBOARD_H
#include "version.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL


//defines to make the keys shorter
#define ______      KC_TRANSPARENT
#define C_S_Linux   LCTL(LSFT(KC_LGUI))
#define T_copy      LSFT(KC_PC_COPY)
#define T_paste     LSFT(KC_PC_PASTE)
#define M_pipe      LSFT(KC_NONUS_BSLASH)
#define M_root      LSFT(KC_NONUS_HASH)




// layer defines
#define Layer_main 0
#define Layer_symbols 1
#define Layer_macros 2
#define Layer_gaming 3



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
  ST_M_round_b,
  ST_M_angle_b,
  ST_M_square_b,
  ST_M_vim_sp,
  ST_M_vim_vs,
  ST_M_all_b,
  ST_M_vim_sp_e,
  ST_M_vim_vs_e,
  ST_M_double_left_angle,
  ST_M_double_right_angle,
  ST_M_double_colon,
  ST_M_bunny_hop,
  ST_M_enable_bunny_hop,
  ST_M_brightness_down,
  ST_M_brightness_up,
};

int rgb_show = 1;
int rgb_timed_out = 0;
int use_bunnyhop = 0;
int enable_bunnyhop = 0;

int modifiers_blink_count = 0; // this is for stuff like enable_bunnyhop and the leader key
int leader_key_is_running = 0;

int brightness_amount = 0;

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
    KC_ESCAPE,          KC_1,           KC_2,               KC_3,           KC_4,           KC_5,           KC_6,                                           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       KC_EQUAL,       TT(3),
    KC_TAB,             KC_Q,           KC_W,               KC_E,           KC_R,           KC_T,           C_S_Linux,                                      KC_F2,          KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           ST_MACRO_SSH,
    KC_TAB,             KC_A,           KC_S,               KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_RALT,
    KC_LSHIFT,          KC_Z,           KC_X,               KC_C,           KC_V,           KC_B,           KC_HYPR,                                        KC_F4,          KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RCTRL,
    KC_LCTRL,           KC_LALT,        C_S_Linux,          LCTL(KC_LGUI),  LSFT(KC_LGUI),                                                                                                  KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_LEAD,



                                                                                                    LSFT(KC_PSCREEN),KC_PSCREEN,                            DYN_MACRO_PLAY1,DYN_MACRO_PLAY2,
                                                                                                                        KC_HOME,                            ST_MACRO_VIM_wq,
                                                                    LT(1,KC_BSPACE),LGUI_T(KC_DELETE),           LCTL(KC_SPACE),                            LSFT_T(KC_ESCAPE),              LT(2,KC_ENTER), KC_SPACE
  ),


  [Layer_symbols] = LAYOUT_ergodox_pretty(
    LSFT(KC_GRAVE),     KC_F1,          KC_F2,              KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_F13,
    ______,             KC_GRAVE,       KC_QUOTE,           LSFT(KC_QUOTE), T_copy,         T_paste,        KC_CIRC,                                        ______,         KC_LABK,        KC_PLUS,        KC_MINUS,       KC_RABK,        KC_EQUAL,       ______,
    ______,             KC_EXLM,        LSFT(KC_2),         LSFT(KC_3),     KC_DLR,         KC_PERC,                                                                        KC_ASTR,        KC_LBRACKET,    KC_RBRACKET,    KC_UNDS,        KC_QUES,        ______,
    KC_LSHIFT,          ST_M_n_equal,   KC_AMPR,            M_pipe,         M_root,         KC_ASTR,        KC_CIRC,                                        ______,         KC_AMPR,        KC_LCBR,        KC_RCBR,        KC_DOT,         KC_NONUS_BSLASH,KC_LSHIFT,
    LALT(KC_LCTRL),     ST_M_n_equal_2, KC_PC_CUT,          KC_PC_COPY,     KC_PC_PASTE,                                                                                                    LSFT(KC_9),     LSFT(KC_0),     ST_M_l_equal,   ST_M_g_equal,   KC_LALT,


                                                                                                                    ______, ______,                         ______, ______,
                                                                                                                            ______,                         ______,
                                                                                        ______, ______,                     ______,                         LSFT(KC_SCOLON),                KC_NONUS_HASH,  KC_SCOLON
  ),


  [Layer_macros] = LAYOUT_ergodox_pretty(
    ______,             ______,         ______,             DYN_REC_START1, DYN_REC_START2, DYN_REC_STOP,   ______,                                         ______,         ______,         ST_M_brightness_down,         ST_M_brightness_up,         ______,         ______,         RESET,
    ______,             ST_M_vim_q,     ST_M_vim_w,         ______,         LCTL(KC_V),     LCTL(KC_B),     ______,                                         ______,         ______,         ______,         ______,         ______,         ______,         ST_M_enable_bunny_hop,
    ______,             ST_M_round_b,   ST_M_angle_b,       ST_M_square_b,  ST_M_vim_sp,    ST_M_vim_vs,                                                                    LCTL(KC_H),     LCTL(KC_J),     LCTL(KC_K),     LCTL(KC_L),     ______,         ______,
    ______,             ST_M_all_b,     ______,             ______,         ST_M_vim_sp_e,  ST_M_vim_vs_e,  ______,                                         ______,         ______,         ______,         ST_M_double_left_angle,         ST_M_double_right_angle,         ______,         ______,
    ______,             ______,         ______,             ______,         ______,                                                                                                         ______,         ______,         ______,         ______,         ______,


                                                                                                                    ______, ______,                         ______, ______,
                                                                                                                            ______,                         ______,
                                                                        KC_SPACE,       LALT(KC_ENTER),                     ______,                         ST_M_double_colon,              ______, ______
  ),


  [Layer_gaming] = LAYOUT_ergodox_pretty(
    KC_0,               KC_1,           KC_2,               KC_3,           KC_4,           KC_5,           KC_6,                                           KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_HOME,
    KC_ESCAPE,          KC_8,           KC_Q,               KC_W,           KC_E,           KC_R,           KC_7,                                           KC_F6,          KC_KP_ASTERISK, KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_MINUS,    KC_END,
    KC_TAB,             KC_9,           KC_A,               KC_S,           KC_D,           KC_F,                                                                           KC_KP_SLASH,    KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_PLUS,     KC_DELETE,
    KC_LSHIFT,          KC_LSHIFT,      KC_X,               KC_C,           KC_V,           KC_G,           KC_ENTER,                                       KC_F5,          KC_KP_ENTER,    KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_UP,          TO(0),
    KC_LCTRL,           KC_Z,           KC_I,               KC_C,           KC_B,                                                                                                           KC_KP_0,        KC_KP_DOT,      KC_LEFT,        KC_DOWN,        KC_RIGHT,
                                                                                                                        KC_Y, KC_U,                         KC_F3, KC_F4,
                                                                                                                              KC_O,                         KC_F2,
                                                                  ST_M_bunny_hop,       KC_LCTRL,                             KC_M,                         KC_F1,          KC_NUMLOCK,     KC_INSERT
  ),


};


extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
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
    [Layer_main] =
            { KM_Light_red,         KM_Light_red,           KM_Light_red,           KM_Light_yellow,        KM_Light_yellow,    \
    //             y                      u                         i                       o                       p
            KM_dirty_green,         KM_dirty_green,         KM_dirty_green,         KM_dirty_green,         KM_dirty_green,     \
    //             h                      j                         k                       l                       ;
            LM_golden_yellow,       LM_golden_yellow,       LM_golden_yellow,       LM_golden_yellow,       KM_Light_yellow,    \
    //             n                      m                         ,                       .                       /
            KM_dirty_green,         KM_dirty_green,         KM_Light_yellow,        KM_Light_yellow,        KM_Light_yellow,    \
    //             <-                     down                      up                      ->
            KM_Light_yellow,        KM_Light_yellow,        KM_Light_yellow,        KM_Light_yellow,                            \


    //             5                      4                         3                       2                       1
            KM_Light_red,           KM_Light_red,           KM_Light_red,           KM_Light_red,           KM_Light_red,       \
    //             t                      r                         e                       w                       q
            KM_dirty_green,         KM_dirty_green,         KM_dirty_green,         KM_dirty_green,         KM_dirty_green,     \
    //             g                      f                         d                       s                       a
            KM_dirty_green,         KM_dirty_green,         KM_dirty_green,         KM_dirty_green,         KM_dirty_green,     \
    //             b                      v                         c                       x                       z
            KM_dirty_green,         KM_dirty_green,         KM_dirty_green,         KM_dirty_green,         KM_dirty_green,     \
    //                                                             esc                     esc
            KM_Light_yellow,        KM_Light_yellow,        KM_Light_yellow,        KM_Light_yellow },




    [Layer_symbols] =
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
    [Layer_macros] =
            { LM_______,            LM_Blooder_Red,         LM_NeonGreen,           LM_______,              LM_______,          \
    //             y                    u                           i                    o                       p
            LM_______,              LM_______,              LM_______,              LM_______,              LM_______,          \
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



    [Layer_gaming] =
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


void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    if(enable_bunnyhop && i == 4){ //show indicator on = key
      if(modifiers_blink_count < 50){
        rgb_matrix_set_color( i, 250, 0, 0 );
      }else if(modifiers_blink_count > 100){
        modifiers_blink_count = 0;
      }
      modifiers_blink_count++;
    }else if(leader_key_is_running && (i == 19 || i == 22 || i == 23)){ //show leader indicator on /,top arrow,right arrow keys
      rgb_matrix_set_color( i, 0, 0, 250 );
    }else{
      HSV hsv = {
        .h = pgm_read_byte(&ledmap[layer][i][0]),
        .s = pgm_read_byte(&ledmap[layer][i][1]),
        .v = pgm_read_byte(&ledmap[layer][i][2]),
      };
      if (!hsv.h && !hsv.s && !hsv.v) {
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
        set_layer_color(Layer_main);
        break;
        case Layer_symbols:
        set_layer_color(Layer_symbols);
        break;
        case Layer_macros:
        set_layer_color(Layer_macros);
        break;
        case Layer_gaming:
        set_layer_color(Layer_gaming);
        break;
    default:
        if (rgb_matrix_get_flags() == LED_FLAG_NONE)
        rgb_matrix_set_color_all(0, 0, 0);
        break;
  }
  }else{
      rgb_matrix_set_color_all(0, 0, 0);
  }

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_SSH:
    if (record->event.pressed) {
      //SEND_STRING(SS_LCTL(SS_TAP(X_R)) SS_DELAY(100) SS_TAP(X_S) SS_DELAY(100) SS_TAP(X_S) SS_DELAY(100) SS_TAP(X_H));
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
    case ST_M_round_b: // ()
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_9)) SS_LSFT(SS_TAP(X_0)));

    }
    break;
    case ST_M_angle_b: // {}
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_LBRACKET)) SS_LSFT(SS_TAP(X_RBRACKET)));

    }
    break;
    case ST_M_square_b: // []
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_LBRACKET) SS_TAP(X_RBRACKET));

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
    case ST_M_all_b: // (){}
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_9)) SS_LSFT(SS_TAP(X_0)) SS_LSFT(SS_TAP(X_LBRACKET)) SS_LSFT(SS_TAP(X_RBRACKET)));

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
    case ST_M_double_left_angle:
    if (record->event.pressed) {
      SEND_STRING("<<");
    }
    break;
    case ST_M_double_right_angle:
    if (record->event.pressed) {
      SEND_STRING(">>");
    }
    break;
    case ST_M_double_colon:
    if (record->event.pressed) {
      SEND_STRING("::");
    }
    break;
    case ST_M_bunny_hop:
    if (record->event.pressed) {
        use_bunnyhop = 1;
        if(!enable_bunnyhop){
            SEND_STRING(SS_DOWN(X_SPACE));
        }
    }else
    {
        use_bunnyhop = 0;
        if(!enable_bunnyhop){
            SEND_STRING(SS_UP(X_SPACE));
        }
    }
    break;
    case ST_M_enable_bunny_hop:
    if (record->event.pressed) {
      enable_bunnyhop = !enable_bunnyhop;
      //enable_bunnyhop ? ergodox_right_led_1_on() : ergodox_right_led_1_off();
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
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

//   uint8_t layer = biton32(state);

//   ergodox_board_led_off();
//   ergodox_right_led_1_off();
//   ergodox_right_led_2_off();
//   ergodox_right_led_3_off();
//   switch (layer) {
//     case 1:
//       ergodox_right_led_1_on();
//       break;
//     case 2:
//       ergodox_right_led_2_on();
//       break;
//     case 3:
//       ergodox_right_led_3_on();
//       break;
//     case 4:
//       ergodox_right_led_1_on();
//       ergodox_right_led_2_on();
//       break;
//     case 5:
//       ergodox_right_led_1_on();
//       ergodox_right_led_3_on();
//       break;
//     case 6:
//       ergodox_right_led_2_on();
//       ergodox_right_led_3_on();
//       break;
//     case 7:
//       ergodox_right_led_1_on();
//       ergodox_right_led_2_on();
//       ergodox_right_led_3_on();
//       break;
//     default:
//       break;
//   }
  return state;
};
int timeout_counter = 0;
int bunny_hop_delay_counter = 0;
LEADER_EXTERNS();
int did_leader_succeed;
void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    did_leader_succeed = leading = false;

    SEQ_ONE_KEY(KC_T) {
      // Anything you can do in a macro.
      SEND_STRING(SS_DOWN(X_LGUI)  SS_TAP(X_ENTER) SS_UP(X_LGUI)  SS_DELAY(500) "timer ");
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
    SEQ_ONE_KEY(KC_H) {
      SEND_STRING("hahahahahahahahahahaha" );
      did_leader_succeed = true;
    } else
    SEQ_ONE_KEY(KC_C) {
      SEND_STRING("code ." SS_TAP(X_ENTER));
      did_leader_succeed = true;
    } else
    SEQ_ONE_KEY(KC_RIGHT) { //wake leds
        rgb_timed_out = 0;
        did_leader_succeed = true;
    } else
    SEQ_TWO_KEYS(KC_RIGHT, KC_RIGHT) { //toggle leds on/off
        rgb_show = !rgb_show;
      did_leader_succeed = true;
    } else
    SEQ_THREE_KEYS(KC_RIGHT, KC_RIGHT, KC_RIGHT){ //turn on leds and wake and reset brightness
        rgb_timed_out = 0;
        rgb_show = 1;
        brightness_amount = 0;
        did_leader_succeed = true;
    } else
    SEQ_ONE_KEY(KC_E) {
      SEND_STRING(SS_LSFT("'") "t80search_bot ");
      did_leader_succeed = true;
    }
    leader_end();
  }

  if(timeout_counter > 40000){
      timeout_counter = 0;
      rgb_timed_out = 1;
  }
  timeout_counter++;

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
    //ergodox_right_led_3_on();
    leader_key_is_running = 1;
}

void leader_end(void) {
  //ergodox_right_led_1_off();
  //ergodox_right_led_2_off();
  //ergodox_right_led_3_off();
  leader_key_is_running = 0;
}
