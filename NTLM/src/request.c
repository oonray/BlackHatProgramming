#include "request.h"
#include <curl/curl.h>
#include <curl/easy.h>

int test_username(bstring username, Args *a) {
  CURL *c = curl_easy_init();
  curl_easy_setopt(c, CURLOPT_URL, bdata(a->url));
  curl_easy_setopt(c, CURLOPT_HTTPAUTH, CURLAUTH_NTLM); // use ntml
  curl_easy_setopt(c, CURLOPT_FOLLOWLOCATION, 1L);
  curl_easy_setopt(c, CURLOPT_USERNAME,
                   bdata(bformat("%s\\%s", a->fqdn, username)));
  curl_easy_setopt(c, CURLOPT_PASSWORD, bdata(a->password));
  int stat = curl_easy_perform(c);
  int res;
  curl_easy_getinfo(c, CURLINFO_HTTP_CODE, &res);
  curl_easy_cleanup(c);
  return res;
}
