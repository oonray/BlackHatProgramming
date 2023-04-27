#include <bstring/bstrlib.h>
#include <ca_dbg.h>
#include <ca_fileio.h>
#include <ca_vector.h>
#include <pthread.h>
#include <sys/_pthread/_pthread_mutex_t.h>

#include "args.h"
#include "request.h"

int main(int argc, char *argv[]) {
  Args *arg = args_create();

  check(arg != NULL, "could not create args");
  check(args_parse(arg, argc, argv) == 0, "Could not parse args");
  check(arg->password != NULL, "password is required");
  check(arg->url != NULL, "url is required");
  check(arg->user_file != NULL, "userlist is required");
  check(arg->fqdn != NULL, "fqdn is required");

  ca_vector *valid_usernames = ca_vector_new(sizeof(bstring), 5);
  check(valid_usernames != NULL, "could not create valid usernames vector");

  ca_io_stream_pipe *coms[] = {
      [CA_INN] = ca_io_stream_new_pipe(0),
      [CA_OUT] = ca_io_stream_new_pipe(0),
  };

  check(coms[0] != NULL, "coud not create coms pipe");
  check(coms[1] != NULL, "coud not create coms pipe");

  pthread_mutex_t **coms_mt = calloc(2, sizeof(pthread_mutex_t));
  check(coms_mt != NULL, "could not allocate mutex");
  pthread_mutex_init(coms_mt[CA_INN], NULL);
  pthread_mutex_init(coms_mt[CA_OUT], NULL);

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

  pthread_t **threads = calloc(arg->threads, sizeof(pthread_t *));
  check(threads != NULL, "could not allocate threads");

  for (int i = 0; i < arg->threads; i++) {
    threads[i] = calloc(1, sizeof(pthread_t));
    pthread_create(threads[i], NULL, &test_worker,
                   (void *)&(worker){
                       .a = arg,
                       .mt = (pthread_mutex_t **)&coms_mt,
                       .coms = (ca_io_stream_pipe **)&coms,
                   });
  }

  for (int i = 0; i < users_s->qty; i++) {
    ca_io_stream_buff_write_pipe(coms[CA_INN], CA_INN, users_s->entry[i]);
    ca_io_stream_io_write_pipe(coms[CA_INN], CA_INN);
  }

  for (int i = 0; i < arg->threads; i++) {
    pthread_join(*threads[i], NULL);
    free(threads[i]);
  }

  free(threads);
  log_info("threads done");

  pthread_mutex_destroy(coms_mt[CA_INN]);
  pthread_mutex_destroy(coms_mt[CA_OUT]);
  ca_io_stream_destroy_pipe(coms[CA_INN]);
  ca_io_stream_destroy_pipe(coms[CA_OUT]);

  log_info("Found Usernames");
  ca_vector_traverse(valid_usernames, print_user);

  return 0;
error:
  args_usage();
  return 1;
}
