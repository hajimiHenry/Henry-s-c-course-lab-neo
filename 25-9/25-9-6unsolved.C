#include <stdio.h>


int main(void) {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    int a[6][6];  // n <= 6
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int found = 0;
    for (int i = 0; i < n && !found; i++) {
        /* 先找出该行的最大值 */
        int row_max = a[i][0];
        for (int j = 1; j < n; j++) {
            if (a[i][j] > row_max) {
                row_max = a[i][j];
            }
        }

        /* 该行可能有多个最大值，都要逐个作为候选鞍点去检查 */
        for (int j = 0; j < n && !found; j++) {
            if (a[i][j] != row_max) {
                continue;
            }
            /* 求这一列的最小值 */
            int col_min = a[0][j];
            for (int k = 1; k < n; k++) {
                if (a[k][j] < col_min) {
                    col_min = a[k][j];
                }
            }
            if (row_max == col_min) {
                printf("%d %d\n", i, j);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("NONE\n");
    }

    return 0;
}
