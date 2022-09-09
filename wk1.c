
// Visual Studio Specific warning suppressor
#define _CRT_SECURE_NO_WARNINGS

// C standard input output library
#include <stdio.h>

// entry point to the application
int main(void)
{
	// variables
	int birthYear = 1980;
	double weightLbs, promoted;
	int narrowed;
	
	printf("The value of birthYear: %d\n", birthYear);
	printf("Please enter YOUR birth year: ");
	scanf("%d", &birthYear);
	printf("The value of birthYear: %d\n", birthYear);
	promoted = birthYear; // int being stored to a double data type (no warnings)
	printf("Here is the birth year as double: %lf\n\n", promoted);

	printf("What is your weight? : ");
	scanf("%lf", &weightLbs);
	printf("Here is your weight: %lf\n", weightLbs);
	printf("Here is your weight: %.1lf\n", weightLbs);
	printf("Here is your weight: %.25lf\n\n", weightLbs);

	narrowed = (int)weightLbs; // cast explicitly to an int (will suppress warnings)

	printf("Here is your weight as an INT: %d\n",narrowed );

	//// logic and output
	//printf("Workshop 1 Part 1\n"
	//	   "=================\n\n");

	//printf("Here are some things...\n"
	//	   "And some more things...-- and more\n\n");

	
	return 0;
}