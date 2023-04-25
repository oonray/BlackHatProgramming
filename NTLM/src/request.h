#ifndef REQUEST_H_
#define REQUEST_H_

#include "args.h"
#include <curl/curl.h>
#include <curl/easy.h>

typedef struct Param {
  bstring username;
  Args *a;
} Param;

void *test_username(void *arg);

#endif // REQUEST_H_
