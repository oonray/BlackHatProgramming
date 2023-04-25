#include "args.h"

Args *args_create() {
  Args *args = calloc(sizeof(Args), 1);
  check(args != NULL, "could not create args");
  args->threads = 5;
  return args;
error:
  return NULL;
}

int args_usage() {
  printf("Usage:\n\t-u\tuserlist\n\t-U\turl\n\t-p\tpassword\n\t-"
         "t\thread\topional\tdefault 5\n\t-f\tfqdn\n\r");
  return 0;
}

int args_parse(Args *a, int argc, char *argv[]) {
  int ch;
  while ((ch = getopt(argc, argv, "U:u:p:t:f:h")) != -1) {
    switch (ch) {
    case 'u':
      a->user_file = bfromcstr(optarg);
      break;
    case 'p':
      a->password = bfromcstr(optarg);
      break;
    case 'U':
      a->url = bfromcstr(optarg);
      break;
    case 't':
      a->threads = atoi(optarg);
      break;
    case 'f':
      a->fqdn = bfromcstr(optarg);
      break;
    case 'h':
    case '?':
    default:
      return 1;
    }
  }
  return 0;
}
