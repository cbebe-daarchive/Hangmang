#include "Morse.h"

void setup() {
  init();
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void onTone() {
  tone(13, 600);
  digitalWrite(13, HIGH);
}

void offTone() {
  noTone(13);
  digitalWrite(13, LOW);
}

Morse buzzer(onTone, offTone, 60);

void loop() {

  while (true) {
    buzzer.FlashMessage("this charles");
    delay(1000);
  }
}