#include <stdio.h>

/*
 * 功能：
 *   先读入 10 个整数存入数组 nums[]，
 *   再读入一个下标 n（0~9），
 *   在区间 [n, 9] 里找到最小元素的位置（下标），并输出这个下标。
 */
int main(void) {
    int nums[10];     /* 存放 10 个整数 */
    int n;            /* 起始下标 n */
    int min_index;    /* 记录当前找到的最小值的下标 */
    int i;            /* 循环变量 */

    /* 读入 10 个整数，存入数组 nums[0] ~ nums[9] */
    for (i = 0; i < 10; ++i) {
        if (scanf("%d", &nums[i]) != 1) {
            return 0; /* 输入失败就结束程序 */
        }
    }

    /* 读入起始下标 n，并做简单合法性检查（0 <= n <= 9） */
    if (scanf("%d", &n) != 1 || n < 0 || n > 9) {
        return 0;
    }

    /* 先假设从位置 n 开始的最小值就在 n 这个位置 */
    min_index = n;

    /* 从 n+1 往后扫描到数组末尾，找更小的元素 */
    for (i = n + 1; i < 10; ++i) {
        if (nums[i] < nums[min_index]) {
            min_index = i; /* 找到更小的就更新最小值下标 */
        }
    }

    /* 输出最小值所在的下标 */
    printf("%d\n", min_index);
    return 0;
}
