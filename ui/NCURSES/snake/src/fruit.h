#ifndef FRUIT_H_
#define FRUIT_H_

#include <cstdlib>
#include <snake.h>

struct Fruit {
  static constexpr char glyph = 'O';
  std::pair<int, int> *loc;

  Fruit(int ix, int iy, Snake *snk);
  ~Fruit();
  int Check_Snake_Path(Snake *snk);
  int New_Loc(int ix, int iy);
};

#endif // FRUIT_H_
