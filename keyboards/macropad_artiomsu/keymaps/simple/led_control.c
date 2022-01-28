#include "sharedDefines.h"

// for the numlock and layer leds
bool num_lock_led_is_on = false;        // if numlock should be on
int led_state_current = 0;              // what is the current layer temp
bool num_lock_triggered = false;        // was the numlock pressed
int last_led_state_current = 0;         // the latest current layer

int count_delay = 0;                    // counter for numlock animation
int count_delay_max = 500;              // delay for which the lights change
int count_current_led = 0;              // which led to light up
int count_num_leds = 4;                 // total number of leds starting at 0
bool led_direction_left = true;         // animation direction of the leds

void matrix_scan_user(void) {
    if(led_state_current != -1 || num_lock_triggered){
        if(!num_lock_triggered){
            last_led_state_current = led_state_current;
            switch (led_state_current)
                {
                    case Layer_shortcuts:
                        LED_ALL_OFF
                        LED_BLUE_ON
                        break;
                    case Layer_calc:
                        LED_ALL_OFF
                        LED_GREEN_ON
                        break;
                    case Layer_extra:
                        LED_ALL_OFF
                        LED_RED_ON
                        break;
                    case Layer_main:
                        LED_ALL_OFF
                        break;
                }
            led_state_current = -1;
        }else{
            num_lock_triggered = false;
        }
    }

    if(last_led_state_current == Layer_main && num_lock_led_is_on && enable_num_lock_animation){
        if(count_delay >= count_delay_max){
            count_delay = 0;
            LED_ALL_OFF
            switch (count_current_led){
                case 0:
                    LED_BLUE_ON
                    break;
                case 1:
                    LED_GREEN_ON
                    break;
                case 2:
                    LED_RED_ON
                    break;
                case 3:
                    LED_WHITE_ON
                    break;
                case 4:
                    LED_ORANGE_ON
                    break;

                default:
                    break;
            }
            if(led_direction_left){
                count_current_led--;
                if(count_current_led < 0){
                    count_current_led = 1;
                    led_direction_left = false;
                }
            }else{
                count_current_led++;
                if(count_current_led > count_num_leds){
                    count_current_led = count_num_leds - 1;
                    led_direction_left = true;
                }
            }

        }
        count_delay++;
    }
}
// small leg goes to ground
void keyboard_pre_init_user(void) {
    setPinOutput(F4);
    setPinOutput(F5);
    setPinOutput(F6);
    setPinOutput(F7);
    setPinOutput(D1);
}


bool led_update_user(led_t led_state) {
    num_lock_led_is_on = led_state.num_lock;
    if(led_state.num_lock){
        num_lock_led_is_on = true;
        num_lock_triggered = true;
    }else{
        if(last_led_state_current == Layer_main){
            LED_ALL_OFF
        }
        num_lock_led_is_on = false;
        num_lock_triggered = true;
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    led_state_current = get_highest_layer(state);
    return state;
}
