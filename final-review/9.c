#include<stdio.h>

void checkETC(int U, double *rate);
void price(int S, int *price1, int *price2, int *price3);
void checktime(int N, int *time1, int *time2, int *time3);


int main(void)
{
    int T,S,U,N;
    scanf("%d%d%d%d",&T,&S,&U,&N);
    
    double rate=0.00;

    int time1,time2,time3;
    int price1,price2,price3;

    if (T==0)
    {
        checkETC(U, &rate);
        price(S, &price1, &price2, &price3);
        checktime(N, &time1, &time2, &time3);
        double total=(time1*price1+time2*price2+time3*price3)*rate;
        printf("%.2lf",total); /* code */
    }
    else if (T==1)
    {
     printf("0.00");   /* code */
    }
    else{
        return 0;
    }

    return 0;
}

void checkETC(int U, double *rate)
{
    if (U==0)
    {
        *rate=1;
        /* code */
    }
    else if (U==1)
    {
        *rate=0.88;   
        /* code */
    }
    else if (U==2)
    {
        *rate=0.90;   /* code */
    }
    else if (U==3)
    {
       *rate=0.95; /* code */
    }
    else
    {
        *rate=1;
    }
}
void price(int S, int *price1, int *price2, int *price3)
{
    if (S==0)
    {
        *price1=2;
        *price2=6;
        *price3=8;
        /* code */
    }
    else if (S==1)
    {
        *price1=8;
        *price2=12;
        *price3=20;
        /* code */
    }
}

void checktime(int N, int *time1, int *time2, int *time3)
{
    if (N<=2)
    {
        *time1=N;
        *time2=0;
        *time3=0;
         /* code */
    }
    else if (N>2&&N<=3)
    {
        *time1=2;
        *time2=N-2;
        *time3=0;
        /* code */
    }
    else
    {
        *time1=2;
        *time2=1;
        *time3=N-3;
        /* code */
    }
}
