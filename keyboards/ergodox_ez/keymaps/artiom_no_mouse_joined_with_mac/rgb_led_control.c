#include "sharedDefines.h"

int8_t brightness_amount = -70;
uint8_t hue_amount = 0;

bool main_layer_brightness = true; // can disable the main layer rgb individually

bool rgb_show = true;
bool rgb_timed_out = true; // set to true so that you will need to type in the password straight away
//uint16_t rgb_sync_to_timer = 0; //sync out timer to the official rgb timer.
uint32_t rgb_time_out_value = 300000; // in milliseconds // 5 minutes by default

uint8_t modifiers_blink_count = 0; // this is for stuff like enable_bunnyhop and the leader key

bool use_default_lighting = true; // do not change used inside loop
bool g_suspend_state;

extern rgb_config_t rgb_matrix_config;

bool caps_lock_on = false;
bool num_lock_on = false;

const uint16_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][4] = {

#ifndef COLORPROGKEYBOARD

    //             8                      9                         0                       -                       =
    [Layer_main_colour] =
            { L_LM_Light_orange,      L_KM_Light_red,           L_KM_dirty_green,         L_KM_dirty_green,         L_KM_dirty_green,    \
    //             y                      u                         i                       o                       p
            L_KM_Light_yellow,        L_LM_Light_orange,        L_KM_Light_red,           L_KM_dirty_green,         L_KM_dirty_green,     \
    //             h                      j                         k                       l                       ;
            L_KM_dirty_green,         L_KM_Light_yellow,        L_LM_Light_orange,        L_KM_Light_red,           L_KM_dirty_green,    \
    //             n                      m                         ,                       .                       /
            L_KM_dirty_green,         L_KM_dirty_green,         L_KM_Light_yellow,        L_LM_Light_orange,        L_KM_Light_red,    \
    //             <-                     down                      up                      ->
            L_KM_dirty_green,         L_KM_dirty_green,         L_KM_Light_yellow,        L_LM_Light_orange,                            \


    //             5                      4                         3                       2                       1
            R_LM_Light_orange,        R_KM_Light_red,           R_KM_dirty_green,         R_KM_dirty_green,         R_KM_dirty_green,       \
    //             t                      r                         e                       w                       q
            R_KM_Light_yellow,        R_LM_Light_orange,        R_KM_Light_red,           R_KM_dirty_green,         R_KM_dirty_green,     \
    //             g                      f                         d                       s                       a
            R_KM_dirty_green,         R_KM_Light_yellow,        R_LM_Light_orange,        R_KM_Light_red,           R_KM_dirty_green,     \
    //             b                      v                         c                       x                       z
            R_KM_dirty_green,         R_KM_dirty_green,         R_KM_Light_yellow,        R_LM_Light_orange,        R_KM_Light_red,     \
    //                                                             esc                     esc
            R_KM_dirty_green,         R_KM_dirty_green,         R_KM_Light_yellow,        R_LM_Light_orange },

#else
    // PROG KEYBOARD LEDS
    //             6                      7                         8                       9                       0
    [Layer_main_colour] =
            { L_LM_skyBlue,           L_LM_Blue,             L_LM_Light_orange,        L_KM_dirty_green,         L_LM_Light_blue_purple,    \
    //             y                      u                         i                       o                       p
            L_LM_skyBlue,             L_LM_Blue,             L_LM_Light_orange,        L_KM_dirty_green,         L_LM_Light_blue_purple,     \
    //             h                      j                         k                       l                       ;
            L_LM_skyBlue,             L_LM_Blue,             L_LM_Light_orange,        L_KM_dirty_green,         L_LM_Light_blue_purple,    \
    //             n                      m                         ,                       .                       /
            L_LM_skyBlue,             L_LM_Blue,             L_LM_Light_orange,        L_KM_dirty_green,         L_LM_Light_blue_purple,    \
    //                                   <-                     down                      up                      ->
                                    L_LM_Blue,             L_LM_Light_orange,        L_KM_dirty_green,         L_LM_Light_blue_purple,                            \


    //             5                      4                         3                       2                       1
            L_LM_skyBlue,             L_LM_Blue,             L_LM_Light_orange,        L_KM_dirty_green,         L_LM_Light_blue_purple,       \
    //             t                      r                         e                       w                       q
            L_LM_skyBlue,             L_LM_Blue,             L_LM_Light_orange,        L_KM_dirty_green,         L_LM_Light_blue_purple,     \
    //             g                      f                         d                       s                       a
            L_LM_skyBlue,             L_LM_Blue,             L_LM_Light_orange,        L_KM_dirty_green,         L_LM_Light_blue_purple,     \
    //             b                      v                         c                       x                       z
            L_LM_skyBlue,             L_LM_Blue,             L_LM_Light_orange,        L_KM_dirty_green,         L_LM_Light_blue_purple,     \
    //                                                                                esc                     esc
                                    L_LM_Blue,             L_LM_Light_orange,        L_KM_dirty_green,         L_LM_Light_blue_purple },

#endif


    [Layer_symbols_colour] =
            { L_LM_Slight_dark_red,   L_LM_Slight_dark_red,     L_LM_Slight_dark_red,     L_LM_Slight_dark_red,     L_LM_Slight_dark_red, \

            L_LM_Blue,                L_LM_LightOrange,         L_LM_LightOrange,         L_LM_Blue,                L_LM_LightOrange,     \

            L_LM_Yellow,              L_LM_Light_pink,          L_LM_Light_pink,          L_LM_LightOrange,         L_LM_LightOrange,     \

            L_LM_Cyan,                L_LM_Light_pink,          L_LM_Light_pink,          L_LM_Yellow,              L_LM_Yellow,          \

            L_LM_Light_pink,          L_LM_Light_pink,          L_LM_Yellow,              L_LM_Yellow,                                  \



            R_LM_Slight_dark_red,     R_LM_Slight_dark_red,     R_LM_Slight_dark_red,     R_LM_Slight_dark_red,     R_LM_Slight_dark_red, \

            R_LM_White,               R_LM_White,               R_LM_Red_Blood,           R_LM_Yellow,              R_LM_Yellow,          \

            R_LM_Yellow,              R_LM_Yellow,              R_LM_Yellow,              R_LM_Yellow,              R_LM_Yellow,          \

            R_LM_Yellow,              R_LM_Light_orange,        R_KM_dirty_green,         R_LM_Cyan,                R_LM_Yellow,          \

            R_LM_White,               R_LM_White,               R_LM_White,               R_LM_Yellow },



    //             8                    9                           0                    -                       =
    [Layer_macros_colour] =
            { L_LM_______,            L_LM_Blooder_Red,         L_LM_NeonGreen,           L_LM_______,              L_LM_______,          \
    //             y                    u                           i                    o                       p
            L_LM_______,              L_LM_Blooder_Red,         L_LM_NeonGreen,           L_LM_______,              L_LM_______,          \
    //             h                    j                           k                    l                       ;
            L_KM_Light_yellow,        L_KM_Light_yellow,        L_KM_Light_yellow,        L_KM_Light_yellow,        L_LM_______,          \
    //             n                    m                           ,                    .                       /
            L_LM_______,              L_LM_______,              L_LM_______,              L_LM_______,              L_LM_______,          \
    //             <-                   down                        up                   ->
            L_LM_______,              L_LM_______,              L_LM_______,              L_LM_______,                                  \


    //             5                    4                           3                    2                       1
            R_LM_Blooder_Red,         R_LM_NeonGreen,           R_LM_NeonGreen,           R_LM_______,              R_LM_______,          \
    //             t                    r                           e                    w                       q
            R_KM_dirty_green,         R_KM_dirty_green,         R_LM_______,              R_LM_Light_blue_purple,   R_KM_Light_red,       \
    //             g                    f                          d                    s                       a
            R_KM_dirty_green,         R_KM_dirty_green,         R_LM_Light_pink,          R_LM_Light_pink,          R_LM_Light_pink,      \
    //             b                    v                           c                    x                       z
            R_KM_dirty_green,         R_KM_dirty_green,         R_LM_______,              R_LM_______,              R_LM_Light_pink,      \
    //                                                          esc                  esc
            R_LM_______,              R_LM_______,              R_LM_______,              R_LM_______ },



    [Layer_gaming_colour] =
            { L_LM_LightBrown,        L_LM_LightBrown,          L_LM_LightBrown,          L_LM_LightBrown,          L_LM_LightBrown,      \

            L_LM_Light_orange,        L_LM_White,               L_LM_White,               L_LM_White,               L_LM_White,           \

            L_LM_Orange,              L_LM_White,               L_LM_White,               L_LM_White,               L_LM_White,           \

            L_LM_Blooder_Red,         L_LM_White,               L_LM_White,               L_LM_White,               L_KM_Light_red,       \

            L_LM_White,               L_LM_White,               L_KM_Light_red,           L_KM_Light_red,                               \



            R_LM_Orange,              R_LM_Orange,              R_LM_Orange,              R_LM_Orange,              R_LM_Orange,          \

            R_LM_NeonGreen,           R_LM_skyBlue,             R_KM_Light_red,           R_LM_Cyan,                R_LM_Orange,          \

            R_LM_Yellow,              R_KM_Light_red,           R_KM_Light_red,           R_KM_Light_red,           R_LM_Orange,          \

            R_LM_LightBrown,          R_LM_Toirquise,           R_LM_Toirquise,           R_LM_Toirquise,           R_LM_skyBlue,         \

            R_LM_Purple,              R_LM_Purple,              R_LM_Light_orange,        R_LM_Purple },




};




