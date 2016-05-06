//--------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

#define SUPERRICH 500000
#define QUITERICH 200000
#define MIAMIPOOR 100000
#define AVERAGE 50000
#define REALISTIC 20000
#define HIGHRATE 0.25
#define MEDIUMRATE 0.10
#define LOWRATE 0.03
#define POORRATE 0.00
#define MAXIMALTAX 50000

void getInput (int * income, int * deductions) {
	int input = -1;
	while ((printf("Enter next amount : "), scanf("%d", &input), input) != 0) {
                if (input > 0) {
                        *income += input;
                } else {
                        *deductions -= input;
                }
        }
}

int getTaxableIncome (int income, int deductions) {
	if (income >= deductions)	{
		return income - deductions;
	} else {
		return 0;
	}
}

char getTaxGroup (int taxable) {
	if (taxable >= SUPERRICH) {
		return 'S';
	} else if (taxable >= QUITERICH) {
                return 'Q';
        } else if (taxable >= MIAMIPOOR) {
                return 'M';
        } else if (taxable >= AVERAGE) {
                return 'A';
        } else if (taxable >= REALISTIC) {
		return 'R';
	} else {
		return 'P';
	}
}

float calculateTax (int taxable, char taxGroup) {
	float r = 0.0;
	if (taxGroup == 'S' || taxGroup == 'Q') {
		r = HIGHRATE;
	} else if (taxGroup == 'M') {
		r = MEDIUMRATE;
	} else if (taxGroup == 'A' || taxGroup == 'R') {
		r = LOWRATE;
	} else if (taxGroup == 'P') {
		r = POORRATE;
	} else {
		printf("Error!");
	}
	
	int finalTax = (taxable * r);
        if (finalTax > MAXIMALTAX) {
                return MAXIMALTAX;
        } else {
                return finalTax;
        }

}

void displayInfo (int income, int deductions, int taxable, char taxGroup, float finalTax) {
	printf("\n");
        printf("Income\t\t= $%8.2f\n", (float) income);
        printf("Deductions\t= $%9.2f\n", (float) deductions);
        printf("Taxable Income\t= $%8.2f\n", (float) taxable);
        printf("Tax Group\t= %c\n", taxGroup);
        printf("Tax Owed\t= $%9.2f\n", finalTax);
}

int main () {
	int income = 0, deductions = 0;

	getInput(&income, &deductions);
	int taxable = getTaxableIncome(income, deductions);
	char taxGroup = getTaxGroup(taxable);
	float finalTax = calculateTax(taxable, taxGroup);
	displayInfo(income, deductions, taxable, taxGroup, finalTax);	

	return(EXIT_SUCCESS);
}
