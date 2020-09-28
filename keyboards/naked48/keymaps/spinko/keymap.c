#include QMK_KEYBOARD_H
#include "quantum.h"
#define AUTO_SHIFT_MODIFIERS

// Flash with: make naked48:spinko:dfu

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _OPPOSIT 1
#define _MOUSE 2
#define _NAV 3
#define _NPAD 4
#define _SYM 5

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYM,
  SYM_LCK,
  NAV,
  NAV_LCK,
  NPADLCK,
  NPADTMP,
  MOUSE,
  OPPOSIT
};

#define SYM MO(_SYM)
#define SYM_LCK TG(_SYM)
#define NAV MO(_NAV)
#define NAV_LCK TG(_NAV)
#define NPADLCK TG(_NPAD)
#define NPADTMP MO(_NPAD)
#define MOUSE TG(_MOUSE)
#define OPPTEMP MO(_OPPOSIT)
#define OPPOSIT OSL(_OPPOSIT)

/****************/
/* Start Keymap */
/****************/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT(
   LT(NAV, KC_DEL),      KC_Q,               KC_W,             KC_E,                     KC_R,            KC_T,                                                       KC_Y,              KC_U,             KC_I,                       KC_O,             KC_P,                       KC_BSPC,                       \
   LT(OPPTEMP, KC_TAB),  KC_A,               KC_S,             KC_D,                     KC_F,            KC_G,                                                       KC_H,              KC_J,             KC_K,                       KC_L,             LT(NAV, KC_SCLN),           LT(OPPTEMP, KC_TAB),           \
   LT(SYM, KC_ESC),      LT(NPADTMP, KC_Z),  KC_X,             KC_C,                     KC_V,            KC_B,                                                       KC_N,              KC_M,             KC_COMM,                    RALT_T(KC_DOT),   LT(NPADTMP, KC_SLSH),       LT(SYM, KC_QUOT),              \
                         LCTL_T(KC_GRV),     LALT_T(KC_EQL),   LALT_T(KC_MINS),          KC_LSFT,         LCMD_T(KC_SPC),  LT(OPPTEMP, KC_ENT),  LT(OPPTEMP,KC_ENT),  RCMD_T(KC_SPC),    KC_RSFT,          RALT_T(KC_LBRC),            RALT_T(KC_RBRC),  RCTL_T(KC_BSLS)                                            \
),

[_NAV] = LAYOUT(
   NAV_LCK,      LCMD(KC_LSFT),    LALT(KC_LSFT),        KC_UP,              LALT(KC_LCMD),     KC_VOLU,                                    KC_PGUP,         KC_RCTL,           KC_UP,            KC_RCTL,                    OPPOSIT,          KC_BSPC, \
   _______,      KC_LCTL,          LALT_T(KC_LEFT),      LSFT_T(KC_DOWN),    LCMD_T(KC_RGHT),   KC_VOLD,                                    KC_PGDN,         KC_LEFT,           KC_DOWN,          KC_RGHT,                    _______,          KC_DEL,  \
   KC_BRID,      KC_BRIU,          LALT_T(KC_MPRV),      KC_MNXT,            LALT_T(KC_MPLY),   KC_MUTE,                                    KC_RCMD,         KC_RALT,           MOUSE,            KC_RALT,                    KC_ESC,           KC_TAB,  \
                 _______,          _______,              _______,            _______,           _______,           KC_BSPC,      MOUSE,     _______,         _______,           _______,          _______,                    _______                    \
),

[_SYM] = LAYOUT(
    SYM_LCK,      KC_GRV,       KC_AMPR,      KC_ASTR,      KC_LPRN,      KC_RPRN,                        _______,      KC_AMPR,      KC_ASTR,      KC_LPRN,     KC_RPRN,      KC_BSPC,  \
    _______,      KC_EQL,       KC_DLR,       KC_PERC,      KC_CIRC,      _______,                        _______,      KC_DLR,       KC_PERC,      KC_CIRC,     KC_COLN,      KC_GRV,   \
    SYM_LCK,      KC_MINS,      KC_EXLM,      KC_AT,        KC_HASH,      OPPOSIT,                        OPPOSIT,      KC_EXLM,      KC_AT,        KC_HASH,     KC_QUES,      KC_TAB,   \
                  _______,      KC_PLUS,      KC_UNDS,      _______,      OPPTEMP,  KC_BSPC,   _______,   OPPTEMP,      _______,      KC_LPRN,      KC_RPRN,     KC_PIPE                \
),

[_NPAD] = LAYOUT(
    NPADLCK,      _______,      KC_7,         KC_8,         KC_9,        KC_BSPC,                          _______,      KC_7,        KC_8,         KC_9,         KC_0,             KC_BSPC, \
    _______,      _______,      KC_4,         KC_5,         KC_6,        KC_DOT,                           _______,      KC_4,        KC_5,         KC_6,         _______,          KC_DEL,  \
    NPADLCK,      _______,      KC_1,         KC_2,         KC_3,        KC_0,                             KC_0,         KC_1,        KC_2,         KC_3,         _______,          KC_TAB,  \
                  _______,      _______,      _______,      _______,     _______,  KC_BSPC,   _______,     _______,      _______,     KC_0,         _______,      _______                   \
),

[_MOUSE] = LAYOUT(
    MOUSE,        _______,      _______,      _______,      _______,      KC_WH_D,                        KC_WH_D,      KC_MS_BTN1,   KC_MS_UP,         KC_MS_BTN2,     MOUSE,         _______,  \
    _______,      KC_WH_L,      KC_ACL0,      KC_ACL1,      KC_ACL2,      KC_WH_R,                        KC_WH_R,      KC_MS_LEFT,   KC_MS_DOWN,       KC_MS_RIGHT,    _______,       _______,  \
    MOUSE,        RGB_HUI,      RGB_SAI,      RGB_VAI,      RGB_MODE_XMAS,KC_WH_U,                        KC_WH_U,      _______,      _______,          _______,        _______,       _______,  \
                  _______,      _______,      _______,      _______,      _______,  RGB_TOG,    RGB_MOD,  _______,      _______,      KC_MS_BTN1,       _______,        _______                  \
),

[_OPPOSIT] = LAYOUT(
   KC_BSPC,                  KC_P,                  KC_O,             KC_I,                KC_U,            KC_Y,                               KC_T,              KC_R,             KC_E,                  KC_W,             KC_Q,                       KC_DEL,                          \
   LT(OPPTEMP, KC_TAB),      LT(NAV, KC_SCLN),      KC_L,             KC_K,                KC_J,            KC_H,                               KC_G,              KC_F,             KC_D,                  KC_S,             LT(NAV, KC_A),              LT(OPPTEMP, KC_TAB),             \
   LT(SYM, KC_QUOT),         LT(NPADTMP, KC_SLSH),  KC_DOT,           KC_COMM,             KC_M,            KC_N,                               KC_B,              KC_V,             KC_C,                  KC_X,             LT(NPADTMP, KC_Z),          LT(SYM, KC_ESC),                 \
                             LCTL_T(KC_BSLS),       KC_RBRC,          LALT_T(KC_LBRC),     KC_LSFT,         LCMD_T(KC_SPC),  KC_ENT,  KC_ENT,   RCMD_T(KC_SPC),    KC_RSFT,          RALT_T(KC_MINS),       KC_EQL,           RCTL_T(KC_GRV)                                               \
)
};
