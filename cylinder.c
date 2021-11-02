/* 
Author: Randall Hunt 
Program: cylinder.c 
Descritpion: This program reads the value for the radius and hieght of a solid cyclinder using two variables to
calculate the surface area and volume of the cylinder. 
*/ 
#include <stdio.h>
#include <stdlib.h>
//define the variable pi to be used within the equations. 
#define pi 3.141592

//create the equations that will be used to find the area and the volume. 
    void area_volume(double radius, double height, double *pointer_area, double *pointer_volume){
        //area equation.
        *pointer_area = (2*pi*radius*height) + (2*pi*radius*radius);
        //volume equation. 
        *pointer_volume = pi*height*radius*radius; 
    }

//main function. 
int main()
{
//decalre the variables that will be used within the program. 
double height, radius, area_total, volume_total; 
    //ask the user to enter the radius of the cylinder. 
    printf("Enter the radius of the cylinder: ");
    //store the number entered by the user to the proper variable. 
    scanf("%lf", &radius);
    //ask the user to enter the height of the cylinder. 
    printf("Enter the height of the cylinder: ");
    //store the number entered by the user to the proper varaible.
    scanf("%lf", &height);
    //plug the variables in from the user to the equations. 
    area_volume(radius, height, &area_total, &volume_total); 
    //print out the area and volume for the user. 
    printf("Output: The volume of the cylinder is %0.3f and the area is %0.3f", volume_total, area_total); 
    
    return 0;
}

