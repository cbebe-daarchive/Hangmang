#include <Arduino.h>
bool is2020 = false;

void clearLEDs() {
  // diplay is Common Cathode => HIGH = OFF
  for (int i = 42; i <= 45; i++) {
    digitalWrite(i,HIGH);
  }
}
void setup() {
  // initializes pinMode for pins 10 and 12 and pull up resistors
  pinMode(10,INPUT); digitalWrite(10,HIGH);
  pinMode(12,INPUT); digitalWrite(12,HIGH);
  // initializes the LED pins
  for (int i = 22; i <= 29; i++) {
    pinMode(i,OUTPUT); pinMode(i+24,OUTPUT);
    digitalWrite(i,LOW); digitalWrite(i+24,LOW);
  }
  // initializes the digit pins
  for (int i = 42; i <= 45; i++) {
    pinMode(i,OUTPUT);
  }
}
void writeOn7Seg(int digit, int number) {
                    //D1,D2,D3,D4
  int digitPins[4] = {42,43,44,45};
                  //A, B, C, D, E, F, G, dp
  int segPins[8] = {51,53,49,47,46,52,50,48};
  int numZero[8] = {1,1,1,1,1,1,0,0};
  int numOne[8] = {0,1,1,0,0,0,0,0};
  int numTwo[8] = {1,1,0,1,1,0,1,0};
  int numThree[8] = {1,1,1,1,0,0,1,0};
  int numFour[8] = {0,1,1,0,0,1,1,0};
  int numFive[8] = {1,0,1,1,0,1,1,0};
  int numNine[8] = {1,1,1,1,0,1,1,0};
  clearLEDs();
  digitalWrite(digitPins[digit-1], LOW);
  switch (number) {
    case 0:
      for (int i = 0; i < 8; i++) {
        digitalWrite(segPins[i], numZero[i]);
      }
      break;
    case 1:
      for (int i = 0; i < 8; i++) {
        digitalWrite(segPins[i], numOne[i]);
      }
      break;
    case 2:
      for (int i = 0; i < 8; i++) {
        digitalWrite(segPins[i], numTwo[i]);
      }
      break;
    case 3:
      for (int i = 0; i < 8; i++) {
        digitalWrite(segPins[i], numThree[i]);
      }
      break;
    case 4:
      for (int i = 0; i < 8; i++) {
        digitalWrite(segPins[i], numFour[i]);
      }
      break;
    case 5:
      for (int i = 0; i < 8; i++) {
        digitalWrite(segPins[i], numFive[i]);
      }
      break;
    case 9:
      for (int i = 0; i < 8; i++) {
        digitalWrite(segPins[i], numNine[i]);
      }
      break;
    default:
      for (int i = 0; i < 8; i++) {
        digitalWrite(segPins[i], HIGH);
      }
  } 

}

void write2019() {
  writeOn7Seg(1,2);
  delay(1);
  writeOn7Seg(2,0);
  delay(1);
  writeOn7Seg(3,1);
  delay(1);
  writeOn7Seg(4,9);
  delay(1);
}

void write2020() {
  writeOn7Seg(1,2);
  delay(1);
  writeOn7Seg(2,0);
  delay(1);
  writeOn7Seg(3,2);
  delay(1);
  writeOn7Seg(4,0);
  delay(1);
}

void playNote(int note,int dur) {
                      //C,  D,  E,  F,  G,  A,  c,  d,  Bb
                      //0,  1,  2,  3,  4,  5,  6,  7,  8
  int frequencies[9] = {262,294,330,349,392,440,523,587,466};
  // plays tone on pin 8 with given duration
  tone(8,frequencies[note],dur);
  int delayCount = 0;
  // displays 2020 while the tone is playing, this is the only way
  while (delayCount < dur) {
    writeOn7Seg(1,2);
    delay(1);
    writeOn7Seg(2,0);
    delay(1);
    writeOn7Seg(3,2);
    delay(1);
    writeOn7Seg(4,0);
    delay(1);
    delayCount += 4;
  }
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
    digitalWrite(LEDArray[note[i]], HIGH);
    // one eighth note in 133.5 bpm is 225 ms
    playNote(note[i],beat[i]*225);
    digitalWrite(LEDArray[note[i]], LOW);
  }
}

void playWack() {
  // Auld Lang Syne in 11/8 Time Signature
  int LEDArray[8] = {22,23,24,25,26,27,28,29};
  int note[58] = {0,3,2,3,5,4,3,4,5,4,3,3,5,6,7,
                  7,6,5,5,3,4,3,4,5,4,3,1,1,0,3,
                  7,6,5,5,3,4,3,4,7,6,5,5,6,7,
                  7,6,5,5,3,4,3,4,5,4,3,1,1,0,};
  int beat[58] = {2,2,1,1,1,2,1,1,1,1,2,1,1,1,5,
                  1,2,1,1,1,2,1,1,1,1,2,1,1,1,5,
                  1,2,1,1,1,2,1,1,1,2,1,1,1,5,
                  1,2,1,1,1,2,1,1,1,1,2,1,1,1,};
  for (int i = 0; i < 58; i++) {
    digitalWrite(LEDArray[note[i]], HIGH);
    playNote(note[i],beat[i]*211);
    digitalWrite(LEDArray[note[i]], LOW);
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
void countDown() {
  for (int i = 5; i > 0; i--){
    writeOn7Seg(2,i); delay(700);
    clearLEDs(); delay(300);
  }
}
void flash2020() {
  for (int i = 0; i < 3; i++) {
    int delayCount = 0;
    while (delayCount < 300) {
      write2020();
      delayCount += 4;
    }
    clearLEDs();
    delay(300);
  }
}
void loop() {
  if (!is2020) {
    write2019();
  } else {
    write2020();
  }
  if (digitalRead(10) == LOW || digitalRead(12) == LOW) {
    bool isWack = false;
    if (digitalRead(12) == LOW) {isWack = true;}
    if (!is2020) {
      countDown();
      flash2020();
      is2020 = true;
    } /*
    Should auld acquaintance be forgot, and never brought to mind?
    Should auld acquaintance be forgot, and days of auld lang syne?
    For auld lang syne, my jo, for auld lang syne,
    We'll tak a cup of kindness yet, for auld lang syne.
    */
    if (isWack) {
      playWack();
    } else {
      playAuldLangSyne();
    }
    lick();
  }
  // Happy New Year man
}