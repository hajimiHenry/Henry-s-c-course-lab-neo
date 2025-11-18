/*
 * 题意：
 *   给一个正整数 N，在它所有因子里找一段“连续的整数因子”：
 *   x * (x+1) * (x+2) * ... * (x+len-1) 正好整除 N，len 尽量大。
 *   先输出最长长度 len，再输出这一段连续因子。
 *   如果不存在长度 > 1 的连续因子，就输出 1 和 N 自身。
 *
 * 思路：
 *   1. 枚举起始因子 i，从 2 开始到 sqrt(N) 为止。
 *      为啥到 sqrt(N) 就够了？因为如果从更大的数开始，至少要两个数相乘
 *      才能长度 >= 2，它们的乘积一定 > N，不可能是 N 的因子。
 *   2. 如果 i 不是 N 的因子，就直接跳过。
 *   3. 否则，用一个临时变量 temp = N，尝试依次除以 i, i+1, i+2, ...
 *      每成功整除一次，长度 len++，并把 temp 更新为 temp / 当前因子。
 *      一旦不能整除，就停下来，此时得到一段以 i 为起点的连续因子，长度为 len。
 *   4. 用 maxLen 记录当前找到的最长长度，用 bestStart 记录对应的起点 i。
 *   5. 枚举结束后：
 *        - 如果 maxLen 仍为 0，说明没有长度 > 1 的连续因子，输出 1 和 N。
 *        - 否则输出 maxLen，并按 bestStart, bestStart+1, ... 打印这段因子。
 */

#include <stdio.h>
#include <math.h>

int main(void) {
    long long n;

    /* 读入 N */
    if (scanf("%lld", &n) != 1) {
        return 0;
    }

    long long maxLen = 0;    /* 当前找到的最长连续因子个数 */
    long long bestStart = 0; /* 最长连续因子对应的起始因子 */

    /* 起点 i 没必要超过 sqrt(n) */
    long long limit = (long long)sqrt((double)n);

    /* 枚举连续因子的起点 i */
    for (long long i = 2; i <= limit; i++) {
        /* 如果 i 不是 n 的因子，就不可能作为一段连续因子的起点 */
        if (n % i != 0) {
            continue;
        }

        long long temp = n;  /* 每次从原来的 n 开始尝试分解 */
        long long j = i;     /* 当前尝试的因子，从 i 开始依次递增 */
        long long len = 0;   /* 从 i 开始连续成功整除的个数 */

        /* 一直用 j, j+1, j+2 ... 去整除 temp，能除多少算多少 */
        while (temp % j == 0) {
            temp /= j;       /* 把这个因子“分解”掉 */
            j++;             /* 换下一个连续的整数因子 */
            len++;           /* 长度加一 */
        }

        /* 如果这次从 i 开始得到的长度更长，就更新答案 */
        if (len > maxLen) {
            maxLen = len;
            bestStart = i;
        }
    }

    if (maxLen == 0) {
        /*
         * maxLen 仍为 0，说明没有任何长度 >= 2 的连续因子序列
         * 题目要求这种情况下输出：
         *   第一行：1
         *   第二行：N
         */
        printf("1\n%lld\n", n);
    } else {
        /* 打印最长长度 */
        printf("%lld\n", maxLen);

        /* 按 “因子1*因子2*...*因子k” 的格式输出这段连续因子 */
        for (long long k = 0; k < maxLen; k++) {
            if (k > 0) {
                printf("*"); /* 因子之间用 * 连接 */
            }
            printf("%lld", bestStart + k);  
        }
        printf("\n");
    }

    return 0;
}

