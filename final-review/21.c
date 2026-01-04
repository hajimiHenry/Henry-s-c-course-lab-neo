#include <stdio.h>
int main(void)
{
    int mon,wei;
    scanf("%d,%d",&mon,&wei);
    int trans;

    if (mon<79&&wei<=15)
    {
        trans=6;
        /* code */
    }
    else if (mon>79&&mon<199&&wei<=15)
    {
        trans=0;    
    }
    else if (mon>=199&&wei<=25)
    {
        trans=0;
        /* code */
    }
    
}