// Written by..: Jonathan De La Cruz
// Date Written: 9/18/18
// Purpose.....: Decision Assignment

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#define PAUSE system("pause")
#define CLS system("cls")
#define FLUSH myFlush()

void myFlush(){
  while(getchar() != '\n');
} // end myFlush

main() {
	
	// variable declarations
	char value1 = ' ';		
	char value2 = ' ';		
	char value3 = ' ';	
	char cantBe = 'Z';
	
	// asking for user input
	printf("Enter character 1 of 3: ");
	scanf("%c", &value1); FLUSH;
	
	printf("Enter character 2 of 3: ");
	scanf("%c", &value2); FLUSH;
	
	printf("Enter character 3 of 3: ");
	scanf("%c", &value3); FLUSH;
	
	// decisions and output
	if(value3 == cantBe || (value1 > value2 || value1 > value3)){         
		printf("\nDead\n"); //condition check for "Dead" output
	} else{                      
			if(value1 == value2 && value3 != cantBe){     
				printf("\nHappy\n");
			} // condition check for "Happy!" output
	
			if(value1 < value2 && value1 < value3){
				printf("\nSad\n");
			} // condition check for "Sad!" output
	}		
} 	// end
