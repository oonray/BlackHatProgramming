#include <screen.h>

Screen::Screen() {
  srand(time(0));
  initscr();
  // raw();
  cbreak();
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);
  window = newwin(0, 0, 0, 0);
  getmaxyx(window, y, x);
  Refresh();

  snk = new Snake(3, 3);
  frt = new Fruit(x, y, snk);
  Draw_Snake();
  Draw_Fruit();
  Refresh();
}

Screen::~Screen() {
  delwin(window);
  endwin();
}

void Screen::Refresh() { wrefresh(window); }
void Screen::Clear() { wclear(window); }
void Screen::Clear_Draw() {
  wclear(window);
  Draw_Snake();
  Draw_Fruit();
  Refresh();
}

int Screen::Check_Fruit(std::pair<int, int> *p) {
  // one before fruit
  if ((p->first == (frt->loc->first - snk->dir->first)) &&
      ((p->second == (frt->loc->second - snk->dir->second)))) {
    return 0;
  }
  return -1;
}

std::pair<int, int> *Screen::Check_Border(std::pair<int, int> *p) {
  if (p->first < 0) {
    p->first = y;
    return p;
  }

  if (p->second < 0) {
    p->second = x;
    return p;
  }

  if (p->first > y) {
    p->first = 0;
    return p;
  }

  if (p->second > x) {
    p->second = 0;
    return p;
  }

  return nullptr;
}

int Screen::Draw_Snake() {
  std::for_each(snk->body->begin(), snk->body->end(),
                [this](std::pair<int, int> *ptr) {
                  Check_Border(ptr);
                  Draw_Char(snk->glyph, ptr->first, ptr->second);
                });

  return 0;
}

int Screen::Erase_Snake() {
  std::for_each(snk->body->begin(), snk->body->end(),
                [this](std::pair<int, int> *ptr) {
                  Erase_Char(snk->glyph, ptr->first, ptr->second);
                });

  return 0;
}
int Screen::Draw_Fruit() {
  Draw_Char(frt->glyph, frt->loc->first, frt->loc->second);
  return 0;
}

int Screen::Erase_Fruit() {
  Erase_Char(frt->glyph, frt->loc->first, frt->loc->second);
  return 0;
}
int Screen::Draw_Char(char c, int x, int y) {
  mvwaddch(window, x, y, c);
  return 0;
}

int Screen::Erase_Char(char c, int x, int y) {
  mvwdelch(window, x, y);
  return 0;
}

void Screen::Draw_Loop() {
  int c;
  while (!done) {
    Erase_Fruit();
    Erase_Snake();

    if (Check_Fruit(snk->body->front()) == 0) {
      snk->Grow();
      frt->New_Loc(x, y);
    }

    if (time(0) % 10 == 0) {
      Clear();
    }

    Refresh();
    snk->Move();
    Draw_Snake();
    Draw_Fruit();
    Refresh();
    usleep(delay);
  }
}

void Screen::Key_Loop() {
  int ch;
  while (!done) {
    ch = getch();
    switch (ch) {
    case KEY_LEFT:
      snk->Change_Direction(DIR::LEFT);
      break;
    case KEY_RIGHT:
      snk->Change_Direction(DIR::RIGHT);
      break;
    case KEY_UP:
      snk->Change_Direction(DIR::UPP);
      break;
    case KEY_DOWN:
      snk->Change_Direction(DIR::DOWN);
      break;
    case 27:
      done = true;
      break;
    default:
      break;
    }
  }
}
