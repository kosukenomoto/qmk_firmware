// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
//
// makeコマンドは下記を実行
// make keyboardio/atreus:20230924:flash
// qmk compile -kb keyboardio/atreus -km 20230924
// qmk flash -kb keyboardio/atreus -km 20230924
// As far as I know, you still need to hold down the Esc key (where it was in the original layout) while pressing QK_BOOT.
//

#include QMK_KEYBOARD_H
#include "keymap_jp.h"

#define JBASE   0
#define UBASE   1
#define JRISE   2
#define URISE   3
#define JSPFN   4
#define USPFN   5
#define JWIN    6
#define UWIN    7
#define JLEF    8
#define ULEF    9
#define HYPSPFN 10
#define JSCFN   11
#define USCFN   12 
#define JNUM    13 
#define UNUM    14 
#define COMFN   15

#define CM_JFN  LT(JNUM,KC_ESC)
#define CM_UFN  LT(UNUM,KC_ESC)

#define LT_USX  LT(URISE,KC_X)
#define LT_JPX  LT(JRISE,KC_X)
#define LT_USA  LT(URISE,KC_A)
#define LT_JPA  LT(JRISE,KC_A)
#define LT_UNUM LT(UNUM,KC_SCLN)
#define LT_JNUM LT(JNUM,JP_SCLN)
#define LT_USSC LT(URISE,KC_SCLN)
#define LT_JPSC LT(JRISE,JP_SCLN)
#define LT_JLEF LT(JLEF,KC_ESC)
#define LT_ULEF LT(ULEF,KC_ESC)
#define LT_JFN1 LT(JSPFN,KC_TAB)
#define LT_UFN1 LT(USPFN,KC_TAB)

#define MO_COMFN MO(COMFN)
#define MO_JNUM MO(JNUM)
#define MO_UNUM MO(UNUM)
#define MO_USFN MO(USPFN)
#define MO_JSFN MO(JSPFN)
#define MO_JRIS MO(JRISE)
#define MO_URIS MO(URISE)
#define MO_HYPS MO(HYPSPFN)
#define MO_JLEF MO(JLEF)
#define MO_ULEF MO(ULEF)
#define LT_JWIN LT(JWIN,KC_F2)
#define LT_UWIN LT(UWIN,KC_F2)
#define MO_JWIN MO(JWIN)
#define MO_UWIN MO(UWIN)

#define DF_JBAS DF(JBASE)
#define DF_UBAS DF(UBASE)

#define CM_SHTZ SFT_T(KC_Z)
#define CM_SHT0 SFT_T(KC_0)
#define CM_SHT1 SFT_T(KC_1)
#define CM_SJSS SFT_T(JP_SLSH)
#define CM_SUSS SFT_T(KC_SLSH)

#define ESC_SFT LSFT_T(KC_ESC)
#define ENT_SFT LSFT_T(KC_ENT)
#define BSP_SFT LSFT_T(KC_BSPC)
#define TAB_SFT RSFT_T(KC_TAB)
#define ESC_ALT LALT_T(KC_ESC)
#define MIS_ALT LALT_T(KC_MINS)

#define A_ALT LALT_T(KC_A)
#define SC_ALT LALT_T(KC_SCLN)
#define F_CTL LCTL_T(KC_F)
#define J_CTL LCTL_T(KC_J)
#define X_CTL LCTL_T(KC_X)
#define DT_CTL LCTL_T(KC_DOT)
#define W_GUI LGUI_T(KC_W)
#define O_GUI LGUI_T(KC_O)
#define S_GUI LGUI_T(KC_S)
#define L_GUI LGUI_T(KC_L)
#define D_GUI LGUI_T(KC_D)
#define K_GUI LGUI_T(KC_K)
#define G_GUI LGUI_T(KC_G)
#define H_GUI LGUI_T(KC_H)

#define SLS_CTL LCTL_T(KC_SLSH)
#define SLS_GUI LGUI_T(KC_SLSH)
#define ESC_CTL LCTL_T(KC_ESC)
#define JMI_CTL LCTL_T(JP_MINS)
#define UMI_GUI LGUI_T(JP_MINS)

