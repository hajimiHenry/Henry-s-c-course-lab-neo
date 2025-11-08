/*
程序目的
- 从标准输入读取两个整数 X、N，输出“严格大于 X 的前 N 个质数（素数）”。

输出格式
- 同一行内数字用空格分隔；
- 每行最多输出 5 个数字，满 5 个立即换行；
- 循环结束后若末行未满 5 个，也补一个换行，保证输出整洁且无尾随空格。

算法思路
- 主循环：从 Y = X + 1 开始递增检查；当且仅当判定为质数时输出并累计，直到累计 m == N。
- 行控制：使用 numcount 记录当前行已输出的个数（0..4）。
  - 若 numcount > 0，则在数字前输出一个空格；
  - 打印后 numcount++；若 numcount == 5，则换行并重置为 0；
  - 循环结束后，若 numcount != 0，再输出一个换行。
- 判素数 prime(n)：
  - n < 2 返回 0；n == 2 返回 1；其他偶数返回 0；
  - 仅试奇数因子 i=3,5,...，直到 i*i > n（实现为 i <= n / i 以避免乘法溢出）；
  - 遇到能整除立即返回 0；试完都不能整除则返回 1。

复杂度
- 单次判素数约 O(√n)；整体与要输出的前 N 个质数的大小有关。
*/
#include <stdio.h>
static int prime(int n);

int main(void) {
    int N, X;
    scanf("%d%d", &X, &N);

    int Y = X + 1;    
    int m = 0;        
    int numcount = 0; 

    while (m < N)
    {
        if (prime(Y)) 
        {
            if (numcount > 0) 
            {
            putchar(' ');
            } 
            printf("%d", Y);
            numcount++;
            if (numcount == 5)
            {            
                putchar('\n');
                numcount = 0;
            }
            m++;
        }
        Y++;
    }

    if (numcount != 0) putchar('\n');       
    return 0;
}

static int prime(int n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (int i = 3; i<n; i += 2)
    {   
        if (n % i == 0) return 0;
    }
    return 1;
}