// 输出N以内的所有完数
// 要求：输入一个整数N(6<=N<=10000)，输出N以内的所有完数，每行一个。
// 思路：对每个数i，求其所有真因子(不含自身)之和，若等于i则为完数。

#include <stdio.h>

int main(void) {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    if (N < 6) return 0; // N小于6则没有完数可输出

    for (int i = 6; i <= N; i++) {
        int sum = 1; // 1必为除自身外的因子（i>1时）

        // 枚举因子，成对加入，避免用到复杂函数
        for (int d = 2; d * d <= i; d++) {
            if (i % d == 0) {
                sum += d;
                if (d != i / d) sum += i / d; // 加入配对因子
            }
        }

        if (sum == i) {
            printf("%d\n", i);
        }
    }

    return 0;
}
