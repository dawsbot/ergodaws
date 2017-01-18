#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define NUM 3 // number keypad

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  |  [   |           |  ]   |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  | E/L4 |   R  |   T  |  (   |           |  )   |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Ctrl/Esc| A/L1 | S/L2 | D/L3 |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|   '    |
 * |--------+------+------+------+------+------|  {   |           |  }   |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |L2    |  '"  | Ctrl |  Alt | LGui |                                       | LGui | Left | Down |  Up  | Right |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,----------------.
 *                                        | Copy |Paste |       |VolumeD|VolumeU |
 *                                 ,------|------|------|       |-------+--------+------.
 *                                 |      |      |BriteU|       | PgUp  |        |      |
 *                                 |Bakspc| Enter|------|       |-------| Enter  |Space |
 *                                 |      |      |BriteD|       |Ctrl+C |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_EQL,         KC_1,           KC_2,           KC_3,            KC_4,      KC_5,   KC_LBRC,
        KC_TAB,         KC_Q,           KC_W,           KC_E,            KC_R,      KC_T,   KC_LPRN,
        CTL_T(KC_ESC),  LT(SYMB, KC_A), LT(MDIA, KC_S), LT(NUM, KC_D),   KC_F,      KC_G,
        KC_LSFT,        CTL_T(KC_Z),    KC_X,           KC_C,            KC_V,      KC_B,   KC_LCBR,
        TG(MDIA),       KC_QUOT,        KC_LCTL,        KC_LALT,         KC_LGUI,
                                                                         LGUI(KC_C),LGUI(KC_V),
                                                                                    KC_PAUS,
                                                        KC_BSPC,         KC_ENT,    KC_SLCK,
        // right hand
        KC_RBRC,      KC_6,   KC_7,     KC_8,      KC_9,   KC_0,             KC_MINS,
        KC_RPRN,      KC_Y,   KC_U,     KC_I,      KC_O,   KC_P,             KC_BSLS,
                      KC_H,   KC_J,     KC_K,      KC_L,   KC_SCLN,          KC_QUOT,
        KC_RCBR,      KC_N,   KC_M,     KC_COMM,   KC_DOT, CTL_T(KC_SLSH),   KC_RSFT,
                              KC_LGUI,  KC_LEFT,   KC_DOWN,KC_UP,            KC_RIGHT,
        KC_VOLD,     KC_VOLU,
        KC_PGUP,
        LCTL(KC_C),  KC_ENT,  KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   ~  |      |           |      |      |      |      |      |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |   $  |      |      |------|           |------| Left | Down |  Up  | Right|   `  |   `    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   |  |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_TRNS,   KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_TRNS,
       KC_TRNS,   KC_EXLM,   KC_AT,     KC_LCBR,   KC_RCBR,   KC_TILD,   KC_TRNS,
       KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_DLR,    KC_TRNS,   KC_TRNS,
       KC_TRNS,   KC_PERC,   KC_CIRC,   KC_LBRC,   KC_RBRC,   KC_PIPE,   KC_TRNS,
       KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
                                                              KC_TRNS,   KC_TRNS,
                                                                         KC_TRNS,
                                                   KC_TRNS,   KC_TRNS,   KC_TRNS,

      // right hand
      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_PLUS,    KC_TRNS,
                  KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   KC_GRV,     KC_GRV,
      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                              KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
      KC_TRNS,    KC_TRNS,
      KC_TRNS,
      KC_TRNS,    KC_TRNS,    KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      | Play |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------| Prev | VolUp| VolDn| Next |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |  w   |    w |------|       |------|      |      |
 *                                 |      |      |space |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                    KC_TRNS, KC_TRNS,
                                                             KC_TRNS,
                                           KC_W,    KC_W,    KC_SPC,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY, KC_TRNS,
                 KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 3: Number Keypad Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   7  |   8  |   9  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |   4  |   5  |   6  |  -   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   1  |   2  |   3  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |    . |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NUM] = KEYMAP(
       // left hand
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_7,     KC_8,     KC_9,     KC_TRNS,  KC_TRNS,
                 KC_TRNS,  KC_4,     KC_5,     KC_6,     KC_MINS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_1,     KC_2,     KC_3,     KC_TRNS,  KC_TRNS,
                           KC_0,     KC_DOT,   KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,
       KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS
)};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs when the keyboard initializes and when power is in sleep mode
void matrix_init_user(void) {
    wait_ms(2000);
};

// Runs constantgly in the background, in a loop.
void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }

};
