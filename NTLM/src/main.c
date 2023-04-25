#include <bstring/bstrlib.h>
#include <ca_dbg.h>
#include <ca_fileio.h>
#include <ca_vector.h>

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
  // ca_io_stream *userlist = ca_io_stream_new_file(arg->user_file, O_RDONLY,
  // 0); ca_io_stream_io_read(userlist); bstring users =
  // ca_io_stream_buff_read(userlist);

  int res = test_username(bfromcstr("admin"), arg);
  log_info("STATUS: %d", res);

  return 0;
error:
  args_usage();
  return 1;
}
