#include "sharedDefines.h"

int8_t brightness_amount = -70;
uint8_t hue_amount = 0;

bool rgb_show = true;
bool rgb_timed_out = true; // set to true so that you will need to type in the password straight away
//uint16_t rgb_sync_to_timer = 0; //sync out timer to the official rgb timer.
uint32_t rgb_time_out_value = 300000; // in milliseconds // 5 minutes by default

uint8_t modifiers_blink_count = 0; // this is for stuff like enable_bunnyhop and the leader key

bool use_default_lighting = true; // do not change used inside loop
bool g_suspend_state;

//extern rgb_config_t rgb_matrix_config;

bool caps_lock_on = false;
bool num_lock_on = false;

#define LAYER_NUM_LEDS_INDIC 8

const rgblight_segment_t PROGMEM led_l_capslock[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, (LAYER_NUM_LEDS_INDIC / 2), HSV_RED}       // Light 1 LEDs, starting with LED 0
);

const rgblight_segment_t PROGMEM led_l_numlock[] = RGBLIGHT_LAYER_SEGMENTS(
    {4, (LAYER_NUM_LEDS_INDIC / 2), HSV_SPRINGGREEN}       // Light 1 LEDs, starting with LED 1
);

const rgblight_segment_t PROGMEM led_l_mac_main[] = RGBLIGHT_LAYER_SEGMENTS(
    {20, LAYER_NUM_LEDS_INDIC,
    21, 255, 170} // orange
);

const rgblight_segment_t PROGMEM led_l_colemac[] = RGBLIGHT_LAYER_SEGMENTS(
    {8, LAYER_NUM_LEDS_INDIC, HSV_TEAL}
);

const rgblight_segment_t PROGMEM led_l_symbols[] = RGBLIGHT_LAYER_SEGMENTS(
    {8, LAYER_NUM_LEDS_INDIC,
    181, 255, 170} // purple
);

const rgblight_segment_t PROGMEM led_l_macros[] = RGBLIGHT_LAYER_SEGMENTS(
    {8, LAYER_NUM_LEDS_INDIC, HSV_YELLOW}
);

const rgblight_segment_t PROGMEM led_l_gaming[] = RGBLIGHT_LAYER_SEGMENTS(
    {8, LAYER_NUM_LEDS_INDIC, HSV_YELLOW}
);

const rgblight_segment_t PROGMEM led_l_mouse[] = RGBLIGHT_LAYER_SEGMENTS(
    {8, LAYER_NUM_LEDS_INDIC, HSV_WHITE}
);

const rgblight_segment_t PROGMEM led_l_nav[] = RGBLIGHT_LAYER_SEGMENTS(
    {8, LAYER_NUM_LEDS_INDIC, HSV_PINK}
);

const rgblight_segment_t PROGMEM led_l_on_combos[] = RGBLIGHT_LAYER_SEGMENTS(
    {31, 3, HSV_RED}
);

const rgblight_segment_t PROGMEM led_l_on_password_bypass[] = RGBLIGHT_LAYER_SEGMENTS(
    {30, 3, HSV_ORANGE}
);

const rgblight_segment_t PROGMEM led_l_on_bunny_hopping[] = RGBLIGHT_LAYER_SEGMENTS(
    {29, 3, HSV_PURPLE}
);

const rgblight_segment_t PROGMEM led_l_on_leader[] = RGBLIGHT_LAYER_SEGMENTS(
    {30, 6, HSV_BLUE}
);

const rgblight_segment_t PROGMEM led_l_on_dynamic_macros_rec[] = RGBLIGHT_LAYER_SEGMENTS(
    {65, 43, HSV_GREEN}
);

// this doesn't work it becomes white for some reason
const rgblight_segment_t PROGMEM led_l_blackout[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, RGB_BLACK}
);

const rgblight_segment_t PROGMEM led_l_password_locked[] = RGBLIGHT_LAYER_SEGMENTS(
    {35, 30, HSV_RED}
);

