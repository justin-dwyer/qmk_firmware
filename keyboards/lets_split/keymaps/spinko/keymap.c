#include QMK_KEYBOARD_H
#define AUTO_SHIFT_MODIFIERS
#define hand_swap_config

// Flash with: make lets_split/rev2:spinko:dfu

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
#define AC(X) A(C(X))
#define SC(X) S(C(X))

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYM,
  SYM_LCK,
  NAV,
  NAV_LCK,
  NPADLCK,
  NPADTMP,
  MOUSE,
  OPPOSIT,
  M_BSDEL
  // LSWAP_TAB,
  // RSWAP_TAB
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

/* Tap Dance */
// enum {
//   LPAR_BRC = 0,
//   RPAR_BRC,
//   SLS_BSLS,
//   COM_PERC,
//   EXCLM_AT,
//   HASH_DLR,
//   GRV_CIRC,
//   EQL_ASTR,
//   MINS_AMP,
//   MINS_GRV,
//   SHIFT_OP
// };

/* Custom Tapping Terms: https://docs.qmk.fm/#/custom_quantum_functions?id=custom-tapping-term */
uint16_t get_tapping_term(uint16_t keycode) {
  switch (keycode) {
//     case TD(LPAR_BRC):
//       return 300;
//     case TD(RPAR_BRC):
//       return 300;
//     case TD(SLS_BSLS):
//       return 300;
//     case TD(COM_PERC):
//       return 300;
//     case TD(EXCLM_AT):
//       return 300;
//     case TD(MINS_AMP):
//       return 300;
//     case TD(MINS_GRV):
//       return 300;
//     case TD(EQL_ASTR):
//       return 300;
//     case TD(HASH_DLR):
//       return 300;
//     case TD(GRV_CIRC):
//       return 300;
    // case LT(NAV, KC_A):
    //   return 5000;
    default:
      return TAPPING_TERM;
  }
}
/* End Custom Tapping Terms */

/******************/
// https://docs.qmk.fm/#/feature_tap_dance?id=example-4-39quad-function-tap-dance39
typedef struct {
  bool is_press_action;
  int state;
} tap;

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5, //send two single taps
  TRIPLE_TAP = 6,
  TRIPLE_HOLD = 7
};

//Tap dance enums
enum {
  SFT_ALT = 0,
  SOME_OTHER_DANCE
};

int cur_dance (qk_tap_dance_state_t *state);

//for the x tap dance. Put it here so it can be used in any keymap
void x_finished (qk_tap_dance_state_t *state, void *user_data);
void x_reset (qk_tap_dance_state_t *state, void *user_data);

// End https://docs.qmk.fm/#/feature_tap_dance?id=example-4-39quad-function-tap-dance39
/*********************/

/*
    MOUSE,        _______,      _______,      _______,      KC_WH_D,      _______,   _______,    KC_MS_BTN1,    KC_MS_UP,       KC_MS_BTN2,     _______,       _______,  \
    _______,      KC_WH_L,      KC_ACL0,      KC_ACL1,      KC_ACL2,      KC_WH_R,   _______,    KC_MS_LEFT,    KC_MS_DOWN,     KC_MS_RIGHT,    _______,       _______,  \
    _______,      _______,      _______,      _______,      KC_WH_U,      _______,   _______,    _______,       _______,        MOUSE,          _______,       _______,  \
    _______,      _______,      _______,      _______,      _______,      _______,   _______,    _______,       _______,        _______,        _______,       _______   \
*/
/* Start Combos */
// enum combo_events {
//   M_LCLICK,
//   M_LCLICK,
//   M_RCLICK,
//   // M_UP,
//   // M_RIGHT,
//   // M_DOWN,
//   // M_LEFT
// };

// const uint16_t PROGMEM click_combo[] = {KC_J, KC_K, COMBO_END};
// const uint16_t PROGMEM rclck_combo[] = {KC_K, KC_L, COMBO_END};
// // const uint16_t PROGMEM up_combo[] = {KC_S, KC_D, COMBO_END};
// // const uint16_t PROGMEM right_combo[] = {KC_D, KC_F, COMBO_END};
// // const uint16_t PROGMEM down_combo[] = {KC_S, KC_F, COMBO_END};
// // const uint16_t PROGMEM left_combo[] = {KC_J, KC_L, COMBO_END};

