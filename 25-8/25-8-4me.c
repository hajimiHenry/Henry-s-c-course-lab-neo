//还是连续因子

/*还是从头开始找因子，找到了就记录下来，然后从后面开始记录，记下他的长度，
    然后开始下面一轮，如果发现了比之前的还长的就更新初始值，和长度
*/
#include <stdio.h>
int main(void){
int N;//要求连续因子的那个最大的数
scanf("%d",&N);

int len;//长度
int start;//第一个符合条件因子
int maxlen=0;
int i;
for ( i = 2; i < N; i++)//最外层，用于要在这里找到第一个因子
{
    if (N%i!=0)
    {
       continue; /* code */
    }
    for (int k = i; k <N; k++)
    {
        if (N%k==0)
        {
           len++ ;/* code */
        }
    }
    if (len >=maxlen)
    {
        maxlen =len;
    }
}
start =i;

if (maxlen == 0) {
        /*
         * maxLen 仍为 0，说明没有任何长度 >= 2 的连续因子序列
         * 题目要求这种情况下输出：
         *   第一行：1
         *   第二行：N
         */
        printf("1\n%lld\n", N);
    } else {
        /* 打印最长长度 */
        printf("%lld\n", maxlen);

        /* 按 “因子1*因子2*...*因子k” 的格式输出这段连续因子 */
        for (long long k = 0; k < maxlen; k++) {
            if (k > 0) {
                printf("*"); /* 因子之间用 * 连接 */
            }
            printf("%lld", start + k);  
        }
        printf("\n");
    }

    return 0;
}