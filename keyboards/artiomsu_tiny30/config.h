#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    artiomsu
#define PRODUCT         artiomsu_tiny30
#define DESCRIPTION     Artiomsu Tiny30

/* key matrix size */
#define MATRIX_ROWS 3
#define MATRIX_COLS 10

/* key matrix pins */
#define MATRIX_ROW_PINS { F4, F5, F6 }
//#define MATRIX_COL_PINS { F7, B1, B3, B2, B6, B5, B4, E6, D7, C6 }
#define MATRIX_COL_PINS { C6, D7, E6, B4, B5, B6, B2, B3, B1, F7 }

#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define DEBOUNCING_DELAY 5


/* key combination for command */
//#define IS_COMMAND() ( keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) )

/* prevent stuck modifiers */
#define PREVENT_STUCK_MODIFIERS

#endif