#define CM_CPGU C(KC_PGUP)
#define CM_CPGD C(KC_PGDN)
#define CM_CHOM C(KC_HOME)
#define CM_CEND C(KC_END)
#define CM_GPGU G(KC_PGUP)
#define CM_GPGD G(KC_PGDN)
#define CM_GHOM G(KC_HOME)
#define CM_GEND G(KC_END)

#define CM_ALTC A(KC_LCTL)
#define CM_ALT4 A(KC_F4)
#define CM_CTL4 C(KC_F4)
#define CM_CTLT C(KC_TAB)
#define CM_GUIT G(KC_TAB)
#define CM_ALTT A(KC_TAB)
#define CM_SF10 S(KC_F10)

#define CM_GUIW G(KC_W)

#define CM_GUIM G(KC_M)
#define CM_ALTM A(KC_M)

#define CM_CTLV C(KC_V)
#define CM_GUIV G(KC_V)
#define CM_CTLC C(KC_C)
#define CM_GUIC G(KC_C)
#define CM_CTLZ C(KC_Z)
#define CM_GUIZ G(KC_Z)
#define CM_CTLX C(KC_X)
#define CM_GUIX G(KC_X)
#define CM_GUIE G(KC_E)
#define CM_SFEN S(KC_END)
#define CM_SFHM S(KC_HOME)
#define CM_WSCS G(S(KC_S))
#define CM_MSCS A(S(KC_S))

#define CM_JHNZ A(KC_GRV)
#define CM_UHNZ C(KC_SPC)
//VM利用時はカラビナでALTGRAVに置き換えて解釈
//(VM利用時はカラビナでCNTLがまずcontrol->command command->controlとなる
//　つぎにーカラビナでCommand+SPAVEであればALT+GRAVに変換）  

enum custom_keycodes {
  CM_LEFT = SAFE_RANGE,
  CM_RGHT,
  CM_UP,
  CM_DOWN,
  CM_SCLT,
  CM_SPFN,
  CM_SPFN2,
  CM_LISX,
  CM_DOT,
  CM_LISE,
  CM_ESFN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [JBASE] = LAYOUT( /* Qwerty win jpkey */
    /***********************************************************************************************/
    /* win jpkey(QMK)  GUI(command)   CTL(control)   ALT(option)                                   */
    /***********************************************************************************************/
    KC_Q,      KC_W,     KC_E,     KC_R,     KC_T,                       KC_Y,      KC_U,     KC_I,     KC_O,    KC_P,
    A_ALT,     KC_S,     KC_D,     F_CTL,    G_GUI,                      H_GUI,     J_CTL,    KC_K,     KC_L,    SC_ALT,//CM_SCLT,
    CM_SHTZ,   X_CTL,    KC_C,     KC_V,     KC_B,    KC_BTN1, CM_SF10,  KC_N,      KC_M,     KC_COMM,  DT_CTL,  CM_SJSS,
    KC_LGUI,   KC_LALT,  KC_LSFT,  CM_SPFN2,  CM_LISE, KC_LCTL, KC_LALT,  CM_SPFN,   CM_JFN,  KC_LSFT,  KC_LALT, MO_COMFN),   

