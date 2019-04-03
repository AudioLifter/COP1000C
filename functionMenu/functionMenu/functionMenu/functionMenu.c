//Name: Jonathan De La Cruz
//Date: 10/30/18
//Purpose: functionMenu assignment

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h> 
#define PAUSE system("pause")
#define CLS system("cls")
#define FLUSH myFlush()

void displayMenu();
int getUserChoice();
void myFlush();
void quit();

main() {
	int userChoice; //holds user menu choice
	
	do {
		displayMenu();
		userChoice = getUserChoice();
		switch (userChoice) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			quit();
			break;
		default:
			printf("\nPlease select a valid option!\n\n\n\n\n");
			PAUSE;
			break;
		}//end switch
	} while (userChoice != 5); //end do-while
	PAUSE;
}//end main

//============================================================================

void displayMenu(){
	CLS;
	printf("MAIN MENU\n\n");
	printf("1. Display Your Name\n");
	printf("2. Dispay your name (x Times)\n");
	printf("3. Display Add Two Numbers\n");
	printf("4. Take the result of item 3 above and square it.\n");
	printf("5. Quit\n");
	return;
}//end displayMenu

int getUserChoice() {
	int result;
	printf("\nPlease enter your selection: ");
	scanf("%i", &result); FLUSH;
	return result;
}//end getUserChoice

void myFlush() {
	while (getchar() != '\n');
} // end myFlush

void quit() {
	CLS;
	printf("Thank you, good bye.\n\n");
	PAUSE;
	exit(0);
}