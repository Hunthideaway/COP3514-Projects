/* 
Program:encode.c
Author:Randall Hunt 
Description: This program replaces the numbres in an integer array with each number's index in the key array. 

*/

#include <stdio.h>
//declare the variables that will be used within the encode program. 
void encode(int x[], int y[], int codex[], int number)
{
//decalre the variables that will be used for the loop. 
int i, j; 
//use the array function. 
for(i=0; i<number; i++)
//make sure that parameters for the length of the coded array is set. 
  for(j=0; j<10; j++)
    if(x[i] == codex[j])
    y[i] = j; 
}

//main function. 
int main()
{
//declare the variables that will be used within the main function. 
int number; 
int x[100]; 
int y[100];
int codex[10]; 
int i; 

//ask the user for their desired size of the array. 
printf("Enter the size of the input array. "); 
scanf("%d", &number); 
//ask the user for the numbers that they would like to use. 
printf("Enter the number: "); 
for(i=0; i<number; i++)
scanf("%d", &x[i]); 
//ask the user for the key array. 
printf("Key Array: "); 
for(i=0; i<10; i++) 
scanf("%d", &codex[i]);
//call the values within the encode function to verify the input values and process the encoding. 
encode(x , y, codex, number); 
//print out the values for the user. 
printf("Output: "); 
for(i=0; i<number; i++)
 printf("%d", y[i]); 
 return 0; 

}









