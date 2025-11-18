#include<stdio.h>
//如何判断一个数是不是完数：
//这个数所有因子相加等于他本身
//如何找出他所有的因子
//内层循环：每一个数都除 一遍，能整除就是
int main(void){

    int N;
    scanf("%d",&N);
    int i,t;
    if (N<6)
    {
        return 0;/* code */
    }
    else

    for ( i = 6; i <= N; i++)//外层循环用于计数
    {
        int sum=0;
        for (t = 1; t < i; t++)//内层循环，用于找出完数
        {
            if (i%t==0)//这里判断是不是因子//做到这里，如果if都满足，说明是完数
            {
                sum+=t;//求和，看这个和是不是他本身
            }
        }
        if (sum==i)
            {
                printf("%d\n",i);/* code */
            }   
    }
    
return 0;
}