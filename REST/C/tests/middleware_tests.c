#include "middleware.h"
#include "munit.h"

MunitResult test_print_all(const MunitParameter params[],
                           void *user_data_or_fixture) {
  check(argparser->args_t != NULL, "Could not create data");
  check(argparser->args_n != NULL, "Could not create data");
  test_add_arg(params, user_data_or_fixture);

  Argparse_Print_Help(argparser);

  return MUNIT_OK;
error:
  return MUNIT_FAIL;
}

int main(int argc, char *argv[]) {
  MunitTest tests[] = {
      {"test_new", test_new, setup, teardown, MUNIT_TEST_OPTION_NONE, NULL},
      {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}};

  MunitSuite suite = {"Munit tests", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE};
  return munit_suite_main(&suite, NULL, 0, NULL);
}
