/* author: randall hunt 
this program is to convert fahrenhiet to celsius
*/ 
#include <stdio.h> 

#define FREEZING_PT 32.0
#define SCALE_FACTOR (5.0/9.0)

int main(void) 

{
double fahrenheit, celsius;

printf("Enter fahrenheit temperature: ");
scanf("%1f", &fahrenheit);

celsius=(fahrenheit-FREEZING_PT)*SCALE_FACTOR;

printf("Celsius equivalent: %.1f\n", celsius);

return 0;
}


