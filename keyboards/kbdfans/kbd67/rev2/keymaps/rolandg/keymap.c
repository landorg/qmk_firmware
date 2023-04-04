/* Copyright 2018 'mechmerlin'
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
* |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Home|
* |----------------------------------------------------------------|
* |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |PgUp|
* |----------------------------------------------------------------|
* | Fn    |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgDn|
* |----------------------------------------------------------------|
* |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|End |
* |----------------------------------------------------------------|
* |Ctrl| Fn | Alt | Space | Win | Space  | Fn |Ctrl|  |Lef|Dow|Rig |
* `----------------------------------------------------------------'
*/
[0] = LAYOUT_all(
    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL,  KC_HOME,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_BSPC, KC_END,
    TT(1),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGUP,
    KC_LSFT, _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN,
    KC_LCTL, MO(1),   KC_LALT,          KC_SPC,           KC_LGUI,          KC_SPC,           MO(1),   KC_RCTL, _______, KC_LEFT, KC_DOWN, KC_RGHT),

/* Keymap Fn Layer
* ,----------------------------------------------------------------.
* |~ `|F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12| \|Del |Prt |
* |----------------------------------------------------------------|
* |Reset|   |   | V-| V+|   |   |   |   | ü |   | ö |   |     |    |
* |----------------------------------------------------------------|
* |      | ä | ß |Ply|Mte|   |   |   |Lef|Dow| Up|Rig|        |    |
* |----------------------------------------------------------------|
* |        |RGB|   |   |   |   |   |   |   |   |   | Caps |PUp|    |
* |----------------------------------------------------------------|
* |    |    |     |       |     |        |    |AltG|  |Hom|PDw|End |
* `----------------------------------------------------------------'
*/
[1] = LAYOUT_all(
    KC_GRAVE, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,     KC_F10, KC_F11,  KC_F12,  _______, _______, KC_PSCR,
    RESET,    _______, _______, KC_VOLD, KC_VOLU, _______, _______, US_UDIA, _______, US_ODIA,  _______, _______, _______,          _______, _______,
    _______,  US_ADIA,   US_SS, KC_MPLY, KC_MUTE, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,          _______,          _______,
    _______,  _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______,  _______, _______, KC_CAPS,          KC_PGUP, _______,
    _______,  _______, _______,          _______,          _______,          _______,           _______, KC_RALT, _______, KC_HOME, KC_PGDN, KC_END)
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
