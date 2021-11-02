#include <stdio.h>
#define N 10
void selection_sort(int a[], int n);
int find_largest(int a[], int n);
int main(void)
{
    int i;
    int a[N];
    printf("Enter %d numbers to be sorted: ", N);
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);
    selection_sort(a, N);
    printf("In sorted order:");
    for (i = 0; i < N; i++)
        printf(" %d", a[i]);
    printf("\n");
    return 0;
}
void selection_sort(int a[], int n)
{
    int largest = 0, temp;
    if (n == 1)
        return;
    largest = find_largest(a, n);
    if (largest < n - 1)
    {
        temp = a[n - 1];
        a[n - 1] = a[largest];
        a[largest] = temp;
    }
    selection_sort(a, n - 1);
}
int find_largest(int a[], int n)
{
    int largest_index = 0;
    int i;
    for (i = 1; i < n; i++)
        if (a[i] > a[largest_index])
            largest_index = i;
    return largest_index;
}