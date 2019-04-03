//Name: Jonathan De La Cruz
//Date: 11/2/18
//Purpose: functionMenu assignment

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

int displayAddTwoNumbers();
void displayMenu();
void displayName();
int getNumber(char message[]);
void myFlush();
void nameXTimes();
void squareChoiceThree(int, int);
int tripFlag();

main() {
	int choice;
	int flagSum = 0;
	float sum = 0;

	do {
		displayMenu();
		choice = getNumber("Please enter your selection: ");
		switch (choice) {
		case 1:
			displayName();
			break;
		case 2:
			nameXTimes();
			break;
		case 3:
			sum = displayAddTwoNumbers();
			flagSum = tripFlag();
			break;
		case 4:
			squareChoiceThree(sum, flagSum);
			break;
		case 5:
			CLS;
			printf("Thanks for using my program. Good bye.\n\n");
			break;
		default:
			printf("\nInvalid selection. Please try again!\n");
			PAUSE;
		}
	} while (choice != 5);

	PAUSE;
}//end main

//======================================================

int displayAddTwoNumbers() {
	int num1, num2, result;
	CLS;
	num1 = getNumber("Please enter the first number: ");
	CLS;
	num2 = getNumber("Please enter the second number: ");
	CLS;
	result = num1 + num2;
	printf("%i + %i equals %i\n", num1, num2, result);
	PAUSE;
	return result;
}//end displayAddTwoNumbers

void displayMenu() {
	CLS;
	printf("MAIN MENU\n");
	printf("1. Display Your Name\n");
	printf("2. Display Your Name (x Times)\n");
	printf("3. Display Add Two Numbers\n");
	printf("4. Take the result of item 3 above and square it\n");
	printf("5. Quit\n\n\n");
	return;
}//end displayMenu

void displayName() {
	char name[50];
	CLS;
	printf("What is your name?: ");
	scanf("%[^\t\n]s", &name); FLUSH;
	CLS;
	printf("Your name is %s\n", name);
	PAUSE;
	return;
}//end displayName

int getNumber(char message[]) {
	int result;
	printf("%s", message);
	scanf("%i", &result); FLUSH;
	return result;
}//end getNumber

void myFlush() {
	while (getchar() != '\n');
} // end myFlush

void nameXTimes() {
	int i, times;
	char name[50];
	CLS;
	printf("Please enter your name: ");
	scanf("%[^\t\n]s", &name); FLUSH;
	CLS;
	times = getNumber("Please enter the number of times to print: ");
	CLS;
	for (i = 0; i < times; ++i) {
		printf("%i. %s\n", i + 1, name);
	}//end for
	PAUSE;
}//end name x Times

void squareChoiceThree(int sum, int flag) {
	int square;
	CLS;
	if (flag == 0) {
		printf("Please go back and do choice 3 first!\n");
		PAUSE;
	}//end if
	else {
		square = sum * sum;
		printf("%i squared is: %i\n", sum, square);
		PAUSE;
	}//end else
	return;
}//end squareChoiceThree

int tripFlag() {
	return 1;
}//end tripFlag