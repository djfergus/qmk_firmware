#include "kb.h"


/*
cd /media/veracrypt1/GIT/qmk_firmware && make clean && make artiomsu_tiny30:default
cd /media/veracrypt1/GIT/qmk_firmware && sudo avrdude -p atmega32u4 -P /dev/ttyACM0 -c avr109 -U flash:w:artiomsu_tiny30_default.hex
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	LAYOUT_30(
		KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
		KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_ENT,
		KC_Z, KC_X, KC_C, KC_V, KC_B, KC_SPC, KC_N, KC_M, KC_COMM, KC_DOT)

};
