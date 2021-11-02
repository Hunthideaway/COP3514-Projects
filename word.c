//Author: Randall Hunt
//Progream: word.c
//Description: this program validates a word by filtering through the users input to ensure all characters are alphabetic letters.
//Date: 09/09/2021
//include
#include <stdio.h>

int main() //main
{
    char string[20], character;//string stores the string entered by the user, character will be used to store each value. 
    int i = 0;
    printf("Please enter a phrase to be validated. ");//inform the user to enter a phrase 
    printf("\nInput: ");//ask the user for their input 
    character = getchar();//character is used to reference the character in a string, using getchar()

    while (character != '\n')//process continues as long as it has reached the end of the line, or new line, or enter. 
    {
        if ((character >= 97 && character <= 122) || (character >= 65 && character <= 90))//validates if the character is a alphabetic letter
        {

        string[i] = character;//refers back to the string 
        i++;//moves to the next character
        character = getchar();}//gets the next character
         else//if the character does not matc the list given 
        {
            printf("Output: Invalid ");//tell the user the input is invalid 
            return 0;//return, ending the process 
        }
    }
    string[i] = '\0'; //signifies the end of the string. 
    printf("Output: %s valid\n", string);//prints the string and that its valid. 

    return 0; //return
}