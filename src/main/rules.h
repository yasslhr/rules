#ifndef RULES_H_
#define RULES_H_

#include <stdbool.h>
#include <stdio.h>
//!Structure of our rules



/**
 * @brief Defining the structure Rule
 * 
 */
typedef struct _Rule Rule;


/**
 * @brief Memory allocation
 * 
 */
extern void *(*rules_malloc)(size_t size);

/**
 * @brief Memory reallocation
 * 
 */
extern void *(*rules_realloc)(void *ptr, size_t size);

/**
 * @brief Memory deallocation
 * 
 */
extern void (*rules_free)(void *ptr);


/**
 * @brief Initialization of the Rules
 * 
 * @return true -->  It returns true when the Rules is initialized.
 * @return false -->  It doesn't return false.
 */
extern bool rules_init(void);


/**
 * @brief Finalization of the Rules
 * 
 * @return true --> It returns true when there has been has much finalization as inisialization.
 * @return false --> It returns false when there is no more Rules initialized.
 */
extern bool rules_finish(void);


/**
 * @brief Destruction of a Rule param rule --> It corresponds to the Rule we want to destroy.
 * 
 * @param rule --> It corresponds to the Rule we want to destroy.
 */
 
extern void rule_destroy(Rule *rule);


/**
 *@brief this function get the size of the array from rules
 *@return she return the number of rules
 */
extern int get_tab_size_from_rules();


/**
* @brief this funtion open the file : facts.txt  
*  @return the function return all facts 
*/
extern char** get_file_facts();



/**
*@brief this function fill the file rules.txt
*/
extern Rule* rules_fill();


/**
*@brief this function get the size on the facts array
*@return this funtion return the number of facts in the array
*/
extern int get_tab_size_from_facts();


/**
*@brief compares the fact with every rules in our rules's array
*@return char * results
*/
extern char * get_output();

/**
*@brief Writes "results" in the output file
*
*/
extern void write_file(char* results);
#endif /* RULES_H_*/    

