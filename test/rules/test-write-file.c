/**
 * @file test-write-file.c
 *
 */

#include <stdlib.h>

#ifdef NDEBUG
#undef NDEBUG
#endif
#include <assert.h>

#include <rules/r_rules.h>

int main(void) {
  rules_init();
  {
  char str[10] = "1 2 3 4";
  assert(write_file(str) == str);
  return EXIT_SUCCESS;
  }
  rules_finish();
}

