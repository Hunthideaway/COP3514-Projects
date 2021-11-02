//Author: Randall Hunt
//Program: arrays1.c
//description: write a prgram that finds all the integers in the range [1,n] , where n is given, that do not appear in a.
//date: 09/14/2021

#include <stdio.h> //include statement for printf and scanf

void findPoints(int a[], int n, int b[]) //void findPoint for calculations on which numbers are not given
{
    int i = 0, j, k = 0; //declare the variables that will be used within the program

    for (i = 1; i <= n; i++) //for loop searching for a missing number
    {
        for (j = 0; j < n; j++) //for loop searching for a missing number
        {
            if (i == a[j]) //break if the element is found
                break;     //break
        }
        if (j == n)
        {             //if the element is not found we store the value of the aray in b
            b[k] = i; //storing that value
            k++;      //indexing b, moving on to the next item
        }
    }
    printf("The output is: "); //dispaly the given final message for the output

    for (i = 0; i < k; i++)  //loop to show all characters in the final array
        printf("%d ", b[i]); //display the values
}

int main() //main function
{
    int n, i = 0; //declare the varaibles that will be used

    printf("Enter the length of the input array: "); //ask the uer for the length of the array the will use
    scanf("%d", &n);                                 //scan that value
    if (n < 1)
    {                                  //ensure that no values are less than 1
        printf("Not a valid input!!"); //inform the user
        return 0;                      //end the program
    }

    while (i < n)
    { //continues as long as i is less than n

        int a[n], b[n]; //declare the arrays that will be used, n being the length of the array input by the user
        if (n > 0)
        {
            printf("Enter the elements of the input array: "); //ask the user for the numbers that will be used

            for (i = 0; i < n; i++)
            {                       //for loop that scans in all values
                scanf("%d", &a[i]); //storing the data
                if (a[i] < 1 || a[i] > n)
                {                                  //ensure no values are less than 1 or greater than the array number
                    printf("Not a valid input!!"); //inform the user
                    return 0;                      //end the program
                }
            }

            findPoints(a, n, b); //call the function to calculate the missing numbers
        }
    }

    return 0; //return
}
