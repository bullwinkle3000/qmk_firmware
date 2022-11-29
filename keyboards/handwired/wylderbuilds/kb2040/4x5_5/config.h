// Dactyl Manuform Hotswap
#pragma once

#include "config_common.h"

//#define PRODUCT_ID 0x0004

// Basic Config
//#define SPLIT_HAND_PIN      GP26  // high = left, low = right

#define USE_SERIAL
#define SPLIT_HAND_PIN      GP29  // high = left, low = right

// Using Serial instead of I2C
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1
#define SERIAL_PIO_USE_PIO0
#define SERIAL_USART_TIMEOUT 100  // USART driver timeout. default 100
#define SERIAL_USART_SPEED 921600
#define SERIAL_USART_PIN_SWAP

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED_MASK 0U

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 10
#define MATRIX_COLS 5

// wiring of each half
#define MATRIX_COL_PINS { GP5, GP6, GP7, GP8, GP9 }
#define MATRIX_ROW_PINS { GP26, GP18, GP20, GP19, GP10 }

#define DIODE_DIRECTION COL2ROW

// WS2812 RGB LED strip input and number of LEDs

// Misc settings                                              -=hy
// Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap
#define LOCKING_SUPPORT_ENABLE
// Locking resynchronize hack
#define LOCKING_RESYNC_ENABLE
// Enables This makes it easier for fast typists to use dual-function keys
#define PERMISSIVE_HOLD

// End of Basic Config
