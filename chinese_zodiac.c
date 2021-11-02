//Author: Randall Hunt
//Prgram: chinese_zodiac.c
//Description: this program is used to calculate the naimal sign for a year of birth entered by the user.
//Date: 08/31/2021

#include <stdio.h> //include the standard libraries

int main()
{ //main

    int year; //variable to store the year
    int sign; //variable to store the calculations that will be used for the sign

    printf("This program will show you which Chinese Zodiac sign you are.\n"); //inform the user of the program

    printf("Enter the year you were born: "); //ask the user for their birth year
    scanf("%d", &year);                       //scan the number

    sign = year % 12; //calculate the ramainder that will be used for the sign.

    if (year <= 0)  //this if statement ensures that an input of 0 or less is not allowed, being that 0 would normally correspond to the year of the Monkey. 
    {
        printf("Invalid Input!!!"); //print findings to user. 
    }
    else
    {
        switch (sign)
        {                                                         //switch function is the most efficent in this case to identify the sign.
        case 11:                                                  //case for the sheep
            printf("The animal sign for %d is the Sheep.", year); //print results
            break;                                                //break is this is the correct sign.

        case 10:                                                  //case for the horse
            printf("The animal sign for %d is the Horse.", year); //print results
            break;                                                //break is this is the correct sign.

        case 9:                                                   //case for the snake
            printf("The animal sign for %d is the Snake.", year); //print results
            break;                                                //break is this is the correct sign.

        case 8:                                                    //case for the dragon
            printf("The animal sign for %d is the Dragon.", year); //print results
            break;                                                 //break is this is the correct sign.

        case 7:                                                    //case for the rabbit
            printf("The animal sign for %d is the Rabbit.", year); //print results
            break;                                                 //break is this is the correct sign.

        case 6:                                                   //case for the tiger
            printf("The animal sign for %d is the Tiger.", year); //print results
            break;                                                //break is this is the correct sign.

        case 5:                                                //case for the ox
            printf("The animal sign for %d is the Ox.", year); //print results
            break;                                             //break is this is the correct sign.

        case 4:                                                 //case for the rat
            printf("The animal sign for %d is the Rat.", year); //print results
            break;                                              //break is this is the correct sign.

        case 3:                                                 //case for the pig
            printf("The animal sign for %d is the Pig.", year); //print results
            break;                                              //break is this is the correct sign.

        case 2:                                                 //case for the dog
            printf("The animal sign for %d is the Dog.", year); //print results
            break;                                              //break is this is the correct sign.

        case 1:                                                     //case for the rooster
            printf("The animal sign for %d is the Rooster.", year); //print results
            break;                                                  //break is this is the correct sign.

        case 0:                                                    //case for the monkey
            printf("The animal sign for %d is the Monkey.", year); //print results
            break;                                                 //break is this is the correct sign.

        default:                        //default case
            printf("Invalid Input!!!"); //print this output if non of the cases are met.
        }
    }

    return 0; //return statement.
}