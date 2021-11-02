#include <string.h> 
#include <stdio.h> 
#include <stdlib.h>
struct color{
    int red; 
    int green; 
    int blue; 
};

struct color make_color(int red,int green,int blue );
struct color brighter(struct color c); 

int main() { 

struct color c1; 
int red, green, blue; 
printf("Enter Red: "); 
scanf("%d", &red);
printf("Enter Green: ");
scanf("%d", &green); 
printf("Enter Blue: "); 
scanf("%d", &blue); 

c1=make_color(red, green, blue); 

printf("c1: %d %d %d \n", c1.red, c1.green, c1.blue);

struct color gold = {255, 215, 0}; 
struct color b_gold= brighter(gold); 

printf("brighter gold: %d %d %d\n", b_gold.red, b_gold.green, b_gold.blue); 

    return 0; 
}

struct color make_color(int red, int green, int blue) { 
    struct color c; 
    if(red<0) red = 0; 
    if(red> 255) red = 255; 
    if(green<0) green = 0; 
    if (green>255) green = 255; 
    if(blue<0)blue = 0; 
    if(blue>255) blue = 255; 
    c.red = red;
    c.green = green;
    c.blue = blue; 
    return c; 
}

struct color brighter(struct color c) { 
    struct color c2; 
    if(c.red==0) c.red= 3; 
    if(c.green==0) c.green=3; 
    if(c.blue==0) c.blue =3; 

        c2.red=(c.red/0.7>255)?255:(int)(c.red/0.7); 
        c2.green=(c.green/0.7>255)?255:(int)(c.green/0.7); 
        c2.blue=(c.blue/0.7>255)?255:(int)(c.blue/0.7); 

        return c2; 
}