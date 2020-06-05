# Default Arduino make file for ubuntu install for U of A Cmput 296/297
# uses a master Makefile derived from a super special Make include available at
#       http://mjo.tc/atelier/2009/02/arduino-cli.html
# It is assumed that Arduino.mk is copied into
# `$(ARDUINO_UA_ROOT)/arduino-ua/mkfiles/' 
# and that ard-parse-boards is located somewhere it can be executed from (such
# as `/usr/local/bin`). Note: ard-parse-boards depends on Perl with YAML
# package (`cpan install YAML` it if you don't have it).

# if there is a ARDUINO_UA_ROOT environment variable, it defines the 
# root of the arduino_ua install.  If not, we assume it is in HOME
ifndef ARDUINO_UA_ROOT
  ARDUINO_UA_ROOT=$(HOME)
endif


ifeq ($(shell uname -s),Darwin)
    # This works for OS X

    ARDUINO_UA_DIR = $(ARDUINO_UA_ROOT)/arduino-ua
    ARDUINO_DIR = $(ARDUINO_UA_DIR)/Arduino.app/Contents/Resources/Java
    AVR_TOOLS_PATH = $(ARDUINO_DIR)/hardware/tools/avr/bin

    AVRDUDE_COM_OPTS = -v -v -v
    AVRDUDE_CONF = $(ARDUINO_DIR)/hardware/tools/avr/etc/avrdude.conf
    AVRDUDE =  $(ARDUINO_DIR)/hardware/tools/avr/bin/avrdude

    # allow user to specify port in Makefile explicitly via
    # make upload ARDUINO_PORT=/dev/ttyACM1
    ifndef ARDUINO_PORT
      ARDUINO_PORT = /dev/tty.usbmodem*
    endif
    # end of OSX

else
    # This works for Linux ubuntu 32 and 64 bit

    ARDUINO_UA_DIR = $(ARDUINO_UA_ROOT)/arduino-ua
    ifeq ($(shell uname -m),x86_64)
        ARDUINO_DIR = $(ARDUINO_UA_DIR)/arduino-1.0.1-64
    else
        ARDUINO_DIR = $(ARDUINO_UA_DIR)/arduino-1.0.1-32
    endif

    # allow user to specify port in Makefile explicitly via
    # make upload ARDUINO_PORT=/dev/ttyACM1
    ifndef ARDUINO_PORT
      ARDUINO_PORT = /dev/ttyACM*
    endif

    AVR_TOOLS_PATH = $(ARDUINO_DIR)/hardware/tools/avr/bin

    AVRDUDE_COM_OPTS = -v -v -v
    AVRDUDE_CONF = $(ARDUINO_DIR)/hardware/tools/avrdude.conf
    AVRDUDE =  $(ARDUINO_DIR)/hardware/tools/avrdude
endif
# end of ubuntU

# After you've defined all of the variables above,
# THEN you can include Arduino.mk:
include $(ARDUINO_UA_DIR)/mkfiles/Arduino.mk
