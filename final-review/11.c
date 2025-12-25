#include<stdio.h>
int main(void)
{
    int num;
    char ch;
    scanf("%d%c",&num,&ch);

    for (int i =num; i >0 ;i--)
    {
        for (int p = 0; p <num-i ; p++)
        {
            printf(" ");
            /* code */
        }
        
        for (int j = 0; j <2*i-1 ; j++)
        {
            printf("%c",ch);
            /* code */
        }
        printf("\n");
        if (ch !='A'&&ch!='a')
        {
            ch=ch-1;
            /* code */
        }
        else if (ch=='A')
        {
            ch='Z';
            /* code */
        }
        else if (ch=='a')
        {
            ch='z';
            /* code */
        }
    }
}