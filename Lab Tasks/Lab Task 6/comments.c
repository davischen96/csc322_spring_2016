#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 
#define MAXCOMMENTS 10000 
#define MAXCOMSIZE 10000 
 
void printComment (char * comment, int n) { 
	int i = 0;        
	printf("%d:\t", n);  
        while (*(comment + i) != '\0') { 
                printf("%c", *(comment + i++)); 
        } 
	printf("\n"); 
} 
 
typedef enum { false, true } bool;
int main (int argc, char* argv[]) {
	FILE *fp1; 
	fp1 = fopen (argv[1], "r");
        bool inString = false, inComment = false, singleLineComment = false; 
        char * comments[MAXCOMMENTS]; 
	char tp[MAXCOMSIZE], input, last; 
	int numberOfComments = 0, i = 0, tpIndex = 0; 
 
	while ((input = fgetc(fp1)) != EOF) { 
		if (inComment) { 
                	tp[tpIndex++] = input; 

			if ((input == '\n' && singleLineComment) || (last == '*' && input == '/')) { 
				tp[tpIndex] = '\0'; 
				singleLineComment = inComment = false; 
				comments[numberOfComments] = malloc(sizeof(char) * tpIndex); 
                                strcpy(comments[numberOfComments], tp); 
				numberOfComments++; 
				tpIndex = 0; 
                        } 

                } else { 
			if ((input == '/' || input == '*') && !inString && last == '/' /*|| last == '*' */) { 
			singleLineComment = input == '/'; 
			inComment = true; 
			tp[0] = '/';
			tp[1] = input;
			tpIndex = 2;
		} else if (last != '\\' && input == '\"') {
			inString = !inString;
                        }
		} 
		last = input;
        }

	printf ("Total number of comments: %d\n", numberOfComments);
        printf("Comments:\n");
        for (i = 0; i < numberOfComments; i++) {
                printComment(comments[i], i + 1);
        }
        return (EXIT_SUCCESS);
}
             

