//Name: Jonathan De La Cruz
//Date: 11/27/18
//Purpose: sortSearch


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
#define SIZE 500

//prototype here
float calcAdjAverage(float a[], int eS);
float calcAverage(float a[], int eS);
void displayAdjustedAverage(float a[], int eS, int flag);
void displayAverage(float a[],int eS, int flag);
void displayHighest(float gpa[], int eS, int flag);
void displayLowest(float gpa[], int eS, int flag);
void displayMenu();
void displaySorted(float a[], int eS, int flag);
char getChoice();
int getGpa(float gpas[], int eS);
void myFlush();
char swapValues(int array[], int location);
void searchGpa(float a[], int eS, int flag);
void sort(float array[], int eS);
void sortAsc(float array[], int eS);
int tripFlag();

main() {
	//decalre stuff here
	char choice;
	float gpaArray[SIZE] = { 0.00 };
	int eSize = 0;
	int flag = 0;

	//do stuff here
	do {
		CLS;
		displayMenu();
		choice = getChoice();
		switch (choice) {
		case 'A':
			eSize = getGpa(gpaArray, eSize);
			flag = tripFlag();
			break;
		case 'B':
			displayAverage(gpaArray, eSize, flag);
			break;
		case 'C':
			displayHighest(gpaArray, eSize, flag);
			break;
		case 'D':
			displayLowest(gpaArray, eSize, flag);
			break;
		case 'E':
			displayAdjustedAverage(gpaArray, eSize, flag);
			break;
		case 'F':
			searchGpa(gpaArray, eSize, flag);
			break;
		case 'G':
			displaySorted(gpaArray, eSize, flag);
			break;
		case 'Q':
			break;
		default:
			printf("\nPlease enter a valid selection!\n");
			PAUSE;
		}//end switch
	} while (choice != 'Q');

	PAUSE;
}//end main

/*===============================================================================================
===============================================================================================*/

float calcAdjAverage(float a[], int eS) {
	float result;
	float sum = 0;
	for (int i = 0; i < eS - 1; i++)
		sum = a[i] + sum;
	result = sum / (eS - 1);
	return result;
}//end calcAdjAverage

float calcAverage(float a[], int eS) {
	float result;
	float sum = 0;
	for (int i = 0; i < eS; i++)
		sum = a[i] + sum;
	result = sum / eS;
	return result;
}//end calcAverage

void displayAdjustedAverage(float a[], int eS, int flag) {
	CLS;
	float adjAverage;

	if (flag == 0) {
		printf("Please go back and enter some GPAs first!\n\n");
		PAUSE;
		return;
	}//end if
	if (eS == 1) {
		printf("Please enter 2 or more values before using this function.\n\n");
		PAUSE;
		return;
	}//end if

	sort(a, eS);
	adjAverage = calcAdjAverage(a, eS);

	printf("The adjusted average is: %.2f\n", adjAverage);
	PAUSE;
}//end displayAdjustedAverage

void displayAverage(float a[], int eS, int flag) {
	float average;

	CLS;
	if (flag == 0) {
		printf("Please go back and enter some values first.\n\n");
		PAUSE;
		return;
	}//end if
	average = calcAverage(a, eS);
	printf("The average GPA is: %.2f\n", average);
	PAUSE;
}//end displayAverage

void displayHighest(float gpa[], int eS, int flag) {
	CLS;
	float highest;

	if (flag == 0)
		printf("Please go back and enter some GPAs first!\n\n");
	else {
		sort(gpa, eS);
		highest = gpa[0];
		printf("The highest GPA is: %.2f\n\n", highest);
	}//end else
	PAUSE;
}//end displayHighest

void displayLowest(float gpa[], int eS, int flag) {
	CLS;
	float lowest;

	if (flag == 0)
		printf("Please go back and enter some GPAs first!\n\n");
	else {
		sort(gpa, eS);
		lowest = gpa[eS - 1];
		printf("The lowest GPA is: %.2f\n\n", lowest);
	}//end else
	PAUSE;
}//end displayLowest

