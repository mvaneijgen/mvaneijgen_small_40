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
#define _NUMBERS 1
#define _RESET 1
// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

//------------------------------------------------------//
// 💃 Tap Dance Definitions 
//------------------------------------------------------//
enum {
  TD_BACKSPACE = 0,
};
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_BACKSPACE]  = ACTION_TAP_DANCE_DOUBLE(KC_BSPACE, KC_LBRC),
};
// END 💃 Tap Dance Definitions -------------------------------------//

//-------------------------------------------------------------------------------------------//
// 🛹 Custom key combos 
// Note 📝: If you add a new combo update #define COMBO_COUNT 1 in config.h
//-------------------------------------------------------------------------------------------//
// enum combos {
//   LCMD_ESC_SLEEP,
//   LCMD_LEFT_MRWD,
//   LCMD_RIGHT_MFFD,
//   LCMD_UP_BRMU,
//   LCMD_DOWN_BRMD,
// };

// const uint16_t PROGMEM lcmd_esc_combo[] = {KC_LCMD, KC_ESC, COMBO_END};
// const uint16_t PROGMEM lcmd_left_combo[] = {KC_LCMD, KC_RIGHT, COMBO_END};
// const uint16_t PROGMEM lcmd_right_combo[] = {KC_LCMD, KC_LEFT, COMBO_END};
// const uint16_t PROGMEM lcmd_up_combo[] = {KC_LCMD, KC_UP, COMBO_END};
// const uint16_t PROGMEM lcmd_down_combo[] = {KC_LCMD, KC_DOWN, COMBO_END};

// combo_t key_combos[COMBO_COUNT] = {
//   [LCMD_ESC_SLEEP] = COMBO(lcmd_esc_combo, KC_SYSTEM_SLEEP),
//   [LCMD_LEFT_MRWD] = COMBO(lcmd_left_combo, KC_MRWD),
//   [LCMD_RIGHT_MFFD] = COMBO(lcmd_right_combo, KC_MFFD),
//   [LCMD_UP_BRMU] = COMBO(lcmd_up_combo, KC_BRMU),
//   [LCMD_DOWN_BRMD] = COMBO(lcmd_down_combo, KC_BRMD),
// };
// END 🛹 Custom key combos -------------------------------------//
//------------------------------------------------------//
// 🏠️ Home row mods 
//------------------------------------------------------//
// Left-hand home row mods
#define CTL_A LCTL_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define GUI_D LGUI_T(KC_D)
#define SFT_F LSFT_T(KC_F)

// Right-hand home row mods
#define SFT_J RSFT_T(KC_J)
#define GUI_K RGUI_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define CTL_SCLN RCTL_T(KC_SCLN)
// END 🏠️ Home row mods -------------------------------------//

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPACE, 
		KC_TAB, CTL_A, ALT_S, GUI_D, SFT_F, KC_G, KC_H, SFT_J, GUI_K, ALT_L, CTL_SCLN, 
		KC_LSHIFT, KC_GRAVE, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_UP, MO(_RESET), 
		KC_LCTL, KC_LALT, KC_LCMD, KC_ENT, KC_SPC, MO(_BASE), KC_LEFT, KC_DOWN, KC_RIGHT
  ),
  [_NUMBERS] = LAYOUT( /* Game */
    KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS, 
		KC_TRNS, KC_EXCLAIM, KC_AT, KC_HASH, KC_DOLLAR, KC_PERCENT, KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_LEFT_PAREN, KC_COLON, 
		KC_TRNS, KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_UNDERSCORE, KC_PLUS, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, KC_PIPE, KC_DOUBLE_QUOTE, KC_LEFT_ANGLE_BRACKET, KC__VOLUP, MO(_RESET), 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_BASE), KC_BRMD, KC__VOLDOWN, KC_BRMU
  ),
  [_RESET] = LAYOUT( /* Game */
    RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(_BASE), 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(_BASE), KC_TRNS, KC_TRNS, KC_TRNS
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
