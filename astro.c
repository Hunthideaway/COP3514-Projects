//working with 2d arrays 
#include <stdio.h> 
#include <string.h> 
#define INPUT_LEN 100 
#define NUM_PLAN 12

int read_line(char *str, int n);

int main(){
//pointer 2d array 
    char *astro[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto", "Sirius", "Betelgeuse", "Rigel"};

    char input[INPUT_LEN +1];
    int i, j, flag = 0; 

    printf("Enter an asstronomical body: ");
    int n = read_line(input, INPUT_LEN);

    for(i=0;i<n && !flag; i++) {
        for(j=0; j < NUM_PLAN; j++) {
            if(!strcmp(input,astro[j])){
                printf("%s is an astronomical body %d.", input, j+1); //shows the index of the string 
                flag = 1; 
                break; 
            }
            else if( j == NUM_PLAN - 1 && i - n - 1) {
                printf("Sorry %s, is not an astronomical body.", input);
                flag = 1; 
                break; 
            }
        }
    }



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

