/**
 * @file test-create-destroy.c
 *
 */

#include <stdlib.h>

#ifdef NDEBUG
#undef NDEBUG
#endif
#include <assert.h>

#include <rules/r_rules.h>

int main(void) {
  { 	char *fact = malloc(sizeof(*fact)*5);
  	char *output = malloc(sizeof(*fact)*5);
	Rule* rule;
	strcpy(fact,"1 2 3");
	strcpy(output,"5 7");
	rule->fact = fact;
	rule->result = output;

	rule_destroy(rule);
  }
  return EXIT_SUCCESS;
}

