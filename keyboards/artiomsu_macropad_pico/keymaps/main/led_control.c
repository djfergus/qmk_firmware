#include "sharedDefines.h"

// for the numlock and layer leds
bool num_lock_led_is_on = false;        // if numlock should be on
int led_state_current = 0;              // what is the current layer temp

bool led_update_user(led_t led_state) {
    num_lock_led_is_on = led_state.num_lock;
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    led_state_current = get_highest_layer(state);
    return state;
}

void keyboard_post_init_user(void) {
    // set this to sync the state of the two halves since we are not using eeprom.
    rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL);
    //rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_sethsv_noeeprom(13, 250, 200);
    expressions_buffer[0] = '\0';
}

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

void oled_clear_whole_screen(void){
    uint8_t width = oled_max_chars();
    //uint8_t height = oled_max_lines();

    char buff[width];
    uint8_t i = 0;
    for(i = 0; i<width; i++){
        buff[i]='#';
    }
    buff[width-1] = '\n';
    buff[width] = '\0';
    oled_set_cursor(0, 0);
    oled_write(buff, false);
    oled_set_cursor(0, 0);
}

bool oled_task_user(void) {
    //oled_set_cursor(0, 0);
    //oled_advance_page(true);
    switch (get_highest_layer(layer_state)) {
        case Layer_main:
            render_logo();
            break;
        case Layer_shortcuts:
            oled_write_P(PSTR("Shortcuts\n"), false);
            break;
        case Layer_calc:
            //oled_advance_page(true);
            //oled_clear();
            //oled_set_cursor(0, 0);
            //oled_clear_whole_screen();
            oled_write_P(PSTR("Calculator\n"), false);
            char pres[32];
            sprintf(pres, "Precision %d\n", decimal_point_pressision);
            oled_write_P(pres, false);
            oled_write_P(expressions_buffer, false);
            oled_write_P(PSTR("\n"), false);
            break;

    }
    return false;
}
