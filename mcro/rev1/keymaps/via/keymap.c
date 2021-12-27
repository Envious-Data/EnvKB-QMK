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
#include "pico_eeprom.h"
#include "via.h"

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [0] = {
        {KC_F13, KC_F14, KC_F15, KC_F16},
        {KC_F17, KC_F18, KC_F19, KC_F20},
        {KC_F21, KC_F22, KC_F23, KC_F24},
    },
    [1] = {
        {KC_F13, KC_F14, KC_F15, KC_F16},
        {KC_F17, KC_F18, KC_F19, KC_F20},
        {KC_F21, KC_F22, KC_F23, KC_F24},
    },

    [2] = {
        {KC_F13, KC_F14, KC_F15, KC_F16},
        {KC_F17, KC_F18, KC_F19, KC_F20},
        {KC_F21, KC_F22, KC_F23, KC_F24},
    },

    [3] = {
        {KC_F13, KC_F14, KC_F15, KC_F16},
        {KC_F17, KC_F18, KC_F19, KC_F20},
        {KC_F21, KC_F22, KC_F23, KC_F24},
    },

    [4] = {
        {KC_F13, KC_F14, KC_F15, KC_F16},
        {KC_F17, KC_F18, KC_F19, KC_F20},
        {KC_F21, KC_F22, KC_F23, KC_F24},
    },

    [5] = {
        {KC_F13, KC_F14, KC_F15, KC_F16},
        {KC_F17, KC_F18, KC_F19, KC_F20},
        {KC_F21, KC_F22, KC_F23, KC_F24},
    },
};

/*
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}
*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;

        case KC_FN0:
            if (record->event.pressed) {
                printf("save keymap to eeprom\n");
                pico_eepemu_flash_dynamic_keymap();
                printf("complete\n");
                printf("save eeconfig to eeprom\n");
                pico_eepemu_flash_eeconfig();
                printf("complete\n");
            }
            return false;
            break;
    }
    return true;
}

