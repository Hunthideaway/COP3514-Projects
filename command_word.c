// Author: Randall Hunt
// Program: command_word.c
// Description: This program is an extension of program 2 section 2. It validates the word from the command line.
// Date: 10/14/2021

#include <stdio.h>
#include <string.h>

int validate(char *word); // validate function

int main(int argc, char *argv[]) // main function
{

    if (argc != 2)                                                    // if there are more than or less than 2 arguments
        printf("Incorrect number of arguments. Usage ./a.out word "); // tell the user that it is the incorrect number of arguments
    else                                                              // else
    {
        int res;                 // variable to store the returned value
        res = validate(argv[1]); // store the returned value
        if (res == 0)            // if the return value is 0 then invalid
            printf("Invalid\n"); // invalid
        else                     // else
            printf("Valid\n");   // valid
    }
    return 1; // end the program
}

int validate(char *word) // function to validate the word.
{
    int i, f = -1;                                     // variables for the function, set f=-1 so that it is initialized but isnt one of the return values. 
    if (*(word + 0) >= 'A' && *(word + 0) <= 'Z')      // if the user enter upercase letters
        f = 0;                                         // f = 0;
    else if (*(word + 0) >= 'a' && *(word + 0) <= 'z') // if the user enters lowercase letters
        f = 1;                                         // f = 1;

    for (i = 1; *(word + i) != 0; i++) // for loop for all characters within the array, start at the second index since we already compared the first. 
    {

        char ch = *(word + i);                // set the character to a variable
        if (f == 0 && ch >= 'A' && ch <= 'Z') // if f=0 and the character is upper case then continue comparing
        {
            continue; // continue
        }
        else if (f == 1 && ch >= 'a' && ch <= 'z') // if f=1 and the character is lower case then continue comparing
        {
            continue; // continue
        }
        else // default else
        {
            return 0; // return 0;
        }
    }

    return 1; // is all passes then return 1;
}
