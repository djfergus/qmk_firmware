LTO_ENABLE = yes
COMMAND_ENABLE = no
DYNAMIC_MACRO_ENABLE = yes
RGBLIGHT_ENABLE = yes
RGB_MATRIX_ENABLE = no
CONSOLE_ENABLE = no
MOUSEKEY_ENABLE = yes
POINTING_DEVICE_ENABLE = no
EXTRAKEY_ENABLE = no #audio and brightness and shiet like that
BOOTMAGIC_ENABLE = no
COMBO_ENABLE = yes #pretty cool allows you to press two keys at the same time which will result in another key
AUDIO_ENABLE = no
LEADER_ENABLE = yes # allows you to do vim like key sequences
MIDI_ENABLE = no
UNICODE_ENABLE = no
BLUETOOTH_ENABLE = no
RAW_ENABLE = no
NKRO_ENABLE = yes
AUTO_SHIFT_ENABLE = no

SRC+= leader.c combos.c lighting.c
