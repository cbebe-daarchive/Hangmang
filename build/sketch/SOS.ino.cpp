#include <Arduino.h>
#line 1 "c:\\Users\\maple\\home\\Project-Sigma\\Morse\\examples\\SOS\\SOS.ino"
#include <Morse.h>

Morse morse(13);

void setup()
{
}

void loop()
{
  morse.dot(); morse.dot(); morse.dot();
  morse.dash(); morse.dash(); morse.dash();
  morse.dot(); morse.dot(); morse.dot();
  delay(3000);
}


