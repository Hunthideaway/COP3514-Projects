#include <stdio.h>
//stdio is a header file for printf and scanf funtions
int main()
{
    int n,j,i=0,k=0,temp;
    printf("Enter value of n:");
    scanf("%d",&n);//taking the n value
    int a[n],b[n];//a is array to store user inputs,b is array to store missed elements in a
    printf("\nEnter elements :");
    while(i<n)//this loop is used to take inputs from the user
    {
        scanf("%d",&temp);//temp is varaible to store user input element tempiraly
        if(temp>=1 && temp<=n)//checking range
            {
                a[i]=temp;//assign temp to the a arry
                i++;//increament i
            }
        else//if invalid range
            printf("\nThe elements must in range of 1 to %d \n",n);
    }
  
    for(i=1;i<=n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==a[j])//if element find break the inner loop
                break;
       }
        if(j==n){//if element not find store i value in b array
                b[k]=i;
                k++;//k is the index of b array
             }
    }
    printf("\nThe output is :");
    for(i=0;i<k;i++)//this loop is to display b array
    {
        printf("%d ",b[i]);
    }

    return 0;
}