  [UBASE] = LAYOUT( /* Qwerty mac uskey */
    /***********************************************************************************************/
    /* mac uskey(QMK)      ALT(option)       GUI(command)                CTL(control)              */
    /* mac karabiner(win)  option(ALT)->GUI  command(GUI)->control(CTL)  control(CTL)->option(ALT) */                        
    /***********************************************************************************************/                                        
    // [vmware使ってない時]  mac_F14 -> mac_cmd+opt+spc(finder find)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
    // [vmware]            mac_F14 -> win_GUI+e                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
    // [vmware]            mac_F13 -> win_F2
    KC_Q,      KC_W,     KC_E,     KC_R,     KC_T,                       KC_Y,      KC_U,     KC_I,     KC_O,    KC_P,
    A_ALT,     KC_S,     KC_D,     F_CTL,    G_GUI,                      H_GUI,     J_CTL,    KC_K,     KC_L,    SC_ALT,//CM_SCLT,
    CM_SHTZ,   X_CTL,    KC_C,     KC_V,     KC_B,    KC_BTN1, CM_SF10,  KC_N,      KC_M,     KC_COMM,  DT_CTL,  CM_SUSS,
    KC_LGUI,   KC_LALT,  KC_LSFT,  CM_SPFN2,  CM_LISE, KC_LCTL, KC_LALT,  CM_SPFN,   CM_UFN,  KC_LSFT,  KC_LALT, MO_COMFN),   

    /**********************************************************************************************/
    //   !       @      #     $    %        ||       &     *     (    )    -                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
    //   _       +      =     -    ^        ||       {     }     [    ]    :
    //   \       `      |     ~    NO       ||       '     "     <    >    ?
   [JRISE] = LAYOUT( 
    JP_EXLM,   JP_AT,     JP_HASH, JP_DLR,    JP_PERC,                    JP_AMPR,  JP_ASTR,  JP_LPRN, JP_RPRN, JP_MINS,  
    JP_UNDS,   JP_PLUS,   JP_EQL,  JP_ASTR,   JP_CIRC,                    JP_LCBR,  JP_RCBR,  JP_LBRC, JP_RBRC, JP_COLN,  
    JP_BSLS,   JP_AMPR,   JP_PIPE, JP_TILD,   JP_GRV,   _______, _______, JP_QUOT,  JP_DQUO,  JP_LABK, JP_RABK, JP_QUES,   
    _______,   _______,   _______, _______,   _______,  _______, _______, KC_LCTL,  KC_LALT,  _______, _______, _______ ),

   [URISE] = LAYOUT( 
    KC_EXLM,   KC_AT,     KC_HASH, KC_DLR,    KC_PERC,                    KC_AMPR,  KC_ASTR,  KC_LPRN, KC_RPRN, KC_MINS,  
    KC_UNDS,   KC_PLUS,   KC_EQL,  KC_ASTR,   KC_CIRC,                    KC_LCBR,  KC_RCBR,  KC_LBRC, KC_RBRC, KC_COLN,  
    KC_BSLS,   KC_AMPR,   KC_PIPE, KC_TILD,   KC_GRV,   _______, _______, KC_QUOT,  KC_DQUO,  KC_LABK, KC_RABK, KC_QUES,   
    _______,   _______,   _______, _______,   _______,  _______, _______, KC_LCTL,  KC_LALT,  _______, _______, _______  ),

//**********************************************************

  [JSPFN] = LAYOUT( /* [> SPFN <] */
    CM_GUIE,   CM_ALT4,   LT_JLEF, CM_GUIT,   CM_WSCS,                    _______,  KC_HOME,  KC_UP,    KC_END,  JP_MINS,
    KC_LALT,   KC_LSFT,   KC_DEL,  MO_HYPS,   KC_TAB,                     KC_BSPC,  KC_LEFT,  KC_DOWN,  KC_RGHT, KC_ENT,
    KC_1,      KC_2,      KC_3,    KC_4,      KC_5,     _______, _______, KC_6,     KC_7,     KC_8,     KC_9,    KC_0,
    _______,   _______,   _______, KC_LALT,   KC_LCTL,  _______, _______, _______,  _______,  _______,  _______, _______ ),

  [USPFN] = LAYOUT( /* [> SPFN <] */
    CM_GUIE,   CM_ALT4,   LT_ULEF, CM_GUIT,   CM_WSCS,                    _______,  KC_HOME,  KC_UP,    KC_END,  KC_MINS,
    KC_LALT,   KC_LSFT,   KC_DEL,  MO_HYPS,   KC_TAB,                     KC_BSPC,  KC_LEFT,  KC_DOWN,  KC_RGHT, KC_ENT,
    KC_1,      KC_2,      KC_3,    KC_4,      KC_5,     _______, _______, KC_6,     KC_7,     KC_8,     KC_9,    KC_0,
    _______,   _______,   _______, KC_LALT,   KC_LCTL,  _______, _______, _______,  _______,  _______,  _______, _______ ),

