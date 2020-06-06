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
    Morse(void (*onCallback)(), void (*offCallback)(), int duration);
    // Flashes message, set nopause to true to not place pauses between letters
    void FlashMessage(char* message, bool nopause = false);
  private:
    // functions for 
    void specialSymbols(char character);
    void flash(int unit);
    void pause(int unit);
    void readChar(char character);
    void flashChar(int symbol);
    void getDigraph(char* dg, int idx);
    void error();
    // Callbacks
    void (*on)();
    void (*off)();
    int _duration;
};

#endif

