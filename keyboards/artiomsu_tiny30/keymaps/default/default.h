#ifndef DEFAULT_H
#define DEFAULT_H

#include "artiomsu_tiny30.h"

#define LCG_T(kc) MT(MOD_LCTL | MOD_LGUI, kc)                         // Left Control + GUI
#define LCSG_T(kc) MT(MOD_LCTL | MOD_LSFT | MOD_RGUI, kc)             // Left Control + Shift + GUI

#define Layer_main 0
#define Layer_symbols 1
#define Layer_nums 2
#define Layer_fkeys 3

extern bool did_leader_succeed;
extern bool leader_key_is_running;

#endif
