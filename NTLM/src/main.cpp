#include <curl/curl.h>
#include <curl/easy.h>
#include <iostream>
#include <string>
#include <thread>
#include <unistd.h>
#include <utility>
#include <vector>

std::vector<std::thread *> *threads;
std::vector<std::pair<std::string, std::string> *> creds;

void Check(std::string user, std::string pass) { CURL *h = curl_easy_init(); }

int main(int argc, char *argv[]) {
  threads = new std::vector<std::thread *>;

  for (;;) {
    switch (getopt(argc, argv, "w:p:u:ht")) {
    case 'w':
      printf("switch 'w' specified\n");
      continue;
    case 'p':
      printf("switch 'p' specified\n");
      continue;
    case 'u':
      printf("switch 'u' specified\n");
      continue;
    case '?':
    case 'h':
    default:
      printf("Help/Usage Example\n");
      break;

    case -1:
      break;
    }

    break;
  }
  return 0;
}
