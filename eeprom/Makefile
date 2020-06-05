# Arduino Child Makefile

# board type (uno/mega2560)
ifndef BOARD_TAG
BOARD_TAG = mega2560
endif

# Point to real makefile
ifndef ARDUINO_DIR
ARDUINO_DIR = /usr/share/arduino
endif
# Where to find the arduino
ifndef ARDUINO_PORT
ARDUINO_PORT = /dev/ttyACM*
endif
# Path to user libraries
ifndef USER_LIB_PATH
USER_LIB_PATH = $(HOME)/Project-Sigma/libraries
endif

# Install location of Arduino Makefile
include $(ARDUINO_DIR)/Arduino.mk
