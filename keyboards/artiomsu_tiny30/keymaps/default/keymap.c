#include "kb.h"

#define Layer_main 0
#define Layer_symbols 1
#define Layer_nums 2

bool leader_key_is_running = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[Layer_main] = LAYOUT_30(
		KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,                       KC_U,   KC_I,   KC_O,   KC_P,
		KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,                       KC_J,   KC_K,   KC_L,   LT(Layer_nums,KC_ENTER),
		KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   LT(Layer_symbols,KC_SPACE), KC_N,   KC_M,   LSFT_T(KC_DOT),LCTL_T(KC_SLASH)
    ),

	[Layer_symbols] = LAYOUT_30(
		KC_GRAVE,       KC_QUOTE,           LSFT(KC_QUOTE),         LSFT(LCTL(KC_C)),   LSFT(LCTL(KC_V)),       _______,        KC_PLUS,        KC_MINUS,       KC_ESC,         KC_EQUAL,
		KC_EXLM,        LSFT(KC_2),         LSFT(KC_3),             KC_DLR,             KC_PERC,                _______,        _______,        _______,        KC_UNDS,        KC_QUES,
		KC_LSHIFT,      KC_AMPR,            LSFT(KC_NONUS_BSLASH),  LSFT(KC_NONUS_HASH),_______,                _______,        _______,        _______,        KC_COMM,         KC_NONUS_BSLASH
    ),

	[Layer_nums] = LAYOUT_30(
		KC_1,   KC_2,                   KC_3,           KC_4,           KC_5,   KC_6,   KC_7,               KC_8,   KC_9,   KC_0,
		_______,_______,                _______,        _______,        _______,_______,_______,            _______,_______,_______,
		KC_LGUI,LCTL(LSFT(KC_LGUI)),    LCTL(KC_LGUI),  LSFT(KC_LGUI),  KC_LEAD,KC_HYPR,LCTL(LSFT(KC_LGUI)),_______,_______,_______
    ),


};


//combos don't forget to edit COMBO_COUNT in config.h
enum combo_events {
    COMBO_LEFT_SQUARE_BRACKET,
    COMBO_RIGHT_SQUARE_BRACKET,
    COMBO_LEFT_CURLY_BRACKET,
    COMBO_RIGHT_CURLY_BRACKET,
    COMBO_LEFT_BRACKET,
    COMBO_RIGHT_BRACKET,
    COMBO_MINUS,
    COMBO_EQUALS,
    COMBO_LESS,
    COMBO_GREATER,
    COMBO_LESS_EQUALS,
    COMBO_GREATER_EQUALS,
    COMBO_LESS_EQUALS_EQUALS,
    COMBO_GREATER_EQUALS_EQUALS,
    COMBO_NOT_EQUALS,
    COMBO_NOT_EQUALS_EQUALS,
    COMBO_PIPE,
    COMBO_ASTARISK,
    COMBO_AMPERSTAND,
    COMBO_ROOT,
    COMBO_HASH,
    COMBO_ALT_F4,
    COMBO_BSPACE,
    COMBO_TAB,
};

