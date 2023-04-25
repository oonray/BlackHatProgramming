#ifndef ARGS_H_
#define ARGS_H_

#include <bstring/bstrlib.h>
#include <ca_dbg.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <unistd.h>

typedef struct Args {
  int threads;
  bstring url;
  bstring user_file;
  bstring password;
} Args;

Args *args_create();
int args_usage();
int args_parse(Args *a, int argc, char *argv[]);

#endif // ARGS_H_
