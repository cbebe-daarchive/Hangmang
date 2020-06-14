/*
  Morse.h - Modified Morse class to actually flash messages
*/

#ifndef MORSE_H
#define MORSE_H

#include <Arduino.h>

class Morse
{
public:
  // Constructor takes two callback functions for on and off signal and the "dot" duration
  // set displayOnSerial to false to prevent from displaying the message on Serial monitor
  Morse(void (*onCallback)(), void (*offCallback)(), int duration = 60, bool displayOnSerial = true)
      : on{onCallback}, off{offCallback}, _duration{duration}, _displayOnSerial{displayOnSerial} {};
  // Flashes message, set nopause to true to not place pauses between letters (prosigns)
  void flashMessage(char *message, bool nopause = false);

private:
  // checking for special symbols and numbers
  void specialSymbols(char character);
  // functions for dealing with single characters
  void readChar(char character);
  void flashChar(byte character);
  void getDigraph(char *dg, int idx);
  void error();

  // flashes an on signal once
  void flash(int unit);
  void pause(int unit);

  // Callbacks for on and off signals
  void (*on)();
  void (*off)();
  // 60 as default
  int _duration;
  // display characters on Serial Monitor
  bool _displayOnSerial;
};

#endif
