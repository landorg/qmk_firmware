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

enum layers {
  _BASE,
  _GAMING,
  _FN,
  _FNL,
  _FNR
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap (Base Layer) Default Layer
   * ,-----------------------------------------------------.
   * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Bsp|
   * |-----------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \|
   * |-----------------------------------------------------|
   * | Fn    |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Enter |
   * |-----------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Sft/Up|
   * |-----------------------------------------------------|
   * |Ctl|Gui|Alt| Spc/FNL  | Spc/FNR  |Fn|AGr/Lft|Gui/Dow|Ctl/Rgt|
   * `-----------------------------------------------------'
   */
  [_BASE] = LAYOUT_60_ansi_split_space(
      QK_GESC,  KC_1,               KC_2,               KC_3,               KC_4,                KC_5,    KC_6,    KC_7,               KC_8,               KC_9,                 KC_0,                  KC_MINS,  KC_EQL,   KC_BSPC,
      KC_TAB,   KC_Q,               KC_W,               KC_E,               KC_R,                KC_T,    KC_Y,    KC_U,               KC_I,               KC_O,                 KC_P,                  KC_LBRC,  KC_RBRC,  KC_BSLS,
      TT(_FN),  MT(MOD_LGUI, KC_A), MT(MOD_LALT, KC_S), MT(MOD_LCTL, KC_D), MT(MOD_LSFT, KC_F),  KC_G,    KC_H,    MT(MOD_RSFT, KC_J), MT(MOD_RCTL, KC_K), MT(MOD_LALT, KC_L),   MT(MOD_RGUI, KC_SCLN), KC_QUOT,            KC_ENT,
      KC_LSFT,  KC_Z,               MT(MOD_RALT, KC_X), KC_C,               KC_V,                KC_B,    KC_N,    KC_M,               KC_COMM,            MT(MOD_RALT, KC_DOT), KC_SLSH,                        RSFT_T(KC_UP),
      KC_LCTL,  KC_LGUI,            KC_LALT,            LT(_FNL, KC_SPC),                        LT(_FNR, KC_BSPC),                   MO(_FN),             RALT_T(KC_LEFT),         MT(MOD_LGUI, KC_DOWN),   RCTL_T(KC_RIGHT)
  ),

  /* Keymap (Gaming Layer)
   * ,-----------------------------------------------------.
   * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Bsp|
   * |-----------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Game|
   * |-----------------------------------------------------|
   * | Fn    |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Enter |
   * |-----------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Sft/Up|
   * |-----------------------------------------------------|
   * |Ctl|Gui|Alt|  Space   |  Space   |AGr|Fn/Lft|Gui/Dow|Ctl/Rgt|
   * `-----------------------------------------------------'
   */
  [_GAMING] = LAYOUT_60_ansi_split_space(
      QK_GESC, KC_1,  KC_2,    KC_3, KC_4,   KC_5, KC_6,    KC_7, KC_8,   KC_9,    KC_0,    KC_MINS,    KC_EQL,  KC_BSPC,
      KC_TAB,  KC_Q,  KC_W,    KC_E, KC_R,   KC_T, KC_Y,    KC_U, KC_I,   KC_O,    KC_P,    KC_LBRC,    KC_RBRC, TG(_GAMING),
      TT(_FN), KC_A,  KC_S,    KC_D, KC_F,   KC_G, KC_H,    KC_J, KC_K,   KC_L,    KC_SCLN, KC_QUOT,              KC_ENT,
      KC_LSFT,        KC_Z,    KC_X, KC_C,   KC_V, KC_B,    KC_N, KC_M,   KC_COMM, KC_DOT,  KC_SLSH,             RSFT_T(KC_UP),
      KC_LCTL, KC_LGUI, KC_LALT,       KC_SPC,       KC_SPC,       OSM(MOD_RALT), LT(_FN, KC_LEFT), MT(MOD_LGUI, KC_DOWN), RCTL_T(KC_RIGHT)
  ),

  /* Keymap Fn Layer
   * ,-----------------------------------------------------.
   * | ` |F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del|
   * |-----------------------------------------------------|
   * |Reset|Tog|Nxt| V-| V+|Hue-|Hue+|Sat-|Sat+|Val-|Prnt|Val+|   |Game|
   * |-----------------------------------------------------|
   * |      |   |   |Ply|Mut|   |Lft|Dow| Up|Rgt|   | ` |    |
   * |-----------------------------------------------------|
   * |        |   |   |Prv|Nxt|   |   |   |   |   |   |Caps |
   * |-----------------------------------------------------|
   * |    |    |     |         |         |   |   |Lock|    |
   * `-----------------------------------------------------'
   */
  [_FN] = LAYOUT_60_ansi_split_space(
      KC_GRAVE, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10, KC_F11,          KC_F12,  KC_DEL,
      QK_BOOT,  RM_TOGG, RM_NEXT, KC_VOLD, KC_VOLU, RM_HUED, RM_HUEU, RM_SATD, RM_SATU, RM_VALD, KC_PSCR, RM_VALU,         _______, TG(_GAMING),
      _______,  _______, _______, KC_MPLY, KC_MUTE, _______, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, _______, KC_GRAVE,        _______,
      _______,           _______, _______, KC_MPRV, KC_MNXT, _______, _______, _______, _______, _______, _______,         KC_CAPS,
      _______,  _______, _______,          _______,          _______,          _______,                            _______, QK_LOCK,   _______
  ),

  /* _FNL Layer
   * ,-----------------------------------------------------.
   * |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
   * |-----------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |   |   |   |
   * |-----------------------------------------------------|
   * |      |   |   |   |   |   |Lft|Dow| Up|Rgt|CwT|   |    |
   * |-----------------------------------------------------|
   * |        |   |   |   |   |   |Hom|PDn|PUp|End|   |     |
   * |-----------------------------------------------------|
   * |    |    |     |         |         |   |   |   |    |
   * `-----------------------------------------------------'
   */
  [_FNL] = LAYOUT_60_ansi_split_space(
      _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT, CW_TOGG, _______,          _______,
      _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP,   KC_END, _______,                   _______,
      _______, _______, _______,          _______,          _______,          _______, _______, _______, _______
  ),

  /* _FNR Layer
   * ,-----------------------------------------------------.
   * |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
   * |-----------------------------------------------------|
   * |     | 7 | 8 | 9 |   |   |   |   |   |   |   |   |   |   |
   * |-----------------------------------------------------|
   * |       | 4 | 5 | 6 |   |   |   |   |   |   |   |   |    |
   * |-----------------------------------------------------|
   * |        | 1 | 2 | 3 |   |   |   |   |   |   |   |     |
   * |-----------------------------------------------------|
   * |    |    |     | 0       |         |   |   |   |    |
   * `-----------------------------------------------------'
   */
  [_FNR] = LAYOUT_60_ansi_split_space(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______,    KC_7,    KC_8,    KC_9, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______,    KC_4,    KC_5,    KC_6, _______, _______, _______, _______, _______, _______, _______,          _______,
      _______, _______,    KC_1,    KC_2,    KC_3, _______, _______, _______, _______, _______, _______,                   _______,
      _______, _______, _______,             KC_0,          _______,          _______, _______, _______, _______
  )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
