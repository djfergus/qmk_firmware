#ifndef SHAREDDEFINES_H
#define SHAREDDEFINES_H

#include QMK_KEYBOARD_H

#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include <math.h>

#define Layer_main 0
#define Layer_shortcuts 1
#define Layer_calc 2

#define EXPRESSIONS_BUFF_SIZE 64
extern char expressions_buffer[EXPRESSIONS_BUFF_SIZE];
extern int decimal_point_pressision;

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
    L1_EXIT_LAYER,
    //other
    FLASH_MACRO,
};

#endif