const uint16_t PROGMEM combo_left_square_bracket[] = {KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM combo_right_square_bracket[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM combo_left_curly_bracket[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM combo_right_curly_bracket[] = {KC_L, KC_K, COMBO_END};
const uint16_t PROGMEM combo_left_bracket[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo_right_bracket[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_equals[] = {KC_9, KC_0, COMBO_END};
const uint16_t PROGMEM combo_minus[] = {KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM combo_less[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_greater[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_less_equals[] = {KC_F, KC_U, COMBO_END};
const uint16_t PROGMEM combo_greater_equals[] = {KC_F, KC_O, COMBO_END};
const uint16_t PROGMEM combo_less_equals_equals[] = {KC_F, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_greater_equals_equals[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM combo_not_equals[] = {KC_J, KC_A, COMBO_END};
const uint16_t PROGMEM combo_not_equals_equals[] = {KC_J, KC_S, COMBO_END};
const uint16_t PROGMEM combo_pipe[] = {KC_F, KC_I, COMBO_END};
const uint16_t PROGMEM combo_amperstand[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM combo_astarisk[] = {KC_F, KC_K, COMBO_END};
const uint16_t PROGMEM combo_root[] = {KC_F, KC_SCOLON, COMBO_END};
const uint16_t PROGMEM combo_hash[] = {KC_F, KC_H, COMBO_END};
const uint16_t PROGMEM combo_alt_f4[] = {KC_F, KC_4, COMBO_END};
const uint16_t PROGMEM combo_bspace[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_A, KC_S, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [COMBO_LEFT_SQUARE_BRACKET] = COMBO_ACTION(combo_left_square_bracket),
    [COMBO_RIGHT_SQUARE_BRACKET] = COMBO_ACTION(combo_right_square_bracket),
    [COMBO_LEFT_CURLY_BRACKET] = COMBO_ACTION(combo_left_curly_bracket),
    [COMBO_RIGHT_CURLY_BRACKET] = COMBO_ACTION(combo_right_curly_bracket),
    [COMBO_LEFT_BRACKET] = COMBO_ACTION(combo_left_bracket),
    [COMBO_RIGHT_BRACKET] = COMBO_ACTION(combo_right_bracket),
    [COMBO_MINUS] = COMBO_ACTION(combo_minus),
    [COMBO_EQUALS] = COMBO_ACTION(combo_equals),
    [COMBO_LESS] = COMBO_ACTION(combo_less),
    [COMBO_GREATER] = COMBO_ACTION(combo_greater),
    [COMBO_LESS_EQUALS] = COMBO_ACTION(combo_less_equals),
    [COMBO_GREATER_EQUALS] = COMBO_ACTION(combo_greater_equals),
    [COMBO_LESS_EQUALS_EQUALS] = COMBO_ACTION(combo_less_equals_equals),
    [COMBO_GREATER_EQUALS_EQUALS] = COMBO_ACTION(combo_greater_equals_equals),
    [COMBO_NOT_EQUALS] = COMBO_ACTION(combo_not_equals),
    [COMBO_NOT_EQUALS_EQUALS] = COMBO_ACTION(combo_not_equals_equals),
    [COMBO_PIPE] = COMBO_ACTION(combo_pipe),
    [COMBO_ASTARISK] = COMBO_ACTION(combo_astarisk),
    [COMBO_AMPERSTAND] = COMBO_ACTION(combo_amperstand),
    [COMBO_ROOT] = COMBO_ACTION(combo_root),
    [COMBO_HASH] = COMBO_ACTION(combo_hash),
    [COMBO_ALT_F4] = COMBO_ACTION(combo_alt_f4),
    [COMBO_BSPACE] = COMBO_ACTION(combo_bspace),
    [COMBO_TAB] = COMBO_ACTION(combo_tab),
};

void process_combo_event(uint16_t combo_index, bool pressed) {

        switch(combo_index) {
        case COMBO_LEFT_SQUARE_BRACKET:
            if (pressed) {
                register_code16(KC_LBRACKET);
            }else{
                unregister_code16(KC_LBRACKET);
            }
        break;
        case COMBO_RIGHT_SQUARE_BRACKET:
            if (pressed) {
                register_code16(KC_RBRACKET);
            }else{
                unregister_code16(KC_RBRACKET);
            }
        break;
        case COMBO_LEFT_CURLY_BRACKET:
            if (pressed) {
                register_code16(KC_LCBR);
            }else{
                unregister_code16(KC_LCBR);
            }
        break;
        case COMBO_RIGHT_CURLY_BRACKET:
            if (pressed) {
                register_code16(KC_RCBR);
            }else{
                unregister_code16(KC_RCBR);
            }
        break;
        case COMBO_LEFT_BRACKET:
            if (pressed) {
                register_code16(LSFT(KC_9));
            }else{
                unregister_code16(LSFT(KC_9));
            }
        break;
        case COMBO_RIGHT_BRACKET:
            if (pressed) {
                register_code16(LSFT(KC_0));
            }else{
                unregister_code16(LSFT(KC_0));
            }
        break;
        case COMBO_MINUS:
            if (pressed) {
                register_code16(KC_MINUS);
            }else{
                unregister_code16(KC_MINUS);
            }
        break;
        case COMBO_EQUALS:
            if (pressed) {
                register_code16(KC_EQUAL);
            }else{
                unregister_code16(KC_EQUAL);
            }
        break;
        case COMBO_LESS:
            if (pressed) {
                register_code16(KC_LABK);
            }else{
                unregister_code16(KC_LABK);
            }
        break;
        case COMBO_GREATER:
            if (pressed) {
                register_code16(KC_RABK);
            }else{
                unregister_code16(KC_RABK);
            }
        break;
        case COMBO_LESS_EQUALS:
            if (pressed) {
                tap_code16(KC_LABK);
                tap_code16(KC_EQUAL);
            }
        break;
        case COMBO_GREATER_EQUALS:
            if (pressed) {
                tap_code16(KC_RABK);
                tap_code16(KC_EQUAL);
            }
        break;
        case COMBO_LESS_EQUALS_EQUALS:
            if (pressed) {
                tap_code16(KC_LABK);
                tap_code16(KC_EQUAL);
                tap_code16(KC_EQUAL);
            }
        break;
        case COMBO_GREATER_EQUALS_EQUALS:
            if (pressed) {
                tap_code16(KC_RABK);
                tap_code16(KC_EQUAL);
                tap_code16(KC_EQUAL);
            }
        break;
        case COMBO_NOT_EQUALS:
            if (pressed) {
                tap_code16(KC_EXLM);
                tap_code16(KC_EQUAL);
            }
        break;
        case COMBO_NOT_EQUALS_EQUALS:
            if (pressed) {
                tap_code16(KC_EXLM);
                tap_code16(KC_EQUAL);
                tap_code16(KC_EQUAL);
            }
        break;
        case COMBO_PIPE:
            if (pressed) {
                register_code16(LSFT(KC_NONUS_BSLASH));
            }else{
                unregister_code16(LSFT(KC_NONUS_BSLASH));
            }
        break;
        case COMBO_ASTARISK:
            if (pressed) {
                register_code16(KC_ASTR);
            }else{
                unregister_code16(KC_ASTR);
            }
        break;
        case COMBO_AMPERSTAND:
            if (pressed) {
                register_code16(KC_AMPR);
            }else{
                unregister_code16(KC_AMPR);
            }
        break;
        case COMBO_ROOT:
            if (pressed) {
                register_code16(LSFT(KC_NONUS_HASH));
            }else{
                unregister_code16(LSFT(KC_NONUS_HASH));
            }
        break;
        case COMBO_HASH:
            if (pressed) {
                register_code16(KC_NONUS_HASH);
            }else{
                unregister_code16(KC_NONUS_HASH);
            }
        break;
        case COMBO_BSPACE:
            if (pressed) {
                register_code16(KC_BSPACE);
            }else{
                unregister_code16(KC_BSPACE);
            }
        break;
        case COMBO_TAB:
            if (pressed) {
                register_code16(KC_TAB);
            }else{
                unregister_code16(KC_TAB);
            }
        break;
        case COMBO_ALT_F4:
            if(pressed){
                tap_code16(LALT(KC_F4));
            }
        }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}



LEADER_EXTERNS();
int did_leader_succeed;

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    did_leader_succeed = leading = false;
    SEQ_ONE_KEY(KC_T) {
      SEND_STRING(SS_DOWN(X_LGUI)  SS_TAP(X_ENTER) SS_UP(X_LGUI)  SS_DELAY(1000) "timer ");
      did_leader_succeed = true;
    } else
    SEQ_TWO_KEYS(KC_B, KC_I) {
      SEND_STRING("https://www.bing.com/images/search?q=");
      did_leader_succeed = true;
    } else
    SEQ_TWO_KEYS(KC_T, KC_O) {
      SEND_STRING("10.0.0.69:19009" SS_TAP(X_ENTER) SS_DELAY(700) "pirate" SS_TAP(X_TAB));
      did_leader_succeed = true;
    } else
    SEQ_ONE_KEY(KC_C) {
      SEND_STRING("code ." SS_TAP(X_ENTER));
      did_leader_succeed = true;
    } else
    SEQ_ONE_KEY(KC_E) {
      SEND_STRING(SS_LSFT("'") "t80search_bot -t ");
      did_leader_succeed = true;
    } else
    SEQ_TWO_KEYS(KC_C, KC_O) {
      SEND_STRING("cd /media/veracrypt1/GIT/qmk_firmware && make clean && make artiomsu_tiny30:default");
      did_leader_succeed = true;
    } else
    SEQ_TWO_KEYS(KC_F, KC_L) {
      SEND_STRING("cd /media/veracrypt1/GIT/qmk_firmware && sudo avrdude -p atmega32u4 -P /dev/ttyACM0 -c avr109 -U flash:w:artiomsu_tiny30_default.hex");
      did_leader_succeed = true;
    }
    leader_end();
  }

}

void leader_start(void) {
    leader_key_is_running = true;
}

void leader_end(void) {
    leader_key_is_running = false;
}
