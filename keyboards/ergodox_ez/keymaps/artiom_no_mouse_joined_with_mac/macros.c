#include "sharedDefines.h"

bool use_bunnyhop = false;
bool enable_bunnyhop = false;

bool combos_on = true; // use combo feature by default
bool mac_mode = false;
bool colemak_mode = false;
uint32_t rgb_timeout_counter = 0;


uint16_t unlock_password_index = 0;
bool password_bypass = false;
// int word_length_count = 0;
// int last_word_length=0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // if(keycode >= 4 && keycode <= 39){
    //     word_length_count++;
    //     last_word_length = word_length_count;
    // }else{
    //     word_length_count = 0;
    // }
    if(rgb_timed_out && unlock_password_index < UNLOCK_PASSWORD_LENGTH && !password_bypass){
        //if(keycode >= 4 && keycode <= 39){ // only lock the letter keys
            if(record->event.pressed){
                if(unlock_password[unlock_password_index] == keycode && record->event.pressed){
                    unlock_password_index++;
                }else{
                    unlock_password_index = 0;
                }
            }
            return false; // return false to block the keys.
        //}
    }

    unlock_password_index = 0;
    rgb_timed_out = false;
    rgb_timeout_counter=0; //reset timeout counter also, so that it will always count from the time the key was pressed.

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
                rgb_time_out_value = 30000;
            }
        break;
        case ST_M_led_timeout_1m:
            if (record->event.pressed) {
                rgb_time_out_value = 60000;
            }
        break;
        case ST_M_led_timeout_5m:
            if (record->event.pressed) {
                rgb_time_out_value = 300000;
            }
        break;
        case ST_M_led_timeout_10m:
            if (record->event.pressed) {
                rgb_time_out_value = 600000;
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
                if(colemak_mode){ // reset the colemak mode
                    layer_on(Layer_colemak);
                }
            }
        break;
        case ST_M_combo_toggle:
            if (record->event.pressed) {
                combo_toggle();
                combos_on = is_combo_enabled();
            }
        break;
        case ST_M_colemak_mode_toggle:
            if (record->event.pressed) {
                colemak_mode = !colemak_mode;
                if(colemak_mode){
                    layer_on(Layer_colemak);
                }else{
                    layer_off(Layer_colemak);
                }
            }
        break;
        case ST_M_password_bypass:
            if (record->event.pressed) {
                password_bypass = !password_bypass;
            }
        break;
        //case ST_M_Mouse_B:
        //case ST_M_Mouse_F:
            // uint8_t mouse_btn = keycode == ST_M_Mouse_B ? MOUSE_BTN4 : MOUSE_BTN5; // These definitions can be found in report.h
            // report_mouse_t currentReport = pointing_device_get_report();
            // if (record->event.pressed) {
            //     currentReport.buttons |= mouse_btn;
            // }else{
            //     currentReport.buttons &= ~mouse_btn;
            // }
            // pointing_device_set_report(currentReport);
            // pointing_device_send();
        //break;
        return false;
  }
  return true;
}

// void dynamic_macro_record_start_user(void){
//     if(mac_mode){
//         layer_move(Layer_mac_main);
//     }else{
//         layer_move(Layer_main);
//     }
// }
/*
    Fix for dymanic macro nuking the mac layer when it starts recording and ends recording might cause issues in the future?
    qmk_firmware/quantum/process_keycode/process_dynamic_macro.c comment out layer_clear() on line 59 and line 76
*/
