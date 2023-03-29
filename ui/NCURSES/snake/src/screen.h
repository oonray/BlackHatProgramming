#ifndef SCREEN_H_
#define SCREEN_H_

#include <ncurses.h>
#include <snake.h>

class Screen {
private:
  WINDOW *window;
  Snake *snk;

public:
  Screen();
  ~Screen();
  void Refresh();
  void Clear();
  void Clear_Draw();
  int Draw_Snake();
  int Draw_Char(char ch, int x, int y);
};

#endif // SCREEN_H_
