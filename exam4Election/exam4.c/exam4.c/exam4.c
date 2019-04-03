//Name: Jonathan De La Cruz
//Date: 11/28/2018
//Purpose: Exam 4


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
#define SIZE 3

void displayArrays(int sorted[], int locations[], int eSize);
void displayMenu();
void displayTotals(int trump[], int obama[], int redSize, int blueSize);
void displayOrderedVotes(int trumpSorted[], int trump[], int obamaSorted[], int obama[], int redSize, int blueSize);
int getNumber(char message[]);
int getVotes(int canidate[], int eSize, char message[]);
void myFlush();
void sort(int candidateSorted[], int eSize);
char swapValues(int array[], int location);

main() {
	//declare stuff here

	//trump arrays
	int trumpVotes[SIZE] = { 0 };
	int trumpSorted[SIZE] = { 0 };
	int trumpLocations[SIZE] = { 0 };
	int redVotesESize = 0;
	int trumpLocationsESize = 0;
	//obama arrays
	int obamaVotes[SIZE] = { 0 };
	int obamaLocations[SIZE] = { 0 };
	int obamaSorted[SIZE] = { 0 };
	int blueVotesESize = 0;
	int obamaLocationsSize = 0;
	//other stuff
	int choice;

	//do stuff here
	do {
		CLS;
		displayMenu();
		choice = getNumber("\nPlease enter your selection: ");

		switch (choice) {
			case 1:
				redVotesESize = getVotes(trumpVotes, redVotesESize, "Ivanka Trump");
				break;
			case 2:
				blueVotesESize = getVotes(obamaVotes, blueVotesESize, "Michelle Obama");
				break;
			case 3:
				displayTotals(trumpVotes, obamaVotes, redVotesESize, blueVotesESize);
				break;
			case 4:
				displayOrderedVotes(trumpSorted, trumpVotes, obamaSorted, obamaVotes,
					redVotesESize, blueVotesESize);
				break;
			case 5:
				//sameVotesSearch(trumpVotes, obamaBotes, redESize, blueESize);
			case 6:
				//highLowAverage(trumpVotes, obamaVotes, redESize, blueESize);
				break;
			case 7:
				CLS;
				printf("Election is over now, exiting program...\n\n");
				break;
			default:
				printf("\n\nPlease make a valid selection!\n");
				PAUSE;
		}//end switch
	} while (choice != 7);



	PAUSE;
}//end main

//=============================================================
void displayArrays(int sorted[], int locations[], int eSize) {
	for (int i = 0; i < eSize; i++) {
		printf("%i. State %i: %i votes\n",
			i + 1, locations[i] + 1, sorted[i]);
	}//end for
	PAUSE;
}//end displayArrays


void displayMenu() {
	printf("Welcome to the Election!\n\n");
	printf("MAIN MENU\n");
	printf("1. Enter a states votes for Ivanka Trump\n");
	printf("2. Enter a states votes for Michelle Obama\n");
	printf("3. Display total votes for each candidate\n");
	printf("4. Display all votes for a selected candidate in order\n");
	printf("5. List states where both candidates received the same number of votes\n");
	printf("6. Display candidates' highest, lowest, and average votes\n");
	printf("7. Exit program\n\n");
}//end displayMenu

void displayOrderedVotes(int trumpSorted[], int trump[],int obamaSorted[], 
	int obama[], int redSize, int blueSize) {
	int choice;
	int i;
	//copy arrays

	for (i = 0; i < redSize; i++)
		trumpSorted[i] = trump[i];
	for (i = 0; i < blueSize; i++)
		obamaSorted[i] = obama[i];
	
	//selecting who to print
	CLS;
	printf("Please select which candidate to display:\n");
	printf("\t1. Ivanka Trump\n");
	printf("\t2. Michelle Obama\n\n");
	choice = getNumber("Please enter your selection: ");

	//switch depending on choice
	switch (choice) {
	case 1: 
		sort(trumpSorted, redSize);

		break;
	case 2:
		sort(obamaSorted, blueSize);

		break;
	}
	PAUSE;
}//end displayOrderedVotes

void displayTotals(int trump[], int obama[], int redSize, int blueSize) {
	int trumpTotal = 0;
	int obamaTotal = 0;
	int i;
	CLS;
	for (i = 0; i < redSize; i++)
		trumpTotal += trump[i];
	for (i = 0; i < blueSize; i++)
		obamaTotal += obama[i];
	printf("The total number of votes for Ivanka Trump is: %i\n", trumpTotal);
	printf("The total number of votes for Michelle Obama is: %i\n", obamaTotal);
	PAUSE;
}//end displayTotals

char getChar(char message[]) {
	char result;
	printf("%s", message);
	scanf("%c", &result); FLUSH;
	return toupper(result);
}//end getChar

int getNumber(char message[]) {
	int result;
	printf("%s", message);
	scanf("%i", &result); FLUSH;
	return result;
}//end getNumber

int getVotes(int canidate[], int eSize, char message[]) {
	char choice;
	
	CLS;
	if (eSize == SIZE) {
		printf("All states have been entered for %s, no more votes can be added at this time\n", message);
		PAUSE;
		return eSize;
	}//end if

	for (eSize; eSize <= SIZE; eSize++) {
		CLS;
		if (eSize == SIZE) {
			CLS;
			printf("That was the last state, all states have been entered for %s\n", message);
			PAUSE;
			return eSize;
		}//end if
		printf("Please state %i votes for %s: ", eSize + 1, message);
		scanf("%i", &canidate[eSize]); FLUSH;
		choice = getChar("\n\nWould you like to enter the next state? (Y/n): ");
		if (choice != 'Y')
			return eSize + 1; // because for loop has not yet incremented eSize, its manually done here if user chooses to exit before entering all states for a canidate
	}//end for
	return eSize;
}//end getVotes

void myFlush() {
	while (getchar() != '\n');
} // end myFlush

void sort(int candidateSorted[], int eSize) {
	char swapped = ' ';
	int i;
	int bottom = eSize - 1;
	//enhanced Bubble Sort
	do {
		swapped = 'N';
		for (i = 0; i < bottom; i++) {
			if (candidateSorted[i] < candidateSorted[i + 1]) {
				swapped = swapValues(candidateSorted, i);
			}// end if
		} // end for
		bottom--;
	} while (swapped == 'Y');
}//end sort

char swapValues(int array[], int location) {
	char result = 'Y';
	int temp;
	temp = array[location];
	array[location] = array[location + 1];
	array[location + 1] = temp;
	return result;
} // end swapValues