#include "default.h"

LEADER_EXTERNS();
bool did_leader_succeed;
bool leader_key_is_running = false;

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
