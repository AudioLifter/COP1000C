//Name: Jonathan De La Cruz
//Date: 11/10/18
//Purpose: carRace assignment


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <Windows.h>
#include <math.h>
#define PAUSE system("pause")
#define CLS system("cls")
#define FLUSH myFlush()

int calcGain();
void displayBanner();
void displayCars(int[]);
void displayFinish();
void displayResults(int[]);
char getChoice();
void myFlush();
void displayRace(int[]);

main() {
	int cars[3] = { 0 };
	char choice = ' ';
	srand((unsigned)time(NULL));//seeding rand()

	displayBanner();
	PAUSE;

	do {
		cars[0] = 0;
		cars[1] = 0;
		cars[2] = 0;
		displayRace(cars);
		PAUSE;
		displayResults(cars);
		choice = getChoice();
	} while (choice == 'Y');

	CLS;
	printf("Goodbye!\n\n\n");
	PAUSE;
}//end main

//======================================================

int calcGain() {
	int gain;
	int const LB = 1;
	int const UB = 3;
	gain = LB + rand() % (UB - LB + 1);
	return gain;
}//end calcGain

void displayBanner() {
	char banner[50] = "Welcome to the Valencia Raceway!";
	int length, i;
	length = strlen(banner);
	CLS;
	
	for (i = 0; i < length + 4; i++) {
		printf("=");
	}//end for
	printf("\n==%s==\n", banner);
	for (i = 0; i < length + 4; i++) {
		printf("=");
	}//end for
	printf("\nPress any key to start the race!\n\n");
}//end displayBanner

void displayCars(int cars[]) {
	int i, j;

	for (i = 0; i < 3; i++) {

		switch (i) {
		case 0:
			for (j = 0; j < cars[i]; j++) {
				printf("A");
			}//end for inner A
			printf("\n");
			break;
		case 1:
			for (j = 0; j < cars[i]; j++) {
				printf("B");
			}//end for inner B
			printf("\n");
			break;
		case 2:
			for (j = 0; j < cars[i]; j++) {
				printf("C");
			}//end for inner C
			printf("\n");
			break;
		}//end switch
	}//end for outer
	Sleep(250);
}//end display cars

void displayFinish(){

	CLS;
	for (int i = 0; i < 80; i++) {
		printf(" ");
	} //end for
	printf("| FINISH\n");
}//end display finish

void displayRace(int cars[]) {
	int whoMoves, gain;
	int const LB = 0;
	int const UB = 2;


	do {
		whoMoves = LB + rand() % (UB - LB + 1);
		CLS;
		gain = calcGain();
		switch (whoMoves) {
		case 0: //movement for car A
			cars[0] += gain;
			
			break;
		case 1: //movement for car B
			cars[1] += gain;
			
			break;
		case 2: //movement for car C
			cars[2] += gain;
			
			break;
		default:
			CLS;
			printf("How the hell did that happen?\n\n\n");
			PAUSE;
			return;
		}

		displayFinish();
		displayCars(cars);

	} while (cars[0] <= 80 && cars[1] <= 80 && cars[2] <= 80);


}//end displayRace

void displayResults(int cars[]) {
	char first = ' ';
	char second = ' ';
	char third = ' ';
	
	//some REALLY lazy sorting
	
	//first
	if (cars[0] > cars[1] && cars[0] > cars[2])
		first = 'A';
	if (cars[1] > cars[0] && cars[1] > cars[2])
		first = 'B';
	if (cars[2] > cars[0] && cars[2] > cars[1])
		first = 'C';
	//third
	if (cars[0] < cars[1] && cars[0] < cars[2])
		third = 'A';
	if (cars[1] < cars[0] && cars[1] < cars[2])
		third = 'B';
	if (cars[2] < cars[0] && cars[2] < cars[1])
		third = 'C';
	//second
	if((first == 'B' || first == 'C') && (third == 'C' || third =='B'))
		second = 'A';
	if ((first == 'A' || first == 'C') && (third == 'A' || third == 'C'))
		second = 'B';
	if ((first == 'A' || first == 'B') && (third == 'A' || third == 'B'))
		second = 'C';

	printf("\n\nFirst place is: %c\n", first);
	printf("Second place is: %c\n", second);
	printf("Third place is: %c\n", third);
}//end displayResults

char getChoice() {
	char result = ' ';
	printf("Would you like to race again? (Y/n): ");
	scanf("%c", &result); FLUSH;
	return toupper(result);
}//end getChoice

void myFlush() {
	while (getchar() != '\n');
} // end myFlush