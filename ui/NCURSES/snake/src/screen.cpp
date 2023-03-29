#include <algorithm>
#include <chrono>
#include <curses.h>
#include <ncurses.h>
#include <screen.h>
#include <thread>

Screen::Screen() {
  initscr();
  raw();
  keypad(stdscr, TRUE);
  window = newwin(0, 0, 0, 0);
  Refresh();
  snk = new Snake(3, 3);
  Clear_Draw();

  std::chrono::seconds dura(1);
  for (int i = 0; i < 10; i++) {
    std::this_thread::sleep_for(dura);
    snk->Move();
    Clear_Draw();
  }
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
  Refresh();
}

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
