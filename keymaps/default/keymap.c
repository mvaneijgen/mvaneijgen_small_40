#include QMK_KEYBOARD_H
#define _BASE 0
#define _GAME 1
#define _NUMSYM 2
#define _CTRL 3
#define _RESET 4
#define _SOPHIE 5
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
//------------------------------------------------------//
// 👨‍💻 Custom short codes  
//------------------------------------------------------//
#define KC_FORC LGUI(LALT(KC_ESC)) // Force quit
#define KC_CTXT LGUI(LSFT(KC_2)) // Capture text from image
#define KC_CAPW LGUI(LSFT(KC_3)) // Capture whole screen
#define KC_CAPP LGUI(LSFT(KC_4)) // Capture portion of screen
#define KC_CREC LGUI(LSFT(KC_5)) // Record screen
#define KC_TLFT LGUI(LSFT(KC_LBRC)) // Move tab left
#define KC_TRGT LGUI(LSFT(KC_RBRC)) // Move tab Right
#define KC_EURO LALT(LSFT(KC_2)) // Euro €

// END 🏠️ Home row mods -------------------------------------//
//------------------------------------------------------//
// 👨‍💻 Custom short codes  
//------------------------------------------------------//
// #define KC_FORC LGUI(LALT(KC_ESC)) // Force quit
// #define KC_CTXT LGUI(LSFT(KC_2)) // Capture text from image
// #define KC_CAPW LGUI(LSFT(KC_3)) // Capture whole screen
// #define KC_CAPP LGUI(LSFT(KC_4)) // Capture portion of screen
// #define KC_CREC LGUI(LSFT(KC_5)) // Record screen
// #define KC_TLFT LGUI(LSFT(KC_LBRC)) // Move tab left
// #define KC_TRGT LGUI(LSFT(KC_RBRC)) // Move tab Right
// #define KC_EURO LALT(KC_2) // Euro €
// #define KC_EMDS LALT(LSFT(KC_MINUS)) // Euro €
// #define KC_MUTM LGUI(LSFT(LALT(KC_M))) // Euro €
// END 👨‍💻 Custom short codes  -------------------------------------//
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

tap_dance_action_t tap_dance_actions[] = {
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
    _______, KC_GRAVE, KC_Z, TD(TD_X_CMDX), TD(TD_C_CMDC), TD(TD_V_CMDV), KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, 
    _______, _______, MO(_NUMSYM), LT(_NUMSYM, KC_ENT), KC_SPC, MO(_CTRL), _______, _______, _______
  ),
  [_GAME] = LAYOUT(
    LT(_RESET, KC_ESC), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, 
    KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_BSLS, 
    KC_LSFT, KC_GRAVE, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_UP, MO(_RESET), 
    KC_LCTL, KC_LALT, KC_LCMD, KC_SPC, KC_ENT, MO(_NUMSYM), KC_LEFT, KC_DOWN, KC_RIGHT
  ),
  [_NUMSYM] = LAYOUT(
    _______, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, _______, 
    KC_CAPS, CTL_COLN, ALT_LCBR, GUI_LPRN, SFT_LBRC, KC_QUOT, KC_DQT, SFT_RBRC, GUI_RPRN, ALT_RCBR, CTL_SCLN,
    KC_EURO, KC_GRV, KC_AT, KC_HASH, KC_MINS, KC_DLR, KC_EQL, KC_PLUS, KC_AMPR, KC_UNDS, KC_DOT, KC_UNDS, 
    _______, _______, TG(_NUMSYM), _______, _______, _______, _______, _______, _______
  ),
  [_CTRL] = LAYOUT(
    KC_FORC, KC_CAPW, KC_CTXT, KC_UP, KC_CAPP, KC_CREC, _______, KC_TLFT, KC_MFFD, KC_TRGT, _______, _______, 
    _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, KC_BRMD, KC_BRMU, RSFT_T(KC_VOLD), RGUI_T(KC_MPLY), LALT_T(KC_VOLU), RCTL_T(KC_MUTE), 
    _______, _______, _______, _______, _______, _______, _______, KC_MRWD, _______, _______, _______, _______, 
    _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [_RESET] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT, 
    TG(_GAME), _______, TG(_SOPHIE), _______, _______, _______, _______, _______, _______, _______, _______, 
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
    _______, _______, TG(_BASE), _______, _______, TG(_BASE), _______, _______, _______
  ),
  [_SOPHIE] = LAYOUT(
    LT(_RESET, KC_ESC), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, 
    KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_BSLS, 
    KC_LSFT, KC_GRAVE, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_UP, MO(_NUMSYM), 
    KC_LCTL, KC_LALT, KC_LCMD, KC_SPC, KC_ENT, MO(_NUMSYM), KC_LEFT, KC_DOWN, KC_RIGHT
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
    }
   return true;
}
// Change led color per layer
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _SOPHIE:
            rgblight_setrgb(255, 0, 149);
            break;
        case _GAME:
            rgblight_setrgb(0, 187, 170);
            break;
        default: // for any other layers, or the default layer
            rgblight_setrgb (255, 255, 255);
            break;
    }
  return state;
}