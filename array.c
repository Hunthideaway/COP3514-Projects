/* 
Author: Randall Hunt 
Program: array.c 
Desrciption: Suppose you are given an array, the program should insert a number x and rearange the array
so that all the elements are less than or equal to x are before x. 
*/ 
#include <stdio.h>
//re-arange function. 
void rearange(int *a, int n, int insert, int *b)
{
    //decalre the other variables that will be used within the program. 
    int *c = a;
    int i; 
    //add the number to the array that is less than or equal to the insert number. 
    for(i=0; i<n; i++)
    {
        int y = *a;
        if (y <= insert)
        {
            *b = y;
            *b++;
        }
        *a++;
    }
    //add the insert number.
    *b = insert; 
    *b++; 
    //add the number to the array if the array is greater than the insert number. 
    for(i=0; i<n; i++)
    {
        int y = *c;
        if(y>insert)
        {
            *b = y; 
            *b++;
        }
        *c++;
    }
}

//main function.
int main()
{
    //declare the variables that will be used within the function. 
    int n, insert, a[n], b[n], i;
    //ask the user to enter the length of the array. 
    printf("Enter the length of the array: ");
    //store the value of the length of the array. 
    scanf("%d", &n);
    //ask the user to enter the elements of the array. 
    printf("Enter the elements of the array: ");
    //store the array given by the user.
    for(i=0; i<n; i++)
    scanf("%d", &a[i]);
    //ask the user to enter the number to be inserted within the array. 
    printf("Enter the number for insertion: ");
    //store the number that will be inserted. 
    scanf("%d", &insert);
//call the rearange function created before the main function. 
rearange(a, n, insert, b);
//print the output of the re-aranged array. 
printf("Output: ");
for(i=0; i<n+1; i++)
printf("%d ",b[i]);

    return 0;
}

