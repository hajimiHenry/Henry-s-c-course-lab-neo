#include<stdio.h>
void aver_stu(int a[10][5]);
void aver_stu(int a[10][5]);
void max(int a[10][5]);

int main()
{ int a[10][5];
  int i,j;
  for(i=0; i<10; i++)
      for(j=0; j<5; j++)
          scanf("%d",&a[i][j]);
  aver_stu(a);
  aver_sco(a);
  max(a);
  return 0;
}
/* 你的程序将被嵌在这里 */

void aver_stu(int a[10][5])
{
    int sum=0;
    for (int k = 0; k < 10; k++)
    {
        for (int i = 0; i < 5; i++)
        {
            sum+=a[k][i];
        }
        int aver=sum/5;
        printf("%3d",aver);
    }
}

void aver_stu(int a[10][5])
{
    int i;
    int k;
    int sum=0;
    for ( i = 0; i < 5; i++)
    {
        for ( k = 0; k < 10; k++)
        {
            sum+=a[k][i];
        }
        int aver=sum/10;
        printf("%3d",aver);
    }
}

void max(int a[10][5])
{
    int i;
    int k;
    int max=a[0][0];
    for ( i = 0; i < 10; i++)
    {
        for ( k = 0; k < 5; k++)
        {
            if (a[i][k]<max)
            {
                continue;
            }
            else
            {
                max=a[i][k];
            }
        }
        printf("%3d",max);
    }
}
