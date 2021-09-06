OLED_ENABLE = no
OLED_DRIVER = SSD1306   # Enables the use of OLED displays
ENCODER_ENABLE = yes       # Enables the use of one or more encoders

LEADER_ENABLE = no         # Enable the leader key feature. See readme.md.

BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
EXTRAKEY_ENABLE = yes      # Audio control and System control
TAP_DANCE_ENABLE = no      # Enable the tap dance feature.
CONSOLE_ENABLE = no        # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no      # Breathing sleep LED during USB suspend
BACKLIGHT_ENABLE = no      # Enable background light
LED_MATRIX_ENABLE = no
RGB_MATRIX_ENABLE = yes
SEQUENCER_ENABLE = no
TERMINAL_ENABLE = no
UNICODE_ENABLE = no
WPM_ENABLE = no
MOUSEKEY_ENABLE = no
RAW_ENABLE = no

COMBO_ENABLE = no

# Saves a bunch of memory
EXTRAFLAGS += -flto
CONSOLE_ENABLE = no
VERBOSE = no
DEBUG_MATRIX_SCAN_RATE  = no
DEBUG_MATRIX = no
MAGIC_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