void keyboard_post_init_user(void) {
    scroll_delay_timer = timer_read();
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

#ifdef SHOW_UNLOCK_ANIMATION
#define UNLOCK_PASSWORD_LED_SEQUENCE_LENGTH 9
// this goes in a line from the bottom row. will need to extend this if using a really long password.
const uint8_t passwordLedsSequence[UNLOCK_PASSWORD_LED_SEQUENCE_LENGTH] = {47, 46, 45, 44, 20, 21, 22, 23 };
#endif

void set_layer_color(uint8_t layer) {
    if(modifiers_blink_count > 200){
        modifiers_blink_count = 0;
    }
    modifiers_blink_count++;

    #ifdef SHOW_UNLOCK_ANIMATION
        bool allowed = false;
    #endif

    for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {

        #ifdef SHOW_UNLOCK_ANIMATION
            allowed = false;

            if(unlock_password_index != 0 && unlock_password_index < UNLOCK_PASSWORD_LED_SEQUENCE_LENGTH){
                for(uint8_t j = 0; j < unlock_password_index; j++){
                    if (i == passwordLedsSequence[j]) {
                        allowed = true;
                    }
                }
            }
            if(rgb_timed_out && !allowed){
                rgb_matrix_set_color(i, 0, 0, 0);
                continue;
            }
        #endif

        #ifndef SHOW_UNLOCK_ANIMATION
            if(rgb_timed_out){
                rgb_matrix_set_color(i, 0, 0, 0);
                continue;
            }
        #endif


        use_default_lighting = true;

        if(leader_key_is_running && (i == 19 || i == 22 || i == 23)){ //show leader indicator on /,top arrow,right arrow keys
            rgb_matrix_set_color( i, 31, 107, 239 );
            use_default_lighting = false;
        }

        if(
            ((layer == 0 && main_layer_brightness) || layer != 0) &&
            (
                (enable_bunnyhop && i == 4) ||
                (password_bypass && i == 9) ||
                (combos_on && i == 47) ||
                (mac_mode && i == 16) ||
                (caps_lock_on && i == 23) ||
                (num_lock_on && i == 22)
            )
        ){
            if(modifiers_blink_count < 100){
                if(num_lock_on && i == 22){
                    rgb_matrix_set_color( i, 5,255,2 );
                    continue;
                }
                if(caps_lock_on && i == 23){
                    rgb_matrix_set_color( i, 255,0,0 );
                    continue;
                }
                rgb_matrix_set_color( i, 237, 28, 28 );
                continue;
            }
        }


        if(use_default_lighting) {
            HSV hsv = {
                .h = pgm_read_byte(&ledmap[layer][i][1]),
                .s = pgm_read_byte(&ledmap[layer][i][2]),
                .v = pgm_read_byte(&ledmap[layer][i][3]),
            };
            if ((!hsv.h && !hsv.s && !hsv.v) || (layer == 0 && !main_layer_brightness)) {
                rgb_matrix_set_color( i, 0, 0, 0 );
            } else {

                if(brightness_amount != 0){
                    uint8_t check = hsv.v + brightness_amount;

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
                    uint8_t check = hsv.h + hue_amount;
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

bool rgb_matrix_indicators_user(void) {
    if (g_suspend_state || keyboard_config.disable_layer_led) { return false; }
    if(rgb_show){
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
            case Layer_colemak:
                set_layer_color(Layer_main_colour);
            break;
            case Layer_mouse:
                set_layer_color(Layer_macros_colour);
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
    return true;
}

bool led_update_user(led_t led_state) {
    caps_lock_on = led_state.caps_lock;
    num_lock_on = led_state.num_lock;
    return true;
}
