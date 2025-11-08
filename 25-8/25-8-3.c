#include<stdio.h>
/*
程序逻辑:
1) 读取 repeat，表示要处理的行数；
2) 每次循环先读 n 与第一个整数，保存为当前最大值 max；
3) 继续读取剩余 n-1 个整数，若有更大就更新 max；
4) 当前行数字读完后立即输出 max。
*/
int main(void)
{
int repeat;
scanf("%d",&repeat);

for(int rpct=0;rpct<repeat;rpct++)
{
   int n;
    scanf("%d",&n);
    int a,max;
    scanf("%d",&a);
    max=a;
   for(int nct=1;nct<n;nct++)
   {
    scanf("%d",&a);
   if (a>=max)
   {
    max=a;
   }
   }   

printf("%d\n",max);

}

   return 0; 
}
