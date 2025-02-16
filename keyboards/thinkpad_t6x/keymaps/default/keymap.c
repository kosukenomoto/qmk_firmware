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
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN_KEYS, /*JiPa: added second layer for functional keys */
    _NUMPAD /*JiPa: adds numpad when enabled by fn+NumLK */
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
          KC_ESC, KC__MUTE, KC__VOLDOWN, KC__VOLUP, RESET,                         KC_PSCR, KC_SLCK, KC_PAUS, KC_INS, KC_HOME, KC_PGUP,
          KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_END, KC_PGDN,
          KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC      ,
          KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_ENT      ,
          KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_BSLS           ,
          KC_LSHIFT,       KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSHIFT            ,
                KC_LCTRL, KC_APP, KC_LALT,             KC_SPACE            , KC_RALT, KC_LGUI, KC_RCTRL, KC_NO, KC_UP, KC_NO,
                                                                                  KC_LEFT, KC_DOWN, KC_RIGHT
      ),
    /* JiPa: Functional keys */
    [_FN_KEYS] = LAYOUT(
          KC_ESC, KC__MUTE, KC__VOLDOWN, KC__VOLUP, RESET,                         KC_PSCR, TG(_NUMPAD), KC_PAUS, KC_INS, KC_BRIU, KC_PGUP,
          KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_BRID, KC_PGDN,
          KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC      ,
          KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_ENT      ,
          KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_BSLS           ,
          KC_LSHIFT,       KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSHIFT            ,
                KC_LCTRL, KC_APP, KC_LALT,             KC_A                , KC_RALT, KC_LGUI, KC_RCTRL, KC_NO, KC_UP, KC_NO,
                                                                                  KC_LEFT, KC_DOWN, KC_RIGHT
      ),
      [_NUMPAD] = LAYOUT(
          KC_ESC, KC__MUTE, KC__VOLDOWN, KC__VOLUP, RESET,                         KC_PSCR, KC_SLCK, KC_PAUS, KC_INS, KC_HOME, KC_PGUP,
          KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_END, KC_PGDN,
          KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_KP_7, KC_KP_8, KC_KP_9, KC_0, KC_MINS, KC_EQL, KC_BSPC      ,
          KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_KP_4, KC_KP_5, KC_KP_6, KC_P, KC_LBRC, KC_RBRC, KC_ENT      ,
          KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_KP_1, KC_KP_2, KC_KP_3, KC_SCLN, KC_QUOT, KC_BSLS           ,
          KC_LSHIFT,       KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_KP_0, KC_COMM, KC_DOT, KC_SLSH, KC_RSHIFT            ,
                KC_LCTRL, KC_APP, KC_LALT,             KC_B            , KC_RALT, KC_LGUI, KC_RCTRL, KC_NO, KC_UP, KC_NO,
                                                                                  KC_LEFT, KC_DOWN, KC_RIGHT
      )
};

void dip_switch_update_user (uint8_t index, bool active)
{
 switch (index) { 
	 case 0:if (active)  /* Fn key */
			{
				layer_on(_FN_KEYS);
				}
			else 
			{
				layer_off(_FN_KEYS);
			} 
		 
		 break; 
	 case 1: if (active) {tap_code(KC_B); break;} /* PWR button */
	 break;
 }
}

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
    }
    return true;
}
