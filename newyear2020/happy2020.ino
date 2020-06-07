#include <Arduino.h>
bool is2020 = false;
int year2019[4] = {2,0,1,9};
int year2020[4] = {2,0,2,0};

void clearLEDs() {
  // diplay is Common Cathode => HIGH = OFF
  for (int i = 42; i < 46; i++) {
    digitalWrite(i, HIGH);
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
  int numDec[10] = {63,6,91,79,102,109,125,7,127,111};
  clearLEDs();
  int numDisplayed = numDec[number];
  digitalWrite(digitPins[digit], LOW);
  for (int i = 0; i < 8; i++) {
    if (numDisplayed & 1) {
      digitalWrite(segPins[i], HIGH);
    } else {
      digitalWrite(segPins[i], LOW);
    }
    numDisplayed >>= 1;
  }
  

}

void write4digits(int num[]) {
  for (int i = 0; i < 4 ; i++) {
    writeOn7Seg(i,num[i]);
    delay(1);
  }
}

void playNote(int note,int dur) {
                      //C,  D,  E,  F,  G,  A,  c,  d,  Bb
                      //0,  1,  2,  3,  4,  5,  6,  7,  8
  int frequencies[9] = {262,294,330,349,392,440,523,587,466};
  // plays tone on pin 8 with given duration
  tone(8,frequencies[note],dur);
  int delayCount = 0;
  // displays 2020 while the tone is playing
  while (delayCount < dur) {
    write4digits(year2020);
    delayCount += 4;
  }
}

void playLick(int beat[], int tempo) {
  int LEDArray[5] = {22,23,24,25,26};
  int note[8] = {4,5,8,6,4,5,3,4};
  // because the lights are remapped
  int LEDs[8] = {1,2,3,4,1,2,0,1};
  for (int i = 0; i < 8; i++) {
    digitalWrite(LEDArray[LEDs[i]],HIGH);
    playNote(note[i],beat[i]*tempo);
    digitalWrite(LEDArray[LEDs[i]],LOW);
  }
}

void lick(bool isWack) {
  // pa da da da dum doo wah
  int beat[8] = {4,2,4,2,1,5,4,6};
  int beatWack1[8] = {1,1,1,1,0,1,1,0};
  int beatWack2[8] = {1,1,1,2,0,2,1,5};
  if (isWack) {
    playLick(beatWack1,105);
    playLick(beatWack2,105);
  } else {
    playLick(beat,63);
  }
}

void playMelody(int beat[], int tempo) {
  int LEDArray[8] = {22,23,24,25,26,27,28,29};
  // The notes of the melody with the frequencies defined
  // in the playNote function
  int note[58] = {0,3,2,3,5,4,3,4,5,4,3,3,5,6,7,
                  7,6,5,5,3,4,3,4,5,4,3,1,1,0,3,
                  7,6,5,5,3,4,3,4,7,6,5,5,6,7,
                  7,6,5,5,3,4,3,4,5,4,3,1,1,0,};
  for (int i = 0; i < 58; i++) {
    digitalWrite(LEDArray[note[i]], HIGH);
    playNote(note[i],beat[i]*tempo);
    digitalWrite(LEDArray[note[i]], LOW);
  }
}

void playAuldLangSyne(bool isWack) {
  int beat[58] = {2,3,1,2,2,3,1,2,1,1,3,1,2,2,6,
                  2,3,1,2,2,3,1,2,1,1,3,1,2,2,6,
                  2,3,1,2,2,3,1,2,2,3,1,2,2,6,
                  2,3,1,2,2,3,1,2,1,1,3,1,2,2,};
  int wack[58] = {1,2,1,1,1,2,1,1,1,1,2,1,1,1,5,
                  1,2,1,1,1,2,1,1,1,1,2,1,1,1,5,
                  1,2,1,1,1,2,1,2,1,2,1,1,1,5,
                  1,2,1,1,1,2,1,1,1,1,2,1,1,1};
  if (isWack) {
    playMelody(wack,211);
  } else { 
    playMelody(beat,225);
  }
  lick(isWack);
}

void countDown() {
  for (int i = 5; i > 0; i--){
    writeOn7Seg(1,i); 
    if (digitalRead(10) == HIGH || digitalRead(12) == HIGH) {
      delay(700); clearLEDs(); delay(300);
    } else {
      delay(200);
    }
  }
}
void flash2020() {
  for (int i = 0; i < 3; i++) {
    int delayCount = 0;
    while (delayCount < 300) {
      write4digits(year2020);
      delayCount += 4;
    }
    clearLEDs();
    delay(300);
  }
}

void loop() {
  if (!is2020) {
    write4digits(year2019);
  } else {
    write4digits(year2020);
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
    playAuldLangSyne(isWack);
  }
  // Happy New Year man
}
