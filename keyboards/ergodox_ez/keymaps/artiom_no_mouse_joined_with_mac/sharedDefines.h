#ifndef SHAREDDEFINES_H
#define SHAREDDEFINES_H

#include QMK_KEYBOARD_H
#include "version.h"
#include "secrets.h"

#define bool _Bool
#define true 1
#define false 0

// layer defines
/*
    Layers accessing other layers must be under the layer that they access.
    For example, if layer 1 is accessing layer 2, layer 2 must be after layer 1.
*/
#define Layer_main 0
#define Layer_mac_main 1
#define Layer_colemak 2
#define Layer_symbols 3
#define Layer_mac_symbols 4
#define Layer_macros 5
#define Layer_gaming 6
#define Layer_mouse 7

// layer Colours since they are different from layers themselves now
#define Layer_main_colour 0
#define Layer_symbols_colour 1
#define Layer_macros_colour 2
#define Layer_gaming_colour 3


enum custom_keycodes {
  //RGB_SLD = EZ_SAFE_RANGE, // do not remove this one otherwise keyboard will send random keycodes.
  RGB_SLD = SAFE_RANGE, // do not remove this one otherwise keyboard will send random keycodes.
  ST_MACRO_SSH,
  ST_MACRO_VIM_wq,
  ST_M_n_equal,
  ST_M_n_equal_2,
  ST_M_l_equal,
  ST_M_g_equal,
  ST_M_vim_q,
  ST_M_vim_w,
  ST_M_vim_sp,
  ST_M_vim_vs,
  ST_M_vim_sp_e,
  ST_M_vim_vs_e,
  ST_M_double_colon,
  ST_M_bunny_hop,
  ST_M_enable_bunny_hop,
  ST_M_brightness_down,
  ST_M_brightness_up,
  ST_M_hue_down,
  ST_M_hue_up,
  ST_M_toggle_main_layer_brightness,
  ST_M_led_timeout_30s,
  ST_M_led_timeout_1m,
  ST_M_led_timeout_5m,
  ST_M_led_timeout_10m,
  ST_M_combo_toggle,
  ST_M_mac_mode_toggle,
  ST_M_colemak_mode_toggle,
  ST_M_password_bypass,
};

extern bool rgb_show;
extern bool rgb_timed_out;
extern uint32_t rgb_timeout_counter;
//extern uint16_t rgb_sync_to_timer; //sync out timer to the official rgb timer.
extern uint32_t rgb_time_out_value;  // in milliseconds

extern bool use_bunnyhop;
extern bool enable_bunnyhop;
extern uint8_t bunny_hop_delay_counter;

extern uint8_t modifiers_blink_count; // this is for stuff like enable_bunnyhop and the leader key
extern bool leader_key_is_running;

extern int8_t brightness_amount;
extern uint8_t hue_amount;

extern bool main_layer_brightness; // can disable the main layer rgb individually

extern bool combos_on; // use combo feature by default
extern bool mac_mode;

//extern int word_length_count;
//extern int last_word_length;

//do not change the following
extern bool use_default_lighting; // do not change used inside loop
extern bool g_suspend_state;

extern bool scrollwheel_up_on;
extern bool scrollwheel_down_on;
extern uint16_t scroll_delay_timer;

extern bool colemak_mode;


//custom password to use keyboard
//#error "Change the password before compiling and commment this line out"
/*
    To make this work you need to create a file called secrets.c and secrets.h

    In secrets.h you need to define the following:
    ----------------------------------------------
    #ifndef SECRETSDEFINES_H
    #define SECRETSDEFINES_H

    #define UNLOCK_PASSWORD_LENGTH 2

    #endif
    ----------------------------------------------

    In secrets.c you need to define the following:
    ----------------------------------------------
    #include "secrets.h"

    uint16_t unlock_password[UNLOCK_PASSWORD_LENGTH] = {4, 5}; // example a, b
    ----------------------------------------------

    To get the keycodes check this following link:
    https://gist.github.com/MightyPork/6da26e382a7ad91b5496ee55fdc73db2
*/

extern uint16_t unlock_password_index;
extern uint16_t unlock_password[UNLOCK_PASSWORD_LENGTH];

extern bool password_bypass;

/*
if the `#define SHOW_UNLOCK_ANIMATION` line is uncommented, the keyboard will light up an led for each correct key press. Might want to turn this off as it will be possible to guess the password eventually since you will know when you hit a correct letter.
*/
#define SHOW_UNLOCK_ANIMATION

