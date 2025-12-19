#include<stdio.h>
#include "string.h"
#define N 10
void sort(char  (*p)[20]) ;
int main()
{char ch[N][20]; int i;
 for (i=0; i<N; i++)        //输入10个串
   scanf("%s",ch[i]);
 sort(ch);                   //利用行指针排序
 for(i=0; i<N; i++)         //输出
    printf("%s\n",ch[i]);
  return 0;
}

/* 你的程序将被嵌在这里 */
    void sort(char  (*p)[20]) 
    {
        char temp[20];
        for (int i = 0; i < N-1; i++)
        {
            for (int j = i+1; j < N; j++)
            {
                if (strcmp(p[i],p[j])>0)
                {
                    strcpy(temp,p[i]);
            strcpy(p[i],p[j]);
            strcpy(p[j],temp);
                }
            }
        }
        
    }