#include<stdio.h>

long long gcd(long long a,long long b){
if(a<0){a=-a;}
if (b<0){
  b=-b ; /* code */
}
if (a==0&&b==0)
{
return 1;
}
while (b!=0){long long r=a%b;
    a=b;
    b=r;/* code */
}


if(a==0)
{
   return a; /* code */
}
else return 0;
}

int main(void){
int a,b;

    scanf("%d/%d",&a,&b);
        long long g=gcd(a,b);
    a/=g;
    b/=g;
    printf("%lld/%lld\n", a, b);
    return 0;
}