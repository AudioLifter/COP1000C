// Written by..: Jonathan De La Cruz
// Date Written: 9/13/18
// Purpose.....: user input math assignment

#define _CRT_SECURE_NO_WARNINGS // TURNS OFF THE _s COMMANDS 
#include <stdio.h> 
#include <stdlib.h> 
#define PAUSE system("pause") 


main() {
	// variable declaration
	
	int val1 = 0;         // first user entered value
	int val2 = 0;         // second user entered value
	int sum = 0;          // sum of user entered values
	int product = 0;      // product of user entered values
	int quotient = 0;     // integer quotient of user entered values
	
	// input
	
	printf("\nPlease enter an integer: ");
	scanf("%i", &val1); 
	printf("Please enter another integer: ");
	scanf("%i", &val2);
	// process
	
	sum = val1 + val2;
	product = val1 * val2;
	quotient = val1 / val2;
	// output
	
	printf("\nThe sum of %i + %i = %i.", val1, val2, sum);
	printf("\nThe product of %i * %i = %i.", val1, val2, product);
	printf("\nThe result of dividing %i / %i as integers is %i.\n\n", val1, val2, quotient);
	
	PAUSE;
} // end main
