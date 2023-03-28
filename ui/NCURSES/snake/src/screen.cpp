#include <algorithm>
#include <curses.h>
#include <ncurses.h>
#include <screen.h>

Screen::Screen() {
  initscr();
  raw();
  keypad(stdscr, TRUE);
  window = newwin(0, 0, 0, 0);
  box(window, '|', '-');
  Refresh();
  snk = new Snake(3, 3);
  Draw_Snake();
}

Screen::~Screen() {
  delwin(window);
  endwin();
}

void Screen::Refresh() { wrefresh(window); }
int Screen::Draw_Snake() {
  std::for_each(snk->body->begin(), snk->body->end(),
                [this](std::pair<int, int> *ptr) {
                  Draw_Char(snk->glyph, ptr->first, ptr->second);
                });

  return 0;
}
int Screen::Draw_Char(char c, int x, int y) {
  mvwaddch(window, x, y, c);
  Screen::Refresh();
  return 0;
}
