#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d",&n);

    for (int i = 1; i < n+1 ; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            int v;
            if (i<j)
            {
                v=i;
                /* code */
            }
            else
            {
                v=j;
                /* code */
            }
            printf("%3d",v);
            /* code */
        }
        printf("\n");
        
        /* code */
    }
    


    
}