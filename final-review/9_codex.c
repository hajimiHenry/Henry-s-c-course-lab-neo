#include <stdio.h>

/*
    题意（简化版）：
    输入四个整数 T S U N
      T：是否特殊车辆（1=特殊车辆，免费；0=普通车辆）
      S：是否重点区域（1=重点；0=非重点）
      U：ETC 类型（0=无ETC；1/2/3=不同折扣）
      N：停车时长（小时，整数，题目给定不超过 24）

    计费规则（阶梯计费）：
      - 前 2 小时（含 2）：按第一档单价 p1
      - 第 3 小时（即 2~3 小时这 1 小时部分）：按第二档单价 p2
      - 超过 3 小时的部分：按第三档单价 p3
    最终费用 = 阶梯原价 * 折扣系数

    本题更“好写、好读、好检查”的关键点：
      1) 单值结果（折扣系数）用 return 返回，比“指针输出”更清爽。
      2) 阶梯费用直接按三段累加，不必拆 time1/time2/time3，变量更少更不容易错。
      3) main 只做：读入 → 调用计算 → 输出。
*/

/* 返回 ETC 折扣系数（单值结果，用 return 最合适） */
static double get_rate(int U)
{
    if (U == 0) return 1.00; /* 没有 ETC，不打折 */
    if (U == 1) return 0.88;
    if (U == 2) return 0.90;
    if (U == 3) return 0.95;
    return 1.00; /* 兜底：异常输入按不打折处理 */
}

/*
    根据区域 S 得到三档单价（一次要“带回 3 个值”，这里用指针输出参数）
    - 重点区域：8 / 12 / 20
    - 非重点区域：2 / 6 / 8
*/
static void get_prices(int S, int *p1, int *p2, int *p3)
{
    if (S == 1) {
        *p1 = 8;
        *p2 = 12;
        *p3 = 20;
    } else {
        *p1 = 2;
        *p2 = 6;
        *p3 = 8;
    }
}

/*
    计算“阶梯原价”（不含折扣）

    把 N 小时拆成三段来累加：
      h1：第一段小时数 = min(N, 2)
      h2：第二段小时数 = 只有 N>=3 才有，固定 1 小时（第 3 小时）
      h3：第三段小时数 = max(N - 3, 0)

    这样写的好处：
      - 不需要很多 if 分支；
      - 边界 N=2 / N=3 很直观；
      - 变量少，不易漏改。
*/
static double calc_base_fee(int N, int p1, int p2, int p3)
{
    int h1 = 0, h2 = 0, h3 = 0;

    if (N <= 0) return 0.0;

    /* 第一段：最多 2 小时 */
    h1 = (N >= 2) ? 2 : N;

    /* 第二段：只有当 N >= 3 时，才会出现“第 3 小时”这 1 小时 */
    h2 = (N >= 3) ? 1 : 0;

    /* 第三段：超过 3 小时的部分 */
    h3 = (N > 3) ? (N - 3) : 0;

    return (double)h1 * p1 + (double)h2 * p2 + (double)h3 * p3;
}

/* 统一计算最终费用：可让 main 更干净 */
static double calc_total_fee(int T, int S, int U, int N)
{
    if (T == 1) return 0.0; /* 特殊车辆：免费 */

    int p1, p2, p3;
    get_prices(S, &p1, &p2, &p3);

    double base = calc_base_fee(N, p1, p2, p3);
    double rate = get_rate(U);

    return base * rate;
}

int main(void)
{
    int T, S, U, N;
    if (scanf("%d%d%d%d", &T, &S, &U, &N) != 4) {
        return 0; /* 输入不完整，直接结束 */
    }

    double total = calc_total_fee(T, S, U, N);

    /* 题目要求：保留两位小数 */
    printf("%.2f", total);
    return 0;
}

