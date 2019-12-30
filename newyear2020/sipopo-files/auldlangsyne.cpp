#include <Arduino.h>

void setup() {
  // initializes pinMode for pin 10 and pull up resistor
  pinMode(10,INPUT);
  digitalWrite(10,HIGH);
  // initializes the LED pins
  for (int i = 22; i < 30; i++) {
    pinMode(i,OUTPUT);
    digitalWrite(i,LOW);
  }
}
void playNote(int note,int dur) {
                      //C,  D,  E,  F,  G,  A,  c,  d,  Bb
                      //0,  1,  2,  3,  4,  5,  6,  7,  8
  int frequencies[9] = {262,294,330,349,392,440,523,587,466};
  // plays tone on pin 8 with given duration
  tone(8,frequencies[note],dur);
  // this is always necessary or else the Arduino will 
  // try playing all the notes all at once
  delay(dur);
}
void playAuldLangSyne() {
  int LEDArray[8] = {22,23,24,25,26,27,28,29};
  // The notes of the melody with the frequencies defined
  // in the playNote function
  int note[58] = {0,3,2,3,5,4,3,4,5,4,3,3,5,6,7,
                  7,6,5,5,3,4,3,4,5,4,3,1,1,0,3,
                  7,6,5,5,3,4,3,4,7,6,5,5,6,7,
                  7,6,5,5,3,4,3,4,5,4,3,1,1,0,};
  // the durations of the notes in terms of eighth notes
  int beat[58] = {2,3,1,2,2,3,1,2,1,1,3,1,2,2,6,
                  2,3,1,2,2,3,1,2,1,1,3,1,2,2,6,
                  2,3,1,2,2,3,1,2,2,3,1,2,2,6,
                  2,3,1,2,2,3,1,2,1,1,3,1,2,2,};
  for (int i = 0; i < 58; i++) {
    // turns on the corresponding LED when note is played
    digitalWrite(LEDArray[i], HIGH);
    // one eighth note in 133.5 bpm is 225 ms
    playNote(note[i],beat[i]*225);
    // turns it off
    digitalWrite(LEDArray[i], LOW);
  }
}

void lick() {
  // pa da da da dum doo wah
  int note[8] = {4,5,8,6,4,5,3,4};
  int beat[8] = {4,2,4,2,1,5,4,6};
  int LEDs[8] = {1,2,3,4,1,2,0,1};
  for (int i = 0; i < 8; i++) {
    digitalWrite(22+LEDs[i],HIGH);
    playNote(note[i],beat[i]*63);
    digitalWrite(22+LEDs[i],LOW);
  }
}
void loop() {
  if (digitalRead(10) == LOW) {
    // Should auld acquaintance be forgot, and never brought to mind?
    // Should auld acquaintance be forgot, and days of auld lang syne?
    // For auld lang syne, my jo, for auld lang syne,
    // We'll tak a cup of kindness yet, for auld lang syne.
    playAuldLangSyne();
    lick();
  }
  // Happy New Year man
}