// combo_t key_combos[COMBO_COUNT] = {
//   [M_LCLICK] = COMBO_ACTION(click_combo),
//   [M_RCLICK] = COMBO_ACTION(rclck_combo),
//   // [M_UP] = COMBO_ACTION(up_combo),
//   // [M_RIGHT] = COMBO_ACTION(right_combo),
//   // [M_DOWN] = COMBO_ACTION(down_combo),
//   // [M_LEFT] = COMBO_ACTION(left_combo)
// };

// void process_combo_event(uint8_t combo_index, bool pressed) {
//   switch(combo_index) {
//     case M_LCLICK:
//       if (pressed) {
//         tap_code16(KC_MS_BTN1);
//       }
//       break;
//     case M_RCLICK:
//       if (pressed) {
//         tap_code16(KC_MS_BTN2);
//       }
//       break;
//     // case M_UP:
//     //   if (pressed) {
//     //     tap_code16(KC_MS_UP);
//     //   }
//     //   break;
//     // case M_RIGHT:
//     //   if (pressed) {
//     //     tap_code16(KC_MS_RIGHT);
//     //   }
//     //   break;
//     // case M_DOWN:
//     //   if (pressed) {
//     //     tap_code16(KC_MS_DOWN);
//     //   }
//     //   break;
//     // case M_LEFT:
//     //   if (pressed) {
//     //     tap_code16(KC_MS_LEFT);
//     //   }
//     //   break;
//   }
// }
/* End Combos */

/****************/
/* Start Keymap */
/****************/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_ortho_4x12(
   LT(NAV, KC_DEL),      KC_Q,               KC_W,             KC_E,                     KC_R,            KC_T,            KC_Y,              KC_U,             KC_I,                       KC_O,             KC_P,                       KC_BSPC,                       \
   LT(OPPTEMP, KC_TAB),  KC_A,               KC_S,             KC_D,                     KC_F,            KC_G,            KC_H,              KC_J,             KC_K,                       KC_L,             LT(NAV, KC_SCLN),           LT(OPPTEMP, KC_TAB),           \
   LT(SYM, KC_ESC),      LT(NPADTMP, KC_Z),  KC_X,             KC_C,                     KC_V,            KC_B,            KC_N,              KC_M,             KC_COMM,                    RALT_T(KC_DOT),   LT(NPADTMP, KC_SLSH),       LT(SYM, KC_QUOT),              \
   KC_ENT,               LCTL_T(KC_GRV),     LALT_T(KC_EQL),   LALT_T(KC_MINS),          KC_LSFT,         LCMD_T(KC_SPC),  RCMD_T(KC_SPC),    KC_RSFT,          RALT_T(KC_LBRC),            RALT_T(KC_RBRC),  RCTL_T(KC_BSLS),            KC_ENT                         \
),

[_NAV] = LAYOUT_ortho_4x12(
   NAV_LCK,      LCMD(KC_LSFT),    LALT(KC_LSFT),        KC_UP,              LALT(KC_LCMD),     KC_VOLU,      KC_PGUP,             KC_RCTL,             KC_UP,                 KC_RCTL,               OPPOSIT,      KC_BSPC, \
   _______,      KC_LCTL,          LALT_T(KC_LEFT),      LSFT_T(KC_DOWN),    LCMD_T(KC_RGHT),   KC_VOLD,      KC_PGDN,             KC_LEFT,             KC_DOWN,               KC_RGHT,               _______,      KC_DEL,  \
   KC_BRID,      KC_BRIU,          LALT_T(KC_MPRV),      KC_MNXT,            LALT_T(KC_MPLY),   KC_MUTE,      KC_RCMD,             KC_RALT,             MOUSE,                 KC_RALT,               KC_ESC,       KC_TAB,  \
   KC_BSPC,      _______,          _______,              _______,            _______,           _______,      _______,             _______,             _______,               _______,               _______,      _______  \
),

[_SYM] = LAYOUT_ortho_4x12(
    SYM_LCK,      KC_GRV,       KC_AMPR,      KC_ASTR,      KC_LPRN,      KC_RPRN,      _______,      KC_AMPR,      KC_ASTR,      KC_LPRN,     KC_RPRN,      KC_BSPC,  \
    _______,      KC_EQL,       KC_DLR,       KC_PERC,      KC_CIRC,      _______,      _______,      KC_DLR,       KC_PERC,      KC_CIRC,     KC_COLN,      KC_GRV,   \
    _______,      KC_MINS,      KC_EXLM,      KC_AT,        KC_HASH,      OPPOSIT,      OPPOSIT,      KC_EXLM,      KC_AT,        KC_HASH,     KC_QUES,      KC_TAB,   \
    KC_BSPC,      _______,      KC_PLUS,      KC_UNDS,      _______,      OPPTEMP,      OPPTEMP,      _______,      KC_LPRN,      KC_RPRN,     KC_PIPE,      _______   \
),

