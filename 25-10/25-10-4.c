/*
 * Read a 6x7 matrix and output its transpose (7x6) using array indexing only.
 */
#include <stdio.h>

int main(void) {
    int matrix[6][7];
    int i, j;

    for (i = 0; i < 6; ++i) {
        for (j = 0; j < 7; ++j) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                return 0;
            }
        }
    }

    for (j = 0; j < 7; ++j) {
        for (i = 0; i < 6; ++i) {
            printf("%3d", matrix[i][j]);
        }
        if (j != 6) {
            putchar('\n');
        }
    }

    return 0;
}
