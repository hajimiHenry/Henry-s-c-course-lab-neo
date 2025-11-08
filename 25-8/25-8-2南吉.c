#include<stdio.h>

int main()
{
    int x,n;
    scanf("%d%d",&x,&n);
    int c=0;
    while(c<n)
    {
        x++;
        for(int i=2;i<=x;i++)
        {
            if(x%i!=0)
            {
                continue;
            }
            if(x%i==0&&x!=i)
            {
                break;
            }
            if(x==i)
            {
                printf("%d ",x);
                c++;
            }
        }
    }
    return 0;
}