void displayMenu() {
	char banner[20] = "M A I N    M E N U";
	int length = strlen(banner);
	for (int i = 0; i < length + 20; i++)
		printf("*");
	printf("\n***       %s       ***\n", banner);
	for (int i = 0; i < length + 20; i++)
		printf("*");
	printf("\nA. Enter GPA\n");
	printf("B. Display Average of all GPA's\n");
	printf("C. Display the Highest GPA\n");
	printf("D. Display the Lowest GPA\n");
	printf("E. Display the Adjusted Average\n");
	printf("F. See if a certain GPA was entered\n");
	printf("G. Display the contents of the Array\n");
	printf("Q. Quit\n\n");
}//end displayMenu

void displaySorted(float a[], int eS, int flag) {
	CLS;
	if (flag == 0)
		printf("Please go back and enter some GPAs first!\n\n");
	else {
		sortAsc(a, eS);
		printf("Here are all GPAs entered:\n");
		for (int i = 0; i < eS; i++) {
			printf("\t%.2f\n", a[i]);
		}//end for
	}//end else
	PAUSE;
}//end displaySorted

char getChoice() {
	char result;
	printf("Please enter your choice: ");
	scanf("%c", &result); FLUSH;
	return toupper(result);
}//end getChoice

int getGpa(float a[], int eSize) {

	CLS;
	if (eSize == SIZE) {
		printf("Maximum number of GPAs entered.\n\n");
		PAUSE;
		return eSize;
	}//end if

	printf("Please enter your GPA: ");
	scanf("%f", &a[eSize]); FLUSH;

	if (a[eSize] < 2.0) {
	printf("\n\nYou need to study harder.\n");
	PAUSE;
	}//end if
	if (a[eSize] > 3.5) {
	printf("\n\nNice work.\n");
	PAUSE;
	}//end if
	
	return eSize + 1;
}//end getGpa

void myFlush() {
	while (getchar() != '\n');
} // end myFlush

void searchGpa(float a[], int eS, int flag) {
	float gpaToFind;
	int top = 0;
	int bottom = eS - 1;
	int middle = (top + bottom) / 2;
	char notFound = 'Y';

	CLS;
	if (flag == 0) {
		printf("Please go back and enter some GPAs first!\n\n");
		PAUSE;
		return;
	}//end if
	
	sort(a, eS);
	printf("Please enter a GPA to find: ");
	scanf("%f", &gpaToFind); FLUSH;

	while (top <= bottom && notFound == 'Y') {
		if (a[middle] > gpaToFind)
			top = middle + 1;
		else if (a[middle] < gpaToFind)
			bottom = middle - 1;
		else
			notFound = 'N';
		middle = (top + bottom) / 2;
	} // end while

	if (notFound == 'Y')
		printf("A %.2f GPA was not entered\n\n.", gpaToFind);
	else
		printf("I found %.2f GPA in element %i\n\n", gpaToFind, middle + 1);
	PAUSE;
}//end searchGpa

void sort(float array[], int eS) {
	char swapped;
	int bottom = eS - 1;
	do {
		swapped = 'N';
		for (int i = 0; i < bottom; i++) {
			if (array[i] < array[i + 1]) {
				swapped = swapValues(array, i);
			}// end if
		} // end for
		bottom--;
	} while (swapped == 'Y');
}//void sort

void sortAsc(float array[], int eS) {
	char swapped;
	int bottom = eS - 1;
	do {
		swapped = 'N';
		for (int i = 0; i < bottom; i++) {
			if (array[i] > array[i + 1]) {
				swapped = swapValues(array, i);
			}// end if
		} // end for
		bottom--;
	} while (swapped == 'Y');
}//void sort

char swapValues(int array[], int location) {
	char result = 'Y';
	int temp;
	temp = array[location];
	array[location] = array[location + 1];
	array[location + 1] = temp;
	return result;
}//end swapValues

int tripFlag() {
	return 1;
}//end tripflag
