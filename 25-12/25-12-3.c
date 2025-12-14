
#include<stdio.h>
#include<string.h>
void turn(char s[]);
int main()
{ char str[81];
  scanf("%s",str);
  turn(str);
  printf("%s",str);
  return 0;
}
/* 你的函数将被嵌在这里 */
/* 本题只在同一个字符串内部交换“单个字符”，
   和 25-12-2.c 中用 strcpy 交换“整条字符串”不一样 */

void turn(char s[])
{
    int low = 0;               /* 左侧字符下标，从头开始 */
    int high = strlen(s) - 1;  /* 右侧字符下标，从尾开始 */

    while (low < high)
    {
        char temp = s[low];    /* 这里只交换单个字符，不是字符串 */
        s[low] = s[high];      /* 左右互换位置 */
        s[high] = temp;

        low++;
        high--;
    }
}
