#include<stdio.h>
int main(void){
    int N;
    scanf("%d",&N);
    int i;
    int d;
    int sum=0;
    if (N<6)
    {
      return 0;  /* code */
    }
    else
    {
    for ( int i = 6; i <=N; i++)
    {
        int sum=0;
       for (d =1; d<i; d++)
       {
        if (i%d==0)
       {
        sum=sum+d;
       }
       }    
       if (sum==i)
       {
        printf("%d\n",sum);
       }
    }
    }
    return 0;
}
