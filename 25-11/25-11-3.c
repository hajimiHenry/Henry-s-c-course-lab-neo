#include<stdio.h>
#include<string.h>
void tongji(char s[],int leibie[4]);
int main()
{char a[50];
 int leibie[4]={0};
 gets(a);
 tongji(a,leibie);
 printf("%d %d %d %d",leibie[0],leibie[1],leibie[2],leibie[3]);
 return 0;
}
/* 你写的函数将被嵌在这里 */
void tongji(char s[ ],int leibie[4]){

    for (int i = 0; s[i]!='\0'; i++)
    {
        if ((s[i]>=65&&s[i]<=90)||(s[i]>=97&&s[i]<=122))
        {
            leibie[0]+=1; /* code */
        }
       else if (s[i]>=48&&s[i]<=57)
        {
            leibie[1]+=1;
        }
       else if (s[i]==32)
        {
            leibie[2]+=1;
        }
        else{
            leibie[3] +=1;
        }
    }
}
