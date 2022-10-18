/*
*****************************************************************************
                          Workshop - #6 (P2)
Full Name  : utsav gautam
Student ID#: 157891219
Email      : ugautam4@myseneca.ca
Section    : ZAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
******************* **********************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//macros
#define MIN_WISHLIST_ITEMS 1 
#define MAX_WISHLIST_ITEMS 10
#define DETAILS 5

int main(void)
{
    //variable declaration
const double minimumNetIncome= 500.00, maximumNetIncome = 400000.00; 
double netEarnedIncome = 0, totalCost = 0;
int forecastItems, selection, flag = 1;
double itemCost[MAX_WISHLIST_ITEMS];
int importance[MAX_WISHLIST_ITEMS];
char options[MAX_WISHLIST_ITEMS];

//printing title
printf("+--------------------------+\n");
printf("+   Wish List Forecaster   |\n"); 
printf("+--------------------------+\n");

//Net income earned input
 do {
 printf("\nEnter your monthly NET income: $");
 scanf("%lf", &netEarnedIncome);
 if (netEarnedIncome < minimumNetIncome) {
 printf("ERROR: You must have a consistent monthly income of at least $500.00");
 printf("\n");
 }
 if (netEarnedIncome > maximumNetIncome) {
 printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00");
 printf("\n");
 }
 } while (netEarnedIncome < minimumNetIncome || netEarnedIncome > maximumNetIncome);

 //pass the conditions above ask user input wishlist items

 do{
     printf("\nHow many wish list items do you want to forecast?: ");
    scanf("%d", &forecastItems);
    
    //if item entered is less than 1 OR items is greater than 10
    if (forecastItems < MIN_WISHLIST_ITEMS || forecastItems > MAX_WISHLIST_ITEMS) {
    
    //then output this
    printf("ERROR: List is restricted to between 1 and 10 items.\n");
 }
 } while (forecastItems < MIN_WISHLIST_ITEMS || forecastItems > MAX_WISHLIST_ITEMS);

  //creating a for loop so that it keeps looping through the item # 
    
    int r;
    for (r = 0; r < forecastItems; r++) {
        printf("\nItem-%d Details:\n", r + 1);
         //print the following for the cost of item
    do {
        printf("   Item cost: $");
        scanf("%lf", &itemCost[r]);
        //check to see if item number is less than 100.00
         if (itemCost[r] < 100.00) {
         //if it is than print the following statement
            printf("      ERROR: Cost must be at least $100.00\n");
        }
        else {
    //if number entered is greater than 100.00 than add that number into the the total cost and keep doing that until all items are entered
    //save to array for later use.
   totalCost += itemCost[r]; 
            }
        } while (itemCost[r] < 100.00);
        //print the following for the importance of the item
    do {
        printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
        scanf("%d", &importance[r]);
        //check to see if importance number is less than or equal to 0 OR greater than or equal to 4
            if (importance[r] <= 0 || importance[r] >= 4) {
            //if it is than print the following statement
                printf("      ERROR: Value must be between 1 and 3\n");
            }
        } while (importance[r] <= 0 || importance[r] >= 4);

        //print the following to ask if the item has a finacncing option 
    do {
        printf("   Does this item have financing options? [y/n]: "); 
        scanf(" %c", &options[r]);
        //check to see if options is not equal to 'y' OR not equal to 'n' 
        if (options[r] != 'y' && options[r] != 'n') {
            //if it is not than print the following statement
            printf("      ERROR: Must be a lowercase 'y' or 'n'\n"); }
        } while (options[r] != 'y' && options[r] != 'n');
    }
     //printing the final output of all the items
    printf("\nItem Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    //loop through so that it prints the statement below with each of the items and their information
    int s;
    for (s = 0; s < forecastItems; s++) {
        printf("%3d  %5d    %5c    %11.2lf\n",s+1,importance[s],options[s],itemCost[s]); 
    }
        printf("---- -------- -------- -----------\n"); 
        printf("                      $%11.2lf\n\n",totalCost); 

        double yearlyIncome = 12 * netEarnedIncome; 
       
        //forecasting wishlist
         do {
            printf("How do you want to forecast your wish list?\n");
            printf(" 1. All items (no filter)\n");
            printf(" 2. By priority\n");
            printf(" 0. Quit/Exit\n");
            printf("Selection: ");
            scanf("%d", &selection);

            if (selection < 0 || selection > 2){
            printf("\nERROR: Invalid menu selection.\n\n"); }

            if (selection == 0){
                flag = 0;
                printf("\nBest of luck in all your future endeavours!\n");
            }
            if (selection == 1) {
                double totalYears = 0; 
                double totalMonths = 0; 
                int flag2 = 0;

                totalYears = totalCost / yearlyIncome; 
                totalMonths = (int)((totalYears * 12) + 1) % 12;

                printf("\n====================================================\n");
                printf("Filter:   All items\n");
                printf("Amount:   $%1.2lf\n", totalCost);
                printf("Forecast: %d years, %d months\n", (int)totalYears, (int)totalMonths);
                for (s = 0; s < forecastItems; s++) {
                    if (options[s] == 'y') {
                        flag2 = 1;
                    }
                    }
                   
                    if (flag2 == 1) {
                        printf("NOTE: Financing options are available on some items.\n"); 
                        printf("      You can likely reduce the estimated months.\n");
                    }
                    printf("====================================================\n\n");
                    }

            if (selection == 2) {
                    int filterPriority;
                    double filterAmount = 0; 
                    int flag3 = 0, flag4 = 0;  
                    printf("\nWhat priority do you want to filter by? [1-3]: "); 
                    scanf("%d", &filterPriority);

                    while (!flag3) {
                        if (filterPriority < 1 || filterPriority > 3) {
                                printf("    ERROR: Value must be between 1 and 3\n");
                                flag3 = 0;
                                }
                        else {flag3 = 1;
                        }
                    }
            for (s = 0; s < forecastItems; s++) {
                if (importance[s] == filterPriority) {
                    filterAmount += itemCost[s];
                    if (options[s] == 'y') {
                        flag4 = 1;
                    }
                }
            }
            double totalYears2 = 0; double totalMonths2 = 0;

            totalYears2 = filterAmount / yearlyIncome; 
            totalMonths2 = (int)((totalYears2 * 12) + 1) % 12;
            printf("\n====================================================\n");
            printf("Filter:   by priority (%d)\n", filterPriority);
            printf("Amount:   $%1.2lf\n", filterAmount);
            printf("Forecast: %d years, %d months\n", (int)totalYears2, (int)totalMonths2);

            if (flag4 == 1) {
            printf("NOTE: Financing options are available on some items.\n");
            printf("      You can likely reduce the estimated months.\n");
            }
            printf("====================================================\n\n");
            }
         } while (flag==1); 

         return 0;





}