/*
梅森数：按原有思路修正版本（新文件）

思路保持（与你原代码一致）：
- 外层循环枚举指数 i；
- 内层通过乘法循环计算 2^i；
- 再做 h = 2^i - 1，判断是否为素数，是则输出。

这份文件只修正错误，不改变你的总体写法。修正点：
1) 每轮外层循环重置 m=1，再用内层循环乘 2（原来未重置，导致从 7 开始且越乘越大直至溢出）。
2) 外层循环范围改为 i=2..n，包含上界 n（题意为“不超过 2^n - 1”）。
3) judgeprime 修正边界并提速：
   - q<2 不是素数；q==2 是素数；偶数直接非素数；
   - 只试奇数因子到 k*k<=q（原来试到 q-1，性能差）。
4) 使用 found 标志：只有当一个都没输出时才打印 "None"（原来直接根据 n 输出会误判）。

说明：本题约束 n<20，2^n-1 最大为 524287，使用 int 安全。
*/

#include <stdio.h>

// 判素数：边界正确，试除到 sqrt(q)
static int judgeprime(int q) {
    if (q < 2) return 0;      // 小于 2：非素数
    if (q == 2) return 1;     // 2：素数
    if (q % 2 == 0) return 0; // 其他偶数：非素数
    for (int k = 3; k * k <= q; k += 2) { // 只试奇数因子到 sqrt(q)
        if (q % k == 0) return 0;
    }
    return 1;
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int found = 0;            // 是否已输出过至少一个梅森素数
    for (int i = 2; i <= n; i++) { // 包含上界 n
        int m = 1;            // 修正点：每轮外层循环都重置 m=1
        for (int count = 0; count < i; count++) {
            m *= 2;           // 计算 2^i（保持你的“乘法循环”思路）
        }
        int h = m - 1;        // 得到 2^i - 1
        if (judgeprime(h)) {  // 判素数
            printf("%d\n", h);
            found = 1;
        }
    }

    if (!found) {             // 只在完全没有结果时输出 None
        printf("None");
    }
    return 0;
}
    