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
//------------------------------------------------------//
// 💃 Tap Dance  
//------------------------------------------------------//
#define KC_CMDZ LGUI(KC_Z) // Custom CMD + Z
#define KC_CMDX LGUI(KC_X) // Custom CMD + X
#define KC_CMDC LGUI(KC_C) // Custom CMD + C
#define KC_CMDV LGUI(KC_V) // Custom CMD + V

enum {
  TD_Z_CMDZ,
  TD_X_CMDX,
  TD_C_CMDC,
  TD_V_CMDV,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_Z_CMDZ] = ACTION_TAP_DANCE_DOUBLE(KC_Z, KC_CMDZ),
  [TD_X_CMDX] = ACTION_TAP_DANCE_DOUBLE(KC_X, KC_CMDX),
  [TD_C_CMDC] = ACTION_TAP_DANCE_DOUBLE(KC_C, KC_CMDC),
  [TD_V_CMDV] = ACTION_TAP_DANCE_DOUBLE(KC_V, KC_CMDV),
};
// END 💃 Tap Dance  -------------------------------------//
// enum custom_keycodes {
//     KC_BSPCDEL,
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    LT(_RESET, KC_ESC), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, 
    KC_TAB, CTL_A, ALT_S, GUI_D, SFT_F, KC_G, KC_H, SFT_J, GUI_K, ALT_L, CTL_BSLS, 
    _______, KC_GRAVE, TD(TD_Z_CMDZ), TD(TD_X_CMDX), TD(TD_C_CMDC), TD(TD_V_CMDV), KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, 
    _______, _______, MO(_NUMSYM), LT(_NUMSYM, KC_ENT), KC_SPC, MO(_CTRL), _______, _______, _______
  ),
  [_NUMSYM] = LAYOUT(
    _______, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, _______, 
    KC_CAPS, CTL_COLN, ALT_LCBR, GUI_LPRN, SFT_LBRC, KC_QUOT, KC_DQT, SFT_RBRC, GUI_RPRN, ALT_RCBR, CTL_SCLN,
    _______, KC_TILD, KC_AT, KC_HASH, KC_MINS, KC_DLR, KC_EQL, KC_PLUS, KC_AMPR, KC_DOT, KC_UNDS, KC_TILDE, 
    _______, _______, TG(_NUMSYM), _______, _______, _______, _______, _______, KC_EQL
  ),
  [_CTRL] = LAYOUT(
    _______, _______, _______, KC_UP, _______, _______, _______, KC_MFFD, _______, _______, _______, _______, 
    _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, KC_BRMD, KC_BRMU, RSFT_T(KC_VOLD), RGUI_T(KC_MPLY), LALT_T(KC_VOLU), RCTL_T(KC__MUTE), 
    _______, _______, _______, _______, _______, _______, _______, KC_MRWD, _______, _______, _______, _______, 
    _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [_GAME] = LAYOUT(
    LT(_RESET, KC_ESC), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPACE, 
    KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_BSLS, 
    KC_LSHIFT, KC_GRAVE, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_UP, MO(_RESET), 
    KC_LCTL, KC_LALT, KC_LCMD, KC_SPC, KC_ENT, MO(_NUMSYM), KC_LEFT, KC_DOWN, KC_RIGHT
  ),
  [_RESET] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET, 
    TG(_GAME), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
    _______, _______, TG(_BASE), _______, _______, TG(_BASE), _______, _______, _______
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   switch (keycode) {
     // Left-hand home row mods symbols layer
      case CTL_COLN: if (record->tap.count > 0) { if (record->event.pressed) { tap_code16(KC_COLN); } return false; }
      case ALT_LCBR: if (record->tap.count > 0) { if (record->event.pressed) { tap_code16(KC_LBRC); } return false; }
      case GUI_LPRN: if (record->tap.count > 0) { if (record->event.pressed) { tap_code16(KC_LPRN); } return false; }
      case SFT_LBRC: if (record->tap.count > 0) { if (record->event.pressed) { tap_code16(KC_LCBR); } return false; }
      // Right-hand home row mods symbols layer
      case SFT_RBRC: if (record->tap.count > 0) { if (record->event.pressed) { tap_code16(KC_RCBR); } return false; }
      case GUI_RPRN: if (record->tap.count > 0) { if (record->event.pressed) { tap_code16(KC_RPRN); } return false; }
      case ALT_RCBR: if (record->tap.count > 0) { if (record->event.pressed) { tap_code16(KC_RBRC); } return false; }
      case CTL_SCLN: if (record->tap.count > 0) { if (record->event.pressed) { tap_code16(KC_SCLN); } return false; }
      // Custom shift keys
//       static uint8_t saved_mods = 0; // Place this outside of the switch, but inside process_record_user()
// case KC_BSPCDEL:
//     if (record->event.pressed) {
//         if (get_mods() & MOD_MASK_SHIFT) {
//             saved_mods = get_mods() & MOD_MASK_SHIFT; // Mask off anything that isn't Shift
//             del_mods(saved_mods); // Remove any Shifts present
//             register_code(KC_DEL);
//         } else {
//             saved_mods = 0; // Clear saved mods so the add_mods() below doesn't add Shifts back when it shouldn't
//             register_code(KC_BSPC);
//         }
//     } else {
//         add_mods(saved_mods);
//         unregister_code(KC_DEL);
//         unregister_code(KC_BSPC);
//     }

//     return false;
    }
   return true;
}