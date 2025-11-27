#include<stdio.h>
int main (void){

    int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int w;
    scanf("%d",&w);

    int sum=13;//从一月开始计算，第一个要算的就是13
    //月份循环
    for (int i = 1; i <= 12;i++)
    {
      int n=sum%7;
      int m=n+w;
      if (m>7)
      {
        m-=7;
      }
      
      if (m==5)
      {
        printf("%d\n",i);/* code */
      }
        sum+=days[i-1];
    }
    return 0;
}