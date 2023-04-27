#include "request.h"
#include <ca_vector.h>
#include <curl/curl.h>
#include <curl/easy.h>
#include <pthread.h>

static size_t write_callback(char *ptr, size_t size, size_t nmemb,
                             void *userdata) {
  return size * nmemb;
}

void *test_username(void *arg) {
  Param *p = (Param *)arg;
  CURL *c = curl_easy_init();
  curl_easy_setopt(c, CURLOPT_URL, bdata(p->a->url));
  curl_easy_setopt(c, CURLOPT_HTTPAUTH, CURLAUTH_NTLM); // use ntml
  curl_easy_setopt(c, CURLOPT_FOLLOWLOCATION, 1L);
  curl_easy_setopt(c, CURLOPT_USERNAME,
                   bdata(bformat("%s\\%s", p->a->fqdn, p->username)));
  curl_easy_setopt(c, CURLOPT_NOPROGRESS, 1);
  curl_easy_setopt(c, CURLOPT_VERBOSE, 0);
  curl_easy_setopt(c, CURLOPT_WRITEFUNCTION, write_callback);
  curl_easy_setopt(c, CURLOPT_WRITEDATA, NULL);
  curl_easy_setopt(c, CURLOPT_PASSWORD, bdata(p->a->password));

  if (p->a->proxy != NULL) {
    curl_easy_setopt(c, CURLOPT_PROXY, bdata(p->a->proxy));
  }

  curl_easy_perform(c);
  long code;
  curl_easy_getinfo(c, CURLINFO_HTTP_CODE, &code);
  if (code == 200) {
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

    while (open != -1) {
      if (out != NULL) {
        ca_vector_push(v->v, out);
      }
      if (ca_io_stream_io_read_pipe(v->p, CA_OUT) > 0) {
        out = ca_io_stream_buff_read_pipe(v->p, CA_OUT);
      }
      open = ca_io_stream_pipe_open(v->p, CA_OUT);
    }
  }
  return arg;
error:
  return NULL;
}

int print_user(void *data) {
  log_info("Valid user:%s\t", bdata((bstring)data));
  return 0;
}
