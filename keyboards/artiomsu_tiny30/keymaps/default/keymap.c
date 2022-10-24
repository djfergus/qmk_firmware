#include "default.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[Layer_main] = LAYOUT_tiny_thirty(
		LT(Layer_fkeys,KC_Q),   KC_W,                   KC_E,                   KC_R,                   KC_T,                   KC_Y,                       KC_U,                   KC_I,           KC_O,                   KC_P,
		KC_A,                   KC_S,                   KC_D,                   KC_F,                   LT(Layer_nums,KC_G),    KC_H,                       KC_J,                   KC_K,           KC_L,                   LSFT_T(KC_ENTER),
		LCTL_T(KC_Z),           LALT_T(KC_X),           LCG_T(KC_C),            LSG_T(KC_V),            LGUI_T(KC_B),           LT(Layer_symbols,KC_SPACE), KC_N,                   KC_M,           LCSG_T(KC_DOT),         HYPR_T(KC_SLASH)
    ),

	[Layer_symbols] = LAYOUT_tiny_thirty(
		KC_GRAVE,               KC_QUOTE,               LSFT(KC_QUOTE),         LSFT(LCTL(KC_C)),       LSFT(LCTL(KC_V)),       KC_LABK,                    KC_PLUS,                KC_MINUS,       KC_RABK,                KC_EQUAL,
		KC_EXLM,                LSFT(KC_2),             LSFT(KC_3),             KC_DLR,                 KC_PERC,                KC_ASTR,                    KC_LBRACKET,            KC_RBRACKET,    KC_UNDS,                KC_QUES,
		KC_LSHIFT,              KC_AMPR,                LSFT(KC_NONUS_BSLASH),  LSFT(KC_NONUS_HASH),    KC_ASTR,                _______,                    LSFT(KC_SCOLON),        KC_SCOLON,      KC_COMM,                KC_NONUS_BSLASH
    ),

	[Layer_nums] = LAYOUT_tiny_thirty(
		KC_1,                   KC_2,                   KC_3,                   KC_4,                   KC_5,                   KC_6,                       KC_7,                   KC_8,           KC_9,                   KC_0,
		DYN_REC_START1,         DYN_REC_START2,         DYN_REC_STOP,           KC_MS_WH_UP,            _______,                KC_MS_LEFT,                 KC_MS_DOWN,             KC_MS_UP,       KC_MS_RIGHT,            KC_PSCREEN,
		DYN_MACRO_PLAY1,        DYN_MACRO_PLAY2,        KC_MS_BTN4,             KC_MS_WH_DOWN,          KC_MS_BTN4,             KC_MS_BTN3,                 KC_MS_BTN1,             KC_MS_BTN2,     KC_DELETE,              KC_ESC
    ),

	// [Layer_fkeys] = LAYOUT_30(
	// 	_______,                KC_F2,                  KC_F3,                  KC_F4,                  KC_F5,                  KC_F6,                      KC_F7,                  KC_F8,          KC_F9,                  KC_F10,
	// 	KC_F11,                 KC_F12,                 _______,                _______,                RGB_VAI,                RGB_SAI,                    RGB_HUI,           RGB_MODE_REVERSE,    _______,                KC_F1,
	// 	KC_LEAD,                _______,                _______,                RGB_MODE_SNAKE,         RGB_VAD,                RGB_SAD,                    RGB_HUD,           RGB_MODE_FORWARD,    _______,                RGB_TOG
    // ),

	[Layer_fkeys] = LAYOUT_tiny_thirty(
		_______,                KC_F2,                  KC_F3,                  KC_F4,                  KC_F5,                  KC_F6,                      KC_F7,                  KC_F8,          KC_F9,                  KC_F10,
		KC_F11,                 KC_F12,                 RGB_VAI,                RGB_SAI,                RGB_HUI,                KC_LEFT,                    KC_DOWN,                KC_UP,          KC_RIGHT,               KC_F1,
		KC_LEAD,                RGB_MODE_SNAKE,         RGB_VAD,                RGB_SAD,                RGB_HUD,                _______,                    _______,           RGB_MODE_REVERSE,    RGB_MODE_FORWARD,       RGB_TOG
    ),

/*
	[Layer_template] = LAYOUT_30(
		_______,                _______,                _______,                _______,                _______,                _______,                    _______,                _______,        _______,                _______,
		_______,                _______,                _______,                _______,                _______,                _______,                    _______,                _______,        _______,                _______,
		_______,                _______,                _______,                _______,                _______,                _______,                    _______,                _______,        _______,                _______
    ),
*/
};
