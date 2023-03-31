#ifndef SNAKE_H_
#define SNAKE_H_

#include <algorithm>
#include <array>
#include <utility>
#include <vector>

enum class DIR { UPP = 0, DOWN = 1, LEFT = 2, RIGHT = 3 };

struct Snake {
  std::vector<std::pair<int, int> *> *body;
  const std::pair<int, int> *dir;
  static constexpr char glyph = '#';
  static constexpr std::array<std::pair<int, int>, 4> paths = {
      std::pair<int, int>{-1, 0}, std::pair<int, int>{1, 0},
      std::pair<int, int>{0, -1}, std::pair<int, int>{0, 1}};

  Snake(int x = 1, int y = 1);
  ~Snake();
  int Move();
  int Grow();
  int Change_Direction(DIR d);
};

#endif // SNAKE_H_
