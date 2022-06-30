/* Copyright 2022 Envious Design
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

//#include "rev1.h"
//#include "matrix.h"
//#include "tusb.h"

#include QMK_KEYBOARD_H

void board_init(void) {
}

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
  // Key Matrix to LED Index
  {   0, 1, 2,  3 },
  {   4, 5, 6,  7 },
  {   8, 9, 10, 11 },
}, {
	// LED Index to Physical Position
	{  0,0  }, { 75,0  }, {149,0  }, {224,0  }, 
	{  0,32 }, { 75,32 }, {149,32 }, {224,32 }, 
	{  0,64 }, { 75,64 }, {149,64 }, {224,64 },
}, {
  // LED Index to Flag
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,
} };
#endif