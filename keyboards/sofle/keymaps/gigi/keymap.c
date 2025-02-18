/* Copyright 2020 Josef Adamcik
 * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
 * Modification for Vial support by Drew Petersen
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

// clang-format off

#include <stdio.h>

#include QMK_KEYBOARD_H
#include "layers.h"
#include "encoder.c"
#include "oled.c"
#include "rgb.c"


// Tap Dance declarations
enum {
    TD_LSHIFT_CAPS,
    TD_RSHIFT_CAPS,
    TD_ESC_GRV,
    TD_MUTE_PLAY
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_LSHIFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [TD_RSHIFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_RSFT, KC_CAPS),
    [TD_ESC_GRV] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_GRV),
    [TD_MUTE_PLAY] = ACTION_TAP_DANCE_DOUBLE(KC_MUTE, KC_MPLY),
};

// shortcuts

#define KC_TAB_NUM LT(_NUMPAD, KC_TAB)
#define KC_LSHIFT_CAPS TD(TD_LSHIFT_CAPS)
#define KC_RSHIFT_CAPS TD(TD_RSHIFT_CAPS)
#define KC_ESC_GRV TD(TD_ESC_GRV)
#define KC_SYMBO MO(_SYMBOL)
#define KC_MOVE MO(_MOVE)

// Default keymap. This can be changed in Vial. Use oled.c to change beavior that Vial cannot change.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC|`|   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | DEL  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |TAB|NUM|  A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |KC_HOME|------+------+------+------+------+------|
 * |LGUI  |   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |  INS
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *     | LALT | LCTL | LSHIFT_CAPS |LOWER | /Space  /       \Enter \  |RAISE | RSHIFT_CAPS | RCTL | RALT |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_COLEMAKDH] = LAYOUT(
        KC_ESC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS,
            KC_DEL,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_BSPC,
          KC_TAB_NUM, KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                KC_M,    KC_N,    KC_E,    KC_I,    KC_O,  KC_QUOT,
            KC_LGUI,  KC_Z,   KC_X,    KC_C,    KC_D,    KC_V, KC_MUTE,       KC_HOME,  KC_K,    KC_H,    KC_COMM, KC_DOT, KC_SLSH,  KC_INS,
                KC_LALT ,  KC_LCTL, KC_LSHIFT_CAPS , KC_SYMBO , KC_SPC,       KC_ENT,  KC_MOVE, KC_RSHIFT_CAPS, KC_RCTL, KC_RALT
),
/* SYMBOL
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  |   +  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F11 | F12  |      |      |      |                    |KC_MPRV|KC_MNXT|    |   [  |   ]  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |   {  |   }  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |KC_HOME|------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |   =  |   \  | INS  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *     | LALT | LCTL | LSHIFT_CAPS |LOWER | /Space  /       \Enter \  |RAISE | RShift | RCTL | RALT |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_SYMBOL] = LAYOUT(
   XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_PLUS,
   XXXXXXX,   KC_F11, KC_F12  , XXXXXXX,XXXXXXX,XXXXXXX,                       KC_MPRV, KC_MNXT, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX,
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, KC_PIPE,
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,       _______, _______, _______, XXXXXXX, KC_EQL, KC_BSLS, _______,
                     _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
/* MOVE
 * ,----------------------------------------.                     ,-----------------------------------------.
 * |      |      |   |UG_TOGG|UG_PREV|UG_NEXT|                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |   |LM_TOGG|LM_PREV|LM_NEXT|                    | PgUp |      |  Up  |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |    |LM_BRID|LM_BRIU|-------.    ,-------|PgDown| Left | Down | Rigth|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      | Undo |  Cut | Copy | Paste|      |-------|    |-------| Home | End  |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_MOVE] = LAYOUT(
  XXXXXXX, XXXXXXX , XXXXXXX , UG_TOGG, UG_PREV , UG_NEXT,                      XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,  XXXXXXX,  XXXXXXX,  LM_TOGG, LM_PREV, LM_NEXT,                     KC_PGUP, XXXXXXX,   KC_UP,  XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  LM_BRID, LM_BRIU,                       KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT,  XXXXXXX, XXXXXXX,
  XXXXXXX,KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, XXXXXXX,  _______,       _______,  KC_HOME,  KC_END, XXXXXXX, XXXXXXX,   XXXXXXX, _______,
                    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),

/* NUMPAD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | trans|      |      |      |      |      |                    |      |NumLck|      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |      |      |      |      |      |                    |   ^  |   7  |   8  |   9  |   *  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | trans|      |      |      |      |      |-------.    ,-------|   -  |   4  |   5  |   6  |   =  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | trans|      |      |      |      |      |-------|    |-------|   +  |   1  |   2  |   3  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | Bspc | WIN  |LOWER | Enter| /Space  /       \Enter \  |SPACE | 0    |  .   | RAlt |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_NUMPAD] = LAYOUT(
    //,------------------------------------------------.                    ,---------------------------------------------------.
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   _______, KC_NUM,  XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,
    //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_CIRC, KC_P7,  KC_P8,   KC_P9,   KC_ASTR, XXXXXXX,
    //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_MINS, KC_P4,  KC_P5,   KC_P6,   KC_EQL,  KC_PIPE,
    //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,_______,   _______,KC_PLUS, KC_P1,  KC_P2,   KC_P3,   KC_SLSH, _______,
    //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                _______, OSM(MOD_MEH), _______, _______, _______,   _______, _______,  KC_P0,   KC_PDOT, _______
    //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
)
};
