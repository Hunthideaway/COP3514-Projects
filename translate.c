/* 

Title: Translate  

Author: Randall Hunt  

Description: This program converts phones numbers that are given with numbers and letters, such as (813)-AIR-PORT, to the  

phone number that must be dialed into a phone. --> (813)-247-7678. 

*/ 

 

#include <stdio.h> 

 

int main() 

{ 

 //delcare the variable that will be used to store the phone number characters. 

 char alphabet=(""); 

 //ask the user for the phone number they would like to translate.  

 printf("Enter the phone number: "); 

 /*use the while function to read to input from the user and returns the same value if the input value is already a number*/ 

 while(alphabet !='\n') 

 { 

     //declare the variable that is used to store the variable. 

     alphabet = getchar(); 

     //use the switch function to convert the variables to numbers.  

     switch(alphabet) 

{ 

    //declare the letters that convert to 2. 

    case'A': 

    case'B':  

    case'C': printf("2"); 

    break; 

    //declare the letters that convert to 3. 

    case'D':  

    case'E': 

    case'F': 

    printf("3"); 

    break; 

    //declare the letters that convert to 4.  

    case'G': 

    case'H': 

    case'I': 

    printf("4");  

    break;  

    //declare the letters that convert to 5.  

    case'J': 

    case'K': 

    case'L': 

    printf("5"); 

    break;  

    //delare the letters that convert to 6. 

    case'M': 

    case'N': 

    case'O': 

    printf("6"); 

    break; 

    //declare the letters that convert to 7. 

    case'P': 

    case'Q': 

    case'R': 

    printf("7"); 

    break; 

    //declare the lettes that convert to 8. 

    case'S': 

    case'T': 

    case'U': 

    printf("8"); 

    break; 

    //declare the letters that convert to 9. 

    case'W': 

    case'X': 

    case'Y': 

    case'Z': 

    printf("9"); 

    break;  

    //use default to print out the numbers for the program.  

    default: 

    printf("%c", alphabet); 

    break;  

     

} 

     

} 

   return 0;  

} 