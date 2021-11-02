/* 
Author: Randall Hunt 
Program: command_phone.c
Description: This program is a modificaton of a previous program. It will be capable of using the phone number as a command line argument. 
Example: ./a.out 727-PET-CARE
Output: 727-738-2273
*/  


#include <stdio.h> 
#include <stdlib.h> 

//void function to translate the phone number given by the user. 
void translate(char *word, char *phone_number) 
{ 
//decalre the variables that will be used. 
int i=0, j=0; 
char alphabet, number; 
while(word[i] !='\0') 
{
alphabet = word[i]; 
//add the dashed between every set of 3 numbers.
if(j == 3 || j == 7) 
{
phone_number[j] = '-';
j++;
}
//if the characters given are between 0 and 9 then continue without translating. 
if(alphabet >= '0' && alphabet <= '9') 
{
phone_number[j] = alphabet; 
j++;
i++;
continue; 
}
     //use the switch function to convert the variables to numbers.  
     switch(alphabet) 
{ 
    //declare the letters that convert to 2. 
    case'A': 
    case'B':  
    case'C': 
    number='2'; 
    break; 
    //declare the letters that convert to 3. 
    case'D':  
    case'E': 
    case'F': 
    number='3'; 
    break; 
    //declare the letters that convert to 4.  
    case'G': 
    case'H': 
    case'I': 
    number='4';  
    break;  
    //declare the letters that convert to 5.  
    case'J': 
    case'K': 
    case'L': 
    number='5'; 
    break;  
    //delare the letters that convert to 6. 
    case'M': 
    case'N': 
    case'O': 
    number='6'; 
    break; 
    //declare the letters that convert to 7. 
    case'P': 
    case'Q': 
    case'R': 
    case'S': 
    number='7'; 
    break; 
    //declare the lettes that convert to 8. 
    case'T': 
    case'U':
    case'V': 
    number='8'; 
    break; 
    //declare the letters that convert to 9. 
    case'W': 
    case'X': 
    case'Y': 
    case'Z': 
    number = '9';
    break;  
    //case for the '-', 
    case'-':
    number= '0';
  break;
  }
  //skip the '-' 
 if(number =='0') {
 i++;
 continue;
 } 
//add the numbers to the phone number that is being translated.
   phone_number[j]= number;
   i++;
   j++;  
}
//stop the string from continuing.
phone_number[j] = '\0';
}
int main(int argc, char *argv[]) {
//verify that there is not two arguments and if there is then inform the user that the input is wrong. 
if(argc !=2) 
{
//inform the user that the number they gave was not within the parameters. 
printf("Output: Incorrect number of arguments. Usage ./a.out phoneNumber"); 
return 0;
} 
//create the pointers for the phone number given and the transaltion of it. 
char *word = argv[1]; 
//Memory allocation. 
char *phone_number = malloc(13);
//call the function translate. 
translate(word, phone_number);
//display the phone number that it translated. 
printf("%s", phone_number); 
//deallocate allocated memory using the free() function.
free(phone_number); 

}



