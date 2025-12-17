#include<stdio.h>


//鎬荤數璐?鏈嶅姟璐?鐢佃垂
//鍏呯數妗?鐢佃垂+

int main(void)
{
    int type,time,level;
    scanf("%d",&type);

    double price1,servprice,manageprice;
    double elec,serv;
    int N;
    double total;

    if (type==1)
    {
        int time;
        scanf("%d",&time);
        scanf("%d",&N);

        checkprice(time,&price1);
        elec=N*price1;
        serv=0.01*elec;

        total=elec+serv;
    }
    else if (type==2)
    {
        int time;
        scanf("%d",&time);
        scanf("%d",&level);
        scanf("%d",&N);

        checkprice(time,&price1);
        checkserve(level,&servprice);
        checkmanage(level,&manageprice);

        elec=N*price1;
        serv=(servprice+manageprice)*elec;

        total=elec+serv;
    }  
    
    printf("%.2f",total);
 }


void checkprice(int a, double *price)
{
    if (a==0)
    {
        *price=0.81;
    }
    if (a==1)
    {
        *price=0.5;
    }
    if (a==2)
    {
        *price=0.27;/* code */
    }
}

void checkserve(int a, double *price)
{   
    if (a==1)
    {
        *price=1.5;
    }
    if (a==2)
    {
        *price=1.0;
    }
    else
    {
        *price=0.7;/* code */
    }
}

void checkmanage(int a,double* price)
{
    if (a==1)
    {
        *price=0.1;
    }
    if (a==2)
    {
        *price=0.2;
    }
    else
    {
        *price=0.3;/* code */
    }


}
