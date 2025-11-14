#include<stdio.h>
int main (void){
int n;
scanf("%d",&n);
int arr[n];
int i;

for ( i = 0; i < n; i++)
{
scanf("%d",&arr[i]);//填入数字
}
//开始做比较
//我要找最大值和她的zuixiao下标
//最大值：先付一个，进去和下一个比就能出来
//找最小下标怎么找
//可以把k直接付给maxindex，但是怎判断她是不是最小的以及怎么更新
//
int max;
int maxindex;
max=arr[0];
for (int k = i-1; k>=0; k--)
{
    if (max<=arr[k])
    {
        max=arr[k];
        maxindex=k;
    }
}
printf("%d",max);
putchar(' ');
printf("%d",maxindex);

return 0;
}