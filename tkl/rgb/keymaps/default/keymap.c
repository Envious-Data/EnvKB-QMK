/* Copyright 2022 Adam K (@Envious-Data)
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
#include "print.h"
#include "stdbool.h"
#include <stdio.h>

#define rgb_matrix_hsv_to_rgb hsv_to_rgb


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [0] = LAYOUT(
        KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SCRL, KC_PAUS,
	    
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_INS,  KC_HOME, KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_NO,   KC_DEL,  KC_END,  KC_PGDN,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,          KC_UP,
        KC_LCTL, KC_LWIN, KC_LALT,                   KC_SPC,                             KC_RALT, KC_RWIN,          MO(1),  KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT(
        QK_BOOTLOADER,    KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  KC_MUTE, KC_VOLD, KC_VOLU,
	    
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_MOD, RGB_SAI, RGB_VAI,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_MYCM, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_RMOD,RGB_SAD, RGB_VAD,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_TOG,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_CALCULATOR,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,          KC_TRNS,          RGB_SPI,
        KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                             KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, RGB_HUI, RGB_SPD, RGB_HUD
    ),
    [2] = LAYOUT(
        QK_BOOTLOADER,    KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  KC_MUTE, KC_VOLD, KC_VOLU,
	    
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_MOD, RGB_SAI, RGB_VAI,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_MYCM, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_RMOD,RGB_SAD, RGB_VAD,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_TOG,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_CALCULATOR,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,          KC_TRNS,          RGB_SPI,
        KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                             KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, RGB_HUI, RGB_SPD, RGB_HUD
    ),
    [3] = LAYOUT(
        QK_BOOTLOADER,    KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  KC_MUTE, KC_VOLD, KC_VOLU,
	    
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_MOD, RGB_SAI, RGB_VAI,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_MYCM, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_RMOD,RGB_SAD, RGB_VAD,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_TOG,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_CALCULATOR,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,          KC_TRNS,          RGB_SPI,
        KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                             KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, RGB_HUI, RGB_SPD, RGB_HUD
    )
};



void suspend_power_down_user(void) {
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_user(void) {
    rgb_matrix_set_suspend_state(false);
}

/*
void rgb_matrix_indicators_kb(void) {
	switch (biton32(layer_state)) {
		case 1:
			rgb_matrix_set_color(83, 16, 16, 16);
		default:
	}
}
*/


void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
	if (host_keyboard_led_state().caps_lock) {
		RGB_MATRIX_INDICATOR_SET_COLOR(50, 16, 16, 16); // assuming caps lock is at led #50
	}    
	if (host_keyboard_led_state().scroll_lock) {
		RGB_MATRIX_INDICATOR_SET_COLOR(14, 16, 16, 16); // assuming caps lock is at led #14
	}
	if (get_highest_layer(layer_state) == 1) {
		RGB_MATRIX_INDICATOR_SET_COLOR(83, 16, 16 ,16);
	}
}

