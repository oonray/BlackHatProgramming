#ifndef SNAKE_H_
#define SNAKE_H_

#include <algorithm>
#include <array>
#include <utility>
#include <vector>

struct Snake {
  std::vector<std::pair<int, int> *> *body;
  static constexpr char glyph = '#';

  Snake(int x = 1, int y = 1);
  ~Snake();
  int Move(int x, int y);
  int Grow();
};

#endif // SNAKE_H_
