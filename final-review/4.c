#include <stdio.h>

int main(void)
{

    int N;
    scanf("%d",&N);
    
    int p;
    int a;

    
    for (int i = 0; i < N; i++)
    {
        scanf("%d",&p);
        int max=0;
        for (int j = 0; j < p; j++)
       {
        scanf("%d",&a);
        if (a>=max)
        {
            max=a;
            /* code */
        }
       }
        float b=max/10000.0;
        printf("%.2f\n",b);
        /* code */
    }

    return 0;
}