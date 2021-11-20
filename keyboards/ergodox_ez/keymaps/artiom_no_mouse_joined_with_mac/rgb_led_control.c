#include "sharedDefines.h"

int brightness_amount = 0;
int hue_amount = 0;

bool main_layer_brightness = true; // can disable the main layer rgb individually

bool rgb_show = true;
bool rgb_timed_out = false;
int timeout_counter = 0;
uint32_t rgb_sync_to_timer = 0; //sync out timer to the official rgb timer.
int rgb_time_out_value = 360;   // 100 = ~9seconds, 666= ~ 54s

int modifiers_blink_count = 0; // this is for stuff like enable_bunnyhop and the leader key

bool use_default_lighting = true; // do not change used inside loop
bool g_suspend_state;

extern rgb_config_t rgb_matrix_config;

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
