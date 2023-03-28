#include <snake.h>

Snake::Snake(int x, int y) {
  body = new std::vector<std::pair<int, int> *>;
  body->push_back(new std::pair<int, int>{x, y});
}

Snake::~Snake() { delete body; }

int Snake::Grow() {
  std::pair<int, int> *last = body->back();
  body->push_back(new std::pair<int, int>{last->first + 1, last->second});
  return 0;
}
