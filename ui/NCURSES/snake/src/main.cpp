#include <iostream>
#include <screen.h>
#include <string>
#include <thread>

int key = 0;

int main(int argc, char *argv[]) {
  Screen *s = new Screen();
  std::thread Draw_Loop_T(&Screen::Draw_Loop, s);
  s->Key_Loop();
  Draw_Loop_T.join();
  delete s;
}
