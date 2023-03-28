#include <iostream>
#include <screen.h>
#include <string>

int main(int argc, char *argv[]) {
  Screen *s = new Screen();
  getchar();
  delete s;
}
