#ifndef _BLANK_H
#define _BLANK_H

class Blank
{
public:
  Blank(int idx,
        char letter,
        void (*revealCallback)(int, char),
        void (*hideCallback)(int, char))
      : _idx{idx},
        _letter{letter},
        reveal{revealCallback},
        hide{hideCallback}
  {
    isGuessed = false;
  };

  void update()
  {
    if (isGuessed)
      reveal(_idx, _letter);
    else
      hide(_idx, _letter);
  }

  void guessed()
  {
    isGuessed = true;
    reveal(_idx, _letter);
  };

  void reset()
  {
    isGuessed = false;
    hide(_idx, _letter);
  };

private:
  int _idx;
  char _letter;
  bool isGuessed;
  void (*reveal)(int idx, char letter);
  void (*hide)(int idx, char letter);
};

#endif