/* Copyright 2015-2023 Jack Humbert
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

enum planck_layers { _QWERTY, _LOWER, _RAISE, _NUMS, _ADJUST };

enum planck_keycodes { QWERTY = SAFE_RANGE, BACKLIT, EXT_PLV };

#define ADJUST MO(_ADJUST)
#define LOWER MO(_LOWER)
#define NUMS MO(_NUMS)
#define RAISE MO(_RAISE)

enum unicode_names {
    AA,
    AE,
    OE
};

const uint32_t unicode_map[] PROGMEM = {
    [AA]  = 0x00C5,
    [AE] = 0x00C4,
    [OE]  = 0x00D6,
};

const uint16_t PROGMEM left_bracket_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM right_bracket_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM left_paren_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM right_paren_combo[] = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[] = {
    COMBO(left_bracket_combo, KC_LBRC),
    COMBO(right_bracket_combo, KC_RBRC),
    COMBO(left_paren_combo, KC_LPRN),
    COMBO(right_paren_combo, KC_RPRN),
};

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//        ┌─────────────┬───────────┬───────────┬───────────┬───────────┬─────┐   ┌──────┬───────────┬───────────┬───────────┬───────────┬──────┐
//        │     tab     │     q     │     w     │     e     │     r     │  t  │   │  y   │     u     │     i     │     o     │     p     │ bspc │
//        ├─────────────┼───────────┼───────────┼───────────┼───────────┼─────┤   ├──────┼───────────┼───────────┼───────────┼───────────┼──────┤
//        │ LCTL_T(esc) │ LCTL_T(a) │ LALT_T(s) │ LGUI_T(d) │ LSFT_T(f) │  g  │   │  h   │ RSFT_T(j) │ LGUI_T(k) │ RALT_T(l) │ RCTL_T(;) │  '   │
//        ├─────────────┼───────────┼───────────┼───────────┼───────────┼─────┤   ├──────┼───────────┼───────────┼───────────┼───────────┼──────┤
//        │    lsft     │     z     │     x     │     c     │     v     │  b  │   │  n   │     m     │     ,     │     .     │     /     │ ent  │
//        ├─────────────┼───────────┼───────────┼───────────┼───────────┼─────┤   ├──────┼───────────┼───────────┼───────────┼───────────┼──────┤
//        │    lctl     │   LOWER   │   lalt    │   lgui    │ TT(_NUMS) │ spc │   │ rgui │   RAISE   │   left    │   down    │    up     │ rght │
//        └─────────────┴───────────┴───────────┴───────────┴───────────┴─────┘   └──────┴───────────┴───────────┴───────────┴───────────┴──────┘
[_QWERTY] = LAYOUT_planck_grid(
      KC_TAB         , KC_Q         , KC_W         , KC_E         , KC_R         , KC_T   ,     KC_Y    , KC_U         , KC_I         , KC_O         , KC_P            , KC_BSPC,
      LCTL_T(KC_ESC) , LCTL_T(KC_A) , LALT_T(KC_S) , LGUI_T(KC_D) , LSFT_T(KC_F) , KC_G   ,     KC_H    , RSFT_T(KC_J) , LGUI_T(KC_K) , RALT_T(KC_L) , RCTL_T(KC_SCLN) , KC_QUOT,
      KC_LSFT        , KC_Z         , KC_X         , KC_C         , KC_V         , KC_B   ,     KC_N    , KC_M         , KC_COMM      , KC_DOT       , KC_SLSH         , KC_ENT ,
      KC_LCTL        , LOWER        , KC_LALT      , KC_LGUI      , TT(_NUMS)    , KC_SPC ,     KC_RGUI , RAISE        , KC_LEFT      , KC_DOWN      , KC_UP           , KC_RGHT
),

//        ┌─────┬─────┬─────┬─────┬───────┬─────┐   ┌──────┬──────┬──────┬──────┬──────┬──────┐
//        │  ~  │ f1  │ f2  │ f3  │  f4   │     │   │      │ btn1 │ ms_u │ btn2 │ wh_u │      │
//        ├─────┼─────┼─────┼─────┼───────┼─────┤   ├──────┼──────┼──────┼──────┼──────┼──────┤
//        │ del │ f5  │ f6  │ f7  │  f8   │     │   │ btn3 │ ms_l │ ms_d │ ms_r │ wh_d │  |   │
//        ├─────┼─────┼─────┼─────┼───────┼─────┤   ├──────┼──────┼──────┼──────┼──────┼──────┤
//        │     │ f9  │ f10 │ f11 │  f12  │     │   │      │ wh_d │ wh_u │ home │ end  │      │
//        ├─────┼─────┼─────┼─────┼───────┼─────┤   ├──────┼──────┼──────┼──────┼──────┼──────┤
//        │     │     │     │     │ RAISE │     │   │      │ btn1 │ btn2 │ vold │ volu │ mply │
//        └─────┴─────┴─────┴─────┴───────┴─────┘   └──────┴──────┴──────┴──────┴──────┴──────┘
[_LOWER] = LAYOUT_planck_grid(
      KC_TILD , KC_F1   , KC_F2   , KC_F3   , KC_F4  , _______ ,     _______    , KC_MS_BTN1    , KC_MS_UP    , KC_MS_BTN2  , KC_MS_WH_UP   , _______,
      KC_DEL  , KC_F5   , KC_F6   , KC_F7   , KC_F8  , _______ ,     KC_MS_BTN3 , KC_MS_LEFT    , KC_MS_DOWN  , KC_MS_RIGHT , KC_MS_WH_DOWN , KC_PIPE,
      _______ , KC_F9   , KC_F10  , KC_F11  , KC_F12 , _______ ,     _______    , KC_MS_WH_DOWN , KC_MS_WH_UP , KC_HOME     , KC_END        , _______,
      _______ , _______ , _______ , _______ , RAISE  , _______ ,     _______    , KC_MS_BTN1    , KC_MS_BTN2  , KC_VOLD     , KC_VOLU       , KC_MPLY
),

//        ┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬───┬───┬───┬──────┐
//        │  `  │  1  │  2  │  3  │  4  │  5  │   │  6  │  7  │ 8 │ 9 │ 0 │ bspc │
//        ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼───┼───┼───┼──────┤
//        │ del │  (  │  )  │  +  │  =  │  {  │   │  }  │  -  │ [ │ ] │ _ │  \   │
//        ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼───┼───┼───┼──────┤
//        │     │  !  │  @  │  #  │  $  │  %  │   │  ^  │  &  │ * │ ( │ ) │      │
//        ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼───┼───┼───┼──────┤
//        │     │     │     │     │     │     │   │     │     │ { │ } │ ( │  )   │
//        └─────┴─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴───┴───┴───┴──────┘
[_RAISE] = LAYOUT_planck_grid(
      KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,     KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_BSPC,
      KC_DEL  , KC_LPRN , KC_RPRN , KC_PLUS , KC_EQL  , KC_LCBR ,     KC_RCBR , KC_MINS , KC_LBRC , KC_RBRC , KC_UNDS , KC_BSLS,
      _______ , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC ,     KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , _______,
      _______ , _______ , _______ , _______ , _______ , _______ ,     _______ , _______ , KC_LCBR , KC_RCBR , KC_LPRN , KC_RPRN
),

//        ┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌──────┬──────┬─────┬──────┬───────┬──────┐
//        │  ~  │  /  │  7  │  8  │  9  │  -  │   │      │  [   │  ]  │  =   │   [   │ bspc │
//        ├─────┼─────┼─────┼─────┼─────┼─────┤   ├──────┼──────┼─────┼──────┼───────┼──────┤
//        │     │  *  │  4  │  5  │  6  │  0  │   │ left │ down │ up  │ rght │ X(AE) │  |   │
//        ├─────┼─────┼─────┼─────┼─────┼─────┤   ├──────┼──────┼─────┼──────┼───────┼──────┤
//        │     │  +  │  1  │  2  │  3  │  .  │   │      │  {   │  }  │      │       │      │
//        ├─────┼─────┼─────┼─────┼─────┼─────┤   ├──────┼──────┼─────┼──────┼───────┼──────┤
//        │     │     │     │     │     │     │   │      │      │     │      │       │      │
//        └─────┴─────┴─────┴─────┴─────┴─────┘   └──────┴──────┴─────┴──────┴───────┴──────┘
[_NUMS] = LAYOUT_planck_grid(
      KC_TILD , KC_SLSH , KC_7    , KC_8    , KC_9    , KC_MINS ,     _______ , KC_LBRC , KC_RBRC , KC_EQL  , KC_LBRC , KC_BSPC,
      _______ , KC_ASTR , KC_4    , KC_5    , KC_6    , KC_0    ,     KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , X(AE)   , KC_PIPE,
      _______ , KC_PLUS , KC_1    , KC_2    , KC_3    , KC_DOT  ,     _______ , KC_LCBR , KC_RCBR , _______ , _______ , _______,
      _______ , _______ , _______ , _______ , _______ , _______ ,     _______ , _______ , _______ , _______ , _______ , _______
),

//        ┌─────┬─────────┬─────────┬─────────┬─────────┬─────────┐   ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────┐
//        │     │ QK_BOOT │ DB_TOGG │ RGB_TOG │ RGB_MOD │ RGB_HUI │   │ RGB_HUD │ RGB_SAI │ RGB_SAD │ RGB_VAI │ RGB_VAD │ del │
//        ├─────┼─────────┼─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────┤
//        │     │ EE_CLR  │ MU_NEXT │  AU_ON  │ AU_OFF  │ AG_NORM │   │ AG_SWAP │ QWERTY  │         │         │         │     │
//        ├─────┼─────────┼─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────┤
//        │     │ AU_PREV │ AU_NEXT │  MU_ON  │ MU_OFF  │  MI_ON  │   │ MI_OFF  │         │         │         │         │     │
//        ├─────┼─────────┼─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────┤
//        │     │         │         │         │         │         │   │         │         │         │         │         │     │
//        └─────┴─────────┴─────────┴─────────┴─────────┴─────────┘   └─────────┴─────────┴─────────┴─────────┴─────────┴─────┘
[_ADJUST] = LAYOUT_planck_grid(
      _______ , QK_BOOT , DB_TOGG , RGB_TOG , RGB_MOD , RGB_HUI ,     RGB_HUD , RGB_SAI , RGB_SAD , RGB_VAI , RGB_VAD , KC_DEL ,
      _______ , EE_CLR  , MU_NEXT , AU_ON   , AU_OFF  , AG_NORM ,     AG_SWAP , QWERTY  , _______ , _______ , _______ , _______,
      _______ , AU_PREV , AU_NEXT , MU_ON   , MU_OFF  , MI_ON   ,     MI_OFF  , _______ , _______ , _______ , _______ , _______,
      _______ , _______ , _______ , _______ , _______ , _______ ,     _______ , _______ , _______ , _______ , _______ , _______
)
};
/* clang-format on */

