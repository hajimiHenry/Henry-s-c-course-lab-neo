// 简单版：输出 N 以内所有完数（不用复杂函数）
#include <stdio.h>

int main(void) {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    if (N < 6) return 0; // 小于 6 没有完数

    // 枚举每个候选数 x，并求它的真因子之和
    for (int x = 6; x <= N; x++) {
        int sum = 0;              // 累加真因子（不含 x 本身）
        for (int d = 1; d < x; d++)
        {
            if (x % d == 0) sum += d;
        }
        if (sum == x) 
        {
            printf("%d\n", x);  // x 是完数
        }
    }
    


    return 0;
}
