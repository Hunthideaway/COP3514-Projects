//Author: Randall Hunt 
//Program: Arrays.c
//Descirption: This program finds the duplicate number within the array. 
#include <stdio.h>

void find_duplicates(int *a, int n, int *b, int *size); //find_duplicate function 
int main() //main function 
{
    int i; //variable for loop 
    int n; //variable for length of array 
    
    printf("Enter the size of the array: "); //ask the user for the length of the array
    scanf("%d", &n); //scan in the number 
    int a[n]; //variable to hold the array 
    printf("Enter %d array elements: ", n); //ask the user to enter the values for the array 
    for (i = 0; i < n; i++) //for loop to scan in all values 
        scanf("%d", &a[i]); //store all the values 
    
    int b[n/2]; //variable to hold the matching values 
    int size; //variable for the size of the array 
    find_duplicates(a, n, b, &size); //call the function 
    for(i =0; i<size; i++)//print out all values that match 
    printf("Output: %d\n", *(b+i)); //printing values to screen 
    printf("Size: %d\n", size); //print the size of the array 


    return 0; //end program 
}
void find_duplicates(int *a, int n, int *b, int *size) { //find_duplicate function 
    *size = 0; //initiate the size 
    int *p, *q;  //variables for the loops 
    for(p = a; p < a+n; p++){ //loop for the first value 
        for(q = p+1; q<a+n; q++) { //loop for the second value 
            if(*p == *q) { //if they match 
               *(b++) = *p; //add p to the array 
               *size+=1; //increase the size 
            }

        }

    }

}