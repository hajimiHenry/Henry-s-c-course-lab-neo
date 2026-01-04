#include <stdio.h>
#include <string.h>

/* ===== 我做的修改点（按你要求标注）=====
   1) 变量/字段命名统一：
      - name -> id
      - arr  -> scores
      - sum3 -> total
      - minscore -> minScore
      - x[] -> players[]
   2) 交换函数改成“传指针交换”swap(Player *a, Player *b)，否则传值交换不会生效
   3) 冒泡排序比较规则补全：总分降序；同分最低分小的在前；再同分按输入顺序 idx
   4) 输出格式按题目要求："%10s%6d\n"
*/

typedef struct {
    char id[10];
    int scores[4];
    int total;
    int minScore;
    int idx;
} Player;

/* 修改点：用指针交换两个结构体（交换整个人的信息，不会错位） */
static void swap(Player *a, Player *b)
{
    Player tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void)
{
    int n;
    scanf("%d", &n);

    Player players[n];

    for (int i = 0; i < n; i++) {
        /* 修改点：记录输入顺序，用于“完全相同”时保持稳定（不乱序） */
        players[i].idx = i;

        /* 修改点：编号用 %9s 限长；4 个分数分别用 &scores[k] 读入 */
        scanf("%9s%d%d%d%d",
              players[i].id,
              &players[i].scores[0], &players[i].scores[1], &players[i].scores[2], &players[i].scores[3]);

        int minScore = players[i].scores[0];
        int sum = players[i].scores[0];

        for (int k = 1; k < 4; k++) {
            if (players[i].scores[k] < minScore) minScore = players[i].scores[k];
            sum += players[i].scores[k];
        }

        players[i].minScore = minScore;
        /* 修改点：total 表示“去掉最低分后的 3 个分数之和” */
        players[i].total = sum - minScore;
    }

    for (int pass = 0; pass < n - 1; pass++) {
        for (int i = 0; i < n - 1 - pass; i++) {
            int needSwap = 0;

            /* 修改点：排序规则
               1) total 大的在前（降序）
               2) total 相同：minScore 小的在前（升序）
               3) 再相同：idx 小的在前（保持输入顺序） */
            if (players[i].total < players[i + 1].total) needSwap = 1;
            else if (players[i].total == players[i + 1].total && players[i].minScore > players[i + 1].minScore) needSwap = 1;
            else if (players[i].total == players[i + 1].total &&
                     players[i].minScore == players[i + 1].minScore &&
                     players[i].idx > players[i + 1].idx) needSwap = 1;

            if (needSwap) swap(&players[i], &players[i + 1]);
        }
    }

    for (int i = 0; i < n; i++) {
        /* 修改点：按题目要求的宽度输出 */
        printf("%10s%6d\n", players[i].id, players[i].total);
    }

    return 0;
}