   [JLEF] = LAYOUT( /* [> MO_JLEF <] */
    _______,   _______, _______, _______, _______,                    _______,  CM_CHOM,  KC_PGUP,  CM_CEND, _______,
    _______,   _______, _______, _______, CM_ALTC,                    _______,  CM_CPGU,  KC_PGDN,  CM_CPGD, _______,
    _______,   _______, _______, _______, _______,  _______, _______, _______,  _______,  _______,  _______, _______,
    _______,   _______, _______, _______, _______,  _______, _______, _______,  _______,  _______,  _______, _______ ),
   [ULEF] = LAYOUT( /* [> MO_ULEF <] */
    _______,   _______, _______, _______, _______,                    _______,  CM_CHOM,  KC_PGUP,  CM_CEND, _______,
    _______,   _______, _______, _______, CM_ALTC,                    _______,  CM_CPGU,  KC_PGDN,  CM_CPGD, _______,
    _______,   _______, _______, _______, _______,  _______, _______, _______,  _______,  _______,  _______, _______,
    _______,   _______, _______, _______, _______,  _______, _______, _______,  _______,  _______,  _______, _______ ),

  [HYPSPFN] = LAYOUT( /* [> MO_HYPS <] */
    _______,   _______, _______, _______, _______,                    _______,  _______,  CM_UP,   _______,  _______,
    _______,   _______, _______, _______, _______,                    _______,  CM_LEFT,  CM_DOWN, CM_RGHT,  _______,
    _______,   _______, _______, _______, _______,  _______, _______, _______,  _______,  _______,  _______, _______,
    _______,   _______, _______, _______, _______,  _______, _______, _______,  _______,  _______,  _______, _______ ),

  [JNUM] = LAYOUT(
    _______,   _______, _______, _______, _______,                    DF_UBAS,  _______,  _______,  _______, QK_BOOT,
    KC_F1,     KC_F2,   KC_F3,   KC_F4,   KC_F5,                      _______,  KC_BTN1,  CM_SF10,  _______, _______,
    KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  _______, _______,  _______,  _______,  _______, KC_LSFT,
    QK_BOOT,   _______, _______, _______, _______,  _______, _______, _______,  _______,  _______,  _______, _______ ),

  [UNUM] = LAYOUT( 
    _______,   _______, _______, _______, _______,                    DF_UBAS,  _______,  _______,  _______, QK_BOOT,
    KC_F1,     KC_F2,   KC_F3,   KC_F4,   KC_F5,                      _______,  KC_BTN1,  CM_SF10,  _______, _______,
    KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  _______, _______,  _______,  _______,  _______, KC_LSFT,
    QK_BOOT,   _______, _______, _______, _______,  _______, _______, _______,  _______,  _______,  _______, _______ ),

