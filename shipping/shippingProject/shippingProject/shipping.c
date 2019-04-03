//Name: Jonathan De La Cruz
//Date: 9/27/18
//Purpose: shipping


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define PAUSE system("pause")
#define CLS system("cls")
#define FLUSH myFlush()

void myFlush() {
	while (getchar() != '\n');
} // end myFlush

main() {
	//declarations
	float weight = 0.00;
	float miles = 0.00;
	float costWeight = 0.00;
	float costDistance = 0.00;
	float costTotal = 0.00;

	printf("Please enter the weight of the package:  "); 
	scanf("%f", &weight); FLUSH; //getting weight from user

	printf("Please enter the shipping distance in miles: ");
	scanf("%f", &miles); FLUSH;
	
	if (weight <= 10) {
		costWeight = 10.00;
	} //end if for weight <= 10.00
	else {
		costWeight = 10.00 + (weight - 10) * 1.55;
	} //end else for weight > 10.00

	if (miles <= 250) {
		costDistance = 6.66;
	} //end if for distance <= 250
	else {
		costDistance = (ceil(miles / 250)) * 6.66;
	} //end else for distance > 250
	
	costTotal = costWeight + costDistance; //calculating total cost

	//output
	printf("\nPackage Weight is %.1f pound.", weight);
	printf("\nDistance to ship is %.1f miles.", miles);
	printf("\nCost to ship based on weight is..: $%.2f", costWeight);
	printf("\nCost to ship based on distance is: $%.2f", costDistance);
	printf("\nTotal cost to ship is............: $%.2f\n\n", costTotal);

	PAUSE;

} // end main