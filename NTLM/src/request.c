#include "request.h"
#include <ca_vector.h>
#include <curl/curl.h>
#include <curl/easy.h>
#include <pthread.h>

static size_t write_callback(char *ptr, size_t size, size_t nmemb,
                             void *userdata) {
  return size * nmemb;
}

int test_username(bstring username, bstring password, bstring url, bstring fqdn,
                  bstring proxy) {
  CURL *c = curl_easy_init();
  curl_easy_setopt(c, CURLOPT_URL, bdata(url));
  curl_easy_setopt(c, CURLOPT_HTTPAUTH, CURLAUTH_NTLM); // use ntml
  curl_easy_setopt(c, CURLOPT_FOLLOWLOCATION, 1L);
  curl_easy_setopt(c, CURLOPT_USERNAME,
                   bdata(bformat("%s\\%s", fqdn, username)));
  curl_easy_setopt(c, CURLOPT_NOPROGRESS, 1);
  curl_easy_setopt(c, CURLOPT_VERBOSE, 0);
  curl_easy_setopt(c, CURLOPT_WRITEFUNCTION, write_callback);
  curl_easy_setopt(c, CURLOPT_WRITEDATA, NULL);
  curl_easy_setopt(c, CURLOPT_PASSWORD, bdata(password));

  if (proxy != NULL) {
    curl_easy_setopt(c, CURLOPT_PROXY, bdata(proxy));
  }

  curl_easy_perform(c);
  long code;
  curl_easy_getinfo(c, CURLINFO_HTTP_CODE, &code);
  curl_easy_cleanup(c);
  check(code == 200, "");
  return 0;
error:
  return -1;
}

int print_user(void *data) {
  log_info("Valid user:%s\t", bdata((bstring)data));
  return 0;
}

int pipe_open(worker *a, int num, int io) {
  pthread_mutex_lock(a->mt[num]);
  int open = ca_io_stream_pipe_open(a->coms[num], io);
  pthread_mutex_unlock(a->mt[num]);
  return open;
}

void *test_worker(void *arg) {
  worker *a = (worker *)arg;

  int open_inn = pipe_open(a, CA_INN, CA_OUT);
  int open_out = pipe_open(a, CA_OUT, CA_INN);

  bstring username;
  while (open_inn != -1 && open_out != -1) {
    // wait for data
    pthread_mutex_lock(a->mt[CA_INN]);
    if (ca_io_stream_io_read_pipe(a->coms[CA_INN], CA_OUT) <= 0) {
      pthread_mutex_unlock(a->mt[CA_INN]);
      continue;
    }
    // we have input data
    username = ca_io_stream_buff_read_pipe(a->coms[CA_INN], CA_OUT);
    pthread_mutex_unlock(a->mt[CA_INN]);

    if (test_username(username, a->a->password, a->a->url, a->a->fqdn,
                      a->a->proxy) != 0) {
      continue;
    }

    pthread_mutex_lock(a->mt[CA_OUT]);
    ca_io_stream_buff_write_pipe(a->coms[CA_OUT], CA_OUT, username);
    ca_io_stream_io_write_pipe(a->coms[CA_OUT], CA_OUT);
    pthread_mutex_unlock(a->mt[CA_OUT]);

    open_inn = pipe_open(a, CA_INN, CA_OUT);
    open_out = pipe_open(a, CA_OUT, CA_INN);
  }
  return NULL;
}
