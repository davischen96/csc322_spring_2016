//----Provides ambient pressure for a dive, the partial pressure of oxygen for the dive, and the oxygen pressure group.
//---------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

#define MAXPRESSURE 1.4
#define CONTINGENCYPRESSURE 1.6
#define FEETPERPRESSURE 33.0
//---------------------------------------------------------------------------------------------------------------------
float computeAmbPres (int depth) {
    return 1 + depth/FEETPERPRESSURE;
}

float computePartPres (int pressure, int percentage) {
    return pressure * percentage / 100.0;
}

char computePressureGroup (float pressure) {
    return ((int) (pressure * 10)) + 'A';
}

char * evalBool (float pressure, float minimum) {
    return pressure > minimum ? "true" : "false";
}


int main () {
    int percentage = 0, depth = 0;

    printf("Enter depth and percentage O2   : ");
    scanf("%d %d", &depth, &percentage);
    float pressure = computeAmbPres(depth);
    float parto2pressure = computePartPres(pressure, percentage);
    char pressureGroup = computePressureGroup(parto2pressure);

    printf("\nAmbient pressure\t\t:%4.1f\n", pressure);
    printf("O2 pressure\t\t\t: %4.2f\n", parto2pressure);
    printf("O2 group\t\t\t: %c\n", pressureGroup);
    printf("\n\n\nExceeds maximal O2 pressure\t: %s\n", evalBool(parto2pressure, MAXPRESSURE));
    printf("Exceeds contingency O2 pressure\t: %s\n", evalBool(parto2pressure, CONTINGENCYPRESSURE));

    return(EXIT_SUCCESS);
}
