#include "webserver.h"

int main(int argc, char *argv[]) {
  struct mg_mgr mgr;
  mg_mgr_init(&mgr);                              // Init manager
  mg_http_listen(&mgr, bdata(&uri), event, &mgr); // Setup listener
  for (;;)
    mg_mgr_poll(&mgr, 1000); // Event loop
  mg_mgr_free(&mgr);         // Cleanup
  return 0;
}
