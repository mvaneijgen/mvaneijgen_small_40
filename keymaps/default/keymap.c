/* Copyright 2019 Mitchel van Eijgen
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
#define _BASE 0
#define _GAME 1
// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT( /* Base */
    KC_DEL, KC_MUTE, KC_PEQL, KC_PSLS, KC_PAST, \
    KC_PGUP, KC_7, KC_8, KC_9, KC_PMNS, \
    KC_PGDN, KC_4, KC_5, KC_6, KC_PPLS, \
    KC_MPLY, KC_1, KC_2, KC_3, KC_ENT, \
    TG(_GAME), KC_0, KC_DOT \
  ),
  [_GAME] = LAYOUT( /* Game */
    KC_ESC, KC_1, KC_2, KC_3, KC_4, \
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, \
    KC_LSFT, KC_A, KC_S, KC_D, KC_F, \
    KC_LCTL, KC_Z, KC_X, KC_C, KC_ENT, \
    TG(_BASE), KC_SPC, KC_COMM \
  ),
};

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
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
