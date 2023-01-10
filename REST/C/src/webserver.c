#include "webserver.h"

void event(struct mg_connection *c, int ev, void *ev_data,
                  void *fn_data) {
  if (ev == MG_EV_HTTP_MSG) {
    struct mg_http_message *msg = (struct mg_http_message *)ev_data;
    if (mg_http_match_uri(msg, bdata(&api_hello))) {
      handle_hello(c);
      return;
    }

   handle_default(c, msg);
   return;
  }
}

void handle_hello(struct mg_connection *c) {
  mg_http_reply(c, 200, "", "{%Q:%d}\n", "status", 1);
}

void handle_default(struct mg_connection *c, struct mg_http_message *data) {
  struct mg_http_serve_opts opts = {.root_dir = "."};
  mg_http_serve_dir(c, data, &opts);
}
