    #include<stdio.h>
    int judge(int n,int a,int b,int c);


    int main(void)
    {
        int N,M,a,b,c;
        scanf("%d%d%d%d%d",&N,&M,&a,&b,&c);

        for (int i = N; i <= M; i++)
        {
            if (judge(i,a,b,c))
            {
                printf("%d\n",i);/* code */
            }
        }
    }
    int judge(int n,int a,int b,int c)
    {
        if (n%3==a&&n%5==b&&n%7==c)
        {
            return 1;
            /* code */
        }
        return 0;
    }