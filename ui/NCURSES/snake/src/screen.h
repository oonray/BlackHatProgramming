#ifndef SCREEN_H_
#define SCREEN_H_

#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <fruit.h>
#include <ncurses.h>
#include <snake.h>
#include <unistd.h>
#include <vector>

class Screen {
private:
  int x, y;
  bool done = false;
  WINDOW *window;
  Snake *snk;
  Fruit *frt;

  static constexpr int delay = 150000;

public:
  Screen();
  ~Screen();
  void Refresh();
  void Clear();
  void Clear_Draw();
  // check
  std::pair<int, int> *Check_Border(std::pair<int, int> *p);
  int Check_Fruit(std::pair<int, int> *p);
  // fruits
  int Draw_Fruit();
  int Erase_Fruit();
  // snake
  int Draw_Snake();
  int Erase_Snake();
  // Draw
  int Draw_Char(char ch, int x, int y);
  int Erase_Char(char ch, int x, int y);
  // loops
  void Draw_Loop();
  void Key_Loop();
};

#endif // SCREEN_H_
