/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

 // place overrides here
#define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                              SONG(COLEMAK_SOUND), \
                              SONG(DVORAK_SOUND) \
                            }

/* Use I2C or Serial, not both */
#define USE_SERIAL
// #define USE_I2C

/* Select hand configuration */
// #define MASTER_LEFT
#define MASTER_RIGHT
// #define EE_HANDS

/* Tap Dance / Mod Tap */
#define TAPPING_TERM 175
/* Suggested by https://www.reddit.com/r/olkb/comments/8qppdn/qmk_issue_with_mt_when_typing_quickly/ */
#define IGNORE_MOD_TAP_INTERRUPT
#undef PERMISSIVE_HOLD
#undef PREVENT_STUCK_MODIFIERS
/*
#define TAPPING_TERM_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD
*/

/* Auto-shift Settings */
/* Prevents auto-shifting alphas */
#define NO_AUTO_SHIFT_ALPHA
#define NO_AUTO_SHIFT_SPECIAL
#define AUTO_SHIFT_TIMEOUT 225

/* Combo Keys */
// #define COMBO_COUNT 2

/* Mouse Settings */
// #define MK_3_SPEED
// #define MK_MOMENTARY_ACCEL
// #define MK_C_OFFSET_UNMOD   18
// #define MK_C_INTERVAL_UNMOD 16
// #define MK_C_OFFSET_0       2
// #define MK_C_INTERVAL_0     16
// #define MK_C_OFFSET_1       6
// #define MK_C_INTERVAL_1     16
// #define MK_C_OFFSET_2       36
// #define MK_C_INTERVAL_2     16
#define MK_W_OFFSET_UNMOD   10
#define MK_W_INTERVAL_UNMOD 100
// #define MK_W_OFFSET_0       1
// #define MK_W_INTERVAL_0     360
// #define MK_W_OFFSET_1       1
// #define MK_W_INTERVAL_1     120
// #define MK_W_OFFSET_2       1
// #define MK_W_INTERVAL_2     20
#define MOUSEKEY_DELAY	            0
#define MOUSEKEY_INTERVAL	        0
#define MOUSEKEY_MAX_SPEED	        1
#define MOUSEKEY_TIME_TO_MAX	    10
#define MOUSEKEY_WHEEL_MAX_SPEED	1
#define MOUSEKEY_WHEEL_TIME_TO_MAX	100
