#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include "rules.h"

#include "rules.inc"



//! return the array size  (number of rules)
int get_tab_size_from_rules(){
    // ouverture du fichier rules.txt :
    FILE * fp = NULL;
    fp = fopen("example.rules.txt", "r");
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

int get_tab_size_from_facts(){
    //! open the file : example.facts.txt
    FILE * fp = NULL;
    fp = fopen("example.facts.txt", "r");
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

Rule* fill_rules(){
    //! opening the files example.rules.txt :
    FILE * fp = NULL;
    fp = fopen("example.rules.txt", "r");
    if (fp == NULL){    //! if the file couldn't be opened :
        printf("Erreur file open\n");
    }else{            //! if the file is open without errors
        //! recuperation of rules :
        Rule *rules = malloc(sizeof(Rule)*get_tab_size_from_rules());
        if(!rules){
            return NULL;
        }
        char str[10];
        int nb_rule = 0;
        int line_type = 0; //! 0-> premisse , 1-> result -> 2-> space without rules
        Rule r;

        while (fgets(str, 10, fp) != NULL){ //! insertion of rules in the array
            char *p;
            size_t len = strlen(str);
            if (len > 0 && str[len-1] == '\n') {
                str[--len] = '\0';
            }
            if (line_type == 0){
                strcpy(r.fact, str);
            }
            if (line_type == 1){
                strcpy(r.result, str);
                rules[nb_rule] = r;
                nb_rule += 1;
            }
            line_type += 1;
            if (line_type == 3){line_type = 0;}
        }
        fclose(fp);
        return rules;
    }
    printf("Getting NULL");
    return NULL;
}
//! retrieve example.facts.txt
char** get_file_facts(){
    //! opening the files : example.facts.txt :
    FILE * fp = NULL;
    fp = fopen("example.facts.txt", "r");
    if (fp == NULL){    //! if the file couldn't be opened :
        printf("Issue while opening the file\n");
    }else{            //! if the file is open without errors
        //! recuperation of "facts" :
        char str[10];
        char **facts = malloc(sizeof (char) * get_tab_size_from_facts()*10);

        unsigned int nb_facts= 0;
        while (fgets(str, 10, fp) != NULL) {
            facts[nb_facts] = malloc(sizeof (char));

            //! removing "\n"
            size_t len = strlen(str);
            if (len > 0 && str[len-1] == '\n') {
                str[--len] = '\0';
            }
            strcpy(facts[nb_facts],str);

            nb_facts += 1;
        }
        fclose(fp);
        return facts;
    }
    return NULL;
}

void write_file(char* results) {
    FILE* fp = NULL;
    
    fp = fopen("example.output.txt","w");
    
    if (fp != NULL){
    	fputs(results, fp);
    	fclose(fp);
    }
}

char * get_output(){
	char* nb_facts = *get_file_facts();
	int continuee = 0;
	char *result = malloc(sizeof(char)*10);
	Rule* tab_rule = fill_rules(); 
	
	strcpy(result, nb_facts);	

	while(continuee == 0){
		int i =0;
		char str[10];
		strcpy(str, nb_facts);
		int size = 10;
		for(i=0; i< get_tab_size_from_rules();i++){

			if(strcmp(str,tab_rule[i].fact)==0){
				strcpy(str, tab_rule[i].result);
				size = size+10;
				result = realloc(result, size);
				char espace[10] = " ";
				strcat(result, espace);
				strcat(result, str);	
			}
			
		}
		continuee = 1;
	}

	return result;
}


