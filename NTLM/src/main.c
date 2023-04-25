#include <bstring/bstrlib.h>
#include <ca_dbg.h>
#include <ca_fileio.h>
#include <ca_vector.h>
#include <pthread.h>

#include "args.h"
#include "request.h"

int main(int argc, char *argv[]) {
  Args *arg = args_create();

  check(arg != NULL, "could not create args");
  check(args_parse(arg, argc, argv) == 0, "");
  check(arg->password != NULL, "password is required");
  check(arg->url != NULL, "url is required");
  check(arg->user_file != NULL, "userlist is required");
  check(arg->fqdn != NULL, "fqdn is required");

  // arguments parsed
  ca_io_stream *userlist = ca_io_stream_new_file(arg->user_file, O_RDONLY, 0);
  check(userlist != NULL, "could not open file %s", bdata(arg->user_file));
  check(ca_io_stream_io_read(userlist) != 0, "could not reld file %s",
        bdata(arg->user_file));

  bstring users = ca_io_stream_buff_read(userlist);
  check(users != NULL, "could not read file %s", bdata(arg->user_file));

  struct bstrList *users_s = bsplit(users, '\n');
  check(users_s->qty > 0, "could not split wordlist");
  log_info("using %d usernames", users_s->qty);

  pthread_t **threads = calloc(arg->threads, sizeof(pthread_t));
  check(threads != NULL, "could not allocate threads");
  int counter = 0;
  while (counter < users_s->qty) {
    // for (int i = 0; i < arg->threads; i++) {
    log_info("trying %s", bdata(users_s->entry[counter]));
    Param *P = &(Param){
        .username = users_s->entry[counter],
        .a = arg,
    };

    pthread_t t;
    pthread_create(&t, NULL, &test_username, P);
    pthread_join(t, NULL);
    //}

    // for (int i = 0; i < arg->threads; i++) {
    // pthread_join(*threads[i], NULL);
    //}
    counter++;
  }
  free(threads);

  return 0;
error:
  args_usage();
  if (threads)
    free(threads);
  return 1;
}
