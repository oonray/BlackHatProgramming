#include <iostream>
#include <string>
#include <thread>
#include <vector>

#include <caaa/argparse.h>
#include <curl/curl.h>

std::vector<std::thread *> *threads;
std::vector<std::string *> *user;

std::vector<std::string *> *pass;

int main(int argc, char *argv[]) {
  threads = new std::vector<std::thread *>;
  return 0;
}
