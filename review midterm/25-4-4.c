#include<stdio.h>
int main(void){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    //三个数怎么比大小
    //先找到一个复位最大值，然后挨个去比较

    int max=a;
    if(max<b)
    {
       max=b; /* code */
    }
    if (max<c)
    {
       max=c; /* code */
    }
    printf("%d",c);
    return 0 ;
    

}