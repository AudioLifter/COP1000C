//Name: Jonathan De La Cruz
//Date: 10/19/18
//Purpose: triangle assignment

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
	int userNum = 0; //userNumber
	int i; //counter
	int currentRow; //tracks number of asteriks to use per row
	char goAgain = ' ';

	do {
		do {
			printf("Please enter the number of rows (1-50) you wish to generate: ");
			scanf("%i", &userNum); FLUSH; //getting input from user

			if (userNum < 1 || userNum > 50) { //checking input
				printf("\nInvalid entry, please enter a number between 1 and 50.\n");
				PAUSE;
			} //end if to check if input is valid, else user is prompted to try again.
			CLS;
		} while (userNum < 1 || userNum > 50); //loop continues until input is valid

		for (i = 0; i <= userNum; i++) { //prints number of rows user selecter
			for (currentRow = 1; currentRow <= i; currentRow++) { //prints number of asteriks per row
				printf("* ");
			}//end for
			printf("\n");
		}//end for	
		PAUSE;
		CLS;

		printf("Would you like to print another triangle? (Y/n): ");
		scanf("%c"); FLUSH;
	} while (goAgain == "Y");

	PAUSE;

} //end triangle


