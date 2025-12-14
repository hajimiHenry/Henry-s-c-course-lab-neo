#include <stdio.h>
#include <math.h>

int prime( int p );
void Goldbach( int n );
    
int main()
{
    int m, n, i, cnt;

    scanf("%d %d", &m, &n);
    if ( prime(m) != 0 ) printf("%d is a prime number\n", m);
    if ( m < 6 ) m = 6;
    if ( m%2 ) m++;
    cnt = 0;
    for( i=m; i<=n; i+=2 ) {
        Goldbach(i);
        cnt++;
        if ( cnt%5 ) printf(", ");
        else printf("\n");
    }

    return 0;
}

/* 你的代码将被嵌在这里 */
/*其中函数prime当用户传入参数p为素数时返回1，否则返回0；
函数Goldbach按照格式“n=p+q”输出n的素数分解，其中p≤q均为素数。
又因为这样的分解不唯一（例如24可以分解为5+19，还可以分解为7+17），
要求必须输出所有解中p最小的解。*/
int prime( int p )
{
    int i;

    if ( p < 2 ) return 0;
    for ( i = 2; i <= sqrt(p); i++ )
        if ( p % i == 0 ) return 0;
    return 1;
}

void Goldbach( int n )
{
    for(int p=3;p<=(n/2);p+=2)
    {
        if (prime(p)&&prime(n-p))
        {
            printf("%d=%d+%d",n,p,n-p);
            break;
        }
        
    }
                                                                                    
}
