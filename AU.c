/* Author: Randall Hunt
Program: Convert AU 
Description: This program converts astronomical units to kilometers and miles. 
*/ 

#include <stdio.h>

//define what pie is
#define PI 3.1415


int main()
{
double rad;
printf("Enter the radius in kilometers (km): ");
scanf("%lf", &rad); 

//eaquation for the volume
double volume = (4.0/3.0)*PI * (rad * rad *rad);
printf("The volume of your astronomical body is %lf km^3. \n", volume);


return 0;
}
