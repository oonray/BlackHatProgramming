#ifndef MIDDLEWARE_H_
#define MIDDLEWARE_H_

#include "mongoose.h"
#include <caaa/bstrlib.h>
#include <caaa/dbg.h>
#include <caaa/vector.h>

typedef void (*mc_final_handler)(struct mg_connection *c,
                                 struct mg_http_message *data);
typedef int (*mc_handler)(struct mg_connection *c,
                          struct mg_http_message *data);
// Returns int to handle errors.
// if error we break the chain

typedef struct mc_MiddleWareChain {
  Vector *handlers;
} mc_MiddleWareChain;

mc_MiddleWareChain *mc_MiddleWareChain_New();
mc_MiddleWareChain *mc_MiddleWareChain_New_Args(mc_handler *handlers,
                                                int handlers_lengt);

int mc_MiddleWareChain_Add_Handler(mc_MiddleWareChain *mc, mc_handler handler);

void mc_MiddleWareChain_Run(mc_MiddleWareChain *ch, mc_final_handler h,
                            struct mg_connection *c,
                            struct mg_http_message *data);

#endif // MIDDLEWARE_H_
