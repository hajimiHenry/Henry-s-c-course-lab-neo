#include<stdio.h>
int main(void)
{
int d,m,y;
int a,b,c;
    scanf("%d/%d/%d",&y,&m,&d);
    scanf("%d/%d/%d",&a,&b,&c);

    if (a<y)
    {
      printf("%d/%d/%d",a,b,c);
    }
    else if (a>y)
    {printf("%d/%d/%d",y,m,d);}
else{
if (m<b)
    {printf("%d/%d/%d",y,m,d);}
else if (m>b)
{
     printf("%d/%d/%d",a,b,c);
}
else{
    if (c<d)
    {
            printf("%d/%d/%d",a,b,c);
    }
    else if (c>d)
    {
    printf("%d/%d/%d",y,m,d);
    }
    else{      printf("%d/%d/%d",a,b,c);}
}
}
return 0;}