// don't forget to increase RGBLIGHT_MAX_LAYERS in config.h
const rgblight_segment_t* const PROGMEM led_all_layers[] = RGBLIGHT_LAYERS_LIST(
    led_l_capslock,
    led_l_numlock,
    led_l_mac_main,
    led_l_colemac,
    led_l_symbols,
    led_l_macros,
    led_l_gaming,
    led_l_mouse,
    led_l_nav,

    led_l_on_combos,
    led_l_on_password_bypass,
    led_l_on_bunny_hopping,
    led_l_on_leader,
    led_l_on_dynamic_macros_rec,
    led_l_blackout,
    led_l_password_locked
);


void keyboard_post_init_user(void) {
    scroll_delay_timer = timer_read();
    //rgb_matrix_enable();
    rgblight_layers = led_all_layers;
}

void suspend_power_down_user(void) {
    g_suspend_state = true;
    //rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_user(void) {
    g_suspend_state = false;
    //rgb_matrix_set_suspend_state(false);
}

#ifdef SHOW_UNLOCK_ANIMATION
#define UNLOCK_PASSWORD_LED_SEQUENCE_LENGTH 9
// this goes in a line from the bottom row. will need to extend this if using a really long password.
const uint8_t passwordLedsSequence[UNLOCK_PASSWORD_LED_SEQUENCE_LENGTH] = {47, 46, 45, 44, 20, 21, 22, 23 };
#endif

// void set_layer_color(uint8_t layer) {
//     if(modifiers_blink_count > 200){
//         modifiers_blink_count = 0;
//     }
//     modifiers_blink_count++;

//     #ifdef SHOW_UNLOCK_ANIMATION
//         bool allowed = false;
//     #endif

//     for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {

//         #ifdef SHOW_UNLOCK_ANIMATION
//             allowed = false;

//             if(unlock_password_index != 0 && unlock_password_index < UNLOCK_PASSWORD_LED_SEQUENCE_LENGTH){
//                 for(uint8_t j = 0; j < unlock_password_index; j++){
//                     if (i == passwordLedsSequence[j]) {
//                         allowed = true;
//                     }
//                 }
//             }
//             if(rgb_timed_out && !allowed){
//                 rgb_matrix_set_color(i, 0, 0, 0);
//                 continue;
//             }
//         #endif

//         #ifndef SHOW_UNLOCK_ANIMATION
//             if(rgb_timed_out){
//                 rgb_matrix_set_color(i, 0, 0, 0);
//                 continue;
//             }
//         #endif


//         use_default_lighting = true;

//         if(leader_key_is_running && (i == 19 || i == 22 || i == 23)){ //show leader indicator on /,top arrow,right arrow keys
//             rgb_matrix_set_color( i, 31, 107, 239 );
//             use_default_lighting = false;
//         }

//         if(
//             ((layer == 0 && main_layer_brightness) || layer != 0) &&
//             (
//                 (enable_bunnyhop && i == 4) ||
//                 (password_bypass && i == 9) ||
//                 (combos_on && i == 47) ||
//                 (mac_mode && i == 16) ||
//                 (caps_lock_on && i == 23) ||
//                 (num_lock_on && i == 22)
//             )
//         ){
//             if(modifiers_blink_count < 100){
//                 if(num_lock_on && i == 22){
//                     rgb_matrix_set_color( i, 5,255,2 );
//                     continue;
//                 }
//                 if(caps_lock_on && i == 23){
//                     rgb_matrix_set_color( i, 255,0,0 );
//                     continue;
//                 }
//                 rgb_matrix_set_color( i, 237, 28, 28 );
//                 continue;
//             }
//         }


//         if(use_default_lighting) {
//             HSV hsv = {
//                 .h = pgm_read_byte(&ledmap[layer][i][1]),
//                 .s = pgm_read_byte(&ledmap[layer][i][2]),
//                 .v = pgm_read_byte(&ledmap[layer][i][3]),
//             };
//             if ((!hsv.h && !hsv.s && !hsv.v) || (layer == 0 && !main_layer_brightness)) {
//                 rgb_matrix_set_color( i, 0, 0, 0 );
//             } else {

