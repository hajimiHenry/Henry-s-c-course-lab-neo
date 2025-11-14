//梅森数，输入一个n，输出所有的�?的n次方减一小的数梅�?
//循环，指数递减，进出循环的条件是什�?
//进循环，读取了值直接进去干
//出循环：直接不停相加，加到那个最大的�?  
//输出：写在循环里

//

#include<stdio.h>

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


int main(void){
int n;
int m=2;
int h;

scanf("%d",&n);
int found=0;
        for (int i = 2; i <= n; i++)
        {
          int i=1;
          for ( int count = 0; count < i; count++)
            {
              m*=2;
              h=m;
            }
            h-=1;
            if (prime(h))
            {
              printf("%d\n",h);
              found+=1;
            }
        }

if (found==0)
{
  printf("None");/* code */
}

return 0;
    }
