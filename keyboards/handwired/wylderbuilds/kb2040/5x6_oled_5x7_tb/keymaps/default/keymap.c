#include QMK_KEYBOARD_H

#define _BASE   0
#define _NAV    1
#define _SYST   2
#define _MOUSE  3  //layer for mouse functions

// Macros
#define TASK    LCTL(LSFT(KC_ESC))
#define TAB_R   LCTL(KC_TAB)
#define TAB_L   LCTL(LSFT(KC_TAB))
#define TAB_RO  LCTL(LSFT(KC_T))
#define CAD     LCTL(LALT(KC_DEL))
#define IAD		LCTL(LALT(KC_INS))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_5x7(
        // left hand
            LT(_SYST, KC_ESC),  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,
            KC_TAB,   		KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,
            KC_LCTL,   		KC_A,    KC_S,    KC_D,   KC_F,   KC_G,
            KC_LSFT,     	KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,
                                     KC_APP,  KC_LGUI,
        KC_LALT, LT(_NAV, KC_SPC),
        KC_BTN3, KC_BTN1,
        _______, _______,
        // right hand
            KC_6,    KC_7,    KC_8,   KC_9,     KC_0,    KC_MINS,  KC_EQL,
            KC_Y,    KC_U,    KC_I,   KC_O,     KC_P,    KC_DEL,   KC_BSPC,
            KC_H,    KC_J,    KC_K,   KC_L,     KC_SCLN, KC_QUOT,  KC_ENT,
            KC_N,    KC_M,    KC_COMM,   KC_DOT,  KC_SLSH,  KC_RSFT,  _______,
                              MO(_NAV),  TG(_MOUSE),
                 KC_SPC,
                 KC_WFWD,
        _______, KC_WBAK),

    [_NAV] = LAYOUT_5x7(
        // left hand
            KC_TILD,   _______,    _______,    _______,   _______,   _______,
            _______,   _______,    _______,    LCTL(LSFT(KC_E)),     _______,   _______,
            _______,   LCTL(KC_A), LCTL(KC_S), _______,   _______,   _______,
            _______,   KC_UNDO,    KC_CUT,     KC_COPY,   KC_PSTE,   _______,
                                   _______, _______,
        _______, _______,
        _______, _______,
        _______, _______,
        // right hand
            _______,   _______,    _______,   _______,    _______,  KC_LBRC,  KC_RBRC,
            _______,   KC_HOME,    KC_UP,     KC_END,     _______,  _______,  _______,
            KC_PGUP,   KC_LEFT,    KC_DOWN,   KC_RIGHT,   _______,  _______,  _______,
            KC_PGDN,   TAB_L,      TAB_R,     _______,    _______,  _______,  _______,
                                   _______,   _______,
             _______,
             _______,
    _______, _______),

    [_SYST] = LAYOUT_5x7(
        // left hand
            _______,   KC_F1,     KC_F2,      KC_F3,     KC_F4,     KC_F5,
            _______,   KC_INS,    KC_PAUS,    _______,   IAD,   	   CAD,
            KC_CAPS,   KC_NUM,    KC_SCRL,    _______,   _______,   _______,
            _______,   _______,   _______,    _______,   _______,   _______,
                                  _______,    _______,
        _______, _______,
        _______, _______,
        _______, _______,
        // right hand
            KC_6,      KC_F7,      KC_F8,     KC_F9,     KC_F10,  	_______,  _______,
            _______,   _______,    _______,   _______,   _______,  _______,  _______,
            _______,   _______,    _______,   KC_MSTP,   KC_VOLD,  KC_VOLU,  KC_MUTE,
            _______,   _______,    _______,   _______,   _______,  _______,  _______,
                                   QK_BOOT,   EE_CLR,
                 _______,
                 _______,
        _______, _______),

    [_MOUSE] = LAYOUT_5x7(
        // left hand
            _______,   _______,    _______,    _______,   _______,   _______,
            _______,   _______,    _______,    _______,   _______,   _______,
            _______,   _______,    _______,    _______,   _______,   _______,
            _______,   _______,    _______,    _______,   _______,   _______,
                                   _______, _______,
        _______, _______,
        _______, _______,
        _______, _______,
        // right hand
            _______,   _______,    _______,   _______,   _______,  _______,  _______,
            _______,   _______,    _______,   _______,   _______,  _______,  _______,
            _______,   KC_BTN1,    KC_BTN2,   KC_BTN3,   _______,  _______,  _______,
            _______,   _______,    _______,   _______,   _______,  _______,  _______,
                                   _______,  _______,
                 _______,
                 _______,
        _______, _______),

};


void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    debug_enable=true;
    debug_matrix=true;
    debug_keyboard=true;
    debug_mouse=true;
}

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Nav\n"), false);
            break;
        case _SYST:
            oled_write_P(PSTR("System\n"), false);
            break;
        case _MOUSE:
            oled_write_P(PSTR("Mouse\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    return false;
}
#endif