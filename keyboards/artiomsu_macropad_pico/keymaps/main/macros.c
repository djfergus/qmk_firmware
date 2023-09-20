#include "sharedDefines.h"

// for the calculator functionality
int input_count = 0;                            // stores the amount of the filled in expressions_buffer.
char expressions_buffer[EXPRESSIONS_BUFF_SIZE]; // stores the typed out string
//expressions_buffer[0] = '\0';
int decimal_point_pressision = 2;               // how many decimal points to show by default, can be changed via macros bellow.


double te_interp(const char *expression, int *error);

void delete_char_from_buff(void);

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
                //if(input_count>0){
                if(expressions_buffer[0] != '\0'){
                    send_string(expressions_buffer);
                }
            }
            break;
        case L1_EXIT_LAYER:
            if(record->event.pressed){
                //input_count = 0; // don't reset to keep history
                //expressions_buffer[0] = '\0';
                layer_move(Layer_main);
            }
            break;
        case L1_DELETE:
            if (record->event.pressed) {
                if(input_count > 0){
                    delete_char_from_buff();
                }
            }
            break;
        case FLASH_MACRO:
            if(record->event.pressed){
                SEND_STRING("cd /temp/GIT/qmk_firmware && make clean && qmk flash -kb artiomsu_macropad_pico -km main");
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

void delete_char_from_buff(void){
    if(input_count > 0){
        input_count--;
        expressions_buffer[input_count] = '\0';
    }
}

