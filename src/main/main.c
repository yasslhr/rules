#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include "rules.h"

#include "rules.inc"

/**
*@brief Forward Chaining system
*/
int main (int argc,char **argv){
   
    
// test output :
    char* result = get_output();
    
// test write in output.txt :
    write_file(result);
    
    printf("Rules have been successfully written in your output file ! \n");

    return EXIT_SUCCESS;
	
}
