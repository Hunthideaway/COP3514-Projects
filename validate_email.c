/* Author: Randall Hunt
Program: validate_email.c
Description: This program validates that the email address entered by the student or individual is a school domain program, the program ends in edu, in order for the individual to recieve the discount. 

*/

#include <stdio.h> 

void read_line(char *x)
{
//ask the user for the input of the email address using the read_line function. 
printf("Input: "); 
scanf("%s", x);

}

//validate the email given by the user is within the domain required. (.edu) 
int validate(char *s1) 
{
//declare the variables that will be used within the program. 
int i, a, b; 
a=0; 
b=0; 
//make sure that the email address ends with edu. 
for(i=0; s1[i]!='\0'; i++) 
{
a++;
}
//check the last 3 digits of the email. 
for(i=0; i<a; i++)
{
if(i==a-3)
{
//make sure that the first letter the email ends with is 'e'. 
if(s1[i]=='e')
{
b++;
}
}
if(i==a-2)
{
//the second to last letter at the end of the email is 'd'. 
if(s1[i]=='d')
{
b++; 
}
}
if(i==a-1)
{
//make sure that the last letter in the email is 'u'.
if(s1[i]=='u')
{
b++;
}
}

}
//validate that b in-fact equals 3, which will mean that the email ends with edu. 
if(b==3)
{
//the email ends with edu.
a=1; 
}
else 
{
//the email does not end with edu. 
a=0; 
}

//return a
return a; 
}

//main function. 
int main()
{
//declare the web address with a limit of 1000 characters as given in the project parmeters. 
char web_address[1000];
//daclare the varaibles that will be used within the program. 
int r; 
//call the function of read_line in order to take the email address from the user. 
read_line(web_address); 
//validate the web address is within the parameters given.
r=validate(web_address); 
//if the value returned is 1 then print "Verification Successful". 
if(r==1)
{
printf("Verification Successful!"); 
}
//if the value returned if 0 then print "not eligible for discount code". 
else if(r==0)
{
printf("Not Eligible For Discount Code!!"); 
}
//return 0. 
return 0; 
}






















