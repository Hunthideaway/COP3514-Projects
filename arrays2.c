//Randall Hunt
//Program: arrays2.c
//description: This program check if two arrays of the same length match after some number of shifts on the first array.
//date: 9/14/2021

#include <stdio.h>//include for printf and scanf 

void shift(int first[], int n)//shift function to shift the numbers 
{
    int temp = first[0], i;//declare variables 

    for (i = 0; i < n - 1; i++)//for loop 

        first[i] = first[i + 1];//moving numbers 

    first[n - 1] = temp;//moving numbers
}

int main()//main 
{

    int n, i = 0;//declare variables 
    int count =0;//declare variables 

    printf("Enter the length of the input arrays: ");//ask the user for the array length 
    scanf("%d", &n);//scan that value 
    if (n > 0)//ensure that it is greater than 0
    {
        int first[n], second[n];//delcare the arrays

        printf("Enter the elements for the first array: ");//ask the user for the first array values 
        for (int i = 0; i < n; i++)//scan all of them 
            scanf("%d", &first[i]);//scan and store

        printf("Enter the elements for the second array:  ");//ask the user for the second array values 
        for (int i = 0; i < n; i++){//loop to scan them all 
            scanf("%d", &second[i]);//scan and store 
        }

            for (i = 0; i < n; i++)//for loop to continue for all values 
            {
                if (first[i] != second[i])//if the values don't match 
                {
                    shift(first, n);//shift them 
                }
                
                count++;//increase the counter 

                while (count == n)//if the counter reaches the length for the array
                {
                    for(i=0; i<n; i++){//for loop to varify all values 
                    if (first[i] != second[i])//if they values do not equal 
                    {
                        char result = 'F';//F = false 
                        printf("Output: %c\n", result);//print the out come 
                        return 0;//end the program 
                    }
                    else if (first[i] == second[i])//if the values equal 
                    {
                        char result = 'T';//T = True 
                        printf("Output: %c\n", result); //print out the out come 
                        return 0;//end the program 
                        
                    }
                    
                    }
                }
            }
    }
    else if (n < 1)//if the user enters value less than 1 
    {
        printf("Invalid input!!");//inform them that the input is invalid 
    }

    return 0;//end the program 
}