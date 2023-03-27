#include <iostream>
#include <ncurses.h>
#include <string>

class Screen {
private:
  WINDOW *window;

public:
  Screen();
  ~Screen();
  void Refresh();
};

Screen::Screen() {
  initscr();
  window = newwin(0, 0, 0, 0);
}

Screen::~Screen() {
  delwin(window);
  endwin();
}

void Screen::Refresh() { wrefresh(window); }

int main(int argc, char *argv[]) {}
