/*
  words.h
  
  Contains all the words for the Hangman game
  Feel free to add your own words!
*/

#ifndef _WORDS_H_
#define _WORDS_H_

#include <avr/pgmspace.h>

const char word1[] = "fluctuation";
const char word2[] = "intent";
const char word3[] = "hemorrhoids";
const char word4[] = "sacrifice";

const char *const words[] = {word1, word2, word3, word4};

#endif // _WORDS_H_