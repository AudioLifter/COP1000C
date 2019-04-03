//Name: Jonathan De La Cruz
//Date: 11/9/18
//Purpose: arrayIntro Assignment


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
#define SIZE 1000

float calcAverage(float[], int);
float calcSum(float[], int);
void displayAll(float[], int, int);
void displayAverage(float[], int, int);
void displayMenu();
void displaySum(float[], int, int);
int enterNumber(float[], int);
int getChoice(char[]);
void myFlush();


main() {
	int menuChoice = 0;
	int flag = 0;
	int eSize = 0;
	float numberArray[SIZE] = { 0 };

	do {
		displayMenu();
		menuChoice = getChoice("Enter selection: ");
		switch (menuChoice) {
		case 1:
			eSize = enterNumber(numberArray, eSize);
			flag = 1;
			break;
		case 2:
			displaySum(numberArray, eSize, flag);
			break;
		case 3:
			displayAverage(numberArray, eSize, flag);
			break;
		case 4:
			displayAll(numberArray, eSize, flag);
			break;
		case 5:
			CLS;
			printf("Good bye!\n\n\n");
			break;
		default:
			printf("\nPlease enter a valid selection!\n\n");
			PAUSE;
		}//end switch
	} while (menuChoice != 5); //end do-while
	PAUSE;
}

//======================================================

float calcAverage(float a[], int eSize) {
	float average = 0.0;
	float sum = 0.0;
	sum = calcSum(a, eSize);
	average = sum / eSize;
	return average;
}//end calcAverage

float calcSum(float a[], int eSize) {
	float sum = 0.0;
	for (int i = 0; i < eSize; i++) {
		sum = sum + a[i];
	}//end for 
	return sum;
}//end calcSum

void displayAll(float a[], int eSize, int flag) {
	CLS;
	if (flag == 0) {
		printf("There are no values in the array yet!\n");
		PAUSE;
		return;
	}//end if
	for (int i = 0; i < eSize; i++) {
		printf("%i. %.2f\n", i + 1, a[i]);
	}//end for 
	PAUSE;
}//end displayAlll

void displayAverage(float a[], int eSize, int flag) {
	float average = 0.0;
	CLS;
	if (flag == 0) {
		printf("Please add atleast 1 value to the array first!\n");
		PAUSE;
		return;
	}//end if
	average = calcAverage(a, eSize);
	printf("The average of all %i elements in the array is: %.2f\n", eSize, average);
	PAUSE;
}//end displayAverage

void displayMenu() {
	CLS;
	printf("MAIN MENU\n\n");
	printf("1. Enter a number\n");
	printf("2. Display the sum of all numbers entered\n");
	printf("3. Display average of numbers entered\n");
	printf("4. Display all numbers entered\n");
	printf("5. Quit\n");
}//end displayMenu

void displaySum(float a[], int eSize, int flag) {
	float sum = 0.0;
	CLS;
	if (flag == 0) {
		printf("Please add atleast 1 value to the array first!\n");
		PAUSE;
		return;
	}//end if
	sum = calcSum(a, eSize);
	printf("The sum of all values entered is: %.2f\n", sum);
	PAUSE;
}//end displaySum

int enterNumber(float a[], int eSize) {
	CLS;
	if (eSize >= SIZE) {
		printf("Array is full!\n");
		PAUSE;
		return eSize;
	}//end if

	printf("Please enter a number to store in the array: ");
	scanf("%f", &a[eSize]); FLUSH;
	eSize = eSize + 1;
	return eSize;
}//end enterNumber

int getChoice(char message[]) {
	int result;
	printf("%s", message);
	scanf("%i", &result); FLUSH;
	return result;
}//end getNumber

void myFlush() {
	while (getchar() != '\n');
} // end myFlush