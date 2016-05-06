#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[128];
typedef enum { mammal, insect, bird, fish } Type;
typedef struct {
    Type type;
    double size;
    String name;
} Animal;



Type getType (String type) {
        if (!strcmp(type, "mammal")) {
                return mammal;
        } else if (!strcmp(type, "insect")) {
                return insect;
        } else if (!strcmp(type, "bird")) {
                return bird;
        } else if (!strcmp(type, "fish")) {
                return fish;
        } else {
        printf("Wrong Animal Type.\n");
        exit(1);
        }
}


int enterInfo (Animal * animals) {
	String type;
	printf("Enter animal information (\"exit\" to exit)\n");
	
	printf("What is the name : ");
	scanf("%s", animals->name);
	
	if (!strcmp(animals->name, "exit")) {
        return 0;
    	}	

	printf("What is the size : ");
    	scanf("%lf", &animals->size);

    	printf("What is the type : ");
    	scanf("%s", type);

	animals->type = getType(type);

	return 1;
}



char * getString (Type type) {
	switch(type) {
		case mammal:
			return "mammal";
        	case insect:
			return "insect";
        	case bird:
			return "bird";
        	case fish:
			return "fish";
        	default:
			return "error";
	}
}


void print (Animal ** animals, int size) {
	int i;
	Animal * a;
	printf("The following new species were found:\n");
	for (i = 0; i < size; i++) {
        	a = *(animals + i);
        	printf("%-20s has size %5.2f and is a %s.\n", a->name, a->size, getString(a->type));
    }
}

int main (void) {

        int size = 1;
        int index = -1;
        Animal ** discovered = malloc(sizeof(Animal *));

        while (1) {
                Animal * a = malloc(sizeof(Animal));

                if (a == NULL) {
                        perror("Can't allocate");
                        exit(-1);
                }

                if (++index >= size) {
                        size *= 2;
                        discovered = realloc(discovered, size * sizeof(Animal *));
                        if (*discovered == NULL) {
                                perror("Can't allocate");
                                exit(-1);
                        }
                }

                if (!enterInfo(a)) {
                        break;
                } else {
                        *(discovered + index) = a;
                }
	}

        print(discovered, index);
        return(0);
}
