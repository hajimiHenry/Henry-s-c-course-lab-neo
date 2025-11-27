/*
 * 题目：给定 N 个字符串，按冒泡排序从小到大排序；
 输出扫描完成第 K 趟后的中间结果。
 *
 * 输入：
 *   第 1 行：N 和 K（1 <= K < N <= 100）
 *   接下来的 N 行：每行一个非空字符串，长度不超过 10，仅由小写英文字母组成。
 *
 * 输出：
 *   冒泡排序执行完第 K 趟后的当前序列，每行输出一个字符串。
 */

#include<stdio.h>
#include<string.h>
int main(void){

    int n,k;//n是字符串的数量，同时也是行数
    scanf("%d%d",&n,&k);

    char arr[n][11];

    //读入字符数组
    for (int i = 0; i < n; i++)
    {
        scanf("%10s",arr[i]);
    }
    
    //开始做冒泡排序

    for (int p = 0; p < k; p++)
    {
        for (int j = 0; j < n-1-p; j++)
        {
            if (strcmp(arr[j], arr[j + 1]) > 0)
            {
                char temp[11];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            } 
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%s\n", arr[i]);
    }

return 0;
}


