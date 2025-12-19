#include <stdio.h>
int main(void)
{
    int a;
    char b;
    scanf("%d %c",&a,&b);

    for (int i = 0; i < a; i++)
    {
        char cur=b;
        int len=i*2+1;
        int t=0;
        while (t < a - 1 - i)
        {
            putchar(' ');
            t++;/* code */
        }
        for (int j = 0; j < len; j++)
        {
            
            printf("%c",cur);
            if (cur=='a')
            {
                cur='z';
            }
            else if(cur=='A')
            {
                cur='Z';/* code */
            }
            else{cur--;}

            /* code */
        }
        
        printf("\n");

        /* code */
    }
    



}
