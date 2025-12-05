#include <stdio.h>

int main(void) {
    int N;
    if (scanf("%d", &N) != 1) {
        return 0;
    }

    int counts[10] = {0};

    for (int i = 0; i < N; ++i) {
        int x;
        if (scanf("%d", &x) != 1) {
            return 0;
        }

        if (x == 0) {
            counts[0]++;
        } else {
            if (x < 0) {
                x = -x;
            }
            while (x > 0) {
                int d = x % 10;
                counts[d]++;
                x /= 10;
            }
        }
    }

    int maxCount = 0;
    for (int d = 0; d < 10; ++d) {
        if (counts[d] > maxCount) {
            maxCount = counts[d];
        }
    }

    printf("%d: ", maxCount);

    int first = 1;
    for (int d = 0; d < 10; ++d) {
        if (counts[d] == maxCount) {
            if (!first) {
                putchar(' ');
            }
            printf("%d", d);
            first = 0;
        }
    }
    putchar('\n');

    return 0;
}
