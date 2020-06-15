#include <Arduino.h>
#include <Adafruit_GFX.h>

const int maxWrongGuesses = 6;

char getInput()
{
  return 'A';
}

void correctGuess(char guessedChar)
{
}

void game()
{
  bool guessed = false;
  char guessedLetters[26];
  int guesses = 0, wrongGuesses = 0;
  const char *word = "TESTING";

  while (wrongGuesses < maxWrongGuesses && !guessed)
  {
    // implement getting user input
    char guessedChar = getInput();
    if (strchr(word, guessedChar) == NULL)
      wrongGuesses++;
    else
      correctGuess(guessedChar); // display correct char

    guessedLetters[guesses++] = guessedChar;
  }

  if (guessed)
  {
    // you won waw
  }
  else
  {
    // you los rip
  }
}