#include <stdio.h>

int find_max(const int a[], int n);

int main(void)
{
    int a[10];
    for (int i = 0; i < 10; i++) {
        if (scanf("%d", &a[i]) != 1) {
            return 0;
        }
    }

    printf("%d", find_max(a, 10));
    return 0;
}

int find_max(const int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}
