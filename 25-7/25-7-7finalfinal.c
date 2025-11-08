#include<stdio.h>

long long gcd(long long a, long long b);

int main(void) {
    long long a, b;
    scanf("%lld/%lld", &a, &b);
    long long g = gcd(a, b);
    a /= g; b /= g;
    printf("%lld/%lld\n", a, b);
    return 0;
}

long long gcd(long long a, long long b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    if (a == 0 && b == 0) return 1;
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}
