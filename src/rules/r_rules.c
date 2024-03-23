#include <assert.h>

#include <stdbool.h>

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include "./r_rules.h"

#include "./r_rules.inc"

void *(*rules_malloc)(size_t size) = malloc;
void *(*rules_realloc)(void *ptr, size_t size) = realloc;
void (*rules_free)(void *ptr) = free;


static int counter = 0;

/**
 * @brief
 *
 * @return true
 * @return false
 */
bool rules_init(void) {
  if (!counter++) {
    assert(printf("Rules initialised\n"));
  }
  return true;
}

/**
 * @brief
 *
 * @return true
 * @return false
 */
bool rules_finish(void) {
  if (counter) {
    if (!--counter) {
      assert(printf("Rules finished\n"));
    }
    return true;
  } else {
    return false;
  }
}

/**
 * @brief
 *
 * @param result,size,start
 * @return Rule*
 */

Rule *rule_create(const char* result, const char* start) {
  Rule* rule = rules_malloc(sizeof *rule);
  if (rule) {
    strcpy(rule->result,result);
    strcpy(rule->fact,start);
    return rule;
  } else {
    return NULL;
  }
}


/**
 * @brief
 *
 * @param rule
 */

void rule_destroy(Rule *rule) {
  rules_free(rule->result);
  rules_free(rule);
}

/**
 * @brief
 *
 * @param rule
 * @return unsigned int
 */
const char *rule_get_result(const Rule *rule) {
  return rule->result;
}

/**
*@brief Writes "results" in the output file
*
*/
char* write_file(char* results) {
    FILE* fp = NULL;
    
    fp = tmpfile();
    
    if (fp != NULL){
    	fputs(results, fp);
    	fclose(fp);
    	return results;
    }
    return NULL;
}

/**
*@brief this function get the size on the facts array
*@return this funtion return the number of facts in the array
*/
int get_tab_size_from_facts(){
    //! open the file : example.facts.txt
    FILE * fp = NULL;
    fp = fopen("test.txt","a+");
    if (fp == NULL){	//! if the file couldn't be opened :
        printf("Erreur fp\n");
    }else{			//! if the file is open without errors
        char str[10];
        int nb_facts= 0;
        while (fgets(str, 10, fp) != NULL){ //! number of facts in the array
            nb_facts += 1;
        }
        fclose(fp);
        
        return nb_facts;
    }
}


//! return the array size  (number of rules)
/**
 *@brief this function get the size of the array from rules
 *@return she return the number of rules
 */
int get_tab_size_from_rules(){
    // ouverture du fichier rules.txt :
    FILE * fp = NULL;
    fp = fopen("test.txt", "a+");
    if (fp == NULL){	//! if the file couldn't be opened :
        printf("Erreur file open\n");
    }else{			//! if the file is open without errors :
        char str[10];
        int nb_rule = 0;
        int line_type = 0; //! 0-> premise , 1-> result -> 2-> space without rules

        while (fgets(str, 10, fp) != NULL){ //! number of rules in the array
            if (line_type == 0){
                nb_rule += 1;
            }
            line_type += 1;
            if (line_type == 3){
            	line_type = 0;
            }
        }
        fclose(fp);
        return nb_rule;
    }
}
