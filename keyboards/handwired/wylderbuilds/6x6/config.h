//
// Created by nethe on 11/9/2022.
//
//#define PRODUCT_ID 0x0001

#ifndef WYLD_QMK_FIRMWARE_CONFIG_H
#define WYLD_QMK_FIRMWARE_CONFIG_H

#endif // WYLD_QMK_FIRMWARE_CONFIG_H

// Dactyl Manuform Hotswap
#pragma once

#include "config_common.h"
// Basic Config

#define SPLIT_HAND_PIN      GP26  // high = left, low = right

//#define VENDOR_ID 0x444d
//#define PRODUCT_ID 0x3536

// Using Serial instead of I2C
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1
#define SERIAL_PIO_USE_PIO0
#define SERIAL_USART_TIMEOUT     100  // USART driver timeout. default 100
#define SERIAL_USART_SPEED 921600
#define SERIAL_USART_PIN_SWAP

// RP2040 Settings
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED_MASK 0U
// More RP2040 Settings
#define RP2040_FLASH_AT25SF128A
#define RP2040_FLASH_GD25Q64CS
#define RP2040_FLASH_W25X10CL
#define RP2040_FLASH_IS25LP080
#define RP2040_FLASH_GENERIC_03H

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 14
#define MATRIX_COLS 6

#define MATRIX_COL_PINS { GP3, GP4, GP5, GP6, GP7, GP8 }
#define MATRIX_ROW_PINS { GP9, GP10, GP11, GP12, GP13, GP14, GP15 }
#define DIODE_DIRECTION COL2ROW

// End of Basic Config