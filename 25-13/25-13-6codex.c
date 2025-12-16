#include <stdio.h>

static void swap_int_codex(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

static int is_fixed_codex(int *p, int *fixed[], int fixed_count)
{
    int i;
    for (i = 0; i < fixed_count; i++) {
        if (p == fixed[i]) {
            return 1;
        }
    }
    return 0;
}

void adjust_codex(int (*a)[5])
{
    int i, j, k;
    int *pmax = &a[0][0];
    int *fixed[5];

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (*(*(a + i) + j) > *pmax) {
                pmax = *(a + i) + j;
            }
        }
    }
    swap_int_codex(pmax, *(a + 2) + 2);

    fixed[0] = *(a + 2) + 2;

    {
        int ci[4] = {0, 0, 4, 4};
        int cj[4] = {0, 4, 0, 4};

        for (k = 0; k < 4; k++) {
            int *target = *(a + ci[k]) + cj[k];
            int *pmin = NULL;

            for (i = 0; i < 5; i++) {
                for (j = 0; j < 5; j++) {
                    int *cur = *(a + i) + j;
                    if (is_fixed_codex(cur, fixed, 1 + k)) {
                        continue;
                    }
                    if (pmin == NULL || *cur < *pmin) {
                        pmin = cur;
                    }
                }
            }

            swap_int_codex(pmin, target);
            fixed[1 + k] = target;
        }
    }
}

int main(void)
{
    int a[5][5];
    int i, j;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            scanf("%d", *(a + i) + j);
        }
    }

    adjust_codex(a);

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%3d", *(*(a + i) + j));
        }
        printf("\n");
    }

    return 0;
}
