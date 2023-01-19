#ifndef MIDDLEWARE_H_
#define MIDDLEWARE_H_

#include "mongoose.h"
#include <caaa/bstrlib.h>
#include <caaa/dbg.h>

typedef int (*handler)(struct mg_connection *c, struct mg_http_message *data);
// Returns int to handle errors.
// if error we break the chain

typedef struct MiddleWareChain {
  handler *handlers[];
  int handlers_length;
  int order; // reverse recursion or regular recursion
             // Dont knwo why i added this as an option.
  struct mg_connection *c;
  struct mg_http_message *data;
} MiddleWareData;

#endif // MIDDLEWARE_H_
