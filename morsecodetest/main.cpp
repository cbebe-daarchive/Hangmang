#include <Arduino.h>
#include "Morse.h"

void setup() {
  init();
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void onTone() {
  tone(13, 440, 1000);
}

void offTone() {
  noTone(13);
}

int main() {
  Morse buzzer(onTone, offTone, 60);
  while (true) {
    tone(13, 440, 1000);
  }
  onTone();

  // while (true) {
  //   buzzer.FlashMessage("MORSE CODE");
  // }

  return 0;
}