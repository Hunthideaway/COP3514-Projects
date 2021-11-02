# include <stdio.h> 
#include <string.h>
#include <ctype.h> 

int main() { 

char convert[100]; 
int i; 
printf("Please enter a phrase to convert from lowercase to uppercase: ");
gets(convert);


for (i = 0; convert[i]!='\0'; i++) {
      if(convert[i] >= 'a' && convert[i] <= 'z') {
         convert[i] = convert[i] -32;
      }
}
printf("%s", convert); 
return 0; 
}