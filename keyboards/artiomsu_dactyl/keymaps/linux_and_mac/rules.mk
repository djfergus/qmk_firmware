# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = no       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
COMBO_ENABLE = no			# combo feature
LEADER_ENABLE = yes			# leader key

RGBLIGHT_ENABLE = yes        # Enable keyboard RGB underglow
RGBLIGHT_DRIVER = WS2812
WS2812_DRIVER = vendor
AUDIO_ENABLE = no           # Audio output
SPLIT_KEYBOARD = yes
SERIAL_DRIVER = vendor

SRC+= secrets.c combos.c leader.c macros.c rgb_led_control.c
