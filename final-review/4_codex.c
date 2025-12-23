#include <stdio.h>

int main(void)
{
    int N;
    if (scanf("%d", &N) != 1) return 0;

    for (int i = 0; i < N; i++) {
        int n;
        scanf("%d", &n);

        int max_amount = 0;
        for (int j = 0; j < n; j++) {
            int x;
            scanf("%d", &x);
            if (x > max_amount) max_amount = x;
        }

        printf("%.2f\n", max_amount / 10000.0);
    }

    return 0;
}
