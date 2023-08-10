/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once


#define MK_3_SPEED
#define MK_W_OFFSET_UNMOD 1
#define MK_W_INTERVAL_UNMOD 20

#define MK_C_OFFSET_UNMOD 10 //Cursor offset per movement (unmodified)
#define MK_C_INTERVAL_UNMOD 16 //Time between cursor movements (unmodified)
#define MK_C_OFFSET_0 2 //Cursor offset per movement (KC_ACL0)
#define MK_C_INTERVAL_0	16 //Time between cursor movements (KC_ACL0)
#define MK_C_OFFSET_1 10 //Cursor offset per movement (KC_ACL1)
#define MK_C_INTERVAL_1	16 //Time between cursor movements (KC_ACL1)
#define MK_C_OFFSET_2 32 //Cursor offset per movement (KC_ACL2)
#define MK_C_INTERVAL_2	16 //Time between cursor movements (KC_ACL2)


// my defines

//#define BACKLIGHT_BREATHING
//#define BREATHING_PERIOD 6
#undef NO_DEBUG
#define NO_DEBUG

#undef NO_PRINT
#define NO_PRINT

// force nkro
//#define FORCE_NKRO

// Leader key defines
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 500

//combos
//#define COMBO_COUNT 26
#define COMBO_COUNT 24
#define COMBO_TERM 30
//#define EXTRA_EXTRA_LONG_COMBOS

//dynamic macros. 128 is default but we don't have not enough ram
//#define DYNAMIC_MACRO_NO_NESTING
//#define DYNAMIC_MACRO_SIZE 64

#define CAPS_WORD_IDLE_TIMEOUT 3000  // https://docs.qmk.fm/#/feature_caps_word?id=customizing-caps-word

//#define COMBOS_WORKING // uncomment this when combos are working
