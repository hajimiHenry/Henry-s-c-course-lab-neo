#include<stdio.h>

void aver_stu(int a[10][5]);
void aver_sco(int a[10][5]);
void max(int a[10][5]);

int main()
{
    int a[10][5];
    int i,j;
    for(i = 0; i < 10; i++)
        for(j = 0; j < 5; j++)
            scanf("%d", &a[i][j]);
    aver_stu(a);
    aver_sco(a);
    max(a);
    return 0;
}

/* （1）每个学生的平均分 */
void aver_stu(int a[10][5])
{
    int i, j, sum, aver;
    for (i = 0; i < 10; i++)
    {
        sum = 0;
        for (j = 0; j < 5; j++)
        {
            sum += a[i][j];
        }
        aver = sum / 5;
        printf("%3d", aver);
    }
    printf("\n");
}

/* （2）每门课的平均分 */
void aver_sco(int a[10][5])
{
    int i, j, sum, aver;
    for (j = 0; j < 5; j++)
    {
        sum = 0;
        for (i = 0; i < 10; i++)
        {
            sum += a[i][j];
        }
        aver = sum / 10;
        printf("%3d", aver);
    }
    printf("\n");
}

/* （3）最高分学生学号和课程号 */
void max(int a[10][5])
{
    int i, j;
    int max_val = a[0][0];
    int max_i = 0, max_j = 0;

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (a[i][j] > max_val)
            {
                max_val = a[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }

    /* 学号和课程号都是从 1 开始 */
    printf("%3d%3d\n", max_i + 1, max_j + 1);
}
