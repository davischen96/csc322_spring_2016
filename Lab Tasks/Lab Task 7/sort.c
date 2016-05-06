//sort data with pointers

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef int* IntPointer;
typedef int ArrayOfFiveInts[SIZE];
typedef IntPointer ArrayOfFivePointers[SIZE];


//-----------------------

void initialize (ArrayOfFiveInts ints, ArrayOfFivePointers pointers) {
	int i;
	for (i = 0; i < SIZE; i++) {
		ints[i] = rand();
//whatever srand and getpid mean to seed?
//		srand(getpid());
		pointers[i] = &(ints[i]);
	}
}

void printArray (int* array) {
	int i;
	for (i = 0; i < SIZE; i++) {
		printf(" %d : %d\n", i, *(array + i));
	}
}

void printIntsFromPointers (int ** array) {
	int i;
	for (i = 0; i < SIZE; i++) {
		printf(" %d : %d\n", i, **(array + i));
	}
}

void bubbleSort (int* array) {
	int i, j;
	for (i = 0; i < SIZE - 1; i++) {
		for (j = 0; j < SIZE - i - 1; j++) {
			if (*(array + j) > *(array + j + 1)) {
				int t = *(array + j);
				*(array + j) = *(array + j + 1);
				*(array + j + 1) = t;
			}
		}
	}
}

void bubbleSortFromPointers (int ** array) {
	int i, j;
	for (i = 0; i < SIZE - 1; i++) {
		for (j = 0; j < SIZE - i - 1; j++) {
			if (**(array + j) > **(array + j + 1)) {
				int * t = *(array + j);
				*(array + j) = *(array + j + 1);
				*(array + j + 1) = t;
			}
		}
	}
}

int main(void) {
	ArrayOfFiveInts ints;
	ArrayOfFivePointers pts;

	srand(getpid());
	initialize(ints, pts);

	printf("---- Initialized array of integers ----\n");
	printArray(ints);

	printf("---- Sorted array of pointers ----\n");
	bubbleSortFromPointers(pts);
	printIntsFromPointers(pts);

	printf("---- Sorted array of integers ----\n");
	bubbleSort(ints);
	printArray(ints);

	printf("---- Array of pointers ----\n");
	printIntsFromPointers(pts);


	return (EXIT_SUCCESS);
}
