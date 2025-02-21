# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
# AUDIO_ENABLE = yes          # Audio output

RGB_MATRIX_ENABLE = no     # Enable WS2812 RGB matrix
#RGB_MATRIX_DRIVER = WS2812
SPLIT_KEYBOARD = yes

#RGBLIGHT_SUPPORTED = yes
#RGB_MATRIX_SUPPORTED = yes

LAYOUTS = split_3x5_3
