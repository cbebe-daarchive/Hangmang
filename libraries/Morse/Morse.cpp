/*
  Morse.cpp - Library for flashing Morse code.
  Modified to actually print messages and 
*/

#include "Morse.h"

// define units
const int dot = 1;
const int dash = 3;

const char letters[] ={ 
  0x0D, // A
  0x57, // B
  0x77, // C
  0x17, // D
  0x01, // E
  0x75, // F
  0x1F, // G
  0x55, // H
  0x05, // I
  0xFD, // J
  0x37, // K
  0x5D, // L
  0x0F, // M
  0x07, // N
  0x3F, // O
  0x7D, // P
  0xDF, // Q
  0x1D, // R
  0x15, // S
  0x03, // T
  0x35, // U
  0xD5, // V
  0x3D, // W
  0xD7, // X
  0xF7, // Y
  0x5F, // Z
};

// anything with HH (error digraph) does not exist
                    //  ! " # $ % & ' ( ) * + , - . / 0 1 2 3 4 5 6 7 8 9 : ; < = > ? @
const char* digraphs = "KWRRHHSXHHASWGNGKKHHARGWDURKNROMWMUMSMHTEHTHMSOIONOSKRHHNUHHUDAC";



Morse::Morse(void (*onCallback)(), void (*offCallback)(), int duration) {
  on = onCallback;
  off = offCallback;
  _duration = duration;
}

void Morse::FlashMessage(char* message, bool nopause) {
  int space = nopause ? dot : dash;
  if (message == "") return error();
  {
    int i = 0;
    while (message[i] != '\0') {
      readChar(message[i++]);
      pause(space);
    }
  }
}

// get digraph for special characters
void Morse::getDigraph(char* dg, int idx) {
  dg[0] = digraphs[2 * idx];
  dg[1] = digraphs[2 * idx + 1];
  dg[2] = 0;
}

// these are usually combinations of letters
void Morse::specialSymbols(char character) {
  if (character == ' ') return pause(dash);
  int idx = character - '!';
  char dg[3];
  getDigraph(dg, idx);
  FlashMessage(dg, true);
}

void Morse::readChar(char character) {
  // invalid character
  if (character < ' ') return error();
  // special symbols & numbers
  if (character < 'A') return specialSymbols(character);
  // uppercase letters
  if (character <= 'Z') return flashChar((int) letters[character - 'A']);
  // idk why underscore is not with the other symbols
  if (character == '_') return FlashMessage("UK", true);
  // lowercase letters
  if (character >= 'a' && character <= 'z') 
    return flashChar(letters[character - 'a']);
  error();
}

// send error prosign (HH)
void Morse::error() {
  FlashMessage("HH", true);
}

void Morse::flashChar(int character) {
  while (character) {
    // get first two bits
    flash(character & dash);
    pause(dot);
    // read next symbol
    character >>= 2;
  }
}

// a dot is one unit, a dash three
void Morse::flash(int unit) {
  on();
  pause(unit);
  off();
}

// space between dots and dashes: 1, letters: 3, words: 7
void Morse::pause(int unit) {
  delay(_duration * unit);
}