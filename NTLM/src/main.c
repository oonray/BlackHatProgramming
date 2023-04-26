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

  ca_vector *valid_usernames = ca_vector_new(sizeof(bstring), 0);
  check(valid_usernames != NULL, "could not create valid usernames vector");

  ca_io_stream_pipe *coms = ca_io_stream_new_pipe(0);
  check(coms != NULL, "coud not create coms pipe");

  pthread_mutex_t coms_mt;
  pthread_mutex_init(&coms_mt, NULL);

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

  pthread_t com;
  pthread_create(&com, NULL, &valid_user,
                 (void *)&(UserParam){
                     .v = valid_usernames,
                     .p = coms,
                 });

  pthread_t **threads = calloc(arg->threads, sizeof(pthread_t *));
  check(threads != NULL, "could not allocate threads");

  int counter = 0;
  while (counter < users_s->qty) {
    for (int i = 0; i < arg->threads; i++) {
      threads[i] = calloc(1, sizeof(pthread_t));
      pthread_create(threads[i], NULL, &test_username,
                     (void *)&(Param){
                         .username = users_s->entry[counter],
                         .a = arg,
                         .m = &coms_mt,
                     });
    }

    for (int i = 0; i < arg->threads; i++) {
      pthread_join(*threads[i], NULL);
      free(threads[i]);
    }
    counter++;
  }
  free(threads);

  // close consumer
  pthread_mutex_lock(&coms_mt);
  ca_io_stream_buff_write_pipe(coms, CA_INN, bfromcstr("%&DONE!"));
  ca_io_stream_io_write_pipe(coms, CA_INN);
  pthread_mutex_unlock(&coms_mt);
  pthread_mutex_destroy(&coms_mt);
  ca_io_stream_destroy_pipe(coms);

  // wait for consumer
  pthread_join(com, NULL);
  ca_vector_traverse(valid_usernames, print_user);

  return 0;
error:
  args_usage();
  return 1;
}
