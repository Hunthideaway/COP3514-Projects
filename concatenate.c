#include <stdio.h> 

void concatenate (char *s1, char *s2); 

int main() { 
char str2[50];
char str1[50]; 

printf("Enter the input for first word: "); 
scanf("%s", str1); 

printf("Enter the input for second word: "); 
scanf("%s", str2); 

concatenate(str1, str2); 
printf("Output: %s\n", str1); 

return 0; 
}

void concatenate (char *s1, char *s2) { 

char *p, *q; 
for(p=s1; *p != '\0'; p++)
        ; 

for(q=s2; *q !='\0' ;q++ ){
    *p++ = *q; }

    *p = '\0'; 

 }