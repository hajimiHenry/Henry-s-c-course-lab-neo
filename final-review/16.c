#include<stdio.h>

int main (void)
{
    int n;
    scanf("%d",&n);
    int temp1,temp2;
    int index=0;

    for (int i = 0; i < n; i++)
    {
        
        scanf("%d.%d",&temp1,&temp2);
        if (temp2<10)
        {
            temp2*=10;
            /* code */
        }
        
        int score=temp1*100+temp2;
        if (score<=3720&&score>=3630)
        {
            index++;
            /* code */
        }        
    }
    printf("%d",index);

    return 0;
}