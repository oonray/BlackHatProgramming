#include <munit/munit.h>
#include <request.h>

static MunitResult ntml_test_worker(const MunitParameter params[],
                                    void *fixture) {
  log_info("test started");
  return MUNIT_OK;
error:
  return MUNIT_ERROR;
}

MunitTest tests[] = {{
                         "ntml-test-worker",     /* name */
                         ntml_test_worker,       /* test */
                         NULL,                   /* setup */
                         NULL,                   /* tear_down */
                         MUNIT_TEST_OPTION_NONE, /* options */
                         NULL                    /* parameters */
                     },
                     /* Mark the end of the array with an entry where the test
                      * function is NULL */
                     {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}};

static const MunitSuite suite = {
    "ntml tests",           /* name */
    tests,                  /* tests */
    NULL,                   /* suites */
    1,                      /* iterations */
    MUNIT_SUITE_OPTION_NONE /* options */
};

int main(int argc, char *argv[]) {
  return munit_suite_main(&suite, NULL, argc, argv);
}
