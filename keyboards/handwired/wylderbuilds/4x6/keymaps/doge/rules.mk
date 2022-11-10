# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file

#Build Options. change yes to no to disable
VIA_ENABLE = yes 										# Enable VIA support
# Change Bootmagic from no to lite if you wanna use bootmagic
BOOTMAGIC_ENABLE = no 						  # Enable Bootmagic Lite
LTO_ENABLE = yes										# Enables Link Time Optimization

COMBO_ENABLE = yes									# Enables combos
LEADER_ENABLE = yes									# Enable Leader
MOUSEKEY_ENABLE = yes								# Mouse keys
EXTRAKEY_ENABLE = no         				# Audio control and System control
NKRO_ENABLE = yes										# Enable N-Key Rollover
TAP_DANCE_ENABLE = yes 							# Enable tap-dance

# Sourcing needed base files
#SRC+=
