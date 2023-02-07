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

// End of Basic Config
