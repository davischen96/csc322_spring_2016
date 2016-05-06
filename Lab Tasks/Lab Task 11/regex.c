#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <regex.h>

#define MAX_STR_LEN 128
#define SEPARATORS ".!?"

//typedef char String[MAX_STR_LEN];

int main (void) {
    regex_t creg;
    char input[MAX_STR_LEN], regex[MAX_STR_LEN];
    char *str1, *str2, *token, *subtoken;
    char * saveptr1, *saveptr2;    
    int i, j;

    //char input[] = "Hello my name is Davis! What is your name young Padawan? Nice to meet you too!";
    
    printf("Please enter the string to analyze (max length %d chars): ", MAX_STR_LEN - 1);
    fgets(input, MAX_STR_LEN, stdin);
    input[strlen(input)-1] = '\0';
    
    printf("Please enter the regular expression (max length %d chars): ", MAX_STR_LEN - 1);
    scanf("%s", regex);
    //fgets(regex, MAX_STR_LEN, stdin);
    //regex[strlen(input)-1] = '\0';

    if (regcomp(&creg,regex,REG_EXTENDED) != 0) {
        printf("ERROR: Something wrong in the regular expression\n");
        exit(EXIT_FAILURE);
    }

    printf("Input is: %s\n", input);

    for (i = 1, str1 = input; ; i++, str1 = NULL) {
        token = strtok_r(str1, SEPARATORS, &saveptr1);
        if (token == NULL)
            break;
        printf("Sentence %d: %s\n", i, token);
        
        if (regexec(&creg,token,0,NULL,0) == 0) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
        
        for (str2 = token; ; str2 = NULL) {
            subtoken = strtok_r(str2, " ", &saveptr2);
            if (subtoken == NULL)
                break;
            //printf(" --> %s\n", subtoken);
            j++;
        }
        printf("%d words\n", j);
        j=0;
    }
    regfree(&creg);
    return(EXIT_SUCCESS);
}


