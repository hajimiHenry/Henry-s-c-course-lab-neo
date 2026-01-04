#include <stdio.h>
#include <string.h>

/*
  题意（简述）：
  - 每位选手有 4 个评委分数（<=10 的正整数），其中 1 个是最低分。
  - 去掉最低分后，剩下 3 个分数之和为“总分”。
  - 有 N（N<15）位选手，输入每位选手的编号（长度<10）和 4 个分数。
  - 输出按总分从高到低排序的结果（每行：编号 + 总分，格式 "%10s%6d\n"）。
  - 若总分相同，则“原始最低分更小”的选手排在前面。
  - 若仍相同，为了稳定性（不乱序），按输入先后（idx 小的在前）。

  本示范做法（最直观，适合初学者）：
  1) 读入每个选手：编号 + 4 个分数
  2) 计算每人：
     - minScore：4 个分数中的最低分
     - sum3：4 个分数总和 - 最低分（即去掉最低分后的总分）
  3) 用冒泡排序按规则排序（不使用库函数，易理解）。
*/

typedef struct
{
    char id[10];  /* 选手编号：长度<10，所以数组开到 10（含 '\0'） */
    int score[4]; /* 4 个评委分数 */
    int minScore; /* 4 个分数的最低分（用于同总分时的比较） */
    int sum3;     /* 去掉最低分后的总分 */
    int idx;      /* 输入顺序（用于最后的稳定排序） */
} Player;

int main(void)
{
    int n; /* 选手人数 */

    /* 读入 N；若读入失败直接结束 */
    if (scanf("%d", &n) != 1)
        return 0;

    /* 题目给定 N < 15，所以这里直接开固定长度数组最简单（避免动态内存） */
    Player p[15];

    /* 逐个读入每位选手的数据，并同时计算 minScore 与 sum3 */
    for (int i = 0; i < n; i++)
    {
        p[i].idx = i; /* 记录原始输入顺序 */

        /* 读入：编号 + 4 个整数分数
           - %9s：最多读取 9 个字符，给 '\0' 留空间，避免编号过长造成越界
           - 对 int 用 & 取地址；数组元素是普通 int 变量 */
        scanf("%9s%d%d%d%d",
              p[i].id,
              &p[i].score[0], &p[i].score[1], &p[i].score[2], &p[i].score[3]);

        /* 计算最低分与总和 */
        int minScore = p[i].score[0]; /* 先假设第 0 个是最低分 */
        int sum = p[i].score[0];      /* 先把第 0 个分数计入总和 */

        /* 扫描剩下 3 个分数：更新最低分并累加总和 */
        for (int k = 1; k < 4; k++)
        {
            if (p[i].score[k] < minScore)
            {
                minScore = p[i].score[k];
            }
            sum += p[i].score[k];
        }

        /* 保存结果：最低分、去最低分后的总分 */
        p[i].minScore = minScore;
        p[i].sum3 = sum - minScore;
    }

    /* 冒泡排序：
       外层 i：已就位的“最大项”数量
       内层 j：比较相邻的 p[j] 和 p[j+1]，若顺序不符合规则则交换 */
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            int needSwap = 0; /* 标记是否需要交换 */

            /* 排序规则（优先级从高到低）：
               1) sum3 大的排前面（降序）
               2) sum3 相同：minScore 小的排前面（升序）
               3) 仍相同：idx 小的排前面（保持输入顺序的稳定性） */
            if (p[j].sum3 < p[j + 1].sum3)
            {
                needSwap = 1;
            }
            else if (p[j].sum3 == p[j + 1].sum3 && p[j].minScore > p[j + 1].minScore)
            {
                needSwap = 1;
            }
            else if (p[j].sum3 == p[j + 1].sum3 &&
                     p[j].minScore == p[j + 1].minScore &&
                     p[j].idx > p[j + 1].idx)
            {
                needSwap = 1;
            }

            /* 如果不符合排序规则，则交换两个结构体（整个人的信息一起换） */
            if (needSwap)
            {
                Player tmp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tmp;
            }
        }
    }

    /* 按题目要求格式输出：每行编号 + 总分 */
    for (int i = 0; i < n; i++)
    {
        printf("%10s%6d\n", p[i].id, p[i].sum3);
    }

    return 0;
}
