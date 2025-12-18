#include<stdio.h>

int sumdigit(int a);

int main(void)
{
    int a,b;
    scanf("%d%d",&a,&b);

    for ( a ; a <= b ;a++)
    {
        if (sumdigit(a)%5==0||sumdigit(a)%7==0)
        {
            printf("%5d",a);
            /* code */
        }
    }
    printf("\n");

}

int sumdigit(int a)
{
    int sum=0;
    while (a>0)
    {
        sum+=a%10;
        a/= 10;
        /* code */
    }
    return sum;

}