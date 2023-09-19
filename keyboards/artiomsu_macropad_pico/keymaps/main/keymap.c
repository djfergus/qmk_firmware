#include QMK_KEYBOARD_H

#define _QWERTY 0

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_artiomsu_macropad(
        KC_A, KC_B, KC_C, KC_D,
        KC_E, KC_F, KC_G, KC_H,
        KC_Z, KC_J, KC_K, KC_L,
        KC_M, KC_N, KC_O,
        KC_P, KC_Q, KC_R,
        KC_S, KC_T, QK_BOOT
    )
};

void keyboard_post_init_user(void) {
    // set this to sync the state of the two halves since we are not using eeprom.
    rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL);
    //rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_sethsv_noeeprom(13, 250, 200);
}

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

bool oled_task_user(void) {
    render_logo();
    return false;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
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
