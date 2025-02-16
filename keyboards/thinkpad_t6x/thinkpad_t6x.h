/* Copyright 2021 Jiri Panacek
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

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

/*
  Qwerty Thinkpad T60 German Layout (linearized)
+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+
| ESC  | MUTE | VDN  | VUP  | THV  |      |      |      | PWR  | PRTSC| SCRLK| PAUSE| INS  | HOME | PGUP |
+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+
| F1   | F2   | F3   | F4   | F5   | F6   | F7   | F8   | F9   | F10  | F11  | F12  | DEL  | END  | PGDN |
+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+
| `    | 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    | 9    | 0    | -    | =    | BKSP        |
+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+
| TAB  | Q    | W    | E    | R    | T    | Y    | U    | I    | O    | P    | [    | ]    | ENTER       |
+------+------+------+------+------+------+------+------+------+------+------+------+------+             +
| CAPS | A    | S    | D    | F    | G    | H    | J    | K    | L    | ;    | '    | \    |             |
+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+
| SHFT | <    | Z    | X    | C    | V    | B    | N    | M    | ,    | .    | /    | SHIFT              |
+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+
| FN   | CTRL | WIN  | ALT  |              SPACE               | ALTG | GUI  | CTRL | PRPG | UP   | NXPG |
+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+
                                                                                    | LEFT | DOWN | RIGHT|
                                                                                    +------+------+------+
  Qwerty Thinkpad T60 German Layout
+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+
| ESC  | MUTE | VDN  | VUP  | THV  |      |      |      | PWR  | PRTSC| SCRLK| PAUSE| INS  | HOME | PGUP |
+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+
| F1   | F2   | F3   | F4   | F5   | F6   | F7   | F8   | F9   | F10  | F11  | F12  | DEL  | END  | PGDN |
+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+
| `    | 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    | 9    | 0    | -    | =    | BKSP        |
+------+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+--+---+------+
| TAB     | Q    | W    | E    | R    | T    | Y    | U    | I    | O    | P    | [    | ]    | ENTER    |
+---------+-+----+-+----+-+----+-+----+-+----+-+----+-+----+-+----+-+----+-+----+-+----+-+----+-+        +
| CAPS      | A    | S    | D    | F    | G    | H    | J    | K    | L    | ;    | '    | \    |        |
+-------+---+--+---+--+---+--+---+--+---+--+---O--+---+--+---+--+---+--+---+--+---+--+---+------+--------+
| SHFT  | <    | Z    | X    | C    | V    | B    | N    | M    | ,    | .    | /    | SHIFT             |
+------++------+-----++-----++------+------+------+------+------+------+------+------+-----+------+------+
| FN   |  CTRL | WIN | ALT  |              SPACE                | ALTG | GUI  | CTRL | PRPG | UP  | NXPG |
+------+-------+-----+------+-----------------------------------+------+------+------+------+-----+------+
                                                                                     | LEFT | DOWN| RGHT |
                                                                                     +------+-----+------+
*/
#define LAYOUT( \
    k500, k410, k310, k210, k510,                         k113, k213, k612, k009, k012, k011, \
    k001, k002, k302, k502, k508, k505, k306, k006, k008, k108, k110, k109, k010, k112, k111, \
    k000, k100, k101, k102, k103, k003, k004, k104, k105, k106, k107, k007, k005, k308      , \
    k300, k200, k201, k202, k203, k303, k304, k204, k205, k206, k207, k307, k305, k608      , \
    k301, k400, k401, k402, k403, k503, k504, k404, k405, k406, k407, k507, k408            , \
    k314,       k600, k601, k602, k603, k703, k704, k604, k605, k606, k707, k614            , \
          k015, k211, k513,             k708            , k713, k411, k615, k611, k512, k711, \
                                                                            k712, k710, k709  \
) { \
    {  k000,  k001,  k002,  k003,  k004,  k005,  k006,  k007,  k008,  k009,  k010,  k011,  k012, KC_NO, KC_NO,  k015},  \
    {  k100,  k101,  k102,  k103,  k104,  k105,  k106,  k107,  k108,  k109,  k110,  k111,  k112,  k113, KC_NO, KC_NO},  \
    {  k200,  k201,  k202,  k203,  k204,  k205,  k206,  k207, KC_NO, KC_NO,  k210,  k211, KC_NO,  k213, KC_NO, KC_NO},  \
    {  k300,  k301,  k302,  k303,  k304,  k305,  k306,  k307,  k308, KC_NO,  k310, KC_NO, KC_NO, KC_NO,  k314, KC_NO},  \
    {  k400,  k401,  k402,  k403,  k404,  k405,  k406,  k407,  k408, KC_NO,  k410,  k411, KC_NO, KC_NO, KC_NO, KC_NO},  \
    {  k500, KC_NO,  k502,  k503,  k504,  k505, KC_NO,  k507,  k508, KC_NO,  k510, KC_NO,  k512,  k513, KC_NO, KC_NO},  \
    {  k600,  k601,  k602,  k603,  k604,  k605,  k606, KC_NO,  k608, KC_NO, KC_NO,  k611,  k612, KC_NO,  k614,  k615},  \
    { KC_NO, KC_NO, KC_NO,  k703,  k704, KC_NO, KC_NO,  k707,  k708,  k709,  k710,  k711,  k712,  k713, KC_NO, KC_NO}  \
}
