#include "request.h"
#include <ca_vector.h>
#include <curl/curl.h>
#include <curl/easy.h>
#include <pthread.h>

void *test_username(void *arg) {
  Param *p = (Param *)arg;
  CURL *c = curl_easy_init();
  curl_easy_setopt(c, CURLOPT_URL, bdata(p->a->url));
  curl_easy_setopt(c, CURLOPT_HTTPAUTH, CURLAUTH_NTLM); // use ntml
  curl_easy_setopt(c, CURLOPT_FOLLOWLOCATION, 1L);
  curl_easy_setopt(c, CURLOPT_USERNAME,
                   bdata(bformat("%s\\%s", p->a->fqdn, p->username)));
  curl_easy_setopt(c, CURLOPT_PASSWORD, bdata(p->a->password));
  int stat = curl_easy_perform(c);
  int res;
  curl_easy_getinfo(c, CURLINFO_HTTP_CODE, &res);
  if (res == 200) {
    int open = ca_io_stream_pipe_open(p->p, CA_INN);
    if (open != -1) {
      pthread_mutex_lock(p->m);
      ca_io_stream_buff_write_pipe(p->p, CA_INN, p->username);
      ca_io_stream_io_write_pipe(p->p, CA_INN);
      pthread_mutex_unlock(p->m);
    }
  }
  curl_easy_cleanup(c);
  return NULL;
}

void *valid_user(void *arg) {
  check(arg != NULL, "no arg provided");
  UserParam *v = (UserParam *)arg;

  int open = ca_io_stream_pipe_open(v->p, CA_OUT);
  while (open != -1) {
    bstring out = NULL;
    if (ca_io_stream_io_read_pipe(v->p, CA_OUT) > 0) {
      out = ca_io_stream_buff_read_pipe(v->p, CA_OUT);
    }

    while (bstrcmp(out, bfromcstr("%&DONE!")) != 0) {
      open = ca_io_stream_pipe_open(v->p, CA_OUT);
      if (open == -1) {
        return NULL;
      }
      if (out != NULL) {
        ca_vector_push(v->v, out);
      }
      if (ca_io_stream_io_read_pipe(v->p, CA_OUT) > 0) {
        out = ca_io_stream_buff_read_pipe(v->p, CA_OUT);
      }
    }
  }
  log_info("consumer done");
  return arg;
error:
  return NULL;
}

int print_user(void *data) {
  log_info("Valid user:%s\t", bdata((bstring)data));
  return 0;
}
