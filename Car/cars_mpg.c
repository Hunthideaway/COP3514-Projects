/*
Author: Randall Hunt 
Program: cars_mpgs.c
Description: This program reads in a file selected by the user, pertaining to the format given. The information within 
the file describes a vehicle and its fuel economy. The program then stores the vehicles with the highest or best city fuel 
economy and sorts them. 
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CAR 51 //define the elements length 
#define MAX 6000 //define the largest possible amount of cars allowed 
struct car //struct to store the cars variables 
{
    char ID[CAR]; //identification for the car 
    char class[CAR]; //classification for the car 
    char engine[CAR]; //engine type 
    char trans[CAR]; //transmission type 
    int city; //city millage 
    char fuel[CAR]; //fuel type 
    int highway; //highway millage 
};

void sort_city_mpg(struct car list[], int n); //function to sort the cars 
void swap(struct car *a, struct car *b); //swap function to sort the list 

int main() //main function 
{   
    struct car c[MAX]; //variable array to store the cars information 
    struct car large[MAX]={0}; //variable array to store the vehicle with the larest city millage, with all elements initialized to 0 
    char file[CAR]; //variable to store the user entered file name 
    printf("Enter the file name: "); //ask the user for the file name 
    scanf("%s",file); //scan in the users enter string
    FILE* open; //create a file 
    open = fopen(file,"r"); //read the file 

    int index=0; //variable for the index of the file and initialized to 0 
    do{ //scan all elements and store them within the proper elements from the file 
    fscanf(open, "%[^,], %[^,], %[^,], %[^,], %d, %[^,], %d\n", c[index].ID, c[index].class, c[index].engine, c[index].trans, &c[index].city, c[index].fuel, &c[index].highway);
    index++; //increment 
    }
    while(!feof(open)); //stop once you reach the end of the file 
    fclose(open); //close that file 

    int i, j; //variales for the loop 
    for(i=0; i<index;i++){ //increment through the user file 
        for(j=0; j<10; j++){ //increment through the array holding the largest city fuel economy
        if(c[i].city > large[j].city){ //compare the user file vehicles fuel economy to that which is in the large array 
                large[j] = c[i]; //if city is larger than an element within the array, replace that element 
                break; //break, since we dont want that element in every position 
            }
        }
    }

    sort_city_mpg(large, j); //call the sort function for the top 10 
    FILE* output; //create an output file 
    output = fopen("Top10_city_mpg.csv", "w"); //open the file with permissions to wright 

    for(i=0;i<10; i++){ //for every element within the large array 
        fprintf(output, "%s, %s, %s, %s, %d, %s, %d\n", large[i].ID, large[i].class, large[i].engine, large[i].trans, large[i].city, large[i].fuel, large[i].highway );
    } //print the elements to the file 

    printf("Output file name: Top10_city_mpg.csv\n"); //inform the user what the name of the file is
    fclose(output); //close that file 


    return 0; //close the program 
}

void sort_city_mpg(struct car list[], int n) //sort function 
{

    int i, j, min_idx; //variables for the loops and index 
    for (i = 0; i < n - 1; i++) //for loop to compare elements 
    {
        min_idx = i; //index varaible initiated 
        for (j = i + 1; j < n; j++) //for loop to compare elements 
        {
            if (list[j].city < list[min_idx].city) //if the city fuel economy is smaller 
                min_idx = j; //set it to the min 
        }
    }
    swap(&list[min_idx], &list[i]); //call the swap function 
}

void swap(struct car *a, struct car *b) { //swap function 
struct car temp = *a; //temp variable to store the value of a 
*a = *b; //a stores the value of b 
*b = temp; //b stores the value of temp which is a 
}