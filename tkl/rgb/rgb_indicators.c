// Copyright 2021 Dasky (@daskygit)
// SPDX-License-Identifier: GPL-2.0-or-later
//#include "dasky.h"
//#include "wrappers.h"
//#include "tap_dances.h"
#ifdef RGB_MATRIX_ENABLE
#    include "rgb_bits.h"
#endif
#include "rgb_indicators.h"
#ifdef USBPD_ENABLE
#    include "usbpd_bits.h"
#else
#    define rgb_matrix_hsv_to_rgb hsv_to_rgb
#endif


#ifdef RGB_MATRIX_ENABLE
void rgb_show_layer(uint8_t led_min, uint8_t led_max) {
    switch (get_highest_layer(layer_state)) {
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
                        case KC_RIGHT:
                            hue = ((kc - KC_1) * 28) % 255;
                            break;
                            hue = 0;
                            break;
                        case KC_UP:
                            hue = 201;
                            break;
                        case RGB_TOG ... RGB_SPD:
                            continue;
                        case MAGIC_TOGGLE_NKRO:
                            hue = 222;
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

/*
void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    rgb_show_layer(led_min, led_max);
    //rgb_check_blinking(led_min, led_max);
}
*/
#endif
