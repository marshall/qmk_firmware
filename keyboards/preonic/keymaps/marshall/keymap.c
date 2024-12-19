/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NUMPAD
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT
};


enum {
  GR1 = 0, // 1`
  EXTL,   // !~
  MNEQ,   // -=
  USPL,   // _+
  BRC,    // []
  CBR     // {}
};

tap_dance_action_t tap_dance_actions[] = {
  // tap once for 1, twice for grave
  [GR1] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_GRV),
  // tap once for !, twice for ~
  [EXTL] = ACTION_TAP_DANCE_DOUBLE(KC_EXLM, KC_TILD),
  // tap once for -, twice for =
  [MNEQ] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_EQL),
  // tap once for _, twice for +
  [USPL] = ACTION_TAP_DANCE_DOUBLE(KC_UNDS, KC_PLUS),
  // tap once for [, twice for ]
  [BRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
  // tap once for {, twice for }
  [CBR] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |  1   |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | - _  | + =  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |Backsp|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | ` ~  | \ |  |  [{  |  ]}  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC,
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_ENT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_QUOT,
  KC_LCTL, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_GRV,  KC_BSLS, KC_LBRC,  KC_RBRC
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  !~  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  _ + |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  !~  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  _ + |   |  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |   :  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | F10  | F11  | F12  | Next | Vol- | Vol+ | Play |   <  |   >  |   ?  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Prev | Next |  {{  |Numpad|
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
  TD(EXTL), KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN, TD(USPL), _______,
  TD(EXTL), KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN, TD(USPL), KC_PIPE,
  _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_COLN,  _______,
  _______,  KC_F10,  KC_F11,  KC_F12,  KC_MNXT, KC_VOLD, KC_VOLU,  KC_MPLY, KC_LT,   KC_GT,   KC_QUES,  KC_DQUO,
  _______,  _______, _______, _______, _______, _______, _______,  _______, KC_MPRV, KC_MNXT, TD(CBR),  TG(_NUMPAD)
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | F11  | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  Up  |      |      |      |      |      |      |      |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  | Left | Down |Right | Home | PgUp | Left | Down |  Up  | Right|      | Play |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |  End | PgDn |      |      | Prev | Next |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Vol- | Vol+ |      | Mute |
 * `-----------------------------------------------------------------------------------'
 * TODO this needs a lot of love
 */
[_RAISE] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______,
  KC_DEL,  KC_LEFT, KC_DOWN, KC_RIGHT,KC_HOME, KC_PGUP, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, KC_MPLY,
  _______, _______, _______, _______, KC_END,  KC_PGDN, _______, _______, KC_MPRV, KC_MNXT, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, _______, KC_MUTE
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset| Debug|      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Aud cy|Aud on|AudOff|AGnorm|AGswap|Qwerty|      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, QK_BOOT, DB_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
  _______, _______, MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______, _______, _______,
  _______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Numpad & Mouse
 * ,-----------------------------------------------------------------------------------.
 * |      |      |M-clic|      |      |      |      | NumLk|   /  |   *  |   -  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |L-clck|  Up  |R-clck|Scrl U| ACL0 |      |   7  |   8  |   9  |   +  |  ]   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Left | Down |Right |Scrl D| ACL1 |      |   4  |   5  |   6  |   +  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | ACL2 |      |   1  |   2  |   3  |Enter |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |   0  |   0  |   .  |Enter |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_preonic_grid(
  _______, _______, KC_BTN3, _______, _______, _______, _______, KC_NUM,  KC_SLSH,  KC_ASTR, KC_MINS, KC_BSLS,
  _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, KC_ACL0, _______, KC_7,    KC_8,     KC_9,    KC_PLUS, KC_RBRC,
  _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_ACL1, AG_SWAP, KC_4,    KC_5,     KC_6,    KC_PLUS, _______,
  _______, _______, _______, _______, _______, KC_ACL2, MI_OFF,  KC_1,    KC_2,     KC_3,    KC_ENT,  _______,
  _______, _______, _______, _______, _______, _______, _______, KC_0,    KC_0,     KC_DOT,  KC_ENT,  _______
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
#ifdef BACKLIGHT_ENABLE
        backlight_step();
#endif
#ifdef __AVR__
        writePinLow(E6);
#endif
      } else {
        unregister_code(KC_RSFT);
#ifdef __AVR__
        writePinHigh(E6);
#endif
      }
      return false;
      break;
  }
  return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo += 1;
      } else {
        muse_tempo -= 1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
  return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
      }
  }
  return true;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
  if (muse_mode) {
    if (muse_counter == 0) {
      uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
      if (muse_note != last_muse_note) {
        stop_note(compute_freq_for_midi_note(last_muse_note));
        play_note(compute_freq_for_midi_note(muse_note), 0xF);
        last_muse_note = muse_note;
      }
    }
    muse_counter = (muse_counter + 1) % muse_tempo;
  } else {
    if (muse_counter) {
      stop_all_notes();
      muse_counter = 0;
    }
  }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
