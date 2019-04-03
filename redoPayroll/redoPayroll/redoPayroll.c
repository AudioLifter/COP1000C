//Name: Jonathan De La Cruz
//Date: 10/28/18
//Purpose: redo payroll

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#define PAUSE system("pause")
#define CLS system("cls")
#define FLUSH myFlush()

//function prototypes
float calcFedTax(float);
float calcGrossPay(float, float);
float calcMedIns(float);
float calcNetPay(float, float, float);
float calcOvertimePay(float, float);
float calcRegPay(float, float);
void displayPayrollInfo(float, float, float, float,
	float, float, float, float);
float getHourlyRate();
float getHoursWorked();
int goAgain();
void myFlush() {
	while (getchar() != '\n');
} // end myFlush

//===================================
main() {
	//variable declarations
	float payRate;
	float hoursWorked;
	float regPay;
	float overPay;
	float fedTax;
	float grossPay;
	float netPay;
	float medIns;
	int userChoice;

	do {
		payRate = getHourlyRate();
		hoursWorked = getHoursWorked();
		regPay = calcRegPay(payRate, hoursWorked);
		overPay = calcOvertimePay(payRate, hoursWorked);
		grossPay = calcGrossPay(regPay, overPay);
		fedTax = calcFedTax(grossPay);
		medIns = calcMedIns(grossPay);
		netPay = calcNetPay(grossPay, fedTax, medIns);
		displayPayrollInfo(payRate, hoursWorked, regPay, overPay,
			grossPay, fedTax, medIns, netPay);
		PAUSE;
		CLS;
		userChoice = goAgain();
		CLS;
	} while (userChoice == 1);
	
	PAUSE;
}//end main

 /*==============================================================
 ==================  Funtion Definitions  =======================
 ================================================================*/

float calcFedTax(float grossPay) {
	float fedTax;
	fedTax = grossPay * .27;
	return fedTax;
} //end calcFedTax

float calcGrossPay(float regPay, float overPay) {
	float grossPay;
	grossPay = regPay + overPay;
	return grossPay;
} //end calcGrossPay

float calcMedIns(float grossPay) {
	float medIns;
	medIns = grossPay * .14;
	return medIns;
}//end calcMedIns

float calcNetPay(float grossPay, float fedTax, float medIns) {
	float netPay;
	netPay = grossPay - fedTax - medIns;
	return netPay;
}//end calcNetPay

float calcOvertimePay(float hourRate, float hoursWorked) {
	float overPay;
	
	if (hoursWorked > 40)
		overPay = (hoursWorked - 40) * (hourRate * 1.5);
	else 
		overPay = 0.00;

	return overPay;
}//end calcOvertimePay

float calcRegPay(float hourRate, float hoursWorked) {
	float regPay;
	
	if (hoursWorked > 40)
		regPay = hourRate * 40;
	else
		regPay = hourRate * hoursWorked;

	return regPay;
}//end calcRegPay

void displayPayrollInfo(float hourRate, float hoursWorked, float regPay, float overPay, float grossPay, float fedTax,
	float medIns, float netPay) {
	printf("Hourly Rate: %.2f", hourRate);
	printf("\nHours Worked: %.2f", hoursWorked);
	printf("\nRegular Pay: %.2f", regPay);
	printf("\nOT Pay: %.2f", overPay);
	printf("\nGross Pay: %.2f", grossPay);
	printf("\nFederal Tax (27%%): %.2f", fedTax);
	printf("\nMedical Insurance (14%%): %.2f", medIns);
	printf("\nNet Pay: %.2f\n", netPay);
	return;
}//end displayPayrollInfo

float getHourlyRate() {
	float hourlyRate;
	printf("Please enter your hourly rate: $");
	scanf("%f", &hourlyRate);
	return hourlyRate;
}//end getHourlyRate

float getHoursWorked() {
	float hoursWorked;
	printf("Please enter the number of hours you worked this week: ");
	scanf("%f", &hoursWorked);
	return hoursWorked;
}//end getHoursWorked

int goAgain() {
	int decision;
	printf("\n\nWould you like to calculate another week? (1 for Yes / 0 for No): ");
	scanf("%i", &decision); FLUSH;
	return decision;
}//end goAgain