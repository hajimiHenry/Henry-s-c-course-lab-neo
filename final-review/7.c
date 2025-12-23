#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d",&n);
    int p=1;

    for (int i = n; i >0 ; i--)
    {
        for (int j = 0; j < i ; j++)
        {
            printf("%4d",p);
            p++;
        }
        printf("\n");
    }
    return 0;
}