  [COMFN] = LAYOUT( /* [> MO_HYPS <] */
    _______,   _______, _______, _______, _______,                    _______,  _______,  CM_UP,   _______,  QK_BOOT,
    _______,   _______, _______, _______, _______,                    _______,  CM_LEFT,  CM_DOWN, CM_RGHT,  _______,
    _______,   _______, _______, _______, _______,  _______, _______, _______,  _______,  _______,  _______, _______,
    _______,   _______, _______, _______, _______,  _______, _______, _______,  _______,  DF_JBAS,  DF_UBAS, _______ )

};

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record){
    switch (keycode) {
        case LT(URISE,KC_A):
            return 0;
        case LT(JRISE,KC_A):
            return 0;
        case LT(URISE,KC_SCLN):
            return 0;
        case LT(JRISE,JP_SCLN):
            return 0;
        case LT(JSPFN,KC_TAB):
            return 0;
        case LT(USPFN,KC_TAB):
            return 0;
        default:
            return QUICK_TAP_TERM; 
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case G_GUI:
            return 70;
        case H_GUI:
            return 70;
        case J_CTL:
            return 70;
        case F_CTL:
            return 70;
        case A_ALT:
            return 70;
        case LT(URISE,KC_SCLN):
            return 120;
        case LT(JRISE,JP_SCLN):
            return 120;
        case CM_SHTZ:
            return 70;
        default:
            return TAPPING_TERM; 
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT_USX:
            return true;
        case LT_JPX:
            return true;
        default:
            return false; 
    }
}

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record){
    switch (keycode) {
        case LT_USX:
            return false;
        case LT_JPX:
            return false;
        default:
            return true; 
    }
} 

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record){
    switch (keycode) {
        case LT_USX:
            return true;
        case LT_JPX:
            return true;
        default:
            return false; 
    }
} 
static bool process_jp_symbols_impl(uint16_t keycode, bool pressed) {
    if (!pressed) {
        return true;
    }
    uint8_t shift = keyboard_report->mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
    if (!shift) {
        return true;
    }
    uint16_t s;
    switch (keycode) {
        // Replace Shift-Symbols like ANSI for JIS.
        case JP_2:    s = JP_AT; break;
        case JP_6:    s = JP_CIRC; break;
        case JP_7:    s = JP_AMPR; break;
        case JP_8:    s = JP_ASTR; break;
        case JP_9:    s = JP_LPRN; break;
        case JP_0:    s = JP_RPRN; break;
        case JP_GRV:  s = JP_TILD; break;
        case JP_EQL:  s = JP_PLUS; break;
        case JP_MINS: s = JP_UNDS; break;
        case JP_QUOT: s = JP_DQUO; break;
        case JP_SCLN: s = JP_COLN; break;
        case JP_BSLS: s = JP_PIPE; break;
        default: return true;
    }
    unregister_mods(shift);
    tap_code16(s);
    register_mods(shift);
    return false;
}

bool process_jp_symbols(uint16_t keycode, keyrecord_t *record) {
    return process_jp_symbols_impl(keycode, record->event.pressed);
}

void tap_code16jp(uint16_t keycode) {
    if (process_jp_symbols_impl(keycode, true)) {
        tap_code16(keycode);
    }
}


//SPFN ============================================
static bool spfn_pressed = false; 
static uint16_t spfn_pressed_time = 0;
static bool lise_pressed = false;
static uint16_t lise_pressed_time = 0;
static bool sclt_pressed = false;
static uint16_t sclt_pressed_time = 0;

//上関数のIMEON/OFF切り替え専用
//TODO 汎用的な関数を引数に取れるようにすること(関数アドレス)
static void user_lt_hnzn(keyrecord_t *record, int layer, bool *modifier_pressed, uint16_t *modifier_pressed_time, bool tapping_term_disable) {
      if (record->event.pressed) {
        *modifier_pressed_time = record->event.time;
        *modifier_pressed = true;
        layer_on(layer);
      } else {
        layer_off(layer);
        if (*modifier_pressed && (tapping_term_disable || (timer_elapsed(*modifier_pressed_time) < TAPPING_TERM))) {
         if (get_highest_layer(default_layer_state)==JBASE){
             SEND_STRING(SS_LALT("`"));
         }else{
             SEND_STRING(SS_LALT("`"));
             //VM利用時はカラビナでALTGRAVに置き換えて解釈
             //(VM利用時はカラビナでCNTLがまずcontrol->command command->controlとなる
             //　つぎにーカラビナでCommand+SPAVEであればALT+GRAVに変換）             
         }
        }
        *modifier_pressed = false;
      }
}

static void user_lt(keyrecord_t *record, int layer, uint16_t keycode, bool *modifier_pressed, uint16_t *modifier_pressed_time, bool tapping_term_disable) {
        if (record->event.pressed) {
        *modifier_pressed = true;
        *modifier_pressed_time = record->event.time;

        layer_on(layer);
      } else {
        layer_off(layer);

        if (*modifier_pressed && (tapping_term_disable || (timer_elapsed(*modifier_pressed_time) < TAPPING_TERM))) {
          register_code(keycode);
          unregister_code(keycode);
          unregister_code(keycode);
        }
        *modifier_pressed = false;
      }
}

