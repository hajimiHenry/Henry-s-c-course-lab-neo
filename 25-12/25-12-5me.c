#include<stdio.h>

int findmax(int a[],int k);

int  main(void)
{
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
       scanf("%d", &arr[i]);
    }
    
    printf("%d",findmax(arr, 10));
    return 0;
}

int findmax(int a[], int k)
{
    int max=a[0];
    for (int i = 1; i < k; i++)
    {
        if (a[i] >= max)
        {
           max=a[i];
        }
    }
    
    return max;
}
