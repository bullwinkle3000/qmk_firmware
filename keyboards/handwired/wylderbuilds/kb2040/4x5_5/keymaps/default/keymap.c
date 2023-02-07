#include QMK_KEYBOARD_H

#define _BASE 0
#define _RAISE 1
#define _LOWER 2

#define SFT_ESC  SFT_T(KC_ESC)
#define CTL_BSPC CTL_T(KC_BSPC)
#define ALT_SPC  ALT_T(KC_SPC)
#define SFT_ENT  SFT_T(KC_ENT)

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

#define ____ KC_TRANSPARENT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base (qwerty)
     * ,----------------------------------,                  ,----------------------------------,
     * |   q  |   w  |   e  |   r  |   t  |                  |   y  |   u  |   i  |   o  |   p  |
     * |------+------+------+------+------|                  |------+------+------+------+------|
     * |   a  |   s  |   d  |   f  |   g  |                  |   h  |   j  |   k  |   l  |   ;  |
     * |------+------+------+------+------|                  |------+------+------+------+------|
     * |   z  |   x  |   c  |   v  |   b  |                  |   n  |   m  |   ,  |   .  |   /  |
     * '------+------+------+-------------'                  '------+------+------+------+------'
     *        |  [   |   ]  |                                              |   '  |  `~  |
     *        '-------------+------,                                ,------|-------------'
     *                      | ESC  |                                | BSPC |
     *                      |-------------,                  ,------+------|
     *                      | TAB  |  GUI |                  | SHIFT| SPACE|
     *                      |------+------|                  |------+------|
     *                      | CTRL | RAISE|                  | LOWER| ENTER|
     *                      '-------------'                  '-------------'
     */
    [_BASE] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                 KC_LBRC, KC_RBRC,                                              KC_QUOT, KC_GRV,
                                      SFT_ESC,                       KC_BSPC,
                                      KC_TAB, KC_LGUI,       KC_RSFT, KC_SPC,
                                      KC_LCTRL, RAISE,       LOWER,   KC_ENT
        ),

    /*  RAISE
     * ,----------------------------------,                  ,----------------------------------,
     * |   1  |   2  |   3  |   4  |   5  |                  |   6  |   7  |   8  |   9  |   0  |
     * |------+------+------+------+------|                  |------+------+------+------+------|
     * |   (  |   )  |   {  |   }  |   =  |                  |  -   |   4  |   5  |   6  |   ;  |
     * |------+------+------+------+------|                  |------+------+------+------+------|
     * | QK_BOOT| BOOT |   [  |   ]  |      |                  |      |   1  |   2  |   3  |      |
     * |------+------+------+-------------|                  |------+------+------+------+------,
     *        |      |      |                                              |   0  |   .  |
     *        '-------------+------,                                ,------|-------------'
     *                      | QK_BOOT  |                            | BSPC |
     *                      |-------------,                  ,------+------|
     *                      | GUI  |  TAB |                  | SHIFT| SPACE|
     *                      |------+------|                  |------+------|
     *                      | CTRL | RAISE|                  | LOWER| ENTER|
     *                      '-------------'                  '-------------'
     */
    [_RAISE] = LAYOUT(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        S(KC_9), S(KC_0), KC_LCBR, KC_RCBR,  KC_EQL,            KC_MINS,  KC_4,    KC_5,    KC_6, KC_QUOT,
        QK_RBT, QK_BOOT, KC_LBRC, KC_RBRC,    ____,             ____,    KC_1,    KC_2,    KC_3,    ____,
        ____,    ____,                                                 KC_0,  KC_DOT,
        QK_BOOT,                            ____,
        ____,    ____,             ____,    ____,
        ____,    ____,             ____,    ____
        ),

    /*  LOWER
     * ,----------------------------------,                  ,----------------------------------,
     * |   !  |   @  |   #  |   $  |   %  |                  |   ^  |   &  |   *  |   (  |   )  |
     * |------+------+------+------+------|                  |------+------+------+------+------|
     * |   (  |   )  |   {  |   }  |   =  |                  |      |   -  |   +  |   |  |      |
     * |------+------+------+------+------|                  |------+------+------+------+------|
     * |      |      |      |      |      |                  |      | LEFT | DOWN |  UP  | RIGHT|
     * |------+------+------+-------------|                  |------+------+------+------+------,
     *        |      |      |                                              |      |      |
     *        '-------------+------,                                ,------|-------------'
     *                      | ESC  |                                | QK_BOOT |
     *                      |-------------,                  ,------+------|
     *                      | GUI  |  TAB |                  | SHIFT| SPACE|
     *                      |------+------|                  |------+------|
     *                      | CTRL | RAISE|                  | LOWER| ENTER|
     *                      '-------------'                  '-------------'
     */
    [_LOWER] = LAYOUT(
        KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
        S(KC_9), S(KC_0), KC_LBRC, KC_RBRC,  KC_EQL,               ____, KC_MINS,  KC_EQL, KC_PIPE,    ____,
        ____,    ____,    ____,    ____,    ____,               ____, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,
        ____,    ____,                                              ____, ____,
        ____,                             QK_BOOT,
        ____,    ____,             ____,    ____,
        ____,    ____,             ____,    ____
        )
};
void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}
