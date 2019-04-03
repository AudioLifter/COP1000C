// Written by..: Jonathan De La Cruz 
// Date Written: 9/11/18 
// Purpose.....: Design, variables, and math review up to today 

#define _CRT_SECURE_NO_WARNINGS // TURNS OFF THE _s COMMANDS 
#include <stdio.h> 
#include <stdlib.h> 
#define PAUSE system("pause") 

main() { 

    //Declare variables here 
    float li = 2.0;        // lithium 
    float os = 3.0;        // osmium 
    float hg = 4.0;        // mercury 
    float kr = 5.0;        // krypton 
    float totalLi = 2.0;   // total lithium 
    float totalOs = 3.0;   // total osmium 
    float totalHg = 4.0;   // total mercury 
    float totalKr = 5.0;   // total krypton 
    float totalOz = 0.0;   // total ounces 
    int totalGal = 0;      // total gallons 
    float remainingOz = 0.0; // ounces left over after finding gallons 

    // [I] Get input from user 
	printf("============================================================\n");
  	
	printf("Please enter amount of Lithium(oz): ");
  	scanf("%f", &li);
  	
	printf("Please enter the amount of Osmium in(oz): ");
  	scanf("%f", &os);
  	
	printf("Please enter the amount of Mercury(oz): ");
  	scanf("%f", &hg);
  	
	printf("Please enter the amount of Krypton(oz): ");
  	scanf("%f", &kr);
    
	// [P] calculate stuff 
	
	totalLi = li + li * 2;
	totalOs = os + ((os + li ) * li); 
	totalHg = hg * os;
	totalKr = kr * 1.5;
    totalOz = li + os + (li + os) * li + hg * os + kr * 1.5 + li *2; 
	totalGal = totalOz / 128;
	remainingOz = totalOz - totalGal * 128;
    
	// [O] output info here 

  

    printf("============================================================\n");
    printf("Lithium: %.1f oz.\n", li); 
    printf("Osmium : %.1f oz.\n", os); 
    printf("Mercury: %.1f oz.\n", hg); 
    printf("Krypton: %.1f oz.\n", kr); 

    printf("============================================================\n"); 
    printf("Total Lithium: %.1f oz.\n", totalLi); 
    printf("Total Osmium : %.1f oz.\n", totalOs); 
    printf("Total Mercury: %.1f oz.\n", totalHg); 
    printf("Total Krypton: %.1f oz.\n", totalKr); 

    printf("============================================================\n"); 
    printf("Total Ounces you will need: %.1f\n", totalOz); 
    printf("============================================================\n"); 
    printf("You will need a container that holds %i gallons and %.1f oz.\n", 
        totalGal, remainingOz); 

    printf("============================================================\n\n\n\n"); 
    
    PAUSE;


} // End 
