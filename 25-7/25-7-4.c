#include <stdio.h>
#include <stdbool.h>

bool is_prime(long long n) {
    if (n <= 1) return false;
    if (n % 2 == 0) return n == 2;
    for (long long i = 3; i <= n / i; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main(void) {
    long long n;
    if (scanf("%lld", &n) != 1) {
        fprintf(stderr, "输入无效\n");
        return 1;
    }
    if (is_prime(n)) {
        printf("%lld 是素数\n", n);
    } else {
        printf("%lld 不是素数\n", n);
    }
    return 0;
}
