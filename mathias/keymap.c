/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

enum layers {
    _COLEMAK_DH = 0,
    _QWERTY,
    _NAV,
    _SYM,
    _FUNCTION,
    _ADJUST,
    _SYM2,
};

#ifdef OLED_ENABLE
bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // QMK Logo and version information
    // clang-format off
    static const char PROGMEM qmk_logo[] = {
      0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
      0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
      0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
    // clang-format on

    oled_write_P(qmk_logo, false);
    oled_write_P(PSTR("Kyria - mathias\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state | default_layer_state)) {
      case _QWERTY:
        oled_write_P(PSTR("QWERTY\n"), false);
        break;
      case _COLEMAK_DH:
        oled_write_P(PSTR("Colemak-DH\n"), false);
        break;
      case _NAV:
        oled_write_P(PSTR("Nav\n"), false);
        break;
      case _SYM:
        oled_write_P(PSTR("Sym\n"), false);
        break;
      case _FUNCTION:
        oled_write_P(PSTR("Function\n"), false);
        break;
      case _ADJUST:
        oled_write_P(PSTR("Adjust\n"), false);
        break;
      default:
        oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_P(led_usb_state.num_lock ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(led_usb_state.caps_lock ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);

    return false;
  } else {
    // clang-format off
    static const char PROGMEM qmk_logo[] = {
      0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
      0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
      0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
    // clang-format on

    oled_write_P(qmk_logo, false);

    return false;
  }
}
#endif


// Aliases for readability
#define QWERTY   DF(_QWERTY)
#define COLEMAK  DF(_COLEMAK_DH)
//#define DVORAK   DF(_DVORAK)

#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define FKEYS    MO(_FUNCTION)
#define ADJUST   MO(_ADJUST)
#define SYM2     MO(_SYM2)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
   * Base Layer: Colemak DH
   * ,-----------------------------------------.                              ,-----------------------------------------.
   * | TAB  |  Q   |  W   |  F   |  P   |  B   |                              |  J   |  L   |  U   |  Y   | : ;  | BSPC |
   * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
   * |LSFT ⇧|  A   |  R   |  S   |  T   |  G   |                              |  M   |  N   |  E   |  I   |  O   | ' "  |
   * |------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------|
   * |CTL/ES|  Z   |  X   |  C   |  D   |  V   |  [   | NAV  |  |FKEYS |  ]   |  K   |  H   | , <  | . >  | / ?  |ALT/EN|
   * `------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------'
   *                      |ADJUST|LGUI ◆|LSFT ⇧| BSPC |LCTL ⎈|  |ALT/EN| SPC  | SYM  |RGUI ◆| SYM2 |
   *                      |      |      |      |      |      |  |      |      |      |      |      |
   *                      `----------------------------------'  `----------------------------------'
   */
  [_COLEMAK_DH] = LAYOUT(
      KC_TAB  , KC_Q ,  KC_W   ,  KC_F  ,   KC_P ,   KC_B ,                                        KC_J,   KC_L ,  KC_U ,   KC_Y ,KC_SCLN, KC_BSPC,
      KC_LSFT , KC_A ,  KC_R   ,  KC_S  ,   KC_T ,   KC_G ,                                        KC_M,   KC_N ,  KC_E ,   KC_I ,  KC_O , KC_QUOT,
      CTL_ESC, KC_Z ,  KC_X   ,  KC_C  ,   KC_D ,   KC_V ,KC_LBRC, NAV,      FKEYS  , KC_RBRC,  KC_K,   KC_H ,KC_COMM, KC_DOT ,KC_SLSH, ALT_ENT,
      ADJUST, KC_LGUI, KC_LSFT, KC_BSPC,KC_LCTL,   ALT_ENT, KC_SPC ,  SYM  , KC_RGUI, SYM2
      ),

  /*
   * Base Layer: QWERTY
   *
   * ,-----------------------------------------.                              ,-----------------------------------------.
   * | TAB  |  Q   |  W   |  E   |  R   |  T   |                              |  Y   |  U   |  I   |  O   |  P   | BSPC |
   * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
   * |LSFT ⇧|  A   |  S   |  D   |  F   |  G   |                              |  H   |  J   |  K   |  L   | : ;  | ' "  |
   * |------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------|
   * |CTL/ES|  Z   |  X   |  C   |  V   |  B   |  [   | NAV  |  |FKEYS |  ]   |  N   |  M   | , <  | . >  | / ?  |ALT/EN|
   * `------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------'
   *                      |ADJUST|LGUI ◆|LSFT ⇧| BSPC |LCTL ⎈|  |ALT/EN| SPC  | SYM  |RGUI ◆| APP  |
   *                      |      |      |      |      |      |  |      |      |      |      |      |
   *                      `----------------------------------'  `----------------------------------'
   */
  [_QWERTY] = LAYOUT(
      KC_TAB  , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                        KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_BSPC,
      KC_LSFT , KC_A ,  KC_S   ,  KC_D  ,   KC_F ,   KC_G ,                                        KC_H,   KC_J ,  KC_K ,   KC_L ,KC_SCLN, KC_QUOT,
      CTL_ESC, KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , KC_LBRC, NAV,     FKEYS  , KC_RBRC,  KC_N,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, ALT_ENT,
      ADJUST, KC_LGUI, KC_LSFT, KC_BSPC,KC_LCTL,    ALT_ENT, KC_SPC ,  SYM , KC_RGUI, KC_APP
      ),

  /*
   * Nav Layer: Media, navigation
   *
   *  ,-----------------------------------------.                              ,-----------------------------------------.
   * |      |      |      |      |      |      |                              | PGUP | HOME |  UP  | END  | VOLU | DEL  |
   * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
   * |      |LGUI ◆|LALT ⎇|LCTL ⎈|LSFT ⇧|      |                              | PGDN | LEFT | DOWN | RGHT | VOLD | Ins  |
   * |------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |ScrLoc|  |      |      |PAUSE | MPRV | MPLY | MNXT | MUTE |PrintS|
   * `------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------'
   *                      |      |      |      |      |      |  |      |      |      |      |      |
   *                      |      |      |      |      |      |  |      |      |      |      |      |
   *                      `----------------------------------'  `----------------------------------'
   */
  [_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_VOLU, KC_DEL,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, KC_INS,
      _______, _______, _______, _______, _______, _______, _______, KC_SLCK, _______, _______,KC_PAUSE, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_PSCR,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
      ),

  /*
   * Sym Layer: Numbers and symbols
   *
   * ,-------------------------------------------.                              ,-------------------------------------------.
   * |        |  !   |  @   |  |   |   {  |  }   |                              |      |  7   |  8   |  9   |  *   |        |
   * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
   * |        | Tab  |  $   |  '"  |   (  |  )   |                              | - _  |  4   |  5   |  6   |  \|  |        |
   * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
   * |        |  %   |  ^   |  ~   |   [  |  ]   |      |      |  |      |      |  0   |  1   |  2   |  3   |  =+  |        |
   * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
   *                        |      |      |LSHFT |      |      |  |      |      |      |      |      |
   *                        |      |      |      |      |      |  |      |      |      |      |      |
   *                        `----------------------------------'  `----------------------------------'
   */
       [_SYM] = LAYOUT(
         _______, KC_EXCLAIM, KC_AT, KC_PIPE, KC_LCBR, KC_RCBR,                                     _______, KC_7, KC_8, KC_9, KC_KP_ASTERISK, _______,
         _______, KC_TAB, KC_DOLLAR, KC_QUOT, KC_LPRN, KC_RPRN,                                    KC_MINS, KC_4, KC_5, KC_6, KC_BSLS, _______,
         _______, KC_PERC, KC_CIRC, KC_TILD, KC_LBRC, KC_RBRC, _______, _______, _______, _______, KC_0, KC_1, KC_2, KC_3, KC_EQUAL, _______,
                                    _______, _______, KC_LSFT, _______, _______, _______, _______, _______, _______, _______
       ),

  /*
   * Old sym Layer (SYM2): Numbers and symbols
   * ,-----------------------------------------.                              ,-----------------------------------------.
   * |  `   |  1   |  2   |  3   |  4   |  5   |                              |  6   |  7   |  8   |  9   |  0   |  =   |
   * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
   * |  ~   |  !   |  @   |  #   |  $   |  %   |                              |  ^   |  &   |  *   |  (   |  )   |  +   |
   * |------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------|
   * |  |   | \ |  |  :   | : ;  | - _  |  [   |  {   |      |  |      |  }   |  ]   |  _   | , <  | . >  | / ?  | ? !  |
   * `------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------'
   *                      |      |      |      |      |      |  |      |      |      |      |      |
   *                      |      |      |      |      |      |  |      |      |      |      |      |
   *                      `----------------------------------'  `----------------------------------'
   */
  [_SYM2] = LAYOUT(
      KC_GRV ,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5 ,                                       KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,   KC_0 , KC_EQL ,
      KC_TILD , KC_EXLM,  KC_AT , KC_HASH,  KC_DLR, KC_PERC,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
      KC_PIPE , KC_BSLS, KC_COLN, KC_SCLN, KC_MINS, KC_LBRC, KC_LCBR, _______, _______, KC_RCBR, KC_RBRC, KC_UNDS, KC_COMM,  KC_DOT, KC_SLSH, KC_QUES,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
      ),

  /*
   * Function Layer: Function keys
   *
   * ,-------------------------------------------.                              ,-------------------------------------------.
   * |        |  F9  | F10  | F11  | F12  |      |                              |      |      |      |      |      |        |
   * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
   * |        |  F5  |  F6  |  F7  |  F8  |      |                              |      | Shift| Ctrl |  Alt |  GUI |        |
   * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
   * |        |  F1  |  F2  |  F3  |  F4  |      |      |      |  |      |      |      |      |      |      |      |        |
   * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
   *                        |      |      |      |      |      |  |      |      |      |      |      |
   *                        |      |      |      |      |      |  |      |      |      |      |      |
   *                        `----------------------------------'  `----------------------------------'
   */
  [_FUNCTION] = LAYOUT(
      _______,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, _______,                                     _______, _______, _______, _______, _______, _______,
      _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______,                                     _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, _______,
      _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
      ),

  /*
   * Adjust Layer: Default layer settings, RGB
   *
   * ,-------------------------------------------.                              ,-------------------------------------------.
   * |        |      |      |QWERTY|      |      |                              |      |      |      |      |      |        |
   * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
   * |        |      |      |      |      |      |                              | TOG  | SAI  | HUI  | VAI  | MOD  |        |
   * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
   * |        |      |      |Colmak|      |      |      |      |  |      |      |      | SAD  | HUD  | VAD  | RMOD |        |
   * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
   *                        |      |      |      |      |      |  |      |      |      |      |      |
   *                        |      |      |      |      |      |  |      |      |      |      |      |
   *                        `----------------------------------'  `----------------------------------'
   */
  [_ADJUST] = LAYOUT(
      _______, _______, _______, QWERTY , _______, _______,                                    _______, _______, _______, _______,  _______, _______,
      _______, _______, _______, _______, _______, _______,                                    RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI,  RGB_MOD, _______,
      _______, _______, _______, COLEMAK, _______, _______,_______, _______, _______, _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, _______,
      _______, _______, _______,_______, _______, _______, _______, _______, _______, _______
      ),

  // /*
  //  * Layer template
  //  *
  //  * ,-------------------------------------------.                              ,-------------------------------------------.
  //  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
  //  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
  //  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
  //  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
  //  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
  //  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
  //  *                        |      |      |      |      |      |  |      |      |      |      |      |
  //  *                        |      |      |      |      |      |  |      |      |      |      |      |
  //  *                        `----------------------------------'  `----------------------------------'
  //  */
  //     [_LAYERINDEX] = LAYOUT(
  //       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
  //       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
  //       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  //                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  //     ),
};
