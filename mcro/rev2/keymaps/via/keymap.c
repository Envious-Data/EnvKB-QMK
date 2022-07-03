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


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [0] = {
        {KC_F13, KC_F14, KC_F15, KC_F16, KC_NO},
        {KC_F17, KC_F18, KC_F19, KC_F20, KC_NO},
        {KC_F21, KC_F22, KC_F23, KC_F24, KC_NO},
    },
    [1] = {
        {KC_F13, KC_F14, KC_F15, KC_F16, KC_NO},
        {KC_F17, KC_F18, KC_F19, KC_F20, KC_NO},
        {KC_F21, KC_F22, KC_F23, KC_F24, KC_NO},
    },
    [2] = {
        {KC_F13, KC_F14, KC_F15, KC_F16, KC_NO},
        {KC_F17, KC_F18, KC_F19, KC_F20, KC_NO},
        {KC_F21, KC_F22, KC_F23, KC_F24, KC_NO},
    },
    [3] = {
        {KC_F13, KC_F14, KC_F15, KC_F16, KC_NO},
        {KC_F17, KC_F18, KC_F19, KC_F20, KC_NO},
        {KC_F21, KC_F22, KC_F23, KC_F24, KC_NO},
    },
};


/* The encoder_update_user is a function.
 * It'll be called by QMK every time you turn the encoder.
 *
 * The index parameter tells you which encoder was turned. If you only have
 * one encoder, the index will always be zero.
 * 
 * The clockwise parameter tells you the direction of the encoder. It'll be
 * true when you turned the encoder clockwise, and false otherwise.
 */
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code_delay(KC_VOLD, 10);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            rgb_matrix_increase_hue();
        } else {
            rgb_matrix_decrease_hue();
        }
    }
    return false;
}