[_NPAD] = LAYOUT_ortho_4x12(
    NPADLCK,      _______,      KC_7,         KC_8,         KC_9,        KC_BSPC,       _______,      KC_7,        KC_8,         KC_9,         KC_0,             KC_BSPC, \
    _______,      _______,      KC_4,         KC_5,         KC_6,        KC_DOT,        _______,      KC_4,        KC_5,         KC_6,         _______,          KC_DEL,  \
    _______,      _______,      KC_1,         KC_2,         KC_3,        KC_0,          KC_0,         KC_1,        KC_2,         KC_3,         _______,          KC_TAB,  \
    KC_BSPC,      _______,      _______,      _______,      _______,     _______,       _______,      _______,     KC_0,         _______,      _______,          _______  \
),

[_MOUSE] = LAYOUT_ortho_4x12(
    MOUSE,        _______,      _______,      _______,      _______,      KC_WH_D,   KC_WH_D,               KC_MS_BTN1,               KC_MS_UP,               KC_MS_BTN2,     MOUSE,         _______,  \
    _______,      KC_WH_L,      KC_ACL0,      KC_ACL1,      KC_ACL2,      KC_WH_R,   KC_WH_R,               KC_MS_LEFT,               KC_MS_DOWN,             KC_MS_RIGHT,    _______,       _______,  \
    _______,      _______,      _______,      _______,      _______,      KC_WH_U,   KC_WH_U,               _______,                  _______,                _______,        _______,       _______,  \
    _______,      _______,      _______,      _______,      _______,      _______,   _______,               _______,                  KC_MS_BTN1,             _______,        _______,       _______   \
),

[_OPPOSIT] = LAYOUT_ortho_4x12(
   KC_BSPC,                  KC_P,                  KC_O,             KC_I,                KC_U,            KC_Y,            KC_T,              KC_R,             KC_E,                  KC_W,             KC_Q,                       KC_DEL,                          \
   LT(OPPTEMP, KC_TAB),      LT(NAV, KC_SCLN),      KC_L,             KC_K,                KC_J,            KC_H,            KC_G,              KC_F,             KC_D,                  KC_S,             LT(NAV, KC_A),              LT(OPPTEMP, KC_TAB),             \
   LT(SYM, KC_QUOT),         LT(NPADTMP, KC_SLSH),  KC_DOT,           KC_COMM,             KC_M,            KC_N,            KC_B,              KC_V,             KC_C,                  KC_X,             LT(NPADTMP, KC_Z),          LT(SYM, KC_ESC),                 \
   KC_ENT,                   LCTL_T(KC_BSLS),       KC_RBRC,          LALT_T(KC_LBRC),     KC_LSFT,         LCMD_T(KC_SPC),  RCMD_T(KC_SPC),    KC_RSFT,          RALT_T(KC_MINS),       KC_EQL,           RCTL_T(KC_GRV),             KC_ENT                           \
),

/*
[_TYPING] = LAYOUT_ortho_4x12(
   KC_ESC,               KC_Q,               KC_W,             KC_E,          KC_R,            KC_T,            KC_Y,              KC_U,             KC_I,                  KC_O,             KC_P,                       KC_BSPC,                      \
   KC_TAB,               KC_A,               KC_S,             KC_D,          KC_F,            KC_G,            KC_H,              KC_J,             KC_K,                  KC_L,             LT(NAV, KC_SCLN),           LT(SYM, KC_QUOT),             \
   KC_LSFT,              KC_Z,               KC_X,             KC_C,          KC_V,            KC_B,            KC_N,              KC_M,             KC_COMM,               KC_DOT,           LT(NPADTMP, KC_SLSH),       KC_RSFT,                      \
   LCTL_T(KC_BSLS),      TD(MINS_AMP),       TD(EQL_ASTR),     KC_LALT,       KC_BSPC,         KC_SPC,          RCMD_T(KC_SPC),    RSFT_T(KC_DEL),   TD(LPAR_BRC),          TD(RPAR_BRC),     TD(GRV_CIRC),               KC_ENT                        \
),
*/
};

