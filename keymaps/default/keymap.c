#include QMK_KEYBOARD_H
#define _BASE 0
#define _NUMBERS 1
#define _RESET 2
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
#define CTL_BSLS RCTL_T(KC_BSLS)
// END 🏠️ Home row mods -------------------------------------//

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPACE, 
		KC_TAB, CTL_A, ALT_S, GUI_D, SFT_F, KC_G, KC_H, SFT_J, GUI_K, ALT_L, CTL_BSLS, 
		KC_LSHIFT, KC_GRAVE, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_UP, MO(_RESET), 
		KC_LCTL, KC_LALT, KC_LCMD, KC_ENT, KC_SPC, MO(_NUMBERS), KC_LEFT, KC_DOWN, KC_RIGHT
  ),
  [_NUMBERS] = LAYOUT( /* Game */
    KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS, 
		KC_TRNS, KC_EXCLAIM, KC_AT, KC_HASH, KC_DOLLAR, KC_PERCENT, KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_LEFT_PAREN, KC_COLON, 
		KC_TRNS, KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_UNDERSCORE, KC_PLUS, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, KC_PIPE, KC_DOUBLE_QUOTE, KC_LEFT_ANGLE_BRACKET, KC__VOLUP, MO(_RESET), 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_NUMBERS), KC_BRMD, KC__VOLDOWN, KC_BRMU
  ),
  [_RESET] = LAYOUT( /* Game */
    RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(_BASE), 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(_BASE), KC_TRNS, KC_TRNS, KC_TRNS
  ),
};