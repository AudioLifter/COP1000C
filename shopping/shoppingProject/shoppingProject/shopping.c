//Name: Jonathan De La Cruz
//Date: 10/3/18
//Purpose: shopping assingment

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#define PAUSE system("pause")
#define CLS system("cls")
#define FLUSH myFlush()

void myFlush() {
	while (getchar() != '\n');
} // end myFlush

main() {
	//declarations
	int weeks = 0; //number of weeks being tracked
	float budget = 0; //money spent on food that week
	float low = 0; //lowest amount spent in any week over tracked period
	float high = 0; //highest amount spent in any week over tracked period
	int i = 0; //counter for "for" loop
	char runAgain = ' '; //used to check if user wants to run again
	do {
		do {
			printf("Please enter the number of weeks you wish to track (5-50): ");
			scanf("%i", &weeks); FLUSH;

			CLS;
		} while (weeks < 5 || weeks > 50); //end input check do-while

		for (i = 0; i < weeks; i++) { //counts up to user entered weeks value

			printf("%i.Please enter the amount spent on food this week: $", i + 1);
			scanf("%f", &budget); FLUSH;

			while (low == 0)
				low = budget;

			if (budget > 250)
				printf("You are going to get fat.\n");

			if (budget < 50.55)
				printf("You are going to starve.\n");

			if (budget >= high)
				high = budget;

			if (budget <= low)
				low = budget;
		} //end for loop
		
		i = 0;

		printf("The lowest you spent on food in a week was: $%.2f\n", low);
		printf("The most you spent on food in a week was:...$%.2f\n", high);
		
		printf("Would you like to track more weeks? (Y/n): "); //asking to run program again
		scanf("%c", &runAgain); FLUSH;
		CLS;
	} while (runAgain == 'Y'); //program continues to loop as long as user enters Y

	PAUSE;
}//end main