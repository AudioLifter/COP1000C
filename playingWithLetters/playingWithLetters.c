//Name: Jonathan De La Cruz
//Date: 11/13/18
//Purpose: playingWithLetters

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#define PAUSE system("pause")
#define CLS system("cls")
#define FLUSH myFlush()
#define SIZE 50

int clearArray(char myWord[], int eS);
void displayWord(char myWord[], int eS);
void displayWordBackwards(char myWord[], int eS);
void displayWordVertical(char myWord[], int eS);
void displayWordUpsdVert(char myWord[], int eS);
int getWord(char myWord[], int eS);
char getChoice();
void myFlush();

main() {
	int eSize = 0;
	char myWord[SIZE] = { ' ' };
	char choice = ' ';

	do {
		CLS;
		eSize = getWord(myWord, eSize);
		displayWord(myWord, eSize);
		displayWordBackwards(myWord, eSize);
		displayWordVertical(myWord, eSize);
		displayWordUpsdVert(myWord, eSize);
		PAUSE;
		eSize = clearArray(myWord, eSize);
		choice = getChoice();
	} while (choice == 'Y');
	CLS;
	printf("Goodbye!");
	PAUSE;
}//end main

//=================================================================
int clearArray(char myWord[], int eS) {
	for (int i = 0; i < SIZE; i++) {
		myWord[i] = ' ';
	}//end for
	eS = 0;
	return eS;
}//end clearArray

void displayWord(char myWord[], int eS) {
	printf("1. The word is: %s\n\n", myWord);
}//end displayWord

void displayWordBackwards(char myWord[], int eS) {
	printf("2. The word backwards is: ");
	for (int i = eS; i >= 0; i--)
		printf("%c", myWord[i]);
	printf("\n\n");
}//end displayWordBackwards

void displayWordVertical(char myWord[], int eS) {
	printf("3. The word vertical is: \n");
	for (int i = 0; i < eS; i++)
		printf("%c\n", myWord[i]);
	printf("\n");
}//end displayWordVertical

void displayWordUpsdVert(char myWord[], int eS) {
	printf("4. The word upside down vertical is:\n");
	for (int i = eS - 1; i >= 0; i--)
		printf("%c\n", myWord[i]);
	printf("\n\n\n");
}//end displayWordUpsdVert

char getChoice() {
	char result;
	CLS;
	printf("Would you like go again? (Y/n): ");
	scanf("%c", &result); FLUSH;
	return toupper(result);
}//getChoice

int getWord(char myWord[], int eS) {
	CLS;
	printf("Please enter your word: ");
	scanf("%s", myWord); FLUSH;
	eS = strlen(myWord);
	return eS;
}//end getWord

void myFlush() {
	while (getchar() != '\n');
} // end myFlush
