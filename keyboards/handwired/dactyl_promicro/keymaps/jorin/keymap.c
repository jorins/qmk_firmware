#include QMK_KEYBOARD_H

#define _ KC_TRNS
#define x KC_NO
#define KC_CTBS MT(MOD_LCTL, KC_BSPC)

#define SC_LS F(F_SC_LS)
#define SC_RS F(F_SC_RS)
#define SC_LC F(F_SC_LC)
#define SC_RC F(F_SC_RC)
#define SC_LG F(F_SC_LG)
#define SC_RG F(F_SC_RG)
#define SC_LA F(F_SC_LA)
#define SC_RA F(F_SC_RA)
#define SC_FN F(F_SC_FN)

enum functions {
  F_SC_LS,
  F_SC_RS,
  F_SC_LC,
  F_SC_RC,
  F_SC_LG,
  F_SC_RG,
  F_SC_LA,
  F_SC_RA,
  F_SC_FN,
};

enum {
  L_BASE,
  L_FN,
  L_SYSFN,
  L_RESET,
};

const uint16_t cadet_table[][3] = {
  // Hold mod, tap mod, tap key
  // Modify this array to adjust for your locale and preferences
  {KC_LSFT, KC_LSFT, KC_8}, // Left shift / (
  {KC_RSFT, KC_LSFT, KC_9}, // Right shift / )
  {KC_LCTL, KC_LCTL, KC_BSPC}, //Left ctrl / ctrl + backspace
  {KC_RCTL, KC_LSFT, KC_7},  // Unused: right ctrl / /
  {KC_LGUI, KC_RALT, KC_7},  // Left GUI / {
  {KC_RGUI, KC_RALT, KC_0},  // Right GUI / }
  {KC_LALT, KC_RALT, KC_8},  // Left alt / [
  {KC_RALT, KC_RALT, KC_9},  // Right alt / ]
  {L_SYSFN, KC_RALT, KC_0}  // Right Fn / }
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_BASE] = LAYOUT_6x6(
    KC_ESC  , KC_1    , KC_2    , KC_3    , KC_4     , KC_5    , /*|*/ KC_6   , KC_7    , KC_8     , KC_9    , KC_0    , KC_MINS ,
    KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R     , KC_T    , /*|*/ KC_Y   , KC_U    , KC_I     , KC_O    , KC_P    , KC_LBRC ,
    KC_CTBS , KC_A    , KC_S    , KC_D    , KC_F     , KC_G    , /*|*/ KC_H   , KC_J    , KC_K     , KC_L    , KC_SCLN , KC_QUOT ,
    SC_LS   , KC_NUBS , KC_Z    , KC_X    , KC_C     , KC_V    , /*|*/ KC_B   , KC_N    , KC_M     , KC_COMM , KC_DOT  , KC_SLSH ,
    KC_GRV  , SC_LG   , SC_LA   , KC_LEFT , KC_RIGHT , KC_SPC  , /*|*/ KC_SPC , KC_LEFT , KC_RIGHT , KC_UP   , KC_DOWN , KC_QUOT ,
                                  KC_1    , KC_2     , KC_3    , /*|*/ KC_3   , KC_2    , KC_1     ,
                                                       KC_4    , /*|*/ KC_4   ,
                                                       KC_5    , /*|*/ KC_5
  ),

  [L_FN] = LAYOUT_6x6(
    KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6 , /*|*/ KC_F7   , KC_F8   , KC_F9   , KC_F10   , KC_F11 , KC_F12 ,
    _     , _     , _     , _     , _     , _     , /*|*/ _       , _       , _       , _        , _      , _      ,
    SC_LC , _     , _     , _     , _     , _     , /*|*/ KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT , _      , _      ,
    _     , _     , _     , _     , _     , _     , /*|*/ KC_HOME , KC_PGDN , KC_PGUP , KC_END   , _      , _      ,
    _     , _     , _     , _     , _     , _     , /*|*/ _       , _       , _       , _        , _      , _      ,
            _     , _     , _     , _     , _     , /*|*/ _       , _       , _       , _        , _
  ),

  [L_SYSFN] = LAYOUT_6x6(
    KC_ESC  , KC_1    , KC_2    , KC_3    , KC_4     , RESET   , /*|*/ RESET  , KC_7    , KC_8     , KC_9    , KC_0    , KC_MINS ,
    KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R     , KC_T    , /*|*/ KC_Y   , KC_U    , KC_I     , KC_O    , KC_P    , KC_NUHS ,
    KC_CAPS , KC_A    , KC_S    , KC_D    , KC_F     , KC_G    , /*|*/ KC_H   , KC_J    , KC_K     , KC_L    , KC_SCLN , KC_ENT  ,
    KC_LSFT , KC_NUBS , KC_Z    , KC_X    , KC_C     , KC_V    , /*|*/ KC_B   , KC_N    , KC_M     , KC_COMM , KC_DOT  , KC_SLSH ,
    KC_GRV  , KC_LALT , KC_LGUI , KC_LEFT , KC_RIGHT , KC_BSPC , /*|*/ KC_SPC , KC_LEFT , KC_RIGHT , KC_UP   , KC_DOWN , KC_QUOT ,
              KC_HOME , KC_ESC  , KC_PSCR , RESET    , KC_SPC  , /*|*/ KC_ENT , RESET   , KC_DEL   , KC_HOME , KC_END
  ),

  [L_RESET] = LAYOUT_6x6(
    RESET , x , x , x , x , x , /*|*/ x , x , x , x , x , x ,
    x     , x , x , x , x , x , /*|*/ x , x , x , x , x , x ,
    x     , x , x , x , x , x , /*|*/ x , x , x , x , x , x ,
    x     , x , x , x , x , x , /*|*/ x , x , x , x , x , x ,
    x     , x , x , x , x , x , /*|*/ x , x , x , x , x , x ,
            x , x , x , x , x , /*|*/ x , x , x , x , x
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool is_hold(keyrecord_t *record) {
  return (record->tap.count <= 0 || record->tap.interrupted);
};

void cadet_function(keyrecord_t *record, uint16_t hold_mod, uint16_t tap_mod, uint16_t tap_key) {
  // Generalised space cadet.
  // Gives a function that holds hold_mod on hold, or tap_mod+tap_key on tap.
  if (record->event.pressed) {
    if (is_hold(record)) {
      register_code(hold_mod);
    }
  }
  else {
    if (is_hold(record)) {
      unregister_code(hold_mod);
    }
    else {
      register_code(tap_mod);
      register_code(tap_key);
      unregister_code(tap_key);
      unregister_code(tap_mod);
    }
  }
};

void layer_cadet(keyrecord_t *record, uint16_t hold_layer, uint16_t tap_mod, uint16_t tap_key) {
  // Generalised space cadet but with a layer instead of a mod on hold
  // Gives a function that holds hold_layer on hold, or tap_mod+tap_key on tap.
  if (record->event.pressed) {
    if (is_hold(record)) {
      layer_state_set(1 << hold_layer | layer_state);
    }
  }
  else {
    if (is_hold(record)) {
      //layer_state_set(return_layer);
      layer_clear();
    }
    else {
      register_code(tap_mod);
      register_code(tap_key);
      unregister_code(tap_key);
      unregister_code(tap_mod);
    }
  }
};

// Custom Actions
const uint16_t PROGMEM fn_actions[] = {
  [F_SC_LS] = ACTION_FUNCTION_TAP(F_SC_LS),
  [F_SC_RS] = ACTION_FUNCTION_TAP(F_SC_RS),
  [F_SC_LC] = ACTION_FUNCTION_TAP(F_SC_LC),
  [F_SC_RC] = ACTION_FUNCTION_TAP(F_SC_RC),
  [F_SC_LG] = ACTION_FUNCTION_TAP(F_SC_LG),
  [F_SC_RG] = ACTION_FUNCTION_TAP(F_SC_RG),
  [F_SC_LA] = ACTION_FUNCTION_TAP(F_SC_LA),
  [F_SC_RA] = ACTION_FUNCTION_TAP(F_SC_RA),
  [F_SC_FN] = ACTION_FUNCTION_TAP(F_SC_FN),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch (id) {
    case F_SC_LS ... F_SC_RA:
      cadet_function(record, cadet_table[id][0], cadet_table[id][1], cadet_table[id][2]);
      break;
    case F_SC_FN:
      layer_cadet(record, cadet_table[id][0], cadet_table[id][1], cadet_table[id][2]);
      break;
  }
};

/*
// Macros
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) { register_code(KC_RSFT); }
      else { unregister_code(KC_RSFT); }
      break;
  }
  return MACRO_NONE;
};
*/

/*
// Loop
void matrix_scan_user(void) {
  // Empty
};
*/
