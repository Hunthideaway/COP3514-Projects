//this compares the length of two names and outputs which is longer 
#include <stdio.h> 
#include <string.h> 
#define NAME_LEN 69

int read_line(char *str, int n); 

int main() {

    char name1[NAME_LEN+1], name2[NAME_LEN+1]; 
    printf("Enter the first persons name: ");
    read_line(name1, NAME_LEN);
     printf("Enter the second persons name: ");
    read_line(name2, NAME_LEN);

    if(!strcmp(name1, name2)) 
        printf("The names are the same length. ");
    
    else if(strlen(name1) > strlen(name2))
        printf("Name 1 is longer than name 2. ");
    
    else if(strlen(name1) <strlen(name2))
        printf("Name 1 is shorter than name 2.");

    else 
        printf("names are the same length, but different characters."); 

    return 0; 
}

int read_line(char *str, int n) { 

    int ch, i =0; 
    while((ch = getchar()) != '\n')
    {
            if(i<n) 
            {
                *str++ = ch; 
                i++; 
            }

    }
*str = '\0'; 
return i; 
}