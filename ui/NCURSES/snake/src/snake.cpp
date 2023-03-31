#include <snake.h>

Snake::Snake(int x, int y) {
  body = new std::vector<std::pair<int, int> *>;
  body->push_back(new std::pair<int, int>{x, y});
  Change_Direction(DIR::RIGHT);
}

Snake::~Snake() { delete body; }

int Snake::Grow() {
  std::pair<int, int> *last = body->back();
  body->push_back(new std::pair<int, int>{last->first + 1, last->second});
  return 0;
}

int Snake::Move() {
  auto first = body->front();
  std::pair<int, int> *front = new std::pair<int, int>{
      first->first + dir->first, first->second + dir->second};

  body->insert(body->begin(), front);
  body->pop_back();
  return 0;
}

int Snake::Change_Direction(DIR d) {
  dir = &paths[(int)d];
  return 0;
}
