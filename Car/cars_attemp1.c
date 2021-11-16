/*


*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CAR 51
#define MAX 6000
struct car
{
    char ID[CAR];
    char class[CAR];
    char engine[CAR];
    char trans[CAR];
    int city;
    char fuel[CAR];
    int highway;
};

void sort_city_mpg(struct car list[], int n);

int main()
{
    char file_name[CAR];
    printf("Enter the file name: ");
    scanf("%s", file_name);
    FILE *open;
    open = fopen(file_name, "r");
    if (open == NULL) // if the file can not be opened
    {
        printf("Error opening file!!"); // inform the user
        return 1;                       // end
    }


    struct car c[150];
    struct car largest[150]; 
    int j, i;

    
        FILE *output;
    output = fopen("Top10_city_mpg.csv", "w");
    if (output == NULL) // if the file can not be opened
    {
        printf("Error opening file!!"); // inform the user
        return 1;                       // end
    }

    while (fgets(c, MAX, open) != NULL)
    {
        for (i = 0; i < MAX + 1; i++)
        {
            fscanf(open, "%[^,], %[^,], %[^,], %[^,], %d, %[^,], %d\n", c[i].ID, c[i].class, c[i].engine, c[i].trans, &c[i].city, c[i].fuel, &c[i].highway);
            for(j=0; j<11; j++) {
                if(c[i].city > largest[j].city){
                    largest[j]=c[i];
                    break; 
                }
                
            }
            while(j<11){
                fputs(largest, output); 
                j++; 
            }

        }
            printf("Output file: Top10_city_mpg.csv");
    }
     fclose(output); 
    fclose(open); 
    return 0; 
}



void sort_city_mpg(struct car list[], int n){



            return; 
}