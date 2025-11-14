#include<stdio.h>
int main(void){

     //先判断能不能构成三角形
     int a,b,c;
     scanf("%d%d%d",&a,&b,&c);

     if (a+b>c&&b+c>a&&a+c>b)
     {
        if (a==b&&b==c)
        {
            printf("1");
        }
        else if (a==b||a==c||b==c)
        {
            printf("2");
        }
        else{
            printf("3");
        }
        
     }
     else{
        printf("0");
     }
     return 0;
    }
