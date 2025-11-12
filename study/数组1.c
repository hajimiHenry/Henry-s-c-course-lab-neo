#include <stdio.h>

int main(void) {
    int nums[10];
    int n;
    int min_index;
    int i;

    for (i = 0; i < 10; ++i) {
        if (scanf("%d", &nums[i]) != 1) {
            return 0;
        }
    }

    if (scanf("%d", &n) != 1 || n < 0 || n > 9) {
        return 0;
    }

    min_index = n;
    for (i = n + 1; i < 10; ++i) {
        if (nums[i] < nums[min_index]) {
            min_index = i;
        }
    }

    printf("%d\n", min_index);
    return 0;
}
