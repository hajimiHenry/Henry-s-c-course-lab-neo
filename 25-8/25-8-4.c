#include<stdio.h>
int main(void){
long long int N;
scanf("%lld",&N);
int m=10;
int k;
int p;
int count=0,sum=0;
do
{
 k=N/m;
 p=N%m;
 m=m*10;
 count+=1;g
 sum=sum+k; 
} while (k>=10);

printf("%d",count);
putchar(' ');
printf("%d",sum);
return 0;
}


printf();
//正整数 除以十，不行再除一百，再往上除
//循环除法按照计数器
//求和：在每个循环中累加
//用哪种循环呢