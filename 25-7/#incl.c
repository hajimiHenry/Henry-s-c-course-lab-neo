#include<stdio.h>
int main(void){

    int a;
    scanf("%d",&a);

    int m=a/100;
    int t=a%100;/*后两位*/
    int n=t/10;/*中间那个数*/
    int p=a%10;/*个位数*/

    if (a/100!=0)
    {
    int b=3;
    printf("3\n");
    printf("%d %d %d\n",m,n,p);
    printf("%d %d %d\n",p,n,m);
    }
    else if (a/10!=0)
    {
     int b=2;   
     printf("2\n");
     printf("%d %d\n",n,p);
     printf("%d %d\n",p,n);
    }
    else{
        int b=1;
        printf("1\n");
        printf("%d\n",a);
        printf("%d\n",a);

    }
return 0;
}