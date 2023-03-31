#include "fruit.h"

Fruit::Fruit(int ix, int iy, Snake *snk) { New_Loc(ix, iy); }

Fruit::~Fruit() {}

int Fruit::New_Loc(int ix, int iy) {
  int x = (rand() % ix) - 2;
  int y = (rand() % iy) - 2;

  loc = new std::pair<int, int>(y, x);
  return 0;
}
