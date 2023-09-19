#include "sharedDefines.h"

// for the calculator functionality
int input_count = 0;                            // stores the amount of the filled in expressions_buffer.
char expressions_buffer[EXPRESSIONS_BUFF_SIZE]; // stores the typed out string
//expressions_buffer[0] = '\0';
int decimal_point_pressision = 2;               // how many decimal points to show by default, can be changed via macros bellow.


double te_interp(const char *expression, int *error);

void write_char_to_buff(char c);

char *dtostrf(double val, signed char width, unsigned char prec, char *sout);

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
                // todo add decimal precision
                //sprintf(output_string, "%1.5f", result);
                //sprintf(output_string, "hello there %f", result);
                //snprintf(output_string, sizeof(output_string)*EXPRESSIONS_BUFF_SIZE, "%f", result);
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
        case L1_EXIT_LAYER:
            if(record->event.pressed){
                input_count = 0;
                expressions_buffer[0] = '\0';
                layer_move(Layer_main);
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

// pico doesn't have this se we need to steal it
char *dtostrf(double val, signed char width, unsigned char prec, char *sout)
{
  //Commented code is the original version
  /*char fmt[20];
  sprintf(fmt, "%%%d.%df", width, prec);
  sprintf(sout, fmt, val);
  return sout;*/

  // Handle negative numbers
  uint8_t negative = 0;
  if (val < 0.0) {
    negative = 1;
    val = -val;
  }

  // Round correctly so that print(1.999, 2) prints as "2.00"
  double rounding = 0.5;
  for (int i = 0; i < prec; ++i) {
    rounding /= 10.0;
  }

  val += rounding;

  // Extract the integer part of the number
  unsigned long int_part = (unsigned long)val;
  double remainder = val - (double)int_part;

  if (prec > 0) {
    // Extract digits from the remainder
    unsigned long dec_part = 0;
    double decade = 1.0;
    for (int i = 0; i < prec; i++) {
      decade *= 10.0;
    }
    remainder *= decade;
    dec_part = (int)remainder;

    if (negative) {
      sprintf(sout, "-%ld.%0*ld", int_part, prec, dec_part);
    } else {
      sprintf(sout, "%ld.%0*ld", int_part, prec, dec_part);
    }
  } else {
    if (negative) {
      sprintf(sout, "-%ld", int_part);
    } else {
      sprintf(sout, "%ld", int_part);
    }
  }
  // Handle minimum field width of the output string
  // width is signed value, negative for left adjustment.
  // Range -128,127
  char fmt[129] = "";
  unsigned int w = width;
  if (width < 0) {
    negative = 1;
    w = -width;
  } else {
    negative = 0;
  }

  if (strlen(sout) < w) {
    memset(fmt, ' ', 128);
    fmt[w - strlen(sout)] = '\0';
    if (negative == 0) {
      char *tmp = malloc(strlen(sout) + 1);
      strcpy(tmp, sout);
      strcpy(sout, fmt);
      strcat(sout, tmp);
      free(tmp);
    } else {
      // left adjustment
      strcat(sout, fmt);
    }
  }

  return sout;
}
