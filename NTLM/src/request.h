#ifndef REQUEST_H_
#define REQUEST_H_

#include "args.h"
#include <ca_fileio.h>
#include <ca_vector.h>
#include <curl/curl.h>
#include <curl/easy.h>
#include <pthread.h>

typedef struct worker {
  Args *a;
  ca_io_stream_pipe **coms;
  pthread_mutex_t **mt;
  ca_vector *v;
} worker;

void *test_worker(void *arg);
int test_username(bstring username, bstring password, bstring url, bstring fqdn,
                  bstring proxy);
void *valid_user(void *arg);
int print_user(void *data);

#endif // REQUEST_H_
