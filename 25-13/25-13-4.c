#include <stdio.h>

void input(int *p);
void proc(int *p);
void output(int *p);

main()
{int a[10];
 input(a);     //输入10个整数
 proc(a);      //调换
 output(a);    //输出
 return 0;
}

/* 请在这里填写答案 */
void input(int *p)
{
    int *arr=p;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d",&arr[i]);
    }
}

void proc(int *p)
{
    int minindex=0;
    for (int i = 0; i <  10; i++)
    {
        if (p[i]<=p[minindex])
        {
           minindex=i; /* code */
        }
    }
    int maxindex=0;
    for (int i = 0; i < 10; i++)
    {
        if (p[i]>=p[maxindex])
        {
           maxindex=i; /* code */
        }    
    }
    
    int temp0=p[0];
    p[0]=p[minindex];
    p[minindex]=temp0;

    if (maxindex == 0) maxindex = minindex;

    int temp9=p[9];
    p[9]=p[maxindex];
    p[maxindex]=temp9;
}

void output(int *p)
{
    for (int i = 0; i < 10; i++)
    {
       printf("%3d",p[i]); /* code */
    }
    
}

