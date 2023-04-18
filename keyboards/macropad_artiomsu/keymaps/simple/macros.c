#include "sharedDefines.h"

// for the calculator functionality
#define EXPRESSIONS_BUFF_SIZE 64
int input_count = 0;                            // stores the amount of the filled in expressions_buffer.
char expressions_buffer[EXPRESSIONS_BUFF_SIZE]; // stores the typed out string
int decimal_point_pressision = 2;               // how many decimal points to show by default, can be changed via macros bellow.

bool enable_num_lock_animation = true;  // play the numlock animation, toggled through macro.


double te_interp(const char *expression, int *error);

void write_char_to_buff(char c);

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
                SEND_STRING("cd /temp/GIT/qmk_firmware && make clean && make macropad_artiomsu:simple");
            }
            break;
        case FLASH_MACRO:
            if(record->event.pressed){
                SEND_STRING("cd /temp/GIT/qmk_firmware && sudo avrdude -p atmega32u4 -P /dev/ttyACM0 -c avr109 -U flash:w:macropad_artiomsu_simple.hex");
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
