// Dactyl Manuform Hotswap
#pragma once

#include "config_common.h"
// Basic Config

//#define PRODUCT_ID 0x0002

#define SPLIT_HAND_PIN      GP26  // high = left, low = right

// Using Serial instead of I2C
#define SERIAL_USART_FULL_DUPLEX 
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1
#define SERIAL_PIO_USE_PIO0
#define SERIAL_USART_TIMEOUT     100  // USART driver timeout. default 100
#define SERIAL_USART_SPEED 921600
#define SERIAL_USART_PIN_SWAP

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 12
#define MATRIX_COLS 6

#define MATRIX_COL_PINS { GP3, GP4, GP5, GP6, GP7, GP8 }
#define MATRIX_ROW_PINS { GP10, GP11, GP12, GP13, GP14, GP15 }
#define DIODE_DIRECTION COL2ROW

#define SPLIT_POINTING_ENABLE
#define ROTATIONAL_TRANSFORM_ANGLE  -25
#define POINTING_DEVICE_INVERT_Y
#define POINTING_DEVICE_RIGHT
#define PMW33XX_CS_PIN GP17
#define POINTING_DEVICE_TASK_THROTTLE_MS 1

//// Sensor Notes ////
//// Pi Pico pins ////
// 3V3  -- Power (not 3v3_EN)
// GP17 -- CS pin
// GP20 -- MISO pin
// GP19 -- MOSI pin
// GP18 -- SCK pin clock
// GND  -- GND

// WS2812 RGB LED strip input and number of LEDs
#ifdef RGBLIGHT_ENABLE
#define RGB_DI_PIN GP17
#define RGBLED_NUM 34
//#define DRIVER_LED_TOTAL 34
#define RGBLED_SPLIT { 17, 17 }
#define STM32_SYSCLK KINETIS_SYSCLK_FREQUENCY
#define NOP_FUDGE 0.4
#endif

// OLED Pins and Driver
#ifdef OLED_ENABLE
#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP18
#define I2C1_SCL_PIN GP19
// OLED Options
#define SPLIT_OLED_ENABLE
#define SPLIT_WPM_ENABLE
#define OLED_DISPLAY_WIDTH 128
#define OLED_DISPLAY_HEIGHT 32
#define OLED_MATRIX_SIZE 512
#define OLED_RESET -1
#define OLED_DISPLAY_ADDRESS 0x3C
#define OLED_BRIGHTNESS 255
#define OLED_TIMEOUT 32000
#define OLED_FADE_OUT
#define OLED_FADE_OUT_INTERVAL 0
#endif

// Misc settings
// Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap
#define LOCKING_SUPPORT_ENABLE
// Locking resynchronize hack
#define LOCKING_RESYNC_ENABLE
// Enables This makes it easier for fast typists to use dual-function keys
#define PERMISSIVE_HOLD
// End of Basic Config
