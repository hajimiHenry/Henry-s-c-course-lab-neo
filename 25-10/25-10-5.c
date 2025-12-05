#include <stdio.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    int digits[800] = {0};
    int size = 1;
    digits[0] = 1;

    for (int factor = 2; factor <= n; ++factor) {
        int carry = 0;
        for (int idx = 0; idx < size; ++idx) {
            int product = digits[idx] * factor + carry;
            digits[idx] = product % 10;
            carry = product / 10;
        }
        while (carry > 0) {
            digits[size] = carry % 10;
            carry /= 10;
            ++size;
        }
    }

    int count = 0;
    for (int idx = size - 1; idx >= 0; --idx) {
        putchar('0' + digits[idx]);
        ++count;
        if (count % 40 == 0) {
            putchar('\n');
        }
    }
    if (count % 40 != 0) {
        putchar('\n');
    }

    return 0;
}
