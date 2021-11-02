//this multiplies the same indexes in two arrays together and stores them within another array. 
#include <stdio.h>

void multi_vec(int v1[], int v2[], int v3[], int n){
    int *p, *q, *r; 

    for(p=&v1[0], q=&v2[0], r=&v3[0]; p<&v1[n], q<&v2[n], r<&v3[n]; p++, q++, r++)
        *r = *p * *q;  
        
}

int main(void)
{
    int i, size;
    printf("Please enter the length of the vectors:\n");
    scanf("%d", &size);
    int a[size], b[size], c[size];
    printf("enter the first vector");
    for (i = 0; i < size; i++)
        scanf("%d", &a[i]);
    printf("enter the second vector");
    for (i = 0; i < size; i++)
        scanf("%d", &b[i]);
    multi_vec(a, b, c, size);
    for (i = 0; i < size; i++)
        printf("%d\t", c[i]);
    return 0;
}