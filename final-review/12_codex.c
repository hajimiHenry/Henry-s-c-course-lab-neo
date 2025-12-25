#include <stdio.h>

int main(void) {
    int uniq[100];
    int m = 0;
    int x;

    while (scanf("%d", &x) == 1 && x != -1) {
        int found = 0;
        for (int j = 0; j < m; j++) {
            if (uniq[j] == x) {
                found = 1;
                break;
            }
        }
        if (!found && m < 100) {
            uniq[m++] = x;
        }
    }

    for (int i = 0; i < m; i++) {
        printf("%4d", uniq[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
    if (m > 0 && m % 10 != 0) {
        printf("\n");
    }
    return 0;
}
