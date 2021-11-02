/*
Author: Randall Hunt 
Program: USF_emails.c 
Decsription: This program calls a text file containing emails to add all usf.edu emails to another file. 
Date: 10/27/2021 
*/

#include <stdio.h>
#include <string.h> 
#define MAX 2001 //MAX + 1, 

int is_USF_email(char *email); //verification function 

int main() //main function 
{   
    char file[101]; //variable for the file name 
    char string[MAX]; //content of the document
    printf("Enter file name: "); //ask the user for the file name
    scanf("%s", file); //store the file name within file 
    FILE* pFile; //create a variable for the file 
    pFile =fopen(file, "r"); //set the file equal to the file name and desired mode 
    if(pFile ==NULL) //if the file can not be opened 
    {
        printf("Error opening file!!"); //inform the user 
        return 1; //end 
    } 
    char newF[MAX] = "USF_"; //variable for the new file with USF at the front 
    strcat(newF, file); //concat the old file opened to the new file with USF at the front 
    
    FILE* outPut; //create an output file to store all the verified emails 
    outPut= fopen(newF, "w"); //set output file to the new file and desired mode 
        if(outPut ==NULL) //if the file can not be opened 
    {
        printf("Error opening file!!"); //inform the user 
        return 1; //end 
    }
    
    while(fgets(string, MAX, pFile)!= NULL){ //while loop to travers through the entire text document
    
      if(is_USF_email(string)) { //if the string is verified 
        fputs(string, outPut); //put the string within the outPut file 
    }

    }
    printf("Output File name: %s", newF); //dispaly the name of the newly created file 
    fclose(pFile); //close the original file 
    fclose(outPut); //close outPut file 

    return 0; //end 
}


int is_USF_email(char *email) //email verification function 
{
    if(strstr(email, "usf.edu") != NULL) //checking to see if the email has usf.edu within it
    return 1; //return 1 is it does, true 

    return 0; //return 0 other wise, false 
} 