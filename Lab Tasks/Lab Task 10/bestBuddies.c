#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[128];
typedef struct node {
	String name;
	struct node * next;
	struct node * friend;
} LinkedNode;


int addName (LinkedNode * head, LinkedNode * newNode) {
	//newNode->name = (char*)malloc(sizeof(newNode->name));

	printf("Enter name : ");
	scanf("%s", newNode->name);
        //printf("name1: %s\n", newNode->name);
	//fgets(newNode->name,sizeof(newNode->name),stdin);
	//printf("%s", newNode->name);
	//newNode->name = temp;
	if (!strcmp(newNode->name, "-1")) {
        //if ((newNode->name)[0] == '\n'){
               // printf("name: %s\n", newNode->name);
	   	free(newNode);
        	return 0;
    	} else {
        	newNode->next = head->next;
        	head->next = newNode;
        	return -1;
	}
}

LinkedNode * findFriend (LinkedNode * head, String name) {
        LinkedNode * dummy = head;

        while (dummy->next != NULL) {
                dummy = dummy->next;
                if (!strcmp(name, dummy->name)) {
			return dummy;
        	}
	}
	return NULL;
}


void addFriend (LinkedNode * head) {
	String friendName;
	LinkedNode * friend = NULL;
	LinkedNode * dummy = head;

	while (dummy->next != NULL) {
		dummy = dummy->next;

		for (;;) {
			printf("Enter best friend for %s : ", dummy->name);
            		scanf("%s", friendName);

			if ((friend = (findFriend(head, friendName))) == NULL) {
                		printf("Friend doesn't exist.\n");
            		} else {
                		break;
            		}
        	}
		dummy->friend = friend;
    	}
}

void printNodes (LinkedNode * head) {
    	LinkedNode * dummy;

	while (head->next != NULL) {
        	dummy = head->next;
        	free(head);
        	head = dummy;
        	printf("The best friend of %s is %s\n", head->name, head->friend->name);
    	}
	free(head);
}


int main (void) {
	LinkedNode * head = (LinkedNode*)malloc(sizeof(LinkedNode));

	head->next = NULL;

	printf("Type -1 to stop adding names.\n");
	while(addName(head, malloc(sizeof(LinkedNode))));

	if (head->next == NULL) {
		printf("No Name Entered\n");
        	free(head);
        	return -1;		
	}

	addFriend(head);

	printNodes(head);

	return(EXIT_SUCCESS);
}

