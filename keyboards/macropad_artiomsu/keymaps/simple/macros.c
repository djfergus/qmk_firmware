#include "sharedDefines.h"

// for the calculator functionality
#define EXPRESSIONS_BUFF_SIZE 64
int input_count = 0;                            // stores the amount of the filled in expressions_buffer.
char expressions_buffer[EXPRESSIONS_BUFF_SIZE]; // stores the typed out string
int decimal_point_pressision = 2;               // how many decimal points to show by default, can be changed via macros bellow.

bool enable_num_lock_animation = true;  // play the numlock animation, toggled through macro.

struct rlShiet{
    char *text;
    bool team;
};

struct rlShiet rlShiet_arr[] = {
    { "WHAT A SAVE!!!!!!", false},
    { "WHAT A SHOT!!!!!!", false},
    { "AWESOME PASS!!!!!", false},
    { "OOPs My Bad :(", false},

    { "Take the shot :)", true},
    { "I got it my son", true},
    { "Centering the boi ;)", true},
    { "Passing to you", true},

    { "On your Left ;)", true},
    { "Behind you ;)", true},
    { "Demoing Goalie", true},
    { "On your Right ;)", true},

    { "Taking Boost", true},
    { "All yours :O", true},
    { "Hold up need to take a piss", false},
    { "Hold up need to take a shiet", false},

    { "Need Sum Booost", true},
    { "y u so mad bro?", false},
    { "Its just a game bro", false}
};

double te_interp(const char *expression, int *error);

void write_char_to_buff(char c);

void rl2(int n){
    rlShiet_arr[n].team ? tap_code(KC_Y) : tap_code(KC_T);
    _delay_ms(100);
    send_string(rlShiet_arr[n].text);
    tap_code(KC_ENTER);
    tap_code(KC_ENTER);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L1_1:
            if (record->event.pressed) {
                write_char_to_buff('1');
            }
            break;
        case L1_2:
            if (record->event.pressed) {
                write_char_to_buff('2');
            }
            break;
        case L1_3:
            if (record->event.pressed) {
                write_char_to_buff('3');
            }
            break;
        case L1_4:
            if (record->event.pressed) {
                write_char_to_buff('4');
            }
            break;
        case L1_5:
            if (record->event.pressed) {
                write_char_to_buff('5');
            }
            break;
        case L1_6:
            if (record->event.pressed) {
                write_char_to_buff('6');
            }
            break;
        case L1_7:
            if (record->event.pressed) {
                write_char_to_buff('7');
            }
            break;
        case L1_8:
            if (record->event.pressed) {
                write_char_to_buff('8');
            }
            break;
        case L1_9:
            if (record->event.pressed) {
                write_char_to_buff('9');
            }
            break;
        case L1_0:
            if (record->event.pressed) {
                write_char_to_buff('0');
            }
            break;
        case L1_PLUS:
            if (record->event.pressed) {
                write_char_to_buff('+');
            }
            break;
        case L1_MINUS:
            if (record->event.pressed) {
                write_char_to_buff('-');
            }
            break;
        case L1_MULTIPLY:
            if (record->event.pressed) {
                write_char_to_buff('*');
            }
            break;
        case L1_SLASH:
            if (record->event.pressed) {
                write_char_to_buff('/');
            }
            break;
        case L1_DOT:
            if (record->event.pressed) {
                write_char_to_buff('.');
            }
            break;
        case L1_POWER:
            if (record->event.pressed) {
                write_char_to_buff('^');
            }
            break;
        case L1_MOD:
            if (record->event.pressed) {
                write_char_to_buff('%');
            }
            break;
        case L1_EQUALS:
            if (record->event.pressed) {
                double result = te_interp(expressions_buffer, 0);
                char output_string[EXPRESSIONS_BUFF_SIZE];

                dtostrf(result, 1, decimal_point_pressision, output_string);
                send_string(output_string);
                input_count = 0;
            }
            break;
        case L1_PRINT_EQUATION:
            if (record->event.pressed) {
                if(input_count>0){
                    send_string(expressions_buffer);
                }
            }
            break;
        case L1_PRECISION_MINUS:
            if (record->event.pressed) {
                if(decimal_point_pressision > 0){
                    decimal_point_pressision--;
                }
            }
            break;
        case L1_PRECISION_PLUS:
            if (record->event.pressed) {
                if(decimal_point_pressision < 10){
                    decimal_point_pressision++;
                }
            }
            break;
        case L1_EXIT_LAYER:
            if(record->event.pressed){
                input_count = 0;
                expressions_buffer[0] = '\0';
                layer_move(Layer_main);
            }
            break;
        case COMPILE_MACRO:
            if(record->event.pressed){
                SEND_STRING("cd /media/veracrypt1/GIT/qmk_firmware && make clean && make macropad_artiomsu:simple && sudo avrdude -p atmega32u4 -P /dev/ttyACM0 -c avr109 -U flash:w:macropad_artiomsu_simple.hex");
            }
            break;
        case G1:
            if(record->event.pressed){
                rl2(0);
            }
            break;
        case G2:
            if(record->event.pressed){
                rl2(1);
            }
            break;
        case G3:
            if(record->event.pressed){
                rl2(2);
            }
            break;
        case G4:
            if(record->event.pressed){
                rl2(3);
            }
            break;
        case G5:
            if(record->event.pressed){
                rl2(4);
            }
            break;
        case G6:
            if(record->event.pressed){
                rl2(5);
            }
            break;
        case G7:
            if(record->event.pressed){
                rl2(6);
            }
            break;
        case G8:
            if(record->event.pressed){
                rl2(7);
            }
            break;
        case G9:
            if(record->event.pressed){
                rl2(8);
            }
            break;
        case G10:
            if(record->event.pressed){
                rl2(9);
            }
            break;
        case G11:
            if(record->event.pressed){
                rl2(10);
            }
            break;
        case G12:
            if(record->event.pressed){
                rl2(11);
            }
            break;
        case G13:
            if(record->event.pressed){
                rl2(12);
            }
            break;
        case G14:
            if(record->event.pressed){
                 rl2(13);
            }
            break;
        case G15:
            if(record->event.pressed){
                 rl2(14);
            }
            break;
        case G16:
            if(record->event.pressed){
                 rl2(15);
            }
            break;
        case G17:
            if(record->event.pressed){
                 rl2(16);
            }
            break;
        case G18:
            if(record->event.pressed){
                 rl2(17);
            }
            break;
        case G19:
            if(record->event.pressed){
                 rl2(18);
            }
            break;
        case TOGGLE_NUM_LOCK_ANIMATION:
            if(record->event.pressed){
                enable_num_lock_animation=!enable_num_lock_animation;
            }
            break;
    }
	return true;
}


void write_char_to_buff(char c){
    if(input_count+1 < EXPRESSIONS_BUFF_SIZE){
        expressions_buffer[input_count] = c;
        expressions_buffer[input_count+1] = '\0';
        input_count++;
    }
}
