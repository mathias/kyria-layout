# @mathias Kyria Keymap

This keymap contains ~5~ 4 layers which allows it to include all keys found on an ANSI layout TKL keyboard plus media keys.
Hardware features of the Kyria such as OLEDs, rotary encoders and underglow are also supported.

The five different layers are the following:
1. Base layer (Colemak-DH, QWERTY, ~or Dvorak~)
2. Navigation layer
3. Symbols/Numbers layer
4. Function layer
5. Adjust layer

## Base layer(s)
```
Base Layer: -

  /*
   * ,-----------------------------------------.                              ,-----------------------------------------.
   * | TAB  |   |      |      |      |      |                              |      |      |      |      |      | BSPC |
   * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
   * |LSFT ⇧|      |      |      |      |      |                              |      |      |      |      |      | ' "  |
   * |------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------|
   * |CTL/ES|      |      |      |      |      |      | NAV  |  |FKEYS |      |      |      |      |      |      |ALT/EN|
   * `------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------'
   *                      |ADJUST|LGUI ◆|LSFT ⇧| BSPC |LCTL ⎈|  |ALT/EN| SPC  | SYM  |RGUI ◆| APP  |
   *                      |      |      |      |      |      |  |      |      |      |      |      |
   *                      `----------------------------------'  `----------------------------------'
   */
```
Three different well-known keyboard layouts are provided to fill in the placeholder `-` keys: QWERTY, Colemak-DH, and Dvorak. The default layer can be changed at runtime, more info on that in the section on the [adjust layer](#adjust-layer).

For the rest of this write-up, the base layer will be assumed to be QWERTY and will be used as a reference to describe physical keys, e.g. “<kbd>B</kbd> key” vs, the much more verbose, “lower inner index key”.

```
  /*
   * Base Layer: Colemak DH
   * ,-----------------------------------------.                              ,-----------------------------------------.
   * | TAB  |  Q   |  W   |  F   |  P   |  B   |                              |  J   |  L   |  U   |  Y   | : ;  | BSPC |
   * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
   * |LSFT ⇧|  A   |  R   |  S   |  T   |  G   |                              |  M   |  N   |  E   |  I   |  O   | ' "  |
   * |------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------|
   * |CTL/ES|  Z   |  X   |  C   |  D   |  V   |  [   | NAV  |  |FKEYS |  ]   |  K   |  H   | , <  | . >  | / ?  |ALT/EN|
   * `------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------'
   *                      |ADJUST|LGUI ◆|LSFT ⇧| BSPC |LCTL ⎈|  |ALT/EN| SPC  | SYM  |RGUI ◆| APP  |
   *                      |      |      |      |      |      |  |      |      |      |      |      |
   *                      `----------------------------------'  `----------------------------------'
   */
```

```
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
```

## Navigation layer

```
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
```

## Sym layer
```
  /*
   * Sym Layer: Numbers and symbols
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
```
The top row is the unshifted num row, the home row of the layer is the shifted num row and the bottom row contains the hyphen `-` and the underscore `_` on the best lower row spot because of how frequent they are as well as redundant symbols that are already present on the base layer but are reproduced here to avoid juggling back and forth between base, shift, and sym when typing a string of symbols.


## Function layer
```
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
```
In a similar fashion to the nav layer, pressing down `FKEYS` with the right thumb enables a numpad of function keys on the opposite hand and modifiers on the right-hand home row. Once again, mirror symmetry is leveraged in this keymap for the order of the right-hand modifiers.

The <kbd>Alt</kbd> modifier, despite being situated on the right half of the keyboard is *not* `KC_RALT`, it is `KC_LALT`. `KC_RALT` is actually the <kbd>AltGr</kbd> key which generally acts very differently to the left <kbd>Alt</kbd> key. Keyboard shortcuts involving <kbd>AltGr</kbd>+<kbd>F#</kbd> are rare and infrequent as opposed to the much more common <kbd>Alt</kbd>+<kbd>F#</kbd> shortcuts. Consequently, `KC_LALT` was chosen for the function layer.

Since there are more than 10 function keys, the cluster of F-keys does not follow the usual 3×3+1 numpad arrangement.


## Adjust layer
```
Adjust Layer: Default layer settings, RGB
                                                                                                                         
,-------------------------------------------.                              ,-------------------------------------------.
|        |      |      |QWERTY|      |      |                              |      |      |      |      |      |        |
|--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
|        |      |      |~Dvor~|      |      |                              | TOG  | SAI  | HUI  | VAI  | MOD  |        |
|--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
|        |      |      |Colmak|      |      |      |      |  |      |      |      | SAD  | HUD  | VAD  | RMOD |        |
`----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
                       |      |      |      |      |      |  |      |      |      |      |      |
                       |      |      |      |      |      |  |      |      |      |      |      |
                       `----------------------------------'  `----------------------------------'
```

Default layer settings on the left and various RGB underglow controls on the right.

The default layer settings are lined up on the middle finger column because the home middle finger key is <kbd>D</kbd> on QWERTY (like the “D” in “Dvorak”) and the lower middle finger key is <kbd>C</kbd> on QWERTY (like the “C” in “Colemak”). I can hear you say that “QWERTY” doesn't start with “E” but Dvorak and Colemak were already aligned in a column so the QWERTY may as well join the formation.

## Hardware Features

### Rotary Encoder
The left rotary encoder is programmed to control the volume whereas the right encoder sends <kbd>PgUp</kbd> or <kbd>PgDn</kbd> on every turn.

### OLEDs
The OLEDs display the current layer at the top of the active layers stack, the Kyria logo and lock status (caps lock, num lock, scroll lock).

### Underglow
The underglow LEDs are controlled by the Adjust layer.

## Make your own Kyria key map

Check out the #keymap-ideas channel on the official SplitKB Discord server for inspiration.
