#include "webserver.h"

static void fn(struct mg_connection *c, int ev, void *ev_data, void *fn_data) {
  struct mg_http_serve_opts opts = {.root_dir = "."};   // Serve local dir
  if (ev == MG_EV_HTTP_MSG) mg_http_serve_dir(c, (struct mg_http_message *)ev_data, &opts);
}

int main(int argc,char *argv[]) {
  struct mg_mgr mgr;
  mg_mgr_init(&mgr);
  mg_http_listen(&mgr, "0.0.0.0:8000", fn, NULL);     // Create listening connection
  for (;;) mg_mgr_poll(&mgr, 1000);                   // Block forever
}
