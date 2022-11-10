// Include external files
#include QMK_KEYBOARD_H
#include <stdio.h>
#ifdef OLED_ENABLE
#include "oled_driver.h"
#include "./sharedDefines.h"
//#include "oled-saferead.c"
#include "./dog.c" // This file is from HellTM here's the video.「 https://www.youtube.com/watch?v=HgIQRazCAjo 」

// Oleds rotation
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

// Need Lines for showing if caps/etc and what layer is toggled.
bool oled_task_user(void) {
if (is_keyboard_left()) {

  // Host  (is_keyboard_)keyboard layer status
  oled_write_P(PSTR("layer: "), false);

  switch (get_highest_layer(layer_state)) {
    case colemak:
      oled_write_P(PSTR("Default\n"), false);
      break;

    case hub:
      oled_write_P(PSTR("hub\n"), false);
      break;

    case qwerty:
      oled_write_P(PSTR("qwerty\n"), false);
      break;

    case furo:
      oled_write_P(PSTR("furo\n"), false);
      break;

    default:
      // Or use the write_ln shortcut over adding '\n' to the end of your string
      oled_write_P(PSTR("Undefined"), false);

  }

    // Host Keyboard LED status
    oled_write_P(PSTR("NKRO "), keymap_config.nkro);
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    // Keyboard Pet vartables start
    current_wpm   = get_current_wpm();
    led_usb_state = host_keyboard_led_state();
    // Keyboard Pet vartables end
  }
//if (is_keyboard_left()) {}

    if (is_keyboard_master()) {
      print_status_narrow();
    } else {
      print_logo_narrow();
    }

    return false;
}
#endif
