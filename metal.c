//Author: Randall Hunt 
//Program: metal.c
//Description: This program scans two arrays and outputs the number of matching characters. 
//Date: 10/14/2021

#include <stdio.h>
#define MAX 1001 //define the maximum length for the characters, include 1 extra for the null pointer.

int count(char *s1, char *s2);   //refernece for main
int read_line(char *str, int n); //reference for main

int main() //main
{

    char s1[MAX], s2[MAX]; //variables to store the string arrays

    printf("Enter s1: "); //ask the user to enter the first string
    read_line(s1, MAX);   //use read line to store the values

    printf("Enter s2: "); //ask the user for the second string array
    read_line(s2, MAX);   //use read line to store the values

    count(s1, s2); //call the count function

    return 0; //end the program
}

int count(char *s1, char *s2) //count function
{

    char *i;      //pointer for s1
    char *j;      //pointer for s2
    int size = 0; //stores the size of the matching characters

    for (i = s1; *i != '\0'; i++)
    { //loop for s1
        for (j = s2; *j != '\0'; j++)
        {                 //loop for s2
            if (*i == *j) //if the characters are the same
                size++;   //increase the size
        }
    }

    printf("Output: %d \n", size); //print the size
    return 0;                      //end successfully
}

int read_line(char *str, int n) //read line given my instrcutor. Used to take in characters in string.
{

    int ch, i = 0;
    while ((ch = getchar()) != '\n')
    {
        if (i < n)
        {
            *str++ = ch;
            i++;
        }
    }
    *str = '\0';
    return i;
}