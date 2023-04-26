#ifndef REQUEST_H_
#define REQUEST_H_

#include "args.h"
#include <ca_fileio.h>
#include <ca_vector.h>
#include <curl/curl.h>
#include <curl/easy.h>
#include <sys/_pthread/_pthread_mutex_t.h>

typedef struct Param {
  bstring username;
  Args *a;
  ca_io_stream_pipe *p;
  pthread_mutex_t *m;
} Param;

typedef struct UserParam {
  ca_vector *v;
  ca_io_stream_pipe *p;
  int running;
} UserParam;

void *test_username(void *arg);
void *valid_user(void *arg);
int print_user(void *data);

#endif // REQUEST_H_
