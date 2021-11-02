//Author: Randall Hunt
// Date: 10/06/2021
//Program: Indeces.c
//Description: this program takes in an array from the user and calculates the indice of two numbers in the array
//such that they add up to the key, which is also given by the user.
//the output should be the index of the values that add up to the key
#include <stdio.h>

void find_indices(int a[], int n, int key, int *index1, int *index2); //find_indices function

int main()
{                                              //main function
    int n, i, k;                               //declare varaibles
    int index1, index2;                        //delcare pointers for indices
    printf("Enter the length of the array: "); //ask the user for the length of the array
    scanf("%d", &n);                           //store that value in n

    int a[n]; //declare the array variable

    printf("Enter the elements of the array: "); //ask the user for the elements of the array
    for (i = 0; i < n; i++)                      //loop used to store each value
        scanf("%d", &a[i]);                      //scanning in the values

    printf("Enter the key value: "); //ask the user for the key
    scanf("%d", &k);                 //store the key in k

    find_indices(a, n, k, &index1, &index2);    //call the function to find the values
    printf("Output: %d %d \n", index1, index2); //print the two values
    return 0;                                   //end the program
}

void find_indices(int a[], int n, int key, int *index1, int *index2)
{                          //function used to find the indices
    int *p, *q;            //poitners used for the loop
    int temp1 = -1, temp2; //temp variables to store the indices
    for (p = a; p < a + n; p++)
    {              //for loop for the first value
        temp1++;   //increment the temp for the first index
        temp2 = 0; //initialize the second temp variable for index 2
        for (q = a + 1; q < a + n; q++)
        {            //for loop for second value
            temp2++; //increment temp2 for the second index
            if (*p + *q == key)
            {                    //if the values of the indexes match the key
                *index1 = temp1; //store the value of the first index into index1
                *index2 = temp2; //store the value of the second index into index2

                return; //end the function
            }
        }
    }
}