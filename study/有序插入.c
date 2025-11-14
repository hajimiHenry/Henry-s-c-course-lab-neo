#include <stdio.h>

int main(void) {
    int a[100];      // 数组容量设成 100，保证够用
    int n;           // 当前数组中已有元素个数
    int x;           // 要插入的新元素

    // 读入 n
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    // 读入已经从小到大排好序的 n 个整数
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // 读入要插入的新整数 x
    if (scanf("%d", &x) != 1) {
        return 0;
    }

    // 下面是“有序插入”的核心算法，直接写在 main 里

    int i = n - 1;   // 从最后一个元素开始

    // 从右往左，只要当前元素比 x 大，就向右挪一格
    while (i >= 0 && a[i] > x) {
        a[i + 1] = a[i];  // 把 a[i] 挪到右边
        i--;              // 往左看一个位置
    }

    // 循环结束后，i 停在第一个不大于 x 的元素位置
    // 或者变成 -1，表示 x 最小
    // 两种情况都可以用 a[i + 1] = x 来处理
    a[i + 1] = x;

    // 有效元素个数加 1
    n = n + 1;

    // 输出插入后的数组
    for (int j = 0; j < n; j++) {
        if (j > 0) {
            printf(" ");
        }
        printf("%d", a[j]);
    }
    printf("\n");

    return 0;
}
