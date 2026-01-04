#include <stdio.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int v;
            if (i < j)
                v = i;
            else
                v = j;
            printf("%3d", v);
        }
        printf("\n");
    }

    return 0;
}