//                 if(brightness_amount != 0){
//                     uint8_t check = hsv.v + brightness_amount;

//                     if(check < 250 && check > 10){
//                         hsv.v = check;
//                     }else{
//                         if(brightness_amount<0){
//                             brightness_amount+=10;
//                         }else{
//                             brightness_amount-=10;
//                         }
//                     }
//                 }

//                 if(hue_amount != 0){
//                     uint8_t check = hsv.h + hue_amount;
//                     if(check > 250){
//                         check = check - 250;
//                     }
//                     if(check < 5){
//                         check = check + 250;
//                     }
//                     if(check < 250 && check > 5){
//                         hsv.h = check;
//                     }
//                 }

//                 RGB rgb = hsv_to_rgb( hsv );
//                 float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
//                 rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
//             }
//         }
//     }
// }

// bool rgb_matrix_indicators_user(void) {
//     if (g_suspend_state || keyboard_config.disable_layer_led) { return false; }
//     if(rgb_show){
//         switch (biton32(layer_state)) {
//             case Layer_main:
//                 set_layer_color(Layer_main_colour);
//             break;
//             case Layer_symbols:
//                 set_layer_color(Layer_symbols_colour);
//             break;
//             case Layer_macros:
//                 set_layer_color(Layer_macros_colour);
//             break;
//             case Layer_gaming:
//                 set_layer_color(Layer_gaming_colour);
//             break;
//             case Layer_mac_main:
//                 set_layer_color(Layer_main_colour);
//             break;
//             case Layer_mac_symbols:
//                 set_layer_color(Layer_symbols_colour);
//             break;
//             case Layer_colemak:
//                 set_layer_color(Layer_main_colour);
//             break;
//             case Layer_mouse:
//                 set_layer_color(Layer_macros_colour);
//             break;
//             default:
//                 if (rgb_matrix_get_flags() == LED_FLAG_NONE){
//                     rgb_matrix_set_color_all(0, 0, 0);
//                 }
//             break;
//     }
//     }else{
//         rgb_matrix_set_color_all(0, 0, 0);
//     }
//     return true;
// }

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(2, layer_state_cmp(state, Layer_mac_main));
    rgblight_set_layer_state(3, layer_state_cmp(state, Layer_colemak));
    rgblight_set_layer_state(4, layer_state_cmp(state, Layer_symbols) || layer_state_cmp(state, Layer_mac_symbols));
    rgblight_set_layer_state(5, layer_state_cmp(state, Layer_macros));
    rgblight_set_layer_state(6, layer_state_cmp(state, Layer_gaming));
    rgblight_set_layer_state(7, layer_state_cmp(state, Layer_mouse));
    rgblight_set_layer_state(8, layer_state_cmp(state, Layer_nav));

    //rgblight_set_layer_state(9, combos_on);
    if(combos_on){
        rgblight_blink_layer_repeat(9, 1000, 5);
    }
    rgblight_set_layer_state(10, password_bypass);
    rgblight_set_layer_state(11, enable_bunnyhop);
    //rgblight_set_layer_state(12, leader_key_is_running); moved to leader.c
    //if(dynamic_macro_recording){ // moved to macros
    //    rgblight_blink_layer_repeat(13, 800, 10);
    //}else{
    //    rgblight_unblink_layer(13);
    //}
    // 14 for blackout in leader
    //rgblight_set_layer_state(15, unlock_password_index < UNLOCK_PASSWORD_LENGTH); // moved to macros


    return state;
}

bool led_update_user(led_t led_state) {
    caps_lock_on = led_state.caps_lock;
    num_lock_on = led_state.num_lock;

    rgblight_set_layer_state(0, caps_lock_on);
    rgblight_set_layer_state(1, num_lock_on);

    return true;
}
