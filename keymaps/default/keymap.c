#include QMK_KEYBOARD_H
#define _BASE 0
#define _NUMSYM 1
#define _CTRL 2
#define _GAME 3
#define _RESET 4
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

// Using non-basic keycodes in mod-taps https://precondition.github.io/home-row-mods#using-non-basic-keycodes-in-mod-taps
// Left-hand home row mods symbols layer
#define CTL_COLN LCTL_T(KC_F23)
#define ALT_LCBR LALT_T(KC_F23)
#define GUI_LPRN LGUI_T(KC_F23)
#define SFT_LBRC LSFT_T(KC_F23)

// Right-hand home row mods symbols layer
#define SFT_RBRC RSFT_T(KC_F22)
#define GUI_RPRN RGUI_T(KC_F22)
#define ALT_RCBR LALT_T(KC_F22)
#define CTL_SCLN RCTL_T(KC_F22)
// END 🏠️ Home row mods -------------------------------------//

enum custom_keycodes {
    KC_BSPCDEL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    LT(_RESET, KC_ESC), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPCDEL, 
    KC_TAB, CTL_A, ALT_S, GUI_D, SFT_F, KC_G, KC_H, SFT_J, GUI_K, ALT_L, CTL_BSLS, 
    KC_NO, KC_GRAVE, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, 
    KC_NO, KC_NO, MO(_NUMSYM), LT(_NUMSYM, KC_ENT), KC_SPC, MO(_CTRL), KC_NO, KC_NO, KC_NO
  ),
  [_NUMSYM] = LAYOUT(
    KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS, 
    KC_CAPS, CTL_COLN, ALT_LCBR, GUI_LPRN, SFT_LBRC, KC_QUOT, KC_DQT, SFT_RBRC, GUI_RPRN, ALT_RCBR, CTL_SCLN,
    KC_TRNS, KC_TILD, KC_PIPE, KC_AT, KC_MINS, KC_DLR, KC_LT, KC_GT, KC_AMPR, KC_PLUS, KC_UNDS, KC_QUES, 
    KC_TRNS, KC_TRNS, TG(_NUMSYM), KC_TRNS, KC_TRNS, TG(_GAME), KC_NO, KC_NO, KC_EQL
  ),
  [_CTRL] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_MFFD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_BRMD, KC_BRMU, RSFT_T(KC_VOLD), RGUI_T(KC_MPLY), LALT_T(KC_VOLU), RCTL_T(KC__MUTE), 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MRWD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [_GAME] = LAYOUT(
    KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPACE, 
    KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_BSLS, 
    KC_LSHIFT, KC_GRAVE, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_UP, MO(_RESET), 
    KC_LCTL, KC_LALT, KC_LCMD, KC_SPC, KC_ENT, MO(_NUMSYM), KC_LEFT, KC_DOWN, KC_RIGHT
  ),
  [_RESET] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, TG(_BASE), KC_TRNS, KC_TRNS, TG(_BASE), KC_TRNS, KC_TRNS, KC_TRNS
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   switch (keycode) {
     // Left-hand home row mods symbols layer
      case CTL_COLN: if (record->tap.count > 0) { if (record->event.pressed) { tap_code16(KC_COLN); } return false; }
      case ALT_LCBR: if (record->tap.count > 0) { if (record->event.pressed) { tap_code16(KC_LCBR); } return false; }
      case GUI_LPRN: if (record->tap.count > 0) { if (record->event.pressed) { tap_code16(KC_LPRN); } return false; }
      case SFT_LBRC: if (record->tap.count > 0) { if (record->event.pressed) { tap_code16(KC_LBRC); } return false; }
      // Right-hand home row mods symbols layer
      case SFT_RBRC: if (record->tap.count > 0) { if (record->event.pressed) { tap_code16(KC_RBRC); } return false; }
      case GUI_RPRN: if (record->tap.count > 0) { if (record->event.pressed) { tap_code16(KC_RPRN); } return false; }
      case ALT_RCBR: if (record->tap.count > 0) { if (record->event.pressed) { tap_code16(KC_RCBR); } return false; }
      case CTL_SCLN: if (record->tap.count > 0) { if (record->event.pressed) { tap_code16(KC_SCLN); } return false; }
      // Custom shift keys
      static uint8_t saved_mods = 0; // Place this outside of the switch, but inside process_record_user()
case KC_BSPCDEL:
    if (record->event.pressed) {
        if (get_mods() & MOD_MASK_SHIFT) {
            saved_mods = get_mods() & MOD_MASK_SHIFT; // Mask off anything that isn't Shift
            del_mods(saved_mods); // Remove any Shifts present
            register_code(KC_DEL);
        } else {
            saved_mods = 0; // Clear saved mods so the add_mods() below doesn't add Shifts back when it shouldn't
            register_code(KC_BSPC);
        }
    } else {
        add_mods(saved_mods);
        unregister_code(KC_DEL);
        unregister_code(KC_BSPC);
    }

    return false;
   }
   return true;
}