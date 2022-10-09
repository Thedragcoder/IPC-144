/*
*****************************************************************************
                          Workshop - #5 (P2)
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
#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3

int main(void)
{
    const int JAN = 1, DEC = 12;
    int giveYear = 0, giveMonth = 0;
    int i;
    double rateOfMorning, rateOfEvening, totalOfMorning = 0, totalOfEvening = 0;


    printf("General Well-being Log\n");
    printf("======================\n");

    do
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf(" %d %d", &giveYear, &giveMonth);
        if (giveYear < MIN_YEAR || giveYear> MAX_YEAR)
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
        }
        if (giveMonth < JAN || giveMonth > DEC)
        {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }

    } while (giveYear < MIN_YEAR || giveYear > MAX_YEAR || giveMonth < JAN || giveMonth > DEC);
    printf("\n*** Log date set! ***\n");

    for (i = 1; i <= LOG_DAYS && (LOG_DAYS >= 3 || LOG_DAYS <= 28); i++)
    {
        printf("\n");
        printf("%d-", giveYear);
        switch (giveMonth)
        {
        case 1:
            printf("JAN");
            break;
        case 2:
            printf("FEB");
            break;
        case 3:
            printf("MAR");
            break;
        case 4:
            printf("APR");
            break;
        case 5:
            printf("MAY");
            break;
        case 6:
            printf("JUN");
            break;
        case 7:
            printf("JUL");
            break;
        case 8:
            printf("AUG");
            break;
        case 9:
            printf("SEP");
            break;
        case 10:
            printf("OCT");
            break;
        case 11:
            printf("NOV");
            break;
        case 12:
            printf("DEC");
            break;
        }
        printf("-%02d\n", i);

        do {
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &rateOfMorning);

            if (rateOfMorning < 0.0 || rateOfMorning > 5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        } while (rateOfMorning < 0.0 || rateOfMorning > 5.0);

        totalOfMorning += rateOfMorning;

        do {
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &rateOfEvening);

            if (rateOfEvening < 0.0 || rateOfEvening > 5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        } while (rateOfEvening < 0.0 || rateOfEvening > 5.0);
        totalOfEvening += rateOfEvening;
    }
    printf("\nSummary\n");
    printf("=======\n");

    printf("Morning total rating: %.3lf\n", totalOfMorning);
    printf("Evening total rating:  %.3lf\n", totalOfEvening);
    printf("----------------------------\n");
    printf("Overall total rating: %.3lf\n\n", (totalOfMorning + totalOfEvening));

    printf("Average morning rating:  %.1lf\n",
        (totalOfMorning / LOG_DAYS));
    printf("Average evening rating:  %.1lf\n",
        (totalOfEvening / LOG_DAYS));
    printf("----------------------------\n");
    printf("Average overall rating:  %.1lf\n\n",
        ((totalOfMorning / LOG_DAYS) + (totalOfEvening / LOG_DAYS)) / 2);

    return 0;
}