static bool bsdel_mods = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    // case KC_A:
    //     register_code(KC_F);
    //   return false;break;
    case M_BSDEL: {
      uint8_t kc = KC_BSPC;
        if (keyboard_report->mods || bsdel_mods) {
          kc = KC_DEL;
        }

        if (record->event.pressed) {
          register_code (kc);
          bsdel_mods = keyboard_report->mods;
        }
        else {
          unregister_code (kc);
          bsdel_mods = false;
        }
    }
    // case M_DELBS: {
    //   uint8_t kc = KC_BSPC;
    //     if (keyboard_report->mods || delbs_mods) {
    //       kc = KC_DEL;
    //     }

    //     if (record->event.pressed) {
    //       register_code (kc);
    //       bsdel_mods = keyboard_report->mods;
    //     }
    //     else {
    //       unregister_code (kc);
    //       bsdel_mods = false;
    //     }
    // }
  }
  return true;
};

// // Is shift being held? Let's store this in a bool.
// static bool alt_held = false;

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
// 	switch(keycode) {
//     case KC_LALT:
//       alt_held = record->event.pressed;
//       return true;
//       break;
//     case KC_RALT:
//       alt_held = record->event.pressed;
//       return true;
//       break;
// 		case LSWAP_TAB: {
// 			if (record->event.pressed) {
// 				if (alt_held) {
// 					register_code(SH_TG);
// 				} else {
// 					register_code(KC_TAB);
// 				}
// 			} else { // Release the key
// 				// unregister_code(KC_LBRC);
// 				// unregister_code(KC_LALT);
// 				// unregister_code(KC_RALT);
// 				// unregister_code(KC_9);
// 			}
// 			return false;
// 			break;
// 		}
// 		case RSWAP_TAB: {
// 			if (record->event.pressed) {
// 				if (alt_held) {
// 					register_code(SH_TG);
// 				} else {
// 					register_code(KC_TAB);
// 				}
// 			} else { // Release the key
// 				// unregister_code(KC_RBRC);
// 				// unregister_code(KC_LSFT);
// 				// unregister_code(KC_RSFT);
// 				// unregister_code(KC_0);
// 			}
// 			return false;
// 			break;
// 		}
// 	}
// 	return true;
// };

/*******************/
// https://docs.qmk.fm/#/feature_tap_dance?id=example-4-39quad-function-tap-dance39
/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return SINGLE_TAP;
    //key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    /*
     * DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
     * action when hitting 'pp'. Suggested use case for this return value is when you want to send two
     * keystrokes of the key, and not the 'double tap' action/macro.
    */
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  //Assumes no one is trying to type the same letter three times (at least not quickly).
  //If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
  //an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
  if (state->count == 3) {
    if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
    else return TRIPLE_HOLD;
  }
  else return 8; //magic number. At some point this method will expand to work for more presses
}

//instanalize an instance of 'tap' for the 'x' tap dance.
static tap xtap_state = {
  .is_press_action = true,
  .state = 0
};

void x_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: register_code(KC_LBRC); break;
    case SINGLE_HOLD: register_code(KC_LSFT); break;
    case DOUBLE_TAP: register_code(KC_MINS); break;
    case DOUBLE_HOLD: register_code(KC_LALT); break;
    case DOUBLE_SINGLE_TAP: register_code(KC_X); unregister_code(KC_X); register_code(KC_X);
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}

void x_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: unregister_code(KC_LBRC); break;
    case SINGLE_HOLD: unregister_code(KC_LSFT); break;
    case DOUBLE_TAP: unregister_code(KC_MINS); break;
    case DOUBLE_HOLD: unregister_code(KC_LALT);
    case DOUBLE_SINGLE_TAP: unregister_code(KC_X);
  }
  xtap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [SFT_ALT]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL,x_finished, x_reset)
  // [LPAR_BRC]  = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LPRN),
  // [RPAR_BRC]  = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RPRN),
  // [SLS_BSLS]  = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_BSLS),
  // [COM_PERC]  = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_PERC),
  // [EXCLM_AT]  = ACTION_TAP_DANCE_DOUBLE(KC_EXLM, KC_AT),
  // [HASH_DLR]  = ACTION_TAP_DANCE_DOUBLE(KC_HASH, KC_DLR),
  // [GRV_CIRC]  = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_CIRC),
  // [EQL_ASTR]  = ACTION_TAP_DANCE_DOUBLE(KC_EQL, KC_ASTR),
  // [MINS_AMP]  = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_AMPR),
  // [MINS_GRV]  = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_GRV),
  // [SHIFT_OP]  = ACTION_TAP_DANCE_DUAL_ROLE(KC_RSFT, _OPPOSIT)
};
/****************/