// static void user_mt(keyrecord_t *record, uint16_t modcode, uint16_t keycode, bool *modifier_pressed, uint16_t *modifier_pressed_time, bool tapping_term_disable) {
//         if (record->event.pressed) {
//         *modifier_pressed = true;
//         *modifier_pressed_time = record->event.time;
//       } else {
// 	if (!*modifier_pressed) unregister_code(modcode);
//         if (*modifier_pressed && (tapping_term_disable || (timer_elapsed(*modifier_pressed_time) < TAPPING_TERM))) {
//           register_code(keycode);
//           unregister_code(keycode);
//           unregister_code(keycode);
//         }
//         *modifier_pressed = false;
//       }
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    // reset the user_lt & user_tt flags
    if (keycode != CM_SPFN) {spfn_pressed = false;}
    if (keycode != CM_LISE) {lise_pressed = false;}
    if (keycode != CM_SCLT) {sclt_pressed = false;}
  }
  switch (keycode) {
    case CM_SPFN:
      if (get_highest_layer(default_layer_state)==JBASE){
        user_lt(record,JSPFN,KC_SPC,&spfn_pressed,&spfn_pressed_time,false);
      } else {
        user_lt(record,USPFN,KC_SPC,&spfn_pressed,&spfn_pressed_time,false);
      }
      return false;
      break;
    case CM_SPFN2:
      if (get_highest_layer(default_layer_state)==JBASE){
        user_lt_hnzn(record,JSPFN,&spfn_pressed,&spfn_pressed_time,false);
      } else {
        user_lt_hnzn(record,USPFN,&spfn_pressed,&spfn_pressed_time,false);
      }
      return false;
      break;
    case CM_LISE:
      if (get_highest_layer(default_layer_state)==JBASE){
        user_lt(record,JRISE,KC_TAB,&lise_pressed,&lise_pressed_time,false);
      } else {
        user_lt(record,URISE,KC_TAB,&lise_pressed,&lise_pressed_time,false);
      }
      return false;
      break;
    case CM_SCLT:
      if (get_highest_layer(default_layer_state)==JBASE){
        user_lt(record,JNUM,KC_SCLN,&sclt_pressed,&sclt_pressed_time,false);
      } else {
        user_lt(record,UNUM,KC_SCLN,&sclt_pressed,&sclt_pressed_time,false);
      }
      return false;
      break;
    case CM_LEFT:
      if(record->event.pressed){
        //pressed
        tap_code(KC_LEFT);
        tap_code(KC_LEFT);
        tap_code(KC_LEFT);
        tap_code(KC_LEFT);                        
      } else {
        //released
      }
      break;
    case CM_RGHT:
      if(record->event.pressed){
        //pressed
        tap_code(KC_RGHT);
        tap_code(KC_RGHT);
        tap_code(KC_RGHT);
        tap_code(KC_RGHT);
      }else{
        //released
      }
      break;
    case CM_UP:
      if(record->event.pressed){
        //pressed
        tap_code(KC_UP);
        tap_code(KC_UP);
        tap_code(KC_UP);
        tap_code(KC_UP);
      }else{
        //released
      }
      break;
    case CM_DOWN:
      if(record->event.pressed){
        //pressed
        tap_code(KC_DOWN);
        tap_code(KC_DOWN);
        tap_code(KC_DOWN);
        tap_code(KC_DOWN);
      }else{
        //released
      }
      break;
    default:
      if (record->event.pressed) {
        // reset the flag
        spfn_pressed = false;
        lise_pressed = false;
        sclt_pressed = false;
      }
      break;
    }

    switch (get_highest_layer(default_layer_state)){
        case JBASE:
            return process_jp_symbols(keycode,record);
            break;
        default:
            break;
    }

    return true;
}
