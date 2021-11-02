#include <stdio.h> 

#define N 10

void find_two_largest(int a[], int n, int *largest, int *second_largest);

int main()
{
        int i, max, second_max;
        int a[N];

        printf("Enter %d elements for the arary: ", N);
        for(i=0;i<N;i++)
                scanf("%d", &a[i]);

        find_two_largest(a, N, &max, &second_max);
        printf("the largest value is: %d and the second largest is: %d\n", max, second_max);

        return 0;

}

void find_two_largest(int a[], int n, int *largest, int *second_largest) { 
    int i; 
    int max1, max2; //variables, max1 is the largest value, max2 is the second largest 
    //comparing the first two values to initialize them
    if(a[0] > a[1]) { //if the first value if greater than the second value 
        max1 = a[0]; 
        max2 = a[1]; 
    }
    else{ //other wise the second value is larger and set it equal to max1 
        max1 = a[1]; 
        max2 = a[0]; 
    }
    for(i=2; i<n; i++) { 
        if( a[i] > max1) { 
            max2 = max1; 
            max1 = a[i]; 
        }
        else if(a[i] > max2 )
            max2 = a[i]; 
    }
    *largest = max1; 
    *second_largest = max2;

}