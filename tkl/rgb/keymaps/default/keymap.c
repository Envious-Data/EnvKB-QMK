/* Copyright 2021 sekigon-gonnoc
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
//#include "pico_eeprom.h"
//#include "print.h"
#include "rgblight.h"
#ifdef RGB_MATRIX_ENABLE
#    include "rgb_bits.h"
#endif


void keyboard_post_init_user(void) {
// Customise these values to desired behaviour
 debug_enable=true;
 debug_matrix=true;
 debug_keyboard=true;
 debug_mouse=true;
 //memset(&user_state, 0, sizeof(user_state));
}


//#define _BASE 0
//#define _DVORAK 1
//#define _FN 2
//#define _ADJUST 3
//#define _CAPSLOCK 4
//#define _SCROLLLOCK 5

//#define BLINK_DURATION 150
//uint16_t rgb_blink_timer = 0;
#define rgb_matrix_hsv_to_rgb hsv_to_rgb


enum layer_names {
    _BASE,
	_DVORAK,
    _FN,
    _ADJUST,
    _CAPSLOCK,
    _SCROLLLOCK
};

/*
void rgb_check_blinking(uint8_t led_start, uint8_t led_end) {
    if (is_keyboard_master()) {
        if (rgb_blink_timer > 0) {
            if (timer_elapsed(rgb_blink_timer) > AUTO_SHIFT_TIMEOUT) {
                user_state.blinking = true;
                for (uint8_t i = led_start; i < led_end + 1; i++) {
#ifdef RGB_MATRIX_ENABLE
                    rgb_matrix_set_color(i, 0, 0, 0);
#endif
#ifdef RGBLIGHT_ENABLE
                    rgblight_setrgb_at(0, 0, 0, i);
#endif
                }
                if (timer_elapsed(rgb_blink_timer) - AUTO_SHIFT_TIMEOUT > BLINK_DURATION) {
                    rgb_blink_timer     = 0;
                    user_state.blinking = false;
                }
            }
        }
    } else {
        if (user_state.blinking) {
            for (uint8_t i = led_start; i < led_end + 1; i++) {
#ifdef RGB_MATRIX_ENABLE
                rgb_matrix_set_color(i, 0, 0, 0);
#endif
#ifdef RGBLIGHT_ENABLE
                rgblight_setrgb_at(0, 0, 0, i);
#endif
            }
        }
    }
}
*/
#ifdef RGB_MATRIX_ENABLE
void rgb_show_layer(uint8_t led_min, uint8_t led_max) {
    switch (get_highest_layer(layer_state)) {
        case _SCROLLLOCK:
            return;
        default:
            break;
    }

    for (uint8_t i = led_min; i < led_max; i++) {
        if (rgb_matrix_led_index_has_pos(i)) {
            uint16_t kc  = pgm_read_word(&keymaps[get_highest_layer(layer_state)][led_position[i].row][led_position[i].col]);
            uint8_t  hue = 0;
            uint8_t  val = rgb_matrix_get_val();
            switch (get_highest_layer(layer_state)) {
                default:
                    switch (kc) {
                        case KC_F1 ... KC_F12:
                            hue = ((kc - KC_1) * 28) % 255;
                            break;
                        default:
                            val = 0;
                            break;
                    }
                    break;
            }
            HSV hsv = {.h = hue, .s = 255, .v = val};
            RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
            rgb_matrix_set_color(g_led_config.matrix_co[led_position[i].row][led_position[i].col], rgb.r, rgb.g, rgb.b);
        }
    }
}

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    rgb_show_layer(led_min, led_max);
    //rgb_check_blinking(led_min, led_max);
}
#endif

/*
void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_CAPS:
            break;
    }
}
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, KC_PAUS,
	    
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_INS,  KC_HOME, KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_NO,   KC_DEL,  KC_END,  KC_PGDN,
        LT(4, KC_CAPS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,          KC_UP,
        KC_LCTL, KC_LWIN, KC_LALT,                   KC_SPC,                             KC_RALT, KC_RWIN,          MO(2),  KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_DVORAK] = LAYOUT(
        KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	    
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                            KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_FN] = LAYOUT(
        KC_TRNS,          KC_F13,   KC_F14, KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  KC_MUTE, KC_VOLD, KC_VOLU,
	    
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_MOD, RGB_SAI, RGB_VAI,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_MYCM, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_RMOD,RGB_SAD, RGB_VAD,
        KC_TRNS, KC_TRNS, KC_TRNS, DEBUG,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_TOG,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_CALCULATOR,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,          KC_TRNS,          RGB_SPI,
        KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                             KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, RGB_HUI, RGB_SPD, RGB_HUD
    ),
    [_ADJUST] = LAYOUT(
        KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	    
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                            KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_CAPSLOCK] = LAYOUT(
        KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	    
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                            KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_SCROLLLOCK] = LAYOUT(
        KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	    
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                            KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
};
	

//
// SOME OF THIS CODE DOESNT WORK BECAUSE: 
//
//uint8_t keyboard_leds(void) {
//    // TODO
//    return 0;
//}
//
/*
// 
const rgblight_segment_t PROGMEM my_layer0_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_BLUE}       //  starting with LED 6, Light 4 LEDs
);
// 
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_BLUE}
);
// FN Key LED layer thing
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {83, 1, HSV_BLUE}
);
// 
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_BLUE}
);
// Capslock doot
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {50, 1, HSV_BLUE}
);
// 
const rgblight_segment_t PROGMEM my_layer5_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_BLUE}
);
// etc..

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layer0_layer,
    my_layer1_layer,    // Overrides caps lock layer
    my_layer2_layer,    // Overrides other layers
    my_layer3_layer,    // Overrides other layers
    my_layer4_layer,    // Overrides other layers
	my_layer5_layer     // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _DVORAK));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(2, layer_state_cmp(state, _FN));
    rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
	rgblight_set_layer_state(4, layer_state_cmp(state, _CAPSLOCK));
    return state;
}
*/