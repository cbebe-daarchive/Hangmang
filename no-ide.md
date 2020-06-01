# IDE-less Arduino Uploading + WSL (Windows Subsystem for Linux)

- This is a guide to uploading Arduino Sketches from a Linux Terminal. 
- This also shows you how to install a Linux Subsystem on your Windows machine.
## Installing Ubuntu WSL

1. To activate WSL, go to **Control Panel** -> Programs -> Programs and Features -> Turn Windows Features on or off -> **Windows Subsystem for Linux**. Reboot.
2. Go to Microsoft Store, search Linux, and install your distribution of "choice" (Ubuntu recommended, assuming it from now on)
3. Launch Ubuntu WSL, wait for installation, set your UNIX username and password

## Installing Arduino toolchain

1. Update and upgrade your source list
  ```
  sudo apt update
  sudo apt upgrade
  ```
2. Install Arduino SDK
  ```
  sudo apt install arduino-mk
  ```
3. Create your directory for your sketches and go to it
  ```
  mkdir ~/sketchbook
  cd ~/sketchbook
  ```
4. Create Child Makefile that attaches to Daddy Makefile (/usr/share/arduino/Arduino.mk)
  - This needs to be present in every directory that your sketches are in
  ```
  nano Makefile
  ```
  - Copy the following
  ```
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

  # Default install location of Arduino Makefile
  include $(ARDUINO_DIR)/Arduino.mk
  ```
## Uploading your sketch to the Arduino

1. Place your sketch (*.ino) file in a directory with the child Makefile (no other makefile should be present)
2. Build your binaries for the appropriate Arduino board (BOARD_TAG must be properly set)
  ```
  make
  ```
- This creates a directory named "build-(BOARD_TAG)" which contains all object and hex files needed to be flashed to the Arduino
3. Flash the sketch to the Arduino (should be connected via USB)
  ```
  make upload
  ```
4. Clean up the build folder when done uploading
  ```
  make clean
  ```
5. (Optional) Chain these commands to save time
  ```
  make upload clean
  ```
  **Note**: if you're flashing to multiple similar boards, skip the clean part to save time in compiling
  
  ## Reading from Serial Monitor coming soon
