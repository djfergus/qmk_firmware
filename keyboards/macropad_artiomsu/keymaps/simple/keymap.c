#include "sharedDefines.h"

/*
This layout removes unessesarry functions from the tinyexpr library,
well the functions that are not needed for the layout as this is a fairly simple calculator.
The reduction in size allows you to add more features to the firmware without compromising on the calculator.

To compile the layout
make clean && make macropad_artiomsu:simple

To find the device plug it in and run
sudo dmesg | grep tty

To flash the firmware
sudo avrdude -p atmega32u4 -P /dev/ttyACM0 -c avr109 -U flash:w:macropad_artiomsu_minimised.hex
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[Layer_main] = LAYOUT_artiomsu_macropad( //default numpad
		KC_NUM_LOCK,     KC_KP_SLASH,    KC_KP_ASTERISK,     KC_KP_MINUS,
		KC_KP_7,        KC_KP_8,        KC_KP_9,            KC_KP_PLUS,
		KC_KP_4,        KC_KP_5,        KC_KP_6,            KC_KP_ENTER,
		KC_KP_1,        KC_KP_2,        KC_KP_3,            KC_COMMA,
		KC_KP_0,        KC_KP_DOT,      KC_KP_EQUAL,        LT(Layer_shortcuts, KC_BACKSPACE)),

	[Layer_shortcuts] = LAYOUT_artiomsu_macropad( //internal settings, layer switching and obs shortcuts.
		COMPILE_MACRO,              FLASH_MACRO,                KC_CALCULATOR,                 L1_PRECISION_MINUS,
		PB_7,                       PB_8,                       PB_9,                          L1_PRECISION_PLUS,
		PB_4,                       PB_5,                       PB_6,                          TOGGLE_NUM_LOCK_ANIMATION,
		PB_1,                       PB_2,                       PB_3,                          PB_20,
		PB_10,                      PB_11,                      TO(Layer_calc),                TO(Layer_main)),

    [Layer_calc] = LAYOUT_artiomsu_macropad( //hardware calculator
		L1_PRINT_EQUATION,  L1_SLASH,   L1_MULTIPLY,    L1_MINUS,
		L1_7,               L1_8,       L1_9,           L1_PLUS,
		L1_4,               L1_5,       L1_6,           L1_POWER,
		L1_1,               L1_2,       L1_3,           L1_MOD,
		L1_0,               L1_DOT,     L1_EQUALS,      L1_EXIT_LAYER),

    // [Layer_extra] = LAYOUT_MACROPAD(
	// 	_______,_______,_______,_______,
	// 	_______,    KC_W,_______,_______,
	// 	KC_A,       KC_S,       KC_D,       _______,
	// 	_______,    KC_UP,      _______,    _______,
	// 	KC_LEFT,    KC_DOWN,    KC_RIGHT,   TO(Layer_main))
};
