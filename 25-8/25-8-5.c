#include<stdio.h>

int main(void) {
    long long n;

    if (scanf("%lld", &n) != 1) { // 读取输入的整数。
        return 1;
    }

    

    long long divider = 1;
    // 找到最高位对应的 10 的幂，例如 12345 -> divider = 10000。
    while (n / divider >= 10) {
        divider *= 10;
    }

    // 循环输出每一位：从最高位到最低位。
    while (divider > 0) {
        printf(divider == 1 ? "%lld" : "%lld ", n / divider); // 先输出当前最高位。
        n %= divider;    // 去掉已经输出的最高位。
        divider /= 10;   // 移动到下一位。
    }

    putchar('\n');

    return 0;
}
