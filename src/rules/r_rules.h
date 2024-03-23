#ifndef R_RULES_H_
#define R_RULES_H_

#include <stdbool.h>

#include <stdio.h>

//!Structure of our rules



//! Defining the structure Rule
/**
 * @brief Defining the structure Rule
 * 
 */
typedef struct _Rule Rule;



//! Memory allocation
/**
 * @brief Memory allocation
 * 
 */
extern void *(*rules_malloc)(size_t size);

//! Memory reallocation
/**
 * @brief Memory reallocation
 * 
 */
extern void *(*rules_realloc)(void *ptr, size_t size);

//! Memory deallocation
/**
 * @brief Memory deallocation
 * 
 */
extern void (*rules_free)(void *ptr);


//! return true -->  It returns true when the Rules is initialized.return false -->  It doesn't return false.
/**
 * @brief Initialization of the Rules
 * 
 * @return true -->  It returns true when the Rules is initialized.
 * @return false -->  It doesn't return false.
 */
extern bool rules_init(void);


//!Finalization of the Rules return true --> It returns true when there has been has much finalization as inisialization. return false --> It returns false when there is no more Rules initialized.
/**
 * @brief Finalization of the Rules
 * 
 * @return true --> It returns true when there has been has much finalization as inisialization.
 * @return false --> It returns false when there is no more Rules initialized.
 */
extern bool rules_finish(void);

//! Creation of a Rule param size --> It corresponds to the memory that allocated to it. return Rule* --> It returns a Rule pointer.
/**
 * @brief Creation of a Rule
 * 
 * @param size --> It corresponds to the memory that allocated to it.
 * @return Rule* --> It returns a Rule pointer.
 */

//extern Rule *rule_create(const unsigned int result, unsigned int*start);

/**
 * @brief Destruction of a Rule param rule --> It corresponds to the Rule we want to destroy.
 * 
 * @param rule --> It corresponds to the Rule we want to destroy.
 */
//extern void rule_destroy(Rule *rule);

//! get result of rule
extern const char *rule_get_result(const Rule *rule);

/**
*@brief Writes "results" in the file
*
*/
extern char* write_file(char* results);

/**
*@brief this function get the size on the facts array
*@return this funtion return the number of facts in the array
*/
extern int get_tab_size_from_facts();
#endif /* R_RULES_H_*/
