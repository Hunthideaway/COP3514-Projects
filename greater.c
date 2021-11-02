//this counts the number of values that are greater than 25, using pointer notation 
#include <stdio.h>


int compare_array(int a[], int n, int value)
{
    int *p, count = 0;
    for (p = &a[0]; p < &a[n]; p++)
        if (*p > value)
            count++;
    return count;
}

int main()
{
    int count = 0;
    int a[7] = {3, 42, 52, 91, 2, 13, 49};
    count = compare_array(a, 7, 25);
    printf("the number of elements greater than 25 is: %d\n", count);
    return 0;
}