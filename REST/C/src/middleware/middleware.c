#include "middleware.h"
#include <caaa/vector.h>

// Creates a empty chain.
mc_MiddleWareChain *mc_MiddleWareChain_New() {
  mc_MiddleWareChain *chain = calloc(1, sizeof(mc_MiddleWareChain));
  check(chain != NULL, "Could not initialize chain");
  chain->handlers = Vector_New(sizeof(mc_handler), 0);
  check(chain->handlers != NULL,
        "Could not initialize chain vector of handlers");

  return chain;
error:
  return NULL;
}

// Uses mc_middleare_chain new and adds a chain.
mc_MiddleWareChain *mc_MiddleWareChain_New_Args(mc_handler *handlers,
                                                int handlers_lengt) {
  check(handlers != NULL, "Handlers is null");
  check(handlers_lengt > 0, "got handlers but length is 0");

  mc_MiddleWareChain *chain = calloc(1, sizeof(mc_MiddleWareChain));
  check(chain != NULL, "Could not initialize chain");

  chain->handlers =
      Vector_New_Data(sizeof(mc_handler), 0, (void **)handlers, handlers_lengt);
error:
  return NULL;
}

void mc_MiddleWareChain_Run(mc_MiddleWareChain *ch, mc_final_handler h,
                            struct mg_connection *c,
                            struct mg_http_message *data) {
  check(ch != NULL, "middleware chain is null.");
  check(h != NULL, "findal handler is null.");
  check(c != NULL, "mg_connection is null.");
  check(data != NULL, "mg_http_message is null.");

  for (int i = 0; i < ch->handlers->end; i++) {
    ((mc_handler)ch->handlers->contents[i])(c, data);
  }
  h(c, data);
error:
  return;
}
