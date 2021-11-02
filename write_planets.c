#include <stdio.h>
#define MAX_LEN 1000
int main()
{
    FILE* pFile;
    char *planets[] = {"Mercury", "Venus", "Earth",
                   "Mars", "Jupiter", "Saturn",
                   "Uranus", "Neptune", "Pluto"};
    printf ("File planets.txt written\n");
    return 0;
}