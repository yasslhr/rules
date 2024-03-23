/**
 * @file test-init-finish.c
 *
 */

#include <stdlib.h>

#ifdef NDEBUG
#undef NDEBUG
#endif
#include <assert.h>

#include <rules/r_rules.h>

int main(void) {
  assert(rules_init());
  assert(rules_init());
  assert(rules_init());
  { /* some code */ }
  assert(rules_finish());
  assert(rules_finish());
  assert(rules_finish());
  assert(!rules_finish());
  return EXIT_SUCCESS;
}