extern bool caps_lock_on;
extern bool num_lock_on;

//alternative colour scheme
//#define COLORPROGKEYBOARD

//colours                   hsv             // rgb
#define L_KM_Light_red        {0, 0,223,252}     // 252,32,31
#define L_KM_Light_yellow     {0, 31,208,234}    // 234,181,42
#define L_KM_dirty_green      {0, 97,231,230}    // 21,230,76
#define L_LM_golden_yellow    {0, 32,191,236}    // 236,191,59
#define L_LM_Slight_dark_red  {0, 255,246,238}   //238,8,23
#define L_LM_Blue             {0, 166,240,228}   //13,41,228
#define L_LM_LightBlue        {0, 150,255,204}   //0,102,204
#define L_LM_DarkerBlue       {0, 150,255,102}   //0,51,102
#define L_LM_LightOrange      {0, 0,183,238}     //238,67,66
#define L_LM_Cyan             {0, 130,255,255}   //0,249,255
#define L_LM_Yellow           {0, 42,248,240}    //240,237,6
#define L_LM_______           {0, 0,0,0}         //no colour
#define L_LM_Light_pink       {0, 216,123,238}   // 238,122,235
#define L_LM_White            {0, 0,0,255}       // 255,255,255
#define L_LM_Red_Blood        {0, 6,240,224}     // 224,43,13
#define L_LM_NeonGreen        {0, 82,247,246}    // 28,246,7
#define L_LM_LighterBlue      {0, 178,231,238}   // 53,22,238
#define L_LM_darker_Yellow    {0, 36,230,248}    // 248,213,24
#define L_LM_Light_orange     {0, 31,255,255}    // 255,186,0
#define L_LM_Blooder_Red      {0, 0,242,205}     // 205,11,10
#define L_LM_LightBrown       {0, 19,150,185}    // 185,125,75
#define L_LM_Orange           {0, 13,237,253}    // 253,90,17
#define L_LM_skyBlue          {0, 124,62,253}    // 190,253,246
#define L_LM_Toirquise        {0, 115,255,248}   // 0,248,169
#define L_LM_Purple           {0, 195,255,251}   // 136,0,251
#define L_LM_Light_blue_purple {0, 178,183,238}   // 92,66,238

#define R_KM_Light_red        {1, 0,223,252}     // 252,32,31
#define R_KM_Light_yellow     {1, 31,208,234}    // 234,181,42
#define R_KM_dirty_green      {1, 97,231,230}    // 21,230,76
#define R_LM_golden_yellow    {1, 32,191,236}    // 236,191,59
#define R_LM_Slight_dark_red  {1, 255,246,238}   //238,8,23
#define R_LM_Blue             {1, 166,240,228}   //13,41,228
#define R_LM_LightBlue        {1, 150,255,204}   //0,102,204
#define R_LM_DarkerBlue       {1, 150,255,102}   //0,51,102
#define R_LM_LightOrange      {1, 0,183,238}     //238,67,66
#define R_LM_Cyan             {1, 130,255,255}   //0,249,255
#define R_LM_Yellow           {1, 42,248,240}    //240,237,6
#define R_LM_______           {1, 0,0,0}         //no colour
#define R_LM_Light_pink       {1, 216,123,238}   // 238,122,235
#define R_LM_White            {1, 0,0,255}       // 255,255,255
#define R_LM_Red_Blood        {1, 6,240,224}     // 224,43,13
#define R_LM_NeonGreen        {1, 82,247,246}    // 28,246,7
#define R_LM_LighterBlue      {1, 178,231,238}   // 53,22,238
#define R_LM_darker_Yellow    {1, 36,230,248}    // 248,213,24
#define R_LM_Light_orange     {1, 31,255,255}    // 255,186,0
#define R_LM_Blooder_Red      {1, 0,242,205}     // 205,11,10
#define R_LM_LightBrown       {1, 19,150,185}    // 185,125,75
#define R_LM_Orange           {1, 13,237,253}    // 253,90,17
#define R_LM_skyBlue          {1, 124,62,253}    // 190,253,246
#define R_LM_Toirquise        {1, 115,255,248}   // 0,248,169
#define R_LM_Purple           {1, 195,255,251}   // 136,0,251
#define R_LM_Light_blue_purple {1, 178,183,238}   // 92,66,238

#define L_KM_TEST {0,214,253,245} //pink
#define R_KM_TEST {1,214,253,245} //pink

#endif
