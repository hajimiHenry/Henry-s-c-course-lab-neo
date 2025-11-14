#include<stdio.h>

int main(void){

int a,b,max;
scanf("%d,%d",&a,&b);
if (a>=b)
{
   max=a; /* code */
}
else{
    max=b;
}
printf("max=%d",max);
return 0;
}