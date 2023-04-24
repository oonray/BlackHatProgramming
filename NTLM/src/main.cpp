#include <curl/curl.h>
#include <curl/easy.h>
#include <iostream>
#include <string>
#include <thread>
#include <unistd.h>
#include <utility>
#include <vector>

std::string help =
    "help:\n\t-h\thelp\n\t-w\tuserlist\n\t-p\tpassword\n\t-u\turl";

std::vector<std::thread *> *threads;
std::vector<std::string> *creds;

std::string url;
std::string wordlist;
std::string pass;

void Check(std::string user) {
  CURL *h = curl_easy_init();
  curl_easy_setopt(h, CURLOPT_URL, url.c_str());
}

int main(int argc, char *argv[]) {
  threads = new std::vector<std::thread *>;
  creds = new std::vector<std::string>;

  for (;;) {
    switch (getopt(argc, argv, "w:p:u:ht")) {
    case 'w':
      wordlist = optarg;
      continue;
    case 'p':
      pass = optarg;
      continue;
    case 'u':
      url = optarg;
      continue;
    case '?':
    case 'h':
    default:
      std::cout << help << '\n';
      break;
    case -1:
      break;
    }
    break;
  }
  return 0;
}