#ifdef AUDIO_ENABLE
float plover_song[][2]    = SONG(PLOVER_SOUND);
float plover_gb_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                print("mode just switched to qwerty and this is a huge string\n");
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case BACKLIT:
            if (record->event.pressed) {
                register_code(KC_RSFT);
#ifdef BACKLIGHT_ENABLE
                backlight_step();
#endif
#ifdef KEYBOARD_planck_rev5
                writePinLow(E6);
#endif
            } else {
                unregister_code(KC_RSFT);
#ifdef KEYBOARD_planck_rev5
                writePinHigh(E6);
#endif
            }
            return false;
            break;
        case EXT_PLV:
            if (record->event.pressed) {
#ifdef AUDIO_ENABLE
                PLAY_SONG(plover_gb_song);
#endif
            }
            return false;
            break;
    }
    return true;
}

/* clang-format off */
float melody[8][2][2] = {
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
};
/* clang-format on */

#define JUST_MINOR_THIRD 1.2
#define JUST_MAJOR_THIRD 1.25
#define JUST_PERFECT_FOURTH 1.33333333
#define JUST_TRITONE 1.42222222
#define JUST_PERFECT_FIFTH 1.33333333

#define ET12_MINOR_SECOND 1.059463
#define ET12_MAJOR_SECOND 1.122462
#define ET12_MINOR_THIRD 1.189207
#define ET12_MAJOR_THIRD 1.259921
#define ET12_PERFECT_FOURTH 1.33484
#define ET12_TRITONE 1.414214
#define ET12_PERFECT_FIFTH 1.498307

deferred_token tokens[8];

uint32_t reset_note(uint32_t trigger_time, void *note) {
    *(float*)note = 440.0f;
    return 0;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    cancel_deferred_exec(tokens[index]);
    if (clockwise) {
        melody[index][1][0] = melody[index][1][0] * ET12_MINOR_SECOND;
        melody[index][0][0] = melody[index][1][0] / ET12_PERFECT_FIFTH;
        audio_play_melody(&melody[index], 2, false);
    } else {
        melody[index][1][0] = melody[index][1][0] / ET12_MINOR_SECOND;
        melody[index][0][0] = melody[index][1][0] * ET12_TRITONE;
        audio_play_melody(&melody[index], 2, false);
    }
    tokens[index] = defer_exec(1000, reset_note, &melody[index][1][0]);
    return false;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) {
                    PLAY_SONG(plover_song);
                }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) {
                    PLAY_SONG(plover_gb_song);
                }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
    }
    return true;
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_ESC):
        case LT(_NUMS, KC_SPC):
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_ESC):
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}
