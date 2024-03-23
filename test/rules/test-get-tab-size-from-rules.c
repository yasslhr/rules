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
   assert(get_tab_size_from_rules() == 0);
  return EXIT_SUCCESS;
  }
  rules_finish();
}
