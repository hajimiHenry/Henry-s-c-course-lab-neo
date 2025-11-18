//还是连续因子

/*还是从头开始找因子，找到了就记录下来，然后从后面开始记录，记下他的长度，
    然后开始下面一轮，如果发现了比之前的还长的就更新初始值，和长度
*/
#include <stdio.h>
int main(void){
int N;//要求连续因子的那个最大的数
scanf("%d",&N);

int len=0;//长度
int start;//第一个符合条件因子
int maxlen=0;
int i;
for ( i = 2; i < N; i++)//最外层，用于要在这里找到第一个因子
{
    len=0;
    if (N%i!=0)
    {
       continue;
    }
    for (int k = i; k <N; k++)
    {
        if (N%k!=0)
        {
           break;
        }
        len++;
    }
    if (len >=maxlen)
    {
        maxlen =len;
        start=i;
    }
}

if (maxlen == 1) {
        printf("1\n%d\n", N);
    } else {
        printf("%d\n", maxlen);

        for (int k = 0; k < maxlen; k++) {
            if (k > 0) {
                printf("*");
            }
            printf("%d", start + k);  
        }
        printf("\n");
    }

    return 0;
}

