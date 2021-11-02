/* Author: Randall Hunt 
Program: STR.c 
Description: This program calculates the number of times that a STR is repeated in a DNA sequence provided in a file. 
*/ 
//Includes
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>  
//Count the str repeats. 
int count_repeats(char*sequence, char*str) {
//declare the variables that will be used within the program. 
int i, j, k, y, count = 0; 
//loop that counts the repetition. 
for( i = 0; i <= strlen(sequence) - strlen(str); i++) {
j = 0; 
y = 0; 

if(sequence[i] == str[j])
{
for(k = i; j <= strlen(str) - 1; k++, j++) {
if(sequence[k] != str[j]){
y = 1; 
break; 

}
}
//add 1 to the number of repeated sequences found. 
if(y == 0) { 
count = count + 1; 
}
}

}
//return the count that was found. 
return count; 

}

//main function. 
int main() {
//declare the variables and their limits. 
char str[100], file_name[100], sequence[20000]; 
int q; 
//file pointer.
FILE *fptr; 
//ask the use to enture the file name that will be opened. 
printf("Enter the file name to open: "); 
scanf("%s", file_name); 
//if the file cant be opened let the user know and exit the program. 
if((fptr = fopen(file_name, "r")) == NULL) {
printf("Error opening file!"); 
exit(1); 

}

fscanf(fptr, "%[^\n]", sequence);
//ask the user to enter the string to search for and scan for it. 
printf("Enter string to search ");
scanf("%s", str);

q = count_repeats(sequence,str);
//let the user know the amount that the sequence was repeated. 
printf("The occurence was found %d time",q);
//return
return 0;
}



