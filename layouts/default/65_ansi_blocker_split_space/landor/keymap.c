/* Copyright 2020 'landorg'
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
#include "keymap_us_international.h"

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =| \|Del |Home|
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Backs|PgUp|
   * |----------------------------------------------------------------|
   * | Fn    |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgDn|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|End |
   * |----------------------------------------------------------------|
   * |Ctrl| Fn | Alt | BkSpc | Win | Space  | Fn |Ctrl|  |Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
  [0] = LAYOUT_65_ansi_blocker_split_space(
      QK_GESC,  KC_1,               KC_2,               KC_3,               KC_4,                KC_5,    KC_6,    KC_7,               KC_8,               KC_9,               KC_0,                  KC_MINS,  KC_EQL,   KC_BSPC,  KC_HOME,
      KC_TAB,   KC_Q,               KC_W,               KC_E,               KC_R,                KC_T,    KC_Y,    KC_U,               KC_I,               KC_O,               KC_P,                  KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_END,
      TT(2),    MT(MOD_LGUI, KC_A), MT(MOD_LALT, KC_S), MT(MOD_LCTL, KC_D), MT(MOD_LSFT, KC_F),  KC_G,    KC_H,    MT(MOD_RSFT, KC_J), MT(MOD_RCTL, KC_K), MT(MOD_LALT, KC_L), MT(MOD_RGUI, KC_SCLN), KC_QUOT,            KC_ENT,   KC_PGUP,
      KC_LSFT,  KC_Z,               KC_X,               KC_C,               KC_V,                KC_B,    KC_N,    KC_M,               KC_COMM,            KC_DOT,             KC_SLSH,                         KC_RSFT,  KC_UP,    KC_PGDN,
      KC_LCTL,  MO(2),              KC_LALT,            KC_SPC,             KC_LGUI,             KC_BSPC,                                                  MO(2),              RCTL_T(KC_RALT),                 KC_LEFT,  KC_DOWN,  KC_RGHT
  ),

  /* Keymap (Gaming Layer)
   * ,----------------------------------------------------------------.
   * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =| \|Del |Home|
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Backs|PgUp|
   * |----------------------------------------------------------------|
   * | Fn    |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgDn|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|End |
   * |----------------------------------------------------------------|
   * |Ctrl| Fn | Alt | Space | Win | Space  | Fn |Ctrl|  |Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
  [1] = LAYOUT_65_ansi_blocker_split_space(
      QK_GESC, KC_1,  KC_2,    KC_3, KC_4,   KC_5, KC_6,    KC_7, KC_8,   KC_9,    KC_0,    KC_MINS,         KC_EQL,           KC_BSPC, KC_HOME,
      KC_TAB,  KC_Q,  KC_W,    KC_E, KC_R,   KC_T, KC_Y,    KC_U, KC_I,   KC_O,    KC_P,    KC_LBRC,         KC_RBRC,          KC_BSLS,   TG(1),
      TT(2),   KC_A,  KC_S,    KC_D, KC_F,   KC_G, KC_H,    KC_J, KC_K,   KC_L,    KC_SCLN, KC_QUOT,                   KC_ENT,          _______,
      KC_LSFT,        KC_Z,    KC_X, KC_C,   KC_V, KC_B,    KC_N, KC_M,   KC_COMM, KC_DOT,  KC_SLSH,         KC_RSFT,          KC_UP,   QK_LOCK,
      KC_LCTL, MO(2), KC_LALT,       KC_SPC,       KC_LGUI,       KC_SPC,          MO(2),   RCTL_T(KC_RALT),          KC_LEFT, KC_DOWN, KC_RGHT
  ),

  /* Keymap Fn Layer
   * ,----------------------------------------------------------------.
   * |~ `|F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12| \|Del |Prt |
   * |----------------------------------------------------------------|
   * |Reset|   |   | V-| V+|   |   |   |   | ü |   | ö |   |     |    |
   * |----------------------------------------------------------------|
   * |      | ä | ß |Ply|Mte|   |   |   |Lef|Dow| Up|Rig|        |    |
   * |----------------------------------------------------------------|
   * |        |RGB|   |   |Nxt|Prv|   |   |   |   |   | Caps |PUp|    |
   * |----------------------------------------------------------------|
   * |    |    |     |       |     |        |    |AltG|  |Hom|PDw|End |
   * `----------------------------------------------------------------'
   */
  [2] = LAYOUT_65_ansi_blocker_split_space(
      KC_GRAVE, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,     KC_F10, KC_F11,          KC_F12,            KC_DEL, KC_PSCR,
      QK_BOOT,  _______, _______, KC_VOLD, KC_VOLU, _______, _______, _______, _______, _______,  _______, _______,         _______,          _______,   TG(1),
      _______,  _______, _______, KC_MPLY, KC_MUTE, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, KC_GRAVE,                 _______,          _______,
      _______,           RGB_TOG, _______, KC_MPRV, KC_MNXT, _______, _______, _______, _______,  _______, _______,         KC_CAPS,          KC_PGUP, _______,
      _______,  _______, _______,          _______,          _______,          _______,           _______, RCTL_T(KC_RALT),           KC_HOME, KC_PGDN, KC_END
  ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RCTL_T(KC_RALT):
        if (record->tap.count && record->event.pressed) {
            set_oneshot_mods(MOD_BIT(KC_RALT));
            return false;
        }
        return true;
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
