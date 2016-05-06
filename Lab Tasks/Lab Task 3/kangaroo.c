//---Calculates the expected number of kills each year
//---------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#define AVGROADWIDTH 0.01
#define KILLCONSTANT 1.47
//---------------------------------------------------------------

int main () {
    float side = 1.0, length = 1.0;
    int kangaroos = 0;


    printf("Enter side of square in km  : ");
    scanf("%f", &side);
    printf("Enter roads length in km    : ");
    scanf("%f", &length);
    printf("Enter number of 'roos:      : ");
    scanf("%d", &kangaroos);

    float kills = KILLCONSTANT * length * AVGROADWIDTH * kangaroos / (side * side);
    printf("Expected number of kills is : %1.1f\n", kills);

    return (EXIT_SUCCESS);
}

