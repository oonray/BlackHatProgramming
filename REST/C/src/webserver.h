#ifndef WEBSERVER_H_
#define WEBSERVER_H_

#include "mongoose.h"
#include <caaa/bstrlib.h>
#include <caaa/dbg.h>

static struct tagbstring api_hello = bsStatic("/api/hello");
static struct tagbstring uri = bsStatic("http://0.0.0.0:8000");

void handle_hello(struct mg_connection *c);
void handle_default(struct mg_connection *c, struct mg_http_message *hm);
void event(struct mg_connection *c, int ev, void *ev_data, void *fn_data);

#endif // WEBSERVER_H_
