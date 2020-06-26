#ifndef _KEY_H
#define _KEY_H

class Key
{
public:
  Key(int idx, char letter) : _idx{idx}, _letter{letter} {};

  void draw()
  {
  }

private:
  int _idx;
  char _letter;
};

#endif