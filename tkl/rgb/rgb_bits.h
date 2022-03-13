// Copyright 2021 Dasky (@daskygit)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once
#include <stdint.h>
#include <stdbool.h>

typedef struct led_to_matrix_pos {
    uint8_t row : 6;
    uint8_t col : 18;
} led_to_matrix_pos;

led_to_matrix_pos led_position[DRIVER_LED_TOTAL];

void rgb_matrix_led_index_init(void);

bool rgb_matrix_led_index_has_pos(uint8_t led_index);
