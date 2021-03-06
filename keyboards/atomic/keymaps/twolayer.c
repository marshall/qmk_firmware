#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* QWERTY - MIT ENHANCED / GRID COMPATIBLE
   * .---------------------------------------------------------------------------------------------------------------------- 2u ------------.
   * | ESC    | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | -      | =      | XXXXXX . BACKSP |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
   * | TAB    | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | [      | ]      | \      | DEL    |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ------------+--------|
   * | LCTRL1 | A      | S      | D      | F      | G      | H      | J      | K      | L      | ;      | '      | XXXXXX . ENTER  | PG UP  |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ---------------------+--------|
   * | LSHIFT | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | /      | XXXXXX . RSHIFT | UP     | PG DN  |
   * |--------+--------+--------+--------+--------+- 6.25u ---------+--------+--------+--------+--------+-----------------+--------+--------|
   * | BRITE  | LALT   |  FN    |               XXXXXX . SPACE                        | RCTRL  | RALT   | FN     | LEFT   | DOWN   | RIGHT  |
   * '--------------------------------------------------------------------------------------------------------------------------------------'
   */
  [0] = LAYOUT_grid( /* QWERTY */
    KC_ESC,  KC_1,   KC_2,  KC_3,   KC_4,   KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC,
    KC_TAB,  KC_Q,   KC_W,  KC_E,   KC_R,   KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
    KC_LCTL, KC_A,   KC_S,  KC_D,   KC_F,   KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_ENT,  KC_PGUP,
    KC_LSFT, KC_Z,   KC_X,  KC_C,   KC_V,   KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RSFT, KC_UP,   KC_PGDN,
    M(0),    KC_ALT, MO(1), KC_SPC, KC_SPC, KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_RCTL, KC_RALT, MO(1),   KC_LEFT, KC_DOWN, KC_RGHT,
  ),

  /* FUNCTION
   * .---------------------------------------------------------------------------------------------------------------------- 2u ------------.
   * | GRV    | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    | XXXXXX .        |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
   * | SCR LK | F13    | F14    | F15    | F16    | F17    | F18    | F19    | F20    | F21    | F22    | F23    | F24    | PAUSE  | PR SCR |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ------------+--------|
   * | CAP LK | MS BT5 | MS BT4 | MS BT3 | MS BT2 | SLOW M | FAST M | NEXT   | VOL+   | VOL-   | PLAY   |        | XXXXXX .        | WHEEL+ |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ---------------------+--------|
   * | NUM LK |        |        |        |        |        |        |        | INSERT |   END1 |  HOME  | XXXXXX .        | MOUS U | WHEEL- |
   * |--------+--------+--------+--------+--------+- 6.25 ------------+--------+--------+------+--------+-----------------+--------+--------|
   * |        |        |   FN   |                  XXXXXX . MS BT1                      |      |        |   FN   | MOUS L | MOUS D | MOUS R |
   * '--------------------------------------------------------------------------------------------------------------------------------------'
   */
  [1] = LAYOUT_grid( /* FUNCTION LAYER*/
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,     KC_F9,   KC_F10,  KC_F11,  KC_F12,  ___T___, ___T___,
    KC_SLCK, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,    KC_F21,  KC_F22,  KC_F23,  KC_F24,  KC_PAUS, KC_PSCR,
    KC_CAPS, KC_BTN5, KC_BTN4, KC_BTN3, KC_BTN2, KC_ACL0, KC_ACL2, KC_MNXT, KC_VOLD,   KC_VOLU, KC_MPLY, _______, ___T___, ___T___, KC_WH_U,
    KC_NLCK, _______, _______, _______, _______, _______, _______, _______, KC_INSERT, KC_END,  KC_HOME, ___T___, ___T___, KC_MS_U, KC_WH_D,
    _______, _______, MO(1),   _______, _______, KC_BTN1, KC_BTN1, _______, _______,   _______, _______, MO(1),   KC_MS_L, KC_MS_D, KC_MS_R,
  ),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
    break;
  }
  return MACRO_NONE;
};
