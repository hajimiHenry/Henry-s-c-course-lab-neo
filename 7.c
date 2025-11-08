#include<stdio.h>
int main(void){
int A,B;
scanf("%d%d",&A,&B);
/*AB A大于零B大于零 A=0B不=0 b=0a不管 a小于0b小于零 a和b其中一个小鱼0*/
double c=(double) A/B;

if (B==0)
{if (A<=0)
{
  printf("(%d)/%d=Error",A,B);
}
else{
    printf("%d/%d=Error",A,B);
}
}
else if(A>=0&&B>0)
{
printf("%d/%d=%.2f",A,B,c);
}
else if (A<0&&B<0)
{
printf("%d/(%d)=%.2f",A,B,c);
}
else if (A<0&&B>0)
{
printf("%d/%d=%.2f",A,B,c);
}
else if (A>0&&B<0)
{
printf("%d/(%d)=%.2f",A,B,c);
}

return 0;
}