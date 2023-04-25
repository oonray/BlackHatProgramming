#ifndef REQUEST_H_
#define REQUEST_H_

#include "args.h"
#include <curl/curl.h>
#include <curl/easy.h>

int test_username(bstring username, Args *a);

#endif // REQUEST_H_
