#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 10000


void printComments (char * word, int n) {
	printf("#%d:\n", n);
	int i = 0;
	while (*(word + i) != '\0') {
		printf("%c", *(word + i++));
	}
	printf("\n");
}

int main(int argc, char* argv[]) {

FILE *fp1;
char input, lastChar;

typedef enum {false, true} bool;
fp1 = fopen (argv[1], "r");
char * comments[MAXLINES];
int numberOfComments = 0, i = 0;
bool inString = false, inComment = false, singleLineComment = false;
char temp[MAXLINES];
int tempIndex = 0;


while ((input = fgetc(fp1)) != EOF) {
	

	if(inComment) {
		temp[tempIndex++] = input;
		if ((input == '\n' && singleLineComment) || (lastChar == '*' && input == '/')){
			temp[tempIndex] = '\0';
				singleLineComment = inComment = false;
				comments[numberOfComments] = malloc(sizeof(char) * tempIndex);
				strcpy(comments[numberOfComments], temp);
				++numberOfComments;
				tempIndex = 0;
		}	
		} else {
			if (!inString && lastChar == '/' && (input == '/' || input == '*')) {
				singleLineComment = input == '/';
				inComment = true;
				temp[0] = '/';
				temp[1] = input;
				tempIndex = 2;
			} else if (input == '\"' && lastChar != '\\') {
				inString = !inString; 
			}
			}		
				lastChar = input;
			}
 

printf ("Total no of comment lines: %d\n", numberOfComments);
printf("Comments:\n");
for (i = 0; i < numberOfComments; i++) {
	printComments(comments[i], i + 1);
}
return(EXIT_SUCCESS);
}

