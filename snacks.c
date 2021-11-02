//Author: Randall Hunt 
//Program: snacks.c 
//Description: This program is intended to calculate the price of snacks for a group of 10. The total is output showing how much it will be for each person. I have included a calculator for cash amount and change. 
//Date: 09/09/2021
//include standard library 
#include <stdio.h>
//main function
int main()
{
    int choice;//used to store the choice of the user 
    float total;//use to calculate the total

    printf("Please select from the list: \n");//ask the user to select from the list
    printf(" 1. Energy bars-$3.99/box \n 2. Candy bars-$2.39 /box \n 3. Chips -$4.79/bag \n 4. Pretzels-$2.99/bag \n 5. Popcorns-$3.50 /bag \n 6. Energy drinks-$4.99/half dozen");//display list
    printf("\nPlease enter 0 when you are finished with your selection:  ");//inform the user to enter 0 when finished
    printf("\nEnter Selection: ");//ask the user for their selection
    scanf("%d", &choice);//store their selection 
    
    while (choice != 0)//make sure the user did not ensure 0 
    {
        switch (choice)//switch statement for the selection. 
        {
        case 1://selection 1 
        { //energy bars
            int ebars;
            printf("Enter number of boxes($3.99/energy bar): ");//ask the user to enter the amount 
            scanf("%d", &ebars);//store the amount entered 
            total += 3.99 * ebars;//calculate the amount and add it in total
            break;//break
        }

        case 2: //candy bars
        {
            int cbars;
            printf("Enter number of boxes($2.39/candy bar): ");//ask the user to enter the amount 
            scanf("%d", &cbars);//store the amount entered 
            total += 2.39 * cbars;//calculate the amount and add it in total
            break;//break
        }

        case 3: //chips
        {
            int chips;
            printf("Enter the number of bags($4.79/chip bag): ");//ask the user to enter the amount 
            scanf("%d", &chips);//store the amount entered 
            total += 4.79 * chips;//calculate the amount and add it in total
            break;//break
        }

        case 4: //pretzels
        {
            int pretz;
            printf("Enter the number of bags($2.99/pretzel bag): ");//ask the user to enter the amount 
            scanf("%d", &pretz);//store the amount entered 
            total += 2.99 * pretz;//calculate the amount and add it in total
            break;//break
        }

        case 5: //popcorn
        {
            int popcorn;
            printf("Enter the number of bags($3.50/popcorn bag): ");//ask the user to enter the amount 
            scanf("%d", &popcorn);//store the amount entered 
            total += 3.50 * popcorn;//calculate the amount and add it in total
            break;//break
        }

        case 6: //energy drinks
        {
            float drink;
            printf("Enter then number of drinks in mutliples of 6.($4.99/half dozen): ");//ask the user to enter the amount 
            scanf("%f", &drink);//store the amount entered 
            total += 4.99 * (drink/6);//calculate the amount and add it in total
            break;//break
        }

        default://default encase the user does not enter a valid selection 
            printf("Please enter a valid selection: ");//inform them 
        }
        printf("Enter a selection or enter 0 to terminate: ");//ask them to enter another selction or enter 0 to stop 
        scanf("%d", &choice);//store their choice 
    }

    printf("The total for your selections is: $%.2lf", total);//print the total 
    printf("\nEach person must pay: $%.2f", total/10);//print the total for each person

    float cash;//extra: stores the amount of cash from the user 

    //ask the customer to enter the amount of cash they are paying for the items with and store it.

    printf("\nEnter cash received: ");//ask the user to enter the amount of cash 

    scanf("%f", &cash);//store cash 

    //print out the change with will be given to the user.
    if(cash - total < 0 ){//if the user enters a value less than total
        printf("You do not have enough money!!");//tell them they do not have enough 

    }
    else {
    printf("Your change is: $%.2f", cash - total);//print the amount of change the user gets back. 
    }

    return 0;//return 
}