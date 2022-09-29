#ifndef SHAREDDEFINES_H
#define SHAREDDEFINES_H

#include "macropad_artiomsu.h"
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
#include <string.h>
//#include <limits.h>

#define LED_BLUE_ON writePinHigh(F4);
#define LED_GREEN_ON writePinHigh(F5);
#define LED_RED_ON writePinHigh(F6);
#define LED_WHITE_ON writePinHigh(F7);
#define LED_ORANGE_ON writePinHigh(D1);

#define LED_BLUE_OFF writePinLow(F4);
#define LED_GREEN_OFF writePinLow(F5);
#define LED_RED_OFF writePinLow(F6);
#define LED_WHITE_OFF writePinLow(F7);
#define LED_ORANGE_OFF writePinLow(D1);

#define LED_ALL_OFF writePinLow(F4); writePinLow(F5); writePinLow(F6); writePinLow(F7); writePinLow(D1);

#define Layer_main 0
#define Layer_shortcuts 1
#define Layer_calc 2
#define Layer_extra 3

enum custom_keycodes {
    // for the calc layer
    L1_1 = SAFE_RANGE,
    L1_2,
    L1_3,
    L1_4,
    L1_5,
    L1_6,
    L1_7,
    L1_8,
    L1_9,
    L1_0,
    L1_SLASH,
    L1_MULTIPLY,
    L1_MINUS,
    L1_PLUS,
    L1_EQUALS,
    L1_DOT,
    L1_PRINT_EQUATION,
    L1_POWER,
    L1_MOD,
    L1_PRECISION_MINUS,
    L1_PRECISION_PLUS,
    L1_EXIT_LAYER,
    //other
    COMPILE_MACRO,
    FLASH_MACRO,
    TOGGLE_NUM_LOCK_ANIMATION,
};

extern bool enable_num_lock_animation;

#endif
