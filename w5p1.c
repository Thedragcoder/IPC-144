/*
*****************************************************************************
                          Workshop - #5 (P1)
Full Name  : utsav gautam
Student ID#: 157891219
Email      : ugautam4@myseneca.ca
Section    : ZAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MIN_YEAR 2012 // Macros
#define MAX_YEAR 2022 // Macros
int main(void)
{
    // variables 
    const int JAN = 1; 
    const int DEC = 12;
    int giveYear, giveMonth; 

    printf("General Well-being Log\n"); 
    printf("======================\n"); 
    do
 {
    printf("Set the year and month for the well-being log (YYYY MM): ");
    scanf("%d %d", &giveYear, &giveMonth);
    if (giveYear < MIN_YEAR || giveYear > MAX_YEAR) {
    printf(" ERROR: The year must be between 2012 and 2022 inclusive\n");
    }

    if (giveMonth <JAN || giveMonth > DEC) {
    printf(" ERROR: Jan.(1) - Dec.(12)\n");
    }

    }
    while (giveYear <MIN_YEAR || giveYear > MAX_YEAR || giveMonth <JAN || giveMonth > DEC);
    printf("\n*** Log date set! ***\n\n");
    printf("Log starting date: %d-", giveYear);
    
    switch (giveMonth) {
        case 1: printf("JAN"); break;
        case 2: printf("FEB"); break;
        case 3: printf("MAR"); break;
        case 4: printf("APR"); break;
        case 5: printf("MAY"); break;
        case 6: printf("JUN"); break;
        case 7: printf("JUL"); break;
        case 8: printf("AUG"); break;
        case 9: printf("SEP"); break;
        case 10: printf("OCT"); break;
        case 11: printf("NOV"); break;
        case 12: printf("DEC"); break;

    } 
    printf("-01\n"); 
    
    return 0;
}
