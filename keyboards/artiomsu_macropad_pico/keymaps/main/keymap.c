#include "sharedDefines.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [Layer_main] = LAYOUT_artiomsu_macropad(
        LT(Layer_shortcuts, KC_BACKSPACE), KC_F2, TO(Layer_calc), QK_BOOT,
        KC_NUM_LOCK,     KC_KP_SLASH,    KC_KP_ASTERISK,     KC_KP_MINUS,
        KC_KP_7,         KC_KP_8,        KC_KP_9,            KC_KP_PLUS,
        KC_KP_4,         KC_KP_5,        KC_KP_6,
        KC_KP_1,         KC_KP_2,        KC_KP_3,
        KC_KP_0,         KC_KP_DOT,      KC_KP_ENTER
    ),
    [Layer_shortcuts] = LAYOUT_artiomsu_macropad(
		TO(Layer_main),  PB_23,          PB_24,              FLASH_MACRO,
        PB_10,           PB_11,          PB_12,              PB_13,
		PB_7,            PB_8,           PB_9,               PB_14,
		PB_4,            PB_5,           PB_6,
		PB_1,            PB_2,           PB_3,
		PB_20,           PB_21,          PB_22
    ),
    [Layer_calc] = LAYOUT_artiomsu_macropad( //hardware calculator
        L1_EXIT_LAYER,      L1_POWER,   L1_MOD,         KC_T, // put delete macro here later
		L1_PRINT_EQUATION,  L1_SLASH,   L1_MULTIPLY,    L1_MINUS,
		L1_7,               L1_8,       L1_9,           L1_PLUS,
		L1_4,               L1_5,       L1_6,
		L1_1,               L1_2,       L1_3,
		L1_0,               L1_DOT,     L1_EQUALS
    )

};

bool encoder_update_user_Layer_calc(uint8_t index, bool clockwise) {
    switch (index){
        case 0:
            if (clockwise) {
                if(decimal_point_pressision < 10){
                    decimal_point_pressision++;
                }
            } else {
                if(decimal_point_pressision > 0){
                    decimal_point_pressision--;
                }
            }
            break;
        case 1:
            if (clockwise) {
                tap_code(KC_3);
            } else {
                tap_code(KC_4);
            }
            break;
        case 2:
            if (clockwise) {
                tap_code(KC_5);
            } else {
                tap_code(KC_6);
            }
            break;
        case 3:
            if (clockwise) {
                tap_code(KC_7);
            } else {
                tap_code(KC_8);
            }
            break;
        default:
            return true;
    }
    return false;
}


bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (get_highest_layer(layer_state)) {
        case Layer_main:
        case Layer_shortcuts:
            switch (index){
                case 0:
                    if (clockwise) {
                        tap_code(KC_1);
                    } else {
                        tap_code(KC_2);
                    }
                    break;
                case 1:
                    if (clockwise) {
                        rgblight_increase_val_noeeprom();
                    } else {
                        rgblight_decrease_val_noeeprom();
                    }
                    break;
                case 2:
                    if (clockwise) {
                        rgblight_increase_hue_noeeprom();
                    } else {
                        rgblight_decrease_hue_noeeprom();
                    }
                    break;
                case 3:
                    if (clockwise) {
                        rgblight_step_noeeprom();
                    } else {
                        rgblight_step_reverse_noeeprom();
                    }
                    break;
                default:
                    return true;
            }
            return false;
        break;
        case Layer_calc:
            return encoder_update_user_Layer_calc(index, clockwise);
        default:
            return true;
    }
}
