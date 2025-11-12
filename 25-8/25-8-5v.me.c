    #include<stdio.h>

    int main(void){
    long long int N;
    scanf("%lld",&N);

    if (10<N&&N<100)
    {
        printf("2");
        putchar(' ');
        int m=N/10;
        int t=N%10;
        int sum99=m+t;
        printf("%d",sum99);
    }
    
    else if (N>0&&N<10){
    printf("1");
    putchar(' ');
    int m=N/10;
    int t=N%10;
    int sum99=m+t;
    printf("%d",sum99);
    }


    else{

    int fenmu=10;
    int i;
    for (i = 2; N/fenmu>=10; i++)
    {
    fenmu*=10;
    }

    int sum=0;

    while (fenmu>0)
    {
    sum+=N/fenmu;
    N%=fenmu;
    fenmu/=10;
    }

    printf("%d",i);
    putchar(' ');
    printf("%d",sum);
        return 0;
    }
    }