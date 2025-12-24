#include<stdio.h>
int main (void){

//用循环解决，有几个写几轮循环
//现有的基数，乘以10在加上去，得到下一个要加的数
//sum是总和，原理是分和相加，上一次的分和*10再+
int a,n;
scanf("%d%d",&a,&n);
int sum=0;
int b=0;
for (int i = 0; i < n; i++)
{
    b=b*10+a;
    sum+=b;
    
}

printf("%d",sum);
return 0;
}