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
//bool isLeft = is_keyboard_left(); doesn't work for leds, since the state is synced externally, but will leave it here for future reference.

#define LAYER_NUM_LEDS_INDIC 10

//good
const rgblight_segment_t PROGMEM led_l_capslock[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, (LAYER_NUM_LEDS_INDIC / 2), HSV_RED}       // Light 1 LEDs, starting with LED 0
);

//good
const rgblight_segment_t PROGMEM led_l_numlock[] = RGBLIGHT_LAYER_SEGMENTS(
    {4, (LAYER_NUM_LEDS_INDIC / 2), HSV_SPRINGGREEN}       // Light 1 LEDs, starting with LED 1
);

//good
const rgblight_segment_t PROGMEM led_l_mac_main[] = RGBLIGHT_LAYER_SEGMENTS(
    {55, 4,
    21, 255, 170} // orange
);

//good
const rgblight_segment_t PROGMEM led_l_colemac[] = RGBLIGHT_LAYER_SEGMENTS(
    {50, 6, HSV_TEAL}
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

//good
const rgblight_segment_t PROGMEM led_l_on_combos[] = RGBLIGHT_LAYER_SEGMENTS(
    {31, 5, HSV_RED}
);

//good
const rgblight_segment_t PROGMEM led_l_on_password_bypass[] = RGBLIGHT_LAYER_SEGMENTS(
    {37, 6, HSV_SPRINGGREEN}
);

//good
const rgblight_segment_t PROGMEM led_l_on_bunny_hopping[] = RGBLIGHT_LAYER_SEGMENTS(
    {59, 4, HSV_PURPLE}
);

//good
const rgblight_segment_t PROGMEM led_l_on_leader[] = RGBLIGHT_LAYER_SEGMENTS(
    {30, 6, HSV_BLUE}
);

//good
const rgblight_segment_t PROGMEM led_l_on_dynamic_macros_rec[] = RGBLIGHT_LAYER_SEGMENTS(
    {65, 43, HSV_GREEN}
);

// this doesn't work it becomes white for some reason
const rgblight_segment_t PROGMEM led_l_blackout[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, RGB_BLACK}
);

//good
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
    rgblight_layers = led_all_layers;
    // set this to sync the state of the two halves since we are not using eeprom.
    rgblight_mode_noeeprom(RGBLIGHT_MODE_TWINKLE + 3);
    //rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_sethsv_noeeprom(13, 250, 20);
}

void suspend_power_down_user(void) {
    g_suspend_state = true;
}

void suspend_wakeup_init_user(void) {
    g_suspend_state = false;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    //rgblight_set_layer_state(2, layer_state_cmp(state, Layer_mac_main));
    if(layer_state_cmp(state, Layer_mac_main)){
        rgblight_blink_layer_repeat(2, 1000, 5);
    }else{
        rgblight_unblink_layer(2);
    }
    //rgblight_set_layer_state(3, layer_state_cmp(state, Layer_colemak));
    if(layer_state_cmp(state, Layer_colemak)){
        rgblight_blink_layer_repeat(3, 1000, 5);
    }else{
        rgblight_unblink_layer(3);
    }
    rgblight_set_layer_state(4, layer_state_cmp(state, Layer_symbols) || layer_state_cmp(state, Layer_mac_symbols));
    rgblight_set_layer_state(5, layer_state_cmp(state, Layer_macros));
    rgblight_set_layer_state(6, layer_state_cmp(state, Layer_gaming));
    rgblight_set_layer_state(7, layer_state_cmp(state, Layer_mouse));
    rgblight_set_layer_state(8, layer_state_cmp(state, Layer_nav));

    //rgblight_set_layer_state(9, combos_on);
    if(combos_on){
        rgblight_blink_layer_repeat(9, 1000, 5);
    }else{
        rgblight_unblink_layer(9);
    }
    //rgblight_set_layer_state(10, password_bypass);
    if(password_bypass){
        rgblight_blink_layer_repeat(10, 1000, 5);
    }else{
        rgblight_unblink_layer(10);
    }
    //rgblight_set_layer_state(11, enable_bunnyhop);
    if(enable_bunnyhop){
        rgblight_blink_layer_repeat(11, 1000, 5);
    }else{
        rgblight_unblink_layer(11);
    }
    //rgblight_set_layer_state(12, leader_key_is_running); moved to leader.c
    if(dynamic_macro_recording){ // also in macros.c
       rgblight_blink_layer_repeat(13, 800, 10);
    }else{
       rgblight_unblink_layer(13);
    }
    // 14 for blackout in leader
    //rgblight_set_layer_state(15, unlock_password_index < UNLOCK_PASSWORD_LENGTH); // moved to macros


    return state;
}

bool led_update_user(led_t led_state) {
    caps_lock_on = led_state.caps_lock;
    num_lock_on = led_state.num_lock;

    //rgblight_set_layer_state(0, caps_lock_on);
    if(caps_lock_on){
        rgblight_blink_layer_repeat(0, 1000, 5);
    }else{
        rgblight_unblink_layer(0);
    }
    //rgblight_set_layer_state(1, num_lock_on);
    if(num_lock_on){
        rgblight_blink_layer_repeat(1, 1000, 5);
    }else{
        rgblight_unblink_layer(1);
    }

    return true;
}
